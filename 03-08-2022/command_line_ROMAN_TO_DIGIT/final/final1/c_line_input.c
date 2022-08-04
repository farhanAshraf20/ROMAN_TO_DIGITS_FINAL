#include<stdio.h>
#include <string.h>
#include <stdlib.h>

#define max_no 3
#define min_no 1

char fix_letter[] = "IVXLCDM";
char *fun_input;

int fun_i;//=0;
int max;// = 1000;							
int sum;// = 0;
int count_I = 0, count_X = 0, count_C = 0, count_V = 0, count_L = 0, count_D = 0;

int input_check(void);
int function_check(char *fun_input);
int file_write(void);


int main(int argc, char* argv[])
{
	char line[1000];
		
	FILE *fptr;
	fptr = fopen(argv[1], "r");
	
	if(fptr == NULL)
	{
		printf("Error in file opening");
	}
	
	//printf("No of argument : %d \n",argc);
	//printf("Argument No1 :%s \n",argv[0]);	
	printf("Argument No2 :%s \n",argv[1]);
	
	
	
	while(fgets(line,sizeof(line), fptr) != NULL)
	{
		
		fun_i=0;
		max = 1000;							
		sum = 0;
		count_I = 0, count_X = 0, count_C = 0, count_V = 0, count_L = 0, count_D = 0;
		
				
		
		fun_input = line;				//command line input to char pointer
    		fun_i=0;
		if (input_check() == 0)
		{
			//printf("-------------------------------------------------------\n");
			function_check(fun_input);
		}
		else
		{
			exit(0);
		}
		
	}
	
        	
        fclose(fptr);

return 0;
}


int input_check(void)							//check input function
{	

	char *input;
	int size = 0;
	int flag = 1;
	
	
	input = fun_input ;
    	printf("\n------------------------------------\n");
    	printf("fun input :%s",input);
    	
	size = strlen(input);
		
	//printf("\nsize ... : %d \n",size);
	
	//for (int i = 0; i < size; i++)				// for only command line
	
	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (fix_letter[j] == input[i])
			{
				flag = 0;
				//printf("check input : %c \n",input[i]);
				break;
			}
			else
			{
				flag = 1;
			}
		}
	}
	
	
	if(flag == 0)
	{
		return 0;
	}
	else
	{
		printf("...Invalid Input...\n");
		return 1;
	}
	
}


int function_check(char *fun_input)					// code locic function
{
	//printf("\nfunction input : %s",fun_input);
	
	//printf("\nfunction input test for i : %d\n",fun_i);
  	printf("\nfunction input test for string: %c\n",fun_input[fun_i]);
  	
  	printf("\nfunction input size  test for string: %ld\n",strlen(fun_input));
  	
  	
  	
	switch (fun_input[fun_i])
	{
		case 'I':
		{
		    count_I++;
		    sum += 1;
		    max = 1;
		    // printf("\nvalue of max :%d\n",max);
		    break;
		}
		case 'V':
		{
		    count_V++;

		    if (max >= 5)
		    {
			sum += 5;
			max = 5;
		    }
		    else if (sum == 1)
		    {
			sum = 5 - sum;
		    }
		    
		    else
		    {
			count_I = count_I + 2;
		    }
		    break;
		}
		case 'X':
		{
		    count_X++;
		    if (max >= 10)
		    {
			sum += 10;
			max = 10;
		    }
		    else if (sum == 1)
		    {
			sum = 10 - sum;
		    }
		    else
		    {
			count_X = count_X + 2;
		    }

		    break;
		}
		case 'L':
		{
		    count_L++;
		    if (max >= 50)
		    {
			sum += 50;
			max = 50;
		    }
		    else
		    {
			sum = 50 - sum;
		    }
		    break;
		}
		case 'C':
		{
		    count_C++;
		    if (max >= 100)
		    {
			sum += 100;
			max = 100;
		    }
		    else
		    {
			sum = 100 - sum;
		    }
		    break;
		}
		case 'D':
		{
		    count_D++;
		    if (max >= 500)
		    {
			sum += 500;
			max = 500;
		    }
		    else
		    {
			sum = 500 - sum;
		    }
		    break;
		}
		case 'M':
		{
		    if (max >= 1000)
		    {
			sum += 1000;
			max = 1000;
		    }
		    else
		    {
			sum = 1000 - sum;
		    }
		    break;
		}
		default:
		{
		    printf("\nInvalid entry...\n");
		    break;
		}
	}
	
	
	fun_i++;
								// Shifting Input char pointer 
	//printf("the i valu %d\n",fun_i);
	
	//if (fun_input[i] !='\0')				// for only command line
	
	/*if (fun_input[fun_i + 1] !='\0')
	{
		function_check(fun_input);
	}*/
	
	if(strlen(fun_input) > (fun_i+1))
	{
		function_check(fun_input);
	}
	else
	{
		if ((count_I <= max_no) && (count_C <= max_no) && (count_X <= max_no) && (count_V <= min_no) && (count_L <= min_no) && (count_D <= min_no))
		{
			printf("Interger is : %d\n", sum);
			printf("------------------------------------\n");
			file_write();
		}
		else
		{
			printf("Invalid input...\n");
		}
	}

	return 0;
}


int file_write(void)
{
	//FILE *out=fopen("output.txt","w");
	FILE *out=fopen("output.txt","a+");
	//fputs(fun_input,out);
	fprintf(out,"\n-----------------------------------------\n");
	fprintf(out,"Input  : %sOutput : %d\n",fun_input,sum);
	fprintf(out,"-----------------------------------------\n");
	fclose(out);

return 0;
}
