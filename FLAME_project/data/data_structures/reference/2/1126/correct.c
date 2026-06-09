#include <stdio.h>
#include <string.h>
char a[1001],b[1001];
int i,s[1001],l,o,f,m[1001],j=1,k,q,u[1001],z,sum=0,zj[1001],w,e;
int main(){
	while(scanf("%c",&a[i])!=EOF){
		i+=1;
	}
	for(o=0;o<i;o++){
		if(a[o]=='*'||a[o]=='/'||a[o]=='+'||a[o]=='-'||a[o]=='=')
		{
		b[l]=a[o];
		s[l]=o;
		l++;
	}
	
	}
	for(k;k<l;k++){
		f=s[k]-1;
		if(k==0)
		for(f;f>=0;f--){
			if(a[f]==32)continue;
			else{
			m[k]=(a[f]-'0')*j+m[k];
			j=j*10;
		}
		}
		else 
		for(f;f>s[k-1];f--){
			if(a[f]==32)continue;
			else{
			m[k]=(a[f]-'0')*j+m[k];
			j=j*10;
		}
		}
		j=1;
	}
	i=0;
	for(q;q<k;q++){
		if(b[q]=='-'||b[q]=='+'||b[q]=='=')
		{
		u[i]=q;
		i++;
	}
		
	}
	for(z=0;z<i;z++){
		f=u[z];
		if(z==0)
		for(w=0;w<f+1;w++)
		{
			if(w==0)
			zj[z]=m[w]+zj[z];
			if(b[w]=='*')
			zj[z]=m[w+1]*zj[z];
			if(b[w]=='/')
			zj[z]=zj[z]/m[w+1];
		}
		else
		for(w=u[z-1]+1;w<f+1;w++){
			if(w==u[z-1]+1)
			zj[z]=m[w]+zj[z];
			if(b[w]=='*')
			zj[z]=m[w+1]*zj[z];
			if(b[w]=='/')
			zj[z]=zj[z]/m[w+1];		
		}
		e=u[z];
		if(z==0)sum=sum+zj[z];
		else {
		e=u[z-1];
		if(b[e]=='-')
		sum=sum-zj[z];
		else if(b[e]=='+')
		sum=sum+zj[z];
	}
	}
	printf("%d",sum);
}




