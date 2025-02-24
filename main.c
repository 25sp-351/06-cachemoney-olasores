#include <stdio.h>
#include <stdlib.h>
#include "memoize.h"

int main() {
    char line[100];
    while (fgets(line, sizeof(line), stdin)) {
        int cents = atoi(line);
        char* text = convert_with_memo(cents);
        printf("%d = %s\n", cents, text);
        free(text);
    }
    
    cleanup_memo();
    return 0;
}