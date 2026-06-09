#include <stdio.h>
#include <stdlib.h>

int main()
{
  char a[1000],b[1000]={};
  int i,j,R,L,G,h;
  gets(a);
  j=0;
  for(i=0;i<=strlen(a);i++){
    if(a[i]=='-'){
            if(a[i+1]<='z'&&a[i+1]>='a'&&a[i-1]<='z'&&a[i-1]>='a'&&a[i+1]>a[i-1]){
                    R=a[i+1];
                    L=a[i-1];
                    for(h=1;h<R-L;h++){
                            G=L+h;
                        b[j]=G;
                        j++;
                    }
        }
            else if(a[i+1]<='Z'&&a[i+1]>='A'&&a[i-1]<='Z'&&a[i-1]>='A'&&a[i+1]>a[i-1]){
                    R=a[i+1];
                    L=a[i-1];
                    for(h=1;h<R-L;h++){
                            G=L+h;
                        b[j]=G;
                        j++;
                    }
        }
            else if(a[i+1]<='9'&&a[i+1]>='0'&&a[i-1]<='9'&&a[i-1]>='0'&&a[i+1]>a[i-1]){
                    R=a[i+1];
                    L=a[i-1];
                    for(h=1;h<R-L;h++){
                            G=L+h;
                        b[j]=G;
                        j++;
                    }
        }
            else {
                b[j]=a[i];
                j++;
            }
    }
    else {
        b[j]=a[i];
        j++;
    }
  }
  printf("%s",b);

}



