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
        if(s[i-1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1]){ // @@ [Incorrect range check: should be s[i-1]>='0'&&s[i-1]<='9' && s[i+1]>='0'&&s[i+1]<='9'; current condition may match non-digits like ':' that are >= '0' and <= '9']
        k=s[i+1]-s[i-1];
        for(int j=1;j<k;j++){
            printf("%c",s[i-1]+j);
        }    
        }
        if(s[i-1]>='a'&&s[i+1]<='z'&&s[i-1]<s[i+1]){ // @@ [Incorrect range check: should be s[i-1]>='a'&&s[i-1]<='z' && s[i+1]>='a'&&s[i+1]<='z'; current condition may match non-lowercase characters with ASCII >= 'a' and next <= 'z']
        k=s[i+1]-s[i-1];
        for(int j=1;j<k;j++){
            printf("%c",s[i-1]+j);
        }    
        }
        if(s[i-1]>='A'&&s[i+1]<='Z'&&s[i-1]<s[i+1]){ // @@ [Incorrect range check: should be s[i-1]>='A'&&s[i-1]<='Z' && s[i+1]>='A'&&s[i+1]<='Z'; current condition may match non-uppercase characters with ASCII >= 'A' and next <= 'Z']
        k=s[i+1]-s[i-1];
        for(int j=1;j<k;j++){
            printf("%c",s[i-1]+j);
        }    
        }
    }
    else{printf("%c",s[i]); // @@ [When s[i]=='-' but expansion conditions are not met, this else does not execute, so the dash is not printed. Should print the dash unchanged in that case.]
    }    
}
return 0;
}