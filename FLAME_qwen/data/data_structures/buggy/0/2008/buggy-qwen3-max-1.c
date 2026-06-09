#include <stdio.h>
#include <string.h>
int main()
{
    char sta[1000],las[10000];
    int n,m,i;
    gets(sta); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers that remove 'gets' entirely.]
    for(n=0,m=0;m<(strlen(sta)+1);n++,m++){
        las[n]=sta[m];
        if(sta[m+1]=='-'){
            if(('0'<=sta[m])&&(sta[m]<sta[m+2])&&(sta[m+2]<='9')){
                for(i=0;i<(sta[m+2]-sta[m]-1);i++){
                    las[n+1+i]=sta[m]+1+i;
                }
                n=n+i; // @@ [Variable 'i' is used after the loop where it was declared, but its value is the number of iterations; however, this logic skips characters incorrectly and may cause out-of-bound writes or missed characters. Also, 'i' is reused in subsequent loops without reset, leading to undefined behavior.]
                m=m+1;
                printf("%d %d\n",n,m);
            }
            if(('a'<=sta[m])&&(sta[m]<sta[m+2])&&(sta[m+2]<='z')){
                for(i=0;i<(sta[m+2]-sta[m]-1);i++){
                    las[n+1+i]=sta[m]+1+i;
                }
                n=n+i; // @@ [Same issue: 'i' retains value from previous loop (if any), causing incorrect index update. Should use loop bound variable directly or reset 'i'.]
                m=m+1;
            }
            if(('A'<=sta[m])&&(sta[m]<sta[m+2])&&(sta[m+2]<='Z')){
                for(i=0;i<(sta[m+2]-sta[m]-1);i++){
                    las[n+1+i]=sta[m]+1+i;
                }
                n=n+i; // @@ [Same issue as above: 'i' is not reset between cases, leading to wrong 'n' update if multiple conditions could theoretically match (though they shouldn't). Also, overlapping ranges not handled properly.]
                m=m+1;
            }
        }
    }
    puts(las);
    return 0;
}