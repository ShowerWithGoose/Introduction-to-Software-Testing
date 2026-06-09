#include <stdio.h>
#include<string.h>
char s[1000000];
int jdg(int i){
    return s[i-1]>='a'&&s[i+1]<='z'&&s[i-1]<s[i+1] || s[i-1]>='A'&&s[i+1]<='Z'&&s[i-1]<s[i+1] || s[i-1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1];
}
int main(){
    scanf("%s",s);
    int sl=strlen(s);
    for(int i=0;i<sl;++i){
        if(s[i]=='-'){
            if(jdg(i)){
                for(int j=s[i-1]+1;j<s[i+1];++j)printf("%c",j);
            }else printf("-");
        }else printf("%c",s[i]);
    }
}
