#include "hmac_sha256/sha256.h"
#include "tiny-AES-c/aes.h"
#include <stdio.h>
#include <string.h>

int main(){

	printf("SHA256 Test: \"Hello, World!\"\n");

	SHA256_HASH test_hash;
	char* test_val = "Hello, World!";

	Sha256Calculate(test_val, strlen(test_val), &test_hash);

	for(int i = 0; i<SHA256_HASH_SIZE; i++){
		printf("%.2X", test_hash.bytes[i]);
	}
	printf("\n\n");

	printf("AES256 Test: Key -> A*32, IV -> A*16, \"Hello, World!\"+padding\n");

	struct AES_ctx ctx;
	uint8_t key[32];
	uint8_t iv[16];
	uint8_t data[32];

	memset(key, 'A', 32);
	memset(iv, 'A', 16);
	memset(data, '\0', 32);
	strcpy(data, "Hello, World!");

	AES_init_ctx_iv(&ctx, key, iv);
	AES_CBC_encrypt_buffer(&ctx, data, 32);

	for(int i = 0; i<2; i++){
		for(int j = 0; j<16; j++){
			printf("%.2X ", data[(i*16)+j]);
		}
		printf("\n");
	}

	AES_init_ctx_iv(&ctx, key, iv);
	AES_CBC_decrypt_buffer(&ctx, data, 32);

	printf("%s\n", data);

	return 0;

}