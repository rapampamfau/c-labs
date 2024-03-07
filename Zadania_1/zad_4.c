#include <stdio.h>

int main() {
    for(int i = 1; i <= 200; i++) {
        if (i % 5 == 0 && i % 7 == 0) {
            printf("FooBar");
        } else if (i % 7 == 0) {
            printf("Bar");
        } else if (i % 5 == 0) {
            printf("Foo");
        } else {
            printf("%d ", i);
        }

        printf("\n");
        
    }
    return 0;
}