#include <stdio.h>
#include <string.h>
char a[1000];
char b[1000];
int na, nb, nc;
char m, n;
int ccl(int x, int y, char opt); 
int main()
{
	
	
	/*gets(a);
	int len = strlen(a);
	for (int i=0, j=0; i<len; i++){
		if (a[i]!=' ') b[j++] = a[i];
	}*/
	scanf("%d %c", &na, &m);
	int cnt = 0;
	int ans = 0;
//	int *p = b;
//	p+=2;
	if (m=='=') ans = na;
	else{
		scanf("%d", &nb);
		scanf(" %c", &n);
		if (n!='=') scanf("%d", &nc);
		while(n!='='){       
		
		if(n=='+'||n=='-'){		
				na = ccl(na, nb, m);
				m = n;
				nb = nc;
			}else if (m=='*'||m=='/'){
				na = ccl(na, nb, m);
				m = n;
				nb = nc;
				
				
			}else{
				nb = ccl(nb, nc, n);
			}
			scanf(" %c", &n);
			if (n!='=') scanf("%d", &nc);
		}ans = ccl(na, nb, m);
		
	}
	printf("%d", ans);
	return 0;
}

int ccl(int x, int y, char opt)
{
	switch(opt){
		case '+':return x+y;
			break;
		case '-':return x-y;
			break;
		case '*':return x*y;
			break;
		case '/':return x/y;
	}
}
