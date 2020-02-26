#!/bin/bash
mkdir assignment-1
cd assignment-1
for i in `seq 1 10`;
do
	mkdir Query-$i
	touch Query-$i/response-$i.sh
done  
