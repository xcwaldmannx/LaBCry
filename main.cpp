#include "KeyPair.h"
#include "MessageCoder.h"

#include <iostream>
#include <string>

int correct = 0;
int incorrect = 0;

void run(int bit) {
	KeyPair keyPair = KeyPair(32, 1000);
	//keyPair.print();

	PublicKeyNonce nonce = keyPair.generateNonce();
	//nonce.print();

	MessageCoder::encode(nonce, bit);
	int32_t msg = MessageCoder::decode(keyPair.getPrivateKey(), nonce);

	if ((msg == 0 && bit == 0) || (msg == 1 && bit == 1)) {
		correct++;
	} else {
		std::cout << "--INCORRECT--" << std::endl;
		incorrect++;
	}
}

int main() {

	for (int i = 0; i < 1000; i++) {
		run(0);
	}

	std::cout << "Correct: " << correct << std::endl;
	std::cout << "Inorrect: " << incorrect << std::endl;

	std::string s;
	std::cin >> s;

	return 0;
}