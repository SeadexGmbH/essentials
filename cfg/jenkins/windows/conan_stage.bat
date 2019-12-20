rem @ECHO OFF
conan config init --force

cd ../../../build
conan install .. -g cmake -s compiler="Visual Studio" -s compiler.version=16 -s compiler.toolset=v142 -s compiler.runtime=MD -s arch=x86_64 -s build_type=Release -s cppstd=17 --build=never
