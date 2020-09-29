//consumerangelo

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <time.h>
#define MAX_LEN 10

struct region{
    int len;
    char buf[MAX_LEN];
    int in;
    int out;
};

int main()
{    
    struct region* rptr;
    int fd;
    fd = shm_open("/myregion",O_RDONLY,0666);


    if(fd == -1){
        printf("shared memory failed\n");
		exit(-1);
    }
    rptr = mmap(0,sizeof(struct region), PROT_READ, MAP_SHARED, fd, 0);
    if (rptr == MAP_FAILED) {
            printf("Map failed\n");
            exit(-1);
    }
    //struct region* next_consumer;
    time_t t;
    struct tm *tm;
    char fechayhora[100];
    rptr->out = 0;
    for (int i = 0; i < 3; i++)
    {
        
        
        //next_consumer = rptr;
        //strftime(fechayhora, 100, "%H/%M/%S", tm);
        printf("Creando proceso a  %d",rptr->len);
        //kill(next_consumer->len,SIGKILL);
        sleep(5);
        
    }
    
    printf("%d\n",rptr->len);
    //printf("%s",rptr->buf);
	sleep(5);
    
   return 0;
}
