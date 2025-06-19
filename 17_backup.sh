#!/bin/bash
read -p "Enter filename to backup: " file
if [ -f "$file" ]; then
  cp $file "$file.bak"
  echo "Backup created as $file.bak"
else
  echo "File does not exist"
fi
