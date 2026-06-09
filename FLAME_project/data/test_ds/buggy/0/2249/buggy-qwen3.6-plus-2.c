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
            if((a[j-1]>='0'&&a[j-1]<='9'&&a[j+1]>='0'&&a[j+1]<='9'&&a[j+1]>a[j-1])||(a[j-1]>='a'&&a[j-1]<='z'&&a[j+1]>='a'&&a[j+1]<='z'&&a[j+1]>a[j-1])||(a[j-1]>='A'&&a[j-1]<='Z'&&a[j+1]>='A'&&a[j+1]<='Z'&&a[j+1]>a[j-1])) // @@ Incorrect character range checks (comparing with integers 0 and 9 instead of character literals '0' and '9') and missing conditions to ensure both characters are of the same type and the right character is strictly greater than the left.
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