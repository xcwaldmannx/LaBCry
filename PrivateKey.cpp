#include "PrivateKey.h"

#include <iostream>
#include <random>
#include <chrono>
#include <vector>

using namespace labcry;

PrivateKey::PrivateKey(size_t size) : m_size(size) {
	std::vector<int32_t> data;
	std::random_device rd;
	std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count() + rd());
	std::uniform_real_distribution<float>dis(10, 99);

	for (size_t i = 0; i < m_size; i++) {
		data.push_back((int32_t) dis(gen));
	}

	m_data = new Vector(&data[0], m_size);
}

PrivateKey::~PrivateKey() {

}

size_t PrivateKey::size() {
	return m_size;
}

Vector& PrivateKey::getData() {
	return *m_data;
}

void PrivateKey::print() {
	std::cout << "PrivateKey: " << std::endl;
	m_data->print();
}
