#include <stdio.h>
#include <string.h>
int main() {
	char a[1000],b[1000];
	gets(a);
	int i;
	i=strlen(a);

	int i2=0;
	if(a[0]=='0') {
		int i1=0;
		while(a[i1+2]=='0') {
			i1++;
		}
		int a1=i1+1;
		if(a[i1+3]=='\0')
		{
			b[0]=a[i1+2];
			b[1]='e';
			b[2]='-';
			if(i-2>=10) {
			int i3;
			i3=(i-2)/10;
			b[3]=i3+48;
			i2++;
			i3=(i-2)%10;
			b[4]=i3+48;
		} else {
			b[3]=i-2+48;
		}
			
		puts(b);
		return 0;	
		}
		i2=2;
		b[0]=a[i1+2];
		b[1]='.';
		i1++;
		while(i1+2<i) {
			b[i2]=a[i1+2];
			i1++;
			i2++;
		}

		b[i2]='e';
		i2++;
		b[i2]='-';
		i2++;
		if(a1>=10) {
			int i3;
			i3=(a1)/10;
			b[i2]=i3+48;
			i2++;
			i3=(a1)%10;
			b[i2]=i3+48;
		} else {
			b[i2]=a1+48;
		}
	}

	else {
		while(a[i2+1]!='.')
			i2++;
		int i5=i2;
		if(i2==0) {
			a[i]='e';
			a[i+1]='0';
			puts(a);
			return 0;
		}
		int i3=2;
		b[0]=a[0];
		b[1]='.';

		while(i2+2<i) {
			a[i2+1]=a[i2+2];
			i2++;
		}

		b[0]=a[0];
		b[1]='.';
		while(i3<i) {
			b[i3]=a[i3-1];
			i3++;
		}

		i2--;
		b[i3]='e';
		i3++;
		if(i5>=10) {
			int i4;
			i4=(i5)/10;
			b[i3]=i4+48;
			i3++;
			i4=(i5)%10;
			b[i3]=i4+48;
		} else {
			b[i3]=i5+48;
		}


	}



	printf("%s",b) ;
	return 0;
}


