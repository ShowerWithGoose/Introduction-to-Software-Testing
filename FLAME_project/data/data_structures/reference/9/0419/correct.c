#include<stdio.h>

struct line
{
    int arr[10];
    struct line* next;
};

int main()
{
    int n;scanf("%d",&n);  //确定组数
    int i,j;struct line s[n];//创建数据
    for(i=0;i<n;i++)      //确定具体数据
    {   for(j=0;j<4;j++)scanf("%d",&(s[i].arr[j]));
        s[i].arr[4]=1;s[i].next=NULL;} //初始化




    for(i=0;i<n;i++)//连接
    {      for(j=0;j<n;j++)
    {
        if(s[i].arr[2]==s[j].arr[0]&&s[i].arr[3]==s[j].arr[1])
            {s[i].next=&s[j];s[j].arr[4]=0;}
    }
    }



    int length[100],head[100];
    int n1=0,n2=0;
    for(i=0;i<n;i++)
    {
        if(s[i].arr[4]==1)
        {
            int num=1;struct line* plist;
            head[n2++]=i;
            plist=&s[i];
            while(plist->next)
            {
                num++;
                plist=plist->next;
            }
            length[n1++]=num;
            //printf("%d\n",num);

        }
    }

    int max=length[0],h=0;;
    for(i=0;i<n1;i++)
    {
        if(length[i]>max)
        {
            max=length[i];
            h=i;
        }

    }
    printf("%d %d %d",max,s[head[h]].arr[0],s[head[h]].arr[1]);



        return 0;
}


