#include<stdio.h>
#include<string.h>
char s[10010]={'\0'},b[100010]={'\0'};
int main(){
    int i,j=0;
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; it may cause buffer overflow and is removed in C11 standard, leading to compilation error on modern compilers]
    for(i=0;i<strlen(s);i++,j++){
        b[j]=s[i];
        if(s[i]=='-'&&s[i+1]>s[i-1]){
            if((s[i-1]-'0'<=9&&s[i-1]-'0'>=0&&s[i+1]-'0'>=0&&s[i+1]-'\0'<=9)||(s[i-1]-'A'<=25&&s[i-1]-'A'>=0&&s[i+1]-'A'>=0&&s[i+1]-'A'<=25)||(s[i-1]-'a'<=25&&s[i-1]-'a'>=0&&s[i+1]-'a'>=0&&s[i+1]-'a'<=25)){ // @@ [Incorrect digit range check: 's[i+1]-'\0'<=9' should be 's[i+1]<='9'; also, subtracting base char like '0', 'A', 'a' can yield negative values, so condition logic is flawed]
                for(int k=1;k<s[i+1]-s[i-1];k++){ // @@ [Variable 'k' declared inside for-loop initializer may not be supported in older C standards (e.g., C89), causing compilation error if compiler defaults to such standard]
                    b[j]=s[i-1]+k;
                    j++;
                }
                b[j]=s[i+1];
                i++;
            }    
            
        }
    }
    puts(b);
    return 0;
}