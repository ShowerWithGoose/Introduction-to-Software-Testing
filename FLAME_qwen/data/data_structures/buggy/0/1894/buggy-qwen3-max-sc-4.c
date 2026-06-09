#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
char s[100];
gets(s); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; many compilers will issue a compilation error or warning. Use 'fgets' instead.]
int l=strlen(s);
int k=0;
for(int i=0;i<l;i++){
    if(s[i]=='-'&&i>=1&&i<=(l-2)){
        if(s[i-1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1]){ // @@ [Incorrect condition: should also check that s[i-1] <= '9' and s[i+1] >= '0' to ensure both are digits. As written, it allows cases like '-9' where s[i-1] could be a letter >= '0'.]
        k=s[i+1]-s[i-1];
        for(int j=1;j<k;j++){
            printf("%c",s[i-1]+j);
        }    
        }
        if(s[i-1]>='a'&&s[i+1]<='z'&&s[i-1]<s[i+1]){ // @@ [Incorrect condition: should also check that s[i-1] <= 'z' and s[i+1] >= 'a' to ensure both are lowercase letters. As written, it allows mixed-type cases like 'Z-a' to pass if Z >= 'a' (which it isn't), but more critically, fails to validate the lower bound of s[i+1] and upper bound of s[i-1].]
        k=s[i+1]-s[i-1];
        for(int j=1;j<k;j++){
            printf("%c",s[i-1]+j);
        }    
        }
        if(s[i-1]>='A'&&s[i+1]<='Z'&&s[i-1]<s[i+1]){ // @@ [Incorrect condition: should also check that s[i-1] <= 'Z' and s[i+1] >= 'A' to ensure both are uppercase letters. As written, it may incorrectly process non-uppercase characters.]
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