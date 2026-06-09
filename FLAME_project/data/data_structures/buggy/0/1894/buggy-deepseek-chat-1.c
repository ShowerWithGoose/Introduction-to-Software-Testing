#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
char s[100];
gets(s);
int l=strlen(s);
int k=0;
for(int i=0;i<l;i++){
    if(s[i]=='-'&&i>=1&&i<=(l-2)){
        if(s[i-1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1]){ // @@ The condition should check that both characters are digits, i.e., s[i-1]>='0' && s[i-1]<='9' && s[i+1]>='0' && s[i+1]<='9'. The current condition only checks the lower bound of s[i-1] and the upper bound of s[i+1], which incorrectly allows cases like '0-b' or '4-B' to be expanded.
        k=s[i+1]-s[i-1];
        for(int j=1;j<k;j++){
            printf("%c",s[i-1]+j);
        }    
        }
        if(s[i-1]>='a'&&s[i+1]<='z'&&s[i-1]<s[i+1]){ // @@ The condition should check that both characters are lowercase letters, i.e., s[i-1]>='a' && s[i-1]<='z' && s[i+1]>='a' && s[i+1]<='z'. The current condition only checks the lower bound of s[i-1] and the upper bound of s[i+1], which incorrectly allows cases like 'a-R' to be expanded.
        k=s[i+1]-s[i-1];
        for(int j=1;j<k;j++){
            printf("%c",s[i-1]+j);
        }    
        }
        if(s[i-1]>='A'&&s[i+1]<='Z'&&s[i-1]<s[i+1]){ // @@ The condition should check that both characters are uppercase letters, i.e., s[i-1]>='A' && s[i-1]<='Z' && s[i+1]>='A' && s[i+1]<='Z'. The current condition only checks the lower bound of s[i-1] and the upper bound of s[i+1], which incorrectly allows cases like 'D-e' to be expanded.
        k=s[i+1]-s[i-1];
        for(int j=1;j<k;j++){
            printf("%c",s[i-1]+j);
        }    
        }
    }
    else{printf("%c",s[i]);
    }    
}
return 0;
}