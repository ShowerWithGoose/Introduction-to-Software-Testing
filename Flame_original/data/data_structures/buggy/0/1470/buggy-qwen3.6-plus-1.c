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
        if(a[i]=='-'&&a[i-1]<a[i+1]){
            if((a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>='0'&&a[i+1]<='9')||(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[i+1]<='Z')||(a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z')){
                for(j=1;j<=a[i+1]-a[i-1];j++){ // @@ The condition j<=a[i+1]-a[i-1] causes the character a[i+1] to be printed inside this loop, and it will be printed again in the next iteration of the outer loop, leading to a duplicate character. It should be j<a[i+1]-a[i-1].
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