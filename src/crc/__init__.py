# Copyright (c) 1994-2019 Adam Karpierz
# Licensed under the zlib/libpng License
# http://opensource.org/licenses/zlib/
#
# Purpose:
#     Public Python API of CRC package.

from __future__ import absolute_import

import ctypes as ct

from ._platform import CFUNC
from ._dll      import dll

class FILE(ct.Structure): pass

#
# The types of the CRC values.
#

crc8_t  = ct.c_uint8
crc16_t = ct.c_uint16
crc24_t = ct.c_uint32
crc32_t = ct.c_uint32
crc40_t = ct.c_uint64
crc56_t = ct.c_uint64
crc64_t = ct.c_uint64
# This type must be big enough to contain at least 64 bits.
crc_t   = crc64_t

# CRC Model Abstract type.
#
# The following type stores the context of an executing instance
# of the model algorithm. Most of the fields are model parameters
# which must be set before the first initializing call to each
# function crc_model_t related function.

class crc_model_t(ct.Structure):
    _fields_ = [
    # Parameters
    ("name",     ct.c_char * (32+1)),  # Name of the crt variant.
    ("width",    ct.c_int),    # Width in bits [8,32].
    ("poly",     crc_t),       # The algorithm's polynomial.
    ("init",     crc_t),       # Initial register value.
    ("refin",    ct.c_short),  # Reflect input bytes?
    ("refout",   ct.c_short),  # Reflect output CRC?
    ("xorout",   crc_t),       # XOR this to output CRC.
    ("check",    crc_t),       # CRC for the ASCII bytes "123456789".
    # Internals
    ("_crc_table", crc_t * 256),
    ("_crc_update_func", 
     CFUNC(crc_t, ct.c_void_p, ct.c_size_t, ct.POINTER(crc_t), crc_t)),
]

# Purpose:
#
#     Predefined CRC models.
#
crc_predefined_models = ct.cast(ct.c_int.in_dll(dll, "crc_predefined_models").value,
                                ct.POINTER(crc_model_t))

# Purpose:
#
#     Create new CRC model.
#
# Arguments:
#     \param[in] width    
#     \param[in] poly     
#     \param[in] init     
#     \param[in] refin   
#     \param[in] refout  
#     \param[in] xorout  
#     \param[in] check    
#     \return                 CRC model created.
#
crc_model = CFUNC(crc_model_t,
                  ct.c_char_p,
                  ct.c_int,
                  crc_t,
                  crc_t,
                  ct.c_short,
                  ct.c_short,
                  crc_t,
                  crc_t)(
                  ("crc_model", dll), (
                  (1, "name"),
                  (1, "width"),
                  (1, "poly"),
                  (1, "init"),
                  (1, "refin"),
                  (1, "refout"),
                  (1, "xorout"),
                  (1, "check"),))

# Purpose:
#
#     Find predefined CRC model.
#
# Arguments:
#     \param[in] name  CRC model name.
#     \return          CRC model found or NULL on failure.
#
crc_predefined_model_by_name = CFUNC(ct.POINTER(crc_model_t),
                                     ct.c_char_p)(
                                     ("crc_predefined_model_by_name", dll), (
                                     (1, "name"),))

# Purpose:
#
#     Find CRC model in CRC models table.
#
# Arguments:
#     \param[in] name        CRC model name.
#     \param[in] crc_models  CRC models table.
#     \return                CRC model found or NULL on failure.
#
crc_model_by_name = CFUNC(ct.POINTER(crc_model_t),
                          ct.c_char_p,
                          ct.POINTER(crc_model_t))(
                          ("crc_model_by_name", dll), (
                          (1, "name"),
                          (1, "crc_models"),))

# Purpose:
#
#     Calculate the initial CRC value.
#
# Arguments:
#     \param[in] crc_model  CRC model.
#     \return               The initial CRC value.
#
crc_init = CFUNC(crc_t,
                 ct.POINTER(crc_model_t))(
                 ("crc_init", dll), (
                 (1, "crc_model"),))

# Purpose:
#
#     Update the CRC value with new data.
#
# Arguments:
#     \param[in] crc_model  CRC model.
#     \param[in] data       Pointer to a buffer of \a data_len bytes.
#     \param[in] data_len   Number of bytes in the \a data buffer.
#     \param[in] crc        The current CRC value.
#     \return               The updated CRC value.
#
crc_update = CFUNC(crc_t,
                   ct.POINTER(crc_model_t),
                   ct.c_void_p,
                   ct.c_size_t,
                   crc_t)(
                   ("crc_update", dll), (
                   (1, "crc_model"),
                   (1, "data"),
                   (1, "data_len"),
                   (1, "crc"),))

# Purpose:
#
#     Calculate the final crc value.
#
# Arguments:
#     \param[in] crc_model  CRC model.
#     \param[in] crc        The current CRC value.
#     \return               The final   CRC value.
#
crc_finalize = CFUNC(crc_t,
                     ct.POINTER(crc_model_t),
                     crc_t)(
                     ("crc_finalize", dll), (
                     (1, "crc_model"),
                     (1, "crc"),))

del ct
