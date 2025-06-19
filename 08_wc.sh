#!/bin/bash
echo "Enter file name:"
read file
if [ -f "$file" ]; then
  wc $file
else
  echo "File does not exist"
fi
