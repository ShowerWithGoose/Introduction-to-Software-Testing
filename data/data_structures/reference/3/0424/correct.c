#include <stdio.h>
#include <string.h>

char ch[1000001],num;

int main(){
	scanf("%s",ch);
	int i,dot,p;
	for(dot=0;ch[dot];++dot)
		if(ch[dot]=='.')break;
	for(p=0;ch[p];++p)
		if(ch[p]>'0')break;
	for(i=dot;ch[i];++i)
		ch[i]=ch[i+1];
	while(ch[0]=='0')
		for(i=0;ch[i];++i)
			ch[i]=ch[i+1];
	for(;i>1;--i)
		ch[i]=ch[i-1];
	if(ch[1])ch[1]='.';
	printf("%se%d",ch,dot<p?dot-p:dot-p-1);
	return 0;
}
