#include<stdio.h>
int main()
{
    char s,a[100];
    int i,j,k,delta;
    for(i=0;scanf("%c",&s)!=EOF;i++){
        a[i]=s;
    } @@ [The loop does not properly terminate the string with '\0', leading to undefined behavior when accessing a[j+1] beyond the last character. Also, using scanf in a loop like this may include newline characters which are not handled correctly.]
    for(j=0;j<=i;j++){ @@ [Loop condition should be j < i, not j <= i, because valid indices are 0 to i-1. Accessing a[i] is out-of-bounds since a[i] was never assigned (loop stopped after EOF).]
        if(a[j]!='-'){
            printf("%c",a[j]);
        }
        else if(a[j]=='-'){
            if((a[j-1]>='0'&&a[j+1]<='9'&&a[j-1]<a[j+1])||(a[j-1]>='a'&&a[j+1]<='z'&&a[j-1]<a[j+1])||(a[j-1]>='A'&&a[j+1]<='Z'&&a[j-1]<a[j+1])){ @@ [Condition checks are incorrect: e.g., 'a[j-1] >= '0'' but 'a[j+1] <= '9'' without verifying that a[j+1] >= '0'. Same issue for letters. This allows mixed-type cases like '0-Z' to pass if Z <= '9' (which it isn't), but more critically, it doesn't ensure both ends are of the same category. Also, accessing a[j-1] when j=0 leads to out-of-bounds access.]
                delta=a[j+1]-a[j-1];
                for(k=1;k<=delta-1;k++){
                printf("%c",a[j-1]+k);
                }
                
                
            }
        }
    }
    return 0;
}