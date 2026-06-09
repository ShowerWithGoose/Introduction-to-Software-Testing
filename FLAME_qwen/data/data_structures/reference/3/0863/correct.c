#include<stdio.h>
#include<string.h>
char s[25];
int main()
{
	int i, len, p_dot, first_num, last_num, Pow;	

	gets(s);
	len = strlen(s);
	for(i = 0; i < len; i++){
		if(s[i] == '.') break;
	}
	p_dot = i;  //求出小数点的位置，若没有则为len。 

	for(i = 0; i < len; i++){
		if(s[i] != '0' && s[i] != '.') break;
	}
	first_num = i; //求出从左到右第一个非0数的位置，若没有则为len。 
	
	for(i = len - 1; i >= 0; i--){
		if(s[i] != '0' && s[i] != '.') break;
	}
	last_num = i; //求出从右到左第一个非0数的位置，若没有则为len。 
	
	if(last_num <= p_dot && first_num >= p_dot){ //此时说明全是0，直接输出0。 
		putchar('0');
		return 0;
	}
	
	if(first_num < p_dot) Pow = p_dot - first_num - 1;
	else Pow = p_dot - first_num; //求出次数。 
	
	putchar(s[first_num]); //后面为输出结果。 
	if(last_num > first_num){
		putchar('.');
		for(i = first_num + 1; i <= last_num; i++) 
			if(s[i] != '.') putchar(s[i]);
	}
	 printf("e%d", Pow);

	return 0;
}



