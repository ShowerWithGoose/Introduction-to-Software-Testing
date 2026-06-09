#include <stdio.h>
#include <string.h>
char s[800], d[800],t[800];int num[800],tnu[800];
int main()
{ char c=' ';int j,k,i,p,nam=0,q,n=1;
gets(s);
for(j=k=0;s[j]!= '\0';j++)
	if(s[j]!=c)
	s[k++]=s[j];
	s[k]= '\0';//Ïû³ı¿Õ¸ñ 
int m=strlen(s);

int sum=1;


for(i=0,j=0,k=0,p=0;i<m;i++,j++){
	if(s[i]=='*'||s[i]=='/'||s[i]=='-'||s[i]=='+'||s[i]=='='){
		d[k++]=s[i];
	}
	if(s[i]>='0'&&s[i]<='9'){
		for (sum=1;sum<11;sum++){
			if(s[i+sum]>='0'&&s[i+sum]<='9'){
				continue;
			}int nam=0,q,n=1;
			 for (q = sum; q > 0; q--) {
                    nam += (s[i + q- 1] - '0') * n;
                    n *= 10;
                }
                num[p++]=nam;i+=sum-1;
                break;
                if(s[i+sum]<'0')
                break;
		}
	}
}int o=strlen(d);
    for(i=0,j=0;i<o+1;i++){
    	if(d[i]=='+'||d[i]=='-'){
    		tnu[j]=num[i];
    		t[j]=d[i];j++; 
		}else if(d[i]=='='){
		   	tnu[j]=num[i];
    		t[j]=d[i];j++;
		}else if(d[i]=='*'){
			num[i+1]*=num[i];
		}
    	else if(d[i]=='/'){
    		num[i+1]=num[i]/num[i+1];
		}
	}
int final=tnu[0];
for(i=0;i<strlen(t);i++){
	if(t[i]=='-'){
		final-=tnu[i+1];
	}else if(t[i]=='+'){
		final+=tnu[i+1];
	}
}printf("%d",final);
	



return 0;
}



