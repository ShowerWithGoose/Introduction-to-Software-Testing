#include<stdio.h>
#include<string.h>
char ques[1000000];
char ans[10000000];
int a[100]={0};
void lengthen(int i,int x,int j)
{
    int temp;
    int k=1;
    for(k=1;k<=x;k++)
    {
        ques[i+k-1]=ques[i-1]+k;
    }//字符拓展
    for(temp=0;temp<j;temp++)
    {
        ques[i+x+temp]=ans[temp];
    }//将在ans中储存的字符拷贝到ques中实时更新ques
}
int main()
{
	int i=0,j=0,x=0;
	int len=0;
	int xiao1,xiao2,da1,da2,shu1,shu2;
	int locate=0;
	gets(ques);//读入题目
	len=strlen(ques);
	for(i=0;i<len;i++){
		if(ques[i]=='-'&&ques[i+1]>ques[i-1])//判断减号位置且后大于前
		{
			locate=i;
			for(locate++,j=0;locate<len;locate++,j++)
           {
	        	ans[j]=ques[locate];
			}//将i+1到末尾的字符存储到map里
           	xiao1=ques[i-1]-'a';
	      	xiao2=ques[i+1]-'a';
	        da1=ques[i-1]-'A';
            da2=ques[i+1]-'A';
	        shu1=ques[i-1]-'0';
	        shu2=ques[i+1]-'0';//判断拓展哪种
			if(0<=xiao1&&xiao1<25&&0<xiao2&&xiao2<=25)//小写字母延长
			{
				x=ques[i+1]-ques[i-1]-1;//拓展字符个数
				lengthen(i,x,j);
			}
			else if(0<=da1&&da1<25&&0<da2&&da2<=25)//大写
			{
				x=ques[i+1]-ques[i-1]-1;//拓展字符个数
				lengthen(i,x,j);
			}
			else if(0<=shu1&&shu1<9&&0<shu2&&shu2<=9){
				x=ques[i+1]-ques[i-1]-1;//拓展字符个数
				lengthen(i,x,j);
			}
			len=strlen(ques);
		
		}
		
	}
	printf("%s",ques);
	return 0;

	
}



