#include "Processbar.h"

#define Length 101
#define Style '#'

const char *label = "|/-\\";

void ProcBar(double filesize, double current)
{
  char bar[Length];
  memset(bar, '\0', sizeof(bar));
  int len = strlen(label);

  int cnt = 0;
  double rate = (current*100.0)/filesize;
  int loop = (int)rate; 
  while(cnt <= loop)
  {
    bar[cnt++] = Style;
  }
  printf("[%-100s][%.1lf%%][%c]\r",bar, rate, label[cnt%len]);
  fflush(stdout);
}
