#include"matrix class.cpp"
matrix transpose(matrix x)
{
	int i, j;
	matrix y = x;
	y.nc = x.nr;
	y.nr = x.nc;
	for (i = 1; i <= y.nr; i++)
	for (j = 1; j <= y.nc; j++)
		y.str[i][j] = x.str[j][i];
	return y;
}
matrix echelon(matrix m)
{
	int r, c, found = 0;
	for (r = 1; r <= m.nr; r++)
	{

		for (m.i = r; (m.i <= m.nr) && (found == 0); m.i++)
		for (m.j = 1; (m.j <= m.nc) && (found == 0); m.j++)
		if (m.str[m.i][m.j] != 0)
			found++;
		m.i--; m.j--; found--;
		//cout << m.i << "\/" << m.j << "\/" << m.str[m.i][m.j];
		c = m.j;
		if (m.i != r)
			m.row(r, 'c', m.i);
		//m.display();
		/*float p = m.str[r][c];*/
		//cout << '"' << r << c << '"' << endl;
		if (m.str[r][c] != 1)
			m.rowo(r, '/', m.str[r][c]);
		//m.display();
		//cout << '"' << r << c << '"' << endl;
		for (int n = r - 1; n >= 1; n--)
		if (m.str[n][c] != 0)
		{
			float v = m.str[n][c];
			m.rowo(r, '*', v);
			m.row(n, '-', r);
			m.rowo(r, '/', v);
			int brek = 0;
			for (int i = 1; i <= m.nc; i++)
			{
				if ((m.str[n][i]<0.000001) && (m.str[n][i]>0))
				{
					m.o(n);
					return (m);
				}
				if ((m.str[n][i]>-0.000001) && (m.str[n][i] < -0))
				{
					m.o(n);
					return (m);
				}
				if (m.str[n][i] == 0)brek++;
			}
			if (brek == m.nc)return m;
		}
		//m.display();
		//cout << '"' << r << c << '"' << endl;
		for (int n = r + 1; n <= m.nr; n++)
		if (m.str[n][c] != 0)
		{
			float v = m.str[n][c];
			m.rowo(r, '*', v);
			m.row(n, '-', r);
			m.rowo(r, '/', v);
			int brek = 0;
			for (int i = 1; i <= m.nc; i++)
			{
				if ((m.str[n][i]<0.000001) && (m.str[n][i]>0))
				{
					m.o(n);
					return (m);
				}
				if ((m.str[n][i]>-0.000001) && (m.str[n][i] < -0))
				{
					m.o(n);
					return (m);
				}
				if (m.str[n][i] == 0)brek++;
			}
			if (brek == m.nc)return m;
		}

		//m.display();
	}
	return m;
}
matrix solution(matrix x)
{
	matrix sol;
	if (x.nc > x.nr)
	{
		cout << "number of equation must be greater then equal to number of variables";
			return sol;
	}
	sol = echelon(x);
	return sol;
}
//double determinant(matrix x)
//{
//	double minor[11] = { 0 }, cofactor[11];
//	double det = 0;
//	if (x.nc != x.nr)
//	{
//		cout << "It is not a square matrix";
//		return 0;
//	}
//	matrix temp = echelon(x);
//	for (temp.i = 1; temp.i <= temp.nr; temp.i++)
//	{
//		for (temp.j = 1; temp.j <= temp.nc; temp.j++)
//			minor[temp.i] += temp.str[temp.i][temp.j];
//		if (minor[temp.i] == 0)
//		{
//			cout << 'a';
//			return 0;
//		}
//
//	}
//	for (temp.i = 1; temp.i <= temp.nc; temp.i++)
//	{
//		for (temp.j = 1; temp.j <= temp.nr; temp.j++)
//			minor[temp.i] += temp.str[temp.j][temp.i];
//		if (minor[temp.i] == 0)
//		{
//			cout << 'b';
//			return 0;
//		}
//	}
//	if (x.nc != 1)
//	for (int colom = 1; colom <= x.nc; colom++)
//	{
//		matrix a = x;
//		a.rowo(rownum, 'd', rownum);
//		a.colomo(colom, 'd', colom);
//		//a.display();
//		minor[colom] = determinant(a);
//		//cout << minor[colom] << "minor" << colom << endl;
//	}
//	else
//		return x.str[1][1];
//	for (int colom = 1; colom <= x.nc; colom++)
//	{
//		cofactor[colom] = pow(-1, rownum + colom)*minor[colom]; //cout << cofactor[colom] << "cofactor" << colom << endl;
//	}
//	for (int colom = 1; colom <= x.nc; colom++)
//		det += x.str[rownum][colom] * cofactor[colom];
//	return det;
//}
//matrix adjoint(matrix x)
//{
//	matrix minor, cofactor;
//	minor.nc = cofactor.nc = x.nc;
//	minor.nr = cofactor.nr = x.nr;
//	if (x.nc != x.nr)
//	{
//		cout << "It is not a square matrix";
//		return 0;
//	}
//	for (int row = 1; row <= x.nr;row++)
//	for (int colom = 1; colom <= x.nc; colom++)
//	{
//		matrix a = x;
//		a.rowo(row, 'd', row);
//		a.colomo(colom, 'd', colom);
//		//a.display();
//		minor.str[row][colom] = (float)determinant(a);
//		cout << minor.str[row][colom] << endl;
//	}
//	minor.display();
//	for (int row = 1; row <= x.nr; row++)
//	for (int colom = 1; colom <= x.nc; colom++)
//	{
//		cofactor.str[row][colom] = pow(-1, row + colom)*minor.str[row][colom]; //cout << cofactor[colom] << "cofactor" << colom << endl;
//	}
//	cofactor.display();
//	return transpose(cofactor);
//}
double determinant(matrix x)
{
	if (x.nc != x.nr)
			{
				cout << "It is not a square matrix";
				return 0;
			}
	if (fact(x) == 0)
		return 0;
	matrix low = factorise(x, 'l');
	double l=1;
	for (int i = 1; i <= low.nc; i++)
		l *= low.str[i][i]; 
	return l;
}
matrix inverse(matrix m)
{
	if (m.nc != m.nr)
	{
		cout << "It is not a square matrix"<<endl;
		return 0;
	}
	if (determinant(m) == 0)
	{
		cout << "Determinant of given matrix is zero." << endl<<" Inverse is not possible." << endl;
		return 0;
	}
	int r, c, found = 0;
	matrix result(m.nc);
	//result.display();
	for (r = 1; r <= m.nr; r++)
	{

		for (m.i = r; (m.i <= m.nr) && (found == 0); m.i++)
		for (m.j = 1; (m.j <= m.nc) && (found == 0); m.j++)
		if (m.str[m.i][m.j] != 0)
			found++;
		m.i--; m.j--; found--;
		//cout << m.i << "\/" << m.j << "\/" << m.str[m.i][m.j];
		c = m.j;
		if (m.i != r)
		{
			m.row(r, 'c', m.i); result.row(r, 'c', m.i);
		}
		//m.display(); result.display();
		/*float p = m.str[r][c];*/
		//cout << '"' << r << c << '"' << endl;
		if (m.str[r][c] != 1)
		{
			float a = m.str[r][c];
			m.rowo(r, '/', a); result.rowo(r, '/', a);
		}
		//m.display();
		//cout << '"' << r << c << '"' << endl;
		for (int n = r - 1; n >= 1; n--)
		if (m.str[n][c] != 0)
		{
			float v = m.str[n][c];
			m.rowo(r, '*', v); result.rowo(r, '*', v);
			m.row(n, '-', r); result.row(n, '-', r);
			m.rowo(r, '/', v); result.rowo(r, '/', v);
		}
		//m.display(); result.display();
		//cout << '"' << r << c << '"' << endl;
		for (int n = r + 1; n <= m.nr; n++)
		if (m.str[n][c] != 0)
		{
			float v = m.str[n][c];
			m.rowo(r, '*', v); result.rowo(r, '*', v);
			m.row(n, '-', r); result.row(n, '-', r);
			m.rowo(r, '/', v); result.rowo(r, '/', v);
		}

		//m.display(); result.display();
	}
	return result;
}
matrix factorise(matrix x,char ch)
{
	if (x.nc != x.nr)
	{
		cout << "it is not a square matrix" << endl;
		return 0;
	}
	if (x.str[1][1] == 0)
	{
		cout << "factorization is not possible" << endl;
		return 0;
	}
		
	matrix l, u;
	int n=x.nr;
	l.nc = u.nc  = x.nc;
	l.nr = u.nr = x.nr;
	for (int i = 1; i <= n; i++)
	{
		//cout << i;
		l.str[1][i] = 0;
		l.str[i][1] = x.str[i][1];
		u.str[i][1] = 0;
		u.str[1][i] = x.str[1][i] / x.str[1][1];
	}
	int N;
	matrix ld[11], ud[11];
	for (int i = 1; i <= 10; i++)
	{
		ld[i].nr = 1;
		ud[i].nc = 1;
	}
	for (N=2; N <= n;N++)
	{
		for (int i = N; i <= n; i++)
		{
			ld[i].nc = N - 1;
			for (int k = 1; k <= N - 1; k++)
				ld[i].str[1][k] = l.str[i][k];
		}
		for (int j = N; j <= n; j++)
		{
			ud[j].nr = N - 1;
			for (int k = 1; k <= N - 1; k++)
				ud[j].str[k][1] = u.str[k][j];
		}
		for (int i = N; i <= n; i++)
		{
			l.str[N][i] = 0;
			float temp = (ld[i] * ud[N]).str[1][1];
			l.str[i][N] = x.str[i][N] - temp;
		}
		if (l.str[N][N] == 0)
		{
				cout << "factorization is not possible" << endl;
				return 0;
		}
		u.str[N][N] = 1;
		if (N == n)
			break;
		for (int j = N + 1; j <= n; j++)
		{
			u.str[j][N] = 0;
			float temp = (ld[N] * ud[j]).str[1][1];
			u.str[N][j] = (x.str[N][j] -  temp)/ l.str[N][N];
		}
	}
	switch (ch)
    {
	case 'a':
		l.display();
		u.display(); return 0; break;
	case 'l':
			return l;
	case'u':
			return u;
	default:
		break;
	}
	//l = l*u;
	//l.display();
}
int fact(matrix x)
{
	matrix l, u;
	int n = x.nr;
	l.nc = u.nc = x.nc;
	l.nr = u.nr = x.nr;
	for (int i = 1; i <= n; i++)
	{
		//cout << i;
		l.str[1][i] = 0;
		l.str[i][1] = x.str[i][1];
		u.str[i][1] = 0;
		u.str[1][i] = x.str[1][i] / x.str[1][1];
	}
	int N;
	matrix ld[11], ud[11];
	for (int i = 1; i <= 10; i++)
	{
		ld[i].nr = 1;
		ud[i].nc = 1;
	}
	for (N = 2; N <= n; N++)
	{
		for (int i = N; i <= n; i++)
		{
			ld[i].nc = N - 1;
			for (int k = 1; k <= N - 1; k++)
				ld[i].str[1][k] = l.str[i][k];
		}
		for (int j = N; j <= n; j++)
		{
			ud[j].nr = N - 1;
			for (int k = 1; k <= N - 1; k++)
				ud[j].str[k][1] = u.str[k][j];
		}
		for (int i = N; i <= n; i++)
		{
			l.str[N][i] = 0;
			float temp = (ld[i] * ud[N]).str[1][1];
			l.str[i][N] = x.str[i][N] - temp;
		}
		if (l.str[N][N] == 0)
			return 0;
		u.str[N][N] = 1;
		if (N == n)
			break;
		for (int j = N + 1; j <= n; j++)
		{
			u.str[j][N] = 0;
			float temp = (ld[N] * ud[j]).str[1][1];
			u.str[N][j] = (x.str[N][j] - temp) / l.str[N][N];
		}
	}
	return 1;
}
//void main()
//{
//	matrix a, b;
//	double ab;
//	a.get();
//	a.display();
//	//factorise(a);
//	/*ab = determinant(a);
//	cout << ab;*/
//	b = inverse(a);
//	//a = solution(a);
//	b.display();
//	a = a*b;
//	a.display();
//	system("PAUSE");
//}
