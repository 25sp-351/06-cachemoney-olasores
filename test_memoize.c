#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "memoize.h"
#include <stdlib.h>

void test_basic_memoization() {
    reset_cache_stats();
    
    char* result1 = convert_with_memo(1234);
    assert(get_cache_hits() == 0);
    
    char* result2 = convert_with_memo(1234);
    assert(get_cache_hits() == 1);
    
    assert(strcmp(result1, result2) == 0);
    
    free(result1);
    free(result2);
    printf("Basic memoization test passed\n");
}

void test_cache_limit() {
    reset_cache_stats();
    
    char* result1 = convert_with_memo(149999);
    assert(get_cache_hits() == 0);
    
    char* result2 = convert_with_memo(149999);
    assert(get_cache_hits() == 1);
    
    char* result3 = convert_with_memo(150000);
    assert(get_cache_hits() == 1); 
    
    free(result1);
    free(result2);
    free(result3);
    printf("Cache limit test passed\n");
}

void test_multiple_values() {
    reset_cache_stats();
    
    int test_values[] = {1, 100, 1234, 5678, 10000};
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);
    
    for (int i = 0; i < num_tests; i++) {
        char* result = convert_with_memo(test_values[i]);
        free(result);
    }
    assert(get_cache_hits() == 0);
    
    for (int i = 0; i < num_tests; i++) {
        char* result = convert_with_memo(test_values[i]);
        free(result);
    }
    assert(get_cache_hits() == num_tests);
    
    printf("Multiple values test passed\n");
}

int main() {
    test_basic_memoization();
    test_cache_limit();
    test_multiple_values();
    
    cleanup_memo();
    printf("All memoization tests passed!\n");
    return 0;
}