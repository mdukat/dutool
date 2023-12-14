CC = gcc

test: test.c hmac_sha256/sha256.c hmac_sha256/sha256.h tiny-AES-c/aes.c tiny-AES-c/aes.h
	$(CC) test.c hmac_sha256/sha256.c tiny-AES-c/aes.c -o test

