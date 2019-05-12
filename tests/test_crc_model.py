# Copyright (c) 2004-2019 Adam Karpierz
# Licensed under proprietary License
# Please refer to the accompanying LICENSE file.

from __future__ import absolute_import

import unittest

import crc


class TypeHandlerABCTestCase(unittest.TestCase):

    def setUp(self):

        self.check_seq = b"123456789";
        self.crc_predefined_models_names = [

            # 8 bits                                                                                
            b"CRC-8",               
            b"CRC-8/AUTOSAR",       
            b"CRC-8/CDMA2000",      
            b"CRC-8/DARC",          
            b"CRC-8/DVB-S2",        
            b"CRC-8/EBU",           
            b"CRC-8/I-CODE",        
            b"CRC-8/ITU",           
            b"CRC-8/MAXIM",         
            b"CRC-8/ROHC",          
            b"CRC-8/WCDMA",         

            # 16 bits
            b"CRC-16/IBM-3740",   
            b"CRC-16/AUTOSAR",    
            b"CRC-16/CCITT-FALSE",
            b"CRC-16/ARC",        
            b"CRC-16/AUG-CCITT",  
            b"CRC-16/BUYPASS",    
            b"CRC-16/CDMA2000",   
            b"CRC-16/DDS-110",    
            b"CRC-16/DECT-R",     
            b"CRC-16/DECT-X",     
            b"CRC-16/DNP",        
            b"CRC-16/EN-13757",   
            b"CRC-16/GENIBUS",    
            b"CRC-16/MAXIM",      
            b"CRC-16/MCRF4XX",    
            b"CRC-16/RIELLO",     
            b"CRC-16/T10-DIF",    
            b"CRC-16/TELEDISK",   
            b"CRC-16/TMS37157",   
            b"CRC-16/USB",        
            b"CRC-A",             
            b"CRC-16/KERMIT",     
            b"CRC-16/MODBUS",     
            b"CRC-16/X-25",       
            b"CRC-16/XMODEM",     
                                  
            # 24 bits          
            b"CRC-24",            
            b"CRC-24/FLEXRAY-A",  
            b"CRC-24/FLEXRAY-B",  

            # 32 bits          
            b"CRC-32",            
            b"CRC-32/AUTOSAR",    
            b"CRC-32/BZIP2",      
            b"CRC-32C",           
            b"CRC-32D",           
            b"CRC-32/JAMCRC",     
            b"CRC-32/MPEG-2",     
            b"CRC-32/POSIX",      
            b"CRC-32Q",           
            b"CRC-32/XFER",       

            # 40 bits                                                                                
            b"CRC-40/GSM",

            # 64 bits                                                                                
            b"CRC-64",
            b"CRC-64/WE",
            b"CRC-64/XZ",
        ]
        self.crc_models = [
            # name                width  poly        init        refin  refout xorout      check #
            #------------------------------------------------------------------------------------#
            crc.crc_model(b"XXX-32", 32, 0x04C11DB7, 0xFFFFFFFF, True,  True,  0xFFFFFFFF, 0xCBF43926),
            crc.crc_model(b"YYY-32", 32, 0x04C11DB7, 0xFFFFFFFF, False, False, 0xFFFFFFFF, 0xFC891918),
            crc.crc_model(b"ZZZ-32", 32, 0x04C11DB7, 0xFFFFFFFF, False, True,  0xFFFFFFFF, 0x1898913F),
            crc.crc_model(b"RRR-32", 32, 0x04C11DB7, 0xFFFFFFFF, True,  False, 0xFFFFFFFF, 0x649C2FD3),
        ]

    def test_predefined_models(self):

        for name in self.crc_predefined_models_names:
            crc_model  = crc.crc_predefined_model_by_name(name)[0]
            crc_result = crc.crc_init(crc_model)
            crc_result = crc.crc_update(crc_model, self.check_seq, 9, crc_result)
            crc_result = crc.crc_finalize(crc_model, crc_result)
            print("%22s: %016X, (should be: %016X), %s" % (
                  crc_model.name, crc_result, crc_model.check,
                  "Ok" if crc_result == crc_model.check else "Error!"))
        print()

    def test_models(self):

        for crc_model in self.crc_models:
            crc_result = crc.crc_init(crc_model)
            crc_result = crc.crc_update(crc_model, self.check_seq, 9, crc_result)
            crc_result = crc.crc_finalize(crc_model, crc_result)
            print("%22s: %016X, (should be: %016X), %s" % (
                  crc_model.name, crc_result, crc_model.check,
                  "Ok" if crc_result == crc_model.check else "Error!"))
        print()
