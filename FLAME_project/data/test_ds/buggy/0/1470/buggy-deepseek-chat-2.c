#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char a[1010];
    int i,j;
    
    gets(a);
    
    for(i=0;i<strlen(a);i++){
        if(a[i]=='-'&&a[i-1]<a[i+1]){ // @@ When i=0, a[i-1] accesses out-of-bounds memory; also, when '-' is at the end, a[i+1] is out-of-bounds.
            if((a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>='0'&&a[i+1]<='9')||(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[i+1]<='Z')||(a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z')){
                for(j=1;j<=a[i+1]-a[i-1];j++){
                    printf("%c",a[i-1]+j);
                }
            }
            else{
                printf("-");
            }
        }
        else{
            printf("%c",a[i]); // @@ When a[i] is '-' and expansion is performed, the '-' itself should not be printed, but here it is printed in the else branch only when the condition fails. However, when expansion is done, the '-' is not printed, which is correct. But the bug is that when expansion is performed, the character after '-' (a[i+1]) is also printed later in the loop, causing duplication. For example, in "a-u", after expanding 'a' to 't', the loop will later print 'u' again, resulting in double 'u'.
        }
    }
    return 0;
}