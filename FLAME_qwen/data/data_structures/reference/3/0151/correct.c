#include<stdio.h>
#include<math.h>
#include<string.h>
char in[111],out[111];
int main() {
	gets(in);
	if(in[0]=='0') {
		int q=0,t=0,num=0;
		

		for(int i=2; i<strlen(in); i++) {
			if(in[i]=='0'&&q==0) continue;
			else {
				q++;

				out[t]=in[i];
				t++;
				if(q==1&&in[i+1]!='\0') {
					out[t]='.';
					t++;
				}
			}
		}
		for(int i=2; in[i]=='0'; i++,num++);
		num++;
		out[t]='e';
		t++;
		out[t]='-';
		t++;
		if(num<10) out[t]='0'+num;
		else {
			out[t+1]='0'+(num)%10;
			out[t]='0'+(num)/10%10;
		}
	} else {
		int t=0,num=0;
		out[t]=in[0];
		t++;
		out[t]='.';
		t++;
		for(int i=0; in[i]!='.'; i++,num++);
		num--;
		if(in[1]=='.') {
			for(int i=2; i<strlen(in); i++) {
				out[t]=in[i];
				t++;
			}
		} else {
			for(int i=1; i<strlen(in); i++) {
				if(in[i]=='.') continue;
				out[t]=in[i];
				t++;
			}
		}
		out[t]='e';
		t++;
		if(num<10) out[t]='0'+num;
		else {
			out[t+1]='0'+num%10;
			out[t]='0'+num/10%10;
		}

	}

	puts(out);




	return 0;
}

