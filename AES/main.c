#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "aes.h"

void Input(uint8_t *in,uint8_t *key);

int main()
{
	uint8_t in[16] = {0x32,0x43,0xf6,0xa8,0x88,0x5a,0x30,0x8d,0x31,0x31,0x98,0xa2,0xe0,0x37,0x07,0x34};
	uint8_t key[16] = {	0x2b,0x7e,0x15,0x16,0x28,0xae,0xd2,0xa6,0xab,0xf7,0x15,0x88,0x09,0xcf,0x4f,0x3c};
	uint8_t out[16]= {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,}; // result: 39 25 84 1d 02 dc 09 fb dc 11 85 97 19 6a 0b 32
	uint8_t expkey[176];
	uint8_t i;
	Input(in,key);
	printf("chuong trinh bat dau!!\n");
	
	Encrypt(in,key,out);
	printf("\nPlaint Text:\n\n");
	for (i=0;i<16;i++) {
		printf("%.2x ",in[i]);
	//	if ((i+1)%4==0&&i!=0) printf("\n");
	}
	
	printf("\n\nCipher Key:\n\n");
	for (i=0;i<16;i++) {
		printf("%.2x ",key[i]);
		//if ((i+1)%4==0&&i!=0) printf("\n");
	}
	printf("\n\nXin vui long doi chuong trinh!!!!\n\n");
	printf("Cipher Text:  ");
	for (i=0;i<16;i++) {
		printf("%.2x ",out[i]);
	}
	printf("\n");
}

void Input(uint8_t *in,uint8_t *key)
{
	uint8_t i,j;
	uint8_t tkey[33];
	uint8_t tin[33];
	S:
	printf("Nhap Plaint Text: ");
	fflush(stdin);
	gets(tin);
	printf("Nhap Key: ");
	fflush(stdin);
	gets(tkey);
	printf("\nLength: %d  ||  Plaint Text: %s\n",strlen(tin),tin);
	printf("\nLength: %d  ||  Key: %s\n",strlen(tkey),tkey);
	if (strlen(tin) != 32 || strlen(tkey) != 32)
	{
		printf("\nPlaint Text or Key is 16 bytes\n\n");
		goto S;
	}
	
	j=0;
	for (i=0;i<32;i++)
	{
		if(tin[i]<='9') {
			tin[i] -=  0x30;
		} else {
			tin[i] -= 0x57;	
		}
		
		if(tkey[i]<='9') {
			tkey[i] -= 0x30;
		} else {
			tkey[i] -= 0x57;	
		}
		
		if ((i+1)%2==0) {
			in[j] = tin[i-1]*0x10 + tin[i];
			key[j] = tkey[i-1]*0x10 + tkey[i];
			j++;
		}
	}
}
