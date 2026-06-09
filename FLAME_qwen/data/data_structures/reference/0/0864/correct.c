#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define ArrayNum(x) (sizeof(x)/sizeof(x[0]))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define ull unsigned long long
int main(){
	char s[500];
    gets(s);
    int len=strlen(s);
    for(int i=0;i<len;i++){
        if((s[i]=='-')&&(s[i+1]>s[i-1])){
            if(((s[i-1]>='a')&&(s[i-1]<='z')&&s[i+1]>='a'&&s[i+1]<='z')||(((s[i-1]>='A')&&(s[i-1]<='Z')&&s[i+1]>='A'&&s[i+1]<='Z'))||(((s[i-1]>='0')&&(s[i-1]<='9')&&s[i+1]>='0'&&s[i+1]<='9'))){
                for(int j=1;j<(s[i+1]-s[i-1]);j++){
                    printf("%c",s[i-1]+j);
                }
               
            }
            else printf("%c",s[i]);
        }
        else printf("%c",s[i]);
    }
}


