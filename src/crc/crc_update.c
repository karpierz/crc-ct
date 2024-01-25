/**
 * Filename: \file
 *
 * Copyright (c) 1994 Adam Karpierz
 * Licensed under the zlib/libpng License
 * https://opensource.org/license/zlib
 *
 * Purpose:
 *
 *     Low-level functions for calculate CRC values.
 *
 * Header:
 *    crc_update.h
 */

#include "crc_defs.h"
#include "crc_update.h"

#define DEFINE_CRC8_UPDATE(width, crc_type) \
crc_t crc##width##_update(const void* data, size_t data_len,   \
                          const crc_t crc_table[], crc_t crc)  \
{                                                              \
    crc_type* _crc_table = (crc_type*)(crc_table);             \
    crc_type  _crc = (crc_type)(crc);                          \
    const unsigned char* buff = (const unsigned char*)data;    \
    while ( data_len-- )                                       \
        _crc = _crc_table[(unsigned char)_crc ^ *buff++];      \
    return ( _crc );                                           \
}

#define DEFINE_CRC8R_UPDATE(width, crc_type) \
        DEFINE_CRC8_UPDATE(width##r, crc_type)

#define DEFINE_CRC_UPDATE(width, crc_type) \
crc_t crc##width##_update(const void* data, size_t data_len,   \
                          const crc_t crc_table[], crc_t crc)  \
{                                                              \
    crc_type* _crc_table = (crc_type*)(crc_table);             \
    crc_type  _crc = (crc_type)(crc);                          \
    const unsigned char* buff = (const unsigned char*)data;    \
    while ( data_len-- )                                       \
        _crc = (_crc << 8) ^                                   \
               _crc_table[(unsigned char)(_crc >>              \
                          (width - 8)) ^ *buff++];             \
    _crc &= WIDTH_MASK(width);                                 \
    return ( _crc );                                           \
}

#define DEFINE_CRCR_UPDATE(width, crc_type) \
crc_t crc##width##r_update(const void* data, size_t data_len,  \
                           const crc_t crc_table[], crc_t crc) \
{                                                              \
    crc_type* _crc_table = (crc_type*)(crc_table);             \
    crc_type  _crc = (crc_type)(crc);                          \
    const unsigned char* buff = (const unsigned char*)data;    \
    while ( data_len-- )                                       \
        _crc = (_crc >> 8) ^                                   \
               _crc_table[(unsigned char)_crc ^ *buff++];      \
    _crc &= WIDTH_MASK(width);                                 \
    return ( _crc );                                           \
}

DEFINE_CRC8_UPDATE (8, crc8_t)
DEFINE_CRC8R_UPDATE(8, crc8_t)
DEFINE_CRC_UPDATE (16, crc16_t)
DEFINE_CRCR_UPDATE(16, crc16_t)
DEFINE_CRC_UPDATE (24, crc24_t)
DEFINE_CRCR_UPDATE(24, crc24_t)
DEFINE_CRC_UPDATE (32, crc32_t)
DEFINE_CRCR_UPDATE(32, crc32_t)
DEFINE_CRC_UPDATE (40, crc40_t)
DEFINE_CRCR_UPDATE(40, crc40_t)
DEFINE_CRC_UPDATE (48, crc48_t)
DEFINE_CRCR_UPDATE(48, crc48_t)
DEFINE_CRC_UPDATE (56, crc56_t)
DEFINE_CRCR_UPDATE(56, crc56_t)
DEFINE_CRC_UPDATE (64, crc64_t)
DEFINE_CRCR_UPDATE(64, crc64_t)
