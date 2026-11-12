@echo off
title AI Care Box - Personal Assistant
cls
echo ========================================================
echo        AI Care Box - Compilation & Execution
echo ========================================================
echo.

echo Checking build...
g++ -std=c++11 -Wall -Wextra main.cpp CareBox.cpp User.cpp ElderlyUser.cpp ProfessionalUser.cpp Reminder.cpp ReminderManager.cpp FamilyContact.cpp DailyCheckIn.cpp DailyBriefing.cpp VoiceAssistant.cpp -o AICareBox.exe

if %ERRORLEVEL% NEQ 0 (
    echo.
    echo [ERROR] Compilation failed!
    pause
    exit /b %ERRORLEVEL%
)

echo [OK] Build successful! Starting application...
echo.
AICareBox.exe
pause

