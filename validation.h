// #include<regex.h>
#include<ctype.h>
#define TRUE 1
#define FALSE 0

// Function Signature
int validateName(char []);

// Function Description

int validateName(char str[25]){
    int i = 0;
    // len = sizeof(str)/sizeof(str[0]);
    while(i < 25 && str[i] != '\0'){
        if(isdigit(str[i])){
            return FALSE;
        }
        i++;
    }
    return TRUE;
}
