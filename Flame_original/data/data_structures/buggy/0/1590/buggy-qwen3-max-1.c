#include<stdio.h>
#include<string.h>
char s[10009],t[100009];
int main(){
    scanf("%s",s);
    int p=strlen(s);
    int cnt=0;
    int i,j;
    for(i=0;i<p;i++){
        if(s[i]=='-'){
            if((('a'<=s[i-1]&&'z'>=s[i+1])||('A'<=s[i-1]&&'Z'>=s[i+1]))&&(s[i-1]<s[i+1])){ // @@ [The condition incorrectly checks 'z'>=s[i+1] and 'Z'>=s[i+1] instead of ensuring both characters are in the same category (e.g., both lowercase, both uppercase, or both digits). Also, digit ranges are not handled at all. Additionally, it does not verify that s[i-1] is a letter of the same case as s[i+1], leading to invalid expansions like 'a-Z'.]
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
    printf("%s",t); // @@ [The output string t is not null-terminated, which may cause undefined behavior or garbage output when printed with %s.]
    return 0;
}