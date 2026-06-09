#include<stdio.h>
#include<string.h>
void tran(int num,char *s); //数字转化为字符串 
int main()
{
	char s[105]=""; //输入数据 
	char end[105]=""; // 后缀 
	int num_0=0; //0的个数 
	scanf("%s",s);
//	puts(s);
	if(s[1]=='.')	//小数点在第二位，带 
	{
		if(s[num_0]=='0')
		{
			num_0++;
			while(s[num_0+1]=='0')
				num_0++;
		}
//		printf("num_0=%d\n",num_0);
		if(num_0>0)
		{
			char p1[2]="";	
			p1[0]=s[num_0+1];
			p1[1]='\0';
			
			char *s1=strstr(s,p1);	//截断0部分 
			strcat(end,"e-");
			char numstr[105]=""; //0的个数转化为字符串 
			tran(num_0,numstr);
			strcat(end,numstr); //组装end 
			char ss[100]="";	//最后的结果
			ss[0]=s1[0];
//			printf("%d\n",strlen(s1));
			if(strlen(s1)!=1)
			ss[1]='.';
			p1[0]=s1[0];
//			strtok(s1,p1);
			strcat(ss,s1+1);
			strcat(ss,end);
			puts(ss);
			return 0;
		}else{
			strcat(s,"e0");
			puts(s);
		}
	}else{	//小数点不在第二位 
		
		if(s[strlen(s)-2]=='.' && s[strlen(s)-1]=='0')	//整数类型 
		{
			int num_0=1;	//0的个数 330.0
			while(s[strlen(s)-num_0-1]==0)
				num_0++;
//			char p2[2];
//			p2[0]=s[strlen(s)-num_0-1];
//			p2[1]='\0';
			char ss1[105]="";	//最后的结果 
//			strtok(s,p2);
			ss1[0]=s[0];
			ss1[1]='.';
			strncat(ss1,s+1,strlen(s)-num_0-2);
			char numstr[105]=""; //0的个数转化为字符串 
			tran(num_0,numstr);
			strcat(ss1,"e");
			strcat(ss1,numstr);
			puts(ss1);
		}else{	//非整数 
			int num_1=0;	//小数点前数字个数
			while(s[num_1]!='.')
			{
				num_1++;
			}
			char ss[105]=""; //最后的结果
			ss[0]=s[0];
			ss[1]='.';
			char *s1=strstr(s,"."); //原来小数点后面的数字
			strtok(s,"."); //原来小数点前面的数字
			strcat(ss,s+1);
			strcat(ss,s1+1); 
			strcat(ss,"e");
			char numstr[100]="";
			tran(num_1-1,numstr);
			strcat(ss,numstr);
			puts(ss);
		}
		
		
	}
	
}
void tran(int num,char *s)
{
	int i=-1;
	while(num>0)
	{
		s[++i] = (char)(num%10)+'0';
		num/=10;
	}
	for(int j=0;j<i;j++,i--)
	{
		char temp = s[i];
		s[i]=s[j];
		s[j]=temp;
	}
} 

