#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
char s[100];
gets(s); // @@ [The function 'gets' is unsafe and has been removed from the C standard library; it may cause compilation errors or warnings in modern compilers. Use 'fgets' instead.]
int l=strlen(s);
int k=0;
for(int i=0;i<l;i++){
    if(s[i]=='-'&&i>=1&&i<=(l-2)){
        if(s[i-1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1]){ // @@ [Incorrect condition: should also check that s[i-1] <= '9' to ensure it's a digit. As written, it allows cases like '-0' where s[i-1] could be a letter >= '0'.]
        k=s[i+1]-s[i-1];
        for(int j=1;j<k;j++){
            printf("%c",s[i-1]+j);
        }    
        }
        if(s[i-1]>='a'&&s[i+1]<='z'&&s[i-1]<s[i+1]){ // @@ [Incorrect condition: should also check that s[i+1] >= 'a' to ensure both are lowercase letters. As written, it allows cases like 'a-Z' if Z <= 'z' (which it is), but Z is uppercase.]
        k=s[i+1]-s[i-1];
        for(int j=1;j<k;j++){
            printf("%c",s[i-1]+j);
        }    
        }
        if(s[i-1]>='A'&&s[i+1]<='Z'&&s[i-1]<s[i+1]){ // @@ [Incorrect condition: should also check that s[i+1] >= 'A' to ensure both are uppercase letters. As written, it allows cases like 'A-z' if z <= 'Z' (which it isn't), but more critically, mixed cases may pass due to ASCII ordering.]
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