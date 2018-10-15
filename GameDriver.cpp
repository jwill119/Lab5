//  GameDriver.cpp

//  Guess which container is in use.

//  Commands:
//    put number    inserts number into the container
//    get           removes and reports a container element
//                    reports "empty" as appropriate
//    next          restarts with a new container
//    hint          reports the container type
//    quit          exits the program

//  tom bailey  3 mar 00


#include <iostream>
#include <limits>
using namespace std;

#include "Container.h"
#include "RanGen.h"


void
setContainer( RanGen & rng, Container * & c ) {
	delete c;
	switch( rng.randint( 1, 4 ) ) {
	case 1: {
		c = new Mob( rng.randint( 1, 10000 ) );
		break;
			}
	case 2: {
		c = new Queue;
		break;
			}
	case 3: {
		c = new Stack;
		break;
			}
	case 4: {
		c = new Priority_Queue;
		break;
			}
	}
}


int
main() {
	cout << "Enter seed for random generator:";
	unsigned long seed;
	cin >> seed;
	RanGen rng( seed );

	Container * c = NULL;
	setContainer( rng, c );
	cout << "  new container created" << endl;

	string command;

	cout << "Command? ";
	while( cin >> command ) {
		if( command == "quit" )
			break;

		else if( command == "next" ) {
			setContainer( rng, c );
			cout << "  new container created" << endl;
		}

		else if( command == "get" )
			if( c->empty() )
				cout << "  empty" << endl;
			else
				cout << "  " << c->get() << " removed" << endl;

		else if( command == "put" ) {
			double item;
			if( cin >> item ) {
				c->put( item );
				cout << "  " << item << " entered" << endl;
			}
			else {
				cout << "  bad item entered, put ignored" << endl;
				cin.clear();
			}
		}

		else if( command == "hint" ) {
			cout << "  container is ";
			c->printName( cout );
			cout << endl;
		}

		else {
			cout << "  unknown command" << endl;
			cout << "  known commands are" << endl;
			cout << "    quit:  exit from the program" << endl;
			cout << "    next:  start over with a new, empty container" << endl;
			cout << "    put x: insert the number x into the container" << endl;
			cout << "    get:   remove a number from the container and report it" << endl;
			cout << "    hint:  report the container type" << endl;
		}

		// skip past end of line
		cin.ignore( numeric_limits<int>::max(), '\n' );

		cout << "Command? ";
	}

	return 0;
}
