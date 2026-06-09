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
        if(s[i-1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1]){ // @@ The condition should check that both characters are digits, i.e., s[i-1]>='0' && s[i-1]<='9' && s[i+1]>='0' && s[i+1]<='9'. Using s[i+1]<='9' alone is insufficient because it doesn't ensure s[i+1] is a digit (e.g., 'B' <= '9' is false, but '0' <= '9' is true, but the condition should also check lower bound).
        k=s[i+1]-s[i-1];
        for(int j=1;j<k;j++){
            printf("%c",s[i-1]+j);
        }    
        }
        if(s[i-1]>='a'&&s[i+1]<='z'&&s[i-1]<s[i+1]){ // @@ The condition should check that both characters are lowercase letters, i.e., s[i-1]>='a' && s[i-1]<='z' && s[i+1]>='a' && s[i+1]<='z'. Using s[i+1]<='z' alone is insufficient because it doesn't ensure s[i+1] is a lowercase letter (e.g., 'Z' <= 'z' is true, but 'Z' is uppercase).
        k=s[i+1]-s[i-1];
        for(int j=1;j<k;j++){
            printf("%c",s[i-1]+j);
        }    
        }
        if(s[i-1]>='A'&&s[i+1]<='Z'&&s[i-1]<s[i+1]){ // @@ The condition should check that both characters are uppercase letters, i.e., s[i-1]>='A' && s[i-1]<='Z' && s[i+1]>='A' && s[i+1]<='Z'. Using s[i+1]<='Z' alone is insufficient because it doesn't ensure s[i+1] is an uppercase letter (e.g., 'a' <= 'Z' is true, but 'a' is lowercase).
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