#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#define MAXARGS 10


void runcmd(char* argv[]) {
  int pid = fork();
  if (pid == 0){
    exec(argv[0], argv);
    fprintf(2, "exec: %s failed...\n", argv[0]);
  }else{
    wait(&pid);
  }  
}


int
main(int argc, char *argv[])
{
  int i;
  static char buf[100];
  char *newargv[MAXARGS];

  if(argc < 2){
    fprintf(2, "Usage: xargs command...\n");
    exit(1);
  }

  
  for (i = 1; i < argc; i++) {
    newargv[i - 1] = argv[i];
  }

  i = 0;
  char c;
  while (read(0, &c, 1) > 0) {
    if (c == '\n') {
      buf[i++] = 0;
      newargv[argc - 1] = buf;
      newargv[argc] = 0;
      runcmd(newargv);
      i = 0;
    } else {
      buf[i++] = c;
    }
  }

  if (i > 0)
  {
    buf[i++] = 0;
    newargv[argc - 1] = buf;
    newargv[argc] = 0;
    runcmd(newargv);   
  }

  exit(0);
}
