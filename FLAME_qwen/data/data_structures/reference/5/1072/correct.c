#include <stdio.h> //不用我多说了
#include <math.h> //数学公式
#include <stdlib.h> //快排和malloc
#include <ctype.h> //字符处理函数
#include <string.h> //字符串函数
#include <time.h>//找时间
#define ll long long //纯粹是为了快~
#define eps 1e-6 //别被浮点数相等判断卡掉
#define MAX 1000005 //看好数据范围，多开5个空间
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define NumberOf(a) (sizeof(a)/sizeof(a[0]))
#define MAXN  10
#define MAXK  1e7
#define swap(x,y) {\
 typeof(x)temp=x;\
x=y;y=temp;\
}
clock_t start,stop;
typedef struct shu{
    int z;
    int x;
}shu;
shu p[100];
int temp;

typedef struct xiang{
    int zh;
    int xi;
    struct xiang *next;
}*List,node;
List createList(int a[],int b[] ,int n) {
    List L = NULL, p = NULL, r = NULL;
    int i;
    for( i = 0; i < n; i++) {
        p = (List) malloc(sizeof (node));
        p->zh = a[i];
        p->xi = b[i];
        p->next = NULL;
        if (L == NULL)
            L = p;
        else
            r->next = p;
        r = p;
    }
    r->next=L;
    return L;
}
void antibubblesort(shu ch[],int n){
    int i,j;
    shu temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(ch[j].z-ch[j+1].z<0)
            {
                temp=ch[j];
                ch[j]=ch[j+1];
                ch[j+1]=temp;}
        }
    }
};
int read(int a[],int b[],char s[])
{
    int i,j,k;
    for(i=0,j=0,k=0;i< strlen(s);i++){
        if(s[i]==' ')
            continue;
        else{
            if(k==j){
                for(a[k]=0;s[i]!=' ';i++)
                {
                    a[k]=a[k]*10+s[i]-48;
                }
                k++;
            }
            else{
                for(b[j]=0;s[i]!=' '&&s[i]!='\0';i++)
                {
                    b[j]=b[j]*10+s[i]-48;
                }
                j++;
            }
        }
    }
    return  k;
}
int  cheng(int a,int b,node* L,int n,int start)
{
	
    int i;
    for(i=start;i<n+start;i++)
    {
        p[i].z=a+L->zh;
        p[i].x=b*L->xi;
        //printf("%d %d\n",p[i].z,p[i].x);
        L=L->next;
    }
    start=i;
    return  start;
}
int main()
{
	for(temp=0;temp<100;temp++)
	{
	  p[temp].z=-1;
	  p[temp].x=0;
	}
    int zhi1[100]={};
    int zhi2[100]={};
    int xi1[100]={};
    int xi2[100]={};
    char s[100];
    gets(s);
    int n1= read(xi1,zhi1,s);
    List L1= createList(zhi1,xi1,n1);
    gets(s);
    int n2= read(xi2,zhi2,s);
    List L2= createList(zhi2,xi2,n2);
    int i,start=0,a,b;
    for(i=0;i<n1;i++)
    {   a=L1->zh;
    	b=L1->xi;
        start= cheng(a,b,L2,n2,start);
        L1=L1->next;
    }
    antibubblesort(p,n1*n2);
    for(i=0;i<n1*n2;i++)
    {
    	/*if(p[i].x==0)
    	break;*/
        if(p[i].z==p[i+1].z)
        {
            p[i+1].x+=p[i].x;
            continue;
        }
        else
        {
            printf("%d %d ",p[i].x,p[i].z);
        }
    }
    return 0;
}


