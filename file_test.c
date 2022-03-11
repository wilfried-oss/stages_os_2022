#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Format : %s <parameter1><parameter2>\n", argv[0]);
        return 1;
    }
    FILE *f1, *f2;
    int ret;
    f1 = fopen(argv[1], "r");
    if (f1 == NULL)
    {
        printf("Error, can't open %s\n", argv[1]);
        exit(1);
    }

    f2 = fopen(argv[2], "w");
    if (f2 == NULL)
    {
        fclose(f1);
        printf("Error, can't open %s\n", argv[2]);
        exit(2);
    }
    else
    {
        int current_char = 0;
        while (1)
        {
            current_char = fgetc(f1);
            fputc(current_char, f2);
            // printf("%c", current_char);
            if (current_char == EOF)
                break;
        }
    }
    printf("La copie s'est bien passée.\n");

    fclose(f1);
    fclose(f2);

    return 0;
}