#include <iostream>

using namespace std;

class Matrix {
	int** values;
	int row, column;
public:
	explicit Matrix(const unsigned int row, const unsigned int column) : row(row), column(column) {
		values = new int*[row];
		for (unsigned int i = 0; i < row; i++) {
			values[i] = new int[column];
			for (unsigned int j = 0; j < column; j++)
				values[i][j] = 0;
		}
	}

	Matrix(const Matrix& copy) : row(copy.row), column(copy.column) {
		values = new int* [row];
		for (unsigned int i = 0; i < row; i++) {
			values[i] = new int[column];
			for (unsigned int j = 0; j < column; j++)
				values[i][j] = copy.values[i][j];
		}
	}

	~Matrix() {
		for (unsigned int i = 0; i < row; i++) {
			delete[] values[i];
		}
		delete[] values;

	}

	Matrix& operator=(const Matrix& other) {
		if (this != &other) {
			for (unsigned int i = 0; i < row; i++) {
				delete[] values[i];
			}
			delete[] values;

			row = other.row;
			column = other.column;

			values = new int* [row];
			for (unsigned int i = 0; i < row; i++) {
				values[i] = new int[column];
				for (unsigned int j = 0; j < column; j++) {
					values[i][j] = other.values[i][j];
				}
			}
		}
		return *this;
	}

	Matrix& operator+=(const Matrix& other) {
		if (row == other.row && column == other.column) {
			for (unsigned int i = 0; i < row; i++)
				for (unsigned int j = 0; j < column; j++)
					values[i][j] += other.values[i][j];
		} else {
			throw logic_error("Can't ADD");
		}

		return *this;
	}

	Matrix operator+(const Matrix& other) const {
		Matrix newMatrix(row, column);
		if (row == other.row && column == other.column) {
			for (unsigned int i = 0; i < row; i++)
				for (unsigned int j = 0; j < column; j++)
					newMatrix.values[i][j] = values[i][j] + other.values[i][j];
		} else {
			throw logic_error("Can't ADD");
		}
		return newMatrix;
	}

	Matrix operator*(const Matrix& other) const {
		if (column != other.row) {
			throw logic_error("Can't Multiply");
		}
		Matrix* newMatrix = new Matrix(row, other.column);
		for (unsigned int i = 0; i < row; i++)
			for (unsigned int j = 0; j < other.column; j++)
				newMatrix->values[i][j] = values[i][j] * other.values[j][i];
		return *newMatrix;
	}

	Matrix operator*(const int scala) const {
		for (unsigned int i = 0; i < row; i++)
			for (unsigned int j = 0; j < column; j++)
				values[i][j] *= scala;
		return *this;
	}

	bool operator==(const Matrix& other) const {
		if (row == other.row && column == other.column) {
			for (unsigned int i = 0; i < row; i++)
				for (unsigned int j = 0; j < column; j++)
					if (values[i][j] != other.values[i][j])
						return false;
			return true;
		}
		return false;
	}

	bool operator!=(const Matrix& other) const {
		return !(*this == other);
	}

	friend ostream& operator<<(ostream& os, const Matrix& matrix);
	friend istream& operator>>(istream& is, const Matrix& matrix);
};

ostream& operator<<(ostream& os, const Matrix& matrix) {
	for (unsigned int i = 0; i < matrix.row; i++) {
		for (unsigned int j = 0; j < matrix.column; j++)
			os << matrix.values[i][j] << '\t';
		os << endl;
	}
	return os;
}

istream& operator>>(istream& is, const Matrix& matrix) {
	for (unsigned int i = 0; i < matrix.row; i++)
		for (unsigned int j = 0; j < matrix.column; j++)
			is >> matrix.values[i][j];
	return is;
}

int main() {
	Matrix m1(2, 2), m2(2, 2);
	cin >> m1;
	cin >> m2;
	Matrix m3 = m1 + m2;
	cout << m3 << endl;
	Matrix m4 = m3 * 10;
	cout << m3 << endl;
	cout << m4 << endl;
}
