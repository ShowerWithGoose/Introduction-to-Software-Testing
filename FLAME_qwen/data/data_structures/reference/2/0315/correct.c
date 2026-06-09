#include <stdio.h>
#include <string.h>
char s[1005];
int numlist[100];
int opelist[100];
int stdlist[100];
int main() {
	gets(s);
	int l = strlen(s),k=0,adv=0,std=0;
	int res = 0;
	//input
	for(int i=0; i<l; i++) {
		switch(s[i]) {
			case ' ':
				break;
			case '+':
				opelist[k++] = 1;
				stdlist[std++]=k-1;
				break;
			case '-':
				opelist[k++] = 2;
				stdlist[std++]=k-1;
				break;
			case '*':
				opelist[k++] = 3;
				adv++;
				break;
			case '/':
				opelist[k++] = 4;
				adv++;
				break;
			case '=':
				goto Cal;
				break;
			default:
				numlist[k] = numlist[k]*10+s[i]-'0';
				break;
		}
	}

	//calculate
Cal:
	stdlist[std]=k;
	for(int i=0; adv!=0; i++) {
		if(opelist[i]==3) {
			numlist[i+1]*=numlist[i];
			adv--;
		} else if(opelist[i]==4) {
			numlist[i+1]=numlist[i]/numlist[i+1];
			adv--;
		}
	}
	res = numlist[stdlist[0]];
	for(int i=0;i<std;i++)
	{
		if(opelist[stdlist[i]]==1) res += numlist[stdlist[i+1]]; else res -= numlist[stdlist[i+1]];
	}
	printf("%d",res);
	return 0;
}


