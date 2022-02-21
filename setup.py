import platform

from setuptools import Extension, setup


def get_ext_modules() -> list:
    """
    获取三方模块
    Windos需要编译使用
    Linux暂未支持
    Mac由于缺乏二进制库支持无法使用
    """

    extra_compile_flags = ["-O2", "-MT"]
    extra_link_args = []
    runtime_library_dirs = []

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
