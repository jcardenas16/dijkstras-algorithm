
#ifndef MYHEADER_H_
#define MYHEADER_H_
#include "Graph.h"


/******************************************************************************
 * Function - assignmentDescription()
 * -------------------------------------------------------------------------
 *	This function is used for output purposes. It takes in a
 *	type(either lab or assign), then the author name, proceeded by the
 *	assignment number, assignment title and the due date.
 ******************************************************************************/
void assignmentDescription(string type, string authorOne, int authorOneId,
			              int assignmentNumber, string assignmentTitle,
						  string dueDate)
{
	int setTheWidth = 18;
	string desc =
			"*  Implementation of Dijkstra’s algorithm to find the \n"
			"*  shortest distance from. Atlanta to the cities on the map\n"
			"*  below. The Paths and the corresponding. distance are identified.";

		cout << left
			 << setfill ('*') << setw (80)
			 << "*" << setfill(' ') << endl
			 << setw(setTheWidth) << "* AUTHOR(S) "
			 << " : " << authorOne   << endl
			 << setw(setTheWidth) << "* STUDENT IDS "
			 << " : " << authorOneId << endl;

		if (type == "Lab")
				cout << setw(setTheWidth) << "* Lab # " << ": "
				<< assignmentNumber << " - " << assignmentTitle << endl;
			else
				cout << setw(setTheWidth-2) << "* ASSIGNMENTS # "
				<< assignmentNumber <<  " : " << assignmentTitle << endl;


		cout	 << setw(setTheWidth) << "* CLASS "         << " : " << "CS1D\n"
			 << setw(setTheWidth) << "* SECTION "       << " : "
			 << "Monday & Wednesdays: 5:00 - 7:20pm\n"
			 << setw(setTheWidth) << "* DUE DATE "
			 << " : " << dueDate << endl

			 << setfill ('-') << setw (80)
			 << "* " << setfill(' ') << endl
			 << "* PROGRAM DESCRIPTION:\n"
			 << desc << endl


			 << setfill ('*') << setw (80)
			 << "*" << setfill(' ') << endl
			 << right;



}



#endif /* MYHEADER_H_ */
