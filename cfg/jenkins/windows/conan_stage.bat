rem @ECHO OFF
conan profile detect
conan_profiles.py

cd ../../..
conan install . -g CMakeToolchain --profile=debug --build=missing
conan install . -g CMakeToolchain --profile=release --build=missing


