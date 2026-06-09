#include <stdio.h>
#include <string.h>
#define ll long long
int main ()
{
//	char ch=getchar();
	char a[1001];
	gets(a);
	int point = -1;
	int fi = -1;
	int time =0 ;
	for (int i=0 ;i<strlen (a);i++)
	{
		if (a[i] == '.') point = i;
		else if (a[i] != '0'&&fi==-1) {
			fi = i;
		}
		if (point != -1 &&fi != -1)
		{
			if(point - fi == -1) printf("%c",a[fi]);
			else printf("%c.",a[fi]);
			
			for(int j =fi+1 ; j<strlen(a) ;j++ )
			{
				if (a[j] != '.') printf("%c",a[j]);
			}
			printf("e%d",(point < fi)?(point - fi):(point - fi - 1));
			break;
		}
	}
}

