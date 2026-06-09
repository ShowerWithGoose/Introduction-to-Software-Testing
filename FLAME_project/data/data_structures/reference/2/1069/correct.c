#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>//4*5-3+6*2
int figure1(char a[]);
int main()
{
    char w[1000];//存储原始字段
    char u[1000];
    char b[1000];//存储数字和乘除号字段,动态变化
    int  c[1000];//存储加减号
    int  d[1000];//存储加减号之间的运算结果
    char smart[1000];//存储第一个加号或减号前的字符
    int i=0,j=0,k=0,start,t,wei1=0,front,answer;
    gets(w);
    //c[0]=c[1]=c[2]=9; 
    for(i=0;i<strlen(w)+1;i++)
    {
    	if(w[i]=='=')
    	{
    		u[k]='\0';
    		break;
		}
        else if(w[i]!=' ')
            u[k]=w[i],k++;
	}
//	printf("%d\n",strlen(w));
//  printf("%d\n",strlen(u));
//  puts(u);
	k=0;
    for(i=0;i<1000;i++)
    {
        b[i]='\0';
        //c[i]='\0';
        smart[i]='\0';
    }
    //sscanf(a,"%d",&start);//读第一个数
    i=0;
    while(u[i]!='+'&&u[i]!='-'&&u[i]!='\0')
    {
        smart[i]=u[i];
        i++;
    }
    start=figure1(smart);
    //printf("%d\n",start);
    strcpy(b,smart);
   // printf("%d\n",strlen(smart));
    for(i=strlen(smart);i<strlen(u);i++)
    {
        if(u[i]!='+'&&u[i]!='-')//读到数字和乘除号
        {
            b[j]=u[i];
            j++;
        }
        else//读到加减号
        {
        	t=i;
            d[k]=figure1(b);
            c[k]=((u[i]=='+')?0:1);
			//printf("%d %d\n",c[k],d[k]);
            k++;
            j=0;
            for(i=0;i<100;i++)
            {
                b[i]='\0';
            }
            i=t;
        }
    }
    d[k]=figure1(b);
    //printf("%d\n",d[k+1]);
    answer=start;
    //printf("**%d\n",answer);
    for(i=1;i<=k;i++)
    {
        if(c[i-1]==0)
            answer=answer+d[i];
        else
            answer=answer-d[i];
      //  printf("$%d\n",d[i]);
       // printf("%d\n",answer);
    }
    printf("%d",answer);
	return 0;
}
int figure1(char a[])
{
    int n=strlen(a);
    int num[100];//初始化为0,用来依次存储算式中出现的数字
    int fuhao[100];//1代表乘，0代表除
    //printf("%d",n);
    int k=0,i=0,first=0,wei=0,ans=0;//wei是第一个数的位数
    sscanf(a,"%d",&first);//读第一个数
    ans=first;
    for(i=0;i<100;i++)
    {
        num[i]=0;
        fuhao[i]=0;
    }
    while(first!=0)
    {
        first=first/10;
        wei++;
    }
    if(wei==n)
    	return ans;
    //printf("%d\n",wei);
    for(i=wei;i<n;i++)
    {
        if(a[i]!='*'&&a[i]!='/')//读到一个数字
        {
            num[k-1]=10*num[k-1]+a[i]-'0';
        }
        else if(a[i]=='*')
        {
            fuhao[k]=1;
            k++;
        }
        else
        {
        	fuhao[k]=0;
			k++;
		}         
    }
    //printf("%d\n",n);
    i=0;
    while(i<k)
    {
        if(fuhao[i]==1)
            ans=ans*num[i];
        if(fuhao[i]==0)
            ans=ans/num[i];
        i++;
    }
    //printf("999\n");
    return ans;
}

