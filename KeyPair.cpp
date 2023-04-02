#include "KeyPair.h"

#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

using namespace labcry;

KeyPair::KeyPair(size_t rows, size_t cols) :
	m_rows(rows), m_cols(cols),
	m_privateKey(new PrivateKey(cols)),
	m_publicKey(new PublicKey(rows, cols)) {

}

KeyPair::~KeyPair() {
	delete m_privateKey;
	delete m_publicKey;
}

PublicKeyNonce KeyPair::generateNonce() {
	Vector equation = Vector(m_cols);

	{
		int equationUseAmount = 10;
		std::vector<int> rows;

		std::random_device rd;
		std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count() + rd());
		std::uniform_real_distribution<float>dis(0, m_rows);
		for (int i = 0; i < equationUseAmount; i++) {
			rows.push_back(dis(gen));
		}

		for (int i = 0; i < rows.size(); i++) {
			for (int j = 0; j < m_cols; j++) {
				equation[j] += m_publicKey->getData()(rows[i], j);
			}
		}
	}

	int mod = 89;

	int32_t actual = Vector::dot(m_privateKey->getData(), equation) % mod;
	//std::cout << "Actual: " << actual << std::endl;

	std::random_device rd;
	std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count() + rd());
	std::uniform_real_distribution<float>dis((actual > floor(mod / 2)) ? -3 : 0, (actual > floor(mod / 2)) ? 0 : 3);
	int32_t error = dis(gen);
	//std::cout << "Error:  " << error << std::endl;
	int32_t answer = (Vector::dot(m_privateKey->getData(), equation) + error) % mod;
	//std::cout << "Answer: " << answer << std::endl;

	return PublicKeyNonce(equation, answer, mod);
}

size_t KeyPair::rows() {
	return m_rows;
}

size_t KeyPair::cols() {
	return m_cols;
}

PrivateKey& KeyPair::getPrivateKey() {
	return *m_privateKey;
}

PublicKey& KeyPair::getPublicKey() {
	return *m_publicKey;
}

void KeyPair::print() {
	m_privateKey->print();
	m_publicKey->print();
}
