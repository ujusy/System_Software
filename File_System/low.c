#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>


int main(void){
    int fd;
    int n,size=0,off=0,i=0,score,num1, num2, num3;
    off_t start, cur;
    char buf[1000];
    double avg;

    fd = open("data",O_RDONLY);
    if(fd == -1){
        perror("Open");
        exit(1);
    }
    
    for(i=0;i<2;i++){
    start = lseek(fd, 0, SEEK_CUR);
    n=read(fd, buf, 8);
    score=atoi(buf);
    printf("학번 : %d ",score);    
    
    cur = lseek(fd, 0, SEEK_CUR);
    n = read(fd, buf, 3);
    num1 =atoi(buf);

    cur = lseek(fd, 0, SEEK_CUR);
    n = read(fd, buf, 3);
    num2 =atoi(buf);

    cur = lseek(fd, 0, SEEK_CUR);
    n = read(fd, buf, 3);
    num3 =atoi(buf);
  
    avg = (num1 + num2 + num3)/3.0;
    printf("평균 :%f \n",avg);
    }

  
    close(fd);

    return 0;

}