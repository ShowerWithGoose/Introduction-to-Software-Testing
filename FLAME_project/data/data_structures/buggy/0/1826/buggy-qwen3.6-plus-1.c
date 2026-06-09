#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define eps 1e-8
int main(){
    int i=0;
    char ch;
    char a[256]={0};
    while((ch=getchar())!='\n'){
        a[i]=ch;
        i++;
    }
    printf("%c",a[0]);
    for(int j=1;j<i;j++){
        if('-'!=a[j]){
            printf("%c",a[j]);
        }
        if('-'==a[j]){
            if(((a[j-1]>='a'&&a[j-1]<='z')&&(a[j+1]>='a'&&a[j+1]<='z'))||((a[j-1]>='A'&&a[j-1]<='Z')&&(a[j+1]>='A'&&a[j+1]<='Z'))||((a[j-1]>='0'&&a[j-1]<='9')&&(a[j+1]>='0'&&a[j+1]<='9'))){
                if (a[j-1] < a[j+1]) { // @@ The problem requires expansion only when the character after '-' is greater than the one before. Without this check, ranges like 'u-B' (where types match in broad sense or logic fails) or invalid ranges might be processed incorrectly or cause issues if logic assumes ascending. More importantly, the previous if condition checks type matching but not order. If a[j-1] >= a[j+1], the loop `k < (a[j+1]-a[j-1])` will have a negative or zero bound, printing nothing, which is correct for "no expansion", but the requirement says "output unchanged" for non-expansion cases. However, the current code structure prints the '-' via the first `if` if it's not '-', wait. If `a[j] == '-'`, the first `if` is false. The second `if` is true. If types don't match, nothing happens inside the second if, so '-' is NOT printed. This is a bug. If types don't match, '-' should be printed.
            } else {
                printf("-"); // @@ If the characters around '-' do not meet the expansion criteria (either different types or not ascending), the '-' symbol itself should be output as part of the unchanged string. The current code fails to print '-' in these cases.
            }
                for(int k=1;k<(a[j+1]-a[j-1]);k++){
                    printf("%c",a[j-1]+k);
                }
            }
        }
    }
return 0;
}