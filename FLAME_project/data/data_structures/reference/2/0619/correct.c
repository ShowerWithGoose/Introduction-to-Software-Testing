#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char s[100],type[100],scopy[100];
	int number[100] = {0,0};
	gets(s);
	for(int i = 0,j = 0;i < strlen(s);i++){
		if(s[i] != ' '){
			scopy[j++]=s[i];
		}
	}
	for(int m = 0,n = 0,l = 0;m < strlen(scopy);m++){
		if(scopy[m]=='+'||scopy[m]=='-'||scopy[m]=='*'||scopy[m]=='/'||scopy[m]=='='){
			type[n++] = scopy[m];
		}
		if(scopy[m]=='0'||scopy[m]=='1'||scopy[m]=='2'||scopy[m]=='3'||scopy[m]=='4'||scopy[m]=='5'||scopy[m]=='6'||scopy[m]=='7'||scopy[m]=='8'||scopy[m]=='9'){
			int length;
			for( length = 1;length <= 10;length++){
				if(scopy[m+length]=='0'||scopy[m+length]=='1'||scopy[m+length]=='2'||scopy[m+length]=='3'||scopy[m+length]=='4'||scopy[m+length]=='5'||scopy[m+length]=='6'||scopy[m+length]=='7'||scopy[m+length]=='8'||scopy[m+length]=='9')
					continue;
				int num = 0,j = length,i = 1;
				for(;j > 0;j--){
					num += (scopy[m + j -1] - '0') * i; 
					i *= 10;
				}
				number[l++]=num;
				m += length - 1;
				if(scopy[m]!='0'||scopy[m]!='1'||scopy[m]!='2'||scopy[m]!='3'||scopy[m]!='4'||scopy[m]!='5'||scopy[m]!='6'||scopy[m]!='7'||scopy[m]!='8'||scopy[m]!='9')
					break;
			}
		}
	}
	int snumber[100];
	char stype[100];
	for(int i = 0,j = 0;i <= strlen(type);i++){
		if(type[i]=='+'||type[i]=='-'||type[i]=='='){
			stype[j] = type[i];
			snumber[j] = number[i];
			j++;
		}
		else if(type[i]=='*'){
			number[i + 1] = number[i] * number[i + 1];
		}
		else if(type[i]=='/'){
			number[i + 1] = number[i] / number[i + 1];
		}
	}
	int output=snumber[0];
	for(int i = 0;i < strlen(stype) - 1;i++){
		if(stype[i] == '+'){
			output += snumber[i+1];
		}
		if(stype[i] == '-'){
			output -= snumber[i+1];
		}
	}
	printf("%d",output);
	return 0;
}




