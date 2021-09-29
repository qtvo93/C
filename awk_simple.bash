#!/bin/bash

awk -F ',' -v OFS="," '{print $0}' people.txt

awk -F ',' '/gmail\.com/ {print ($0, "matched")}' people.txt

File=$1
if [[ -f "$File" ]]; then
	awk -F ',' -v OFS=',' '{print $0}' "$File"
else
	awk -F ',' -v OFS=',' '{print $0}' students.txt
fi

cd ~/cs265/lab5

mkdir A5
rm -rf ~/cs265/lab5/A5/*

cd ~/cs265/lab5
awk -F ',' -v OFS="." '{print $1, $2, $3}' students.txt | xargs mkdir -p


