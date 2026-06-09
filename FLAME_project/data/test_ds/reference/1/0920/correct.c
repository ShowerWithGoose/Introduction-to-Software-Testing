#include<stdio.h>
#include<string.h>
char ch[150000];
int main()
{
    scanf("%s",ch);
    int i,j,k,len=strlen(ch);
    for(i=0; i<len; i++){
        if(ch[i]=='-'){
            if (ch[i-1]>='0'&&ch[i+1]<='9'&&ch[i-1]<ch[i+1]){
                for(k=ch[i+1]-ch[i-1],j=ch[i-1]+1; k>1; k--,j++){
                    printf("%c",j);
                }
            }
            else if (ch[i-1]>='a'&&ch[i+1]<='z'&&ch[i-1]<ch[i+1]){
                for(k=ch[i+1]-ch[i-1],j=ch[i-1]+1; k>1; k--,j++){
                    printf("%c",j);
                }
            }
            else if (ch[i-1]>='A'&&ch[i+1]<='Z'&&ch[i-1]<ch[i+1]){
                for(k=ch[i+1]-ch[i-1],j=ch[i-1]+1; k>1; k--,j++){
                    printf("%c",j);
                }
            }
            else printf("%c",ch[i]);
        }
        else printf("%c",ch[i]);
    }
}


