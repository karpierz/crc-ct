/**
 * Filename: \file
 *
 * Copyright (c) 1994-2019 Adam Karpierz
 * Licensed under the zlib/libpng License
 * http://opensource.org/licenses/zlib/
 *
 * Purpose:
 *
 *     Internal definitions for CRC package.
 *
 * Header:
 *    crc_defs.h
 */

#ifndef _CRC_DEFS_H_
#define _CRC_DEFS_H_

#ifdef __cplusplus
extern "C" {
#endif

#define BIT_MASK(bit) (0x1ULL << (bit))

#define WIDTH_MASK(width) ((((0x1ULL << ((width) - 1)) - 1ULL) << 1) | 0x1ULL)

#define BITS_REVERSE(value, width, type) \
{                                                                 \
    int cnt = (width) >> 1;                                       \
    int bit, hbit;                                                \
    type bmask;                                                   \
    for ( bit = 0, hbit = (width) - 1; bit < cnt; ++bit, --hbit ) \
    {                                                             \
        bmask  = ((value >> bit) ^ (value >> hbit)) & 0x1U;       \
        value ^= ((bmask << bit) | (bmask << hbit));              \
    }                                                             \
}

#ifdef __cplusplus
}
#endif

#endif
