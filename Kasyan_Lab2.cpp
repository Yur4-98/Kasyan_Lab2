#include <iostream>

#include "Complex.h"
#include "DynamicArray.h"
#include "LinkedList.h"
#include "Sequence.h"
#include "Matrix.h"
#include "Interfaces.h"
using namespace std;

/*
void TextDialog()
{

	int q = 1;
	int input = 0;
	int x, y, z;
	Matrix<int> m1(0,0),  m2(0,0),  m3(0,0);

	do
	{
		cout << "int\n";
		cout << "Menu:\n1 - Input\n2 - Output\n3 - Operations\n0 - Exit\n";
		input = -1;
		cin >> input;
		switch (input)
		{
		case 1:

			input = -1;
			cout << "Input:\nFrom console - 1\n||Generation - 2||\n";
			cin >> input;
			switch (input)
			{
			case 1:
			{
				//				delete m1;
				//				delete m2;
				//				delete m3;
				cout << "Enter  matrix1 lines\n";
				cin >> x;
				cout << "Enter  matrix1 columns\n";
				cin >> y;
				cout << "Enter  matrix1 defaunt value\n";
				cin >> z;
				Matrix<int> tmp1(x, y, z);
				m1 = tmp1;
				
				cout << "Enter  matrix2 lines\n";
				cin >> x;
				cout << "Enter  matrix2 columns\n";
				cin >> y;
				cout << "Enter  matrix2 defaunt value\n";
				cin >> z;
				Matrix<int> tmp2(x, y, z);
				m2 = tmp2;
				
				break;
			}
			case 2:
				//later
				break;
			default:
				break;
			}
			break;

		case 2:
			cout << "Matrix1:\n";
			m1.print();
			cout << m1.GetLines();
			cout << "Matrix2:\n";
			m2.print();
			cout << "Matrix3:\n";
			m3.print();
			break;
		case 3:
			input = -1;
			cout << "Operations:\nMatrix sum(m3=m1+m2) - 1\nMatrix mult(m3=m1*m2) - 2\n";
			cin >> input;
			switch (input)
			{
			case 1:
				m3 = m1 + m2;
				break;
			case 2:
				m3 = m1 * m2;
				break;
			case 3:

				break;
			default:
				break;
			}
			break;
		case 0:

			q = 0;
			break;
		default:
			break;
		}

	} while (q);
}
*/
int main()
{

//	ListSequence<int> s1;

//	cout << a;
	int t = 1;
	cout << "what type of elements?\nint - 1\ndouble - 2\ncomplex - 3\n";
	cin >> t;
	TextDialog(t);
	
//    std::cout << "Hello World!\n";
}

