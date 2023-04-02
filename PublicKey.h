#pragma once

#include <cstdint>

#include "Matrix.h"

namespace labcry {

	class PublicKey {
	public:
		PublicKey(size_t rows, size_t cols);
		~PublicKey();

		size_t rows();
		size_t cols();

		Matrix& getData();
		void print();

	private:
		const size_t m_rows = 0;
		const size_t m_cols = 0;
		Matrix* m_data = nullptr;
	};

}
