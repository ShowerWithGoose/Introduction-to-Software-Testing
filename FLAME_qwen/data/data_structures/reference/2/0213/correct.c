#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	char s[10000];
	int num[1000];
	char fu[1000];
	int zan[100];
	int i=0,j=0,k=0,jj=0,sfu=0;
	gets(s);
	//将数字和符号单独存储在两个数组num和fu中 
	for(i=0;s[i]!='\0';i++){
		if(s[i]<='9'&&s[i]>='0'){
			zan[j]=s[i]-'0';
			j++;
		}else if(s[i]=='*'||s[i]=='/'||s[i]=='+'||s[i]=='-'||s[i]=='='){
			fu[k]=s[i];
			for(jj=0;jj<=j-1;jj++){
				num[k]=num[k]*10+zan[jj];
			}
			k++;
			j=0;
			sfu++;
		}
	}
	sfu--;
	int snum=sfu+1;
	sfu++;
	//进行乘除计算和数组数据的迁移 
	for(i=0;fu[i]!='=';i++){
		if(fu[i]=='*'||fu[i]=='/'){
			if(fu[i]=='*'){
				num[i]=num[i]*num[i+1];
				for(k=i+1;k<snum;k++){
					num[k]=num[k+1];
				}
				snum--;
				num[k]='\0';
				for(k=i;k<sfu;k++){
					fu[k]=fu[k+1];
				}
				sfu--;
				fu[k]='\0';
				i--;
			}else{
				num[i]=num[i]/num[i+1];
				for(k=i+1;k<snum;k++){
					num[k]=num[k+1];
				}
				snum--;
				num[k]='\0';
				for(k=i;k<sfu;k++){
					fu[k]=fu[k+1];
				}
				sfu--;
				fu[k]='\0';
				i--;
			}
		}
	} 
	//进行加减运算
	int sum=num[0];
	for(i=0;fu[i]!='=';i++){
		if(fu[i]=='+'){
			sum+=num[i+1];
		}else{
			sum-=num[i+1];
		}
	} 
	printf("%d",sum);
	return 0;
}

