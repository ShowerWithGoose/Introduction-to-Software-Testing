#include <stdio.h>
#include <string.h>

int calc(int a, int b, char op)
{
	int result;
	if (op == '+')
		result = a + b;
	else if (op == '-')
		result = a - b;
	else if (op == '*')
		result = a * b;
	else
		result = a / b;
	return result;
}

int main(){
	int a[100]={1},i,j,k;
	char b[100]={'\0'};
	for(i=0;;i++){
		scanf("%d %c",&a[i],&b[i]);
		if(b[i] == '=')
			break;
	}
	for(j=0;j<=i;j++){
		if(b[j]=='*' || b[j]=='/'){
			a[j] = calc(a[j],a[j+1],b[j]);
			for(k=j+1;k<=i;k++){
				a[k] = a[k+1];
				b[k-1] = b[k];
			}
			j--;
		}
		else if(b[j] == '=')
			break;
	}
	for(j=0;j<=i;j++){
		if(b[j]=='+' || b[j]=='-'){
			a[j] = calc(a[j],a[j+1],b[j]);
			for(k=j+1;k<=i;k++){
				a[k] = a[k+1];
				b[k-1] = b[k];
			}
			j--;
		}
		else if(b[j] == '=')
			break;
	}
	printf("%d\n",a[0]);
	return 0;
}

