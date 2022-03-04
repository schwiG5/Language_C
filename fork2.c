#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>


int main() {
    int child = 0;

    printf("Combien de fils voulez vous ?");
    scanf("%d[^\n]", &child);

    for(int i=0;i<child;i++)
    {
        if(fork() == 0)
        {
            printf("CHILD pid %d DE PARENT pid %d\n",getpid(),getppid());
            exit(0);
        }
    }
    for(int i=0;i<5;i++)
    wait(NULL);

    //printf("%d\n", child);
    exit(EXIT_SUCCESS);
}