# System_Software
-----------

#### 이 repo는 시스템 소프트웨어를 공부하면서 구현 및 공부한 것을 정리한 repo입니다. 

## 1. File System

-------

저수준 파일 입출력 및 고수준 파일 입출력을 이용하여 학번마다 성적의 평균을 출력하는 프로그램

1. row.c - 저수준 파일 입출력

   >1. 저수준 파일 입출력에서 한 줄 씩 읽어 parsing을 해주고 싶었으나 fgets를 사용할 수 없었고 그에 대한 방안으로 파일 기술자가 가리키는 파일에서 offset으로 지정한 크기만큼 오프셋을 이동시킬 수 있는 lseek를 사용해주었다. 파일을 읽어오기 전 파일을 읽기 위해 파일을 먼저 열어주었다.
   >2.  저수준 파일 입출에서 먼저 학번을 읽어 학번을 출력해주고 그 뒤의 숫자들을 차례대로 읽어 atoi 함수를 이용하여 정수로 바꾸어 주었다. 

   여기서 사용한 ```lseek```에 대해 간단히 살펴보자.

   >\#include<sys/types.h> 와 #include <unistd.h>헤더를 사용하며 lseek(int fildes,off_t offset, int whence); 인자를 받는다.
   >
   >인자를 받는다. Offset으로 지정한 크기만큼 offset을 이동시키고 offset의 값은 whence값을 기준으로 해석한다. Whence는 SEEK_SET, SEEK_CUR, SEEK_END가 존재한다. 
   >
   >| **SEEK_SET** | **파일의 시작 기준** |
   >| ------------ | -------------------- |
   >| **SEEK_CUR** | **현재 위치 기준**   |
   >| **SEEK_END** | **파일의 끝 기준**   |

2. High.c - 고수준 파일 입출력

   고수준 파일 입출력의 경우 사용할 수 있는 함수의 범위가 많아 수월하게 구현. 또한 구조체를 사용하여 저수준 보다 확장성 있게 구현.

   >자료형으로 FILE *을 이용하고 fopen을 통해 data파일을 열어주었다. openFIle이라는 함수를 생성해주어 학번과 성적을 읽어 평균을 계산해주었다. 이 과정에서 fscanf함수를 사용해주었다. fscanf는 지정한 파일에서 입력을 받는데 scanf가 사용하는 형식 지정 방법을 그대로 사용한다. 이 함수는 성공적으로 수행하면 읽어온 항목의 개수를 리턴해준다. 

3. filedescripter.c

   >표준 입력에서 데이터를 받아 이를 처리하고 결과를 표준 출력으로 출력하는 수행화일 P가 있다. 프로그램 P를 변경하지 않고 표준 입력 대신 파일 A에서 입력을 받고, 표출 출력 대신 파일 B로 결과를 저장하는 방법을 코딩하시오. *(힌트: dup() 또는 dup2()를 사용하여 표준 입출력을 redirection 하고, 이를 child 에게 전달함. child는 exec()후에도 open file descriptor를 유지함)*

## 3.Process

--------

file A, B, C, D의 내용을 읽고 파일들에 있는 숫자들의 총합계를 계산하려고 한다. (1) 프로세스 한 개가 이를 모두 수행하는 경우와 (2) 여러 개의 프로세스가 한 파일씩 담당하여 동시에 수행하고, 나중에 한 프로세스가 이를 모으는 방법이 있다. 어느 방법으로 수행하는 것이 빠른지 구현하고 실험적으로 비교하려고 한다. 

<img width="136" alt="image-20200513234600696" src="https://user-images.githubusercontent.com/49120090/81827987-45527c00-9574-11ea-80ba-7f118a056cdd.png">

이렇게 주어져 있는 4개의 파일에 들어있는 숫자의 총합을 계산하자.

1. Single.c - 하나의 프로세스로 구현 

   결과 - 

   <img width="226" alt="image-20200513234714539" src="https://user-images.githubusercontent.com/49120090/81828016-4f747a80-9574-11ea-9f6b-1dffef8f5e64.png">

2. multi.c - 여러개의 프로세스로

   <img width="241" alt="image-20200513234746500" src="https://user-images.githubusercontent.com/49120090/81828031-51d6d480-9574-11ea-95d4-e8eeeffa3703.png">

   

