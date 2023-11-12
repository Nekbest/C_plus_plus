#pragma once
#include <iostream>

class Square_matrix
{
private:
	int* dimension;
	double** square_matrix;
public:
	Square_matrix(int dimension);
	Square_matrix(int dimension, double** square_matrix);
	Square_matrix(const Square_matrix& matrix);
	~Square_matrix();
	double get_value(int index_i, int index_j) const;
	int get_dimension() const;
	void set_value(int index_i, int index_j, double value);
	Square_matrix operator +(Square_matrix other_sq_mat);
	Square_matrix operator -(Square_matrix other_sq_mat);
	Square_matrix operator *(Square_matrix other_sq_mat);
	Square_matrix& operator =(const Square_matrix& other_sq_mat);
	Square_matrix gauss_method();
	double determinant();
	bool operator ==(Square_matrix other_sq_mat);
	bool operator !=(Square_matrix other_sq_mat);
	friend std::ostream& operator <<(std::ostream& out, Square_matrix);
	friend std::istream& operator >>(std::istream& out, Square_matrix);
};
