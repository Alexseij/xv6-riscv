#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char** argv) {
  int p[2];
  int pid;
  
  pipe(p);
  
  if (write(p[1], "1", 1) != 1) {
      fprintf(2, "error while parent writing to pipe");
      exit(1); 
  }
 
  if ((pid = fork()) > 0) {
    wait((int *) 0);
    if (read(p[0],(int*) 0,1) != 1) {
      fprintf(2, "error while parent reading from pipe");
      exit(1);
    }

    printf("%d: received pong\n", getpid()); 
  } else if (pid == 0) {
    if (read(p[0],(int*) 0,1) != 1) {
      fprintf(2, "error while child reading from pipe");
      exit(1);
    }
     
    printf("%d: received ping\n", getpid()); 
    if (write(p[1], "1", 1) != 1) {
      fprintf(2, "error while child writing to pipe");
      exit(1); 
    } 
    
    exit(0);
  } else {
    fprintf(2, "error while fork()");
    exit(1);
  }


  exit(0);
}
