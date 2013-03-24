#ifndef MINIAES_INTERNAL_MINIAES_TYPES_HPP_
#define MINIAES_INTERNAL_MINIAES_TYPES_HPP_

namespace mini {
	namespace internal {
		typedef unsigned char Byte;
		typedef unsigned long Word;

		typedef struct {
			Word round;
			union {
				Byte a[16];
				Byte m[4][4];
			};
		} State;

		typedef struct {
			Word keyLength;
			Word *a;
		} Key;

	}	// namespace internal

	typedef enum {
		kKeyLength128Bit = 128 / 32,
		kKeyLength196Bit = 196 / 32,
		kKeyLength256Bit = 256 / 32,
	} KeyLength;

	typedef struct {
		internal::State *state;
		internal::Key *key;
	} AES_State;

}	// namespace mini

#endif	// MINIAES_INTERNAL_MINIAES_TYPES_HPP_