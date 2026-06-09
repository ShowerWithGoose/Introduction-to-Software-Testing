#include<stdio.h>
#include<string.h>
char s[10009],t[100009];
int main(){
    scanf("%s",s);
    int p=strlen(s);
    int cnt=0;
    int i,j;
    for(i=0;i<p;i++){
        if(s[i]=='-'){ // @@ Missing bounds check for i==0 and i==p-1. Accessing s[i-1] when i=0 or s[i+1] when i=p-1 causes out-of-bounds memory access.
            if((('a'<=s[i-1]&&'z'>=s[i+1])||('A'<=s[i-1]&&'Z'>=s[i+1]))&&(s[i-1]<s[i+1])){ // @@ Logical error: range validation is incorrect. It should verify both s[i-1] and s[i+1] are within the same valid range (e.g., s[i-1]>='a' && s[i-1]<='z' && s[i+1]>='a' && s[i+1]<='z'). Also misses the required digit range [0-9].
                char l=s[i-1]+1,r=s[i+1]-1;
                for(;l<=r;l++){
                    t[cnt++]=l;
                    //printf("%d\n",i);    
                }
                continue;
            }
        }
        t[cnt++]=s[i];
        //printf("%d\n",i);
    }
    printf("%s",t); // @@ Array t is not null-terminated, which may cause printf to output garbage characters. Should add t[cnt]='\0'; before printing.
    return 0;
}