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
#include<cstdlib>
#include "calc_useful.h"
using namespace std;


int main(){
    char c;
    char tmp;
    int onenum, twonum;
    int count;
    bool continu = true;
	// declare an STL stack called nums right here:

    cout<<"Please enter your expression:\n";

    c = cin.get(); // priming read for the sentinel loop.
   while(continu==true){
    while(c != '\n'){
 	if(isdigit(c)){
	    cin.putback(c);
	    cin>>onenum;
	// stack operation here.

	}
	else if(isop(c)){
		if(  /* check to see if there's anyting on the stack */){
			//pop two  numbers from the stack
			// evaluate them using the evaluate from stack_useful
			// push result onto the stack
			}
			else{
				cout<<"Error:";
				cout<<"...  "; // what did this error tell us about the user's expression?
        			return -1;
			}

		}
	
	c = cin.get(); // reading at the bottom of the sentinel loop
    } // bottom of the loop that reads a single expression from the keyboard

	  // output the final result from the top of the stack
	  // but only after you check to make sure there's something on the stack
   }
    cout << "Enter another equation?(y or n)";
    cin>> tmp;
    if(tmp=='y' || tmp=='Y')
	continu=true;
    else
	continu=false;

    return 0;
}
