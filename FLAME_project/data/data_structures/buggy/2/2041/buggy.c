#include<stdio.h>

int main()
{
	//É¨ÃèÁ½±é
	int i,num[10000];
	char op[10000];
	i=0;
	scanf("%d %c",&num[i],&op[i]);
	while(op[i]!='='){
		i++;
		scanf("%d %c",&num[i],&op[i]);
	}
	for(i=0;op[i]!='=';i++){//µÚÒ»±éÉ¨Ãè 
		if(op[i]=='*'){
			num[i+1]=num[i]*num[i+1];
			num[i]=0;
			if(i>0){//´«µÝ¼õºÅ 
				op[i]=op[i-1];
			}else{
				op[i]='+';
			} 
		}else if(op[i]=='/'){
			num[i+1]=num[i]/num[i+1];
			num[i]=0;
			if(i>0){//´«µÝ¼õºÅ 
				op[i]=op[i-1];
			}else{
				op[i]='+';
			}
		}
    }
	for(i=0;op[i]!='=';i++){
		if(op[i]=='+'){
			num[i+1]=num[i]+num[i+1];
		}else if(op[i]=='-'){
			num[i+1]=num[i]-num[i+1];
		}
	}
	printf("%d",num[i-1]);
	return 0;
}


