#include <stdio.h>
#include <stdlib.h>

void my_assert(int condition, const char *message, const char *file, int line, const char *func) {
    if (!condition) {
        fprintf(stderr, "%s:%d: %s: Assertion '%s' failed.\n", file, line, func, message);
        exit(1);
    }
}

#define my_assert(condition, message) \
    my_assert(condition, message, __FILE__, __LINE__, __func__)

void foo(int num) {
    my_assert(num >= 0 && num <= 100, "num is out of range");
    printf("foo: num = %d\n", num);
}

int main(int argc, char *argv[]) {
    int num;

    if (argc < 2) {
        fprintf(stderr, "Usage: assert_test aNumber\n(0 <= aNumber <= 100)\n");
        exit(1);
    }

    num = atoi(argv[1]);
    foo(num);

    return 0;
}

