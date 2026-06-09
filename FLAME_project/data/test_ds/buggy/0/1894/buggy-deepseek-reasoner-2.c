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
        if(s[i-1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1]){ // @@ [Incomplete condition: should also check s[i-1]<='9' and s[i+1]>='0' to ensure both are digits]
        k=s[i+1]-s[i-1];
        for(int j=1;j<k;j++){
            printf("%c",s[i-1]+j);
        }    
        }
        if(s[i-1]>='a'&&s[i+1]<='z'&&s[i-1]<s[i+1]){ // @@ [Incomplete condition: should also check s[i-1]<='z' and s[i+1]>='a' to ensure both are lowercase letters]
        k=s[i+1]-s[i-1];
        for(int j=1;j<k;j++){
            printf("%c",s[i-1]+j);
        }    
        }
        if(s[i-1]>='A'&&s[i+1]<='Z'&&s[i-1]<s[i+1]){ // @@ [Incomplete condition: should also check s[i-1]<='Z' and s[i+1]>='A' to ensure both are uppercase letters]
        k=s[i+1]-s[i-1];
        for(int j=1;j<k;j++){
            printf("%c",s[i-1]+j);
        }    
        }
    } // @@ [Missing handling: when dash is present but expansion conditions not met, the dash character should be printed; currently it is omitted]
    else{printf("%c",s[i]);
    }    
}
return 0;
}