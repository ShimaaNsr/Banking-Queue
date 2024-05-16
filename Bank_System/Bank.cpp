#include "Bank.h"
#include "Customer.h"
#include <iostream>
using namespace std;



Bank::Bank()
{
	tallers = new Taller[TallersNum];
	for (int i = 0; i < TallersNum; i++)
	{
		tallers[i].IsAvailable = true;
		tallers[i].TallorNumber = i + 1;
		tallers[i].NumberOfServedCustomers = 0;
		tallers[i].AvalabileTime = 0;
		tallers[i].TotalServedTime = 0;
	}
}

Taller* Bank::findNearestAvailableTeller()
{
	Taller* NearestTaller = nullptr;
	int NearestAvailableTime = INT_MAX;
	for (int i = 0; i < TallersNum;i++)
	{
		if (tallers[i].AvalabileTime < NearestAvailableTime)
		{
			NearestTaller = &tallers[i];
			NearestAvailableTime = tallers[i].AvalabileTime;
		}
	}
	return NearestTaller;
}

//void Bank::displayTellerDetails2()
//{
//	cout << "Our Tellers Details" << endl << endl;
//	for (int i = 0; i < TallersNum;i++)
//	{
//		cout << "teller Number " << i+1 << "Total Serving Time = " << tallers[i].TotalServedTime << " Total Number Of Custmer Which Served By Whom = " << tallers[i].NumberOfServedCustomers << endl << endl;
//	}
//	
//}

void Bank::AddCustomerToWaitingQueue(Customer c1)
{
	WaitingQueue.push(c1);
}

void Bank::AddCustomerToServingQueue(Customer c1)
{
	ServingQueue.push(c1);
}

void Bank::CustomersTitle()
{
	cout << "Customer Number \tCustomer Name  \t Customer Arrival Time \t Customer Serving Time \t Customer Leaving Time \t Served By Tellers Number\n";
}

void Bank::TellersTitle()
{
	cout << "Tellers Details: \n\n";
	cout << "Taller Number \t\t Number Of Customer Served By It \t Total Server Time By It\n";
}

void Bank::BankTitle()
{
	cout << "Bank Details: " << "\n\n";
	cout << "Total Waitting Time \t\t Total Serving Time \n";
}

void Bank::DisplayCustomer(Customer c1,int t,int ArivalTime)
{
	cout << c1.CustomerNumber << "    \t\t\t " << c1.Name << "\t\t  " << ArivalTime << "\t\t\t  " << c1.ServingTime << "\t\t\t  " << c1.CustomerTime <<"\t\t\t  "<<t<<"\n";
}

void Bank::DisplayTeller()
{
	for (int i = 0;i < TallersNum;i++)
	{
		cout << tallers[i].TallorNumber << "\t\t\t " << tallers[i].NumberOfServedCustomers << "\t\t\t\t\t " << tallers[i].TotalServedTime << "\n";
	}
}

void Bank::DisplayBank()
{
	cout << TotalServingTime << "\t\t\t\t " << TotalWaittingTime << "\n";
}

void Bank::AddCustomer(Customer c1)
{
	if (NumberOfAvailableTallors != 0)
	{
		AddCustomerToServingQueue(c1);	
	}
	else
	{
		AddCustomerToWaitingQueue(c1);
	}
	//cout << "Customer Number " << c1.CustomerNumber << "\n\n";
}


