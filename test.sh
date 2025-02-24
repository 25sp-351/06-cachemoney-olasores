#!/bin/bash

run_test() {
    input=$1
    expected=$2
    result=$(echo "$input" | ./money_converter)
    if [ "$result" = "$expected" ]; then
        echo "Test PASSED: $input"
        return 0
    else
        echo "Test FAILED: $input"
        echo "  Expected: $expected"
        echo "  Got: $result"
        return 1
    fi
}

# Compile the program
make clean && make

# Run tests
failed=0

# Test the basic cases
run_test "100" "100 = one dollar" || failed=1
run_test "418" "418 = four dollars eighteen cents" || failed=1
run_test "1234" "1234 = twelve dollars and thirty-four cents" || failed=1
run_test "122309" "122309 = one thousand two hundred twenty-three dollars and nine cents" || failed=1
run_test "16" "16 = sixteen cents" || failed=1

# Test the edge cases
run_test "0" "0 = cents" || failed=1
run_test "1" "1 = one cent" || failed=1
run_test "99" "99 = ninety-nine cents" || failed=1

# Test the memoization limit
run_test "150000" "150000 = one thousand five hundred dollars" || failed=1

if [ $failed -eq 0 ]; then
    echo "All tests passed!"
else
    echo "Some tests failed."
fi