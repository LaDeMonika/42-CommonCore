unsigned char	reverse_bits(unsigned char octet)
{
	int		i = 8;
	unsigned char	res = 0;

	while (i > 0)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		i--;
	}
	return (res);
}
/* res: 0 = 0 * 2 + (5 % 2) = 1 */      /* oct: 5 = 5/2 = 2 */      /* i: 8 */
/* res: 1 = 1 * 2 + (2 % 2) = 2 */      /* oct: 2 = 2 / 2 = 1 */    /* i: 7 */
/* res: 2 = 2 * 2 + (1 % 2) = 5 */      /* oct: 1 = 1 / 2 = 0 */    /* i: 6 */
/* res: 5 = 2 * 5 + (0 % 2) = 10 */     /* oct: 0 = 0 / 2 = 0*/     /* i: 5 */
/* res: 10 = 2 * 10 + (10 % 2) = 20 */  /* oct: 10 = 10 / 2 = 5 */  /* i: 4 */
/* res: 20 =... */                      /* oct: */                  /* i: 3 */
/* res: 40 =... */                      /* oct: */                  /* i: 2 */
/* res: 80 =... 160 */                  /* oct: */                  /* i: 1 */
/* res: 160 = X done */                 /* oct: */                  /* i: 0 */

/*
#include <stdio.h>
int main()
{
    unsigned char original = 160; // Binary: 10101010
    unsigned char reversed = reverse_bits(original); // Expected result: 85 (Binary: 01010101)

    printf("Original: %u (Binary: ", original);
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (original >> i) & 1);
    }
    printf(")\n");

    printf("Reversed: %u (Binary: ", reversed);
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (reversed >> i) & 1);
    }
    printf(")\n");

    return 0;
}
*/