# Copyright (c) 1994-2020 Adam Karpierz
# Licensed under the zlib/libpng License
# https://opensource.org/licenses/Zlib

import sys
import os
import platform
import sysconfig
import ctypes as ct

this_dir = os.path.dirname(os.path.abspath(__file__))

dll_suffix = (("" if sys.version_info[0] <= 2 else
               "." + platform.python_implementation()[:2].lower() +
               sysconfig.get_python_version().replace(".","") + "-" +
               sysconfig.get_platform().replace("-","_")) +
              (sysconfig.get_config_var("EXT_SUFFIX") or ".pyd"))

DLL_PATH = os.path.join(this_dir, "crc" + dll_suffix)

def DLL(*args, **kargs):
    from ctypes import windll, WinDLL
    windll.kernel32.SetDllDirectoryA(os.path.dirname(args[0]).encode("utf-8"))
    try:
        return WinDLL(*args, **kargs)
    finally:
        windll.kernel32.SetDllDirectoryA(None)

from ctypes  import CFUNCTYPE   as CFUNC
from _ctypes import FreeLibrary as dlclose
