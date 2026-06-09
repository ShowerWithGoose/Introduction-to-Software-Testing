#include <stdio.h>
#include <string.h>
int main()
{
    char sta[1000],las[10000];
    int n,m,i;
    gets(sta); // @@ [Use of unsafe function 'gets' which is deprecated and may cause buffer overflow; also, in modern C standards (C11+), 'gets' is removed, leading to compilation error if compiler enforces standard compliance]
    for(n=0,m=0;m<(strlen(sta)+1);n++,m++){
        las[n]=sta[m];
        if(sta[m+1]=='-'){
            if(('0'<=sta[m])&&(sta[m]<sta[m+2])&&(sta[m+2]<='9')){
                for(i=0;i<(sta[m+2]-sta[m]-1);i++){
                    las[n+1+i]=sta[m]+1+i;
                }
                n=n+i;
                m=m+1;
                printf("%d %d\n",n,m);
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