#include<stdio.h>
#include<string.h>
int input1[100000][2],input2[100000][2],output[200000][2];
char buf1[100000],buf2[100000];
char buf[100000];
int change(char number[])//字符串转换为数字 
{
	int i;
	int changenumber=0;
	for(i=0;i<strlen(number);i++)
		changenumber=(number[i]-'0')+changenumber*10;
	return changenumber;
}
void clear(void)//清除buf数组
{
    int i=0;
    int j=strlen(buf);
	for(i=0;i<j;i++)
	    buf[i]='\0';	
} 
void contain(int k)//合并同类项 
{
	int i=0,j=0;
	for(i=0;i<k;i++)
	{
		if(output[i][0]==0)
		    continue;
	    for(j=i+1;j<k;j++)
		{
		    if(output[j][1]==output[i][1])
		    {
			    output[i][0]+=output[j][0];	
			    output[j][0]=0;
			    
			}
		}	
	}
}
void swap(int a,int b)//交换两行 
{
	int temp;
	temp=output[a][0];
	output[a][0]=output[b][0];
	output[b][0]=temp;
	temp=output[a][1];
	output[a][1]=output[b][1];
	output[b][1]=temp;
}
void upsort(int k)//排序 
{
	int max=0;
	for(int i=0;i<k;i++)
	{
		max=i;
		for(int j=i;j<k;j++)
		    if(output[j][1]>output[max][1])
			    max=j;  
		if(max!=i)
		    swap(i,max);
	}
}
int main()
{
	int checknumber=0,in1=0,in2=0,inin=0,i,j,k=0;
	gets(buf1);//读入第一行 
	gets(buf2);//读入第二行 
	for(checknumber=0;buf1[checknumber]!='\0';checknumber++,in1++)//处理第一行 
	{
		for(inin=0;buf1[checknumber]!=' '&&buf1[checknumber]!='\0';inin++,checknumber++)
			buf[inin]=buf1[checknumber];//读入系数an 
		input1[in1][0]=change(buf);
		checknumber++;
		clear();
		for(inin=0;buf1[checknumber]!=' '&&buf1[checknumber]!='\0';inin++,checknumber++)
		    buf[inin]=buf1[checknumber];//读入指数 
		input1[in1][1]=change(buf);
		clear();
	}
	for(checknumber=0;buf2[checknumber]!='\0';checknumber++,in2++)//处理第二行 
	{
		for(inin=0;buf2[checknumber]!=' '&&buf2[checknumber]!='\0';inin++,checknumber++)
		    buf[inin]=buf2[checknumber];//读入系数an 
		input2[in2][0]=change(buf);
		checknumber++;
		clear();
		for(inin=0;buf2[checknumber]!=' '&&buf2[checknumber]!='\0';inin++,checknumber++)
		    buf[inin]=buf2[checknumber];//读入指数
		input2[in2][1]=change(buf);
		clear();
	}
	for(i=0;input1[i][0]!=0;i++)
		for(j=0;input2[j][0]!=0;j++)
		{
			output[k][0]=input1[i][0]*input2[j][0];//系数相乘
			output[k][1]=input1[i][1]+input2[j][1];//指数相加
			k++; 
		}
	contain(k);//合并同类项
	upsort(k);
	if(input1[0][1]!=0&&input2[0][1]!=0)
		for(int l=0;l<k;l++)
			if(output[l][0]!=0)
		    	printf("%d %d ",output[l][0],output[l][1]);
	else
	{
		if(input1[0][1]==0&&input2[0][1]==0)
		    printf("%d 0",input1[0][0]*input2[0][0]);
		if(input1[0][1]==0&&input2[0][1]!=0)
		    for(int l=0;input2[l][0]!=0;l++)
		        printf("%d %d ",input1[0][0]*input2[l][0],input2[l][1]);
		if(input1[0][1]!=0&&input2[0][1]==0)
		    for(int l=0;input1[l][0]!=0;l++)
		        printf("%d %d ",input1[l][0]*input2[0][0],input1[l][1]);
	}
	return 0;
}

