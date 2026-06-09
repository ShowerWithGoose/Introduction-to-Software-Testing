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
            if((a[j-1]>='0'&&a[j+1]<='9')&&(a[j-1]<a[j+1])||(a[j-1]>='a'&&a[j+1]<='z')&&(a[j-1]<a[j+1])||(a[j-1]>='A'&&a[j+1]<='Z')&&(a[j-1]<a[j+1])) // @@ [The original condition logic was incorrect: it used ASCII values 0-9 instead of character '0'-'9', lacked type consistency checks (e.g., mixing digits and letters), and did not check if the start character is less than the end character. The corrected condition ensures both characters are of the same type (digit, lowercase, or uppercase) and the range is valid (start < end).]
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