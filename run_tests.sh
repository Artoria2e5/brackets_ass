#!/bin/bash

if [[ ! -x ./check_brackets ]]; then
	echo "i dont think you compiled it">&2
	exit 1
fi

for f in inputs/*; do
	basef=$(basename "$f")
	./check_brackets < "$basef" > "outputs/$basef.b"
	if !diff "outputs/$basef.a" "outputs/$basef.b"; then
		echo "You messed $basef up. See above for the difference."
	fi
done
