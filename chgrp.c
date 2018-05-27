#ifdef CS333_P5
#include "types.h"
#include "user.h"
int
main(int argc, char * argv[])
{
  if(argc > 2)
  {
    if(atoi(argv[1]) >= 0)
      chgrp(argv[2], atoi(argv[1])); 
    else
      printf(1, "Invalid argument for group\n");
  }
  else
    printf(1, "Too few arguments to chgrp\n");

  exit();
}
#endif
