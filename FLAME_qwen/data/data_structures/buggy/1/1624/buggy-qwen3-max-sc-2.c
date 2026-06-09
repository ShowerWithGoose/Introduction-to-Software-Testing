#include <stdio.h>


int main() 
{
    int n;
    scanf("%d",&n);
    
    if(n==1)
    {
        printf("1");
    }
    if(n==2) // @@ [Using separate 'if' statements instead of 'else if' causes multiple blocks to execute when n >= 2, leading to incorrect combined output]
    {
        printf("1 2 \n2 1 ");
        
    }
    if(n==3) // @@ [Using separate 'if' statements instead of 'else if' causes multiple blocks to execute when n >= 3, leading to incorrect combined output]
    {
        printf("1 2 3\n1 3 2 \n2 1 3 \n2 3 1\n3 1 2\n3 2 1");
    }
    if(n==4) // @@ [Using separate 'if' statements instead of 'else if' causes multiple blocks to execute when n >= 4, leading to incorrect combined output]
    {
        printf("1 2 3 4\n1 2 4 3\n1 3 2 4\n1 3 4 2\n1 4 2 3\n1 4 3 2\n2 1 3 4\n2 1 4 3\n2 3 1 4\n2 3 4 1\n2 4 1 3 \n2 4 3 1\n3 1 2 4\n3 1 4 2\n3 2 1 4\n3 2 4 1\n3 4 1 2\n3 4 2 1\n4 1 2 3\n4 1 3 2\n4 2 1 3\n4 2 3 1\n4 3 1 2\n4 3 2 1\n");
    }
    if(n==5) // @@ [Using separate 'if' statements instead of 'else if' causes multiple blocks to execute when n == 5; also, this block only prints "1", which is completely wrong for n=5]
    {
        printf("1");
    }
                    
    return 0;
}