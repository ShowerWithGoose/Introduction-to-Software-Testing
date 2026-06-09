#include<stdio.h>
#include<string.h>
int main(){
	char c[200]="",d[200]="";
	int l,p=0;
	gets(c);
	l=strlen(c);
	for(int m=0;p<l;p++)
	{
		if(c[p]!='-') {d[m]=c[p];m++;}
		if(c[p]=='-')
			{
				int u=1;
				if((c[p-1]>='a'&&c[p-1]<='z')&&(c[p+1]>='a'&&c[p+1]<='z'))
			    {for(int y=0;y<c[p+1]-c[p-1];y++) {d[m]=c[p-1]+y+1;m++;}
				p++;u=0;}
			
			if((c[p-1]>='A'&&c[p-1]<='Z')&&(c[p+1]>='A'&&c[p+1]<='Z'))
						    {for(int y=0;y<c[p+1]-c[p-1];y++) {d[m]=c[p-1]+y+1;m++;}
							p++;u=0;}
			
			if((c[p-1]>='0'&&c[p-1]<='9')&&(c[p+1]>='0'&&c[p+1]<='9'))
						    {for(int y=0;y<c[p+1]-c[p-1];y++) {d[m]=c[p-1]+y+1;m++;}
							p++;u=0;}
			
			if(u) {d[m]='-';m++;}
			
			}
	}
	printf("%s",d);
	return 0;
}

