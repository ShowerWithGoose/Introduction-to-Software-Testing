#include<stdio.h>
#include<string.h>
char ch[105];
int main()
{
    int i,e,first=0,end=0,point=0;
    gets(ch);
    while(ch[point]!='.')point++;
    while(ch[first]=='0'||ch[first]=='.')first++;
    while(ch[end]!='\0')end++;
    e=point-first;
    if(first==0)e--;
    if((end-first)==1)
        printf("%ce%d",ch[first],e);
    else{
        for(i=first;i<=end-1;i++){
            if(ch[i]>='0'&&ch[i]<='9')printf("%c",ch[i]);
            if(i==first)printf(".");
        }
        printf("e%d",e);
    }
    return 0;
}

