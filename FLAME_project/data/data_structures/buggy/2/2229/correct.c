#include<stdio.h>
#include<string.h>
int main(){
	char a[10000],c[10000],d[10000];
	int f[10000],e[10000];
	int i=0,j,k,b,m,num=0,n,x=1,h=0,w,p,t,g,ans,r,q,s,o,u,v,ab,l;
	gets(a);
	q=strlen(a);
	for(j=0,k=0;j<q;j++){
		if(a[j]!=' '){
			c[k]=a[j];
			k++;
		}
		if(a[j]=='+'||a[j]=='-'){
			num++;
		}
	}
	for(i=0,m=0;i<k;i++){
		x=1;
		h=0;
		g=0;
		if(c[i]=='+'||c[i]=='-'||c[i]=='='){
			d[m]=c[i];
			m++;}
		else if(c[i]>='0'&&c[i]<='9'){
			d[m]=c[i];
			m++;
		}
		else if(c[i]=='*'){
			for(w=1;w<=m;w++){
				if(d[m-w]<'0'||d[m-w]>'9'){
					break;
				}
			}
			w--;
			for(p=1;;p++){
				if(c[i+p]<'0'||c[i+p]>'9'){
					break;
				}
			}
			p--;
			
			for(t=1;t<=w;t++){
				h=h+(d[m-t]-'0')*x;
				x=x*10;
			}
			x=1;
			for(l=p;l>=1;l--){
				g=g+(c[i+l]-'0')*x;
				x=x*10;
			}
			
				
				
			ans=h*g;
            r=ans;
            x=10;
			for(s=1;;s++){
				f[s]=r%x;
				r=r/x;
				
				if(r==0){
					break;
				}
			}
			for(j=1;j<=s;j++){
				d[m-w-1+j]=f[s-j+1]+'0';
			}
			
			i=i+p;
			m=m+s-w;
		}
		else if(c[i]=='/'){
			for(w=1;w<=m;w++){
				if(d[m-w]<'0'||d[m-w]>'9'){
					break;
				}
			}
			w--;
			for(p=1;;p++){
				if(c[i+p]<'0'||c[i+p]>'9'){
					break;
				}
			}
			p--;
			
			for(t=1;t<=w;t++){
				h=h+(d[m-t]-'0')*x;
				x=x*10;
			}
			x=1;
			for(l=p;l>=1;l--){
				g=g+(c[i+l]-'0')*x;
				x=x*10;
			}
			
				
				
			ans=h/g;
            r=ans;
            x=10;
			for(s=1;;s++){
				f[s]=r%x;
				r=r/x;
				
				if(r==0){
					break;
				}
			}
			for(j=1;j<=s;j++){
				d[m-w-1+j]=f[s-j+1]+'0';
			}
			
			i=i+p;
			m=m+s-w;
		}
	}

	for(i=0,n=0;d[i]!='=';i++){
		x=1;
		h=0;
		g=0;
		ab=1;
		if(d[i]>='0'&&d[i]<='9'){
			e[n]=d[i]-'0';
			n++;
			if(d[i+1]<'0'||d[i+1]>'9'){
				u=i;
				o=0;
				for(v=0;v<=u;v++){
					o=o+e[u-v]*ab;
					ab=ab*10;
				}
			}
		}
		else if(d[i]=='+'){
			
			for(p=1;;p++){
				if(d[i+p]=='+'||d[i+p]=='-'||d[i+p]=='='){
					break;
				}
			}
			p--;
			
			
			x=1;
			for(t=p;t>=1;t--){
				g=g+(d[i+t]-'0')*x;
				x=x*10;
			}
			o=o+g;
            
			
			
			i=i+p;
			
		}
		
		else if(d[i]=='-'){
			
			for(p=1;;p++){
				if(d[i+p]=='+'||d[i+p]=='-'||d[i+p]=='='){
					break;
				}
			}
			p--;
			
			
			x=1;
			for(t=p;t>=1;t--){
				g=g+(d[i+t]-'0')*x;
				x=x*10;
			}
			o=o-g;
            
			
			
			i=i+p;
			
		}
	}
	printf("%d",o);
	return 0;
}

