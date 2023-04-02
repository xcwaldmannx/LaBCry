#pragma once

#include "PrivateKey.h"
#include "PublicKey.h"

namespace labcry {

	struct PublicKeyNonce {
		PublicKeyNonce(Vector& equation, int32_t answer, int mod) : equation(Vector(&equation[0], equation.length())), answer(answer), mod(mod) {
		}

		void print() {
			std::cout << "Nonce:" << std::endl;
			equation.print();
			std::cout << "Answer: " << answer << std::endl;
			std::cout << "Mod: " << mod << std::endl;
		}

		Vector equation;
		int32_t answer = 0;
		int mod = 0;
	};

	class KeyPair {
	public:
		KeyPair(size_t rows, size_t cols);
		~KeyPair();

		PublicKeyNonce generateNonce();

		size_t rows();
		size_t cols();

		PrivateKey& getPrivateKey();
		PublicKey& getPublicKey();

		void print();
	private:
		size_t m_rows = 0;
		size_t m_cols = 0;
		PrivateKey* m_privateKey = nullptr;
		PublicKey* m_publicKey = nullptr;
	};

}
