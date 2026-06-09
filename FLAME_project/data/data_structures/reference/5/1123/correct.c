#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct mul
{

    int co;
    int ind;

};
void left(struct mul s[],int n,int N)
{
    for(int i=n;i<N;i++)
    {
        s[i].co=s[i+1].co;
        s[i].ind=s[i+1].ind;
    }

}
void del(struct mul out[],int n,int*p)
{
    int num=0,temp=0;
    for(int i=1;i<n;i++)//i确定，用j查找
    {
        for(int j=i-1;j>=0;j--)
        {
            if(out[j].ind==out[i].ind&&out[i].co!=0&&out[i].ind!=0)
            {
                out[j].co+=out[i].co;
                left(out,i,n);
                num++;
                temp++;
            }
            else continue;
        }
        if(num==1)

            {
                i--;
                num=0;
            }
    }
    *p-=temp;
}
int dx(struct mul* s,struct mul* t)
{
    /*int *a,*b;
    struct mul *p,*q;
    p=(struct mul*)s;
    q=(struct mul*)t;
    a=(int*)p->ind;
    b=(int*)q->ind;*/
    return t->ind-s->ind;//(struct mul.ind*)t-(struct mul.ind*)s;
}
int main()
{
    struct mul mt1[33000],mt2[33000],out[33000];
    int i=0,k1=0,k2=0,k3=0;
    int *p=&k3;
	char s;
	for (i=0;i<33000&&s!='\n';i++)    //最大输入100个数，遇到回车就终止循环
	{
		scanf("%d",&mt1[i].co);
		scanf("%d",&mt1[i].ind);
		s=getchar();           //s用来接收是否是回车
		k1++;                   //检测输入的个数
	}
	s='s';
	for (i=0;i<33000&&s!='\n';i++)    //最大输入100个数，遇到回车就终止循环
	{
		scanf("%d",&mt2[i].co);
		scanf("%d",&mt2[i].ind);
		s=getchar();           //s用来接收是否是回车
		k2++;                   //检测输入的个数
	}


	for(int i=0;i<k1;i++)
    {
        for(int j=0;j<k2;j++)
        {
            out[k3+j].co=mt1[i].co*mt2[j].co;
            out[k3+j].ind=mt1[i].ind+mt2[j].ind;
        }
        k3=k3+k2;//每次增加mt2数组的长度
    }
    // k3最终为out数组的长度
    del(out,k3,p);
    qsort(out,k3,sizeof(struct mul),dx);
    //left(out,2,4);k3--;
    //printf("%d ",out[5].co);
    //printf("%d ",out[5].ind);
    for(int i=0;i<k3;i++)
    {
        printf("%d ",out[i].co);
        printf("%d ",out[i].ind);
    }
    //printf("%d",*p);
    return 0;
}

