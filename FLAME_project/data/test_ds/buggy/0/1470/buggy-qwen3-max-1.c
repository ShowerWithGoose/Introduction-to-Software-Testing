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
        if(a[i]=='-'&&a[i-1]<a[i+1]){ // @@ [When i=0, a[i-1] accesses a[-1], which is invalid memory; also, when '-' is at the end, a[i+1] may be '\0', leading to incorrect comparisons or undefined behavior. Additionally, the condition does not ensure both sides are of the same character type before comparing their values.]
            if((a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>='0'&&a[i+1]<='9')||(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[i+1]<='Z')||(a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z')){
                for(j=1;j<=a[i+1]-a[i-1];j++){ // @@ [This loop prints from a[i-1]+1 up to and including a[i+1], but the problem requires expanding "a-d" to "abcd", meaning it should include a[i-1] and a[i+1] as well. However, in the current logic, the original characters are printed separately: a[i-1] is printed in the else clause when i was at i-1, and a[i+1] will be printed when i reaches i+1. But because the '-' is replaced by the full expansion including the endpoints, this causes duplication. Specifically, the loop should run from j = a[i-1]+1 to j < a[i+1], not <= a[i+1]-a[i-1] steps which includes the endpoint again. In test case "a-u", this causes 'u' to be printed twice: once by the expansion loop (as the last char) and once when i reaches the position of 'u'. Similarly for "B-F", 'F' is printed twice.]
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