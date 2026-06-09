#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 char s[100];
int main (){
int t;   
    gets(s);
    int l;l=strlen(s);
    for(int i=0;i<100;i++){ t=100;
        if(s[i]=='.'){t=i;break;}
       
    }
if(t==1&&s[0]!='0'){//1.23456
    for(int i=0;i<l;i++)printf("%c",s[i]);printf("e0");}
else if(t==1&&s[0]=='0'){
    if(s[l-2]=='0'||s[l-2]=='.'){int i=1;//0.0001 over
    for(int k=1;k<100;k++){
        if (s[1+k]=='0')i++;if(s[1+k]!='0')break;
    }printf("%ce-%d",s[l-1],l-2);
    }
    else{//0.1234
    int i=1;
    for(int k=1;k<100;k++){
        if (s[1+k]=='0')i++;if(s[1+k]!='0')break;
    }
    printf("%c.",s[1+i]);for(int j=1;j<l-i-1;j++)printf("%c",s[1+i+j]);
    printf("e-%d",i);}}
//else if(t=100){printf("%c.",s[0]);for(int j=1;j<=l-1;j++)printf("%c",s[j]);printf("e%d",l-1);}
else if(t!=1){//1234.5678
    printf("%c.",s[0]);
    for(int j=1;j<=t-1;j++)printf("%c",s[j]);
    for(int j=t+1;j<=l-1;j++)printf("%c",s[j]);
    printf("e%d",t-1);}
    system ("pause");
    return 0;
    }


