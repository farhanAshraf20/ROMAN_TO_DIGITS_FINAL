#include <stdio.h>
 
int main(void) 
{
    if (remove("output.txt")||remove("o.txt") == 0) 
    {
        printf("The file is deleted successfully.");
    } 
    else 
    {
        printf("The file is not deleted.");
    }
    return 0;
}
