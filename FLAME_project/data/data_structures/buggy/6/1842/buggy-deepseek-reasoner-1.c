#include<stdio.h>
int main()
{

    int s[110];
    int a,b;
    int p=-1;
    int i;
    while(1) // @@ Missing condition to break on input -1, causing infinite loop and time limit exceeded.
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