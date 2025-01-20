# Copyright (c) 1994 Adam Karpierz
# SPDX-License-Identifier: Zlib

import sys
import os
import platform
import sysconfig
import ctypes as ct  # noqa: F401

this_dir = os.path.dirname(os.path.abspath(__file__))

dll_suffix = (("" if platform.python_implementation() == 'PyPy'
               or sys.version_info[0] <= 2 or sys.version_info[:2] >= (3, 8)
               else ("." + platform.python_implementation()[:2].lower()
               + sysconfig.get_python_version().replace(".", "") + "-"
               + sysconfig.get_platform().replace("-", "_")))
              + (sysconfig.get_config_var("EXT_SUFFIX") or ".pyd"))

DLL_PATH = os.path.join(os.path.dirname(this_dir), "crc" + dll_suffix)

def DLL(*args, **kwargs):
    from ctypes import windll, WinDLL
    windll.kernel32.SetDllDirectoryA(os.path.dirname(args[0]).encode("utf-8"))
    try:
        return WinDLL(*args, **kwargs)
    finally:
        windll.kernel32.SetDllDirectoryA(None)

try:  # noqa: E305
    from _ctypes import FreeLibrary as dlclose  # noqa: E402,N813
except ImportError:  # pragma: no cover
    dlclose = lambda handle: 0
from ctypes  import CFUNCTYPE as CFUNC  # noqa: E402,F401
