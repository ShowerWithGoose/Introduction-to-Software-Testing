#include <stdio.h>
#include <stdlib.h>

int a[15]={0,1,2,3,4,5,6,7,8,9,10,0,0,0,0};


int data[15][116700][15];


int multipy(int n)
{
    int i,ret=1;
    for(i=1;i<=n;i++)
    {
        ret=ret*i;
    }
    return ret;
}

void kickHead(int* a,int n)
{
    int i;
    for(i=n;i<=10;i++)
    {
        a[i]=a[i+1];
    }
    return ;
}

void recoverHead(int* a,int n)
{
    int i;
    for(i=10;i>=n;i--)
    {
        a[i]=i;
    }
    return ;
}


void init_order(int n)
{
    //1的全排
    data[1][1][1]=1;
    //2的全排
    data[2][1][1]=1;
    data[2][1][2]=2;


    data[2][2][1]=2;
    data[2][2][2]=1;
    //3的全排
    data[3][1][1]=1;
    data[3][1][2]=2;
    data[3][1][3]=3;

    data[3][2][1]=1;
    data[3][2][2]=3;
    data[3][2][3]=2;

    data[3][3][1]=2;
    data[3][3][2]=1;
    data[3][3][3]=3;

    data[3][4][1]=2;
    data[3][4][2]=3;
    data[3][4][3]=1;

    data[3][5][1]=3;
    data[3][5][2]=1;
    data[3][5][3]=2;

    data[3][6][1]=3;
    data[3][6][2]=2;
    data[3][6][3]=1;
    //根据已有生成新的
    int i,j,k,m,total,repeat,p,q,l,head,t;//total为n的总共排法，repeat为不同第一个数字重复次数;p q l用于其他计数;head记录每个排头
    //i为轮到的n，j为每个n下的序列序数，k为每个序列中第k位；
    for(i=4;i<=n;i++)
    {
        total=multipy(i);
        repeat=total/i;
        p=i-1;//p记录上一个n order[p].data[q][l]
        //给每个序列的第一个数赋值并给每个序列的后几位根据之前得到的排列赋值
        for(j=1,m=1,t=1,q=0;j<=total;j++,m++)
        {

            q=q%repeat+1;
            head=data[i][j][1]=t;
            kickHead(a,head);
            if(m%repeat==0)
            {
                t++;
            }
            for(k=2,l=1;k<=i;k++,l++)
            {
                data[i][j][k]=a[data[p][q][l]];
            }
            recoverHead(a,head);
        }

    }
    return ;



}




int main()
{
    int n,total,i,j;
    scanf("%d",&n);
    init_order(n);
    total=multipy(n);
    for(i=1;i<=total;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%d ",data[n][i][j]);
        }
        printf("\n");
    }
    return 0;
}



