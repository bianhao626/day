#include "Processbar.h"

double bandwidth = 1024*1024*1.0;

void download(double filesize, callback_t cb)
{
  double current = 0.0;

  printf("download done, current:%lf\n", current);

  while(current <= filesize)
  {
    cb(filesize, current);
    //理论上从网络中获取数据
    current += bandwidth;
    usleep(30000);
  }

  printf("\ndownload done, filesize:%lf\n", filesize);
}

int main()
{
  download(1024*1024*100,ProcBar); 
  download(1024*1024*1,ProcBar); 
  download(1024*1024*38,ProcBar); 
  download(1024*1024*10,ProcBar); 
  download(1024*1024*999,ProcBar); 
  return 0;
}
