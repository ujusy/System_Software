#include <stdio.h>
#include <grp.h>
#include <pwd.h>
#include <string.h>


int main(void){
    char name[100];
    struct group *grp1;
    struct group *grp2;

    int m=0;
    printf("Input user name:  ");
    scanf("%s",name);

    grp1 = getgrnam(name);

    printf("User: %s\n",name);
    printf("Primary Group: %s\n",grp1->gr_name);

   while(1)
   {
        grp2 = getgrent();
        if(grp2 == NULL)
            break;
        if(!strcmp(grp1->gr_name, grp2->gr_name))
        {
            printf("Secondary Group : ");
            while(grp2->gr_mem[m] != NULL){
        printf("%s  ",grp2->gr_mem[m]);
        m++;
        }
            printf("\n");
       }



   }
}
