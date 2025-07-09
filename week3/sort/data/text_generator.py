import random

# Set the number of unique random numbers
total_numbers = 10_000_000

# Generate a list of numbers from 1 to 300,000
numbers = list(range(1, total_numbers + 1))

# Shuffle the list randomly
random.shuffle(numbers)

# Write to a text file
with open("random_numbers.txt", "w") as file:
    for number in numbers:
        file.write(f"{number}\n")

print(f"Generated {total_numbers} unique random numbers in 'random_numbers.txt'.")
