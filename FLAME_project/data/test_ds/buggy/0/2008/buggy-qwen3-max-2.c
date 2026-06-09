#include <stdio.h>
#include <string.h>
int main()
{
    char sta[1000],las[10000];
    int n,m,i;
    gets(sta); // @@ [Using gets() is unsafe and may cause buffer overflow; also, the loop condition m<(strlen(sta)+1) leads to reading beyond string end]
    for(n=0,m=0;m<(strlen(sta)+1);n++,m++){ // @@ [Loop runs one past null terminator; sta[m+1] and sta[m+2] may access out-of-bounds memory when m == strlen(sta)-1 or m == strlen(sta)]
        las[n]=sta[m];
        if(sta[m+1]=='-'){
            if(('0'<=sta[m])&&(sta[m]<sta[m+2])&&(sta[m+2]<='9')){
                for(i=0;i<(sta[m+2]-sta[m]-1);i++){
                    las[n+1+i]=sta[m]+1+i;
                }
                n=n+i;
                m=m+1;
                printf("%d %d\n",n,m); // @@ [Debug print not in expected output; causes wrong answer due to extra output]
            }
            if(('a'<=sta[m])&&(sta[m]<sta[m+2])&&(sta[m+2]<='z')){
                for(i=0;i<(sta[m+2]-sta[m]-1);i++){
                    las[n+1+i]=sta[m]+1+i;
                }
                n=n+i;
                m=m+1;
            }
            if(('A'<=sta[m])&&(sta[m]<sta[m+2])&&(sta[m+2]<='Z')){
                for(i=0;i<(sta[m+2]-sta[m]-1);i++){
                    las[n+1+i]=sta[m]+1+i;
                }
                n=n+i;
                m=m+1;
            }
        }
    }
    puts(las);
    return 0;
}