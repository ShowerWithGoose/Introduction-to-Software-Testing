#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
int main()
{
	int mul=0,plu=0,k=0,numb=0,i,j;
	char a[100],t[100],op[100];
	int num[100]={0};
	gets(t);
	
	for(i=0;t[i]!='\0';i++){
		if(t[i]!=' '){
			a[k]=t[i];
			k++;
		}
	}
	a[k]='\0';
	k=0;
	
	for(i=0;a[i]!='=';i++)
	{
		if(a[i]>='0' && a[i]<='9')
			num[numb]=num[numb]*10+a[i]-'0';
		else{
			numb++;
			op[k++]=a[i];
			switch(a[i]){
				case '+':plu++;break;
				case '-':plu++;break;
				case '*':mul++;break;
				case '/':mul++;break;
			}
		}
	}
	op[k]='=';
	numb+=1;
	k+=1;
	for(i=0;op[i]!='=';i++)
	{
		if(op[i]=='/' || op[i]=='*'){
			mul--;
			if(op[i]=='/'){
				num[i]=num[i]/num[i+1];
				for(j=i;j+1<=k-1;j++)
					op[j]=op[j+1];
				k--;
				for(j=i+1;j+1<=numb-1;j++)
					num[j]=num[j+1];
				numb--;
				i--;
				continue;
			}
			else{
				num[i]=num[i]*num[i+1];
				for(j=i;j+1<=k-1;j++)
					op[j]=op[j+1];
				k--;
				for(j=i+1;j+1<=numb-1;j++)
					num[j]=num[j+1];
				numb--;
				i--;
				continue;
			}
		}
	}
	
		
	for(i=0;op[i]!='=';i++)
	{
		if(op[i]=='+' || op[i]=='-'){
			plu--;
			if(op[i]=='+'){
				num[i]=num[i]+num[i+1];
				for(j=i;j+1<=k-1;j++)
					op[j]=op[j+1];
				k--;
				for(j=i+1;j+1<=numb-1;j++)
					num[j]=num[j+1];
				numb--;
				i--;
				continue;
			}
			else{
				num[i]=num[i]-num[i+1];
				for(j=i;j+1<=k-1;j++)
					op[j]=op[j+1];
				k--;
				for(j=i+1;j+1<=numb-1;j++)
					num[j]=num[j+1];
				numb--;
				i--;
				continue;
			}
		}
	}
	
	printf("%d",num[0]);
	return 0;
}


