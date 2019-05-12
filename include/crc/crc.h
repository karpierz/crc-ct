/**
 * Filename: \file
 *
 * Copyright (c) 1994-2019 Adam Karpierz
 * Licensed under the zlib/libpng License
 * http://opensource.org/licenses/zlib/
 *
 * Purpose:
 *
 *     Public API of CRC package.
 *
 * Header:
 *     crc.h
 */

#ifndef _CRC_H_
#define _CRC_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * The types of the CRC values.
 */
typedef uint8_t  crc8_t;
typedef uint16_t crc16_t;
typedef uint32_t crc24_t;
typedef uint32_t crc32_t;
typedef uint64_t crc40_t;
typedef uint64_t crc48_t;
typedef uint64_t crc56_t;
typedef uint64_t crc64_t;
/**
 * This type must be big enough to contain at least 64 bits.
 */
typedef crc64_t crc_t;

/**
 * CRC Model Abstract type.
 *
 * The following type stores the context of an executing instance
 * of the model algorithm. Most of the fields are model parameters
 * which must be set before the first initializing call to each
 * function crc_model_t related function.
 */
typedef struct
{   /* Parameters */
    const char name[32 + 1]; /* Name of the crt variant.    */
    int   width;             /* Width in bits [8,32].       */
    crc_t poly;              /* The algorithm's polynomial. */
    crc_t init;              /* Initial register value.     */
    short refin;             /* Reflect input bytes?        */
    short refout;            /* Reflect output CRC?         */
    crc_t xorout;            /* XOR this to output CRC.     */
    crc_t check;             /* CRC for the ASCII bytes "123456789". */
    /* Internals */
    crc_t _crc_table[256];
    crc_t (*_crc_update_func)(const void* data, size_t data_len,
                              const crc_t crc_table[], crc_t crc);
} crc_model_t;

/**
 * Purpose:
 *
 *     Predefined CRC models.
 */
extern crc_model_t crc_predefined_models[];

/**
 * Purpose:
 *
 *     Create new CRC model.
 *
 * Arguments:
 *     \param[in] width    
 *     \param[in] poly     
 *     \param[in] init     
 *     \param[in] refin   
 *     \param[in] refout  
 *     \param[in] xorout  
 *     \param[in] check    
 *     \return                 CRC model created.
 */
const crc_model_t crc_model(const char* name,
                            int   width,
                            crc_t poly,
                            crc_t init,
                            short refin,
                            short refout,
                            crc_t xorout,
                            crc_t check);

/**
 * Purpose:
 *
 *     Find predefined CRC model.
 *
 * Arguments:
 *     \param[in] name  CRC model name.
 *     \return          CRC model found or NULL on failure.
 */
const crc_model_t* crc_predefined_model_by_name(const char* name);


/**
 * Purpose:
 *
 *     Find CRC model in CRC models table.
 *
 * Arguments:
 *     \param[in] name        CRC model name.
 *     \param[in] crc_models  CRC models table.
 *     \return                CRC model found or NULL on failure.
 */
const crc_model_t* crc_model_by_name(const char* name,
                                     const crc_model_t crc_models[]);

/**
 * Purpose:
 *
 *     Calculate the initial CRC value.
 *
 * Arguments:
 *     \param[in] crc_model  CRC model.
 *     \return               The initial CRC value.
 */
crc_t crc_init(const crc_model_t* crc_model);

/**
 * Purpose:
 *
 *     Update the CRC value with new data.
 *
 * Arguments:
 *     \param[in] crc_model  CRC model.
 *     \param[in] data       Pointer to a buffer of \a data_len bytes.
 *     \param[in] data_len   Number of bytes in the \a data buffer.
 *     \param[in] crc        The current CRC value.
 *     \return               The updated CRC value.
 */
crc_t crc_update(const crc_model_t* crc_model,
                 const void* data, size_t data_len, crc_t crc);

/**
 * Purpose:
 *
 *     Calculate the final crc value.
 *
 * Arguments:
 *     \param[in] crc_model  CRC model.
 *     \param[in] crc        The current CRC value.
 *     \return               The final   CRC value.
 */
crc_t crc_finalize(const crc_model_t* crc_model, crc_t crc);

#ifdef __cplusplus
}
#endif

#endif
