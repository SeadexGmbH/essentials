rem @ECHO OFF
conan profile detect
conan_profiles.py

cd ../../..
conan install . -g CMakeToolchain --profile=debug --build=missing -s build_type=Debug -of win-cmaked
conan install . -g CMakeToolchain --profile=release --build=missing -s build_type=Release -of win-cmake


