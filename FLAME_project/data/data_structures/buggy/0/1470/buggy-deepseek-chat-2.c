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
        if(a[i]=='-'&&a[i-1]<a[i+1]){ // @@ When i=0, a[i-1] accesses out-of-bounds memory; also, the condition should check that both sides are valid characters before comparing.
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
            printf("%c",a[i]); // @@ When a[i] is '-' but expansion conditions are not met, this prints the '-' character, but the expected behavior is to print '-' only once; however, the main issue is that when expansion occurs, the '-' itself is not printed, but the loop also prints the character after the expansion (a[i+1]) later, causing duplication. For example, in "a-u", after expanding a-u, the loop prints 'u' again when i reaches the position of 'u'.
        }
    }
    return 0;
}