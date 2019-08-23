/*matrix class with three constructor 1.to create a matrix from single value of oder cnXrn
                                        matrix(value,number of columns,number of rows)
									  2.creat unit matrix of n oder
									    matrix(number of columns or rows) 
									  3.defult constructor NULL matrix
*/
#include<iostream>
#include<stdio.h>
using namespace std;
class matrix
{
public:
	float str[11][11];
	int nc, nr, i, j, k;
	//creats matrix from single value of oder cnXrn
	matrix(float x, int rn, int cn)
	{
		for (i = 1; i <= rn; i++)
		{
			for (j = 1; j <= cn; j++)
				str[i][j] = x;
		}
		nc = cn;
		nr = rn;
		p();
		k = 0;
	}
	//creats unit matrix of oder NxN
	matrix(int n)
	{
		for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
		{
			if (i==j)
				str[i][j] = 1;
			else
				str[i][j] = 0;
		}
		nc = nr = n;
		p();
	}
	//defult constructor NULL matrix
	matrix()
	{
		for (i = 1; i <= 10; i++)
		{
			for (j = 1; j <= 10; j++)
				str[i][j] = '/0';
		}
		nc = nr = 10;
		p(); o(0);
	}
	void get()
	{
		cout << "enter the size of matrix";
		cin >> nr >> nc;
		cout << "enter your matrix:" << endl;
		for (i = 1; i <= nr; i++)
		{
			for (j = 1; j <= nc; j++)
				cin >> str[i][j];
		}
		p();
	}
	void display()
	{
		for (i = 1; i <= nr; i++)
		{
			for (j=1; j <= nc; j++)
				cout << str[i][j] << " ";
			cout << endl;
		}
		cout << endl;
	}
	//void get_eq()
	//{
	//	char sstr[2][11][30];
	//	cout << "enter number of equations:";
	//	cin >> nr;
	//	matrix(0, nr, 10);
	//	for (int i = 1; i <= nr; i++)
	//	{
	//		char check;
	//		cout << "enter equation " << i << ':';
	//		cin >> sstr[1][i];
	//		cin >> check;
	//		cin >> sstr[2][i];
	//		if (check != '=')
	//		{
	//			cout << "please use the '=' symbol and space to separate EXAMPLE:" << endl << "4x+4y-3z = 2x+5" << endl;
	//			i--;
	//		}
	//		else
	//		{
	//			int length_sst1 = strlen(sstr[1][i]);
	//			for (int j = 0; j < length_sst1; j++)
	//			{
	//				if ((sstr[1][i][j] >= 40) && (sstr[1][i][j] <= 47))
	//				{
	//					j++;
	//					k++;
	//					for (int desimal = 1; ((sstr[1][i][j] >= 48) && (sstr[1][i][j] <= 57)); desimal *= 10)
	//					{
	//						static char sympol = sstr[1][i][j - 2];
	//						direct(i, k, '*', desimal);
	//						direct(i, k,sympol, (sstr[1][i][j] - 48));
	//						j++;
	//					}
	//					//if ((sstr[1][i][j] >= 97) && (sstr[1][i][j] <= 122))
	//					str[0][k] = sstr[1][i][j];
	//				}
	//				else
	//				{
	//					k++;
	//					for (int desimal = 1; ((sstr[1][i][j] >= 48) && (sstr[1][i][j] <= 57)); desimal *= 10)
	//					{
	//						direct(i, k, '*', desimal);
	//						direct(i, k, '+', (sstr[1][i][j] - 48));
	//						j++;
	//					}
	//					//if ((sstr[1][i][j] >= 97) && (sstr[1][i][j] <= 122))
	//					str[0][k] = sstr[1][i][j];
	//				}
	//			}
	//			int length_sst2 = strlen(sstr[2][i]);
	//			for (int j = 0; j < length_sst2; j++)
	//			{
	//				if ((sstr[2][i][j] >= 40) && (sstr[2][i][j] <= 47))
	//				{
	//					j++;
	//					for (int desimal = 1; ((sstr[2][i][j] >= 48) && (sstr[2][i][j] <= 57)); desimal *= 10)
	//					{
	//						static char sympol = sstr[2][i][j - 2];
	//						direct(i, 0, '*', desimal);
	//						direct(i, 0, sympol, (sstr[2][i][j] - 48));
	//						j++;
	//					}
	//				}
	//				else
	//				{
	//					for (int desimal = 1; ((sstr[2][i][j] >= 48) && (sstr[2][i][j] <= 57)); desimal *= 10)
	//					{
	//						direct(i, 0, '*', desimal);
	//						direct(i, 0, '+', (sstr[2][i][j] - 48));
	//						j++;
	//					}
	//				}
	//				//if ((sstr[1][i][j] >= 97) && (sstr[1][i][j] <= 122))
	//			}
	//		}
	//		k = 0;
	//	}
	//}
	//void get_eq()
	//{
	//	cout << "enter number of equation:";
	//	cin >> nr;
	//	for (int i = 1; i <= nr; i++)
	//	{
	//		int j = 0;
	//		cout << "enter equation " << i << endl;
	//		char  variable;
	//		float value;
	//		do
	//		{
	//			j++;
	//			cin >> value >> variable;
	//			str[i][j] = value;
	//		} while (variable == ' ');
	//		str[i][j] = '\0';
	//		cin >> str[i][0];
	//	}
	//}
    void get_eq()
{
	    cout << "enter number of equations:";
		cin >> nr;
		cout << "enter number of variables:";
		cin >> nc;
		cout << "enter coefficients:" << endl;
		char a = 96;
		for (int i = 0; i < nc; i++)
			cout << ++a<<" ";
		cout << "constant" << endl;
		for (i = 1; i <= nr; i++)
		{
			for (j = 1; j <= nc; j++)
				cin >> str[i][j];
			cin >> str[i][0];
		}

}
	void display_eq()
	{

		for (i = 1; i <= nr; i++)
		{
			char a = 96;
			for (j = 1; j <= nc; j++)
			{
				if (str[i][j]<0)
					cout << str[i][j] << ++a;
				else if ((str[i][j]>0)&&(j!=0))
					cout << '+' << str[i][j] << ++a;
				else if ((str[i][j]>0) && (j == 1))
					cout << str[i][j] << ++a;
				else
					++a;
			}
			cout << '=' << str[i][0] << endl;
		}
	}
	void direct(int rn, int cn, char ch, float num)
	{
		switch (ch)
		{
		case('+') :
			str[rn][cn] += num; break;
		case('-'):
			str[rn][cn] -= num; break;
		case('*'):
			str[rn][cn] *= num; break;
		case('/'):
			str[rn][cn] /= num; break;
		default:
			break;
		}
	}
	//multiplication of matrix and retuns results
	matrix operator*(matrix y)
	{
		matrix rslt;
		if (nc != y.nr)
		{
			cout << "\nnumber of coloms of 1st matrix and rows of 2nd matrix are not equal " << endl;
			return 0;
		}
		else
		{
			rslt.nr = nr;
			rslt.nc = y.nc;
			for (i = 1; i <= rslt.nc; i++)
			for (j = 1; j <= rslt.nr; j++)
				rslt.str[i][j] = 0;
			for (i = 1; i <= rslt.nr; i++)
			for (j = 1; j <= rslt.nc; j++)
			for (k = 1; k <= nc; k++)
			{
				//cout << "c" << i << j << "=" << str[i][j] << "+" << "(" << str[i][k] << "*" << y.str[k][j] << ")" << endl;
				rslt.str[i][j] += str[i][k] * y.str[k][j];
			}
		}
		return rslt;
	}
	matrix operator*(float y)
	{
		matrix rslt;
		rslt.nr = nr;
		rslt.nc = nc;
		for (i = 1; i <= rslt.nr; i++)
		for (j = 1; j <= rslt.nc; j++)
			rslt.str[i][j] = 0;
		for (i = 1; i <= rslt.nr; i++)
		for (j = 1; j <= rslt.nc; j++)
		{
			//cout << "c" << i << j << "=" << str[i][j] << "+" << "(" << str[i][k] << "*" << y.str[k][j] << ")" << endl;
			rslt.str[i][j] = str[i][j] * y;
		}
		return rslt;
	}
	//add two matrixs and returns result matrix
	matrix operator+(matrix y)
	{
		matrix rslt;
		if (nc == y.nc&&nr == y.nr)
		{
			rslt.nc = nc; rslt.nr = nr;
			for (int i = 1; i <= rslt.nr; i++)
			for (int j = 1; j <= rslt.nc; j++)
				rslt.str[i][j] = str[i][j] + y.str[i][j];
		}
		else
		{
			cout << "\nboth matrix's coloms and rows are not equal";
			return 0;
		}
		return rslt;
	}
	matrix operator+(float y)
	{
		matrix rslt;
		rslt.nr = nr;
		rslt.nc = nc;
		for (i = 1; i <= rslt.nr; i++)
		for (j = 1; j <= rslt.nc; j++)
			rslt.str[i][j] = 0;
		for (i = 1; i <= rslt.nr; i++)
		for (j = 1; j <= rslt.nc; j++)
		{
			//cout << "c" << i << j << "=" << str[i][j] << "+" << "(" << str[i][k] << "*" << y.str[k][j] << ")" << endl;
			rslt.str[i][j] = str[i][j] +y;
		}
		return rslt;
	}
	//substract two matrixs and returns result matrix
	matrix operator-(matrix y)
	{
		matrix rslt;
		if (nc == y.nc&&nr == y.nr)
		{
			rslt.nc = nc; rslt.nr = nr;
			for (int i = 1; i <= rslt.nr; i++)
			for (int j = 1; j <= rslt.nc; j++)
				rslt.str[i][j] = str[i][j] - y.str[i][j];
		}
		else
		{
			cout << "\nboth matrix's coloms and rows are not equal";
			//re(x,y);
		}
		return rslt;
	}
	matrix operator-(float y)
	{
		matrix rslt;
		rslt.nr = nr;
		rslt.nc = nc;
		for (i = 1; i <= rslt.nr; i++)
		for (j = 1; j <= rslt.nc; j++)
			rslt.str[i][j] = 0;
		for (i = 1; i <= rslt.nr; i++)
		for (j = 1; j <= rslt.nc; j++)
		{
			//cout << "c" << i << j << "=" << str[i][j] << "+" << "(" << str[i][k] << "*" << y.str[k][j] << ")" << endl;
			rslt.str[i][j] = str[i][j] -y;
		}
		return rslt;
	}
	void row(int result, char oprtr, int target)
	{
		switch (oprtr){
		case('+') :
			for (i = 0; i <=nc; i++)
				str[result][i] = str[result][i] + str[target][i];
			break;
		case('-') :
			for (i = 0; i <= nc; i++)
				str[result][i] = str[result][i] - str[target][i];
			break;
		case('*') :
			for (i = 1; i <=nc; i++)
				str[result][i] = str[result][i] * str[target][i];
			break;
		case('/') :
			for (i = 1; i <= nc; i++)
				str[result][i] = str[result][i] / str[target][i];
			break;
		case('c') :
			for (i = 0; i <= nc; i++)
			{
				float temp = str[result][i];
				str[result][i] =str[target][i];
				str[target][i] = temp;
			}
			break;
		default:
			cout << "invalid operator";
		}
	}
	void colom(int result,char oprtr, int target)
	{
		switch (oprtr){
		case('+') :
			for (i = 1; i <=nr; i++)
				str[i][result] = str[i][result] + str[i][target];
			break;
		case('-') :
			for (i = 1; i <=nr; i++)
				str[i][result] = str[i][result] - str[i][target];
			break;
		case('*') :
			for (i = 1; i <=nr; i++)
				str[i][result] = str[i][result] * str[i][target];
			break;
		case('/') :
			for (i = 1; i <=nr; i++)
				str[i][result] = str[i][result] / str[i][target];
			break;
		case('c') :
			for (i = 1; i <= nr; i++)
			{
				float temp = str[i][result];
				str[i][result] = str[i][target];
				str[i][target] = temp;
			}
			break;
		default:
			cout << "invalid operator";
		}
	}
	void rowo(int result, char oprtr, float num)
	{
		switch (oprtr){
		case('+') :
			for (i = 1; i <= nc; i++)
				str[result][i] = str[result][i] + num;
			break;
		case('-') :
			for (i = 1; i <= nc; i++)
				str[result][i] = str[result][i] - num;
			break;
		case('*') :
			for (i = 0; i <= nc; i++)
				str[result][i] = str[result][i] * num;
			break;
		case('/') :
			for (i = 0; i <= nc; i++)
				str[result][i] = str[result][i] / num;
			break;
		case('d') :
			for (i = num; i <= nc; i++)
				row(i, 'c', i + 1);
				nr--;
			break;
		default:
			cout << "invalid operator";
		}
	}
	void colomo(int result, char oprtr, float num)
	{
		switch (oprtr){
		case('+') :
			for (i = 1; i <= nr; i++)
				str[i][result] = str[i][result] + num;
			break;
		case('-') :
			for (i = 1; i <= nr; i++)
				str[i][result] = str[i][result] - num;
			break;
		case('*') :
			for (i = 1; i <= nr; i++)
				str[i][result] = str[i][result] * num;
			break;
		case('/') :
			for (i = 1; i <= nr; i++)
				str[i][result] = str[i][result] / num;
			break;
		case('d') :
			for (i = num; i <= nr; i++)
				colom(i, 'c', i + 1);
			nc--;
			break;
		default:
			cout << "invalid operator";
		}
	}
	void o(int n)
	{
		for (i = 1; i <= nc; i++)
			str[n][i] = 0;
	}
	void p()
	{
		for (int i = 0; i < nr; i++)
			str[i][0] = 0;
	}
}; 
matrix transpose(matrix);
int fact(matrix);
matrix echelon(matrix m);
matrix solution(matrix x);
double determinant(matrix x);
matrix inverse(matrix m);
matrix factorise(matrix x, char ch);