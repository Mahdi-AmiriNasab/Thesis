set MATLAB=C:\Polyspace\R2020a

cd .

if "%1"=="" ("C:\POLYSP~1\R2020a\bin\win64\gmake"  -f rtwshared.mk all) else ("C:\POLYSP~1\R2020a\bin\win64\gmake"  -f rtwshared.mk %1)
@if errorlevel 1 goto error_exit

exit 0

:error_exit
echo The make command returned an error of %errorlevel%
exit 1
