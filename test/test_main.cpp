#include <cstdio>
#include "../miniAES/internal/miniAES-Utils.hpp"
#include "../miniAES/miniAES.hpp"

using namespace mini;
using namespace mini::internal;

int main(int, char**)
{
    std::string key_str = "2b7e151628aed2a6abf7158809cf4f3c2b7e151628aed2a6abf7158809cf4f3c";
    
	Byte aes_key[32];
	Key key;
    StringToBytes(key_str, aes_key, 32);
	KeyInit(aes_key, &key, kKeyLength256Bit);
	KeyExpansion(&key);
    
	State s;

	{
		s.round = 0;

		s.m[0][0] = 'a';
		s.m[1][0] = 'b';
		s.m[2][0] = 'c';
		s.m[3][0] = 'd';

		s.m[0][1] = 'e';
		s.m[1][1] = 'f';
		s.m[2][1] = 'g';
		s.m[3][1] = 'h';

		s.m[0][2] = 'i';
		s.m[1][2] = 'j';
		s.m[2][2] = 'k';
		s.m[3][2] = 'l';

		s.m[0][3] = 'm';
		s.m[1][3] = 'n';
		s.m[2][3] = 'o';
		s.m[3][3] = 'p';
	}

	Encrypt(&s, &key);
	PrintBytes(&s);

	Decrypt(&s, &key);
	PrintBytes(&s);

	KeyRelease(&key);

	std::string original_string = "Apple, Banana, Char, D-jango, Element, F#, H";
	std::string encrypt_string;
	std::string decrypt_string;

	encrypt_string = AES::Encrypt(original_string, kKeyLength256Bit, key_str.c_str());
	decrypt_string = AES::Decrypt(encrypt_string, kKeyLength256Bit, key_str.c_str());

	printf("%s : %s\n", original_string.c_str(), decrypt_string.c_str());
    printf("%s\n", !strcmp(original_string.c_str(), decrypt_string.c_str())? "equal": "inequal");

	return 0;
}