/*Binary to Decimal: Convert 110101 to decimal.
 *
 * poistion 32 16 8 4 2 1
 *	     1  1 0 1 0 1
 * 32 + 16 + 4 + 1 = 53
 * Traverse through the binary number and keep adding the positional value
 * i.e. 2*value @ pos.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int is_binary(const char* str);

int main(int argc, char** argv) {
	if (argc != 2) {
		printf("Usage: bi2dec <binary number>\n");
		return 1;
	}

	/* Validate input */
	if (!is_binary(argv[1])) {
		printf("Error: Input must be a binary number (only 0s and 1s allowed).\n");
		return 1;
	}

	const char* binary = argv[1];
	int length = strlen(binary);
	int decimal = 0;

	printf("Converting binary %s to decimal\n", binary);

	/* Iterate through the binary string */
	for (int i = 0; i < length; i++) {
		/* Convert character to integer and update the decimal value
		 * Note: ASCII equivalent of char '0' is 48 and '1' is 49.
		 */
		decimal = decimal * 2 + (binary[i] - '0');
	}

	printf("Decimal value is: %d\n", decimal);
	return 0;
}

/* Function to validate if the input string contains only binary digits */
int is_binary(const char* str) {
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] != '0' && str[i] != '1') {
			/* Non-binary character found */
			return 0;
		}
	}
	return 1;
}
