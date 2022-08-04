/*
Roman to digit code 
using command line 
Input we can give : I to M (1 to 1000)

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max_no 3
#define min_no 1

char fix_letter[] = "IVXLCDM";
char *fun_input;

int max = 1000;							
int sum = 0;
int count_I = 0, count_X = 0, count_C = 0, count_V = 0, count_L = 0, count_D = 0;

int input_check(void);
int function_check(char *fun_input);
int file_write(void);


int main(int argc, char* argv[])					// main function
{

		
	//*argv = *(argv+1);
	//printf("Argument No2 :%s \n",*argv);
	//printf("Argument No2 :%s \n",argv[1]);				// for only command line
	
	//fun_input = *argv;
	//fun_input = argv[1];						// for only command line
	
	fun_input = argv[1];						//command line input to char pointer
    	
	if (input_check() == 0)
	{
		printf("-------------------------------------------------------\n");
		function_check(fun_input);
	}
	else
	{
		exit(0);
	}


    return 0;
}


int input_check(void)							//check input function
{	

	char *input;
	int size = 0;
	int flag = 1;
	
	
	input = fun_input ;
    	
    	//printf("fun input :%s",input);
    	
	size = strlen(input);
		
	//printf("\nsize ...: %d \n",size);
	
	//for (int i = 0; i < size; i++)				// for only command line
	
	//for (int i = 0; i < size-1; i++)
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (fix_letter[j] == input[i])
			{
				flag = 0;
				// printf("%c ",input[i]);
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
	
	static int i=0;						//for use input Traverse
  
	switch (fun_input[i])
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
	
	i++;							// Shifting Input char pointer 
	
	//if (fun_input[i] !='\0')				// for only command line
	//if (fun_input[i+1] !='\0')
	if (fun_input[i] !='\0')
	{
		function_check(fun_input);
	}
	else
	{
		if ((count_I <= max_no) && (count_C <= max_no) && (count_X <= max_no) && (count_V <= min_no) && (count_L <= min_no) && (count_D <= min_no))
		{
			printf("\nInterger is : %d\n", sum);
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
	FILE *out=fopen("output.txt","w");
	//fputs(fun_input,out);
	
	fprintf(out,"Input : %sOutput : %d\n",fun_input,sum);
	
	fclose(out);

return 0;
}

