#include "PublicKey.h"

#include <iostream>
#include <random>
#include <chrono>
#include <vector>

using namespace labcry;

PublicKey::PublicKey(size_t rows, size_t cols) : m_rows(rows), m_cols(cols) {
	std::vector<int32_t> data;
	std::random_device rd;
	std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count() + rd());
	std::uniform_real_distribution<float>dis(10, 99);

	for (size_t i = 0; i < m_rows * m_cols; i++) {
		data.push_back((int32_t) dis(gen));
	}

	m_data = new Matrix(&data[0], m_rows, m_cols);
}

PublicKey::~PublicKey() {
	delete m_data;
}

size_t PublicKey::rows() {
	return m_rows;
}

size_t PublicKey::cols() {
	return m_cols;
}

Matrix& PublicKey::getData() {
	return *m_data;
}

void PublicKey::print() {
	std::cout << "PublicKey: " << std::endl;
	m_data->print();
}
