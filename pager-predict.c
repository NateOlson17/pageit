/*
 * File: pager-predict.c
 * Author:       Andy Sayler
 *               http://www.andysayler.com
 * Adopted From: Dr. Alva Couch
 *               http://www.cs.tufts.edu/~couch/
 *
 * Project: CSCI 3753 Programming Assignment 4
 * Create Date: Unknown
 * Modify Date: 2012/04/03
 * Description:
 * 	This file contains a predictive pageit
 *      implmentation.
 */

#include <stdio.h> 
#include <stdlib.h>

#include "simulator.h"

void pageit(Pentry q[MAXPROCESSES]) {
    /* This file contains the stub for a predictive pager */
    /* You may need to add/remove/modify any part of this file */

    /* Static vars */
    static int initialized = 0;
    static int tick = 1; // artificial time
    static int timestamps[MAXPROCESSES][MAXPROCPAGES];

    /* initialize static vars on first run */
    if(!initialized){
	/* Init complex static vars here */
	for (int i = 0; i < MAXPROCESSES; ++i) {
	    for (int j = 0; j < MAXPROCPAGES; ++j) {
		timestamps[i][j] = 0;
	    }
	}
	initialized = 1;
    }

    for (int proc; proc < MAXPROCESSES; ++proc) { //loop through processes
	if (q[proc].active) { //if process active
	    
	}
    }

    /* advance time for next pageit iteration */
    tick++;
}
