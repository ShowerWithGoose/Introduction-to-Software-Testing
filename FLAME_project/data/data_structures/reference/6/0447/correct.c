#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>

int main()
{
    int stack[100],output[500],flag[500]={0};//flag=0时才表示操作无误  
    int op,data,i=0,j=0,cnt=0,top=0,pot=0;//可以信任的已经存好的数据是0~top-1
    while(1)
    {
        scanf("%d",&op);
        if(op==-1)
        break;//判断是否结束操作
        //scanf("%d",&data);

        if(op==1)
        {
            scanf("%d",&data);
            stack[top++]=data;//判断存入数据
            if(top>100)
                flag[pot++]=1,top--,cnt++;
        }
        else if(op==0)
        {
            if(top>0)
            output[pot++]=stack[top-1],cnt++;
            top--;//判断删除数据
            if(top<0)
            flag[pot++]=1,top++,cnt++;
        }
    }
    for(i=0;i<pot;i++)
    {
        if(flag[i]==1)
        printf("error ");
        else if(flag[i]==0)
        printf("%d ",output[i]);
    }
    return 0;
}
