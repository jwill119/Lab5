//  RanGen.h

//  A multiplicative congruential random number generator
//  Constructed with a seed.
//  Returns a sample from a uniform distribution between 0 and 1.

//  The generator is from Example 8.4, page 295, of Banks, Carson, and Nelson.
//     X = ( 7^5 *  X ) mod ( 2^31-1 )
//  The calculation has been revised to avoid overflow using 32 bit integers.

//  tom bailey  18 jan 99

#ifndef RANGEN_H_
#define RANGEN_H_

class RanGen {

private:
  long x;
     //  The current random integer.

  void error( char* message );
     //  Prints message to cout and aborts.

  void next( );
     //  Resets x to the next random integer in the sequence.

public:
  RanGen( long seed );
     //  Requires  0 < seed < (2^31-1).

  ~RanGen( );

  long seed( );
     //  Returns the current random integer.

  long rand( );
     //  Returns a sample from a uniform distribution: 0 < rand < m=2^31-1.

  long randint( long low, long high );
     //  Returns a sample from a uniform distribution: low <= randint <= high.

  double unif( );
     //  Returns a sample from a uniform distribution:  0.0 < unif < 1.0.

  };

#endif

