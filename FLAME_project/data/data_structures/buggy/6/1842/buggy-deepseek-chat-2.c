#include<stdio.h>
int main()
{

    int s[110];
    int a,b;
    int p=-1;
    int i;
    while(1)
    {
        scanf("%d",&a);
        if(a==1)
        {
            scanf("%d",&b);

            if(p==99) // @@ The condition should be p >= 99 or p == 100 to check if the stack is full (since max capacity is 100, indices 0-99 are valid). Using p==99 only catches the exact full state but misses overflow when p is already 100 or more due to a previous error. Also, the reference program uses p<100 to allow push, so the error condition should be p >= 100.
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