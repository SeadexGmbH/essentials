rem ECHO OFF

cd ../../..

rem create folder that will be archived
set essentials_new_version=%CD%\deploy\essentials

mkdir %essentials_new_version%\build\Windows
mkdir %essentials_new_version%\build\Linux

mkdir %essentials_new_version%\build\Windows\x64
mkdir %essentials_new_version%\build\Linux\x64

mkdir "%essentials_new_version%\build\Windows\x64\VS2019 142"
mkdir "%essentials_new_version%\build\Linux\x64\gcc 10"

mkdir "%essentials_new_version%\build\Windows\x64\VS2019 142\Release"
mkdir "%essentials_new_version%\build\Linux\x64\gcc 10\Release"

mkdir "%essentials_new_version%\build\Windows\x64\VS2019 142\Debug"
mkdir "%essentials_new_version%\build\Linux\x64\gcc 10\Debug"

mkdir "%essentials_new_version%\build\Windows\x64\VS2019 142\Release\bin"
mkdir "%essentials_new_version%\build\Linux\x64\gcc 10\Release\bin"

mkdir "%essentials_new_version%\build\Windows\x64\VS2019 142\Release\lib"
mkdir "%essentials_new_version%\build\Linux\x64\gcc 10\Release\lib"

mkdir "%essentials_new_version%\build\Windows\x64\VS2019 142\Debug\lib"
mkdir "%essentials_new_version%\build\Linux\x64\gcc 10\Debug\lib"


rem copy library files
copy %CD%\cmake\lib\essentials.lib "%essentials_new_version%\build\Windows\x64\VS2019 142\Release\lib"
copy %CD%\cmakeD\lib\essentials.lib "%essentials_new_version%\build\Windows\x64\VS2019 142\Debug\lib"
copy %CD%\cmakeD\lib\essentials.pdb "%essentials_new_version%\build\Windows\x64\VS2019 142\Debug\lib"

copy %CD%\cmake\lib\libessentials.so "%essentials_new_version%\build\Linux\x64\gcc 10\Release\lib"
copy %CD%\cmakeD\lib\libessentials.so "%essentials_new_version%\build\Linux\x64\gcc 10\Debug\lib"

rem copy applications
copy %CD%\cmake\bin\essentials_unit_tests.exe "%essentials_new_version%\build\Windows\x64\VS2019 142\Release\bin"
copy %CD%\cmake\bin\context_example.exe "%essentials_new_version%\build\Windows\x64\VS2019 142\Release\bin"
copy %CD%\cmake\bin\enum_example.exe "%essentials_new_version%\build\Windows\x64\VS2019 142\Release\bin"
copy %CD%\cmake\bin\logger_example.exe "%essentials_new_version%\build\Windows\x64\VS2019 142\Release\bin"
copy %CD%\cmake\bin\log_brackets.exe "%essentials_new_version%\build\Windows\x64\VS2019 142\Release\bin"

copy %CD%\cmake\bin\essentials_unit_tests "%essentials_new_version%\build\Linux\x64\gcc 10\Release\bin"
copy %CD%\cmake\bin\context_example "%essentials_new_version%\build\Linux\x64\gcc 10\Release\bin"
copy %CD%\cmake\bin\enum_example "%essentials_new_version%\build\Linux\x64\gcc 10\Release\bin"
copy %CD%\cmake\bin\logger_example "%essentials_new_version%\build\Linux\x64\gcc 10\Release\bin"
copy %CD%\cmake\bin\log_brackets "%essentials_new_version%\build\Linux\x64\gcc 10\Release\bin"

rem copy documentation
robocopy %CD%\docs\release\ %essentials_new_version%\documentation\ /E

rem remove not needed directories
rmdir /s /q %essentials_new_version%\source@tmp
rmdir /s /q %essentials_new_version%\source\.git

rem set a variable with the path of zip archive
set archiveZip=%essentials_new_version%_%1.7z

rem 7zip-ing
"C:\Program Files\7-Zip"\7z a -t7z %archiveZip% %essentials_new_version%

curl -u %2:%3 -T %archiveZip% "%4/essentials_%1.7z"


rem delete old folder
RD /Q /S %essentials_new_version%