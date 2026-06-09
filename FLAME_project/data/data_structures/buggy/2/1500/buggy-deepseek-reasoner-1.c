#include<stdio.h>
#include<string.h>
int main(){
    int ch1[20]={-1};
    char ch2[20]={'0'};
    int i=0,j=0,len=0,x1=0,sum=0;
    while(1){
        scanf(" %d",ch1+i);
        if(ch1[i]!=-1){ @@ // Sentinel check may skip valid integer -1, causing incorrect input reading
            i++;
        }
        scanf(" %c",ch2+j);
        if(ch2[j]!='0'){
            j++;
        }
        if(ch2[j-1]=='='){
            break;
        }
    }len=i;
 /* for(j=0;j<i;j++){
        printf("%d",ch1[j]);}
        printf(" %s",ch2);
        printf("%d ",i);*/
        x1=ch1[0];
        j=0;
        for(i=0;i<len;i++){ @@ // Loop includes the '=' operator, causing out-of-bounds access and incorrect processing
            if(ch2[i]=='/'){
                x1/=ch1[i+1];
            }
            if(ch2[i]=='*'){
                
                x1*=ch1[i+1];
                printf("%d\n",x1); @@ // Unnecessary debug output produces extra result, causing Wrong Answer
            }
            if(ch2[i]=='+'||ch2[i]=='='){ @@ // Treating '=' as '+' is logically incorrect; also leads to out-of-bounds when i is the last operator
                ch1[j]=x1;
            
                ch2[j]='+';
                j++;
                x1=ch1[i+1]; @@ // Accesses ch1[i+1] out of bounds when i is the last operator (index len-1)
            }
            if(ch2[i]=='-'){
                ch1[j]=x1;
            
                ch2[j]='-';
                j++;
                x1=ch1[i+1]; @@ // Same out-of-bounds issue if this block were executed for the last operator (not in this test case, but still a latent error)
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