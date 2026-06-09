#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int main(){
	char sym[1000];
	int num[1000];
	int cnt_sym = 1;
	int cnt_num = 0;
	int count1 = 0;//加减计数器 
	int pos[1000];
	int i,j; 
	int sum = 0;
	sym[0] = '+';
	while(sym[cnt_sym-1]!='='){//读入并删去空格 
	    	scanf("%d",&num[cnt_num++]);
	    	char tmp;
		    scanf("%c",&tmp);
	    	while(tmp==' ')
			scanf("%c",&tmp);
		    sym[cnt_sym++]=tmp;
		}
	for(i=0;i<cnt_sym;i++){
			if(sym[i]=='+'||sym[i]=='-')
			pos[count1++]=i;//记录位置 
		}
		pos[count1]=cnt_sym-1;
    for(j = 0;j < count1; j++){//处理第j个加减号后的乘除法 
		int a;
		a=num[pos[j]];
		for(i=pos[j]+1;i<pos[j+1];i++){
			if(sym[i]=='*') a*=num[i];
			else if(sym[i]=='/') a/=num[i];
		}
		if(sym[pos[j]]=='+') 
		    sum+=a;
		else if(sym[pos[j]]=='-') 
		    sum-=a;
	} 
	printf("%d",sum);
	return 0;
}
	



