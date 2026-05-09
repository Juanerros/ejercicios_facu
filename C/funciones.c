#include <stdio.h>

char str[5] = "print";

void helloworld(char[]);

int main() {
    helloworld(str);
    return 0;
}

void helloworld(char str[5]) {
    printf("%s", str);
}