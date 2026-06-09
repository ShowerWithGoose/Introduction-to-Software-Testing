#include<stdio.h>
int s[100];

int main()
{
    int top=-1,cur,data;
    while(scanf("%d",&cur)!=EOF)
    {
        if(top==-1&&cur==0)//下溢出
        printf("error ");
        else if(top==99&&cur==1)//上溢出
        printf("error ");
        else if(cur==1)//push
        {
            scanf("%d",&data);
            s[++top]=data;
            
        }
        else if(cur==0)//pop
        {
            data=s[top--];
            
            printf("%d ",data);
        }
        else if(cur==-1)
        break;
    }
    return 0;
}


