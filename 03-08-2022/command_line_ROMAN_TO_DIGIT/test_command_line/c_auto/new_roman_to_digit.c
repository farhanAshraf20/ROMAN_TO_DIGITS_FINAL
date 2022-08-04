#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max_no 3
#define min_no 1

char fix_letter[] = "IVXLCDM";
int max = 1000;

char *fun_input;
int size = 0;
int i = 0;
int flag = 1;
int sum = 0;
int count_I = 0, count_X = 0, count_C = 0, count_V = 0, count_L = 0, count_D = 0;
int function_check(char *fun_input);

int main()
{
    char *input;
    char *temp, *first;

    printf("Enter a roman No. (b/w I to M) : ");
    scanf("%s", input);

    first = input;
    fun_input = input;

    size = strlen(input);

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
    if (flag == 0)
    {
        function_check(fun_input);
    }
    else
    {
        // printf("\nINPUT !!!!! : %s\n",first);
        printf("\ninvalid input\n");
    }

    ///***********************************

    return 0;
}

int function_check(char *fun_input)
{
    static int i=0;
    printf("Size of input : %ld\n",strlen(fun_input));
    switch (fun_input[i])
    {
        case 'I':
            if(fun_input[i+1]=='V')
            {
                sum += 4;
                i++;
                break;
            }
            if(fun_input[i+1]=='X')
            {
                sum += 9;
                i++;
                break;
            }
            sum += 1;
            break;

        case 'V':
            sum += 5;
            break;

        case 'X':
            if(fun_input[i+1]=='L')
            {
                sum += 40;
                i++;
                break;
            }
            if(fun_input[i+1]=='C')
            {
                sum += 90;
                i++;
                break;
            }
            sum += 10;
            break;

        case 'L':
            sum += 50;
            break;

        case 'C':
            if(fun_input[i+1]=='D')
            {
                sum += 400;
                i++;
                break;
            }
            if(fun_input[i+1]=='M')
            {
                sum += 900;
                i++;
                break;
            }
            sum += 100;
            break;

        case 'D':
            sum += 500;
            break;

        case 'M':
            sum += 1000;
            break;

        default:
            printf("\nInvalid entry\n");
            break;
    }

    i++;
    if (fun_input[i] !='\0')
    {
        function_check(fun_input);
    }
    else
    {
        if ((count_I <= max_no) && (count_C <= max_no) && (count_X <= max_no) && (count_V <= min_no) && (count_L <= min_no) && (count_D <= min_no))
        {
            printf("\nInterger is : %d\n", sum);
        }
        else
        {
            printf("\ninvalid input\n");
        }


    }
    return 0;
}
