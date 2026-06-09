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
        if(a[i]=='-'&&a[i-1]<a[i+1]){ // @@ When i=0, a[i-1] accesses index -1, causing undefined behavior. Also, the condition should check that both sides are valid characters before comparing.
            if((a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>='0'&&a[i+1]<='9')||(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[i+1]<='Z')||(a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z')){
                for(j=1;j<=a[i+1]-a[i-1];j++){ // @@ The loop should start from j=1 and go to j < (a[i+1]-a[i-1]), not <=, to avoid printing one extra character. For example, "a-d" should print "bcd" (3 characters), but a[i+1]-a[i-1] = 3, so j=1,2,3 prints 3 characters correctly, but the original reference uses j<c, so this is actually correct. However, the reference program prints the characters between, so j should go from 1 to c-1, not c. Here c = a[i+1]-a[i-1], so j < c is correct, not j <= c.
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