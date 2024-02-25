
set MATLAB=C:\Program Files\MATLAB\R2023a

cd .

if "%1"=="" ("C:\PROGRA~1\MATLAB\R2023a\bin\win64\gmake"  -f DC_DC_source_based_matrix_switches1.mk all) else ("C:\PROGRA~1\MATLAB\R2023a\bin\win64\gmake"  -f DC_DC_source_based_matrix_switches1.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1