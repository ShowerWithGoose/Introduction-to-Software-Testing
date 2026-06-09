#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<ctype.h> 
#include<stdlib.h> 
#define GET_BIT(value, bit) (((value) >> bit) & 1)  //读取指定位 
#define CPL BIT(value, bit) ((value) ^= (1 << (bit)))  //取反指定位 
#define SETO BIT(value, bit) ((value) &= ~(1 << (bit)))  //把某位置0 
#define SET1 BIT(value, bit) ((value) |= (1 << (bit)))  //把某位置1
#define ARRAY_LEN(x) (sizeof(x)/sizeof(x[0]))
#define eps 1e-8 
struct line
{
    int x1;
    int y1;
    int x2;
    int y2;
};
typedef struct line line;
int cmp(const void *p1,const void *p2);
void combine(line line[],int i,int n);

int count1=1,count2=1;
int *c1=&count1,*c2=&count2;
int x=0,y=0; 

int main()
{
    line line[105] = {0};
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
    }
    qsort(line,n,sizeof(line[0]),cmp);
    for(int i=0;i<n;i++)
    {
        combine(line,i,n);
        if((*c2)>=(*c1))
        {
            *c1 = *c2;
            x = line[i].x1;
            y = line[i].y1;
        }
        *c2 = 0;
    }
    printf("%d %d %d",*c1,x,y);
    return 0;
}

int cmp(const void *p1,const void *p2)
{
    line *v1 = (line*)p1;
    line *v2 = (line*)p2;
    if((v1->x1)>(v2->x1)) return 1;
    else if((v1->x1)<(v2->x1)) return -1;
    else return 0;
}

void combine(line line[],int i,int n)
{
    for(int j=i+1;j<n;j++)
    {
        if((line[j].x1==line[i].x2)&&(line[j].y1==line[i].y2))
        {
            (*c2)++;
            combine(line,j,n);
        }
    }
}