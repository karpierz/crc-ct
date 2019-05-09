crc-ct
======

Reverse enumerate.

Overview
========

**renumerate(sequence, start=len(sequence)-1, end=0):**

  | Return an enumerate_ object.
  | *sequence* must be an object that has a __reversed__() method or supports the
  | sequence protocol (the __len__() method and the __getitem__() method with
  | integer arguments starting at 0).
  | The __next__() method of the iterator returned by renumerate() returns a tuple
  | containing a count (from *start* which defaults to len(*sequence*) - 1 or ends at
  | *end* which defaults to 0 - but not both) and the values obtained from reverse
  | iterating over *sequence*.

.. code:: python

  >>> from renumerate import renumerate
  >>> seasons = ['Spring', 'Summer', 'Fall', 'Winter']
  >>> list(renumerate(seasons))
  [(3, 'Winter'), (2, 'Fall'), (1, 'Summer'), (0, 'Spring')]
  >>> list(renumerate(seasons, start=4))
  [(4, 'Winter'), (3, 'Fall'), (2, 'Summer'), (1, 'Spring')]
  >>> list(renumerate(seasons, end=2))
  [(5, 'Winter'), (4, 'Fall'), (3, 'Summer'), (2, 'Spring')]

Equivalent to:

.. code:: python

  def renumerate(sequence, start=None, end=None):
      if start is not None and end is not None:
          raise TypeError("renumerate() only accepts start argument or end argument"
                          " - not both.")
      if start is None: start = len(sequence) - 1
      if end   is None: end   = 0
      n = start + end
      for elem in reversed(sequence):
          yield n, elem
          n -= 1

Installation
============

Prerequisites:

+ Python 2.7 or Python 3.4 or later

  * http://www.python.org/
  * 2.7 and 3.6 are primary test environments.

+ pip and setuptools

  * http://pypi.python.org/pypi/pip
  * http://pypi.python.org/pypi/setuptools

To install run::

    python -m pip install --upgrade crc-ct

Development
===========

Visit `development page <https://github.com/karpierz/crc-ct>`__

Installation from sources:

Clone the `sources <https://github.com/karpierz/crc-ct>`__ and run::

    python -m pip install ./crc-ct

or on development mode::

    python -m pip install --editable ./crc-ct

Prerequisites:

+ Development is strictly based on *tox*. To install it run::

    python -m pip install tox

License
=======

  | Copyright (c) 1994-2019 Adam Karpierz
  |
  | Licensed under the zlib/libpng License
  | http://opensource.org/licenses/zlib
  | Please refer to the accompanying LICENSE file.

Authors
=======

* Adam Karpierz <adam@karpierz.net>

.. _enumerate: http://docs.python.org/library/functions.html#enumerate
