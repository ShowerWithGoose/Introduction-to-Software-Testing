#include <stdio.h>
int main()
{
    char a[100];
    scanf("%s", a);
    int j=0;
    while(a[j]!='\0')
    {
        if(a[j]=='-')
        {
            if((a[j-1]>=0&&a[j+1]<=9)||(a[j-1]>='a'&&a[j+1]<='z')||(a[j-1]>='A'&&a[j+1]<='Z')) // @@ [Incorrect range checks: comparing characters with integer 0/9 instead of '0'/'9'; also logic is flawed because it doesn't ensure both ends are same type and valid, e.g., a[j-1] could be 'z' and a[j+1] 'a', which violates requirement that second char must be greater]
            {
            
                for(int k=1;k<=(a[j+1]-a[j-1]-1);k++) // @@ [Loop runs even when a[j+1] <= a[j-1], leading to negative or zero iterations; also no check that both sides are same category (e.g., digit vs letter)]
                {
                    printf("%c",a[j-1]+k);
                }
            }
            else
            printf("-");
        }
        else 
        printf("%c",a[j]);
        j++;
    }

   return 0;
}