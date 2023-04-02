#pragma once

#include "KeyPair.h"

namespace labcry {

	struct MessageEncode {

	};

	struct MessageDecode {

	};

	class MessageCoder {
	public:
		static void encode(PublicKeyNonce& nonce, int bit);
		static int32_t decode(PrivateKey& sk, PublicKeyNonce& nonce);

	};

}
