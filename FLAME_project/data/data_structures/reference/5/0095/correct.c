 //读入，用do while来进行读入，在读入的过程中，顺便记录多项式的项数
//计算，可能会出现很多的指数相同的项，所以计算完后需要进行去重操作
//如果有指数相同的项，只需要保留第一项即可
 
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

int i,j,k;
 
struct expression{   //多项式结构体 
    int xi;        //系数 
    int zhi;       //指数 
};
typedef struct expression ex;//类型转换 
ex a[2000],b[2000],c[2000];//a是第一个多项式，b是第二个多项式 ,c是最后相乘的多项式 
int cmp(const void*p1,const void*p2)//排序函数 
{
    struct expression *a=(struct expression*)p1;
    struct expression *b=(struct expression*)p2;
    return b->zhi - a->zhi;//按指数从大到小排 
}
//return *(int *)p1 - +(int *)p2; 由小到大排 
int main()
{    
    int n=0,nn=0;
	//n是第一个多项式的项的个数 ，nn是第二个多项式的项的个数  
    char ch;
    do   //读入第一个多项式 
    {
        scanf("%d%d%c",&a[n].xi,&a[n].zhi,&ch);
        n++;
    }while(ch!='\n');
    do    //读入第二个多项式
    {
        scanf("%d%d%c",&b[nn].xi,&b[nn].zhi,&ch);
        nn++;
    }while(ch!='\n');
    
    //qsort(*s,n,sizeof(s[0]),cmp)
    //s:地址  n:需要排序的数量  
	//sizeof(s[0]):每个元素占用的空间大小
	//cmp:指向函数的指针，用于确定排序的顺序 
    qsort(a,n,sizeof(ex),cmp); //按指数排序第一个 
    qsort(b,nn,sizeof(ex),cmp); //按指数排序第二个 
	k=0; 
    for(i=0;i<n;i++)
    {
        //使第一个多项式的每一项分别和第二个的每一项相乘 
		for(j=0;j<nn;j++)
        {
            c[k].xi=a[i].xi * b[j].xi;//系数相乘 
            c[k].zhi=a[i].zhi + b[j].zhi;//指数相加 
            k++;
        }
    }
    qsort(c,k,sizeof(ex),cmp);//新多项式共k项，根据指数排序，此时有指数重复的项 
    for(i=0;i<k;i++)
    {
        //指数一样的进行去重操作 
		if(c[i].zhi == c[i+1].zhi && c[i].zhi!=0)//已经排序，所以只和后一项比较 
        {
            c[i+1].xi+=c[i].xi;//系数相加 
            c[i].xi=0;//去重项系数设为零 
        }
    }
    qsort(c,k,sizeof(ex),cmp);//根据指数排序 
    for(i=0;i<k;i++)
    {
        if(c[i].xi==0)//去重项不输出 
        {
            continue;
        }
        else
        {
            printf("%d %d ",c[i].xi,c[i].zhi);//输出 
        }
    }
    return 0;
}


