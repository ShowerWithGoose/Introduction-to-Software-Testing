#include <stdio.h>

void expandString(char *input, char *output) {
    int i = 0, j = 0;
    while (input[i] != '\0') {
        if (input[i] == '-' && i > 0 && input[i + 1] != '\0') {
            char start = input[i - 1];
            char end = input[i + 1];
            
            // Check if both characters surrounding the '-' are valid for expansion
            if (((start >= 'a' && start <= 'z') && (end >= 'a' && end <= 'z') && end > start) ||
                ((start >= 'A' && start <= 'Z') && (end >= 'A' && end <= 'Z') && end > start) ||
                ((start >= '0' && start <= '9') && (end >= '0' && end <= '9') && end > start)) {
                for (char c = start + 1; c < end; ++c) {
                    output[j++] = c;
                }
                ++i; // Increment i to skip the end character // @@ This line incorrectly skips the character immediately following '-', causing it to be omitted from the final output. The character should be processed normally in the next iteration, so this increment should be removed.
            } else {
                output[j++] = input[i];
            }
        } 
        else 
        {
            output[j++] = input[i];
        }
        ++i; // Increment i for the next character
    }
    output[j] = '\0'; // Null-terminate the output string
}

int main() {
    char input[100];
    char output[200]; // Assuming the output can be twice the length of input for expansion
    
  
    fgets(input, sizeof(input), stdin); // Read input from the keyboard
    
    expandString(input, output);
    
    printf("%s\n", output);

    return 0;
}