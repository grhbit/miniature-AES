#include "miniAES.hpp"

namespace mini {

	using namespace internal;

	std::string AES::Encrypt(const std::string& str, KeyLength length, const char *hexKey)
	{
		Byte *bytes = new Byte[length * 4];
		Key *key = new Key;

		StringToBytes(hexKey, bytes, length * 4);

		KeyInit(bytes, key, length);
		KeyExpansion(key);

		std::string result;
		Byte *data;
		State s;
		int count = ((str.size() + 0xf) & ~0xf) / 16;

		std::string input;
		input.resize(count*16, 0);
		input.assign(str, 0, str.size());

		for (int i = 0; i < count; ++i) {
			data = (Byte *)(input.data() + i*16);
            s.round = 0;
			BytesToState(data, &s);
			internal::Encrypt(&s, key);
			StateToBytes(&s, data);
			result.append((const char*)(data), 16);
		}

		KeyRelease(key);
		delete key;
		delete []bytes;

		return result;
	}

	std::string AES::Decrypt(const std::string& str, KeyLength length, const char *hexKey)
	{
		Byte *bytes = new Byte[length * 4];
		Key *key = new Key;

		StringToBytes(hexKey, bytes, length * 4);

		KeyInit(bytes, key, length);
		KeyExpansion(key);

		std::string result;
		Byte *data;
		State s;
		int count = ((str.size() + 0xf) & ~0xf) / 16;

		std::string input;
		input.resize(count*16, 0);
		input.assign(str, 0, str.size());

		for (int i = 0; i < count; ++i) {
			data = (Byte *)(input.data() + i*16);
            s.round = length + 6 + 1;
			BytesToState(data, &s);
			internal::Decrypt(&s, key);
			StateToBytes(&s, data);
			result.append((const char *)(data), 16);
		}

		KeyRelease(key);
		delete key;
		delete []bytes;

		return result;
	}
}