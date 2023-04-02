#pragma once

#include <iostream>
#include <cstdint>
#include <cstring>

namespace labcry {

	class Vector {
	public:
		Vector(int32_t* data, size_t length) : m_length(length) {
			vec = new int32_t[m_length];
			for (size_t i = 0; i < m_length; i++) {
				vec[i] = data[std::min(i, m_length - 1)];
			}
		}

		Vector(size_t length) : m_length(length) {
			vec = new int32_t[m_length];
			if (vec) {
				memset(vec, 0, m_length * sizeof(*vec));
			}
		}

		~Vector() {
			delete vec;
		}

		void set(int32_t* data) {

		}

		static int32_t dot(Vector& v1, Vector& v2) {
			int32_t output = 0;
			for (int i = 0; i < v1.length(); i++) {
				output += v1[i] * v2[i];
			}
			return output;
		}

		size_t length() {
			return m_length;
		}

		void print() {
			for (size_t i = 0; i < m_length; i++) {
				std::cout << vec[i] << ", ";
			}
			std::cout << std::endl;
		}

		int32_t& operator[] (size_t index) {
			return vec[index];
		}

	private:
		size_t m_length = 0;
		int32_t* vec = nullptr;
	};

}
