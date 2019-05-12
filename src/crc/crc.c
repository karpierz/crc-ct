/**
 * Filename: \file
 *
 * Copyright (c) 1994-2019 Adam Karpierz
 * Licensed under the zlib/libpng License
 * http://opensource.org/licenses/zlib/
 *
 * Purpose:
 *
 *     Main functions for calculate CRC values.
 *     (CRC models handling).
 *
 * Header:
 *    crc.h
 */

#include <string.h>

#include "../../include/crc/crc.h"
#include "crc_defs.h"
#include "crc_table.h"
#include "crc_update.h"

typedef void (*crc_table_func_t)(crc_t poly,
                                 short refin,
                                 crc_t crc_table[]);

static const crc_table_func_t crc_table_funcs[] = {
    crc8_table,
    crc16_table,
    crc24_table,
    crc32_table,
    crc40_table,
    crc48_table,
    crc56_table,
    crc64_table,
};

typedef crc_t (*crc_update_func_t)(const void* data, size_t data_len,
                                   const crc_t crc_table[], crc_t crc);

static const crc_update_func_t crc_update_funcs[] = {
    crc8_update,
    crc16_update,
    crc24_update,
    crc32_update,
    crc40_update,
    crc48_update,
    crc56_update,
    crc64_update,
};

static const crc_update_func_t crcr_update_funcs[] = {
    crc8r_update,
    crc16r_update,
    crc24r_update,
    crc32r_update,
    crc40r_update,
    crc48r_update,
    crc56r_update,
    crc64r_update,
};

const crc_model_t crc_model(const char* name,
                            int   width,
                            crc_t poly,
                            crc_t init,
                            short refin,
                            short refout,
                            crc_t xorout,
                            crc_t check)
{
    int idx;
    crc_model_t model;
    memset((void*)&model, 0, sizeof(model));

    strncpy((char*)model.name, name, sizeof(model.name) - 1);
    model.width  = width;
    model.poly   = poly;
    model.init   = init;
    model.refin  = refin;
    model.refout = refout;
    model.xorout = xorout;
    model.check  = check;

    idx = model.width / 8 - 1;
    crc_table_funcs[idx](model.poly, model.refin, model._crc_table);
    model._crc_update_func =  (model.refin
                              ? crcr_update_funcs : crc_update_funcs)[idx];
    return ( model );
}

const crc_model_t* crc_model_by_name(const char* name,
                                     const crc_model_t crc_models[])
{
    const crc_model_t* model;
    for ( model = crc_models ; model->width ; ++model )
        if ( strcmp(model->name, name) == 0 )
            return ( model );
    return ( NULL );
}

crc_t crc_init(const crc_model_t* crc_model)
{
    crc_t crc = crc_model->init;
    if ( crc_model->refin )
        BITS_REVERSE(crc, crc_model->width, crc_t)
    return ( crc );
}

crc_t crc_update(const crc_model_t* crc_model,
                 const void* data, size_t data_len, crc_t crc)
{
    return ( crc_model->_crc_update_func(data, data_len,
                                         crc_model->_crc_table, crc) );
}

crc_t crc_finalize(const crc_model_t* crc_model, crc_t crc)
{
    if ( crc_model->refin ^ crc_model->refout )
        BITS_REVERSE(crc, crc_model->width, crc_t)
    crc ^= crc_model->xorout;
    crc &= WIDTH_MASK(crc_model->width);
    return ( crc );
}

#include "crc_predef.c"

const crc_model_t* crc_predefined_model_by_name(const char* name)
{
    crc_model_t* term = &crc_predefined_models[sizeof(crc_predefined_models) /
                                               sizeof(crc_predefined_models[0]) - 1];
    if ( ! term->name[0] )
    {
        crc_model_t* model;
        for ( model = crc_predefined_models ; model->width ; ++model )
        {
            int idx = model->width / 8 - 1;
            crc_table_funcs[idx](model->poly, model->refin, model->_crc_table);
            model->_crc_update_func = (model->refin
                                       ? crcr_update_funcs : crc_update_funcs)[idx];
        }
        ((char*)term->name)[0] = -1;
    }

    return ( crc_model_by_name(name, crc_predefined_models) );
}
