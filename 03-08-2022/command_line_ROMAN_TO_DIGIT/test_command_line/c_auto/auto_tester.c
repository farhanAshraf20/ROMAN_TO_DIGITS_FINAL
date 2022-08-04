#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <string.h>
//char pointer array


int main()
{

	char line[1000];
	char *buffer;
	int i=0;
	size_t n=0;
	FILE *fptr;
	fptr = fopen("input.txt", "r");
	if(fptr == NULL)
	{
		printf("Error in file opening");
	}
	
	//while(getline(&line, &n, fptr) != EOF)
	//{
	//	printf("Content = %s",line);
	//	buffer=line;
	//	i++;
	//}
		i++;

        	while(fgets(line, sizeof(line), fptr) != NULL)
        	{
        		printf("size of input : %ld : Content = %s",strlen(line)-1,line);
        		
        		
        		
        		
        		
        		
        		
        		
        	}
	
	fclose(fptr);
	
	

		

/*
//execl("./test","input.txt", NULL);


	FILE *fptr;
	char *line;
	size_t n=0;
	int i = 0;
	char *buffer;
	fptr = fopen("input.txt", "r");
	char *temp;
	while(getline(&line, &n, fptr) != -1)
	{
		
		//while(line[i] != '\n')
		//{ 
		//buffer[i];
		//strcpy(,line);
		
		//buffer++;
		i++;
			printf("%ld -- %s", strlen(line), line);
			
			//execl("./test",line, NULL);
			//execl("./test",line, NULL);
			
			//i++;
		
        		
		//}
		
		//i=0;
	}
	buffer = line;
	//printf("%d\n", i);
	for(int val = 0; val < i; val++)
	{
		printf(" Buffer = %s\n", buffer);
	}	





	FILE    *textfile;
	char    ch;

	textfile = fopen("input.txt", "r");
	
	if(textfile == NULL)
	{
		return 1;
	}
	

	while((ch = fgetc(textfile))!=EOF) 
	{
		//putchar(ch);
		printf("input %c\n",ch);
		char *args[]={"./test","VI",NULL};
        	execv(args[0],args);
	}



        //A null terminated array of character
        //pointers
        
         //execv(args,args);
         
	//fclose(textfile);
        printf("Ending-----");
    */ 
    return 0;
}
