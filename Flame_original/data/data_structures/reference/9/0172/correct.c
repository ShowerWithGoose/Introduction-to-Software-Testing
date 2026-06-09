#include<stdio.h>
struct dot
{
    int x1;
    int y1;
    int x2;
    int y2;
} line[105];

int isline(int i,int j)
{
    if((line[i].x2==line[j].x1)&&(line[i].y2==line[j].y1))
        return 1;
    else return 0;
}
void swap_int(int*a,int*b)
{
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}
void swap(int i,int j)
{
    swap_int(&line[i].x1,&line[j].x1);
    swap_int(&line[i].x2,&line[j].x2);
    swap_int(&line[i].y1,&line[j].y1);
    swap_int(&line[i].y2,&line[j].y2);
}
int main()
{
    int i,j,k,n,num;
    int max_num,max=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
    for(i=0;i<n-1;i++)
        for(j=0;j<n-1-i;j++)
            if(line[j].x1>line[j+1].x1)
                swap(j,j+1);
    for(i=0,num=0;i<n;i++)
    {
        for(j=i,k=1;j+k<n;)
        {
            if(isline(j,j+k)==1)
            {
                j=j+k;
                k=1;
                num++;  
            }
            else k++;
        }
        if(num>max)
        {
            max=num;
            max_num=i;
        }  
		num=0;     
    }
    printf("%d %d %d",max+1,line[max_num].x1,line[max_num].y1);
    return 0;
}

