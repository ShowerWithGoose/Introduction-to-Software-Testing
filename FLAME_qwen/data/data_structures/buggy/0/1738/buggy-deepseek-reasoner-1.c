#include <stdio.h>

void expandString(char *str) {
    char expanded[1000]; 
    int j = 0; 
    int i = 0;

    while (str[i] != '\0') {
        
        char prev = str[i-1]; // @@ Accessing str[-1] when i==0 leads to undefined behavior.
        
        char current = str[i];
        
        char next = str[i+1];
        
        if (current == '-' && 
            ((prev >= 'a' && prev <= 'z' && next >= 'a' && next <= 'z') || 
             (prev >= 'A' && prev <= 'Z' && next >= 'A' && next <= 'Z') || 
             (prev >= '0' && prev <= '9' && next >= '0' && next <= '9')) && 
             next > prev && 
             ((prev >= 'a' && next <= 'z') || 
              (prev >= 'A' && next <= 'Z') || 
              (prev >= '0' && next <= '9'))) {
           
            for (char c = prev + 1; c <= next; c++) {
                expanded[j++] = c;
            }
            i++;
        } else {
            
            expanded[j++] = str[i];
        }

        i++;
    }

    expanded[j] = '\0'; 
    printf("%s\n", expanded);
}

int main() { // @@ Duplicate main function, causing compilation error.
    char str[1000];
    
    scanf("%s", str);

    expandString(str);

    return 0;
}


int main() { // @@ Duplicate main function, causing compilation error.
    char str[1000];
    scanf("%s", str);
    expandString(str);
    return 0;
}