// 표준 입력에서 데이터를 받아 이를 처리하고 결과를 표준 출력으로 출력하는 수행화일 P가 있다. 
// 프로그램 P를 변경하지 않고 표준 입력 대신 파일 A에서 입력을 받고, 표출 출력 대신 파일 B로 결과를 저장하는 방법을 코딩
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

intmain(void) {

char* buf[1000]; 
int pid;
int fd, A, B;
int fd1;
 pid =fork();

if (pid ==-1) //Error
 {
perror("Failed to Create Process");
exit(-1);
 } elseif (pid ==0) 
 {
 fd =open("B", O_CREAT | O_WRONLY | O_TRUNC, 0644);
close(1);
dup(fd);
close(fd);
execlp("cat","cat", NULL);

exit(0);
 } else//부모 프로세스
 { 
close(0);
 fd =open("A", O_CREAT | O_WRONLY | O_TRUNC, 0644);
if (fd ==-1) {
perror("Create");
exit(1);
 }
dup(fd);
close(fd);
wait( & pid);

 }

return0;