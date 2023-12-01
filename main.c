#include <stdio.h>
#include <time.h>
#include "kuznechik.h"

void print_w128(w128_t x) {
	for (int i = 0; i < 16; i++)
		printf(" %02X", x.b[i]);
	printf("\n");
}

int main(int argc, char **argv) {	
	const uint8_t test_key[32] = {
		0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 
		0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 
		0xFE, 0xDC, 0xBA, 0x98, 0x76, 0x54, 0x32, 0x10, 
		0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF	
	};
	const uint8_t initial_text[16] = {
		0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x00, 
		0xFF, 0xEE, 0xDD, 0xCC, 0xBB, 0xAA, 0x99, 0x88
	};
	
	int i;
	kuz_key_t key;
	w128_t x;

	kuz_init();

	for (i = 0; i < 16; i++)
		x.b[i] = initial_text[i];
	printf("initial text\t=");
	print_w128(x);

	kuz_set_encrypt_key(&key, test_key);	
	kuz_encrypt_block(&key, &x);
	printf("encrypted text\t=");
	print_w128(x);

	kuz_set_decrypt_key(&key, test_key);
	kuz_decrypt_block(&key, &x);
	printf("decrypted text\t=");
	print_w128(x);
	
	return 0;
}