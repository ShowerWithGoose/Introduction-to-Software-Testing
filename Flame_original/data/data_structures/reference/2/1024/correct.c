#include<stdio.h>
#include<string.h>
int main(){
	char s[1005]={},f[1005]={'='};
	int m[15]={};
	int i=0,d,j=0,h=0,k=0,l=0,q=1,o=0,p=0,z=0,y=0,t=0;
	gets(s);
	d=strlen(s);
	for(i=0;i<d;i++){
		if(s[i]=='*'||s[i]=='/'||s[i]=='+'||s[i]=='-'||s[i]=='='){
			f[k++]=s[i];
		}
		if(s[i]>='0'&&s[i]<='9'){
			for(y=i;y<d;y++){
				if(s[y]>='0'&&s[y]<='9'){
					j++;
				}
				else break;
			}
			i=y-1;
			for(j=j;j>0;j--){
				q=s[y-j]-'0';
				for(l=j;l>0;l--){
					q*=10;
				}
				m[h]+=q;
			}
			m[h]=m[h]/10;
			h++;
		}
	}
	while(f[t]!='='){
		t++;
	}
	for(k=0;f[k]!='=';k++){
		if(f[k]=='*'){
			m[k]=m[k]*m[k+1];
			for(o=k+1;o<=t;o++){
				m[o]=m[o+1];
			}
			for(l=k;f[l]!='=';l++){
				f[l]=f[l+1];
			}
			k--;
		}
		if(f[k]=='/'){
			m[k]=m[k]/m[k+1];
			for(o=k+1;o<=t;o++){
				m[o]=m[o+1];
			}
			for(l=k;f[l]!='=';l++){
				f[l]=f[l+1];
			}
			k--;
		}	
	}
	for(p=0;f[p]!='=';p++){
		if(f[p]=='+'){
			m[p]=m[p]+m[p+1];
			for(z=p+1;z<=t;z++){
				m[z]=m[z+1];
			}
			for(y=p;f[y]!='=';y++){
				f[y]=f[y+1];
			}
			p--;
		}
		if(f[p]=='-'){
			m[p]=m[p]-m[p+1];
			for(z=p+1;z<=t;z++){
				m[z]=m[z+1];
			}
			for(y=p;f[y]!='=';y++){
				f[y]=f[y+1];
			}
			p--;
		}
	}
	printf("%d",m[0]);
	return 0;
}




































/*#include<stdio.h>
int main(){
	char a[2];
	int b;
	gets(a);
	a[0]=a[0]-'0';
	a[1]=a[1]-'0';
	b=a[0]/a[1];
	printf("%d",b);
}
*/















































/*#include<stdio.h>
void s(char*a,char*b,char*c){
	int d=0;
	if(*b=='*'){
		*a=(*b)*(*c);
		s(a,b+2,c+2);
	}
	if(*b=='/'){
		*a=(*b)/(*c);
		s(a,b+2,c+2);
	}
	if(*b=='-'){
		if(*(b+2)=='-'||*(b+2)=='+'){
			*a=(*b)-(*c);
			s(a,b+2,c+2);
		}
		else
			s(a+2,b+2,c+2);
	}
	if(*b=='+'){
		if(*(b+2)=='-'||*(b+2)=='+'){
			*a=(*b)-(*c);
			s(a,b+2,c+2);
		}
		else
			s(a+2,b+2,c+2);
	}
}
int main()
{
	char com[1005];
	gets(com);
	s(com+1,com+2,com+3);
	return 0;
}*/

