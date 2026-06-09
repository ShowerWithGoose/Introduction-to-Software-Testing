#include <stdio.h>

int main(void) {
	int a,b,c;
	char p,q,r;
	a = 0;
	p = '+';
	while(p!='='){
		scanf("%d %c",&b,&q);
		while(q=='*'||q=='/'){
			scanf("%d %c",&c,&r);
			if(q=='*'){
				b *= c;
			}
			if(q=='/'){
				b /= c;
			}
			q = r;
		}
		if(p=='+'){
			a += b;
		}
		if(p=='-'){
			a -= b;
		}
		p = q;
	}
	printf("%d",a);

	return 0;
}

