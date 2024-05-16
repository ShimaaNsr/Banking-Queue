
#include <iostream>
#include <queue>
#include "Bank.h"
#include "Customer.h"
using namespace std;
int main()
{
	Bank MyBank;

	//Customer c1(1,"shimaa", 35, 62);
	//MyBank.AddCustomer(c1);
	////cout << "----------------------------------------------------\n";
	//Customer c2(2,"samaa", 39, 57);
	//MyBank.AddCustomer(c2);
	////cout << "----------------------------------------------------\n";
	//Customer c3(3,"m7md", 78, 124);
	//MyBank.AddCustomer(c3);
	////cout << "----------------------------------------------------\n";
	//Customer c4(4,"mera", 79, 32);
	//MyBank.AddCustomer(c4);
	////cout << "----------------------------------------------------\n";
	//Customer c5(5,"heba", 80, 15);
	//MyBank.AddCustomer(c5);
	////cout << "----------------------------------------------------\n";
	//Customer c6(6,"khaled", 90, 10);
	//MyBank.AddCustomer(c6);
	////cout << "----------------------------------------------------\n";
	//Customer c7(7,"nsr", 95, 20);
	//MyBank.AddCustomer(c7);
	////cout << "----------------------------------------------------\n";
	//Customer c8(8,"mona", 107, 20);
	//MyBank.AddCustomer(c8);
	////cout << "----------------------------------------------------\n";

	int CustomersNum;
	

	cout << "How Many Customers We Will Serve ?" << endl;
	cin >> CustomersNum;
	for (int i = 0;i < CustomersNum;i++)
	{
		cout << "Enter The Data Of The Client Number " << i + 1 << "\n\n";
		int number;
		cout<<"Number: ";
		cin>>number;
		string name;
		cout << "Name: ";
		cin >> name;
		cout << "\n";
		int  time;
		cout << "Time When The Client Enter The Bank: ";
		cin >> time;
		cout << "\n";
		int  servingtime;
		cout << "Time It Will Take To Complete The Client's Service: ";
		cin >> servingtime;
		cout << "\n";
		Customer c1(number,name, time, servingtime);
		MyBank.AddCustomer(c1);
	}
	MyBank.RunBankProcess();
}
	


