
//#include "kernel/types.h"
//#include "kernel/stat.h"
//#include "user/user.h"
//#include "kernel/fs.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

   int main(int argc, char *argv[])
  {
    //empty command line
    if(argc == 0)
      {
          exit(0);
      }

    //process command
    else
      {
          //printf("ARGV: %s\n", argv[0]);
          int pid = fork();

          if(pid > 0)
            {
              printf("parent: child=%d\n", pid);
              pid = wait((int *)0);
              printf("child %d is done\n",pid);
            }
          else if(pid == 0)
            {
              printf("child: exiting\n");
              printf("real time in ticks: %d\n", uptime());
              exit(0);
              exec("ls", &argv[1]);
              printf("exec: %d\n", exec("ls", &argv[1]));
            }
          else
            {
              printf("fork error \n");
            }


      }
        //display uptime
        printf("Real-time in ticks: %d\n", uptime());
        exit(0);
   }
