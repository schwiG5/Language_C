#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int id1 = fork(); 
    int id2 = fork();
    //int id2 = fork();
    
    //printf("Mon id est %d je suis le proc parent\n", id1);
    if (id1 > 0 && id2 > 0){
        printf("Je suis le parent %d %d mon id est %d et mon ppid est %d \n", id1, id2, getpid(), getppid());

    }
    else if (id1 > 0 && id2 == 0)
    {
        printf("Je suis l'enfant 1, %d %d mon id est %d et mon parentID est %d \n", id1, id2, getpid(), getppid());
        exit(0);
    }
    else if (id1 == 0 && id2 > 0)
    {
        printf("Je suis l'enfant 2, %d %d mon id est %d et mon parentID est %d \n", id1, id2, getpid(), getppid());
        exit(0);
    }
    else
    {
        printf("Je suis l'enfant 3, %d %d mon id est %d et mon parentID est %d \n", id1, id2, getpid(), getppid());
        exit(0);
    }

    return 0;
  
}