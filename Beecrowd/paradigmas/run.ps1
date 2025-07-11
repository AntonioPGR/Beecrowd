param (
  [string]$file
)
$exeName = [System.IO.Path]::GetFileNameWithoutExtension($file)
g++ $file -o $exeName".exe"
clear
Start-Process -NoNewWindow -Wait -FilePath $exeName".exe"
Remove-Item ".\$exeName.exe"
