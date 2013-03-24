#include <cstdio>
#include "../miniAES/internal/miniAES-Utils.hpp"

using namespace mini;
using namespace mini::internal;

int main(int, char**)
{
	Byte aes_key[16] = { 0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c };
	Key key;
	KeyInit(aes_key, &key, kKeyLength128Bit);
	KeyExpansion(&key);

	State s;

	{
		s.round = 0;

		s.m[0][0] = 0x32;
		s.m[1][0] = 0x43;
		s.m[2][0] = 0xf6;
		s.m[3][0] = 0xa8;

		s.m[0][1] = 0x88;
		s.m[1][1] = 0x5a;
		s.m[2][1] = 0x30;
		s.m[3][1] = 0x8d;

		s.m[0][2] = 0x31;
		s.m[1][2] = 0x31;
		s.m[2][2] = 0x98;
		s.m[3][2] = 0xa2;

		s.m[0][3] = 0xe0;
		s.m[1][3] = 0x37;
		s.m[2][3] = 0x07;
		s.m[3][3] = 0x34;
	}

	AddRoundKey(&s, &key);

	for (int i = 0; i < 9; ++i) {
		SubBytes(&s);
		ShiftRows(&s);
		MixColumns(&s);
		AddRoundKey(&s, &key);
	}

	SubBytes(&s);
	ShiftRows(&s);
	AddRoundKey(&s, &key);

	PrintBytes(&s);

	InvAddRoundKey(&s, &key);

	for (int i = 0; i < 9; ++i) {
		InvShiftRows(&s);
		InvSubBytes(&s);
		InvAddRoundKey(&s, &key);
		InvMixColumns(&s);
	}

	InvShiftRows(&s);
	InvSubBytes(&s);
	InvAddRoundKey(&s, &key);

	PrintBytes(&s);

	KeyRelease(&key);

	return 0;
}