#include <stdio.h>
#include <string.h>
#include <ctype.h>

char ch[1000+7];
int i,len,flag,num_loc,dot_loc;

int main(){
    gets(ch);
    len=strlen(ch);
    while(ch[dot_loc]!='.') dot_loc++;  //找到点的位置
    while(ch[num_loc]<='0' || ch[num_loc]>'9') num_loc++;  //找到第一个非零数字的位置
    if(num_loc==len-1) printf("%c",ch[num_loc]);
    else printf("%c.",ch[num_loc]);  //输出这个数字+.
    for(i=num_loc+1;i<len;i++) if(isalnum(ch[i])) printf("%c",ch[i]);
    if(dot_loc-num_loc>0) printf("e%d",dot_loc-num_loc-1);
    else printf("e%d",dot_loc-num_loc);
    return 0;
}
