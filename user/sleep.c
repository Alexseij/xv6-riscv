#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char **argv) {
  int sleepTime;
 
  if (argc <= 1) {
    printf("sleep: missing operand\n");
    exit(1);
  }
  sleepTime = atoi(argv[1]);
  
  sleep(sleepTime);

  exit(0);
}
