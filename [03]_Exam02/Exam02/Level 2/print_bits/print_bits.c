#include <unistd.h>

void	print_bits(unsigned char octet)
{
    int num = 8;
    unsigned char bit;

    while(num--)
    {
        bit = (octet >> num & 1) + '0';
        write(1, &bit, 1);
    }
}
/*
#include <stdio.h>
int main()
{
    unsigned char value = 5; // Binary: 10101010
    printf("Binary representation of %u: \n", value);
    print_bits(value);
    printf("\n");
    return 0;
}
*/