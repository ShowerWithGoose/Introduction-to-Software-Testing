#include<stdio.h>
#include<string.h>
int main(){
	char a[1001],b[1001];
	gets(a);
	int dot=0,n=0,i,j,t;
	for(i=0;a[i];i++){
		if(a[i]=='.'){
			dot=i;
			break;
		}
	}
	for(i=0;a[i]!='\0';i++){
		if(a[i]>='1'&&a[i]<='9'){
			n=i;
			break;
		}
	}
	t=dot-n-1;
	if(strlen(a)-n>1){
		if(t<0){
			t++;
			b[0]=a[i];
			b[1]='.';
			for(i=n+1,j=2;a[i];i++,j++){
				b[j]=a[i];
			}
			b[j]='e';
			b[j+1]='-';
			if(t>-10) b[j+2]=(char)-t+48;
			else if(t<=-10){
				b[j+2]=(char)(-t)/10+48;
				b[j+3]=(char)(-t)%10+48;
			}	
		}
		else if(t>=0){
			b[0]=a[i];
			b[1]='.';
			for(i=n+1,j=2;a[i];i++){
				if(i!=dot){
					b[j]=a[i];
					j++;
				}
			}
			b[j]='e';
			if(t<10) b[j+1]=(char)t+48;
			else{
				b[j+1]=(char)t/10+48;
				b[j+2]=(char)t%10+48;
			}	
		}
	}
	else{
		if(t<0){
			t++;
			b[0]=a[i];
			for(i=n+1,j=1;a[i];i++,j++){
				b[j]=a[i];
			}
			b[j]='e';
			b[j+1]='-';
			if(t>-10) b[j+2]=(char)-t+48;
			else if(t<=-10){
				b[j+2]=(char)(-t)/10+48;
				b[j+3]=(char)(-t)%10+48;
			}	
		}
		else if(t>=0){
			b[0]=a[i];
			for(i=n+1,j=1;a[i];i++){
				if(i!=dot){
					b[j]=a[i];
					j++;
				}
			}
			b[j]='e';
			if(t<10) b[j+1]=(char)t+48;
			else{
				b[j+1]=(char)t/10+48;
				b[j+2]=(char)t%10+48;
			}	
		}
	}
	puts(b);
} 

