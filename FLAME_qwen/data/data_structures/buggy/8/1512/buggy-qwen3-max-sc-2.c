#include<stdio.h>
int main()
{
    int n1,n2;
    int l,r;
    int del;
    scanf("%d %d",&n1,&n2);
    printf("%d %d\n",n1,n2); // @@ [This debug print statement interferes with expected output format; the program should not output input values.]
    for(int i=0;i<n2;i++)
    {
        scanf("%d %d",&l,&r);
        printf("%d %d\n",l,r); // @@ [This debug print statement interferes with expected output format; the program should not output edge inputs.]
    }
    scanf("%d",&del);
    printf("%d",del); // @@ [This debug print statement outputs only the deleted vertex without newline and does not produce required DFS/BFS traversal sequences before and after deletion.]
    return 0;
}