//producerangelo
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

//
#define MAX_LEN 10000
struct region{
    int len;
    char buf[MAX_LEN];
    int in;
    int out;


};

int main(){
    struct region* rptr;
    int fd;
    
    fd = shm_open("/myregion",O_CREAT| O_RDWR, S_IRUSR | S_IWUSR);
    if(fd == -1){
        printf("shared memory failed\n");
		exit(-1);
    }
    if(ftruncate(fd,sizeof(struct region)) == -1){
        printf("shared memory failed\n");
        exit(-1);
    }
    rptr= mmap(NULL,sizeof(struct region), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (rptr == MAP_FAILED) {
            printf("Map failed\n");
            return -1;
    }
    
    strcpy(rptr->buf,"hola");
    rptr->len = getpid();
    rptr->in = 0;
    //sprintf(rptr,"%s",rptr->buf);
    dprintf(rptr->len,"%s"," este es pid");
    sprintf(rptr->buf,"%s","hola3");
    printf("Soy el padre con PID %d\n", (int)getpid());
    /*
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("Fork fallado");
    }
    if (pid == 0)
    {
        rptr->len = (int) getpid();
        printf("soy el hijo con pid %d\n",rptr->len);
        sleep(5);
        printf("hijo terminado\n");
        exit(0);
    }
    */
   printf("Esperando al hijo\n");
  for (int i = 0; i < 3; i++)
  {
      int out = sizeof(struct region);
      while ((rptr->in+1)% (sizeof(struct region)) == out )
      {
          
      }
      pid_t c = fork();
      if (c==0)
      {
          rptr->len = (int)getpid();    
          printf("[hijo] pid %d de [padre] pid %d\n",getpid(),getppid());
          dprintf(rptr->len,"%s"," este es pid");
          rptr->in = rptr->in+1;
          exit(0);
      }
      sleep(5);
      
      
      
  }

    
    sleep(3);
    wait(NULL);
    rptr->len = (int) getpid();
    printf("Proceso padre con pid [%d] terminado\n",rptr->len);
    sleep(5);
    return 0;
}
