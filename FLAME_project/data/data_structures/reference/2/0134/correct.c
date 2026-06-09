#include<stdio.h>
#include<string.h>
#include<math.h>
char c[1000];
int *a,d[500]= {0},count=1,ii=0,count2=1,i,flag;
char cc[500],sign1,sign2;
yxj(char m) {
	switch(m)

	{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;

	}
}
void de() {
	int i,j;
	for(i=0,j=0; c[i]!='\0'; i++)
		if(c[i]!=' ')
			c[j++]=c[i];
	c[j]='\0';
}

int main() {

	gets(c);
	de();

	while(c[ii]!='*'&&c[ii]!='/'&&c[ii]!='+'&&c[ii]!='-'&&c[ii]!='=') {
		d[0]=d[0]*10+c[ii]-'0';
		ii++;
	}
	a=&d[0];

	if(c[ii]=='=') {
		printf("%d",d[0]);
		return 0;
	} else
		cc[0]=sign1=c[ii];



	for(i=ii+1; c[i]!='\0'; i++) {
		if(c[i]!='*'&&c[i]!='/'&&c[i]!='+'&&c[i]!='-'&&c[i]!='=')
			d[count]=d[count]*10+c[i]-'0';//count=1
		else {
			count2++;//2
			sign2=sign1;
			sign1=cc[count2-1]=c[i];
			count++;//2
			flag=0;

			while(yxj(sign1)<=yxj(sign2)||sign1=='=') {

				if(flag==0) {
					switch(sign2) {
						case '*':
							d[count-1]=d[count-2]*d[count-1];
							if(count2==2)a=&d[count-1];
							break;
						case '/':
							d[count-1]=d[count-2]/d[count-1];
							if(count2==2)a=&d[count-1];
							break;
						case '+':
							d[count-1]=d[count-2]+d[count-1];
							if(count2==2)a=&d[count-1];
							break;
						case '-':
							d[count-1]=d[count-2]-d[count-1];
							if(count2==2)a=&d[count-1];
							break;
					}

				} else {
					switch(sign2) {
						case '*':
							d[count-1]=*a*d[count-1];
							a=&d[count-1];
							break;
						case '/':
							d[count-1]=*a/d[count-1];
							a=&d[count-1];
							break;
						case '+':
							d[count-1]=*a+d[count-1];
							a=&d[count-1];
							break;
						case '-':
							d[count-1]=*a-d[count-1];
							a=&d[count-1];
							break;
					}
				}
				count2--;//1
				cc[count2-1]=cc[count2];
				cc[count2]='\0';
				if(count2==1) {
					if(sign1=='=') {
						printf("%d",d[count-1]);
						return 0;
					}
					break;
				} else {
					sign2=cc[count2-2];
				}
				flag=1;
			}

		}
	}

}

