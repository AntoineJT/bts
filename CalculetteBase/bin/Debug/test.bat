@ECHO OFF
calculettebase.exe 2>stderr.txt 
REM PAUSE>NUL
ECHO.
ECHO ERRORS
ECHO -------
REM ECHO.
TYPE stderr.txt
ECHO.
PAUSE>NUL