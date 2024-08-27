@echo off

echo Copying MonaEngimenez.dll and MonaEngimenez.lib

Set sourceDir="%~1MonaEngimenez\bin\Debug\"
Set destDir="%~2Game\bin\Debug\"

xcopy /y /i %sourceDir%MonaEngimenez.dll %destDir%

echo Files copied successfully