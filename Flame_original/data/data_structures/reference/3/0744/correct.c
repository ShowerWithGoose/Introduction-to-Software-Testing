#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	gets(a);
	//接下来两种情况：小于1和大于1的  
	int k=0,n=0;
	if(a[0]=='0')//小于零 
	{
		//我要计算小数点后面有几个零
		for(int i=0;i<strlen(a);++i){
			if(a[i]=='.')
			k=i;	
			 
			if(a[i]!='0'&&a[i]!='.'){
			n=i;
			break;//用n-k-1算出后面有多少个零	
			} 
		} 
		int cnt=n-k;
		
		//只有一个数的情况
		if(a[n+1]=='\0'){
			printf("%ce%d",a[n],-cnt);
		} else//一般情况
		{
			printf("%c.",a[n]);
			printf("%se%d",a+n+1,-cnt);
		 } 
	
	 } else//大于零 
	 {
	 	for(int i=0;i<strlen(a);++i){
	 		if(a[i]=='.'){
	 			n=i;
	 			for(int bit=i;bit<strlen(a);bit++)//把小数点给去掉 
	 			{
	 				a[bit]=a[bit+1]; 
				 }
	 			break;
			 }
		 } 
		 //先判断是不是整数
		 if(n==0){
		 	printf("%c.",a[0]);
		 	printf("%se%d",a+1,strlen(a)-1);
		 }else{
		 	printf("%c.",a[0]);
		 	printf("%se%d",a+1,n-1);
		 }
	 }
	return 0;
}



