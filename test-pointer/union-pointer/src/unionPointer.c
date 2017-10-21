// https://stackoverflow.com/questions/346536/difference-between-a-structure-and-a-union/19775707#19775707

int main(int argc, char **argv) {
    union {
        short   s;
        char    c[sizeof(short)];
    } un;

    un.s = 0x0102;

    if (sizeof(short) == 2) {
        if (un.c[0] == 1 && un.c[1] == 2)
            printf("big-endian\n");
        else if (un.c[0] == 2 && un.c[1] == 1)
            printf("little-endian\n");
        else
            printf("unknown\n");
    } else
        printf("sizeof(short) = %d\n", sizeof(short));

    exit(0);
}
// Program from Unix Network Programming Vol. 1 by Stevens.