#include<stdio.h>
#include<math.h>
#include<string.h>
char in[111],out[111];
int main() {
	gets(in);
	if(in[0]=='0') {
		int i=0,j=0,t=0;
		

		for(int k=2; k<strlen(in); k++) {
			if(in[k]=='0'&&i==0) continue;
			else {
				i++;

				out[j]=in[k];
				j++;
				if(i==1&&in[k+1]!='\0') {
					out[j]='.';
					j++;
				}
			}
		}
		for(int k=2; in[k]=='0'; k++,t++);
		t++;
		out[j]='e';
		j++;
		out[j]='-';
		j++;
		if(t<10) out[j]='0'+t;
		else {
			out[j+1]='0'+(t)%10;
			out[j]='0'+(t)/10%10;
		}
	} else {
		int j=0,t=0;
		out[j]=in[0];
		j++;
		out[j]='.';
		j++;
		for(int k=0; in[k]!='.'; k++,t++);
		t--;
		if(in[1]=='.') {
			for(int k=2; k<strlen(in); k++) {
				out[j]=in[k];
				j++;
			}
		} else {
			for(int k=1; k<strlen(in); k++) {
				if(in[k]=='.') continue;
				out[j]=in[k];
				j++;
			}
		}
		out[j]='e';
		j++;
		if(t<10) out[j]='0'+t;
		else {
			out[j+1]='0'+t%10;
			out[j]='0'+t/10%10;
		}

	}

	puts(out);




	return 0;
}

