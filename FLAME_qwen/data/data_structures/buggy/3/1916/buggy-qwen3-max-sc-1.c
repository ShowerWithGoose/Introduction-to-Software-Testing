//JmmyWng
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define MAX 109
int main(){
    char ori[MAX],ans[MAX];
    gets(ori); // @@ [Use of unsafe function 'gets' which may cause buffer overflow; also, 'gets' was removed in C11 standard and may not be available, leading to compilation error]
    int cnt,cntn0=0; // @@ [Variable 'cnt' is used uninitialized in multiple places, leading to undefined behavior]
    int i,j;
    int lng=strlen(ori);
    if(ori[1]=='.'&&ori[0]>'0'&&ori[0]<='9'){  //already
        printf("%se0",ori);
    }
    else if(ori[1]=='.'&&ori[0]=='0'){   //0.~
        for(i=0;i<lng;i++){
            if(ori[i]=='0')cnt++;   //count the 0 before the number // @@ [Using uninitialized 'cnt'; should initialize to 0 before loop]
            else if(ori[i]!='0'&&ori[i]!='.'&&cntn0==0){
                cntn0++;
                printf("%c",ori[i]);
                if(i<lng-1)printf(".");
            }
            else if(cntn0!=0){
                printf("%c",ori[i]);
            }
        }
        printf("e-%d",cnt);
    }
    else{
        i=1;
        while(ori[i]!='.'){ // @@ [If input has no decimal point (e.g., "123"), this loop runs past string end causing undefined behavior]
            cnt++; // @@ [Again, 'cnt' is uninitialized here]
            i++;
        }
        i=0;
        printf("%c.",ori[0]);
        for(i=1;i<lng;i++){
            if(ori[i]=='.')continue;
            printf("%c",ori[i]);
        }
        printf("e%d",cnt);
    }
    return 0;
}