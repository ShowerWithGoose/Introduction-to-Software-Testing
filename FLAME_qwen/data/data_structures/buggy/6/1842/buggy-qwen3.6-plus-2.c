#include<stdio.h>
int main()
{

    int s[110];
    int a,b;
    int p=-1;
    int i;
    while(1) // @@ [The loop condition is always true and lacks a termination check for the input value -1, which will cause an infinite loop. It should include a break statement when a == -1 or change the loop condition.]
    {
        scanf("%d",&a);
        if(a==1)
        {
            scanf("%d",&b);

            if(p==99)
                printf("error ");


            else
            {
            p++;
            s[p]=b;

            }
        }

        else if(a==0)
        {
            if(p==-1)
                printf("error ");

            else
            {
                printf("%d ",s[p]);
                p--;
            }




        }










    }

return 0;





}