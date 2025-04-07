@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"
setlocal
set VSCODE_INSTALL_DIR=C:\appdata\VSCode-win32-x64-1.97.2
set VSCODE_DEV=
set ELECTRON_RUN_AS_NODE=1
start "" "%VSCODE_INSTALL_DIR%\Code.exe" "%VSCODE_INSTALL_DIR%\resources\app\out\cli.js" %~dp0.."
endlocal
