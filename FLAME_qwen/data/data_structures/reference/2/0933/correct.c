#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

char ch[10000], sign;
int x[10000];
void clear1()
{
	int i ,j = 0;
	for (i = 0; i < strlen(ch); ++i)
	{
		if (ch[i] != ' ' && ch[i] != '=') {
			ch[j++] = ch[i];
		}
	}
	ch[j] = '\0';
	return ;
}
void clear2()
{
	int i ,j = 0;
	for (i = 0; i < strlen(ch); ++i) {
		if (ch[i] == '+' || ch[i] == '-') {
			ch[j++] = ch[i];
		}
	}
	ch[j] = '\0';
	return ;
}
void getnum() 
{
	int j = 1, temp;
	char *stam = ch;
	while (sscanf(stam,"%d",&x[j])==1) {
			while (*stam >= '0' && *stam <= '9' && *stam != '\0') stam++;
		    if (*stam != '\0') sign = *stam, stam++;
		    else return;
			while (sign != '+' && sign != '-') {
			   	if (sign == '*') {
				    sscanf(stam,"%d",&temp);
				    x[j] *= temp;
			    } else {
			        sscanf(stam,"%d",&temp);
			        x[j] /= temp;
				}
				while (*stam >= '0' && *stam <= '9' && *stam != '\0') stam++;
				if (*stam != '\0') sign = *stam, stam++;
				else return;
		    }
		    j++;
    } 
}

int main()
{
    int i = 0, j = 1,ans;
    gets(ch);
	clear1();
	getnum();
	clear2();
	
    ans = x[j];
	for (i = 0; i < strlen(ch); ++i) {
		if (ch[i] == '+') {
			ans += x[++j];
		} else {
			ans -= x[++j];
		}
	}
	printf("%d", ans);
	return 0;
}




