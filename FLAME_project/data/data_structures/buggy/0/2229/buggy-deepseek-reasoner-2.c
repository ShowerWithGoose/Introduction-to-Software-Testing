#include<stdio.h>
#include<string.h>
char a[1000000];
int main(){
    
    int i,j,k,m,n,p,w;
    gets(a);    
    
    for(i=0;a[i]!='\0';i++){
        if(a[i]=='-'){
            if((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9')){ // @@ The condition does not fully verify that both characters are within the same valid range and only checks the lower bound of the left character and the upper bound of the right character, allowing invalid pairs like 'a' and '0' to pass.
                if(a[i-1]<a[i+1]){
                    j=strlen(a);
                    p=a[i+1]-a[i-1]-2;
                    w=i;
                    k=a[i+1]-a[i-1];
                    for(n=1;n<=j-i-2;n++){ // @@ The loop runs forward and uses an incorrect bound; it should shift from the end backward to avoid overwriting, and the number of characters to shift should be j-i-1 rather than j-i-2.
                        a[i+n+1+p]=a[i+n+1]; // @@ Copying forward overwrites original characters before they are moved, corrupting the string.
                    }
                    for(m=1;m<=k;m++){
                        a[w]=a[i-1]+m;
                        w=w+1;
                    }
                }
            }
        }
    }
    printf("%s",a);
    return 0;
}