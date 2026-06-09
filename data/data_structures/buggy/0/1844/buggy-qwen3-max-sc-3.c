#include<stdio.h>
int main()
{
    char s,a[100];
    int i,j,k,delta;
    for(i=0;scanf("%c",&s)!=EOF;i++){
        a[i]=s;
    } @@ [The loop does not terminate input with a null terminator, leading to undefined behavior when accessing a[j+1] later. Also, EOF handling with %c may include newline characters and doesn't properly delimit the string.]
    for(j=0;j<=i;j++){ @@ [Loop goes to j<=i, but valid indices are 0 to i-1; accessing a[i] (and a[i+1] in logic) is out-of-bounds.]
        if(a[j]!='-'){
            printf("%c",a[j]);
        }
        else if(a[j]=='-'){
            if((a[j-1]>='0'&&a[j+1]<='9'&&a[j-1]<a[j+1])||(a[j-1]>='a'&&a[j+1]<='z'&&a[j-1]<a[j+1])||(a[j-1]>='A'&&a[j+1]<='Z'&&a[j-1]<a[j+1])){ @@ [Condition checks only one side of the range: e.g., a[j-1]>='0' but a[j+1]<='9' — should also ensure a[j+1]>='0'. Same issue for letters. This allows invalid cross-type cases like '9-a' to pass.]
                delta=a[j+1]-a[j-1];
                for(k=1;k<=delta-1;k++){
                printf("%c",a[j-1]+k);
                }
                
                
            }
        }
    }
    return 0;
}