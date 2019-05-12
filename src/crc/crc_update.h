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
 * Function(s):
 *
 *     crc8_update   - calculates  8 bit CRC value of memory region.
 *     crc8r_update  - calculates  8 bit reverse CRC value of memory region.
 *     crc16_update  - calculates 16 bit CRC value of memory region.
 *     crc16r_update - calculates 16 bit reverse CRC value of memory region.
 *     crc24_update  - calculates 24 bit CRC value of memory region.
 *     crc24r_update - calculates 24 bit reverse CRC value of memory region.
 *     crc32_update  - calculates 32 bit CRC value of memory region.
 *     crc32r_update - calculates 32 bit reverse CRC value of memory region.
 *     crc40_update  - calculates 40 bit CRC value of memory region.
 *     crc40r_update - calculates 40 bit reverse CRC value of memory region.
 *     crc48_update  - calculates 48 bit CRC value of memory region.
 *     crc48r_update - calculates 48 bit reverse CRC value of memory region.
 *     crc56_update  - calculates 56 bit CRC value of memory region.
 *     crc56r_update - calculates 56 bit reverse CRC value of memory region.
 *     crc64_update  - calculates 64 bit CRC value of memory region.
 *     crc64r_update - calculates 64 bit reverse CRC value of memory region.
 *
 * Header:
 *    crc_update.h
 */

#ifndef _CRC_UPDATE_H_
#define _CRC_UPDATE_H_

#include "../../include/crc/crc.h"

#ifdef __cplusplus
extern "C" {
#endif

crc_t crc8_update(const   void* data, size_t data_len, const crc_t crc_table[], crc_t crc);
crc_t crc8r_update(const  void* data, size_t data_len, const crc_t crc_table[], crc_t crc);
crc_t crc16_update(const  void* data, size_t data_len, const crc_t crc_table[], crc_t crc);
crc_t crc16r_update(const void* data, size_t data_len, const crc_t crc_table[], crc_t crc);
crc_t crc24_update(const  void* data, size_t data_len, const crc_t crc_table[], crc_t crc);
crc_t crc24r_update(const void* data, size_t data_len, const crc_t crc_table[], crc_t crc);
crc_t crc32_update(const  void* data, size_t data_len, const crc_t crc_table[], crc_t crc);
crc_t crc32r_update(const void* data, size_t data_len, const crc_t crc_table[], crc_t crc);
crc_t crc40_update(const  void* data, size_t data_len, const crc_t crc_table[], crc_t crc);
crc_t crc40r_update(const void* data, size_t data_len, const crc_t crc_table[], crc_t crc);
crc_t crc48_update(const  void* data, size_t data_len, const crc_t crc_table[], crc_t crc);
crc_t crc48r_update(const void* data, size_t data_len, const crc_t crc_table[], crc_t crc);
crc_t crc56_update(const  void* data, size_t data_len, const crc_t crc_table[], crc_t crc);
crc_t crc56r_update(const void* data, size_t data_len, const crc_t crc_table[], crc_t crc);
crc_t crc64_update(const  void* data, size_t data_len, const crc_t crc_table[], crc_t crc);
crc_t crc64r_update(const void* data, size_t data_len, const crc_t crc_table[], crc_t crc);

#ifdef __cplusplus
}
#endif

#endif
