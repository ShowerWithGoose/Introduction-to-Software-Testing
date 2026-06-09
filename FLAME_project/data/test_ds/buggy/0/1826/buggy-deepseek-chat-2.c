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
        if('-'==a[j]){ // @@ This should be else if to avoid printing the '-' character when it is not expanded. Currently, when '-' is not expanded, it is not printed because the first if fails, but the second if also fails, so nothing is printed for that '-'. However, the problem requires that for non-expandable cases, the '-' should be output unchanged. The logic here only prints '-' if it is not a '-' (impossible) or if it is a '-' and the expansion condition fails, it is skipped entirely. The correct approach is to print '-' in the else branch of the expansion condition.
            if(((a[j-1]>='a'&&a[j-1]<='z')&&(a[j+1]>='a'&&a[j+1]<='z'))||((a[j-1]>='A'&&a[j-1]<='Z')&&(a[j+1]>='A'&&a[j+1]<='Z'))||((a[j-1]>='0'&&a[j-1]<='9')&&(a[j+1]>='0'&&a[j+1]<='9'))){
                for(int k=1;k<(a[j+1]-a[j-1]);k++){
                    printf("%c",a[j-1]+k);
                }
            }
        }
    }
return 0;
}