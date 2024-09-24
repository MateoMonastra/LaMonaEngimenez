@echo off

rem Definir las rutas
set SourceDir1=%~dp0..\MonaEngimenez\bin\Debug\
set SourceDir2=%~dp0..\lib\glew-2.1.0\dll\
set TargetDir=%~dp0..\bin\

rem Crear el directorio de destino si no existe
if not exist "%TargetDir%" (
    mkdir "%TargetDir%"
)

rem Copiar MonaEngimenez.dll
copy "%SourceDir1%MonaEngimenez.dll" "%TargetDir%" /Y

rem Copiar glew32.dll
copy "%SourceDir2%glew32.dll" "%TargetDir%" /Y

echo Archivos copiados correctamente.
pause