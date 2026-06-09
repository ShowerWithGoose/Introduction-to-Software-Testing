#include<stdio.h>
int main()
{
    char s,a[100];
    int i,j,k,delta;
    for(i=0;scanf("%c",&s)!=EOF;i++){
        a[i]=s;
    } @@ [The loop does not terminate input with a null terminator, leading to undefined behavior when processing the array as a string. Also, EOF handling with %c may include newline characters and doesn't properly delimit the string.]
    for(j=0;j<=i;j++){ @@ [Loop goes up to j<=i, which accesses a[i] — an uninitialized or EOF-containing element — causing out-of-bounds access. Should be j < i.]
        if(a[j]!='-'){
            printf("%c",a[j]);
        }
        else if(a[j]=='-'){
            if((a[j-1]>='0'&&a[j+1]<='9'&&a[j-1]<a[j+1])||(a[j-1]>='a'&&a[j+1]<='z'&&a[j-1]<a[j+1])||(a[j-1]>='A'&&a[j+1]<='Z'&&a[j-1]<a[j+1])){ @@ [Condition checks are incorrect: e.g., 'a[j-1] >= '0'' but 'a[j+1] <= '9'' without verifying a[j+1] >= '0'. Same for letters. This allows mixed-type cases like '0-Z' to pass if one side matches part of the condition.]
                delta=a[j+1]-a[j-1];
                for(k=1;k<=delta-1;k++){ @@ [If delta is 1 (e.g., 'a'-'b'), this loop runs from k=1 to 0, which doesn't execute — correct. But logic assumes valid range already, which isn't guaranteed due to flawed condition above. Also, if j is 0, a[j-1] is a[-1] → undefined behavior. Similarly, if j == i-1, a[j+1] is beyond input.]
                printf("%c",a[j-1]+k);
                }
                
                
            }
        }
    }
    return 0;
}