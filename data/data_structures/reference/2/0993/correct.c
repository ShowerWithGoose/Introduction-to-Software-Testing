#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
char a[100003];
int num[50005];
char sign[50005]; 
int inum = -1;
int isign = -1;
int getnum(int start){
	int part = 0;
	int i;
	for(i = start;a[i]>='0'&&a[i]<='9';i++){
		part = part*10 + a[i] - '0';
	}
	return part;
}
int main(void)
{	
	int sum = 0,part;
	int i,j;
	gets(a);
	for(i = 0,j = 0;i <= strlen(a) - 1;i ++){//删除空格 
		if(a[i]!=' '){
			a[j] = a[i];
			j ++;
		}
	}
	a[j] = '\0'; 

	for(i = 0;i <= strlen(a) - 1;i ++){
		if(a[i] >= '0'&&a[i] <= '9'){
			num[++inum] = getnum(i);
			for(j = i + 1;;j++){
				if(a[j] < '0'||a[j] > '9') break;//j指向非数字点 
			}
			i = j - 1;//保证指向最后一位数字 
		}
		else if(a[i] < '0' || a[i] > '9'){
			isign ++;
			sign[isign] = a[i];
		}	
	}
	sum += num[0];
	i = 1;//指向了第二个数字 
	j = 0;//i指向数字，j指向第一个符号
	while(i <= inum){
		if(sign[j] == '*'){
			sum = sum*num[i];
			i ++;
			j ++;
		} 
		else if(sign[j]=='/'){
			sum = sum/num[i];
			i ++;
			j ++;
		}
		else if(sign[j]=='+'){
			if(sign[j + 1] == '+'||sign[j + 1] == '-'||sign[j + 1]=='=')
			{
				sum = sum + num[i];
				i ++;
				j ++;
			}
			else if(sign[j + 1] == '*'||sign[j + 1] == '/')
			{
				part = num[i];
				j ++;
				while(sign[j] == '*'||sign[j] == '/')
				{
					if(sign[j] == '*'){
						part = part * num[i + 1];
						i ++;
						j ++;
					}
					else if(sign[j] == '/'){
						part = part / num[i + 1];
						i ++;
						j ++;
					}
				}
				i ++;
				sum = sum + part;
			}
			
		}
		else if(sign[j] == '-'){
			if(sign[j + 1] == '+'||sign[j + 1] == '-'||sign[j + 1]=='=')
			{
				sum = sum - num[i];
				i ++;
				j ++;
			}
			else if(sign[j + 1] == '*'||sign[j + 1] == '/')
			{
				part = num[i];
				j ++;
				while(sign[j] == '*'||sign[j] == '/')
				{
					if(sign[j] == '*'){
						part = part * num[i + 1];
						i ++;
						j ++;
					}
					else if(sign[j] == '/'){
						part = part / num[i + 1];
						i ++;
						j ++;
					}
				}
				i ++;
				sum = sum - part;
			}
		}
		
	}
	printf("%d",sum); 
	return 0;
}




