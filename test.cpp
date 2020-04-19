#include ""

int main()
{
    int i1 = 1, i2 = -1;

    char *ptr;

    ptr = (char *)&i1;

    for (int i = 0; i < sizeof(i1); i++)
    {
        printf("%x ", ptr[i]);
    }
    printf("i1\n");

    ptr = (char *)&i1;
    for (int i = 0; i < sizeof(i2); i++)
    {
        printf("%x ", ptr[i]);
    }
    printf("i2\n");
}