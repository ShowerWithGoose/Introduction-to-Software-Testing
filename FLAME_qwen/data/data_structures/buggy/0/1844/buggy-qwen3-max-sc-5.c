#include<stdio.h>
int main()
{
    char s,a[100];
    int i,j,k,delta;
    for(i=0;scanf("%c",&s)!=EOF;i++){
        a[i]=s;
    }@@ // The loop does not terminate input with a null terminator '\0', causing undefined behavior in subsequent loops that assume string termination.
    for(j=0;j<=i;j++){@@ // Loop condition should be j < i, not j <= i, because valid indices are 0 to i-1; accessing a[i] reads uninitialized memory (or EOF character), and a[j+1] may go out of bounds.
        if(a[j]!='-'){
            printf("%c",a[j]);
        }
        else if(a[j]=='-'){
            if((a[j-1]>='0'&&a[j+1]<='9'&&a[j-1]<a[j+1])||(a[j-1]>='a'&&a[j+1]<='z'&&a[j-1]<a[j+1])||(a[j-1]>='A'&&a[j+1]<='Z'&&a[j-1]<a[j+1])){@@ // Condition logic is incorrect: it checks a[j-1] >= '0' but a[j+1] <= '9' without verifying a[j+1] >= '0'; similarly for letters. This allows invalid cross-type cases like '0-z' to pass.
                delta=a[j+1]-a[j-1];
                for(k=1;k<=delta-1;k++){@@ // Should print from a[j-1]+1 to a[j+1]-1 inclusive, which is correct, but only if the surrounding characters are valid and same type — however due to flawed condition above, this may run on invalid input.
                printf("%c",a[j-1]+k);
                }
                
                
            }
        }
    }
    return 0;
}