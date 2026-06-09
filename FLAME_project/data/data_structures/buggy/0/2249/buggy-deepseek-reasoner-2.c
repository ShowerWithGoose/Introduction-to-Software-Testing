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
            if((a[j-1]>=0&&a[j+1]<=9)||(a[j-1]>='a'&&a[j+1]<='z')||(a[j-1]>='A'&&a[j+1]<='Z')) // @@ The condition fails to correctly check that both sides are of the same type (digits, lowercase, or uppercase) and that left < right; for digits it uses a[j-1]>=0 (always true) and a[j+1]<=9 (false for digit characters), so expansion never occurs.
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