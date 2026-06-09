#include<stdio.h>
#include<string.h>
char a[1000000];
int main(){
    
    int i,j,k,m,n,p,w;
    gets(a);    
    
    for(i=0;a[i]!='\0';i++){ @@ // Error: i starts from 0, but inside loop a[i-1] is accessed when i=0, causing out-of-bounds. Also, after string modification, loop index is not adjusted.
        if(a[i]=='-'){
            if((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9')){ @@ // Error: condition does not ensure both characters are in the same range (e.g., 'a' and 'Z' would pass incorrectly). Should check both ends for each range.
                if(a[i-1]<a[i+1]){
                    j=strlen(a);
                    p=a[i+1]-a[i-1]-2; @@ // Error: incorrect calculation for shift amount; should be (a[i+1]-a[i-1]-1) to account for characters to insert.
                    w=i;
                    k=a[i+1]-a[i-1]; @@ // Error: k is the difference, but number of characters to insert is (k-1). Loop from m=1 to k will duplicate the right character.
                    for(n=1;n<=j-i-2;n++){ @@ // Error: shift loop bounds and logic are incorrect; does not properly shift the remainder of the string.
                        a[i+n+1+p]=a[i+n+1]; @@ // Error: indices are wrong; this may overwrite or misplace characters.
                    }
                    for(m=1;m<=k;m++){ @@ // Error: loop should go up to k-1 to avoid duplicating the right character; also does not null-terminate after insertion.
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