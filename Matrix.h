#pragma once
#include "Complex.h"
#include "DynamicArray.h"
#include "LinkedList.h"
#include "Sequence.h"

using namespace std;

template<typename T>
class Matrix
{
private:
	int lines;
	int columns;
	
	ArraySequence<ArraySequence<T>> theMatrix;

	const int ERROR_INDEX_OUT_OF_RANGE = 1;
	const int ERROR_INVALID_SIZE = 2;
public:
	Matrix();
	Matrix(int x, int y);
	Matrix(int x, int y, T def);
	Matrix(const Matrix<T>& matrix);
	~Matrix();

	Matrix<T> operator+ (Matrix<T> y);
	Matrix<T> operator- (Matrix<T> y);
	Matrix<T> operator* (Matrix<T> y);
	Matrix<T> operator* (T y);

	Matrix<T>& operator= (Matrix<T> y);
//	bool operator== (Matrix<T> y);
//	bool operator!= (Matrix<T> y);
//	ArraySequence<T> operator[](int index);

	int GetLines();
	int GetColumns();
	T Get(int xIndex,int yIndex);
	void Set(T value, int xIndex, int yIndex);
	void print();


	void SwapLines(int x, int y);
	void SwapColumns(int x, int y);

	void MultLineToConst(int line, T x);
	void MultColimnToConst(int column,T x);

	void SumLine(int line1, int line2);
	void SumColumn(int column1, int column2);
	T NormaMax();

//	ArraySequence<T> GetLine(int Index);
//	ArraySequence<T> GetCilumn(int Index);
};




template<typename T>
Matrix<T>::Matrix() : Matrix(0,0)
{
//	Matrix::lines = 0;
//	Matrix::columns = 0;
//	Matrix::theMatrix = ArraySequence<T>();
}

template<typename T>
Matrix<T>::Matrix(int x, int y) : Matrix(x,y,T(0))
{
//	Matrix::lines = y;
//	Matrix::columns = x;
//	Matrix::theMatrix = ArraySequence<ArraySequence<T>>(y,ArraySequence<T>(x));
}

template<typename T>
Matrix<T>::Matrix(int x, int y, T def)
{
	Matrix::lines = y;
	Matrix::columns = x;
	Matrix::theMatrix = ArraySequence<ArraySequence<T>>(y,ArraySequence<T>(x, def));
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& matrix) : theMatrix(matrix.theMatrix)
{
	this->columns = matrix.columns;
	this->lines = matrix.lines;
//	this->theMatrix = ArraySequence<T>(matrix.theMatrix);
}

template<typename T>
Matrix<T>::~Matrix() {

}

template<typename T>
Matrix<T>& Matrix<T>::operator= (Matrix<T> y) {
	this->columns = y.columns;
	this->lines = y.lines;
	this->theMatrix = y.theMatrix;

//	Matrix<T> res(y);
	return *this;
}
template<typename T>
Matrix<T> Matrix<T>::operator+ (Matrix<T> y) {
	if (this->lines != y.lines || this->columns!= y.columns)
	{
		throw ERROR_INVALID_SIZE;
	}
	Matrix<T> res(/*y.columns, y.lines*/y.columns, y.lines);
	for (int i = 0; i < this->lines; i++)
	{
		for (int j = 0; j < this->columns; j++)
		{
			res.theMatrix[i][j] = this->theMatrix[i][j] + y.theMatrix[i][j];

		}
	}
	return res;
}

template<typename T>
Matrix<T> Matrix<T>::operator- (Matrix<T> y) {
	return ((*this) + y *(-1));
}

template<typename T>
Matrix<T> Matrix<T>::operator* (Matrix<T> y) {
	if (this->columns != y.lines)
	{
		throw ERROR_INVALID_SIZE;
	}
	Matrix<T> res(this->lines, y.columns);
	T tmp;
	for (int i = 0; i < this->lines; i++)
	{
		for (int j = 0; j < y.columns; j++)
		{
			tmp = 0;
			for (int k = 0; k < this->columns; k++)
			{
				tmp = tmp + this->theMatrix[i][k] * y.theMatrix[k][j];
			}
			res.theMatrix[i][j] = tmp;
		}
	}
	return res;
}

