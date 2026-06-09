#include<stdio.h>
#include<string.h>
char sp[100];
int position=0;
char* s;
/*
1.读入首个字符，若读到-则输出-
2.若首位为0，小数点后移到非0位置 symbol=-
3.若首位为整数，小数点移到第一个整数后 symbol为+
4.统计移动了多少，输出
*/
int main(){
	scanf("%s",sp);
	if(sp[0]=='-'){
		printf("-");
		s=&sp[1];
	}
	else
		s=&sp[0];  //判断有没有负号并输出v，重写字符串为正(过
	/*若首位为0，小数点后移到非0位置 symbol=-*/
	if(s[0]=='0'){   //0.1(1是s【2】,输出的cnt应该为-1，即cnt-1）
		           //0.002，cnt=4，输出3
				   //0.0023 cnt=4，输出3
		int cnt=2;
		while(s[cnt]=='0')
			cnt++;
		s+=cnt;
		if(*(s+1)!=NULL){
			printf("%c.%se-%d",s[0],s+1,cnt-1);
		}
		else
			printf("%se-%d",s,cnt-1);
	}
	else{ //29.8输出2.     98e1 
		printf("%c.",s[0]);
		int cnt=1;
		while(s[cnt]!='.')
			cnt++;
		cnt--;
		for(int i=1;s[i]!=NULL;i++){
			if(s[i]=='.')
				i++;
			printf("%c",s[i]);
		}
		printf("e%d",cnt);
	}
	
}


