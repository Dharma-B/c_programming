#include <stdio.h>
#include <string.h>

void hex2bin(const char* hex);

int main(int argc, char** argv) {
	if (argc != 2) {
		printf("Usage: hex2bin <binary number>\n");
		return 1;
	}

	const char* hex = argv[1];
	printf("Converting hex to binary: ");
	hex2bin(hex);
	printf("\n");
	return 0;
}

void hex2bin(const char* hex) {
	const char* lookup[] = {
		"0000", "0001", "0010", "0011",
		"0100", "0101", "0110", "0111",
		"1000", "1001", "1010", "1011",
		"1100", "1101", "1110", "1111"
	};

	for (int i = 0; i < strlen(hex); i++) {
		char c = hex[i];
		if (c >= '0' && c <= '9') {
			printf("%s", lookup[c - '0']);
		} else if (c >= 'A' && c <= 'F') {
			printf("%s", lookup[c - 'A' + 10]);
		} else if (c >= 'a' && c <= 'f') {
			printf("%s", lookup[c - 'a' + 10]);
		} else {
			printf("Invalid hex digit: %c\n", c);
			return;
		}
	}
}
