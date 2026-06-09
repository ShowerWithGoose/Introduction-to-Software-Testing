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
            if((('a'<=s[i-1]&&'z'>=s[i+1])||('A'<=s[i-1]&&'Z'>=s[i+1]))&&(s[i-1]<s[i+1])){ // @@ [The condition incorrectly checks if s[i-1] is a lowercase letter AND s[i+1] is a lowercase letter using 'a'<=s[i-1] && 'z'>=s[i+1], which mixes bounds of different characters. It should check both characters belong to the same category: e.g., ('a'<=s[i-1] && s[i-1]<='z' && 'a'<=s[i+1] && s[i+1]<='z'). Also, digits [0-9] are completely missing from the condition.]
                char l=s[i-1]+1,r=s[i+1]-1; // @@ [The expansion should include s[i+1], but r is set to s[i+1]-1, so the last character is omitted. It should be r = s[i+1].]
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