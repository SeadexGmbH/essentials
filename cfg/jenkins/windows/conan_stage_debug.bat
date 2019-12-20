rem @ECHO OFF
cd ../../../build
conan install .. -g cmake -s compiler="Visual Studio" -s compiler.version=16 -s compiler.toolset=v142 -s compiler.runtime=MDd -s arch=x86_64 -s build_type=Debug --build=never -s cppstd=17
