#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
char s[100];
gets(s); // @@ [gets is deprecated and may cause compilation error on modern compilers (removed in C11).]
int l=strlen(s);
int k=0;
for(int i=0;i<l;i++){ // @@ [Declaration of 'i' inside for loop requires C99 or later; may cause compilation error in C89.]
    if(s[i]=='-'&&i>=1&&i<=(l-2)){
        if(s[i-1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1]){
        k=s[i+1]-s[i-1];
        for(int j=1;j<k;j++){ // @@ [Declaration of 'j' inside for loop requires C99 or later; may cause compilation error in C89.]
            printf("%c",s[i-1]+j);
        }    
        }
        if(s[i-1]>='a'&&s[i+1]<='z'&&s[i-1]<s[i+1]){
        k=s[i+1]-s[i-1];
        for(int j=1;j<k;j++){ // @@ [Declaration of 'j' inside for loop requires C99 or later; may cause compilation error in C89.]
            printf("%c",s[i-1]+j);
        }    
        }
        if(s[i-1]>='A'&&s[i+1]<='Z'&&s[i-1]<s[i+1]){
        k=s[i+1]-s[i-1];
        for(int j=1;j<k;j++){ // @@ [Declaration of 'j' inside for loop requires C99 or later; may cause compilation error in C89.]
            printf("%c",s[i-1]+j);
        }    
        }
    }
    else{printf("%c",s[i]);
    }    
}
return 0;
}