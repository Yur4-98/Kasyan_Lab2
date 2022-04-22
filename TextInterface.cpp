#include "Matrix.h"
#include "Interfaces.h"

void TextDialog(int t)
{
	if (t == 1) {
		int q = 1;
		int input = 0;
		int x, y, z;
		Matrix<int> m1(0, 0), m2(0, 0), m3(0, 0);
		cout << "int\n";
		do
		{

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
					cin >> y;
					cout << "Enter  matrix1 columns\n";
					cin >> x;
					cout << "Enter  matrix1 defaunt value\n";
					cin >> z;
					Matrix<int> tmp1(x, y, z);
					m1 = tmp1;

					cout << "Enter  matrix2 lines\n";
					cin >> y;
					cout << "Enter  matrix2 columns\n";
					cin >> x;
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
				cout << "Operations:\nMatrix sum(m3=m1+m2) - 1\nMatrix mult(m3=m1*m2) - 2\nMatrix Multipline by const(m3 = m1 * const";
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
					int c;
					cout << "Enter  const\n";
					cin >> c;
					m3 = m1 * c;
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
	if (t == 2) {
		int q = 1;
		int input = 0;
		int x, y;
		double z;
		Matrix<double> m1(0, 0), m2(0, 0), m3(0, 0);
		cout << "int\n";
		do
		{

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
					cin >> y;
					cout << "Enter  matrix1 columns\n";
					cin >> x;
					cout << "Enter  matrix1 defaunt value\n";
					cin >> z;
					Matrix<double> tmp1(x, y, z);
					m1 = tmp1;

					cout << "Enter  matrix2 lines\n";
					cin >> y;
					cout << "Enter  matrix2 columns\n";
					cin >> x;
					cout << "Enter  matrix2 defaunt value\n";
					cin >> z;
					Matrix<double> tmp2(x, y, z);
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
				cout << "Operations:\nMatrix sum(m3=m1+m2) - 1\nMatrix mult(m3=m1*m2) - 2\nMatrix Multipline by const(m3 = m1 * const";
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
					int c;
					cout << "Enter  const\n";
					cin >> c;
					m3 = m1 * c;
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
	
	if (t == 3) {
		int q = 1;
		int input = 0;
		int x, y,x1,x2;
		Complex z;
		Matrix<Complex> m1(0, 0), m2(0, 0), m3(0, 0);
		cout << "int\n";
		do
		{

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
					cin >> y;
					cout << "Enter  matrix1 columns\n";
					cin >> x;
					cout << "Enter  matrix1 defaunt value Re\n";
					cin >> x1;
					cout << "Enter  matrix1 defaunt value Im\n";
					cin >> x2;
					z = Complex(x1, x2);
					Matrix<Complex> tmp1(x, y, z);
					m1 = tmp1;

					cout << "Enter  matrix2 lines\n";
					cin >> y;
					cout << "Enter  matrix2 columns\n";
					cin >> x;
					cout << "Enter  matrix2 defaunt value Re\n";
					cin >> x1;
					cout << "Enter  matrix1 defaunt value Im\n";
					cin >> x2;
					z = Complex(x1, x2);
					
					Matrix<Complex> tmp2(x, y, z);
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
				cout << "Operations:\nMatrix sum(m3=m1+m2) - 1\nMatrix mult(m3=m1*m2) - 2\nMatrix Multipline by const(m3 = m1 * const";
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
					int c;
					cout << "Enter  const\n";
					cin >> c;
					m3 = m1 * c;
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
	
}
