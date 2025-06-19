#!/bin/bash
read -p "Enter filename: " file
if [ -f "$file" ]; then
  while read line; do
    echo "$line"
  done < $file
else
  echo "File not found"
fi
