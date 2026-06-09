#include <stdio.h>
#include <string.h>
int main()
{
    char sta[1000],las[10000];
    int n,m,i;
    gets(sta);
    for(n=0,m=0;m<(strlen(sta)+1);n++,m++){ // @@ Loop condition includes null terminator, causing out-of-bounds access when m is strlen(sta) and accessing sta[m+1] later.
        las[n]=sta[m];
        if(sta[m+1]=='-'){ // @@ Accessing sta[m+1] when m is strlen(sta) is out of bounds.
            if(('0'<=sta[m])&&(sta[m]<sta[m+2])&&(sta[m+2]<='9')){
                for(i=0;i<(sta[m+2]-sta[m]-1);i++){
                    las[n+1+i]=sta[m]+1+i;
                }
                n=n+i;
                m=m+1;
                printf("%d %d\n",n,m); // @@ This debug printf produces extraneous output not expected by problem.
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