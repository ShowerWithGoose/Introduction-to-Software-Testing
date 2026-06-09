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
    printf("%c",a[0]); // @@ This line incorrectly prints the first character unconditionally, but the reference program prints each character in a loop. If the first character is part of a valid expansion (e.g., "a-d"), it should be printed as part of the loop, not separately. Additionally, if the input is empty or has no characters, this may cause undefined behavior.
    for(int j=1;j<i;j++){
        if('-'!=a[j]){
            printf("%c",a[j]); // @@ This prints the character after the dash (e.g., 'd' in "a-d") but the reference program prints the expanded characters between a and d, then the loop continues and prints 'd' again, causing duplication. The logic should handle the dash case to print the expansion and skip printing the character after the dash.
        }
        if('-'==a[j]){
            if(((a[j-1]>='a'&&a[j-1]<='z')&&(a[j+1]>='a'&&a[j+1]<='z'))||((a[j-1]>='A'&&a[j-1]<='Z')&&(a[j+1]>='A'&&a[j+1]<='Z'))||((a[j-1]>='0'&&a[j-1]<='9')&&(a[j+1]>='0'&&a[j+1]<='9'))){
                for(int k=1;k<(a[j+1]-a[j-1]);k++){
                    printf("%c",a[j-1]+k);
                }
            }
        }
    }
return 0;
}