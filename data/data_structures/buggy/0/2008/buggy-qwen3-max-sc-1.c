#include <stdio.h>
#include <string.h>
int main()
{
    char sta[1000],las[10000];
    int n,m,i;
    gets(sta); // @@ [Use of unsafe and deprecated function 'gets'; may cause buffer overflow and is removed in C11]
    for(n=0,m=0;m<(strlen(sta)+1);n++,m++){
        las[n]=sta[m];
        if(sta[m+1]=='-'){
            if(('0'<=sta[m])&&(sta[m]<sta[m+2])&&(sta[m+2]<='9')){
                for(i=0;i<(sta[m+2]-sta[m]-1);i++){
                    las[n+1+i]=sta[m]+1+i;
                }
                n=n+i; // @@ [After loop, 'i' equals (sta[m+2]-sta[m]-1), so 'n=n+i' skips correct number of positions, but logic assumes m+2 exists without checking bounds]
                m=m+1;
                printf("%d %d\n",n,m); // @@ [Debug print not in reference program; may affect output format and cause mismatch with expected output]
            }
            if(('a'<=sta[m])&&(sta[m]<sta[m+2])&&(sta[m+2]<='z')){
                for(i=0;i<(sta[m+2]-sta[m]-1);i++){
                    las[n+1+i]=sta[m]+1+i;
                }
                n=n+i; // @@ [Same as above: relies on sta[m+2] without ensuring it's within string bounds; also multiple ifs allow overlapping expansions]
                m=m+1;
            }
            if(('A'<=sta[m])&&(sta[m]<sta[m+2])&&(sta[m+2]<='Z')){
                for(i=0;i<(sta[m+2]-sta[m]-1);i++){
                    las[n+1+i]=sta[m]+1+i;
                }
                n=n+i; // @@ [Same issue: no bounds check for sta[m+2]; also using separate if blocks instead of else-if allows unintended multiple expansions]
                m=m+1;
            }
        }
    }
    puts(las);
    return 0;
}