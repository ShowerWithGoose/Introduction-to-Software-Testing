#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int n, o[101], b[101]; //o:waiting_for_output; b:bool, 0 means not used, 1 means used
void tr(int cd) //tr:tree; cd:current_depth
{
    int i;
    if(cd == n+1){
        for(i=1;i<=n;++i)
            printf(i==n?"%d\n":"%d ",o[i]);
        return;
    }
    for(i=1;i<=n;++i){
        if(b[i] == 0){ //not used
            o[cd] = i;
            b[i] = 1;
            tr(cd + 1);
            b[i] = 0; //used --> not used
        }
    }
    return;
}
int main()
{
    scanf("%d",&n);
    if(n>=9) return 0;
    tr(1);
    system("pause");
    return 0;
}
