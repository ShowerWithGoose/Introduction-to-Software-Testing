//
//  main.c
//  DS1-1
//
//  Created by  on 2022/3/5.
//

#include <stdio.h>

int main() {
    char s[1000];
    char s1[1000];
    int i=0,j=0,k=0;
    scanf("%s",s);
    for(i=j=0;s[i]!='\0';i++){
        s1[j++]=s[i];
        if(s[i]=='-'){
            if(s[i-1]>='0'&&s[i-1]<='9'){
                if(s[i+1]>='0'&&s[i+1]<='9'){
                    j=j-2;
                    for(k=0;k<(s[i+1]-s[i-1]);k++){
                        s1[j++]=s[i-1]+k;
                    }
                    k=0;
                }
            }
            
            else if(s[i-1]>='A'&&s[i-1]<='Z'){
                if(s[i+1]>='A'&&s[i+1]<='Z'){
                    j=j-2;
                    for(k=0;k<(s[i+1]-s[i-1]);k++){
                        s1[j++]=s[i-1]+k;
                    }
                    k=0;
                }
                    
            }
            
            else if(s[i-1]>='a'&&s[i-1]<='z'){
                if(s[i+1]>='a'&&s[i+1]<='z'){
                    j=j-2;
                    for(k=0;k<(s[i+1]-s[i-1]);k++){
                        s1[j++]=s[i-1]+k;
                    }
                    k=0;
                }
                
            }
          
        }
    }
    printf("%s",s1);
        
    return 0;
}

