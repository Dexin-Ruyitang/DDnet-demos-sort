echo off
echo This script can only run on CMD
pause
REM
set a=60
set b=300
set c=600
set d=1800
set e=3600
REM
for %%f in (*.demo) do (
    REM readTWDemoLenth.exe %%f
    for /f "tokens=3" %%i in ('readTWDemoLenth.exe %%f') do set len=%%i
    REM echo %len%
    if %len% GTR 0 (
        if %len% LEQ %a% (
            move %%f .\demo-01m\
        ) else if %len% LEQ %b% (
            move %%f .\demo-05m\
        ) else if %len% LEQ %c% (
            move %%f .\demo-10m\
        ) else if %len% LEQ %d% (
            move %%f .\demo-30m\
        ) else if %len% LEQ %e% (
            move %%f .\demo-60m\
        )
        REM echo %len%
    )
)