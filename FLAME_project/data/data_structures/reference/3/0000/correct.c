#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    char num_in[1024];
    char num_out[1024];
    int type_in = 0;
    int dpoint_location = 0;
    int cnt_zeros_after_dpoint = 0;

    scanf("%s", num_in);

    // judge the input: <1 decimal / >1 decimal
    int i = 0;
    int j = 1;
    for (i = 0; i < strlen(num_in); i++){
        if(num_in[i] == '.'){
            dpoint_location = i;
            if(i == 1 && num_in[0] == '0'){  // <1 decimal
                type_in = 1;
                while ((num_in[i + j] == '0') && ((i + j) < strlen(num_in))){
                    cnt_zeros_after_dpoint++;
                    j++;
                }
            }
            else{  // >1 decimal
                type_in = 2;
            }
            break;
        }
    }

    if(type_in == 1){
        num_out[0] = num_in[dpoint_location + cnt_zeros_after_dpoint + 1];
        if((dpoint_location + cnt_zeros_after_dpoint + 1) < (strlen(num_in) - 1)){
            num_out[1] = '.';
            for (i = 2; i < (strlen(num_in) - dpoint_location - cnt_zeros_after_dpoint); i++)
                num_out[i] = num_in[dpoint_location + cnt_zeros_after_dpoint + i];
        }
        else{
            i = 1;
        }
        num_out[i] = 'e';
        num_out[i+1] = '-';
        printf("%s%d\n", num_out, (cnt_zeros_after_dpoint + 1));
    }
    else if(type_in == 2){
        num_out[0] = num_in[0];
        num_out[1] = '.';
        for (i = 2; i < (dpoint_location + 1); i++)
            num_out[i] = num_in[i - 1];
        for (; i < strlen(num_in); i++)
            num_out[i] = num_in[i];
        num_out[i] = 'e';
        printf("%s%d\n", num_out, (dpoint_location - 1));
    }

    return 0;
}

