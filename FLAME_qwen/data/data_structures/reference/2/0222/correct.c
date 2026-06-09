#include <stdio.h>
#include <string.h>
char s[10000];
int i,j,k,tmp,num=0,a[10000][2],b[10000],result;
int main(){
	gets(s);
	for(i=j=0;s[i]!='\0';i++){
		if(s[i]!=' ')
		s[j++]=s[i];
	}
	s[j-1]='+';
	s[j]='\0';
	for(i=j=0;s[i]!='\0';i++){
		if(s[i]=='+'){
			a[j][0]=i;
			a[j][1]=0;
			num++;
			s[i]='*';
			j++;
		}		
		if(s[i]=='-'){
			a[j][0]=i;
			a[j][1]=1;
			num++;
			s[i]='*';
			j++;
		}		    
	}
	j+=1;
	for(j;j>=1;j--){
		b[j]=1;
	}
	b[0]=0;
    for(i=0;s[i]>='0'&&s[i]<='9';i++){
    	b[0]*=10;
    	b[0]+=s[i]-'0';
	}
			for(i;i<a[0][0];i++){
		if(s[i]=='*'){tmp=0;
			for(k=i+1;s[k]!='*'&&s[k]!='/';k++){
				tmp*=10;
				tmp+=s[k]-'0';
			}
			b[0]*=tmp;
			i=k-1;
		}
	    else{tmp=0;
			for(k=i+1;s[k]!='*'&&s[k]!='/';k++){
				tmp*=10;
				tmp+=s[k]-'0';
			}
			b[0]/=tmp;
			i=k-1;
		}	    
	}
	for(j=0;j<num;j++){
		for(i=a[j][0];i<a[j+1][0];i++){
		if(s[i]=='*'){tmp=0;
			for(k=i+1;s[k]!='*'&&s[k]!='/';k++){
				tmp*=10;
				tmp+=s[k]-'0';
			}
			b[j+1]*=tmp;
			i=k-1;
		}
	    else{tmp=0;
			for(k=i+1;s[k]!='*'&&s[k]!='/';k++){
				tmp*=10;
				tmp+=s[k]-'0';
			}
			b[j+1]/=tmp;
			i=k-1;
		}	    
	}
	}
	result=b[0];	
	for(i=0;i<num-1;i++){
		if(a[i][1]==0)
		result+=b[i+1];
		else
		result-=b[i+1];
	}
	printf("%d",result);
	return 0;
}

