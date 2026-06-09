#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main(){
    char a[100],s[100];
    int p[100],q[100],r[100];
    int i,j,k,m,n,t,b,d,f,m2,n2;
    gets(a);
    for(t=0;t<100;t++){
        p[t]=0;
        q[t]=0;
    }
    for(i=0,j=0;i<strlen(a);i++){
        if(!isspace(a[i])){
            s[j++]=a[i];
        }
    }
    for(k=0;k<j;k++){
        if(s[k]=='+'||s[k]=='-'||s[k]=='*'||s[k]=='/'){
            break;
        }
    }
    if(k==j){
        for(t=0,b=0;t<j-1;t++){
            b=b*10+(s[t]-'0');
        }
        printf("%d",b);
        return 0;
    }
    else{
        for(m=0,n=0;m<j-1;m++){
            if(!isdigit(s[m])){
                p[n++]=m;
            }
        }
        for(t=0;t<p[0];t++){
            q[0]=q[0]*10+(s[t]-'0');
        }
        for(t=p[n-1]+1;t<j-1;t++){
            q[n]=q[n]*10+(s[t]-'0');
        }
        for(d=1;d<n;d++){
            for(t=p[d-1]+1;t<p[d];t++){
                q[d]=q[d]*10+(s[t]-'0');
            }
        }
        for(t=0;t<n;t++){
            if(s[p[t]]=='*'){
                q[t+1]=q[t+1]*q[t];
                q[t]=0;
            }
            if(s[p[t]]=='/'){
                q[t+1]=q[t]/q[t+1];
                q[t]=0;
            }
        }
        for(m2=0,n2=0;m2<n;m2++){
            if(s[p[m2]]=='+'||s[p[m2]]=='-'){
                r[n2++]=m2;
            }
        }
        r[n2]=n;
        for(t=0;t<n2;t++){
            if(s[p[r[t]]]=='-'){
            	for(d=r[t]+1;d<=r[t+1];d++){
            		q[d]=-q[d];
				}
            }
        }
		for(t=0,f=0;t<=n;t++){
            f+=q[t];
        }
        printf("%d",f);
        return 0;    
		}
    }




