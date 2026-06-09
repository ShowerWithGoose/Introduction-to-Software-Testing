#include<stdio.h>
#include<string.h>
void fun(char *str){//消去空格
	char *p=str;
	int i=0;
	while(*p!=NULL){
		if(*p!=' ')
			str[i++]=*p;
	p++;
	}
	str[i]='\0';
	return;
}
int main(){
	char str[200];
	gets(str);
	fun(str);
	int i,j;
	int last;
	int sum=0;
	int digit[100]={};//记录第2,3次循环时的数字
	char charx[100]={};//记录第2,3次循环时的运算符

	
	
	//以下是修改后的第一次循环
		last=str[0]-'0';
		for(i=1,j=1;i<strlen(str);i++){//第一层循环，将分散的数字字符整合成参与运算的数字
			
			if((str[i]=='+')||(str[i]=='-')||(str[i]=='*')||(str[i]=='/')||(str[i]=='='))
			{
				digit[j]=last;
				last=0;
				charx[j++]=str[i];
			}
			else
			{
			digit[j]=last*10+str[i]-'0';
			last=digit[j];
   }

		}
	
  //修改后的第二次循环
 for(i=1;charx[i]!='=';i++)
  {
  	if(charx[i]=='*')
  	{
  		digit[i+1]=digit[i+1]*digit[i];
  		digit[i]=0;
  		if(i==1)
  		charx[i]='+';
  		else
  		charx[i]=charx[i-1];
	  }
	  if(charx[i]=='/')
  	{
  		digit[i+1]=digit[i]/digit[i+1];
  		digit[i]=0;
  		if(i==1)
  		charx[i]='+';
  		else
  		charx[i]=charx[i-1];
	  }
  }

	//第三次循环
	sum=digit[1];
	for(i=1;charx[i]!='=';i++)
	{
		if(charx[i]=='+')
		sum+=digit[i+1];
		else if(charx[i]=='-')
		sum-=digit[i+1];
		else
		break;
}
	printf("%d",sum);
		return 0;
		}



