# Copyright (c) 1994-2022 Adam Karpierz
# Licensed under the zlib/libpng License
# https://opensource.org/licenses/Zlib

import sys
import os
import platform
import sysconfig
import ctypes as ct
from functools import partial

this_dir = os.path.dirname(os.path.abspath(__file__))

dll_suffix = (("" if platform.python_implementation() == 'PyPy'
               or sys.version_info[0] <= 2 or sys.version_info[:2] >= (3, 8)
               else ("." + platform.python_implementation()[:2].lower()
               + sysconfig.get_python_version().replace(".", "") + "-"
               + sysconfig.get_platform().replace("-", "_")))
              + (sysconfig.get_config_var("EXT_SUFFIX") or ".pyd"))

DLL_PATH = os.path.join(this_dir, "crc" + dll_suffix)

from ctypes  import CDLL as DLL         # noqa: E402
from _ctypes import dlclose             # noqa: E402
from ctypes  import CFUNCTYPE as CFUNC  # noqa: E402

DLL = partial(DLL, mode=ct.RTLD_GLOBAL)
