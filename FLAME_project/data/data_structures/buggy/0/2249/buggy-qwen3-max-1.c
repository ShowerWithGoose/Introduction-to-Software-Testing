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
            if((a[j-1]>=0&&a[j+1]<=9)||(a[j-1]>='a'&&a[j+1]<='z')||(a[j-1]>='A'&&a[j+1]<='Z')) // @@ [The condition is logically incorrect: it checks unrelated bounds (e.g., a[j-1] >= 0 is always true for char; also, it doesn't ensure both sides are same type or that a[j+1] > a[j-1]. Additionally, '0'-'9' should be compared with character literals like '0', not integer 0.]
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