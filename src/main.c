#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

#include "hash_table.h"
#include "benchmark/test.h"
#include "utils/random_string.h"

int main(int argc, char *argv[])
{
  if (argc > 2)
  {
    return 1;
  }

  if (argc == 2 && strcmp(argv[1], "-t") == 0)
  {
    test();
    return 0;
  }

  ht_hash_table *ht = ht_new();

  for (int i = 0; i < 100; i++)
  {
    const int key_len = 30;
    const int val_len = 30;
    char key[key_len + 1];
    char val[val_len + 1];
    getRandomCharsLower(key, key_len);
    getRandomCharsLower(val, val_len);
    ht_insert(ht, key, val);
  }

  ht_del_hash_table(ht);
}
