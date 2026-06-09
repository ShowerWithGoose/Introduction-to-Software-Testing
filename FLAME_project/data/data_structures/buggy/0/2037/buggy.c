#include <stdio.h>

int main (){
    char s[200]={0},S[500]={0};
    scanf ("%s", s);
    for (int i=0,j=0;s[i]!='\0';i++,j++){
    	S[j]=s[i];
		if (s[i+1]=='-'){
			if (s[i]>='A'&&s[i]<='Z'&&s[i+2]>='A'&&s[i+2]<='Z'){
				for (char ch=s[i];ch<s[i+2];j++,ch++){
					S[j] = ch;
				}
			}else if (s[i]>='a'&&s[i]<='z'&&s[i+2]>='a'&&s[i+2]<='z'){
				for (char ch=s[i];ch<s[i+2];j++,ch++){
					S[j] = ch;
				}				
			}else if (s[i]>='0'&&s[i]<='9'&&s[i+2]>='0'&&s[i+2]<='9'){
				for (char ch=s[i];ch<s[i+2];j++,ch++){
					S[j] = ch;
				}				
			}else {
				j++;
			}
			i++;j--;
		}
	}
	printf ("%s", S);
	return 0;
}

