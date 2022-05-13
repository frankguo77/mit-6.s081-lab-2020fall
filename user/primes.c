#include "kernel/types.h" 
#include "kernel/stat.h" 
#include "user/user.h"

void primes(int* pf) {

    int val;
    int p[2];

    close(pf[1]);
    pipe(p);
    if (read(pf[0], &val, sizeof(val)) <= 0) {
        return;
    }

    fprintf(1, "prime %d\n", val);

    int pid = fork();
    if (pid == 0){
        //close(0);
        //dup(p[0]);
        //close(p[0]);
        //close(p[1]);
        primes(p);
    }else{
        int tmpval;
        //close(1);
        //dup(p[1]);
        close(p[0]);
        //close(p[1]);    
        while (read(pf[0], &tmpval, sizeof(tmpval)) > 0){
            if (tmpval % val != 0) {
                write(p[1], &tmpval, sizeof(tmpval));
            }
        }
        close(p[1]);
        wait(&pid);
    }
}

int
main(int argc, char *argv[])
{
  int p[2];
    
  pipe(p);
  int pid = fork();
  if (pid == 0){
      //close(0);
      //dup(p[0]);
      //close(p[0]);
      //close(p[1]);
      primes(p);
  }else{
      //close(1);
      //dup(p[1]);
      close(p[0]);
      //close(p[1]);
      for (int i = 2; i <= 35; i++) {
          write(p[1], &i, sizeof(i));
      }
      close(p[1]);
      wait(&pid);
  }
  
  exit(0);
}
