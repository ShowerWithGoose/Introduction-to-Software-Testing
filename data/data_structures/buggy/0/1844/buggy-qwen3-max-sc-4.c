#include<stdio.h>
int main()
{
    char s,a[100];
    int i,j,k,delta;
    for(i=0;scanf("%c",&s)!=EOF;i++){
        a[i]=s;
    }
    for(j=0;j<=i;j++){ @@ [Loop goes out of bounds: 'a[i]' is the null terminator or EOF marker, but loop includes j=i which may access uninitialized or invalid data. Also, input reading doesn't stop at newline, causing potential infinite loop or incorrect processing.]
        if(a[j]!='-'){
            printf("%c",a[j]);
        }
        else if(a[j]=='-'){ @@ [Redundant condition: already checked a[j]!='-' above, so this 'else if' can be just 'else'. Not an error per se, but logic flaw when combined with boundary issues.]
            if((a[j-1]>='0'&&a[j+1]<='9'&&a[j-1]<a[j+1])||(a[j-1]>='a'&&a[j+1]<='z'&&a[j-1]<a[j+1])||(a[j-1]>='A'&&a[j+1]<='Z'&&a[j-1]<a[j+1])){ @@ [Incorrect range checks: e.g., 'a[j-1]>='0'' alone doesn't ensure it's a digit; should also check a[j-1]<='9'. Same for letters — missing lower/upper bound on one side in each condition. This causes false expansions like '0-Z' to be considered valid.]
                delta=a[j+1]-a[j-1];
                for(k=1;k<=delta-1;k++){ @@ [Off-by-one error: should print from a[j-1]+1 to a[j+1]-1 inclusive, which is correct here, BUT only if the condition was right. However, due to flawed condition above, this may run in invalid cases. Also, if j=0 or j=i-1, a[j-1] or a[j+1] accesses out-of-bound memory.]
                printf("%c",a[j-1]+k);
                }
                
                
            }
        }
    }
    return 0;
}