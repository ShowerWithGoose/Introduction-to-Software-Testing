#include<stdio.h>
#include<string.h>
#define MAXN 101
char a[MAXN],in[MAXN];
int main()
{
	int i,j,len;
	scanf("%s",a);
	for(i = 0;a[i] != '\0';i++){
		in[0] = '\0';
		if(a[i] == '-'&&a[i-1] < a[i+1]&&((a[i-1] >= 'a'&&a[i+1] <= 'z')||(a[i-1] >= 'A'&&a[i+1] <= 'Z')||(a[i-1] >= '0'&&a[i+1] <= '9'))){
			len=a[i+1]-a[i-1]-2;
			strcpy(in,a+i+1);
			for(j = 0;j <= len;j++){
				a[i+j] = a[i-1]+j+1;
			}
			a[i+j] = '\0';
			strcat(a,in);
			i=i+len+1;
		}
	}
	printf("%s",a);
 return 0;
}




