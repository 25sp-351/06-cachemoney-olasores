#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memoize.h"
#include "numeric.h"

#define MEMO_LIMIT 150000  // $1500.00 in cents

static char* memo[MEMO_LIMIT] = {NULL};
static int cache_hits = 0;

char* convert_with_memo(int cents) {
    if (cents < 0) {
        return strdup("invalid input");
    }
    
    if (cents < MEMO_LIMIT) {
        if (memo[cents] != NULL) {
            cache_hits++;
            return strdup(memo[cents]);
        }
        memo[cents] = convert_to_text(cents);
        return strdup(memo[cents]);
    }
    
    return convert_to_text(cents);
}

void cleanup_memo(void) {
    for (int i = 0; i < MEMO_LIMIT; i++) {
        if (memo[i] != NULL) {
            free(memo[i]);
            memo[i] = NULL;
        }
    }
    cache_hits = 0;
}

int get_cache_hits(void) {
    return cache_hits;
}

void reset_cache_stats(void) {
    cache_hits = 0;
}