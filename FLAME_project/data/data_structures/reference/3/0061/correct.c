#include<stdio.h>
#include<string.h> 
int main(){
	char in[110];
	gets(in);
	int count,flag,get,gete;
	for(count=1;count<strlen(in);count++){
		if(in[count]=='.')
		flag=count;
	}
	if(flag==1&&in[count]!=0)//不用转换 
	printf("%se0\n",in);
	else if(in[0]=='0'){//小于1 
		for(count=2;count<strlen(in);count++)//get有效数字位置 
			if(in[count]!='0'){
				get=count;break;
			}
			
		for(count=strlen(in),gete=count;count>get;count--){//gete有效数字末尾 
			if(in[count]!=0)
		    break;
		    gete--;
		} 
		if(get!=gete)
		printf("%c.",in[get]);
		else
		printf("%c",in[count]);
		for(count=get+1;count<=gete;count++)
			printf("%c",in[count]);//输出剩余有效位
		printf("e-%d",get-1); 
		}
	else{
		printf("%c.",in[0]);
	    for(count=1;count<strlen(in);count++)
	    if(count!=flag)
	    printf("%c",in[count]);
	    printf("e%d",flag-1);
	}
	    
		
	
}

