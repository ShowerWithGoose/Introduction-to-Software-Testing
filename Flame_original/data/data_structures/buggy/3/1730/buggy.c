#include <stdio.h>
#include <string.h>
int main()
{
//如果是整数，记位
//如果小数点前不为0，记位，输出
//如果小数点前为0，记第一个不为0的数，输出

char num[100];          //342400.982003 
int zheng, dian;
char put[100];
int flag=0;
int j=-1;
int del=0;
gets(num);
int l = strlen(num);
for(int i=0;num[i]!='\0'; i++){
	if(num[i]=='.')flag=1;  
	else if(num[i]!='.'&&flag==0){   //整数部分
	zheng++;
	put[++j]=num[i];        //把原数列赋给新的里面 
		
	}
	
	else{
		dian++;    //小数数位+1 
		put[++j]=num[i];        //把原数列赋给新的里面 
		
	}
}                            //统计完各个位数 
put[j+1]='\0';

int newl=strlen(put); 

if(flag==0){                  //是整数 且结尾不为0 	
	for(int i=newl-1; i>0; i--){
		if(put[i]!='0')break;
		else newl--;
	}
	if(newl==1){
		printf("%ce%d",put[0],l-1);
	}
	else{
		printf("%c.",put[0]);
		for(int i=1; i<=newl-1; i++){
		printf("%c",put[i]);
	}
	printf("e%d",l-1);
	}	
} 
else{         //是小数

if(put[0]!='0'){         //第一位不是0      3232.423
printf("%c.",put[0]);
for(int i=1; i<=newl; i++){
	printf("%c",put[i]);
} 
printf("e%d",zheng-1);	
}                      
else{      //第一位是0  
      	
	int p; 
	for(p=0; put[p]=='0';p++);
	if(p==newl-1)printf("%ce-%d",put[p],p);     //有效数字只有最后一位 
	else{	
	printf("%c.",put[p]);
	for(int i=p+1; put[i]!='\0'; i++){
		printf("%c",put[i]);       //0.00067
	}
	printf("e-%d",p);
	}
}
}
printf("\n");

return 0;
}



