//  Container.h

//  Container is a base class for the containers of
//    GameDriver

//  tom bailey  3 mar 00

//  bag renamed as mob
//  tom bailey  30 may 00

//  classes renamed as Mob, Stack, Queue, Priority_Queue.
//  Mob uses only one random number generator.
//  Mob uses time as random number seed by default.
//  Stack is fast, uses back of vector as top.
//  Queue is fast, uses list as storage.
//  Priority_Queue is still slow.
//  tom bailey  3 nov 03


#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <ctime>
using namespace std;

#include "RanGen.h"

class Container {
public:
		Container( const string & _name ):
			name( _name ), id( nextID++ )  {}
	virtual 
		~Container() {}
	void 
		printName( ostream & out ) 
		{	
			out << name << "." << id; 
		}
	virtual void
		put( double ) = 0;
	virtual double
		get() = 0;
	virtual bool
		empty() = 0;

private:
	string name;
	long id;
	static long nextID;
};

long Container::nextID = 0;


class Mob: public Container {
public:
		Mob( unsigned long seed  ): Container( "mob" ) 
		{
			if( rng == NULL )
			{
				rng = new RanGen( seed );
			}
			rgCount++;
		}

		Mob(): Container( "mob" )
		{
			if( rng == NULL )
			{
				rng = new RanGen( time( NULL ) );
			}
			rgCount++;
		}

		~Mob() 
		{
			rgCount--;
			if( rgCount == 0 )
			{
				delete rng;
			}
		}

	void 
		put( double item ) {
			store.push_back( item );
		}

	double
		get() 
		{
			long index = rng->randint( 0, store.size() - 1 );
			double item = store[index];
			store[index] = store.back();
			store.pop_back();
			return item;
		}

	bool
		empty() 
		{
			return store.size() == 0;
		}

private:
	vector< double > store;
	static RanGen * rng;
	static long rgCount;
};

RanGen * Mob::rng = NULL;
long Mob::rgCount = 0;


class Stack: public Container {
public:
		Stack(): Container( "stack" ) {}

		~Stack() {}

	void 
		put( double item ) 
		{
			store.push_back( item );
		}

	double
		get() 
		{
			double item = store.back();
			store.pop_back();
			return item;
		}

	bool
		empty() 
		{
			return store.size() == 0;
		}

private:
	vector< double > store;
};


class Queue: public Container {
public:
		Queue(): Container( "queue" ) {}

		~Queue() {}

	void 
		put( double item ) 
		{
			store.push_back( item );
		}

	double
		get() 
		{
			double item = store.front();
			store.pop_front();
			return item;
		}

	bool
		empty() 
		{
			return store.size() == 0;
		}

private:
	list< double > store;
};


class Priority_Queue: public Container {
public:
		Priority_Queue(): Container( "priority_queue" ) {}

		~Priority_Queue() {}

	void 
		put( double item ) 
		{
			store.push_back( item );
		}

	double
		get() 
		{
			long index = 0;
			for( long i=1; i<long(store.size()); i++ ) 
				if( store[i] < store[index] )
					index = i;
			double item = store[index];
			store[index] = store.back();
			store.pop_back();
			return item;
		}

	bool
		empty() 
		{
			return store.size() == 0;
		}

private:
	vector< double > store;
};
