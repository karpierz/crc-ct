/**
 * Filename: \file
 *
 * Copyright (c) 1994-2019 Adam Karpierz
 * Licensed under the zlib/libpng License
 * http://opensource.org/licenses/zlib/
 *
 * Purpose:
 *
 *     Low-level functions for calculate CRC tables.
 *
 * Header:
 *    crc_table.h
 */

#include "crc_defs.h"
#include "crc_table.h"

#define DEFINE_CRC_TABLE(width, crc_type) \
void crc##width##_table(crc_t poly,                \
                        short refin,               \
                        crc_t crc_table[])         \
{                                                  \
    crc_type  _poly = (crc_type)(poly);            \
    crc_type* _crc_table = (crc_type*)(crc_table); \
    int idx, bit;                                  \
    _poly &= WIDTH_MASK(width);                    \
    for ( idx = 0; idx < 256; ++idx )              \
    {                                              \
        crc_type elem = (crc_type)idx;             \
        if ( refin )                               \
            BITS_REVERSE(elem, width, crc_type)    \
        else if ( width > 8 )                      \
            elem <<= width - 8;                    \
        for ( bit = 0 ; bit < 8 ; ++bit )          \
        {                                          \
            if ( (elem >> (width - 1)) & 0x1U )    \
                elem = (elem << 1) ^ _poly;        \
            else                                   \
                elem <<= 1;                        \
        }                                          \
        if ( refin )                               \
            BITS_REVERSE(elem, width, crc_type)    \
        elem &= WIDTH_MASK(width);                 \
        _crc_table[idx] = elem;                    \
    }                                              \
}

DEFINE_CRC_TABLE(8,  crc8_t)
DEFINE_CRC_TABLE(16, crc16_t)
DEFINE_CRC_TABLE(24, crc24_t)
DEFINE_CRC_TABLE(32, crc32_t)
DEFINE_CRC_TABLE(40, crc40_t)
DEFINE_CRC_TABLE(48, crc48_t)
DEFINE_CRC_TABLE(56, crc56_t)
DEFINE_CRC_TABLE(64, crc64_t)
