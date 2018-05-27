#ifdef CS333_P5
#include "types.h"
#include "user.h"
int
main(int argc, char * argv[])
{
  if(argc > 2)
  {
    if((atoo(argv[1]) > 0 && atoo(argv[1]) < 1778) || atoi(argv[1]) == 0)
      chmod(argv[2], atoo(argv[1])); 
    else
      printf(1, "Invalid argument for mode\n");
  }
  else
    printf(1, "Too few arguments to chmod\n");
  exit();
}

#endif
