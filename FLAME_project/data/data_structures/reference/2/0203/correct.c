/*基本思路：四则运算的优先级问题
先乘除后加减，则以加减号所在位置为断点，对加减号之后的小式子进行乘除运算
最后将断点连接起来，计算总和 */
#include <stdio.h>
int main()
{	//数据读入，这串式子的特点是先一个数字 再一个字符（运算符号），但中间可能会有空格
	int  shuju[105],count_shuju=0,count_fuhao=1,count_jj=0;//!!!count表示脚标的话 符号在数字后
	char fuhao[105];
	int where_jj[105];
	int i,j,k;
	int result=0; 
	fuhao[0]='+';
	while(fuhao[count_fuhao-1]!='=')
	{
		scanf("%d",&shuju[count_shuju++]);
		char whether_space;
		scanf("%c",&whether_space);
		while(whether_space==' ')
		scanf("%c",&whether_space);
		fuhao[count_fuhao++]=whether_space;
	}//得到所有的运算数据和运算符号 并且给它们列队排好了 两队元素之间在原式子中的关系就是错开的关系 
	
	for(j=0;j<count_fuhao;j++)
	{
		if(fuhao[j]=='+'||fuhao[j]=='-')
		where_jj[count_jj++]=j;
	}//找到加减号在符号数组里的脚标
	where_jj[count_jj]=count_fuhao-1; 
	for(k=0;k<count_jj;k++)
	{	int part;
		part=shuju[where_jj[k]];//外层循环 把小式子相加减 
		for(i=where_jj[k];i<where_jj[k+1];i++) 
		{//计算每个乘除小式子的结果  小式子里的各个数由加减号的脚标定位对应到数据数组的脚标找到 
			if(fuhao[i+1]=='*') 
			part*=shuju[i+1];
			else if(fuhao[i+1]=='/')
			part/=shuju[i+1];
		}
		if(fuhao[where_jj[k]]=='+')
		result+=part;
		else if(fuhao[where_jj[k]]=='-')
		result-=part;
	}
		printf("%d",result);
		return 0;
} 



