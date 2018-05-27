#ifdef CS333_P5
#include "types.h"
#include "user.h"
int
main(int argc, char * argv[])
{
  if(argc > 2)
  {
    if(atoi(argv[1]) >= 0)
      chown(argv[2], atoi(argv[1])); 
    else
      printf(1, "Invalid argument for owner\n");
  }
  else
    printf(1, "Too few arguments to chown\n");

  exit();
}
#endif
