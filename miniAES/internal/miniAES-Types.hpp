#ifndef MINIAES_INTERNAL_MINIAES_TYPES_HPP_
#define MINIAES_INTERNAL_MINIAES_TYPES_HPP_

namespace mini {
	namespace internal {
		typedef unsigned char Byte;

		typedef unsigned short Word;

		typedef struct {
			union {
				Byte a[16];
				Byte m[4][4];
			};
		} State;

		typedef struct {
		} CipherKey;

	}	// namespace internal

	typedef enum {
		kKeyLengh128BIT = 128 / 32,
		kKeyLengh196BIT = 196 / 32,
		kKeyLengh256BIT = 256 / 32,
	} KeyLength;

}	// namespace mini

#endif	// MINIAES_INTERNAL_MINIAES_TYPES_HPP_