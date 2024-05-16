#include "Customer.h"
//int Customer::CustomerNumber = 0;

Customer::Customer(int number,string name, int time, int serving)
{
	CustomerNumber = number;
	Name = name;
	CustomerType = "Arival";
	CustomerTime = time;
	ServingTime = serving;
	//CustomerNumber++;
}
