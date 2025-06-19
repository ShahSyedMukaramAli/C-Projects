#!/bin/bash
read -p "Enter path: " name
if [ -d "$name" ]; then
  echo "It is a directory"
elif [ -f "$name" ]; then
  echo "It is a regular file"
else
  echo "Not found"
fi
