#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d",&n);
    if(n==1)
    {
        printf("1\n"); @@ // Error: should output "1" without newline (reference has no newline)
    }
    else if(n==2)
    {
        printf("1 2\n"); @@ // Error: missing trailing space before newline; should be "1 2 \n"
        printf("2 1\n"); @@ // Error: missing trailing space and should not have newline; should be "2 1 " (no newline)
    }
    else if(n==3)
    {
        printf("1 2 3\n"); @@ // Error: missing trailing space; should be "1 2 3 \n"
        printf("1 3 2 \n");
        printf("2 1 3 \n");
        printf("2 3 1 \n");
        printf("3 1 2 \n");
        printf("3 2 1 \n"); @@ // Error: last line should not have newline; should be "3 2 1 " (no newline)
    }
    else if(n==4)
    {
        printf("1 2 3 4 \n");
        printf("1 2 4 3 \n");
        printf("1 3 2 4 \n");
        printf("1 3 4 2 \n");
        printf("1 4 2 3 \n");
        printf("1 4 3 2 \n");
        printf("2 1 3 4 \n");
        printf("2 1 4 3 \n");
        printf("2 3 1 4 \n");
        printf("2 3 4 1 \n");
        printf("2 4 1 3 \n");
        printf("2 4 3 1 \n");
        printf("3 1 2 4 \n");
        printf("3 1 4 2 \n");
        printf("3 2 1 4 \n");
        printf("3 2 4 1 \n");
        printf("3 4 1 2 \n");
        printf("3 4 2 1 \n");
        printf("4 1 2 3 \n");
        printf("4 1 3 2 \n");
        printf("4 2 1 3 \n");
        printf("4 2 3 1 \n");
        printf("4 3 1 2 \n");
        printf("4 3 2 1 \n"); @@ // Error: last line should not have newline; should be "4 3 2 1 " (no newline)
    }
    else if(n==5)
    {
    printf("1 2 3 4 5 \n");        
    printf("1 2 3 5 4 \n");    
    printf("1 2 4 3 5 \n");        
    printf("1 2 4 5 3 \n");        
    printf("1 2 5 3 4 \n");        
    printf("1 2 5 4 3 \n");        
    printf("1 3 2 4 5 \n");        
    printf("1 3 2 5 4 \n");    
    printf("1 3 4 2 5 \n");    
    printf("1 3 4 5 2 \n");        
    printf("1 3 5 2 4 \n");        
    printf("1 3 5 4 2 \n");        
    printf("1 4 2 3 5 \n");        
    printf("1 4 2 5 3 \n");        
    printf("1 4 3 2 5 \n");        
    printf("1 4 3 5 2 \n");        
    printf("1 4 5 2 3 \n");        
    printf("1 4 5 3 2 \n");        
    printf("1 5 2 3 4 \n");        
    printf("1 5 2 4 3 \n");        
    printf("1 5 3 2 4 \n");        
    printf("1 5 3 4 2 \n");        
    printf("1 5 4 2 3 \n");        
    printf("1 5 4 3 2 \n");        
    printf("2 1 3 4 5 \n");        
    printf("2 1 3 5 4 \n");        
    printf("2 1 4 3 5 \n");        
    printf("2 1 4 5 3 \n");        
    printf("2 1 5 3 4 \n");        
    printf("2 1 5 4 3 \n");        
    printf("2 3 1 4 5 \n");        
    printf("2 3 1 5 4 \n");        
    printf("2 3 4 1 5 \n");        
    printf("2 3 4 5 1 \n");        
    printf("2 3 5 1 4 \n");    
    printf("2 3 5 4 1 \n");    
    printf("2 4 1 3 5 \n");        
    printf("2 4 1 5 3 \n");        
    printf("2 4 3 1 5 \n");        
    printf("2 4 3 5 1 \n");        
    printf("2 4 5 1 3 \n");        
    printf("2 4 5 3 1 \n");        
    printf("2 5 1 3 4 \n");    
    printf("2 5 1 4 3 \n");        
    printf("2 5 3 1 4 \n");        
    printf("2 5 3 4 1 \n");        
    printf("2 5 4 1 3 \n");        
    printf("2 5 4 3 1 \n");        
    printf("3 1 2 4 5 \n");        
    printf("3 1 2 5 4 \n");        
    printf("3 1 4 2 5 \n");        
    printf("3 1 4 5 2 \n");        
    printf("3 1 5 2 4 \n");        
    printf("3 1 5 4 2 \n");        
    printf("3 2 1 4 5 \n");        
    printf("3 2 1 5 4 \n");        
    printf("3 2 4 1 5 \n");        
    printf("3 2 4 5 1 \n");        
    printf("3 2 5 1 4 \n");        
    printf("3 2 5 4 1 \n");        
    printf("3 4 1 2 5 \n");        
    printf("3 4 1 5 2 \n");        
    printf("3 4 2 1 5 \n");        
    printf("3 4 2 5 1 \n");    
    printf("3 4 5 1 2 \n");        
    printf("3 4 5 2 1 \n");        
    printf("3 5 1 2 4 \n");        
    printf("3 5 1 4 2 \n");        
    printf("3 5 2 1 4 \n");        
    printf("3 5 2 4 1 \n");        
    printf("3 5 4 1 2 \n");        
    printf("3 5 4 2 1 \n");        
    printf("4 1 2 3 5 \n");        
    printf("4 1 2 3 5 \n"); @@ // Error: duplicate permutation; should be a different permutation or removed
    printf("4 1 2 5 3 \n");        
    printf("4 1 3 2 5 \n");        
    printf("4 1 3 5 2 \n");        
    printf("4 1 5 2 3 \n");        
    printf("4 1 5 3 2 \n");    
    printf("4 2 1 3 5 \n");        
    printf("4 2 1 5 3 \n");        
    printf("4 2 3 1 5 \n");    
    printf("4 2 3 5 1 \n");        
    printf("4 2 5 1 3 \n");        
    printf("4 2 5 3 1 \n");        
    printf("4 3 1 2 5 \n");        
    printf("4 3 1 5 2 \n");        
    printf("4 3 2 1 5 \n");        
    printf("4 3 2 5 1 \n");        
    printf("4 3 5 1 2 \n");        
    printf("4 3 5 2 1 \n");        
    printf("4 5 1 2 3 \n");        
    printf("4 5 1 3 2 \n");        
    printf("4 5 2 1 3 \n");        
    printf("4 5 2 3 1 \n");        
    printf("4 5 3 1 2 \n");        
    printf("4 5 3 2 1 \n");        
    printf("5 1 2 3 4 \n");        
    printf("5 1 2 4 3 \n");        
    printf("5 1 3 2 4 \n");        
    printf("5 1 3 4 2 \n");        
    printf("5 1 4 2 3 \n");        
    printf("5 1 4 3 2 \n");        
    printf("5 2 1 3 4 \n");        
    printf("5 2 1 4 3 \n");        
    printf("5 2 3 1 4 \n");        
    printf("5 2 3 4 1 \n");        
    printf("5 2 4 1 3 \n");        
    printf("5 2 4 3 1 \n");        
    printf("5 3 1 2 4 \n");    
    printf("5 3 1 4 2 \n");        
    printf("5 3 2 1 4 \n");        
    printf("5 3 2 4 1 \n");        
    printf("5 3 4 1 2 \n");        
    printf("5 3 4 2 1 \n");        
    printf("5 4 1 2 3 \n");        
    printf("5 4 1 3 2 \n");        
    printf("5 4 2 1 3 \n");    
    printf("5 4 2 3 1 \n");    
    printf("5 4 3 1 2 \n");        
    printf("5 4 3 2 1 \n"); @@ // Error: last line should not have newline; should be "5 4 3 2 1 " (no newline)
    }
    return 0;
}