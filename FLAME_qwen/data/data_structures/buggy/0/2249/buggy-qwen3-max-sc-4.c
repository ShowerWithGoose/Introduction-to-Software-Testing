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
            if((a[j-1]>=0&&a[j+1]<=9)||(a[j-1]>='a'&&a[j+1]<='z')||(a[j-1]>='A'&&a[j+1]<='Z')) // @@ [Incorrect condition logic: comparing characters with numeric literals 0 and 9 instead of '0' and '9'; also, conditions check only one side of the range (e.g., a[j-1] >= 'a' but a[j+1] <= 'z') without ensuring both ends are in the same category and valid for expansion]
            {
            
                for(int k=1;k<=(a[j+1]-a[j-1]-1);k++) // @@ [Loop runs even when expansion is invalid (e.g., when a[j+1] <= a[j-1]), leading to negative or zero iterations; also, no check that both surrounding chars are of same type and a[j+1] > a[j-1]]
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