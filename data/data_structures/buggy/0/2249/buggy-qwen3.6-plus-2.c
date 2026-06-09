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
            if((a[j-1]>=0&&a[j+1]<=9)||(a[j-1]>='a'&&a[j+1]<='z')||(a[j-1]>='A'&&a[j+1]<='Z')) // @@ Incorrect digit comparison (should use character literals '0' and '9' instead of integers 0 and 9), missing condition to ensure a[j+1] > a[j-1] for valid expansion, and incomplete range checks (e.g., should verify a[j-1] <= 'z' and a[j+1] >= 'a' to ensure both characters are strictly within the same type range).
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