#!/bin/bash

# Function to print current time in HH/MM/SS format
print_time() {
    printf "%02d:%02d:%02d\n" $(date +"%H") $(date +"%M") $(date +"%S")
}

# Loop to continuously print time every second
while true; do
    clear  # Clear the screen (optional, removes previous timestamps)
    print_time  # Call the function to print current time
    sleep 1  # Wait for 1 second before printing the next time
done
