#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "numeric.h"

static const char* ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
static const char* teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
static const char* tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

static void append(char* buffer, const char* word) {
    if (strlen(buffer) > 0 && word[0] != '\0') {
        strcat(buffer, " ");
    }
    strcat(buffer, word);
}

static void convert_group(int n, char* buffer) {
    if (n >= 100) {
        append(buffer, ones[n / 100]);
        append(buffer, "hundred");
        n %= 100;
    }
    
    if (n >= 10 && n < 20) {
        append(buffer, teens[n - 10]);
    } else {
        if (n / 10 > 0) {  
            append(buffer, tens[n / 10]);
            if (n % 10 > 0) {
                strcat(buffer, "-");
                strcat(buffer, ones[n % 10]);
            }
        } else if (n % 10 > 0) {
            
            append(buffer, ones[n % 10]);
        }
    }
}

char* convert_to_text(int cents) {
    char* result = (char*)malloc(1000);
    result[0] = '\0';
    
    int dollars = cents / 100;
    int remaining_cents = cents % 100;
    
    if (dollars == 0) {
        convert_group(remaining_cents, result);
        append(result, (remaining_cents == 1) ? "cent" : "cents");
        return result;
    }
    
    convert_group(dollars, result);
    append(result, (dollars == 1) ? "dollar" : "dollars");
    
    if (dollars >= 1000 && dollars < 10000) {
        strcat(result, " and ");
        convert_group(remaining_cents, result);
        append(result, (remaining_cents == 1) ? "cent" : "cents");
    } else if (remaining_cents > 0) {
        convert_group(remaining_cents, result);
        append(result, (remaining_cents == 1) ? "cent" : "cents");
    }
    
    return result;
}

void cleanup_text(char* text) {
    free(text);
}