#include<stdio.h>
#include<string.h>
char biaodashi[1000];
int kongge[1000];
char bdstrue[1000];
char fuhao[1000];
char fuhao_later[1000];
int numall_later[1000];
int numall[1000];
int yuanben[1000];
int main()
{
	int j=0;
	gets(biaodashi);
	int length;
	length=strlen(biaodashi);
	for(int i=0;i<length;i++)
	{
		if(biaodashi[i]==' ')
		kongge[i]=1;
	}
	for(int i=0;i<length;i++)//将表达式中的空格去掉 
	{
		if(kongge[i]!=1)
		{
			bdstrue[j]=biaodashi[i];
			j++;
		}	
	}
	int true_length;
	true_length=strlen(bdstrue);
	int k=0;
	for(int x=0;x<true_length;x++)  //把符号存在fuhao数组中 
	{
		if(bdstrue[x]=='+'||bdstrue[x]=='-'||bdstrue[x]=='*'||bdstrue[x]=='/')
		{
			fuhao[k]=bdstrue[x];
			k++;
		}	
	}
	int number=0;
	int g=0;
	int shu_geshu=0,fuhao_geshu=0;
	for(int x=0;x<true_length;x++)//把数字存到numall数组里面 
	{
		if(bdstrue[x]>='0'&&bdstrue[x]<='9')
		{
			number=number*10+(bdstrue[x]-'0');
		}
		else
		{
			numall[g]=number;
			g++;
			number=0;
		}
	}
	for(int x=0;x<shu_geshu;x++)
	{
		if(numall[x]==0)
		{
			yuanben[x]=1;
		}		
	}
	shu_geshu=strlen(fuhao)+1;
	fuhao_geshu=strlen(fuhao);
	for(int x=0;x<fuhao_geshu;x++)//将乘除运算做完 ,将乘除符号记成0 
	{
		if(fuhao[x]=='*')
		{
			int num;
			num=numall[x]*numall[x+1];
			numall[x+1]=num;
			numall[x]=0;
			fuhao[x]='0';
		}
		if(fuhao[x]=='/')
		{
			int num;
			num=numall[x]/numall[x+1];
			numall[x+1]=num;
			numall[x]=0;
			fuhao[x]='0';
		}
	}
//	printf("%d",shu_geshu);
//	for(int x=0;x<shu_geshu;x++)
//	{
//		printf("%d",numall[x]);//////
//	}
	int p=0;
	for(int x=0;x<fuhao_geshu;x++)//留下加减的符号 
	{
		if(fuhao[x]!='0')
		{
			fuhao_later[p]=fuhao[x];
			p++;
		}
	}
	int cishu=strlen(fuhao_later);
//puts(fuhao_later);///
	int q=0;
	for(int x=0;x<shu_geshu;x++)//留下加减的数字
	{
		if(numall[x]!=0)
		{
			numall_later[q]=numall[x];
			q++;
		}
		if(numall[x]==0&&yuanben[x]==1)
		{
			numall_later[q]=numall[x];
			q++;
		}
	}
	//for(int x=0;x<cishu+1;x++)   ///
//	{
//		printf("%d",numall_later[x]);
//	}
	int answer=0;
	int temp=0;
//	printf("%d",cishu);
	for(int x=0;x<cishu;x++)
	{
		if(fuhao_later[x]=='+')
		{
			temp=numall_later[x]+numall_later[x+1];
			numall_later[x]=0;
			numall_later[x+1]=temp;
		//	printf("1");
		//printf("%d",temp);
		}
		else if(fuhao_later[x]=='-')
		{
			temp=numall_later[x]-numall_later[x+1];
			numall_later[x]=0;
			numall_later[x+1]=temp;
		//1	printf("2");
		}
	}
//	for(int x=0;x<cishu;x++)///
//	{
//		printf("%dhhh",numall_later[x]);
//	}
//	for(int x=0;x<cishu;x++)
//	{
//		answer+=numall_later[x];
//	}
	printf("%d",temp);
	return 0;
 } 

