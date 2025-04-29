Changelog
=========

1.4.0 (2025-04-28)
------------------
- Add support for Python 3.14
- Drop support for Python 3.9 (due to compatibility issues).
- Update readthedocs's python to version 3.13
- Update tox's base_python to version 3.13
- Setup (dependencies) update.

1.3.5 (2025-02-14)
------------------
- Setup (dependencies) update.

1.3.4 (2025-01-20)
------------------
- Copyright year update.
- Setup (dependencies) update.

1.3.3 (2024-12-13)
------------------
- Source distribution (\*.tar.gz now) is compliant with PEP-0625.
- 100% code linting.
- Tox configuration is now in native (toml) format.
- Setup (dependencies) update.

1.3.2 (2024-10-30)
------------------
- Setup (dependencies) update.

1.3.1 (2024-10-09)
------------------
- Setup (dependencies) update.

1.3.0 (2024-09-30)
------------------
- Drop support for Python 3.8
- Setup (dependencies) update.

1.2.4 (2024-08-13)
------------------
- Add support for Python 3.13
- Setup (dependencies) update.

1.2.3 (2024-01-26)
------------------
- Cleanup.

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
- Add support for Python 3.9.
- Drop support for Python 3.5 and 3.6.
- Copyright year update.
- Setup general update and improvement.
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
- Python tests have been added.
- Changes and fixes for support of Python2.
- Minor setup improvements.

1.0.0b1 (2019-05-12)
--------------------
- Firt beta release.

0.0.1 (2017-05-09)
------------------
- Initial release for Python.
