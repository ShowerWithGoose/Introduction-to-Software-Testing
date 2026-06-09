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
            if((a[j-1]>=0&&a[j+1]<=9)||(a[j-1]>='a'&&a[j+1]<='z')||(a[j-1]>='A'&&a[j+1]<='Z')) // @@ [Incorrect condition logic: comparing characters with integer 0/9 instead of '0'/'9'; also checking only one side of the range (e.g., a[j-1] >= 'a' but not <= 'z', and similarly for others), and mixing types across cases]
            {
            
                for(int k=1;k<=(a[j+1]-a[j-1]-1);k++) // @@ [Loop runs even when expansion shouldn't occur (e.g., if a[j+1] <= a[j-1]), leading to negative or zero iterations or incorrect output; also, no check that both sides are same type and valid]
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