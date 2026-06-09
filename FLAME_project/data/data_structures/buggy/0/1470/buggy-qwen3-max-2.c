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
        if(a[i]=='-'&&a[i-1]<a[i+1]){ // @@ [This condition accesses a[i-1] when i=0, leading to out-of-bounds read (undefined behavior). Also, it doesn't check that both sides are valid and of the same category before comparing.]
            if((a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>='0'&&a[i+1]<='9')||(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[i+1]<='Z')||(a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z')){
                for(j=1;j<=a[i+1]-a[i-1];j++){ // @@ [This loop prints from a[i-1]+1 up to and including a[i+1], which duplicates the next character (e.g., 'u' in "a-u" becomes "abcdefghijklmnopqrstu", but then the next character 'u' is printed again in the else clause, causing duplication). The expansion should only print characters between the two endpoints, not including the endpoint itself, because the endpoint will be printed when the loop reaches it normally.]
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