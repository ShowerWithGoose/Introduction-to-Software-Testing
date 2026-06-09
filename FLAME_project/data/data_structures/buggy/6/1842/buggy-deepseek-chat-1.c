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

            if(p==99) // @@ The condition should be p >= 99 or p == 100 to check if the stack is full (since max capacity is 100, indices 0-99 are valid). Using p==99 only catches the exact moment when p is 99, but after pushing, p becomes 100, and the next push would overflow without detection. The correct check is if(p >= 99) or if(p == 100) before incrementing.
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