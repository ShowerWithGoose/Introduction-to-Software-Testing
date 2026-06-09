#include<stdio.h>
#include<string.h>
int main(){
    int ch1[20]={-1}; // @@ Array size 20 may be insufficient for longer expressions, risking buffer overflow.
    char ch2[20]={'0'}; // @@ Array size 20 may be insufficient for longer expressions, risking buffer overflow.
    int i=0,j=0,len=0,x1=0,sum=0;
    while(1){
        scanf(" %d",ch1+i);
        if(ch1[i]!=-1){
            i++;
        }
        scanf(" %c",ch2+j);
        if(ch2[j]!='0'){
            j++;
        }
        if(ch2[j-1]=='='){ break; } // @@ Potential undefined behavior if j is 0 and scanf fails, accessing ch2[-1].
    }len=i;
 /* for(j=0;j<i;j++){
        printf("%d",ch1[j]);}
        printf(" %s",ch2);
        printf("%d ",i);*/
        x1=ch1[0];
        j=0;
        for(i=0;i<len;i++){
            if(ch2[i]=='/'){
                x1/=ch1[i+1];
            }
            if(ch2[i]=='*'){
                
                x1*=ch1[i+1];
                printf("%d\n",x1); // @@ Outputs intermediate calculation results, violating the output format requirement.
            }
            if(ch2[i]=='+'||ch2[i]=='='){
                ch1[j]=x1;
            
                ch2[j]='+';
                j++;
                x1=ch1[i+1]; // @@ Accesses ch1[i+1] which may be out of bounds when i is the last index (i == len-1).
            }
            if(ch2[i]=='-'){
                ch1[j]=x1;
            
                ch2[j]='-';
                j++;
                x1=ch1[i+1]; // @@ Accesses ch1[i+1] which may be out of bounds when i is the last index (i == len-1).
            }

        }sum=ch1[0];
        for(i=0;i<j-1;i++){
       //   printf("%d,%c\n",ch1[i],ch2[i]);
            if(ch2[i]=='+'){
                sum+=ch1[i+1];
            }
            if(ch2[i]=='-'){
                sum-=ch1[i+1];
            }
            
        }
        printf("%d",sum);
        return 0;

}