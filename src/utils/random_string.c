#include <stdlib.h>
#include <string.h>
#include <time.h>

int getRand(int min, int max)
{
  static int flag;

  if (flag == 0)
  {
    struct timespec ts;
    timespec_get(&ts, TIME_UTC);
    srandom(ts.tv_nsec ^ ts.tv_sec);
    random();

    flag = 1;
  }
  int ret = min + (int)(random() * (max - min + 1.0) / (1.0 + RAND_MAX));
  return ret;
}

char getRandomCharLower(void)
{
  const char CHARS[] = "abcdefghijklmnopqrstuvwxyz";
  int index = getRand(0, (strlen(CHARS) - 1));
  char c = CHARS[index];
  return c;
}

char *getRandomCharsLower(char *str, int length)
{
  for (int i = 0; i < length; i++)
  {
    str[i] = getRandomCharLower();
  }
  str[length] = '\0';
  return str;
}
