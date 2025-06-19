#!/bin/bash
read -p "Enter base: " base
read -p "Enter exponent: " exp
result=$((base ** exp))
echo "$base ^ $exp = $result"
