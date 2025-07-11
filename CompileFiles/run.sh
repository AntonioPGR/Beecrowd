file="$1"
exeName="${file%.*}"
g++ "$file" -o "$exeName"
clear
"./$exeName"
rm "./$exeName"
