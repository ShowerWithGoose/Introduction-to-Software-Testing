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
        if('-'==a[j]){ // @@ This should be 'else if' to avoid printing the '-' character twice when it is not expanded. Currently, when '-' is not expanded, the first if prints it, and then this if also executes but does nothing, which is correct, but when '-' is expanded, the first if does not print it, and this if prints the expansion, which is correct. However, the logic is flawed because if '-' is not expanded, the first if prints it, and then this if also checks and does nothing, which is fine, but the condition for expansion should also check that a[j+1] > a[j-1] to match the problem requirements. The current code does not check this, so it will attempt expansion even when the second character is less than or equal to the first, leading to incorrect output (e.g., for "d-a", it would try to print characters from 'd' to 'a' in reverse, but the loop condition k < (a[j+1]-a[j-1]) would be negative, causing no output, but the '-' would not be printed, which is wrong). Additionally, the code does not handle the case where '-' is at the beginning or end of the string, which could cause out-of-bounds access.
            if(((a[j-1]>='a'&&a[j-1]<='z')&&(a[j+1]>='a'&&a[j+1]<='z'))||((a[j-1]>='A'&&a[j-1]<='Z')&&(a[j+1]>='A'&&a[j+1]<='Z'))||((a[j-1]>='0'&&a[j-1]<='9')&&(a[j+1]>='0'&&a[j+1]<='9'))){
                for(int k=1;k<(a[j+1]-a[j-1]);k++){
                    printf("%c",a[j-1]+k);
                }
            }
        }
    }
return 0;
}