#!/bin/bash

echo 'Configure conan ...'
conan config init
conan profile update settings.compiler.libcxx=libstdc++11 default

echo 'Install conan ...'

cd ../../../build
conan install .. -g cmake -s compiler="gcc" -s arch=x86_64 -s build_type=Release --build=never -s cppstd=17
conan install .. -g cmake -s compiler="gcc" -s arch=x86_64 -s build_type=Debug --build=never -s cppstd=17