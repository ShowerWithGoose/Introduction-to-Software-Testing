#include<stdio.h>
int main()
{
    int zhan[100];
    int flag,num;
    int i=0;
    while(scanf("%d",&flag)!=-1) // @@ [scanf returns number of items, not the value; this condition never fails, so loop continues even after reading -1; should check flag==-1 to break]
    {
        if(flag==1&&i<99)//ÈëÕ»  // @@ [condition i<99 limits pushes to 99 instead of 100; should be i<100; also missing error output when stack is full (i==100)]
        {
            scanf("%d",&num);
            zhan[i]=num;
            i++;
        }
        else if(flag==0&&i>=0)//³öÕ»  // @@ [i>=0 is always true; the empty check inside is fine, but condition is redundant; no major error but empty check format issue below]
        {
            if(i==0)
            {
                printf("error\n");    // @@ [should print "error " (with space, no newline) as per problem specification]
            } 
            else{
                i--;
                printf("%d ",zhan[i]);
//                printf(" %d\n",i);
            }
        }
//        else
//        {
//            printf("error\n");
//        }
    }
    return 0;
}