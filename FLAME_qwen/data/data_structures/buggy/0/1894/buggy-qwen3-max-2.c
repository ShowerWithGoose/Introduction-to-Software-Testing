#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
char s[100];
gets(s); // @@ [Using gets() is unsafe and deprecated; it can cause buffer overflow. Additionally, some compilers may not support it, leading to compilation errors.]
int l=strlen(s);
int k=0;
for(int i=0;i<l;i++){
    if(s[i]=='-'&&i>=1&&i<=(l-2)){
        if(s[i-1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1]){ // @@ [Incorrect condition: should also ensure s[i-1] <= '9' and s[i+1] >= '0' to confirm both are digits. As written, e.g., 'a'-'9' could pass the first part if s[i-1]='a' (>= '0') and s[i+1]='0' (<= '9'), which is invalid.]
        k=s[i+1]-s[i-1];
        for(int j=1;j<k;j++){
            printf("%c",s[i-1]+j);
        }    
        }
        if(s[i-1]>='a'&&s[i+1]<='z'&&s[i-1]<s[i+1]){ // @@ [Incorrect condition: should also ensure s[i-1] <= 'z' and s[i+1] >= 'a'. Without that, mixed cases like 'Z'-'b' might incorrectly pass parts of the condition.]
        k=s[i+1]-s[i-1];
        for(int j=1;j<k;j++){
            printf("%c",s[i-1]+j);
        }    
        }
        if(s[i-1]>='A'&&s[i+1]<='Z'&&s[i-1]<s[i+1]){ // @@ [Incorrect condition: should also ensure s[i-1] <= 'Z' and s[i+1] >= 'A'. Otherwise, non-uppercase characters might satisfy one side of the condition.]
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