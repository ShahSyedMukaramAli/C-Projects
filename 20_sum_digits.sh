#!/bin/bash
read -p "Enter number: " n
sum=0
while [ $n -gt 0 ]
do
  digit=$((n % 10))
  sum=$((sum + digit))
  n=$((n / 10))
done
echo "Sum of digits: $sum"
