/**
 * Filename: \file
 *
 * Copyright (c) 1994-2019 Adam Karpierz
 * Licensed under the zlib/libpng License
 * http://opensource.org/licenses/zlib/
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

#define DEFINE_CRC8_UPDATE(func_name) \
crc_t func_name##(const void* data, size_t data_len,        \
                  const crc_t crc_table[], crc_t crc)       \
{                                                           \
    crc8_t* _crc_table = (crc8_t*)(crc_table);              \
    crc8_t  _crc = (crc8_t)(crc);                           \
    const unsigned char* buff = (const unsigned char*)data; \
    while ( data_len-- )                                    \
        _crc = _crc_table[(unsigned char)_crc ^ *buff++];   \
    return ( _crc );                                        \
}

#define DEFINE_CRC_UPDATE(func_name, width, crc_type) \
crc_t func_name##(const void* data, size_t data_len,        \
                  const crc_t crc_table[], crc_t crc)       \
{                                                           \
    crc_type* _crc_table = (crc_type*)(crc_table);          \
    crc_type  _crc = (crc_type)(crc);                       \
    const unsigned char* buff = (const unsigned char*)data; \
    while ( data_len-- )                                    \
        _crc = (_crc << 8) ^                                \
               _crc_table[(unsigned char)(_crc >>           \
                          (width - 8)) ^ *buff++];          \
    _crc &= WIDTH_MASK(width);                              \
    return ( _crc );                                        \
}

#define DEFINE_CRCR_UPDATE(func_name, width, crc_type) \
crc_t func_name##(const void* data, size_t data_len,        \
                  const crc_t crc_table[], crc_t crc)       \
{                                                           \
    crc_type* _crc_table = (crc_type*)(crc_table);          \
    crc_type  _crc = (crc_type)(crc);                       \
    const unsigned char* buff = (const unsigned char*)data; \
    while ( data_len-- )                                    \
        _crc = (_crc >> 8) ^                                \
               _crc_table[(unsigned char)_crc ^ *buff++];   \
    _crc &= WIDTH_MASK(width);                              \
    return ( _crc );                                        \
}

DEFINE_CRC8_UPDATE(crc8_update)
DEFINE_CRC8_UPDATE(crc8r_update)
DEFINE_CRC_UPDATE (crc16_update,  16, crc16_t)
DEFINE_CRCR_UPDATE(crc16r_update, 16, crc16_t)
DEFINE_CRC_UPDATE (crc24_update,  24, crc24_t)
DEFINE_CRCR_UPDATE(crc24r_update, 24, crc24_t)
DEFINE_CRC_UPDATE (crc32_update,  32, crc32_t)
DEFINE_CRCR_UPDATE(crc32r_update, 32, crc32_t)
DEFINE_CRC_UPDATE (crc40_update,  40, crc40_t)
DEFINE_CRCR_UPDATE(crc40r_update, 40, crc40_t)
DEFINE_CRC_UPDATE (crc48_update,  48, crc48_t)
DEFINE_CRCR_UPDATE(crc48r_update, 48, crc48_t)
DEFINE_CRC_UPDATE (crc56_update,  56, crc56_t)
DEFINE_CRCR_UPDATE(crc56r_update, 56, crc56_t)
DEFINE_CRC_UPDATE (crc64_update,  64, crc64_t)
DEFINE_CRCR_UPDATE(crc64r_update, 64, crc64_t)
