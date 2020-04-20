#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
void openFile(FILE* fp);
typedef struct student
{
    int class_st;
    int score[5];
    double avg;
}Student;

Student stu[2];

int main(void)
{
    FILE *fp = fopen("data","r");

    if(fp == NULL){
        printf("File is Null\n");
        exit(1);
    }


    // for(int i=0;i<2;i++){

    //     printf("학번: %d  평균: %f",stu[i].class_st,stu[i].avg);
    //     printf("\n");
    // }
    // openFile(fp);

    while()
    fclose(fp);

    return 0;
}

void openFile(FILE *fp){
    double sum=0;
    int i;

    for(i=0;i<2;i++){
        fscanf(fp,"%d %d %d %d",&stu[i].class_st, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]);
        sum = stu[i].score[0]+stu[i].score[1]+stu[i].score[2];
        stu[i].avg = sum/3.0;
    }

}


01 #include <stdlib.h>
02 #include <stdio.h>
03
04 int main(void) {
05 FILE *rfp;
06 int id, s1, s2, s3, s4, n;
07
08 if ((rfp = fopen("unix.dat", "r")) == NULL) {
09 perror("fopen: unix.dat");
10 exit(1);
11 }
12
13 printf("학번 평균\n");
14 while ((n=fscanf(rfp, "%d %d %d %d %d", &id,&s1,&s2,&s3,&s4)) != EOF) {
15 printf("%d : %d\n", id, (s1+s2+s3+s4)/4);
16 }
17
18 fclose(rfp);
19
20 return 0;
21 }
