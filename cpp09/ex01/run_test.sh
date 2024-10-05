#!/bin/bash

# Path to your RPN executable
RPN_EXEC="./RPN"

# Check if the RPN executable exists
if [ ! -f "$RPN_EXEC" ]; then
    echo "Error: RPN executable not found at $RPN_EXEC"
    exit 1
fi

# Read the test cases file line by line
while IFS=$'\t' read -r input_expression expected_output; do
    # Remove quotes from the input expression
    input_expression=${input_expression//\"/}

    # Execute the RPN program and capture the output (both stdout and stderr)
    actual_output=$($RPN_EXEC "$input_expression" 2>&1)

    # Compare the actual output to the expected output
    if [ "$actual_output" = "$expected_output" ]; then
        echo "Test passed for input: \"$input_expression\""
    else
        echo "Test failed for input: \"$input_expression\""
        echo "Expected: $expected_output"
        echo "Got: $actual_output"
    fi
done < test_cases.txt
