#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define LL long long
#define DB double
#define FOR(X,Y,Z)  for(int X = Y;X<Z;X++)  
char a[100];
int main(){
    //freopen(".in","r",stdin);
    gets(a);
    for(int i = 0;i < strlen(a);i++){
        if(a[i]=='-'){
            if(isdigit(a[i-1])&&isdigit(a[i+1])&&(a[i-1]<a[i+1]) ){
                for(int j = a[i-1]+1;j < a[i+1];j++)
                putchar(j);
            }
            else if(isupper(a[i-1])&&isupper(a[i+1])&&(a[i-1]<a[i+1]) ){
                for(int j = a[i-1]+1;j < a[i+1];j++)
                putchar(j);
            }
            else if(islower(a[i-1])&&islower(a[i+1])&&(a[i-1]<a[i+1]) ){
                for(int j = a[i-1]+1;j < a[i+1];j++)
                putchar(j);
            }
            else
            putchar(a[i]);
        }
        else
        putchar(a[i]);
    }

    return 0;
}



