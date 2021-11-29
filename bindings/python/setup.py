from pathlib import Path
from setuptools import setup, Extension

setup(
    name             = 'ufal.nametag',
    version          = '1.1.2.1',
    description      = 'Bindings to NameTag library',
    author           = 'Milan Straka',
    author_email     = 'straka@ufal.mff.cuni.cz',
    url              = 'http://ufal.mff.cuni.cz/nametag',
    license          = 'MPL 2.0',
    py_modules       = ['ufal.nametag'],
    setup_requires   = ['wheel'],
    ext_modules      = [Extension(
        'ufal.ufal_nametag',
        ['../../src_lib_only/nametag.cpp', 'nametag_python.cpp'],
        language = 'c++',
        include_dirs = ['../../src_lib_only'],
        extra_compile_args = ['-std=c++11', '-fvisibility=hidden', '-w'])],
    classifiers = [
        'Development Status :: 5 - Production/Stable',
        'License :: OSI Approved :: Mozilla Public License 2.0 (MPL 2.0)',
        'Programming Language :: C++',
        'Programming Language :: Python',
        'Programming Language :: Python :: 2',
        'Programming Language :: Python :: 3',
        'Topic :: Software Development :: Libraries'
    ]
)
