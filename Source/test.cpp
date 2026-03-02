#include <iostream>
#include "Matrix.h"

bool testMatrixCreateSquare() {
	const size_t R = 128;
	const size_t C = 128;
	Matrix m(R, C);
	for (size_t r = 0; r < R; ++r)
		for (size_t c = 0; c < C; ++c)
			if (m.Get(r, c))
				return false;
	return true;
}

bool testMatrixCreateRow() {
	const size_t C = 128;
	Matrix m(1, C);
	for (size_t c = 0; c < C; ++c)
		if (m.Get(0, c))
			return false;
	return true;
}

bool testMatrixCreateCol() {
	const size_t R = 128;
	Matrix m(R, 1);
	for (size_t r = 0; r < R; ++r)
		if (m.Get(r, 0))
			return false;
	return true;
}

bool testMatrixSetGetSquare() {
	const size_t R = 128;
	const size_t C = 128;
	Matrix m(R, C);
	for (size_t r = 0; r < R; ++r)
		for (size_t c = 0; c < C; ++c) {
			auto val = static_cast<bool>((r + c) % 2);
			m.Set(r, c, val);
			if (m.Get(r, c) != val)
				return false;
		}
	return true;
}



int main() {
	std::cout << "testMatrixCreateSquare " << (testMatrixCreateSquare() ? "passed" : "fail ") << std::endl;
	std::cout << "testMatrixCreateRow " << (testMatrixCreateRow() ? "passed" : "fail ") << std::endl;
	std::cout << "testMatrixCreateCol " << (testMatrixCreateCol() ? "passed" : "fail ") << std::endl;
	std::cout << "testMatrixSetGetSquare " << (testMatrixCreateRow() ? "passed" : "fail ") << std::endl;

  return 0;
}
