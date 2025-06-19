#!/bin/bash
echo "1. Date"
echo "2. List files"
echo "3. Whoami"
echo "Enter choice:"
read ch
case $ch in
  1) date ;;
  2) ls ;;
  3) whoami ;;
  *) echo "Invalid option" ;;
esac
