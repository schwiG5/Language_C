#include <unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<sys/wait.h>

int main(void)
{
    int i;
    for(i=0; i<4; i++)
        if(fork())break;
    printf("Mon nom est <%c>\n", 'A'+i);
    //wait(NULL); enlever le com pour la question 3
    return 0;
}
