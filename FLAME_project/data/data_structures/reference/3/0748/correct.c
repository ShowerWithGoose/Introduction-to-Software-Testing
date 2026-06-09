#include <stdio.h>
#include <string.h>
int main(){
   int i=0,num=0,k=0,length=0;
   char s[150];
   scanf("%s",&s);
   if(s[0]=='0'){
    for(i=2;;i++){
        if(s[i]=='0'){
            num++;
        }
        else if(s[i]!='0'){
            break;
        }
    }
    printf("%c",s[i]);
    if(strlen(s)==i+1){
        printf("e-%d",i-1);
    }
    else if(strlen(s)>i+1){
        printf(".");
        for(int j=i+1;j<strlen(s);j++){
            printf("%c",s[j]);
        }
        printf("e-%d",i-1);
    }
   }


   else if(s[0]>='1'&&s[0]<='9'){
    for(i=1;i<strlen(s);i++){
        if(s[i]=='.'){
            break;
        }
    }
    if(s[1]=='.'){
        for(int k=0;k<strlen(s);k++){
            printf("%c",s[k]);
        }
        printf("e0");
    }
    else{
        length=strlen(s);
        for(i=2;i<length;i++){
            if(s[i]=='.'){
                break;
            }
        }
        for(int m=i;m<length;m++){
                s[m]=s[m+1];
                }
        printf("%c",s[0]);
        printf(".");
        for(int p=1;p<length-1;p++){
            printf("%c",s[p]);
        }
        printf("e%d",i-1);
    }
   }
   return 0;
}

