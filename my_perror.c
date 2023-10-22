#include <stdio.h>
#include <string.h>
#include <errno.h>

void my_perror(const char *message) {
    fprintf(stderr, "%s: %s\n", message, strerror(errno));
}

int main(int argc, char *argv[]) {
    FILE *file;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s file_name\n", argv[0]);
        return 1;
    }

    if ((file = fopen(argv[1], "r")) == NULL) {
        my_perror("fopen");
        return 1;
    }

    printf("Open a file \"%s\".\n", argv[1]);

    fclose(file);
    return 0;
}
