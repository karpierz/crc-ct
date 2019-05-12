/**
 * Filename: \file
 *
 * Copyright (c) 1994-2019 Adam Karpierz
 * Licensed under the zlib/libpng License
 * http://opensource.org/licenses/zlib/
 *
 * Purpose:
 *
 *     Calculate CRC values of file contents.
 *
 * Function(s):
 *
 *     crc_file - Calculates CRC values of file region from current file position.
 *
 *     Prototype:
 *         int crc_file(FILE* stream, long len, crc_model_t crc_models[], crc_t crc_values[]);
 *
 *     Arguments:
 *         \param[in]  stream      File stream.
 *         \param[in]  len         Number of bytes calculate.
 *                                 If it is equals 0 or greater then file length
 *                                 then calculates to the end of file.
 *         \param[in]  crc_models  ...
 *         \param[out] crc_values  ...
 *         \return                 0 on success, -1 if on failure.
 *
 * Header:
 *     crc_file.h
 */

#ifndef _CRC_FD_
#define _CRC_FD_

#include <stdio.h>

#include <crc/crc.h>

#ifdef __cplusplus
extern "C" {
#endif

int crc_file(FILE* stream, long len, crc_model_t crc_models[], crc_t crc_values[]);

#ifdef __cplusplus
}
#endif

#endif
