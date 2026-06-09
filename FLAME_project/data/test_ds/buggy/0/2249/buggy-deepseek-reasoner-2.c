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
            if((a[j-1]>=0&&a[j+1]<=9)||(a[j-1]>='a'&&a[j+1]<='z')||(a[j-1]>='A'&&a[j+1]<='Z')) // @@ The condition does not correctly check that both characters are of the same type (digit, lowercase, uppercase) and that the character after '-' is greater than the one before. For digits, it uses a[j-1]>=0 (always true) and a[j+1]<=9 (only true for control characters, not actual digits), so digit expansions never occur. Also missing a check for left < right; if the condition passes but left >= right, no expansion is performed but the '-' is also not printed, causing missing output.
            {
            
                for(int k=1;k<=(a[j+1]-a[j-1]-1);k++)
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