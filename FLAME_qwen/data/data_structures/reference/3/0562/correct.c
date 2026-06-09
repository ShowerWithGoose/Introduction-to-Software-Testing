#include <stdio.h>
#include <string.h>
int main() {
	long long int a=0,b=0,a1,b1;
	int i,point=100000,base=1,p,youxiao=-1,mowei;
	char in[1000];
	gets(in);
	int len=strlen(in);
	for(i=0; i<len; i++)
		if(in[i]=='.')
			point=i;
	for(i=0; i<len; i++)
		if(in[i]!='0' && in[i]!='.') {
			youxiao=i;
			break;
		}
	for(i=len-1; i>=0; i--)
		if(in[i]!='0' && in[i]!='.') {
			mowei=i;
			break;
		}
	if(youxiao==-1) printf("0");
	else if (len==1) puts(in);
	else if (point-1==youxiao)
		{for(i=youxiao; i<=mowei; i++)
			printf("%c",in[i]);
			printf("e0");} 
	else if (mowei==youxiao && point<youxiao)
		printf("%ce-%d",in[youxiao],youxiao-point);
	else if(mowei==youxiao && point>youxiao &&point!=100000)
		printf("%ce%d",in[youxiao],point-youxiao-1);
	else if(mowei==youxiao && point==100000)
		printf("%ce%d",in[youxiao],len-youxiao-1);
	else if(youxiao<point && mowei>point) {
		printf("%c.",in[youxiao]);
		for(i=youxiao+1; i<=mowei; i++) {
			if(in[i]=='.')
				continue;
			printf("%c",in[i]);
		}
		printf("e%d",point-youxiao-1);
	} else if(youxiao<point && mowei<point) {
		printf("%c.",in[youxiao]);
		for(i=youxiao+1; i<=mowei; i++) {
			printf("%c",in[i]);
		}
		printf("e%d",point-youxiao-1);
	} else if(youxiao>point) {
		printf("%c.",in[youxiao]);
		for(i=youxiao+1; i<=mowei; i++) {
			printf("%c",in[i]);
		}
		printf("e%d",point-youxiao);
	}
	return 0;
}

