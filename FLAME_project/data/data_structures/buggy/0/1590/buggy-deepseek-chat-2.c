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
            if((('a'<=s[i-1]&&'z'>=s[i+1])||('A'<=s[i-1]&&'Z'>=s[i+1]))&&(s[i-1]<s[i+1])){ // @@ Error: The condition incorrectly checks that s[i+1] is within the range 'a' to 'z' or 'A' to 'Z', but it should also check for digits '0' to '9'. Additionally, the comparison 'z'>=s[i+1] is reversed; it should be s[i+1]<='z'. The same issue applies to the uppercase and digit checks. The logic should verify that both s[i-1] and s[i+1] are of the same type (lowercase, uppercase, or digit) and that s[i-1] < s[i+1].
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