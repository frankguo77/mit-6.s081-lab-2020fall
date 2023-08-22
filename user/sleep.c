#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

char*
fmtname(char *path)
{
   static char buf[DIRSIZ+1];
   char *p;

   // Find first character after last slash.
   for(p=path+strlen(path); p >= path && *p != '/'; p--)
     ;
   p++;

   // Return blank-padded name.
   if(strlen(p) >= DIRSIZ)
     return p;
   memmove(buf, p, strlen(p));
   memset(buf+strlen(p), ' ', DIRSIZ-strlen(p));
   return buf;
}
   

void
find(char *path, char*fn)
{
  char buf[512], *p;
  int fd;
  struct dirent de;
  struct stat st;
 
  if((fd = open(path, 0)) < 0){
      fprintf(2, "find: cannot open %s\n", path);
      return;
  }
 
  if(fstat(fd, &st) < 0){
      fprintf(2, "find: cannot stat %s\n", path);
      close(fd);
      return;
  }

  switch(st.type){
  case T_FILE:
    p = fmtname(path);
    if (strcmp(p, fn) == 0){
      printf("%s\n", path);
    }
  }
}

int
main(int argc, char *argv[])
{
  if (argc != 3){
    fprintf(2, "Please input path and filename!\n");
    exit(1);
    } else {
      i = atoi(argv[1]);
      sleep(i);
      fprintf(2, "Bye! \n");
      exit(0);
    }
}

