import platform

from setuptools import Extension, setup


def get_ext_modules() -> list:
    """
    获取三方模块
    Linux和Windows需要编译封装接口
    Mac由于缺乏二进制库支持无法使用
    """
    if platform.system() == "Linux":
        extra_compile_flags = [
            "-std=c++17",
            "-O3",
            "-Wno-delete-incomplete",
            "-Wno-sign-compare",
        ]
        extra_link_args = ["-lstdc++"]
        runtime_library_dirs = ["$ORIGIN"]

    elif platform.system() == "Windows":
        extra_compile_flags = ["-O2", "-MT"]
        extra_link_args = []
        runtime_library_dirs = []

    else:
        return []

    vnostmd = Extension(
        name="vnpy_ost.api.vnostmd",
        sources=["vnpy_ost/api/vnost/vnostmd/vnostmd.cpp"],
        include_dirs=["vnpy_ost/api/include", "vnpy_ost/api/vnost"],
        library_dirs=["vnpy_ost/api/libs", "vnpy_ost/api"],
        libraries=["DntApi", "utapi"],
        extra_compile_args=extra_compile_flags,
        extra_link_args=extra_link_args,
        runtime_library_dirs=runtime_library_dirs,
        language="cpp",
    )

    vnosttd = Extension(
        name="vnpy_ost.api.vnosttd",
        sources=["vnpy_ost/api/vnost/vnosttd/vnosttd.cpp"],
        include_dirs=["vnpy_ost/api/include", "vnpy_ost/api/vnost"],
        library_dirs=["vnpy_ost/api/libs", "vnpy_ost/api"],
        libraries=["DntApi", "utapi"],
        extra_compile_args=extra_compile_flags,
        extra_link_args=extra_link_args,
        runtime_library_dirs=runtime_library_dirs,
        language="cpp",
    )

    return [vnosttd, vnostmd]


setup(ext_modules=get_ext_modules())