template<typename T>
Matrix<T> Matrix<T>::operator* (T y) {
	Matrix<T> res(*this);
	for (int i = 0; i < this->lines; i++)
	{
		res.MultLineToConst(i, y);
	}
	return res;
}

template<typename T>
int Matrix<T>::GetLines() {
	return this->lines;
}

template<typename T>
int Matrix<T>::GetColumns() {
	return this->columns;
}

template<typename T>
T Matrix<T>::Get(int xIndex, int yIndex) {
	return this->theMatrix[yIndex][xIndex];
}

template<typename T>
void Matrix<T>::Set(T value, int xIndex, int yIndex) {
	if (xIndex < 0 || yIndex < 0 || xIndex > this->columns || yIndex > this->lines)
	{
		throw ERROR_INDEX_OUT_OF_RANGE;
	}
	this->theMatrix[yIndex][xIndex] = value;
}

template<typename T>
void Matrix<T>::print() {
	for (int i = 0; i < this->lines; i++)
	{
		for (int j = 0; j < this->columns; j++)
		{
			cout << this->theMatrix[i][j]<<" ";
		}
		cout << "\n";
	}
}

template<typename T>
void Matrix<T>::SwapLines(int x, int y) {
	if (x < 0 || y < 0 || x > this->lines || y > this->lines)
	{
		throw ERROR_INDEX_OUT_OF_RANGE;
	}
	
	ArraySequence<T> tmp = this->theMatrix[x];
	this->theMatrix[x] = this->theMatrix[y];
	this->theMatrix[y] = tmp;
	
}

template<typename T>
void Matrix<T>::SwapColumns(int x, int y) {
	if (x < 0 || y < 0 || x > this->columns|| y > this->columns)
	{
		throw ERROR_INDEX_OUT_OF_RANGE;
	}
	T tmp;
	for (int i = 0; i < this->lines; i++)
	{
		tmp = this->theMatrix[i][x];
		this->theMatrix[i][x] = this->theMatrix[i][y];
		this->theMatrix[i][y] = tmp;
	}
}

template<typename T>
void Matrix<T>::MultLineToConst(int line, T x) {
	if (line < 0 || line > this->lines)
	{
		throw ERROR_INDEX_OUT_OF_RANGE;
	}
	for (int i = 0; i < this->columns; i++)
	{
		this->theMatrix[line][i] = this->theMatrix[line][i] * x;
	}
}

template<typename T>
void Matrix<T>::MultColimnToConst(int column, T x) {
	if (column < 0 || column > this->columns)
	{
		throw ERROR_INDEX_OUT_OF_RANGE;
	}
	for (int i = 0; i < this->lines; i++)
	{
		this->theMatrix[i][column] *= x;
	}
}

template<typename T>
void Matrix<T>::SumLine(int line1, int line2) {
	if (line1 < 0|| line1 > this->lines || line2 < 0 || line2 > this->lines)
	{
		throw ERROR_INDEX_OUT_OF_RANGE;
	}
	for (int i = 0; i < this->columns; i++)
	{
		this->theMatrix[line1][i] += this->theMatrix[line2][i];
	}
}

template<typename T>
void Matrix<T>::SumColumn(int column1, int column2){
	if (column1 < 0 || column1 > this->columns || column2 < 0 || column2 > this->columns)
	{
		throw ERROR_INDEX_OUT_OF_RANGE;
	}
	for (int i = 0; i < this->lines; i++)
	{
		this->theMatrix[i][column1] += this->theMatrix[i][column2];
	}
}

template<typename T>
T Matrix<T>::NormaMax() {
	T tmp(0);
	for (int i = 0; i < this->lines; i++)
	{
		for (int j = 0; j < this->columns; j++)
		{
			if ((this->theMatrix[i][j])*(this->theMatrix[i][j]) > tmp*tmp)
				tmp = this->theMatrix[i][j];
		}
	}
	return tmp;
}
/*
<template<typename T>
ArraySequence<T> Matrix<T>::GetLine(int Index);

template<typename T>
ArraySequence<T> Matrix<T>::GetCilumn(int Index);
*/