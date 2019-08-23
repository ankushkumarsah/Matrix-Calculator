#include "basic.cpp"
void work();
int main()
{
	while (1)
	{
		cout << "enter your choice" << endl;
		cout << "1.transpose" << endl;
		cout << "2.echelon" << endl;
		cout << "3.solution" << endl;
		cout << "4.determinant" << endl;
		cout << "5.inverse" << endl;
		cout << "6.factorise" << endl;
		cout << "7.work sheet" << endl;
		cout << "8.exit" << endl;
		int choice;
		cin >> choice;
		matrix m;
		switch (choice)
		{
		case 1:
			m.get();
			m = transpose(m);
			m.display();
			break;
		case 2:
			m.get();
			m = echelon(m);
			m.display();
			break;
		case 3:
			m.get_eq();
			m = solution(m);
			m.display_eq();
			break;
		case 4:
			m.get();
			cout << determinant(m)<<endl;
			break;
		case 5:
			m.get();
			m = inverse(m);
			m.display();
			break;
		case 6:
			m.get();
			factorise(m, 'a');
			break;
		case 7:
			work();
			break;
		case 8:
			exit(0);
		default:
			cout << "invalid choice. try again" << endl;
			break;
		}
	}
}