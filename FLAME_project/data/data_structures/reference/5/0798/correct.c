#include<stdio.h>
//b1[] b2[];
void exchange(int* m, int* n)
{
    int temp;
    temp=*m;
    *m=*n;
    *n=temp;
}
int main()
{
    char check;
    int answer[1000][2];
    int a[100][2], b[100][2], i=1, j=1, c, d;
while(check!='\n')
{
    scanf("%d%d%c",&a[i][1],&a[i][2],&check);
    i++;
}
check=' ';
while(check!='\n')
{
    scanf("%d%d%c",&b[j][1],&b[j][2],&check);
    j++;
}
for(int k=1; k<=i; k++)
    for(int l=1; l<=j; l++)
{
    answer[k*j+l-j][1]=a[k][1]*b[l][1];
    answer[k*j+l-j][2]=a[k][2]+b[l][2];
}
c=i;
d=j;
for(i=c*d; i>0; i--)
    for(j=1; j<i; j++)
    {
        if(answer[j][2]<answer[i][2])
        {
            exchange(&answer[i][2], &answer[j][2]);
            exchange(&answer[i][1], &answer[j][1]);
        }
        else if(answer[i][2]==answer[j][2])
        {
            answer[i][1]=answer[i][1]+answer[j][1];
            answer[j][1]=0;
            answer[j][2]=0;
        }
    }
for(int k=1; k<=c*d; k++)
{
    if(answer[k][1]!=0)
    {
        if(k==1)
            printf("%d %d",answer[k][1], answer[k][2]);
        else
        printf(" %d %d",answer[k][1], answer[k][2]);
    }
}
    return 0;
}

