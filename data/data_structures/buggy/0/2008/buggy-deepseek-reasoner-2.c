#include <stdio.h>
#include <string.h>
int main()
{
    char sta[1000],las[10000];
    int n,m,i;
    gets(sta);
    for(n=0,m=0;m<(strlen(sta)+1);n++,m++){ // @@ [Off‑by‑one error: loop runs one extra iteration, causing out‑of‑bounds access to sta[m+1] and sta[m+2] when m equals strlen(sta). Should be m<strlen(sta).]
        las[n]=sta[m];
        if(sta[m+1]=='-'){
            if(('0'<=sta[m])&&(sta[m]<sta[m+2])&&(sta[m+2]<='9')){ // @@ [Incorrect condition: checks only sta[m]>= '0' instead of both ends; should be (sta[m]>='0' && sta[m]<='9').]
                for(i=0;i<(sta[m+2]-sta[m]-1);i++){
                    las[n+1+i]=sta[m]+1+i;
                }
                n=n+i;
                m=m+1;
                printf("%d %d\n",n,m); // @@ [Debug output not required; produces unintended printed values.]
            }
            if(('a'<=sta[m])&&(sta[m]<sta[m+2])&&(sta[m+2]<='z')){ // @@ [Incorrect condition: should be (sta[m]>='a' && sta[m]<='z').]
                for(i=0;i<(sta[m+2]-sta[m]-1);i++){
                    las[n+1+i]=sta[m]+1+i;
                }
                n=n+i;
                m=m+1;
            }
            if(('A'<=sta[m])&&(sta[m]<sta[m+2])&&(sta[m+2]<='Z')){ // @@ [Incorrect condition: should be (sta[m]>='A' && sta[m]<='Z').]
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