/**********************************************************************
	Lab Assignment 9 - working with a stack
	It's sometimes tricky to set up the loop that reads the
expression from the keyboard, so I am giving that to you. You have to
fill in the rest of the main.
	John Dolan Fall 2016
			Ohio University
			Home of the Bobcats
**********************************************************************/
#include <stack>
#include <iostream>
#include <cstdlib>
#include "calc_useful.h"
using namespace std;

int main()
{
    char c;
    char tmp;
    int onenum, twonum;
	int st = 0;
    bool continu = true;
	stack <int> stk;					// declare an STL stack called nums right here:

	stk.empty();
	st = 0;

	cout << "Please enter your expression:\n";
	c = cin.get(); 					// priming read for the sentinel loop.

	while(continu == true)
	{
		while(c != '\n')
		{
			if(isdigit(c))
			{
				cin.putback(c);
				cin >> onenum;
				stk.push(onenum);						// stack operation here.
			}
			else if(isop(c)){
				if(stk.empty())
				{
					cout << "\nWrong Expression";
					st = 1;
					break;
				}

				onenum = stk.top();
				stk.pop();
				if(stk.empty())
				{
					cout << "\nWrong Expression";
					st = 1;
					break;
				}

				twonum = stk.top();
				stk.pop();
				onenum = evaluate(onenum, twonum, c);
				stk.push(onenum);
			}
			c = cin.get(); 					// reading at the bottom of the sentinel loop
		} 								// bottom of the loop that reads a single expression from the keyboard

		if(stk.empty())
		{
			cout << "Wrong Expression";
			st = 1;
		}								// output the final result from the top of the stack
										// but only after you check to make sure there's something on the stack
		onenum = stk.top();
		stk.pop();
		if(!stk.empty())
		{
			cout << "Error, Insufficient operators for the operands." << endl;
			st = 1;
		}

		if(st == 0)
		{
			cout << "The and is: " << onenum << endl;
		}

		cout << "Enter another equation?(y or n)";
		cin >> tmp;
		if(tmp=='y' || tmp=='Y')
		continu=true;
		else
		continu=false;
	}

return 0; 
}