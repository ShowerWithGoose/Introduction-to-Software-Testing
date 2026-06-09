#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char c[150]={0},ans[150]={0};
	int tt,ttt=0,p_c,t,st,ptr_end;
	gets(c);

	/*先试试一定有小数点*/
	for(tt=0;c[tt]!='\0'&&c[tt]!='.';tt++);
	for(st=0;c[st]!='\0'&&(c[st]=='0'||c[st]=='.');st++);	 
	ans[ttt++]=c[st];
	if(c[st+1]!='\0') ans[ttt++]='.';
	for(p_c=st+1;c[p_c]!='\0';p_c++){
		if(p_c==tt) continue;
		ans[ttt++]=c[p_c];
	}
	ans[ttt++]='e';
	t=(tt>st) ? tt-st-1 : st-tt;//负数用的abs 
	/*指数为负数*/
	if(tt<st) ans[ttt++]='-';//此处ptr指向了e后第一个数字 
	
	ans[ttt]=t%10+'0';
	t/=10;
	for(ptr_end=ttt+1;t>0;t/=10){
		ans[ptr_end++]=t%10+'0';
	}
	ans[ptr_end--]='\0';
	/*交换*/
	while(ttt<ptr_end){
		ans[ttt]^=ans[ptr_end];
		ans[ptr_end]^=ans[ttt];
		ans[ttt]^=ans[ptr_end];
		ttt++;
		ptr_end--;
	}
	puts(ans);
	return 0;
}



