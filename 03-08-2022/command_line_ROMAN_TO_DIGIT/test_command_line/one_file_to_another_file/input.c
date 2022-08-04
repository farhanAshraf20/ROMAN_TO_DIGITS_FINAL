#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
        //A null terminated array of character
        //pointers
        char *args[]={"./code","VI",NULL};
        execv(args[0],args);
     
        printf("Ending-----");
     
    return 0;
}
