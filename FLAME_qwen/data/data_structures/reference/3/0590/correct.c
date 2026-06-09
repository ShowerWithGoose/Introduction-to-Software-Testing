#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
char s[110];
char* p=NULL;
int l=0,k=0,m=0;
scanf("%s",s);
p=strchr(s,'.');
l=strlen(s);
if(p==NULL)
    puts(s);
else{
    if(s[0]=='-'){
        k++;printf("%c",s[0]);
    }
if(p==s+1+k+m&&*(p-1+k+m)=='0'){
     while(*(p+1+k+m)=='0'){
        m++;
    }
    printf("%c",*(p+1+k+m));
    if(p+2+k+m!=s+l){printf(".%s",p+2+k+m);}

    printf("e-%d",m+1);
    return 0;
}
else if (p==s+1+k+m&&*(p-1+k+m)!='0'){
    printf("%se0",s);
}
else if(p>s+1+k+m){
    while(p>s+1+k+m){
        m++;
    }printf("%c.",*(s+k));
while(s+k+1<=s+l-1){if(*(s+k+1)!='.'){
    printf("%c",*(s+k+1));
}
 k++;
}printf("e%d",m);
}

}




return 0;}


