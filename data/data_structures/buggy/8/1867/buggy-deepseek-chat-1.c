#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    int n,m,d;
    scanf("%d %d",&n,&m);
    printf("%d %d\n",n,m);
    int bian[m][2]; 
    int visited[n];
    for(int i=0;i<m;i++){
        scanf("%d %d",&bian[i][0],&bian[i][1]);
        printf("%d %d\n",bian[i][0],bian[i][1]);
    }
    scanf("%d",&d);
    printf("%d",d);
    return 0;
}