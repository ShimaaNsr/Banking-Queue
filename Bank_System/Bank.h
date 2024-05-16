#pragma once
#include <queue>
#include "Customer.h"
struct CompareCustomerTime
{
	bool operator()(const Customer& lhs, Customer& rhs) const
	{
		return  lhs.CustomerTime > rhs.CustomerTime;

	}
};

struct Taller
{
	int TallorNumber = 3;
	int NumberOfServedCustomers;
	int AvalabileTime;
	bool IsAvailable;
	int TotalServedTime;
};

class Bank
{
private:
	int BankTime;
	int TallersNum = 3;
	int NumberOfAvailableTallors = 3;
	int CustomerTime;
	Taller* tallers;
	int TotalServingTime;
	int TotalWaittingTime;
	Taller* findNearestAvailableTeller();
	void displayTellerDetails2();
	queue<Customer> WaitingQueue;
	priority_queue<Customer, vector<Customer>,CompareCustomerTime> ServingQueue;
	void AddCustomerToWaitingQueue(Customer c1);
	void AddCustomerToServingQueue(Customer c1);
	void CustomersTitle();
	void TellersTitle();
	void BankTitle();
	void DisplayCustomer(Customer c1,int t1,int AvvivalTime);
	void DisplayTeller();
	void DisplayBank();
public:
	Bank();
	void AddCustomer(Customer c1);
	void RunBankProcess();

};

