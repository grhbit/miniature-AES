#include <cstdio>
#include "../miniAES/internal/miniAES-Utils.hpp"

int main(int, char**)
{
	mini::internal::Byte con = 0x1;

	for (int i = 0; i < 10; ++i) {
		printf("%02x\n", con);
		con = mini::internal::ByteMul(0x02, con);
	}

	mini::internal::State s;
	s.m[0][0] = 0x19;
	s.m[0][1] = 0xa0;
	s.m[0][2] = 0x9a;
	s.m[0][3] = 0xe9;

	s.m[1][0] = 0x3d;
	s.m[1][1] = 0xf4;
	s.m[1][2] = 0xc6;
	s.m[1][3] = 0xf8;

	s.m[2][0] = 0xe3;
	s.m[2][1] = 0xe2;
	s.m[2][2] = 0x8d;
	s.m[2][3] = 0x48;

	s.m[3][0] = 0xbe;
	s.m[3][1] = 0x2b;
	s.m[3][2] = 0x2a;
	s.m[3][3] = 0x08;

	puts("");
	mini::internal::PrintBytes(&s);
	mini::internal::SubBytes(&s);

	puts("");
	mini::internal::PrintBytes(&s);
	mini::internal::ShiftRows(&s);

	puts("");
	mini::internal::PrintBytes(&s);
	mini::internal::MixColumns(&s);

	puts("");
	mini::internal::PrintBytes(&s);

	return 0;
}