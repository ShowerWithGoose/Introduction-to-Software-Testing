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
            if((a[j-1]>=0&&a[j+1]<=9)||(a[j-1]>='a'&&a[j+1]<='z')||(a[j-1]>='A'&&a[j+1]<='Z'))
            { // @@ Error: The condition (a[j-1]>=0&&a[j+1]<=9) incorrectly compares characters with integers 0 and 9, which are not the character digits '0' and '9'. This will never be true for digit characters. It should be (a[j-1]>='0'&&a[j+1]<='9').
            
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