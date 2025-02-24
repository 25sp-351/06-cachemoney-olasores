# Test Cases 

## Basic I/O Tests

1. Input: just zero "0"
   - Output: "cent"

2. Input: single digit e.g "5"
   - Output: "five cents"
   
3. Input: Double digit cents e.g "45"
   - Output: "forty-five cents"
   
4. Input: Single digit dollars e.g "100"
   - Output: "one dollar"
   
5. Input: Double digit dollars with cents e.g "1234"
   - Output: "twelve dollars and thirty-four cents"
   
6. Input: Thousands e.g "122309"
   - Output: "one thousand two hundred twenty-three dollars and nine cents"

## Edge Cases
1. Maximum memoized value "149999"
   - Tests the memoization limit
   
2. Value above memoization "150000"
   - Tests handling of non-memoized values
   
3. Zero cents "100"
   - Should not include "and cents" in the output

4. Input: 1 
   - should output "one-cents'

5. "and" in between numbers of 4 digits or more 
   - should include "and" in between numbers greater than 4 digits or more 
   - should not include "and" between numbers less than 4 digits e.g 123: one dollar twenty-three cents

6. Hypenated Numbers
   - The output should include hypen between numbers like 21 and 99 should have a hypen between them


## Error Cases
1. Negative numbers as input
   - Should handle gracefully
   - Output: Invalid
   
2. Very large numbers
   - Should handle without buffer overflow122309
   - Output an Invalid amount for very large numbers


## RUN Test 
- chmod +x tests.sh
- ./tests.sh

## RUN program 
- make 
- ./money_converter