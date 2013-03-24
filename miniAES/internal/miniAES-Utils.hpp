#ifndef MINIAES_INTERNAL_MINIAES_UTILS_HPP_
#define MINIAES_INTERNAL_MINIAES_UTILS_HPP_

#include "miniAES-Types.hpp"
#include <string>

namespace mini {
	namespace internal {
		void KeyInit(const Byte *, Key *, KeyLength keyLength);
		void KeyExpansion(Key *);
		void KeyRelease(Key *);

		void SubBytes(State *);
		void ShiftRows(State *);
		void MixColumns(State *);
		void AddRoundKey(State *, Key *);

		void InvShiftRows(State *);
		void InvSubBytes(State *);
		void InvMixColumns(State *);
		void InvAddRoundKey(State *, Key *);

		void PrintBytes(State *);

	}	// namespace internal

	void StringToBytes(const std::string&, internal::Byte *, size_t bytes_size);
	void BytesToString(const internal::Byte *, size_t bytes_size, std::string&);

}	// namespace mini

#endif	// MINIAES_INTERNAL_MINIAES_UTILS_HPP_