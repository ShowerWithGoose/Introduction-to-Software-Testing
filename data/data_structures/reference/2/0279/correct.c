#include<stdio.h>
#include<string.h>
#include<math.h>

void degap(char *ch){
	char *str=ch;
	int i=0,j=0;
	for(i=0;ch[i]!='\0';i++){
		if(ch[i]!=' '){
			str[j++]=ch[i];
		}
	}
	str[j]='\0';
	ch=str;
}

int main()
{
	char equal0[1000],equal[1000],add[100],quan[100][1000];
	int num[100][1000],numl[100],ready[100];
	int result;
	gets(equal);
	degap(equal);
	int i=0,j=0,k=0,l=0,k0=0,l0=0;
	int len=strlen(equal);
	int count=1;//k:+-;l:*/;
	for(i=0;i<=len-1;i+=count){
		if(equal[i]>='0' && equal[i]<='9'){
			num[k][l]=equal[i]-'0';
			for(j=i;equal[j+1]>='0' && equal[j+1]<='9' && j<len-2;j++){
				num[k][l]=num[k][l]*10+(equal[j+1]-'0');
				count++;
			}
		}
		else if(equal[i]=='*' || equal[i]=='/'){
			quan[k][l]=equal[i];
			l++;
			count=1;
		}
		else if(equal[i]=='+' || equal[i]=='-' || equal[i]=='='){
			add[k]=equal[i];
			numl[k]=l;//一个加减组中含有乘除的个数； 
			k++;
			l=0;
			count=1;
		}
		else{
			continue;
		}
	}
	int len1=strlen(add);
	for(k0=0;k0<=len1;k0++){
		ready[k0]=num[k0][0]; 
		for(l0=0;l0<numl[k0];l0++){
			if(quan[k0][l0]=='*'){
				ready[k0]*=num[k0][l0+1];
			}
			else if(quan[k0][l0]=='/'){
				ready[k0]/=num[k0][l0+1];
			}
		}
	}//先算乘除模块存入数组ready; 
	result=ready[0];
	for(k0=0;k0<len1;k0++){
		if(add[k0]=='+'){
			result+=ready[k0+1];
		}
		else if(add[k0]=='-'){
			result-=ready[k0+1];
		}
		else if(add[k0]=='='){
			break;
		}
	}
	printf("%d\n",result);
	return 0;
}

