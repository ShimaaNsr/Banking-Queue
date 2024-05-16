#pragma once
#include <string>
#include <iostream>
using namespace std;
class Customer
{
public:
	//static int CustomerNumber;
	int CustomerNumber;
	string Name;
	string CustomerType="Arival";
	int CustomerTime;
	int ServingTime;
	int WaitingTime;

public:
	Customer(int number,string name, int Time, int serving);
};


