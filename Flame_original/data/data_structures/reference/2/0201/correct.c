#include <stdio.h>
#include <string.h>

int main(){
	char str[50],sym[100],str2[50];
	gets(str);
	int num=0,k=0,j=0,i=0,sum=0,num_sym,num_num;
	int number[100];
	
	for(i=0;i<strlen(str);i++){
		if(str[i]>='0'&&str[i]<='9'){
			num=num*10+str[i]-'0';
		}
		else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'){
			number[k]=num;
			k++;
			sym[j]=str[i];
			sym[j+1]='\0';
			j++;
			num=0;
		}
		else if(str[i]==' '){
			continue;
		}
		else if(str[i]=='='){
			number[k]=num;
			k++;
			break;
		}
	}
	//读入没有问题 
	num_sym=j; 
	num_num=k;
	//printf("num_numis:%d num_symis：%d\n",num_num,num_sym);
	for(i=0,j=0;i<num_sym;j++,i++){
		if(sym[i]=='-'){
			number[j+1]=-number[j+1];
			//printf("%d %d\n",number[j],number[j+1]);
			continue;
		}
		else if(sym[i]=='+'){
			//printf("%d %d\n",number[j],number[j+1]);
			continue;
		}
		else if(sym[i]=='*'){
			number[j+1]=number[j]*number[j+1];
			number[j]=0;
			//printf("%d %d\n",number[j],number[j+1]);
			continue;
		}
		else if(sym[i]=='/'){
			number[j+1]=number[j]/number[j+1];
			number[j]=0;
			//printf("%d %d %d\n",number[j],number[j+1],number[j+2]);
			continue;
		}
	}
	for(i=0;i<num_num;i++){
		sum+=number[i];
	}
	printf("%d",sum);
}

