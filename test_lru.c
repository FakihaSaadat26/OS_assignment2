#include "types.h"
#include "stat.h"
#include "user.h"

#define NPAGES 100

int main(void) {
  printf(1, "\n=== LRU PAGE REPLACEMENT TEST ===\n");
  char *pages[NPAGES];
  for (int i = 0; i < NPAGES; i++) {
    pages[i] = malloc(4096);
    if (pages[i]) {
      pages[i][0] = i;
    } else {
      printf(1, "Page %d allocation failed (expected if memory full)\n", i);
    }
  }
  // Access some pages to update LRU
  for (int i = 0; i < NPAGES; i += 10) {
    if (pages[i]) pages[i][0] = 42;
  }
  printf(1, "LRU test complete. Check kernel log for eviction evidence.\n");
  exit();
}
