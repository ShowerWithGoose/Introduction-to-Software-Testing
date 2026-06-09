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
            if((a[j-1]>=0&&a[j+1]<=9)||(a[j-1]>='a'&&a[j+1]<='z')||(a[j-1]>='A'&&a[j+1]<='Z')) // @@ Missing bounds checks for j-1 and j+1, incorrect digit comparisons (should use '0' and '9'), missing lower/upper bounds for letters, missing left<right check, and OR allows mixed types
            {
            
                for(int k=1;k<=(a[j+1]-a[j-1]-1);k++) // @@ Loop condition does not handle case when left >= right; should check left < right before expanding, otherwise print '-'
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