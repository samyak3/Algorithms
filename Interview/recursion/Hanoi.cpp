/*
 * Hanoi.cpp
 *
 *  Created on: Feb 1, 2016
 *      Author: Admin
 */

//The Tower of Hanoi Problem

#include<iostream>

using namespace std;

//function to print the sequence of moves

void f(int nDisksToMove, char sourcePeg , char destPeg, char auxPeg)
{
	if(nDisksToMove == 1)
	{
		cout << "Move disk #1 from " << sourcePeg << " to "<< destPeg << endl;
		return;
	}

	//Move all disks except last one to aux peg so that  largest one can be moved to dest peg
	f( nDisksToMove - 1 , sourcePeg , auxPeg , destPeg);

	cout << "Move disk #" << nDisksToMove <<" from " << sourcePeg << " to "<< destPeg << endl;

	//Now move the disks from auxPeg to destPeg
	f( nDisksToMove - 1 , auxPeg , destPeg , sourcePeg);
}
int main()
{
	int nDisks;

	cout << "Enter the number of disks to move :: ";

	cin >> nDisks;

	cout << endl;

	cout << "Moves required :: " << endl;

	f(nDisks , 'A' , 'C' , 'B');

	return 0;
}
//Learning : The number of steps required are 2^n - 1;
