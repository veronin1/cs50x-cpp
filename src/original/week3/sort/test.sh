#!/bin/bash

# Empty the file at start
> test_results.txt

for i in {1..3}
do
    for j in *0.txt
    do
        echo "running: sort$i: $j" | tee -a test_results.txt
        # Use 'time' wrapped to capture both stdout and stderr
        { time ./sort$i $j > /dev/null; } 2>&1 | tee -a test_results.txt
        echo "******" | tee -a test_results.txt
    done
done
