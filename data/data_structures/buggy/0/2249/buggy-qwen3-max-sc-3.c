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
            if((a[j-1]>=0&&a[j+1]<=9)||(a[j-1]>='a'&&a[j+1]<='z')||(a[j-1]>='A'&&a[j+1]<='Z')) // @@ [Incorrect condition logic: comparing characters with numeric literals 0 and 9 without quotes; also, conditions check only one side of the range (e.g., a[j-1] >= 'a' but a[j+1] <= 'z'), which doesn't ensure both are in the same category or that a[j+1] > a[j-1]. Additionally, accessing a[j-1] when j=0 leads to out-of-bounds read.]
            {
            
                for(int k=1;k<=(a[j+1]-a[j-1]-1);k++) // @@ [Potential undefined behavior: if a[j-1] >= a[j+1], the loop runs with negative or zero iterations incorrectly; also, no validation that expansion is valid (same type and increasing). Moreover, if j=0, a[j-1] is invalid memory access.]
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