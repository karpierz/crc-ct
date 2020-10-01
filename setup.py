# Copyright (c) 1994-2020 Adam Karpierz
# Licensed under the zlib/libpng License
# https://opensource.org/licenses/Zlib

from os import path
from io import open
from glob import glob
from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext

top_dir = path.dirname(path.abspath(__file__))

class BuildExt(build_ext):

    compile_args = {
        "msvc": ["/O2", "/WX", "/wd4996"],
        "unix": ["-O3", "-g0", "-ffast-math"],
    }
    link_args = {
        "msvc": ["/DEF:src/crc/crc.def"],
        "unix": [],
    }

    def build_extensions(self):
        cc_type = self.compiler.compiler_type
        compile_args = self.compile_args.get(cc_type, self.compile_args["unix"])
        link_args    = self.link_args.get(cc_type, self.link_args["unix"])
        if cc_type == "msvc":
            pass
        elif cc_type == "unix":
            pass
        for ext in self.extensions:
            ext.extra_compile_args = compile_args
        for ext in self.extensions:
            ext.extra_link_args = link_args
        build_ext.build_extensions(self)

ext_modules = [Extension(name="crc._platform.crc",
                         language="c",
                         sources=["src/crc/crc.c",
                                  "src/crc/crc_table.c",
                                  "src/crc/crc_update.c",
                                  "src/crc/crc_py.c"],
                         depends=["include/crc/crc.h",
                                  "src/crc/crc.def",
                                  "src/crc/crc_defs.h",
                                  "src/crc/crc_table.h",
                                  "src/crc/crc_update.h"])]

with open(glob(path.join(top_dir, "src/*/__about__.py"))[0],
          encoding="utf-8") as f:
    class about: exec(f.read(), None)

setup(
    name             = about.__title__,
    version          = about.__version__,
    description      = about.__summary__,
    url              = about.__uri__,
    download_url     = about.__uri__,

    author           = about.__author__,
    author_email     = about.__email__,
    maintainer       = about.__maintainer__,
    maintainer_email = about.__email__,
    license          = about.__license__,

    ext_modules = ext_modules,
    cmdclass    = dict(build_ext=BuildExt),
)