void Bank::RunBankProcess()
{
	cout << "\n\n\n";
	CustomersTitle();
	cout << "------------------------------------------------------------------------------------------------------------------------------------------" << endl;

	while (!ServingQueue.empty())
	{
		Customer Current_Customer = ServingQueue.top();
		BankTime = Current_Customer.CustomerTime;
		ServingQueue.pop();
		if (Current_Customer.CustomerType == "Arival")
		{
			bool done = false;
			for (int i = 0;i < TallersNum; i++)
			{
				if (tallers[i].IsAvailable)
				{
					Current_Customer.WaitingTime = BankTime - Current_Customer.CustomerTime;
					Current_Customer.CustomerType = "Departure";
					int arival = Current_Customer.CustomerTime;
					Current_Customer.CustomerTime = BankTime + Current_Customer.ServingTime;
					TotalServingTime += Current_Customer.ServingTime;
					TotalWaittingTime += Current_Customer.WaitingTime;
					tallers[i].AvalabileTime = Current_Customer.CustomerTime;
					//cout << "availale time = " << tallers[i].AvalabileTime;
					tallers[i].IsAvailable = false;
					NumberOfAvailableTallors--;
					tallers[i].NumberOfServedCustomers++;
					tallers[i].TotalServedTime += Current_Customer.ServingTime;
					DisplayCustomer(Current_Customer,tallers[i].TallorNumber, arival);
					cout << "\n";
					//cout << "Our Client " << Current_Customer.Name <<" Who Was Served By Teller Number " << tallers[i].TallorNumber<< " Waited For " << Current_Customer.WaitingTime << " To Complete The Process He Wanted, Which Took " << Current_Customer.ServingTime << " And Leave The Bank At " << Current_Customer.CustomerTime << "\n\n";
					AddCustomerToServingQueue(Current_Customer);

					done = true;
					break;
				}
			}
			if (done == false)
			{
				AddCustomerToWaitingQueue(Current_Customer);
			}
			
		}
		else if(Current_Customer.CustomerType == "Departure")
		{
				if (!WaitingQueue.empty())
				{
					Customer Current_Customer = WaitingQueue.front();
					Taller* NearestTaller = findNearestAvailableTeller();
					NearestTaller->IsAvailable = true;
					NearestTaller->NumberOfServedCustomers++;
					//cout << "available time = " << NearestTaller->AvalabileTime;
					NearestTaller->TotalServedTime += Current_Customer.ServingTime;
					if (NearestTaller->AvalabileTime <= Current_Customer.CustomerTime)
					{
						Current_Customer.WaitingTime = 0;
					}
					else
					{
						Current_Customer.WaitingTime = BankTime - Current_Customer.CustomerTime;
						//cout << "Waitting time for customer 4 = " << Current_Customer.WaitingTime << "\n";
					}

					
					int arival = Current_Customer.CustomerTime;
					Current_Customer.CustomerTime = Current_Customer.WaitingTime + Current_Customer.CustomerTime + Current_Customer.ServingTime;
					TotalServingTime += Current_Customer.ServingTime;
					TotalWaittingTime += Current_Customer.WaitingTime;
					DisplayCustomer(Current_Customer, NearestTaller->TallorNumber, arival);
					cout << "\n";
					//cout << "Our Client " << Current_Customer.Name << "Who Was Served By Teller Number " << NearestTaller->TallorNumber << " Waited For " << Current_Customer.WaitingTime << " To Complete The Process He Wanted, Which Took " << Current_Customer.ServingTime << " And Leave The Bank At " << Current_Customer.CustomerTime << "\n\n";
					Current_Customer.CustomerType = "Departure";
					NearestTaller->AvalabileTime = Current_Customer.CustomerTime;
					NearestTaller->IsAvailable = false;

					AddCustomerToServingQueue(Current_Customer);
					
					WaitingQueue.pop();
				}
				else
				{
					NumberOfAvailableTallors++;
				}
			
			
		}

	}
	cout << "------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	TellersTitle();
	cout << "------------------------------------------------------------------------------------------" << endl;
	DisplayTeller();
	cout << "\n\n";
	BankTitle();
	cout << "----------------------------------------------------" << endl;
	DisplayBank();
	/*cout << "Total Serving And Waiting Time: " << endl;
	cout << "Total Serving Time\t\t\t\t Total Waitting Timre" << endl;
	cout << TotalServingTime << "\t\t\t\t\t\t " << TotalWaittingTime << endl*/;
}


