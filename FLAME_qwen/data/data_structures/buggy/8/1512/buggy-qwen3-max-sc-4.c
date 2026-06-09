#include<stdio.h>
int main()
{
    int n1,n2;
    int l,r;
    int del;
    scanf("%d %d",&n1,&n2);
    printf("%d %d\n",n1,n2); // @@ [This debug print should not be present in the final program and alters output format]
    for(int i=0;i<n2;i++)
    {
        scanf("%d %d",&l,&r);
        printf("%d %d\n",l,r); // @@ [This debug print should not be present and violates output specification]
    }
    scanf("%d",&del);
    printf("%d",del); // @@ [This outputs only the deleted vertex, but expected output requires DFS/BFS sequences before and after deletion]
    return 0;
}