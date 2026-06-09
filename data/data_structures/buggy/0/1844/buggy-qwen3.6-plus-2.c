#include<stdio.h>
int main()
{
    char s,a[100];
    int i,j,k,delta;
    for(i=0;scanf("%c",&s)!=EOF;i++){
        a[i]=s;
    }
    for(j=0;j<=i;j++){ // @@ Loop condition j<=i accesses uninitialized a[i], should be j<i.
        if(a[j]!='-'){
            printf("%c",a[j]);
        }
        else if(a[j]=='-'){ // @@ Missing else branch to print '-' when expansion conditions are not met.
            if((a[j-1]>='0'&&a[j+1]<='9'&&a[j-1]<a[j+1])||(a[j-1]>='a'&&a[j+1]<='z'&&a[j-1]<a[j+1])||(a[j-1]>='A'&&a[j+1]<='Z'&&a[j-1]<a[j+1])){ // @@ Incorrect range check logic; only verifies lower bound for left char and upper bound for right char, failing to ensure both characters belong to the same valid range. Also lacks boundary checks for j-1 and j+1.
                delta=a[j+1]-a[j-1];
                for(k=1;k<=delta-1;k++){
                printf("%c",a[j-1]+k);
                }
                
                
            }
        }
    }
    return 0;
}