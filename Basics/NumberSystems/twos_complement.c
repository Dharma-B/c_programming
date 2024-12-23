/* Two's complement is a way to represent negative numbers in binary, which
 * makes arithmetic operations (like addition and subtraction) straightforward
 * for computers.
 *
 * Computers can’t directly represent negative numbers using only 0s and 1s.
 * Two's complement solves this by:
 * Using the Most Significant Bit (MSB) as a "sign bit":
 * 0 = Positive number.
 * 1 = Negative number.
 *
 * To Find the Two's Complement:
 *
 * Step 1: Invert all bits (flip 0 to 1, and 1 to 0).
 * Step 2: Add 1 to the result.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void twos_complement(int number, int bit_width);
int is_numeric(const char* str);

int main(int argc, char** argv) {
	if (argc != 3) {
		printf("Usage: 2s_complement <number> <bit_width>\n");
		return 1;
	}

	/* Validate input */
	if (!is_numeric(argv[1])) {
		printf("Error: Input must be a positive integer.\n");
		return 1;
	}

	int number = atoi(argv[1]);
	int bit_width = atoi(argv[2]);
	if (bit_width != 8 && bit_width != 16 && bit_width != 32) {
		printf("Error: bit_width should be 8 or 16 or 32\n");
		return 1;
	}

	printf("Two's complement of %d (%d-bit): ", number, bit_width);
	twos_complement(number, bit_width);
	printf("\n");
	return 0;
}

void twos_complement(int number, int bit_width) {
	/* BIT MASK EXAMPLE
	 *  _________________________________________________________________________
	 * |bit_width 	1 << bit_width	(1 << bit_width) - 1	Binary Representation|
	 * |     3		8		7			00000111     |
	 * |     5		32		31			00011111     |
	 * |     8		256		255			11111111     |
	 * |_________________________________________________________________________|
	 */
	int mask = (1 << bit_width) - 1;
	/* Invert the number and add 1 */
	int twos_comp = (~number + 1) & mask;
	for (int i = bit_width - 1; i >= 0; i--) {
		/* Print from MSB (left most) first */
		printf("%d", (twos_comp >> i) & 1);
	}
}

/* Function to validate if a string contains only digits */
int is_numeric(const char* str) {
	for (int i = 0; str[i] != '\0'; i++) {
		if (!isdigit(str[i])) {
			/* Non-digit character found */
			return 0;
		}
	}
	return 1;
}
