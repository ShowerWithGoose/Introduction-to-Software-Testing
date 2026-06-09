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
            if((('a'<=s[i-1]&&'z'>=s[i+1])||('A'<=s[i-1]&&'Z'>=s[i+1]))&&(s[i-1]<s[i+1])){ // @@ [Incorrect range checks: 'a'<=s[i-1]&&'z'>=s[i+1] mixes bounds for different characters; should check both ends are in same category (e.g., both lowercase), but this condition allows s[i-1]='a' and s[i+1]='Z', which violates requirement. Also missing digit case. Additionally, accesses s[i-1] when i=0 and s[i+1] when i=p-1 cause out-of-bounds reads.]
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
    printf("%s",t); // @@ [t is not null-terminated, leading to undefined behavior when printed with %s.]
    return 0;
}