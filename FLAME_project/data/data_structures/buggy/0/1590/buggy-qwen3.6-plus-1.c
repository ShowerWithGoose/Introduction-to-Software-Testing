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
            if((('a'<=s[i-1]&&'z'>=s[i+1])||('A'<=s[i-1]&&'Z'>=s[i+1]))&&(s[i-1]<s[i+1])){ // @@ The condition checks only for letters (a-z, A-Z) but misses digits (0-9). It should also include a check for digits like ('0'<=s[i-1]&&'9'>=s[i+1]).
                char l=s[i-1]+1,r=s[i+1]-1;
                for(;l<=r;l++){
                    t[cnt++]=l;
                    //printf("%d\n",i);    
                }
                continue; // @@ When expansion occurs, the code skips adding the start character (s[i-1]) and the end character (s[i+1]) to the output. It only adds the intermediate characters. The start character was already added in the previous iteration, but the current '-' and the next character s[i+1] are skipped entirely due to 'continue' and the loop increment, meaning s[i+1] is never added to t.
            }
        }
        t[cnt++]=s[i];
        //printf("%d\n",i);
    }
    printf("%s",t);
    return 0;
}