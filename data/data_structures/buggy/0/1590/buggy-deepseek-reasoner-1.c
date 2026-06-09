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
            if((('a'<=s[i-1]&&'z'>=s[i+1])||('A'<=s[i-1]&&'Z'>=s[i+1]))&&(s[i-1]<s[i+1])){ // @@ [Out-of-bounds access when i==0 or i==p-1; also, condition for same type is incorrect (should check both characters are in the same range and both are letters/digits); missing digit handling for '0'-'9']
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
    } // @@ [Missing null terminator: after the loop, t[cnt] should be set to '\0' before printing, otherwise printf("%s") may print garbage]
    printf("%s",t);
    return 0;
}