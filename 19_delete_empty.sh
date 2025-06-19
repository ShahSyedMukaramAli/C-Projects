#!/bin/bash
for file in *; do
  if [ -f "$file" ] && [ ! -s "$file" ]; then
    echo "Deleting empty file: $file"
    rm "$file"
  fi
done
