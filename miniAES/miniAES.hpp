#ifndef MINIAES_MINIAES_HPP_
#define MINIAES_MINIAES_HPP_

#include "internal/miniAES-Utils.hpp"

namespace mini {

	class AES {
	public:
		static std::string Encrypt(const std::string&, KeyLength, const char *hexKey);
		static std::string Decrypt(const std::string&, KeyLength, const char *hexKey);
	};

}	// namespace mini

#endif	// MINIAES_MINIAES_HPP_