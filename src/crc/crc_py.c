/**
 * Filename: \file
 *
 * Copyright (c) 1994 Adam Karpierz
 * Licensed under the zlib/libpng License
 * https://opensource.org/license/zlib
 *
 * Purpose:
 *
 *     Only for creating C dll using Python setup machinery.
 */

#include <Python.h>

#define MODINIT_FUNC(name) PyInit_##name(void)
#define MODINIT_RETURN(v) v

PyMODINIT_FUNC MODINIT_FUNC(crc)
{
    return MODINIT_RETURN(NULL);
}
