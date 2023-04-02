#pragma once

#include <iostream>
#include <cstdint>
#include <cstring>

#include "Vector.h"

namespace labcry {

	class Matrix {
	public:
		Matrix(int32_t* data, size_t rows, size_t cols) : m_rows(rows), m_cols(cols) {
			mat = new int32_t[m_rows * m_cols];
			for (size_t i = 0; i < m_rows; i++) {
				for (size_t j = 0; j < m_cols; j++) {
					mat[i * m_cols + j] = data[std::min(i * m_cols + j, (m_rows * m_cols) - 1)];
				}
			}
		}

		Matrix(size_t rows, size_t cols) : m_rows(rows), m_cols(cols) {
			mat = new int32_t[m_rows * m_cols];
			memset(mat, 0, (m_rows * m_cols) * sizeof(*mat));
		}

		~Matrix() {
			delete mat;
		}

		Vector getRow(size_t rowIndex) {
			Vector output = Vector(m_cols);
			for (size_t i = 0; i < m_cols; i++) {
				output[i] = mat[rowIndex * m_cols + i];
			}
			return output;
		}

		void print() {
			for (size_t i = 0; i < m_rows; i++) {
				for (size_t j = 0; j < m_cols; j++) {
					std::cout << mat[i * m_cols + j] << ", ";
				}
				std::cout << std::endl;
			}
		}

		Vector operator* (Vector& vec) {
			Vector output = Vector(m_rows);
			for (size_t i = 0; i < m_rows; i++) {
				for (size_t j = 0; j < m_cols; j++) {
					output[i] += mat[i * m_cols + j] * vec[j];
				}
			}
			return Vector(&output[0], m_cols);
		}

		int32_t& operator()(size_t row, size_t col) {
			return mat[row * m_cols + col];
		}

	private:

		size_t m_rows = 0;
		size_t m_cols = 0;
		int32_t* mat = nullptr;
	};

}