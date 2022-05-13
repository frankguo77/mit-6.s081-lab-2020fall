#include "kernel/types.h" 
#include "kernel/stat.h" 
#include "user/user.h"

void primes() {

    int val;
    int p[2];

    pipe(p);
    
    if (read(0, &val, sizeof(val)) <= 0) {
        return;
    }

    fprintf(1, "prime %d\n", val);

    if (fork() == 0){
        close(0);
        dup(p[0]);
        close(p[0]);
        close(p[1]);
        primes();
    }else{
        int tmpval;
        close(1);
        dup(p[1]);
        close(p[0]);
        close(p[1]);    
        while (read(0, &tmpval, sizeof(tmpval)) > 0){
            if (tempval % val != 0) {
                write(1, &tmpval, sizeof(tmpval));
            }
        }
        close(1);
        wait();
    }
}

int
main(int argc, char *argv[])
{
  int p[2];
  int value;
    
  pipe(p);
  if (fork() == 0){
      close(0);
      dup(p[0]);
      close(p[0]);
      close(p[1]);
      primes();
  }else{
      close(1);
      dup(p[1]);
      close(p[0]);
      close(p[1]);
      for (int i = 2; i <= 35; i++) {
          write(1, &i, sizeof(i));
      }
      close(1);
  }
  wait();
  exit(0);
}
