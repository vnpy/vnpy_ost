import platform

from setuptools import Extension, setup


def get_ext_modules() -> list:
    """
    获取三方模块

    Linux需要编译封装接口
    Windows直接使用预编译的pyd即可
    Mac由于缺乏二进制库支持无法使用
    """
    if platform.system() != "Linux":
        return []

    compiler_flags = [
        "-std=c++17",
        "-O3",
        "-Wno-delete-incomplete", "-Wno-sign-compare",
    ]
    extra_link_args = ["-lstdc++"]
    runtime_library_dirs = ["$ORIGIN"]

    vnostmd = Extension(
        "vnpy_ost.api.vnostmd",
        [
            "vnpy_ost/api/vnost/vnostmd/vnostmd.cpp",
        ],
        include_dirs=["vnpy_ost/api/include",
                      "vnpy_ost/api/vnost"],
        define_macros=[],
        undef_macros=[],
        library_dirs=["vnpy_ost/api/libs", "vnpy_ost/api"],
        libraries=["DntApi", "utapi"],
        extra_compile_args=compiler_flags,
        extra_link_args=extra_link_args,
        runtime_library_dirs=runtime_library_dirs,
        depends=[],
        language="cpp",
    )

    vnosttd = Extension(
        "vnpy_ost.api.vnosttd",
        [
            "vnpy_ost/api/vnost/vnosttd/vnosttd.cpp",
        ],
        include_dirs=["vnpy_ost/api/include",
                      "vnpy_ost/api/vnost"],
        define_macros=[],
        undef_macros=[],
        library_dirs=["vnpy_ost/api/libs", "vnpy_ost/api"],
        libraries=["DntApi", "utapi"],
        extra_compile_args=compiler_flags,
        extra_link_args=extra_link_args,
        runtime_library_dirs=runtime_library_dirs,
        depends=[],
        language="cpp",
    )

    return [vnosttd, vnostmd]


setup(
    ext_modules=get_ext_modules(),
)
