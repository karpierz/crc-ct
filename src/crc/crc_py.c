/**
 * Filename: \file
 *
 * Copyright (c) 1994-2019 Adam Karpierz
 * Licensed under the zlib/libpng License
 * http://opensource.org/licenses/zlib/
 *
 * Purpose:
 *
 *     Only for creating C dll using Python setup machinery.
 */

#include <Python.h>

#if PY_MAJOR_VERSION >= 3
  #define MODINIT_FUNC(name) PyInit_##name(void)
  #define MODINIT_RETURN(v) v
#else
  #define MODINIT_FUNC(name) init##name(void)
  #define MODINIT_RETURN(v)
#endif

PyMODINIT_FUNC MODINIT_FUNC(crc)
{
    return MODINIT_RETURN(NULL);
}
