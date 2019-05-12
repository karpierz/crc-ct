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
 * Function(s):
 *
 *     crc8_table  - initializes  8 bit crc table.
 *     crc16_table - initializes 16 bit crc table.
 *     crc24_table - initializes 24 bit crc table.
 *     crc32_table - initializes 32 bit crc table.
 *     crc40_table - initializes 40 bit crc table.
 *     crc48_table - initializes 48 bit crc table.
 *     crc56_table - initializes 56 bit crc table.
 *     crc64_table - initializes 64 bit crc table.
 *
 * Header:
 *    crc_table.h
 */

#ifndef _CRC_TABLE_H_
#define _CRC_TABLE_H_

#include "../../include/crc/crc.h"

#ifdef __cplusplus
extern "C" {
#endif

void crc8_table(crc_t  poly, short refin, crc_t crc_table[]);
void crc16_table(crc_t poly, short refin, crc_t crc_table[]);
void crc24_table(crc_t poly, short refin, crc_t crc_table[]);
void crc32_table(crc_t poly, short refin, crc_t crc_table[]);
void crc40_table(crc_t poly, short refin, crc_t crc_table[]);
void crc48_table(crc_t poly, short refin, crc_t crc_table[]);
void crc56_table(crc_t poly, short refin, crc_t crc_table[]);
void crc64_table(crc_t poly, short refin, crc_t crc_table[]);

#ifdef __cplusplus
}
#endif

#endif
