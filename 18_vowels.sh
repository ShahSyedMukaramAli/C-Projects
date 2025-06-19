#!/bin/bash
read -p "Enter string: " str
count=$(echo "$str" | grep -o -i "[aeiou]" | wc -l)
echo "Vowel count: $count"
