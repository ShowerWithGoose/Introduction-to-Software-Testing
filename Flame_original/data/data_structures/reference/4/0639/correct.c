#include <stdio.h>
#include <string.h>
char a[100][20];
void r(char a[100][20],int n){
    char x[20];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(strcmp(a[i],a[j])>0){
                strcpy(x,a[j]);
                strcpy(a[j],a[i]);
                strcpy(a[i],x);
            }
        }
    }
}
void x(char a[100][20],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<strlen(a[i]);j++){
			if(a[i][j]>='A'&&a[i][j]<='Z'){
				a[i][j]=a[i][j]+'a'-'A';
			}
		}
	}
}
int main(){
    FILE *fp;
    fp=fopen("article.txt","r");
    char c;
    int i=0,j=0,n;
    c=fgetc(fp);
    while(c!=EOF){
        if(c>='a'&&c<='z'){
            a[i][j]=c;
            j++;
        }
        else if(c>='A'&&c<='Z'){
        	a[i][j]=c;
            j++;
		}
        else{
            a[i][j] = '\0';
            j=0;
            i++;
        }
        c=fgetc(fp);
    }
    n=i;
    x(a,n);
    r(a,n);
    int m[105]={0},b;
    for(i=0;i<n;i++){
        b=0;
        m[i]=1;
        for(j=i+1;j<n;j++){
            if (strcmp(a[i],a[j])==0){
                m[i]++;
                a[j][0]='\0';
                b=1;
            }
            if(a[j][0]!='\0'){
                if(b==1){
                    i=j-1;
                }
                break;
            }
        }
    }
    for(i=0;i<n;i++){
        if(a[i][0]!='\0'){
            printf("%s %d\n",a[i],m[i]);
        }
    }
    fclose(fp);
    return 0;
}

