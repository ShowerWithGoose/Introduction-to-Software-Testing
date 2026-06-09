#include<stdio.h>  
#include<string.h>
//char s1[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
//char s2[]={"abcdefghijklmnopqrstuvwxyz"};
//char s3[]={"0123456789"};
char wxc[1000],a[1000]; 
int main(){

        int j=0;
		scanf("%s",&wxc);
	for(int i=0;i<strlen(wxc);i++){
//		if(wxc[i]>='a'&&wxc[i]<='z')
//		print("%c",wxc[i])
//		else if(wxc[i]>='A'&&wxc[i]<='Z')
//		print("%c",wxc[i])
//		else if(wxc[i]>='0'&&wxc[i]<='9')
//		print("%d",wxc[i])
//		else 
		if(wxc[i]=='-'&&wxc[i-1]<wxc[i+1]&&((wxc[i-1]>='a'&&wxc[i+1]<='z')||(wxc[i-1]>='A'&&wxc[i+1]<='Z')||(wxc[i-1]>='0'&&wxc[i+1]<='9'))) {
			char ch;
			for(ch=wxc[i-1]+1;ch<=wxc[i+1];ch++,j++){
				a[j]=ch;//a-c
			}
			i++;
		}else{
			a[j]=wxc[i];
			j++;
		}
//			if s[i1] s[i+1]
//			print("-")
//			else
}
		printf("%s",a);
    return 0;

}




