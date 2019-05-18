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
 * Header:
 *     crc_fd.h
 */

#include <io.h>

#include "crc_fd.h"

int crc_fd(int fd, long len, crc_model_t crc_models[], crc_t crc_values[])
{
    const long BUFF_LEN = 512;
    const int  OK  = 0;
    const int  ERR = -1;

    unsigned char buffer[BUFF_LEN];
    size_t i;
    long file_pos, max_len;
    long total_bytes;
    int  read_bytes;
    const crc_model_t* model;

    if ( (file_pos = _tell(fd)) == -1L ||
         (max_len  = _filelength(fd)) == -1L )
        return ( ERR );

    max_len -= file_pos;

    if ( len <= 0L || len > max_len )
        len = max_len;

    for ( model = crc_models, i = 0 ; model->width ; ++model, ++i )
        crc_values[i] = crc_init(model);

    for ( total_bytes = 0L;
          total_bytes < len &&
          (read_bytes = _read(fd, (void*)buffer,
                              min(BUFF_LEN, len - total_bytes))) > 0;
          total_bytes += read_bytes )
    {
        for ( model = crc_models, i = 0 ; model->width ; ++model, ++i )
            crc_values[i] = crc_update(model, crc_values[i]);
    }

    file_pos = _lseek(fd, file_pos, 0);
    if ( file_pos   == -1L ||
         read_bytes == -1  ||
         total_bytes != len )
        return ( ERR );

    return ( OK );
}
