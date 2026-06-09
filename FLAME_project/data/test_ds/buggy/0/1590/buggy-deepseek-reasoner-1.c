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
            if((('a'<=s[i-1]&&'z'>=s[i+1])||('A'<=s[i-1]&&'Z'>=s[i+1]))&&(s[i-1]<s[i+1])){ // @@ The condition incorrectly checks only one bound of each character and omits the digit range [0-9]. It should verify that both s[i-1] and s[i+1] are in the same valid range (lowercase, uppercase, or digit) and that s[i-1] < s[i+1].
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
    printf("%s",t);
    return 0;
}