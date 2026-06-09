#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define swap(type,a,b) {type t=a;a=b;b=t;}

//思路：首先，定义一个指针数组，每个指针指向‘+’或‘-’的符号；
//再在两个指针间的式子简化，诸如“12/3/4”简化为 “1”，再带入原式进行加减即可



int simplify(char *p1,char*p2) {

	int k,i,j;
	int Number=1;
	int d[1005]= {0};
	char * q[1005];//这里简化函数内部， 再开一个指针数组，指向“*”或“/”
				//因为可能出现 12 这样的两位数 

	q[0]=p1;//第一个指针就指向最前面 
	for(i=1; p1+i!=p2; i++) {
		if(*(p1+i)=='*'||*(p1+i)=='/') {
			q[Number]=p1+i;
			Number++;
		}
	}
	q[Number]=p2;//最后一个指针 

	for(i=0; i<Number; i++) {// d[]储存了每两个乘除号间的数值 
		for(j=1; q[i]!=q[i+1]-j; j++) {
			d[i]+=(*(q[i+1]-j)-'0')*power(10,j-1);
		}
	}

	int answer=0;
	answer+=d[0];

	for(j=1; j<Number; j++) {
		if(*(q[j])==47)
			answer/=d[j];
		else
			answer*=d[j];
	}
	return answer;
}



int power(int base,int index) { //是一个幂函数
	int result=1;
	while(index>0) {
		if(index&1==1) result*=base;
		index>>=1;
		base*=base;
	}
	return result;
}

int main() {
	char a[1005],b[1005],c[1005];
	char *p[1005];
	int number=1;
	gets(a);
	
	int i=0,j=0;
	for(i=0; a[i]!='\0'; i++) {//除去空格 
		if(a[i]!=' ') {
			b[j]=a[i];
			j++;
		}
	}
	
	for(i=1;; i+=1) {
		if(b[i]=='+'||b[i]=='-'||b[i]=='=') {
			p[number]=&b[i];
			number++;
		}
		if(b[i]=='=') break;
	}
	p[0]=&b[0]-1;//见图解释 

	int  answer=0;
	answer+=simplify(p[0],p[1]);
	for(i=1; *p[i]!='='; i++) {
		if(*p[i]=='+')
			answer+=simplify(p[i],p[i+1]);
		else answer-=simplify(p[i],p[i+1]);
	}
	printf("%d",answer);
	return 0;
}












