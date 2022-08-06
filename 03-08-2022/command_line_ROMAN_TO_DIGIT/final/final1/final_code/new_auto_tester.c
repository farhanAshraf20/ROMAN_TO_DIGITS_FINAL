/*
Roman To Digit code( I to M ) 
code reading input from .txt file and store it in another .txt file
input (IVXLCDM) should be the combination of only this alphabates in upper case .

*/
#include<stdio.h>
#include <string.h>
#include <stdlib.h>

#define max_no 3
#define min_no 1

char fix_letter[] = "IVXLCDM";
char *fun_input;

int fun_i;
int count_index=0;
int max;							
int decimal_output;
int count_I = 0, count_X = 0, count_C = 0, count_V = 0, count_L = 0, count_D = 0;

int input_check(void);
int remove_file(void);
int converter_logic(char *fun_input);
int file_write(void);
int file_write_invalid_input(void);


int main(int argc, char* argv[])
{
	remove_file();
	
	char line[9];	
	FILE *fptr;
	fptr = fopen(argv[1], "r");					//. txt file opening 
	
	if(fptr == NULL)
	{
		printf("Error in file opening");		
	}
	
	//printf("No of argument : %d \n",argc);
	//printf("Argument No1 :%s \n",argv[0]);	
	//printf("Argument No2 :%s \n",argv[1]);
		
	while(fgets(line,sizeof(line), fptr) != NULL)			//reading input line by line from .txt file
	{
		
		fun_i=0;
		max = 1000;							
		decimal_output = 0;
		count_index++;
		count_I = 0, count_X = 0, count_C = 0, count_V = 0, count_L = 0, count_D = 0;
		
		
		fun_input = line;					//assigning input
    		
    		
		if (input_check() == 0)					//checking input whether it is correct or not
		{
			//printf("-------------------------------------------------------\n");
			converter_logic(fun_input);			//conversion function call
		}
		else
		{
			exit(0);
		}
		
	}
	
        	
        fclose(fptr);							//closing input file

return 0;
}

int remove_file(void)
{
	if (remove("output.txt") || remove("invalid_output.txt") == 0) 
	{
		printf("The file is deleted successfully.\n");
	} 
	else 
	{
		printf("The file is not deleted.\n");
	}

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


int converter_logic(char *fun_input)					// code locic function
{
	//printf("\nfunction input : %s",fun_input);
	
	//printf("\nfunction input test for i : %d\n",fun_i);
  	//printf("\nfunction input test for string: %c\n",fun_input[fun_i]);
  	
  	//printf("\nfunction input size  test for string: %ld\n",strlen(fun_input));
  	
  	
  	
	switch (fun_input[fun_i])
	{
		case 'I':
		{
			count_I++;		
			if(fun_input[fun_i+1]=='V')
			{
				decimal_output += 4;
				fun_i++;
				break;
			}
		
			if(fun_input[fun_i+1]=='X')
			{
				decimal_output += 9;
				fun_i++;
				break;
			}
			decimal_output += 1;
			break;
		}
		case 'V':
		{
			count_V++;
			decimal_output += 5;
			break;
		}
		case 'X':
		{
			count_X++;
			if(fun_input[fun_i+1]=='L')
			{
				decimal_output += 40;
				fun_i++;
				break;
			}
			if(fun_input[fun_i+1]=='C')
			{
				decimal_output += 90;
				fun_i++;
				break;
			}
			decimal_output += 10;
			break;
		}

		case 'L':
		{
			count_L++;
			decimal_output += 50;
			break;
		}
		case 'C':
		{
			count_C++;
			if(fun_input[fun_i+1]=='D')
			{
				decimal_output += 400;
				fun_i++;
				break;
			}
			if(fun_input[fun_i+1]=='M')
			{
				decimal_output += 900;
				fun_i++;
				break;
			}
			decimal_output += 100;
			break;
		}
		case 'D':
		{
			count_D++;
			decimal_output += 500;
			break;
		}
		case 'M':
		{
			decimal_output += 1000;
			break;
		}
		default:
			printf("\nInvalid entry\n");
			break;
	}
	
	
	fun_i++;
								// Shifting Input char pointer 
	//printf("the i valu %d\n",fun_i);
	
	//if (fun_input[i] !='\0')				// for only command line
	
	/*if (fun_input[fun_i + 1] !='\0')
	{
		converter_logic(fun_input);
	}*/
	
	if(strlen(fun_input) > (fun_i+1))
	{
		converter_logic(fun_input);
	}
	else
	{
		if ((count_I <= max_no) && (count_C <= max_no) && (count_X <= max_no) && (count_V <= min_no) && (count_L <= min_no) && (count_D <= min_no))
		{
			printf("Interger is : %d\n", decimal_output);
			printf("------------------------------------\n");
			file_write();
		}
		else
		{
			file_write_invalid_input();
			printf("Invalid input...\n");
		}
	}

	return 0;
}


int file_write(void)								//writing output file
{
	//FILE *out=fopen("output.txt","w");					//overrite the output in .txt file
	FILE *out=fopen("output.txt","a+");					//append output to the .txt file
	//fputs(fun_input,out);
	fprintf(out,"\n-----------------------------------------\n");
	fprintf(out,"Input  : %sOutput : %d\n",fun_input,decimal_output);
	fprintf(out,"-----------------------------------------\n");
	fclose(out);								//closing .txt file

return 0;
}

int file_write_invalid_input(void)						//writing output file
{
					
	FILE *invalid_out=fopen("invalid_output.txt","a+");			//append output to the .txt file
	//fputs(fun_input,out);
	fprintf(invalid_out,"\n-----------------------------------------\n");
	fprintf(invalid_out,"Input   : %sOutput  : Invalid Input\nIndex no : %d\n",fun_input,count_index);
	fprintf(invalid_out,"-----------------------------------------\n");
	fclose(invalid_out);							//closing .txt file

return 0;
}






