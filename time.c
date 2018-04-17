#ifdef CS333_P2
#include "types.h"
#include "user.h"
int
main(int argc, char * argv[])
{
  int start_ticks = uptime();
  int parent = fork(); 
  if(parent < 0) // fork failed
    return -1;
  if(!parent) // at child
    exec(argv[1], &argv[1]);
  wait();
  int elapsed = uptime() - start_ticks;
  if(argc == 1)
    printf(1, "");
  else
    printf(1, "%s ", argv[1]);
  if(parent)
    printf(1, "ran in %d.%d%d%d seconds.\n",
      elapsed/1000, (elapsed%1000 - elapsed%100)/100,
      (elapsed%100 - elapsed%10)/10, elapsed%10);
  exit();
}

#endif
