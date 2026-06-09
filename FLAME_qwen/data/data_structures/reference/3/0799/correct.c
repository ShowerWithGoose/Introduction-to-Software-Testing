#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char c[150]={0},ans[150]={0};
	int add_dot,ptr=0,p_c,num_e,first_not0,ptr_end;
	gets(c);

	/*先试试一定有小数点*/
	for(add_dot=0;c[add_dot]!='\0'&&c[add_dot]!='.';add_dot++);
	for(first_not0=0;c[first_not0]!='\0'&&(c[first_not0]=='0'||c[first_not0]=='.');first_not0++);	 
	ans[ptr++]=c[first_not0];
	if(c[first_not0+1]!='\0') ans[ptr++]='.';
	for(p_c=first_not0+1;c[p_c]!='\0';p_c++){
		if(p_c==add_dot) continue;
		ans[ptr++]=c[p_c];
	}
	ans[ptr++]='e';
	num_e=(add_dot>first_not0) ? add_dot-first_not0-1 : first_not0-add_dot;//负数用的abs 
	/*指数为负数*/
	if(add_dot<first_not0) ans[ptr++]='-';//此处ptr指向了e后第一个数字 
	
	ans[ptr]=num_e%10+'0';
	num_e/=10;
	for(ptr_end=ptr+1;num_e>0;num_e/=10){
		ans[ptr_end++]=num_e%10+'0';
	}
	ans[ptr_end--]='\0';
	/*交换*/
	while(ptr<ptr_end){
		ans[ptr]^=ans[ptr_end];
		ans[ptr_end]^=ans[ptr];
		ans[ptr]^=ans[ptr_end];
		ptr++;
		ptr_end--;
	}
	puts(ans);
	return 0;
}



