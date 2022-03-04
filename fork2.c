#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    int id1 = fork(); 
    int id2 = fork();
    int wstatus;
    int exit_value = WEXITSTATUS(wstatus);
    //int id2 = fork();
    
    //printf("Mon id est %d je suis le proc parent\n", id1);
    if (id1 > 0 && id2 > 0){
        printf("Je suis le parent %d %d mon id est %d et mon ppid est %d \n", id1, id2, getpid(), getppid());

    }
    else if (id1 > 0 && id2 == 0)
    {
        waitpid(getpid(), &wstatus, 0);
        printf("Je suis l'enfant 1, %d %d mon id est %d et mon parentID est %d \n", id1, id2, getpid(), getppid());
        printf("Le processus fils %d est mort en renvoyant %d\n", getpid(), exit_value);
    }
    else if (id1 == 0 && id2 > 0)
    {
        waitpid(getpid(), &wstatus, 0);
        printf("Je suis l'enfant 2, %d %d mon id est %d et mon parentID est %d \n", id1, id2, getpid(), getppid());
        printf("Le processus fils %d est mort en renvoyant %d\n", getpid(), exit_value);
    }
    else
    {
        waitpid(getpid(), &wstatus, 0);
        printf("Je suis l'enfant 3, %d %d mon id est %d et mon parentID est %d \n", id1, id2, getpid(), getppid());
        printf("Le processus fils %d est mort en renvoyant %d\n", getpid(), exit_value);
    }

    return 0;
  
}