/* Decimal to Binary: Convert 45 to binary.
 * 32 16 8 4 2 1 |
 *  1  0 1 1 0 1 |
 * keep on diving by 2 until quotient is 0
 *
 * 2|45 Remainder
 *  ---\
 * 2|22 1 ^
 *  ---\  ^
 * 2|11 0 ^
 *  ---\  ^
 * 2| 5 1 ^
 *  ---\  ^
 * 2| 2 1 ^
 *  ---\  ^
 * 2| 1 0 ^
 *  ---\  ^
 * 2| 0 1 ^
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int is_numeric(const char* str);
int dec2bin(int decimal);

int main(int argc, char** argv)
{
	if(argc !=2 ){
		printf("Usage: dec2bin <decimal number>\n");
		return 1;
	}

	/* Validate input */
	if (!is_numeric(argv[1])) {
		printf("Error: Input must be a positive integer.\n");
		return 1;
	}

	int decimal = atoi(argv[1]);
	printf("Converting decimal %d to binary\n",decimal);
	dec2bin(decimal);
	printf("\n");
	return 0;
}

/* Use recursive function to print the numbers in reverse order */
int dec2bin(int decimal)
{
	if(decimal > 1)
		dec2bin(decimal/2);
	printf("%d ",decimal%2);
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
