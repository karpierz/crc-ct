/**
 * Filename: \file
 *
 * Copyright (c) 1994-2019 Adam Karpierz
 * Licensed under the zlib/libpng License
 * http://opensource.org/licenses/zlib/
 *
 * Purpose:
 *
 *     Predefined CRC models.
 *
 * Header:
 *    crc.h
 */

#ifndef _CRC_PREDEF_C_
#define _CRC_PREDEF_C_

#include "../../include/crc/crc.h"

typedef enum {false = 0, true = 1} bool;

/* The following table defines the parameters of well-known CRC algorithms. */

crc_model_t crc_predefined_models[] = {

    /* name             width  poly        init        refin  refout xorout      check */
    /*---------------------------------------------------------------------------------*/

    /* 8 bits */                                                                                
    {"CRC-8",               8, 0x07,       0x00,       false, false, 0x00,       0xF4},
    {"CRC-8/AUTOSAR",       8, 0x2f,       0xff,       false, false, 0xff,       0xdf},
    {"CRC-8/CDMA2000",      8, 0x9B,       0xFF,       false, false, 0x00,       0xDA},
    {"CRC-8/DARC",          8, 0x39,       0x00,       true,  true,  0x00,       0x15},
    {"CRC-8/DVB-S2",        8, 0xD5,       0x00,       false, false, 0x00,       0xBC},
    {"CRC-8/EBU",           8, 0x1D,       0xFF,       true,  true,  0x00,       0x97},
    {"CRC-8/I-CODE",        8, 0x1D,       0xFD,       false, false, 0x00,       0x7E},
    {"CRC-8/ITU",           8, 0x07,       0x00,       false, false, 0x55,       0xA1},
    {"CRC-8/MAXIM",         8, 0x31,       0x00,       true,  true,  0x00,       0xA1},
    {"CRC-8/ROHC",          8, 0x07,       0xFF,       true,  true,  0x00,       0xD0},
    {"CRC-8/WCDMA",         8, 0x9B,       0x00,       true,  true,  0x00,       0x25},

    /* 16 bits */
    {"CRC-16/IBM-3740",    16, 0x1021,     0xffff,     false, false, 0x0000,     0x29b1},
    {"CRC-16/AUTOSAR",     16, 0x1021,     0xffff,     false, false, 0x0000,     0x29b1}, /*Alias*/
    {"CRC-16/CCITT-FALSE", 16, 0x1021,     0xFFFF,     false, false, 0x0000,     0x29B1}, /*Alias*/
    {"CRC-16/ARC",         16, 0x8005,     0x0000,     true,  true,  0x0000,     0xBB3D},
    {"CRC-16/AUG-CCITT",   16, 0x1021,     0x1D0F,     false, false, 0x0000,     0xE5CC},
    {"CRC-16/BUYPASS",     16, 0x8005,     0x0000,     false, false, 0x0000,     0xFEE8},
    {"CRC-16/CDMA2000",    16, 0xC867,     0xFFFF,     false, false, 0x0000,     0x4C06},
    {"CRC-16/DDS-110",     16, 0x8005,     0x800D,     false, false, 0x0000,     0x9ECF},
    {"CRC-16/DECT-R",      16, 0x0589,     0x0000,     false, false, 0x0001,     0x007E},
    {"CRC-16/DECT-X",      16, 0x0589,     0x0000,     false, false, 0x0000,     0x007F},
    {"CRC-16/DNP",         16, 0x3D65,     0x0000,     true,  true,  0xFFFF,     0xEA82},
    {"CRC-16/EN-13757",    16, 0x3D65,     0x0000,     false, false, 0xFFFF,     0xC2B7},
    {"CRC-16/GENIBUS",     16, 0x1021,     0xFFFF,     false, false, 0xFFFF,     0xD64E},
    {"CRC-16/MAXIM",       16, 0x8005,     0x0000,     true,  true,  0xFFFF,     0x44C2},
    {"CRC-16/MCRF4XX",     16, 0x1021,     0xFFFF,     true,  true,  0x0000,     0x6F91},
    {"CRC-16/RIELLO",      16, 0x1021,     0xB2AA,     true,  true,  0x0000,     0x63D0},
    {"CRC-16/T10-DIF",     16, 0x8BB7,     0x0000,     false, false, 0x0000,     0xD0DB},
    {"CRC-16/TELEDISK",    16, 0xA097,     0x0000,     false, false, 0x0000,     0x0FB3},
    {"CRC-16/TMS37157",    16, 0x1021,     0x89EC,     true,  true,  0x0000,     0x26B1},
    {"CRC-16/USB",         16, 0x8005,     0xFFFF,     true,  true,  0xFFFF,     0xB4C8},
    {"CRC-A",              16, 0x1021,     0xc6c6,     true,  true,  0x0000,     0xBF05},
    {"CRC-16/KERMIT",      16, 0x1021,     0x0000,     true,  true,  0x0000,     0x2189},
    {"CRC-16/MODBUS",      16, 0x8005,     0xFFFF,     true,  true,  0x0000,     0x4B37},
    {"CRC-16/X-25",        16, 0x1021,     0xFFFF,     true,  true,  0xFFFF,     0x906E},
    {"CRC-16/XMODEM",      16, 0x1021,     0x0000,     false, false, 0x0000,     0x31C3},
                                                                                
 /* {"crc-16-riello",      16, 0x1021,     0x554D,     true,  true,  0x0000,     0x63D0}, */

    /* 24 bits */                                                                                
    {"CRC-24",             24, 0x864CFB,   0xB704CE,   false, false, 0x000000,   0x21CF02},
    {"CRC-24/FLEXRAY-A",   24, 0x5D6DCB,   0xFEDCBA,   false, false, 0x000000,   0x7979BD},
    {"CRC-24/FLEXRAY-B",   24, 0x5D6DCB,   0xABCDEF,   false, false, 0x000000,   0x1F23B8},

    /* 32 bits */                                                                                
    {"CRC-32",             32, 0x04C11DB7, 0xFFFFFFFF, true,  true,  0xFFFFFFFF, 0xCBF43926},
    {"CRC-32/AUTOSAR",     32, 0xf4acfb13, 0xffffffff, true,  true,  0xffffffff, 0x1697d06a},
    {"CRC-32/BZIP2",       32, 0x04C11DB7, 0xFFFFFFFF, false, false, 0xFFFFFFFF, 0xFC891918},
    {"CRC-32C",            32, 0x1EDC6F41, 0xFFFFFFFF, true,  true,  0xFFFFFFFF, 0xE3069283},
    {"CRC-32D",            32, 0xA833982B, 0xFFFFFFFF, true,  true,  0xFFFFFFFF, 0x87315576},
    {"CRC-32/JAMCRC",      32, 0x04C11DB7, 0xFFFFFFFF, true,  true,  0x00000000, 0x340BC6D9},
    {"CRC-32/MPEG-2",      32, 0x04C11DB7, 0xFFFFFFFF, false, false, 0x00000000, 0x0376E6E7},
    {"CRC-32/POSIX",       32, 0x04C11DB7, 0x00000000, false, false, 0xFFFFFFFF, 0x765E7680},
    {"CRC-32Q",            32, 0x814141AB, 0x00000000, false, false, 0x00000000, 0x3010BF7F},
    {"CRC-32/XFER",        32, 0x000000AF, 0x00000000, false, false, 0x00000000, 0xBD0BE338},

    /* 40 bits */                                                                                
    {"CRC-40/GSM", 40, 0x0004820009, 0x0000000000, false, false, 0xffffffffff, 0xd4164fc646},

    /* 64 bits */                                                                                
    {"CRC-64",     64, 0x42F0E1EBA9EA3693, 0x0000000000000000, false, false, 0x0000000000000000, 0x6C40DF5F0B497347},
    {"CRC-64/WE",  64, 0x42F0E1EBA9EA3693, 0xFFFFFFFFFFFFFFFF, false, false, 0xFFFFFFFFFFFFFFFF, 0x62EC59E3F1A4F00A},
    {"CRC-64/XZ",  64, 0x42F0E1EBA9EA3693, 0xFFFFFFFFFFFFFFFF, true,  true,  0xFFFFFFFFFFFFFFFF, 0x995DC9BBDF1939FA},

 /* {"crc-64",       64, 0x000000000000001B, 0x0000000000000000, true,  true,  0x0000000000000000, 0x46A5A9388A5BEFFE}, */
 /* {"crc-64-jones", 64, 0xAD93D23594C935A9, 0xFFFFFFFFFFFFFFFF, true,  true,  0x0000000000000000, 0xCAA717168609F281}, */

    {""},
};

#endif
