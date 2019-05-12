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
 *     crc_fd - Calculates CRC values of file region from current file position.
 *
 *     Prototype:
 *         int crc_fd(int fd, long len, crc_model_t crc_models[], crc_t crc_values[]);
 *
 *     Arguments:
 *         \param[in]  fd          File descriptor.
 *         \param[in]  len         Number of bytes calculate.
 *                                 If it is equals 0 or greater then file length
 *                                 then calculates to the end of file.
 *         \param[in]  crc_models  ...
 *         \param[out] crc_values  ...
 *         \return                 0 on success, -1 if on failure.
 *
 * Header:
 *     crc_fd.h
 */

#ifndef _CRC_FD_
#define _CRC_FD_

#include <crc/crc.h>

#ifdef __cplusplus
extern "C" {
#endif

int crc_fd(int fd, long len, crc_model_t crc_models[], crc_t crc_values[]);

#ifdef __cplusplus
}
#endif

#endif
