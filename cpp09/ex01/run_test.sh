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

    # Execute the RPN program under Valgrind and capture the output and any Valgrind errors
    valgrind_output=$(valgrind --leak-check=full --error-exitcode=1 "$RPN_EXEC" "$input_expression" 2>&1)
    valgrind_exit_code=$?

    # Extract the actual output by filtering out Valgrind messages
    actual_output=$(echo "$valgrind_output" | grep -v "==" | grep -v "Command:" | grep -v "VALGRIND" | grep -v "definitely lost" | grep -v "possibly lost" | grep -v "still reachable" | grep -v "suppressed")

    # Compare the actual output to the expected output
    if [ "$actual_output" = "$expected_output" ] && [ $valgrind_exit_code -eq 0 ]; then
        echo "Test passed for input: \"$input_expression\""
    else
        echo "Test failed for input: \"$input_expression\""
        echo "Expected Output: $expected_output"
        echo "Actual Output: $actual_output"
        if [ $valgrind_exit_code -ne 0 ]; then
            echo "Valgrind detected memory errors:"
            # Print Valgrind errors
            echo "$valgrind_output" | grep -A20 "ERROR SUMMARY"
        fi
    fi
done < test_cases.txt

