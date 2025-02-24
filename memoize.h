#ifndef MEMOIZE_H
#define MEMOIZE_H

char* convert_with_memo(int cents);
void cleanup_memo(void);
int get_cache_hits(void);
void reset_cache_stats(void);

#endif 