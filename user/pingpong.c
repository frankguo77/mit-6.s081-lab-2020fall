#include "kernel/types.h" 
#include "kernel/stat.h" 
#include "user/user.h"

char buf;

int
main(int argc, char *argv[])
{
  int pw[2];
  int pr[2];
    
  pipe(pw);
  pipe(pr);

  if (fork() == 0){
    close(pw[1]);
    close(pr[0]);
    if (read(pw[0],&buf, 1) == 1){
	 fprintf(1, "%d: received ping\n", getpid());
	 write(pr[1], &buf, 1);
	 close(pr[1]);
	 close(pw[0]);
	 exit(0);
    }
  }else{
     close(pw[0]);
     close(pr[1]);
     write(pw[1], &buf, 1);
     if (read(pr[0],&buf, 1) == 1){
	  fprintf(1, "%d: received pong\n", getpid());
	  close(pr[0]);
	  close(pw[1]);
	  exit(0);
    }
  }

  exit(0);
}
