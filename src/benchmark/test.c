#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>

#include "../hash_table.h"
#include "../utils/random_string.h"

void test() {
  printf("test is running...\n");

  ht_hash_table *ht = ht_new();
  assert(ht);

  for (int j = 0; j < 40; j++) {
    const int key_len = 30;
    const int val_len = 30;
    char key[key_len+1];
    char val[val_len+1];
    getRandomCharsLower(key, key_len);
    getRandomCharsLower(val, val_len);

    ht_insert(ht, key, val);
    char *result = ht_search(ht, key);
    assert(strcmp(result, val) == 0);
  }

  printf("all test passed!!\n\n");

  long cpu_time = clock();
  double sec = (double)cpu_time / CLOCKS_PER_SEC;
  printf("%f sec/per an insert\n", sec / 10);
  printf("total: %f sec.\n", sec);

  return;
}
