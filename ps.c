#ifdef CS333_P2
#include "types.h"
#include "user.h"
#include "uproc.h"

#define MAXPROCS 64
  
int
main(void)
{
  struct uproc* table = (struct uproc*) malloc(sizeof(struct uproc) * MAXPROCS);
  int numprocs = getprocs(MAXPROCS, table);
  if (numprocs < 0)
      //free(table);  // this causes a trap error every time ps is called
      return -1;
  struct uproc* up;
  printf(1, "PID\tName\tUID\tGID\tPPID\tPrio\tElapsed\tCPU\tState\tSize\n");
  for(up = table; up < &table[numprocs]; up++){
    printf(1, "%d\t%s\t%d\t%d\t%d\t%d\t%d.%d%d%d\t%d.%d%d%d\t%s\t%d\n", up->pid, up->name, up->uid, up->gid, 
        up->ppid, up->priority, up->elapsed_ticks/1000, (up->elapsed_ticks%1000 - up->elapsed_ticks%100)/100,
        (up->elapsed_ticks%100 - up->elapsed_ticks%10)/10, up->elapsed_ticks%10, up->CPU_total_ticks/1000, 
        (up->CPU_total_ticks%1000 - up->CPU_total_ticks%100)/100, (up->CPU_total_ticks%100 - up->CPU_total_ticks%10)/10,
        up->CPU_total_ticks%10, up->state, up->size);
  }
  free(table);
  exit();
}
#endif
