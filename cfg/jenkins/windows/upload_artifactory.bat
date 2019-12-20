echo create conan package:
cd "%cd%\..\..\..\"
mkdir conan
cd conan
mkdir essentials
cd essentials

SET conanEssentials=%cd%\..\..\..\conan\essentials

mkdir %conanEssentials%\include
robocopy "%cd%\..\..\..\essentials\include" %conanEssentials%\include\ /s /e

mkdir %conanEssentials%\lib
mkdir %conanEssentials%\libd

rem Windows files
copy %cd%\..\..\..\cmake\lib\essentials.lib %conanEssentials%\lib\
copy %cd%\..\..\..\cmakeD\lib\essentials.lib %conanEssentials%\libd\
copy %cd%\..\..\..\cmakeD\lib\essentials.pdb %conanEssentials%\libd\

rem Linux files
copy %cd%\..\..\..\cmake\lib\libessentials.so %conanEssentials%\lib\
copy %cd%\..\..\..\cmakeD\lib\libessentials.so %conanEssentials%\libd\

cd %conanEssentials%

conan new essentials/%1
del conanfile.py

@echo off

(
echo from conans import ConanFile, tools
echo import os
echo[
echo required_conan_version = ^"^>=1.33.0^"
echo[
echo class essentialsConan^(ConanFile^)^:
echo     name = ^"essentials^"
echo     version = ^"^%1^"
echo     license = ^"^<Put the package license here^>^"
echo     description = ^"Seadex essentials library.^"
echo     topics = ^(^"conan^", ^"essentials^", ^"Seadex^"^)
echo     url = ^"http^://essentials.seadex.de^"
echo     options = {^"shared^"^: [True, False]}
echo     default_options = {^"shared^"^: False}
echo     settings = {^"os^"^: [^"Linux^", ^"Windows^"], ^"build_type^"^: [^"Debug^", ^"Release^"]}
echo[
echo     def build_id^(self^)^:
echo         self.info_build.settings.build_type = ^"Any^"
echo[
echo     def package^(self^)^:
echo         self.copy^(^"*.hpp^", dst=^"^", src=^"^"^)
echo         if self.settings.os ^=^= ^"Linux^"^:
echo             if self.settings.build_type ^=^= ^"Release^"^:
echo                 self.copy^(^"*.so^", dst=^"lib^", src=^"lib^", keep_path=False^)
echo                 self.copy^(^"*.a^", dst=^"lib^", src=^"lib^", keep_path=False^)
echo             else^:
echo                 self.copy^(^"*.so^", dst=^"lib^", src=^"libd^", keep_path=False^)
echo                 self.copy^(^"*.a^", dst=^"lib^", src=^"libd^", keep_path=False^)
echo         else^:
echo             if self.settings.build_type ^=^= ^"Debug^"^:
echo                 self.copy^(^"*.lib^", dst=^"lib^", src=^"libd^", keep_path=False^)
echo                 self.copy^(^"*.dll^", dst=^"lib^", src=^"libd^", keep_path=False^)
echo                 self.copy^(^"*.pdb^", dst=^"lib^", src=^"libd^", keep_path=False^)
echo             else^:
echo                 self.copy^(^"*.lib^", dst=^"lib^", src=^"lib^", keep_path=False^)
echo                 self.copy^(^"*.dll^", dst=^"lib^", src=^"lib^", keep_path=False^)
echo[
echo     def package_info^(self^)^:
echo         self.cpp_info.names[^"cmake_find_package^"] = ^"essentials^"
echo         self.cpp_info.names[^"cmake_find_package_multi^"] = ^"essentials^"
echo         self.cpp_info.names[^"cmake^"] = ^"essentials^"
echo         self.cpp_info.libs = [^"essentials^"]
) > conanfile.py

type conanfile.py 

@echo on


conan remote add sxConan %4 False -f --insert

SET VS_version=15
SET toolSetVersion="v142"
SET runtime=MD

conan export-pkg . essentials/%1@sxConan/stable -s os=Windows -s compiler="Visual Studio" -s compiler.version=%VS_version% -s compiler.toolset=%toolSetVersion% -s compiler.runtime=%runtime% -s build_type=Release

SET runtime=MDd
conan export-pkg . essentials/%1@sxConan/stable -s os=Windows -s compiler="Visual Studio" -s compiler.version=%VS_version% -s compiler.toolset=%toolSetVersion% -s compiler.runtime=%runtime% -s build_type=Debug

conan export-pkg . essentials/%1@sxConan/stable -s os=Linux -s compiler=gcc -s compiler.version=10  -s compiler.libcxx=libstdc++11 -s build_type=Release
conan export-pkg . essentials/%1@sxConan/stable -s os=Linux -s compiler=gcc -s compiler.version=10  -s compiler.libcxx=libstdc++11 -s build_type=Debug

SET CONAN_NON_INTERACTIVE=1

conan user %2 -r sxConan -p %3
conan upload essentials/%1@sxConan/stable -r sxConan --all --force

conan remote remove sxConan