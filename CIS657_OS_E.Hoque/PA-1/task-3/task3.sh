#!/bin/bash

# number of processor
cat /proc/cpuinfo | grep "processor" > processor.txt
wc -l processor.txt >> countprocessor.txt
awk '{print $1}' countprocessor.txt >> result

# show core id
cat /proc/cpuinfo | grep "core id" > coreid.txt
awk '{print $4}' coreid.txt >> result

# show cache size
cat /proc/cpuinfo | grep "cache size" >> cachesize.txt
awk '{print $4}' cachesize.txt >> result