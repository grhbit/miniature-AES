#ifndef MINIAES_INTERNAL_MINIAES_UTILS_HPP_
#define MINIAES_INTERNAL_MINIAES_UTILS_HPP_

#include "miniAES-Types.hpp"

namespace mini {
	namespace internal {
		void SubWord(Word *);
		void RotWord(Word *);

		Byte ByteMul(Byte lhs, Byte rhs);

		void SubBytes(State *);
		void ShiftRows(State *);
		void MixColumns(State *);

		void InvShiftRows(State *);
		void InvSubBytes(State *);
		void InvMixColumns(State *);

		void AddRoundKey(State *);

		void PrintBytes(State *);

	}	// namespace internal

}	// namespace mini

#endif	// MINIAES_INTERNAL_MINIAES_UTILS_HPP_