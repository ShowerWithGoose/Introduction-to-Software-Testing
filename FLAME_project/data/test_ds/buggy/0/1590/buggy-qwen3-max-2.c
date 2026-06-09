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
            if((('a'<=s[i-1]&&'z'>=s[i+1])||('A'<=s[i-1]&&'Z'>=s[i+1]))&&(s[i-1]<s[i+1])){ // @@ [The condition incorrectly checks if s[i-1] is >= 'a' and s[i+1] <= 'z', which mixes bounds of different characters. It should check that both s[i-1] and s[i+1] are in the same category (both lowercase, both uppercase, or both digits). Also, digit ranges are completely missing.]
                char l=s[i-1]+1,r=s[i+1]-1; // @@ [The expansion should go from s[i-1]+1 to s[i+1] inclusive, not s[i+1]-1. This causes the last character of the range to be omitted.]
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