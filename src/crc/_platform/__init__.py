# Copyright (c) 1994 Adam Karpierz
# SPDX-License-Identifier: Zlib

import sys
import os
import ctypes as ct

from ._platform import is_windows, is_linux, is_macos

def defined(varname, __getframe=sys._getframe):
    frame = __getframe(1)
    return varname in frame.f_locals or varname in frame.f_globals

def from_oid(oid, __cast=ct.cast, __py_object=ct.py_object):
    return __cast(oid, __py_object).value if oid else None

del sys, os, ct

if is_windows:
    from ._windows import DLL_PATH, DLL, dlclose, CFUNC
elif is_linux:
    from ._linux   import DLL_PATH, DLL, dlclose, CFUNC
elif is_macos:
    from ._macos   import DLL_PATH, DLL, dlclose, CFUNC
else:
    raise ImportError("unsupported platform")
