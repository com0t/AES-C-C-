#ifndef _AES_H
#define _AES_H

void Encrypt(unsigned char *in,unsigned char *key,unsigned char *out);
void Decrypt(unsigned char *in,unsigned char *key,unsigned char *out);

//void Expankey(uint8_t *key,uint8_t *expkey);
//void SubBytes(uint8_t *state);
//void AddRoundKey(uint8_t *state,uint8_t *expkey,uint8_t n);
//void MixColumns(uint8_t *state);
//void ShiftRows(uint8_t *state);

#endif
