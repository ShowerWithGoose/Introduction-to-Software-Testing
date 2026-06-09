#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char a[1010];
    int i,j;
    
    gets(a);
    
    for(i=0;i<strlen(a);i++){
        if(a[i]=='-'&&a[i-1]<a[i+1]){ // @@ out-of-bounds access when i=0 or i at end; no check for bounds
            if((a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>='0'&&a[i+1]<='9')||(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[i+1]<='Z')||(a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z')){
                for(j=1;j<=a[i+1]-a[i-1];j++){ // @@ loop includes the end character, causing it to be printed twice
                    printf("%c",a[i-1]+j);
                }
            }
            else{
                printf("-");
            }
        }
        else{
            printf("%c",a[i]);
        }
    }
    return 0;
}