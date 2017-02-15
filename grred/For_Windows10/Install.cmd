@echo off

:: ---------------------------------------------------------------------------
:: Settings

set FAQFileName=" §  §­ ­¨© ¯® Windows 10.lnk"
set MuiFileName=winhlp32.exe.mui
set ExeFileName=winhlp32.exe

:: ---------------------------------------------------------------------------
:: Displaying installer information

echo ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
echo ³ Windows Help program (WinHlp32) installer for Windows 7 / 8 / 8.1 / 10     ³
echo ³ Revision 4                                                                 ³
echo ³ November 27, 2015                                                          ³
echo ³ Copyright (c) 2009 Chortkeh, 2014 Drinko. All rights reserved.             ³
echo ³ Command-line scripting by Komeil Bahmanpour.                               ³
echo ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
echo.

:: ---------------------------------------------------------------------------
:: Windows version detection

echo Setup is detecting Windows version...
ver | findstr /il "10\.0\." > nul
if %errorlevel% equ 0 (
  echo Microsoft Windows 10 [Version 10.0] detected.
  set WindowsVersion=10
  goto :BypassVersionError
)
ver | findstr /il "6\.4\." > nul
if %errorlevel% equ 0 (
  echo Microsoft Windows 10 [Version 6.4] detected.
  set WindowsVersion=10
  goto :BypassVersionError
)
ver | findstr /il "6\.3\." > nul
if %errorlevel% equ 0 (
  echo Microsoft Windows 8.1 [Version 6.3] detected.
  set WindowsVersion=9
  goto :BypassVersionError
)
ver | findstr /il "6\.2\." > nul
if %errorlevel% equ 0 (
  echo Microsoft Windows 8 [Version 6.2] detected.
  set WindowsVersion=8
  goto :BypassVersionError
)
ver | findstr /il "6\.1\." > nul
if %errorlevel% equ 0 (
  echo Microsoft Windows 7 [Version 6.1] detected.
  set WindowsVersion=7
  goto :BypassVersionError
)
ver | findstr /il "6\.0\." > nul
if %errorlevel% equ 0 (
  echo Microsoft Windows Vista / Server 2008 [Version 6.0] detected.
  set WindowsVersion=6
  goto :BypassVersionError
)
ver | findstr /il "5\.2\." > nul
if %errorlevel% equ 0 (
  echo Microsoft Windows Server 2003 [Version 5.2] detected.
  set WindowsVersion=5
  goto :BypassVersionError
)
ver | findstr /il "5\.1\." > nul
if %errorlevel% equ 0 (
  echo Microsoft Windows XP [Version 5.1] detected.
  set WindowsVersion=5
  goto :BypassVersionError
)
ver | findstr /il "5\.0" > nul
if %errorlevel% equ 0 (
  echo Microsoft Windows 2000 [Version 5.0] detected.
  set WindowsVersion=5
  goto :BypassVersionError
)
echo Inappropriate Windows version. Setup must be run under one of the following
echo operating systems:
echo.
echo * Microsoft Windows 10
echo * Microsoft Windows 8.1
echo * Microsoft Windows 8
echo * Microsoft Windows 7
echo * Microsoft Windows Server 2008
echo * Microsoft Windows Vista
echo * Microsoft Windows Server 2003
echo * Microsoft Windows XP
echo * Microsoft Windows Server 2000
echo 
pause
goto :eof
:: Mandatory for older Windows versions incapable of understanding EOF,
:: eventhough they don't take CMD files as BAT.
exit

:: ---------------------------------------------------------------------------
:: Initialization

:BypassVersionError
if %WindowsVersion% lss 7 (
  echo Inappropriate Windows version. Setup must be run under one of the following
  echo operating systems:
  echo.
  echo * Microsoft Windows 10
  echo * Microsoft Windows 8.1
  echo * Microsoft Windows 8
  echo * Microsoft Windows 7
  echo 
  pause
  goto :eof
)

:: Preserve current directory for further referrings.
set InitialDirectory=%cd%
:: Change drive and path to where the batch file was started from. This is
:: required when your batch file is run-as-administrator, because it sets
:: System32 the working (current) directory.
cd /d "%0\.."

:: ---------------------------------------------------------------------------
:: Windows 10 installation
 
:InstallFor10
echo.
echo Terminating all possible running instances of WinHlp32...
taskkill /f /im %ExeFileName% /t
:: No error checking is required, becasue if it's not opened so far, an error will occur.
echo.


if %WindowsVersion%==10 (
xcopy /r /y /h /q %FAQFileName% "%USERPROFILE%\Desktop"
)

echo Taking the ownership of system's existing %MuiFileName%...
takeown /f "%SystemRoot%\en-US\%MuiFileName%"
takeown /f "%SystemRoot%\ru-RU\%MuiFileName%"
echo.
echo Granting %UserName% full-access permission to system's existing %MuiFileName%...
icacls "%SystemRoot%\en-US\%MuiFileName%" /grant "%UserName%":F
icacls "%SystemRoot%\ru-RU\%MuiFileName%" /grant "%UserName%":F
echo.
echo Copying %MuiFileName% to system...
xcopy /r /y /h /q "en-EN\%MuiFileName%" "%SystemRoot%\en-US"
xcopy /r /y /h /q "ru-RU\%MuiFileName%" "%SystemRoot%\ru-RU"
echo.
if errorlevel 1 goto :Error

echo Taking the ownership of system's existing %ExeFileName%...
takeown /f "%SystemRoot%\%ExeFileName%"
echo.
echo Granting %UserName% full-access permission to system's existing %ExeFileName%...
icacls "%SystemRoot%\%ExeFileName%" /grant "%UserName%":F
echo.
echo Copying %ExeFileName% to system...
xcopy /r /y /h /q %ExeFileName% "%SystemRoot%"
echo.
if errorlevel 1 goto :Error

echo Updating Registry entries...
reg add "HKLM\SOFTWARE\Microsoft\WinHelp" /v "AllowProgrammaticMacros" /t REG_DWORD /d "0x00000001" /f
reg add "HKLM\SOFTWARE\Microsoft\WinHelp" /v "AllowIntranetAccess" /t REG_DWORD /d "0x00000001" /f
if %PROCESSOR_ARCHITECTURE%==AMD64 (
  reg add "HKLM\SOFTWARE\Wow6432Node\Microsoft\WinHelp" /v "AllowProgrammaticMacros" /t REG_DWORD /d "0x00000001" /f
  reg add "HKLM\SOFTWARE\Wow6432Node\Microsoft\WinHelp" /v "AllowIntranetAccess" /t REG_DWORD /d "0x00000001" /f
)
echo.
if errorlevel 1 goto :Error

pause
goto :eof

:: ---------------------------------------------------------------------------
:: Error management

:Error
echo Error installing WinHlp32
echo.
echo Setup will now exit.
echo 
pause
goto :eof
