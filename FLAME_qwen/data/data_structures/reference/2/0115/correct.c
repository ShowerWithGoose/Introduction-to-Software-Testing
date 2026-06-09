#include<stdio.h>
#include<string.h>
#include<ctype.h>
char a[1000];
char *str;
char *str_c;
int num[1000];
char sign[1000];
void fun(char *str){//去掉所有的空格
	char *str_c=str;
	int i,j=0;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]!=' ')
		str_c[j++]=str[i];
	}
		str_c[j]='\0';
		str=str_c;
}

int main(){
	gets(a);
	int sum=0,x=0,y=0;
	fun(a);
	int i=0,cnt=0,cnt2=0,n=0;
	for(i=0;i<strlen(a);i++){
		if(a[i]!='+'&&a[i]!='-'&&a[i]!='*'&&a[i]!='/'){
			for(n=0;a[i]>='0'&&a[i]<='9';i++){
				n=10*n+a[i]-'0';
			}
		num[x]=n;x++;

		//printf("%d ",num[x]);
		if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'){
			sign[y]=a[i];
			y++;
//		printf("%c",sign[y]);
			}
		}
    }//分为num[]里面的数字和剩下的符号
	for(int j=0;j<strlen(sign);j++){
		if(sign[j]=='*'){
			if(sign[j-1]=='-')sign[j]='-';
			else sign[j]='+';
			num[j+1]=num[j]*num[j+1];
			num[j]=0;
		//	printf("%d %d ",num[j],num[j+1]);
		//	printf("%c\n",sign[j]);
		}
		else if(sign[j]=='/'){
			if(sign[j-1]=='-')sign[j]='-';
			else sign[j]='+';
			num[j+1]=num[j]/num[j+1];
			num[j]=0;
		//	printf("%d %d ",num[j],num[j+1]);
		//	printf("%c\n",sign[j]);
		}
	}
	for(int j=0;j<strlen(sign);j++){
		if(sign[j]=='+'){
			sign[j]='+';
			num[j+1]=num[j]+num[j+1];
			num[j]=0;
		//	printf("%d %d ",num[j],num[j+1]);
		//	printf("%c\n",sign[j]);
		}
		else if(sign[j]=='-'){
 			sign[j]='+';
			num[j+1]=num[j]-num[j+1];
			num[j]=0;
		//	printf("%d %d ",num[j],num[j+1]);
		//	printf("%c\n",sign[j]);
		}
	}
	printf("%d",num[x-1]);
	return 0;
}

