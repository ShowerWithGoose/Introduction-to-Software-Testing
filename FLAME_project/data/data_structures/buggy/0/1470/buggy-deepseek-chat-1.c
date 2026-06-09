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
        if(a[i]=='-'&&a[i-1]<a[i+1]){ // @@ The condition a[i-1] < a[i+1] is checked before verifying that a[i-1] and a[i+1] are valid characters. When i=0, a[i-1] accesses out-of-bounds memory, and when '-' is at the end, a[i+1] is out-of-bounds. Also, the comparison uses ASCII values without ensuring both sides are alphanumeric, which can cause incorrect expansion for mixed types like 'u' and 'B' (where 'u' < 'B' in ASCII, but they are different types and should not be expanded).
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
            printf("%c",a[i]);
        }
    }
    return 0;
}