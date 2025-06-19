#!/bin/bash
echo "Enter a string:"
read str
rev_str=$(echo $str | rev)
echo "Reversed: $rev_str"
