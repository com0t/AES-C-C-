#include <stdio.h>
#include <string.h>
#include "aes.h"

void Input(unsigned char *in,unsigned char *key);

int main()
{
	unsigned char in[16] = {0x32,0x43,0xf6,0xa8,0x88,0x5a,0x30,0x8d,0x31,0x31,0x98,0xa2,0xe0,0x37,0x07,0x34};
	unsigned char key[16] = {0x2b,0x7e,0x15,0x16,0x28,0xae,0xd2,0xa6,0xab,0xf7,0x15,0x88,0x09,0xcf,0x4f,0x3c};
	unsigned char out[16]= {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,}; 
	// result: 39 25 84 1d 02 dc 09 fb dc 11 85 97 19 6a 0b 32
	unsigned char i,k;
	
	Input(in,key);
	S:
	printf("\nchuong trinh bat dau!!\n");
	
	Encrypt(in,key,out);
	printf("\nPlaint Text: ");
	for (i=0;i<16;i++) {
		printf("%.2x ",in[i]);
	//	if ((i+1)%4==0&&i!=0) printf("\n");
	}
	
	printf("\n\nCipher Key:  ");
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
	
	printf("\nQua trinh giai ma\n\n");
	Decrypt(out,key,out);
	printf("Plaint Text: ");
	for(i=0;i<16;i++)
		printf("%.2x ",out[i]);
	printf("\nTiep tuc y/n: ");
	fflush(stdin);
	k=getchar();
	if(k!='y') return 0;
	system("cls");
	goto S;
}

void Input(unsigned char *in,unsigned char *key)
{
	unsigned char i,j;
	unsigned char tkey[33];
	unsigned char tin[33];
	S:
	printf("Example Plaint Text: 3243f6a8885a308d313198a2e0370734\n");
	printf("Example Cipher  Key: 2b7e151628aed2a6abf7158809cf4f3c\n\n");
	printf("Cipher Text: 39 25 84 1d 02 dc 09 fb dc 11 85 97 19 6a 0b 32\n\n");
	printf("Input Plaint Text: ");
	fflush(stdin);
	gets(tin);
	printf("Input Key: ");
	fflush(stdin);
	gets(tkey);
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
