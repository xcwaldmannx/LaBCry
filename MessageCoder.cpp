#include "MessageCoder.h"

using namespace labcry;

void MessageCoder::encode(PublicKeyNonce& nonce, int bit) {
	if (bit > 0) {
		nonce.answer += floor(nonce.mod / 2);
	}
}

int32_t MessageCoder::decode(PrivateKey& sk, PublicKeyNonce& nonce) {
	int32_t answer = Vector::dot(sk.getData(), nonce.equation) % nonce.mod;
	int32_t encodedBit = nonce.answer - answer;
	//if (encodedBit < 0) {
	//	encodedBit += floor(nonce.mod / 4);
	//}
	//std::cout << "Encoded Bit: " << encodedBit << std::endl;
	int32_t msg = (encodedBit <= floor(nonce.mod / 4)) ? 0 : 1;
	//std::cout << "Message: " << msg << std::endl;
	return msg;
}
