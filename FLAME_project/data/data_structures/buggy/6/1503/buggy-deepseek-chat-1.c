#include <stdio.h>

struct Zhan
{
    int a;
    int x;
}zhan[100];

int n, r;

int main()
{
    while(r != -1)
    {
        scanf("%d", &zhan[n].a );
        
        if(zhan[n].a == 1)
        {
        if(n<100)
        scanf("%d", &zhan[n].x );
        else
        {
        printf("error ");
        n--;
        }
        }
        
        if(zhan[n].a == 0)
        {
            //printf("n%d ", n);
            if(n > 0)
            {
            n--;
            printf("%d ", zhan[n].x );
            n--; // @@ This line decrements n twice, causing the stack pointer to skip elements and output incorrect values.
            }
            else
            {
            printf("error ");
            n--;
            }
        }
        
        if(zhan[n].a == -1)
        r=-1;
        
        n++;
    }
    
    return 0;
}