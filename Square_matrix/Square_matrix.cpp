#include "Square_matrix.h"

Square_matrix::Square_matrix(int dim)
{
	dimension = new int(dim);
	square_matrix = new double* [*dimension];
	for (int i = 0; i < *dimension; i++)
		square_matrix[i] = new double [*dimension];
	for (int i = 0; i < *dimension; i++)
	{
		for (int j = 0; j < *dimension; j++)
			square_matrix[i][j] = 0;
	}
}

Square_matrix::Square_matrix(const Square_matrix& other_sq_mat)
{

	dimension = new int(other_sq_mat.get_dimension());
	square_matrix = new double* [*dimension];
	for (int i = 0; i < *dimension; i++)
		square_matrix[i] = new double [*dimension];
	for (int i = 0; i < *dimension; i++)
		for (int j = 0; j < *dimension; j++)
			square_matrix[i][j] = other_sq_mat.get_value(i, j);
}

Square_matrix::~Square_matrix()
{
	for (int i = 0; i < *dimension; i++)
		delete [] square_matrix[i];
	delete[] square_matrix;
	delete dimension;

}

Square_matrix::Square_matrix(int dim, double** squ_mat)
{
	dimension = new int (dim);
	square_matrix = new double* [*dimension];
	for (int i = 0; i < *dimension; i++)
		square_matrix[i] = new double [*dimension];
	for (int i = 0; i < *dimension; i++)
	{
		for (int j = 0; j < *dimension; j++)
			square_matrix[i][j] = squ_mat[i][j];
	}
}


double Square_matrix::get_value(int index_i, int index_j) const
{
	return square_matrix[index_i][index_j];
}

int Square_matrix::get_dimension() const
{
	return *dimension;
}

void Square_matrix::set_value(int index_i, int index_j, double value)
{
	square_matrix[index_i][index_j] = value;
}

Square_matrix Square_matrix::operator +(Square_matrix other_sq_mat)
{
	Square_matrix new_sq_mat(*dimension);
	if ((* dimension) == (other_sq_mat.get_dimension()))
	{
		for (int i = 0; i < *dimension; i++)
		{
			for (int j = 0; j < *dimension; j++)
				new_sq_mat.set_value(i, j, square_matrix[i][j] + other_sq_mat.get_value(i, j));
		}
	}
	return new_sq_mat;
}

Square_matrix Square_matrix::operator -(Square_matrix other_sq_mat)
{
	Square_matrix new_sq_mat(*dimension);
	if (*dimension == other_sq_mat.get_dimension())
	{
		for (int i = 0; i < *dimension; i++)
		{
			for (int j = 0; j < *dimension; j++)
				new_sq_mat.set_value(i, j, square_matrix[i][j] - other_sq_mat.get_value(i, j));
		}
	}
	return new_sq_mat;
}

Square_matrix Square_matrix::operator *(Square_matrix other_sq_mat)
{
	Square_matrix new_sq_mat(*dimension);
	if (*dimension == other_sq_mat.get_dimension())
	{
		double element = 0;
		for (int i = 0; i < *dimension; i++)
		{
			for (int j = 0; j < *dimension; j++)
			{
				for (int k = 0; k < *dimension; k++)
					element += square_matrix[i][k] * other_sq_mat.get_value(k, j);
				new_sq_mat.set_value(i, j, element);
				element = 0;
			}
		}
	}
	return new_sq_mat;
}

Square_matrix Square_matrix::gauss_method()	
{
	Square_matrix lower_triangular_matrix(*dimension, square_matrix);
	for (int k = 0; k < *dimension - 1; k++) // k - шаг
	{
		for (int i = k + 1; i < *dimension; i++) // i - строка
		{
			double ratio = lower_triangular_matrix.get_value(i, k);
			for (int j = 0; j < *dimension; j++) // j - столбец
			{
				lower_triangular_matrix.set_value(i, j,
					lower_triangular_matrix.get_value(i, j) - lower_triangular_matrix.get_value(k, j)
					* ratio / lower_triangular_matrix.get_value(k, k));
			}
		}
	}
	return lower_triangular_matrix;
}

double Square_matrix::determinant()
{
	double det = 1;
	Square_matrix sq_mt = gauss_method();
	for (int i = 0; i < *dimension; i++)
		det *= sq_mt.get_value(i, i);
	return det;
}

bool Square_matrix::operator ==(Square_matrix other_sq_mat)
{
	for (int i = 0; i < *dimension; i++)
	{
		for (int j = 0; j < *dimension; j++)
		{
			if (square_matrix[i][j] != other_sq_mat.get_value(i, j))
				return false;
		}
	}
	return true;
}

bool Square_matrix::operator !=(Square_matrix other_sq_mat)
{
	return !(*this == other_sq_mat);;
}

Square_matrix& Square_matrix::operator =(const Square_matrix& other_sq_mat)
{
	dimension = new int(other_sq_mat.get_dimension());
	square_matrix = new double* [*dimension];
	for (int i = 0; i < *dimension; i++)
		square_matrix[i] = new double [*dimension];
	for (int i = 0; i < *dimension; i++)
		for (int j = 0; j < *dimension; j++)
			square_matrix[i][j] = other_sq_mat.get_value(i, j);
	
	return *this;
}

std::ostream& operator <<(std::ostream& out, Square_matrix matrix)
{
	for (int i = 0; i < matrix.get_dimension(); i++)
	{
		for (int j = 0; j < matrix.get_dimension(); j++)
			out << matrix.get_value(i, j) << " ";
		out << "\n";
	}

	return out;
}


std::istream& operator >>(std::istream& out, Square_matrix matrix)
{
	double elem;
	for (int i = 0; i < matrix.get_dimension(); i++)
	{
		for (int j = 0; j < matrix.get_dimension(); j++)
		{
			out >> elem;
			matrix.set_value(i, j, elem);
		}
	}
	return out;
}

