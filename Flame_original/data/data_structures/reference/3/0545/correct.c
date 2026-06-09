#include<stdio.h>
#include<string.h>
char num[200];
char ans[200];
char mid[200];
int main()
{
	int length;
	int locate1,locate2;//locate1小数点位置，locate2第一个非零数位置
	int i=0,m=0;
	int l=0;
	gets(num);//读入题目中小数
	length=strlen(num);//读出字符串长度
	for(i=0;i<length;i++){
		if(num[i]=='.'){
			locate1=i;
			break;
		}//读出小数点位置
	}
	if(locate1==1)//小数点在第二位
	{
		if(num[0]=='0')//第一位0
		{
			for(i=2;i<length;i++){
				if(num[i]!='0'){
					locate2=i;
					break;
				}//读出第一个不为0数字
			}
		
		    ans[0]=num[locate2];//把第一个不为0数存为ans第一位
		    if(locate2!=(length-1))//如果第一位不为0不是最后一位
		    {
			    ans[1]='.';//第二位必为小数点
		    	for(i=locate2+1,m=2;i<length;i++,m++)
		    	{
		    		ans[m]=num[i];//存剩下的数字从ans[2]=num[locate2后面一位]
		    	}	
			}
			else//是最后一位
			{
				m=1;
			}
			for(i=0;i<m;i++){
				printf("%c",ans[i]);//打印小数部分
			}
			printf("e-%d\n",locate2-1);//如0.03就是4-1十的三次方
		
		}
		else//第一位！=0
		{
			for(i=0;i<length;i++){
				printf("%c",num[i]);//直接打印出数字
			}
			printf("e0\n");//十的零次方
		}
		
		
	}
	else//小数点不在第二位
	{
		ans[0]=num[0];
		ans[1]='.';
		for(i=0;i<locate1;i++){
			mid[i]=num[i];//存小数点前数字
		}
		l=i;
		for(i=locate1+1;i<length;i++,l++){
			mid[l]=num[i];//存小数点后数字
		}
		for(i=2;i<=l;i++){
			ans[i]=mid[i-1];
		}
		for(i=0;i<length;i++){
			printf("%c",ans[i]);
		}
		printf("e%d\n",locate1-1);
		
		
	}
	
	
	
	
	return 0;
}

