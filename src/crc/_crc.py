# Copyright (c) 1994-2022 Adam Karpierz
# Licensed under the zlib/libpng License
# https://opensource.org/licenses/Zlib

"""Public Python API of CRC package."""

import ctypes as ct
import itertools

from ._platform import CFUNC
from ._dll      import dll

class FILE(ct.Structure): pass

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

class model_t(ct.Structure):
    """CRC Model Abstract type.

    The following type stores the context of an executing instance
    of the model algorithm. Most of the fields are model parameters
    which must be set before the first initializing call to each
    function crc.model_t related function.
    """
    _fields_ = [
    # Parameters
    ("name",   ct.c_char * (32+1)),  # Name of the CRC variant.
    ("width",  ct.c_int),    # Width in bits [8,32].
    ("poly",   crc_t),       # The algorithm's polynomial.
    ("init",   crc_t),       # Initial register value.
    ("refin",  ct.c_short),  # Reflect input bytes?
    ("refout", ct.c_short),  # Reflect output CRC?
    ("xorout", crc_t),       # XOR this to output CRC.
    ("check",  crc_t),       # CRC for the ASCII bytes "123456789".
    # Internals
    ("_crc_table", crc_t * 256),
    ("_crc_update_func",
     CFUNC(crc_t, ct.c_void_p, ct.c_size_t, ct.POINTER(crc_t), crc_t)),
]

# Predefined CRC models.
#
predefined_models = (model_t * 1000).in_dll(dll, "crc_predefined_models")
for size in itertools.count():
    if predefined_models[size].width == 0: break
predefined_models = (model_t * size).in_dll(dll, "crc_predefined_models")

model = CFUNC(model_t,
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
model.__doc__ = \
"""Create new CRC model.

Args:
    name   (bytes):     Name of the CRC variant.
    width  (int):       Width in bits [8,32].
    poly   (crc.crc_t): The algorithm's polynomial.
    init   (crc.crc_t): Initial register value.
    refin  (bool):      Reflect input bytes?
    refout (bool):      Reflect output CRC?
    xorout (crc.crc_t): XOR this to output CRC.
    check  (crc.crc_t): CRC for the ASCII bytes "123456789".

Returns:
    crc.model_t: CRC model created.
"""

predefined_model_by_name = CFUNC(ct.POINTER(model_t),
                                 ct.c_char_p)(
                                 ("crc_predefined_model_by_name", dll), (
                                 (1, "name"),))
predefined_model_by_name.__doc__ = \
"""Find predefined CRC model.

Args:
    name (bytes): CRC model name.

Returns:
    ctypes.POINTER(crc.model_t): CRC model found or NULL on failure.
"""

model_by_name = CFUNC(ct.POINTER(model_t),
                      ct.c_char_p,
                      ct.POINTER(model_t))(
                      ("crc_model_by_name", dll), (
                      (1, "name"),
                      (1, "crc_models"),))
model_by_name.__doc__ = \
"""Find CRC model in CRC models table.

Args:
    name       (bytes):                      CRC model name.
    crc_models (ctypes.POINTER(crc.model_t): CRC models table.

Returns:
    ctypes.POINTER(crc.model_t): CRC model found or NULL on failure.
"""

init = CFUNC(crc_t,
             ct.POINTER(model_t))(
             ("crc_init", dll), (
             (1, "crc_model"),))
init.__doc__ = \
"""Calculate the initial CRC value.

Args:
    crc_model (ctypes.POINTER(crc.model_t)): CRC model.

Returns:
    crc.crc_t: The initial CRC value.
"""

update = CFUNC(crc_t,
               ct.POINTER(model_t),
               ct.c_void_p,
               ct.c_size_t,
               crc_t)(
               ("crc_update", dll), (
               (1, "crc_model"),
               (1, "data"),
               (1, "data_len"),
               (1, "crc"),))
update.__doc__ = \
"""Update the CRC value with new data.

Args:
    crc_model (ctypes.POINTER(crc.model_t)): CRC model.
    data      (ctypes.c_void_p): Pointer to a buffer of data_len bytes.
    data_len  (int):             Number of bytes in the data buffer.
    crc       (crc.crc_t):       The current CRC value.

Returns:
    crc.crc_t: The updated CRC value.
"""

final = CFUNC(crc_t,
              ct.POINTER(model_t),
              crc_t)(
              ("crc_final", dll), (
              (1, "crc_model"),
              (1, "crc"),))
final.__doc__ = \
"""Calculate the final crc value.

Args:
    crc_model (ctypes.POINTER(crc.model_t)): CRC model.
    crc       (crc.crc_t): The current CRC value.

Returns:
    crc.crc_t: The final CRC value.
"""

del ct
del itertools
