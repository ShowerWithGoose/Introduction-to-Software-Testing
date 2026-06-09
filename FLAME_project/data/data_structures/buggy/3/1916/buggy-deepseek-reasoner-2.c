//JmmyWng
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define MAX 109
int main(){
    char ori[MAX],ans[MAX];
    gets(ori);
    int cnt,cntn0=0; // @@ [cnt is declared but not initialized; it is later used in case 2 and case 3 without being set, leading to undefined behavior]
    int i,j;
    int lng=strlen(ori);
    if(ori[1]=='.'&&ori[0]>'0'&&ori[0]<='9'){  //already
        printf("%se0",ori);
    }
    else if(ori[1]=='.'&&ori[0]=='0'){   //0.~
        for(i=0;i<lng;i++){
            if(ori[i]=='0')cnt++;   //count the 0 before the number
            else if(ori[i]!='0'&&ori[i]!='.'&&cntn0==0){
                cntn0++;
                printf("%c",ori[i]);
                if(i<lng-1)printf(".");
            }
            else if(cntn0!=0){
                printf("%c",ori[i]);
            }
        }
        printf("e-%d",cnt); // @@ [cnt is uninitialized; this produces garbage output like -49153]
    }
    else{
        i=1;
        while(ori[i]!='.'){
            cnt++; // @@ [cnt is used uninitialized here as well; if this branch is taken, the exponent will be garbage]
            i++;
        }
        i=0;
        printf("%c.",ori[0]);
        for(i=1;i<lng;i++){
            if(ori[i]=='.')continue;
            printf("%c",ori[i]);
        }
        printf("e%d",cnt); // @@ [cnt is still uninitialized from the while loop; same issue]
    }
    return 0;
}