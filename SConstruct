#!/usr/bin/env python
import os
import sys

env = SConscript("godot-cpp/SConstruct")

# For reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

env.Append(CPPDEFINES=["GDEXTENSION"])

# tweak this if you want to use different folders, or more folders, to store your source code in.
env.Append(CPPPATH=["src/"])
sources = Glob("src/*.cpp")

if env["platform"] == "windows":
    # IPP library
    env.Append(CPPPATH=["/opt/intel/oneapi/ipp/latest/include/"])
    env.Append(LINKFLAGS=["-Llibs/"])
    if env.get("is_msvc", True):
        env.Append(LINKFLAGS=["setupapi.lib", "Advapi32.lib"])
    else:
        env.Append(LIBS=["setupapi", "Advapi32"])
elif env["platform"].startswith("linux"):
    # IPP library
    env.Append(CPPPATH=["/opt/intel/oneapi/ipp/latest/include/"])
    env.Append(LINKFLAGS=["-Llibs/"])
    #env.Append(LINKFLAGS=[
    #    "/opt/intel/oneapi/ipp/latest/lib/libipps.a",
    #    "/opt/intel/oneapi/ipp/latest/lib/libippvm.a",
    #    "/opt/intel/oneapi/ipp/latest/lib/libippcore.a",
    #])
    env.Append(LIBS=["ipps", "ippvm", "ippcore"])

if env["platform"] == "macos":
    library = env.SharedLibrary(
        "addons/ipp/bin/libgdexample.{}.{}.framework/libipp.{}.{}".format(
            env["platform"], env["target"], env["platform"], env["target"]
        ),
        source=sources,
    )
else:
    library = env.SharedLibrary(
        "addons/ipp/bin/libipp{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )

Default(library)

