#include<stdio.h>
#include<string.h>
int main(){
    char s[301],j;
    int len,i;
    fgets(s,300,stdin);
    len=strlen(s);
    for(i=0;i<len;i++){
        if(i&&i<len-1&&s[i]=='-'){
            if('a'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<='z'){
                j=s[i-1],i++;
                while((++j)<=s[i])putchar(j);
                continue;
            }
            if('A'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<='Z'){
                j=s[i-1],i++;
                while((++j)<=s[i])putchar(j);
                continue;
            }
            if('0'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<='9'){
                j=s[i-1],i++;
                while((++j)<=s[i])putchar(j);
                continue;
            }
        }
        printf("%c",s[i]);
    }
    return 0;
}
