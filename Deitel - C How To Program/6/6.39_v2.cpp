#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
#define MAXRANGE 1000

int recursiveMinimum( int [], int, int );

int main()
{ 
   int array[ SIZE ], loop, smallest;

   srand( time( NULL ) );

   for ( loop = 0; loop < SIZE; loop++ )
      array[ loop ] = 1 + rand() % MAXRANGE;

   printf( "Array members are:\n" );
   for ( loop = 0; loop < SIZE; loop++ )
      printf( " %d ", array[ loop ] );

   printf( "\n" );
   smallest = recursiveMinimum( array, 0, SIZE - 1 );

   printf( "\nSmallest element is: %d\n", smallest );

   return 0;
}

int recursiveMinimum( int array[], int low, int high )
{ 
   static int smallest = MAXRANGE;

   if ( array[ low ] < smallest )
      smallest = array[ low ];

   if ( low == high )
      return smallest;
   else
      return recursiveMinimum( array, low + 1, high );
}