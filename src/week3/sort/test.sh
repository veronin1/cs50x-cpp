#!/bin/bash

# Get average from 10 iterations of all sorts running on all files in data/

files=(random10000.txt random50000.txt reversed50000.txt sorted50000.txt random200000.txt random5000.txt reversed5000.txt sorted5000.txt random300000.txt reversed10000.txt sorted10000.txt)
iterations=10

total_bubble=0
total_selection=0
total_merge=0
count=0

tmpfile=$(mktemp)

for file in "${files[@]}"; do
  echo "Running tests on $file..."
  for ((i=1; i<=iterations; i++)); do
    ./a.out "data/$file" > "$tmpfile"
    bubble_time=$(grep "Bubble Sort:" "$tmpfile" | awk '{print $(NF-1)}')
    selection_time=$(grep "Selection Sort:" "$tmpfile" | awk '{print $(NF-1)}')
    merge_time=$(grep "Merge Sort:" "$tmpfile" | awk '{print $(NF-1)}')

    # Use awk to add floats
    total_bubble=$(awk -v a=$total_bubble -v b=$bubble_time 'BEGIN {print a + b}')
    total_selection=$(awk -v a=$total_selection -v b=$selection_time 'BEGIN {print a + b}')
    total_merge=$(awk -v a=$total_merge -v b=$merge_time 'BEGIN {print a + b}')
    
    count=$((count + 1))
  done
done

avg_bubble=$(awk -v total=$total_bubble -v c=$count 'BEGIN {printf "%.6f", total / c}')
avg_selection=$(awk -v total=$total_selection -v c=$count 'BEGIN {printf "%.6f", total / c}')
avg_merge=$(awk -v total=$total_merge -v c=$count 'BEGIN {printf "%.6f", total / c}')

echo "Average sort times over $count runs:"
echo "Bubble Sort:    $avg_bubble seconds"
echo "Selection Sort: $avg_selection seconds"
echo "Merge Sort:     $avg_merge seconds"

rm "$tmpfile"
