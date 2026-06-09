#include<stdio.h>

int main()
{
	char data[110],result[110];
	int ji=0,OriginLocation=0,i,ri=0;
	scanf("%s",data);
	if(data[0]=='0'){
		OriginLocation=2;
		while(data[OriginLocation]=='0') OriginLocation++;
		ji=OriginLocation-1;
		if(data[OriginLocation+1]=='\0')
			printf("%ce-%d",data[OriginLocation],ji);
		else{
			result[0]=data[OriginLocation];result[1]='.';
			i=OriginLocation+1;ri=2;
			while(data[i]!='\0')
				result[ri++]=data[i++];
			result[ri]='\0';
			printf("%se-%d",result,ji);
		}
	}
	else{
		OriginLocation=1;
		while(data[OriginLocation]!='.') OriginLocation++;
		ji=OriginLocation-1;
		result[0]=data[0];result[1]='.';
		i=1;ri=2;
		while(data[i]!='\0'){
			if(data[i]!='.')
				result[ri++]=data[i];
			i++;
		}
		result[ri]='\0';
		printf("%se%d",result,ji);
	}
	return 0;
}
