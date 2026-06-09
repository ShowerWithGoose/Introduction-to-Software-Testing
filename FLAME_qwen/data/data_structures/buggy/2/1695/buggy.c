#include<stdio.h>

int main() {
	int a1=0,a2,a3;
	char s1='+',s2,s3;
	while (s1!='='){
		scanf("%d%c",&a2,&s2);//一个数一个运算符 
		while (s2=='*'||s2=='/'){
			scanf("%d%c",&a3,&s3);
			if (s2=='*')
				a2=a2*a3;
			else if (s2=='/')
				a2=a2/a3;
			s2=s3;//产生循环，连续乘除 
		}
		if (s1=='+'){
			a1+=a2;
		}
		else if (s1=='-'){
			a1-=a2;
		}
		s1=s2;//产生循环，连续加减 
	}
	printf("%d",a1);
	return 0;
}


