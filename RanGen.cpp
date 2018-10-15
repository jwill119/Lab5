//  RanGen.cpp

//  A multiplicative congruential random number generator
//  Constructed with a seed.
//  Returns a sample from a uniform distribution between 0 and 1.

//  The generator is from Example 8.4, page 295, of Banks, Carson, and Nelson.
//     X = ( a *  X ) mod ( m )
//     with  a = 7^5  and  m = 2^31-1
//  The calculation has been revised to avoid overflow using 32 bit integers.

//  tom bailey  18 jan 99
//  modified     3 dec 99   added next, rand, randint


#include "RanGen.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


const long m = 2147483647;
const double dblm = double( m );
const long a = 16807;
const long k = 127774;
const long r = 13971;


void
RanGen::error( char* message ) {
  cout << message << endl;
  abort();
  }


void
RanGen::next( ) {
    long x1 = r * ( x / k );
    long x2 = a * ( x % k );
    long x2p = m - x2;
    if( x1 < x2p )
      x = x1 + x2;
    else
      x = x1 - x2p;
}


RanGen::RanGen( long seed ) {
    if( (seed<=0) || (seed>=m) )
      error( "Generator seed out of range." );
    x = seed;
    }


RanGen::~RanGen( ) {
    }


long
RanGen::seed( ) {
    return x;
    }


long
RanGen::rand( ) {
	next();
	return x;
}


long
RanGen::randint( long low, long high ) {
	return low + long( floor( unif() * double( high-low+1 ) ) );
}


double
RanGen::unif( ) {
	next();
    return double( x ) / dblm;
    }
