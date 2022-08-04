#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <string.h>


int main()
{

	FILE *fptr = NULL;
	char *line;
	size_t n=0;       // int data type give warning // unsigned integral type
	
	fptr = fopen("input.txt", "r");
	
	while(getline(&line, &n, fptr) != -1)
	{
		//printf("%s",line);
		execl("./test",linex, NULL);	// calling another executable file
        	
	}

        printf("Ending-----");
     
    return 0;
}
