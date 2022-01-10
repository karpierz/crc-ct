# Copyright (c) 1994-2022 Adam Karpierz
# Licensed under the zlib/libpng License
# https://opensource.org/licenses/Zlib

import unittest
import itertools

import crc


class CrcTestCase(unittest.TestCase):

    def setUp(self):

        self.check_seq = b"123456789"

        self.crc_models = (crc.model_t * (4 + 1))(
            # name                width  poly        init        refin  refout xorout      check #
            #------------------------------------------------------------------------------------#
            crc.model(b"XXX-32", 32, 0x04C11DB7, 0xFFFFFFFF, True,  True,  0xFFFFFFFF, 0xCBF43926),
            crc.model(b"YYY-32", 32, 0x04C11DB7, 0xFFFFFFFF, False, False, 0xFFFFFFFF, 0xFC891918),
            crc.model(b"ZZZ-32", 32, 0x04C11DB7, 0xFFFFFFFF, False, True,  0xFFFFFFFF, 0x1898913F),
            crc.model(b"RRR-32", 32, 0x04C11DB7, 0xFFFFFFFF, True,  False, 0xFFFFFFFF, 0x649C2FD3),
        )

        # Hacks to initialize predefined models table (only needed
        # when we iterate over the table by the index).
        crc.predefined_model_by_name(b"")

        self.crc_predefined_model_names = [crc_model.name.decode("utf-8")
                                           for crc_model in crc.predefined_models]
        self.crc_model_names = []
        for idx in itertools.count():
            crc_model = self.crc_models[idx]
            if crc_model.width == 0: break
            self.crc_model_names.append(crc_model.name.decode("utf-8"))

    def test_predefined_models(self):
        """Test of predefined CRC models"""
        for crc_model in crc.predefined_models:
            crc_result = crc.init(crc_model)
            crc_result = crc.update(crc_model, self.check_seq, 9, crc_result)
            crc_result = crc.final(crc_model, crc_result)
            self.assertEqual(crc_result, crc_model.check)
            print("{:>22}: {:016X}".format(crc_model.name.decode("utf-8"), crc_result))
        print()

    def test_user_models(self):
        """Test of user-defined CRC models"""
        for idx in itertools.count():
            crc_model = self.crc_models[idx]
            if crc_model.width == 0: break
            crc_result = crc.init(crc_model)
            crc_result = crc.update(crc_model, self.check_seq, 9, crc_result)
            crc_result = crc.final(crc_model, crc_result)
            self.assertEqual(crc_result, crc_model.check)
            print("{:>22}: {:016X}".format(crc_model.name.decode("utf-8"), crc_result))
        print()
 
    def test_predefined_models_by_name(self):
        """Test of predefined CRC models by model name"""
        for name in self.crc_predefined_model_names:
            crc_model = crc.predefined_model_by_name(name.encode("utf-8"))[0]
            self.assertEqual(name, crc_model.name.decode("utf-8"))
            crc_result = crc.init(crc_model)
            crc_result = crc.update(crc_model, self.check_seq, 9, crc_result)
            crc_result = crc.final(crc_model, crc_result)
            self.assertEqual(crc_result, crc_model.check)
            print("{:>22}: {:016X}".format(crc_model.name.decode("utf-8"), crc_result))
        print()
 
    def test_user_models_by_name(self):
        """Test of user-defined CRC models by model name"""
        for name in self.crc_model_names:
            crc_model = crc.model_by_name(name.encode("utf-8"), self.crc_models)[0]
            self.assertEqual(name, crc_model.name.decode("utf-8"))
            crc_result = crc.init(crc_model)
            crc_result = crc.update(crc_model, self.check_seq, 9, crc_result)
            crc_result = crc.final(crc_model, crc_result)
            self.assertEqual(crc_result, crc_model.check)
            print("{:>22}: {:016X}".format(crc_model.name.decode("utf-8"), crc_result))
        print()
