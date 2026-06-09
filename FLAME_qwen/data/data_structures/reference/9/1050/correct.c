#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include <math.h>
#include <stdlib.h>
int main()
{
int l[105],x[105],y[105],m[105],n[105],max,i,j,s,w,r,f;
scanf("%d",&s);
for(i=0;i<s;i++)
scanf("\n%d%d%d%d",&x[i],&y[i],&m[i],&n[i]);
for(i=0;i<s;i++){
	for(j=i+1;j<s;j++){
		if(x[i]==x[j]&&y[i]==y[j]){
			if(m[j]<m[i]){
				w=m[j];
				r=n[j];
				m[j]=m[i];
				n[j]=n[i];
				m[i]=w;
				n[i]=r;
			}
		}
	}
}
for(i=0;i<s;i++){
	w=m[i];
	r=n[i];
	l[i]=1;
	for(j=0;j<s;j++){
	
	if(w==x[j]&&r==y[j]){
		w=m[j];
		r=n[j];
		l[i]++;	
		j=-1;	
	}
}
}
max=1;
f=1;
for(i=0;i<s;i++){
	if(max<l[i]){
	f=i+1;
	max=l[i];
}
}
printf("%d %d %d",max,x[f-1],y[f-1]);
return 0;
}





