@echo off
setlocal
set py=C:\Windows\py.exe -3.7 -B
set py2=C:\Windows\py.exe -2.7 -B
set vc32="%ProgramFiles(x86)%\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars32.bat"
set vc64="%ProgramFiles(x86)%\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars64.bat"
pushd "%~dp0"
rem # for jni.cffi
rem del /F/Q src\crc\cffi\jni.py 2> nul
rem %py% -c "import sys;sys.path.insert(0, 'src/jt');import jni.cffi"
rem # for jni C API
%py% setup.py build_ext --inplace
popd
pushd "%~dp0"\tests
popd
endlocal
