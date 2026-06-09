#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int step,j,ans,cnt;
char a[1000],s[1000];
long long getNum() {
	ans=0,cnt=0;
	while(s[step]>='0'&&s[step]<='9') {
		step++;
		cnt++;
	}
	for(j=1; j<=cnt; j++) {
		ans=ans+(s[step-j]-'0')*pow(10,j-1);
	}
//	step++;
//	printf("%d",step);
	return ans;
}
//int isdigit(long long m) {
//	if(m>='0'&&m<='9')
//		return 1;
//	return 0;
//}
long long cal(sign) { //用sign来标记这一项是正是负，也就是它的前面是加是减
	long long num = 0;
	long long tmp;
	int flag; //用来标记计算方式， 1 为 * , 2 为 /

	//项的开头必然是数字，所以先赋值一个数字
	num = getNum();
//	printf("%d&\n",num);
//	printf("%lld",num);
	while (1) {
		//收尾部分：如果这一项结束了，进入收尾代码

		//收尾代码

		//循环部分：各种乘除
		if(s[step]=='+'||s[step]=='-'||s[step]=='=') {
			return num*=sign;
		}
//		else if(s[step]=='='){
//			printf("%d");
//		}
		else if (isdigit(s[step])) {
			tmp = getNum();
//			printf("%d@",tmp);
			if (flag == 1)
				num *= tmp;
			else if (flag == 2)
				num /= tmp;
		} else if (s[step] == '*') {
			flag = 1;
			step++;
		} else if (s[step] == '/') {
			flag = 2;
			step++;
		}
	}
}

int main() {
	int i,k,x,y,z,n,m=0;
	gets(a);
	for(x=0,y=0; x<strlen(a); x++) {
		if(a[x]!=' ') {
			s[y]=a[x];
			y++;
		}
	}
//	puts(s);
	m+=cal(1);
//	printf("%d",m);
	for(;step<strlen(s);) {
		if(s[step]=='+'){
			step++;
			m+=cal(1);
//			printf("%d",m);
		}
			
		if(s[step]=='-'){
			step++;
			m+=cal(-1);
//			printf("%d",m);
		}
		if(s[step]=='='){
			printf("%d",m);
			break;
		}
			
	}
//	getNum();
//	printf("%d",ans);
	return 0;
}


