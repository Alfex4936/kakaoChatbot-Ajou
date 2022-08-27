from distutils.core import setup

from Cython.Build import cythonize

setup(
    ext_modules=cythonize(
        module_list=["kakao.py"],
        compiler_directives=dict(
            c_string_encoding="utf-8",
            language_level=3,
        ),
    )
)
