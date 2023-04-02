#pragma once

#include <cstdint>

#include "Vector.h"

namespace labcry {

	class PrivateKey {
	public:
		PrivateKey(size_t size);
		~PrivateKey();

		size_t size();

		Vector& getData();
		void print();

	private:
		size_t m_size = 0;
		Vector* m_data = nullptr;
	};

}
