#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
char s[100];
gets(s);
int l=strlen(s);
int k=0;
for(int i=0;i<l;i++){
    if(s[i]=='-'&&i>=1&&i<=(l-2)){ // @@ [When no expansion condition is met, the '-' is not printed, causing characters to be omitted incorrectly.]
        if(s[i-1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1]){ // @@ [Condition should check both characters are digits (s[i-1]>='0'&&s[i-1]<='9' and s[i+1]>='0'&&s[i+1]<='9'), not just one bound each.]
        k=s[i+1]-s[i-1];
        for(int j=1;j<k;j++){
            printf("%c",s[i-1]+j);
        }    
        }
        if(s[i-1]>='a'&&s[i+1]<='z'&&s[i-1]<s[i+1]){ // @@ [Condition should check both characters are lowercase letters (s[i-1]>='a'&&s[i-1]<='z' and s[i+1]>='a'&&s[i+1]<='z').]
        k=s[i+1]-s[i-1];
        for(int j=1;j<k;j++){
            printf("%c",s[i-1]+j);
        }    
        }
        if(s[i-1]>='A'&&s[i+1]<='Z'&&s[i-1]<s[i+1]){ // @@ [Condition should check both characters are uppercase letters (s[i-1]>='A'&&s[i-1]<='Z' and s[i+1]>='A'&&s[i+1]<='Z').]
        k=s[i+1]-s[i-1];
        for(int j=1;j<k;j++){
            printf("%c",s[i-1]+j);
        }    
        }
    } // @@ [Missing else clause to print the '-' when no expansion occurs, leading to omission of the hyphen.]
    else{printf("%c",s[i]);
    }    
}
return 0;
}