#include<stdio.h>
#include<math.h>
#include<string.h>
char in[111],out[111];
int main() {
	gets(in);
	if(in[0]=='0') {
		int ct=0,j=0,num=0;
		

		for(int q=2; q<strlen(in); q++) {
			if(in[q]=='0'&&ct==0) continue;
			else {
				ct++;

				out[j]=in[q];
				j++;
				if(ct==1&&in[q+1]!='\0') {
					out[j]='.';
					j++;
				}
			}
		}
		for(int q=2; in[q]=='0'; q++,num++);
		num++;
		out[j]='e';
		j++;
		out[j]='-';
		j++;
		if(num<10) out[j]='0'+num;
		else {
			out[j+1]='0'+(num)%10;
			out[j]='0'+(num)/10%10;
		}
	} else {
		int j=0,num=0;
		out[j]=in[0];
		j++;
		out[j]='.';
		j++;
		for(int q=0; in[q]!='.'; q++,num++);
		num--;
		if(in[1]=='.') {
			for(int q=2; q<strlen(in); q++) {
				out[j]=in[q];
				j++;
			}
		} else {
			for(int q=1; q<strlen(in); q++) {
				if(in[q]=='.') continue;
				out[j]=in[q];
				j++;
			}
		}
		out[j]='e';
		j++;
		if(num<10) out[j]='0'+num;
		else {
			out[j+1]='0'+num%10;
			out[j]='0'+num/10%10;
		}

	}

	puts(out);




	return 0;
}

