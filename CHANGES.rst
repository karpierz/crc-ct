Changelog
=========

1.2.1 (2024-01-22)
------------------
- Tox configuration has been moved to pyproject.toml
- Setup update (now based on tox >= 4.0).
- Add support for Python 3.12
- Drop support for Python 3.7
- Add support for PyPy 3.9 and 3.10
- Copyright year update.

1.2.0 (2022-08-02)
------------------
- Add support for Python 3.10 and 3.11
- Add support for PyPy 3.7, 3.8 and 3.9
- Setup update (currently based mainly on pyproject.toml).

1.1.0 (2022-01-10)
------------------
- Drop support for Python 3.6.
- Copyright year update.
- Setup update.

1.1.0rc4 (2021-07-20)
---------------------
- Setup general update and improvement.

1.1.0rc3 (2020-10-18)
---------------------
- Add support for Python 3.9.
- Drop support for Python 3.5.
- General update and cleanup.
- Fixed docs setup.

1.0.0rc9 (2020-01-16)
---------------------
- Fix for missing include stddef.h (for size_t) in crc.h
- Another fixes for gcc/Linux.
- Added ReadTheDocs config file.
- Setup update.

1.0.0rc6 (2019-11-13)
---------------------
- Drop support for Python2.
- Add support for Python 3.8.
- Setup update and cleanup.

1.0.0rc2 (2019-05-19)
---------------------
- C API has been changed in one place: crc_finalize() -> crc_final().
- Python API has been changed. It is now finally established in the
  folowing way; crc.name instead of crc.crc_name in most of cases.
- Python doc-strings update.
- Fix for error in Python definition of crc.predefined_models.
- Python tests have been improved, enhanced and fixed.
- Changes and fixes for support of Python2.
- Minor setup improvement.

1.0.0b2 (2019-05-13)
--------------------
- Python tests have been added.
- Minor setup improvements.

1.0.0b1 (2019-05-12)
--------------------
- Firt beta release.

0.0.1 (2017-05-09)
------------------
- Initial release for Python.
