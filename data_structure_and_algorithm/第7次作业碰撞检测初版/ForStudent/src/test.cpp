/*! gcc -std=c89 -pedantic -Wall -g -o test2 test2.c libkdtree.a -lm */
/* Extended test program, contributed by David Underhill */
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "../kdtree.h"
#include <crtdbg.h>//add this header file to detect memory leaks

#define DEF_NUM_PTS 10

/* returns the distance squared between two dims-dimensional float arrays */
static float dist_sq( float *a1, float *a2, int dims );

/* get a random float between -10 and 10 */
static float rd( void );

int main(int argc, char **argv) {
  int i, num_pts = DEF_NUM_PTS;
  struct kdtree *ptree;
  int *data, *pch;
  struct kdres *presults = NULL;
  float pos[3], dist;
  float pt[3] = { 0, 0, 1 };

  if(argc > 1 && isdigit(argv[1][0])) {
    num_pts = atoi(argv[1]);
  }

  if(!(data = (int*)malloc(num_pts*sizeof(int)))) {
    perror("malloc failed");
    return 1;
  }

  srand( time(0) );

  /* create a k-d tree for 3-dimensional points */
  ptree = kd_create( 3 );

  /* add some random nodes to the tree (assert nodes are successfully inserted) */
  for( i=0; i<num_pts; i++ ) {
    data[i] =i;
    assert( 0 == kd_insert3( ptree, rd(), rd(), rd(), &data[i] ) );
  }

  /* find points closest to the origin and within distance radius */
  presults = kd_nearestf( ptree, pt);

  /* print out all the points found in results */
  printf( "found %d results:\n", kd_res_size(presults) );


  /* get the data and position of the current result item */
  pch = (int*)kd_res_itemf(presults, pos);

  /* compute the distance of the current result from the pt */
  dist = sqrt(dist_sq(pt, pos, 3));

  /* print out the retrieved data */
  printf("node at (%.3f, %.3f, %.3f) is %.3f away and has data=%d\n",
	  pos[0], pos[1], pos[2], dist, *pch);

  /* free our tree, results set, and other allocated memory */
  free( data );
  kd_res_free( presults );
  kd_free( ptree );
  if (!_CrtDumpMemoryLeaks())
  {
	  printf("100!\n");
  }
  system("PAUSE");
  return 0;
}

static float dist_sq( float *a1, float *a2, int dims ) {
  float dist_sq = 0, diff;
  while( --dims >= 0 ) {
    diff = (a1[dims] - a2[dims]);
    dist_sq += diff*diff;
  }
  return dist_sq;
}

static float rd( void ) {
  return (float)rand()/RAND_MAX * 20.0 - 10.0;
}
