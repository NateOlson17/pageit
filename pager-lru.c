
/*
 * File: pager-lru.c
 * Author:       Andy Sayler
 *               http://www.andysayler.com
 * Adopted From: Dr. Alva Couch
 *               http://www.cs.tufts.edu/~couch/
 *
 * Project: CSCI 3753 Programming Assignment 4
 * Create Date: Unknown
 * Modify Date: 2012/04/03
 * Description:
 * 	This file contains an lru pageit
 *      implmentation.
 */

#include <stdio.h> 
#include <stdlib.h>

#include "simulator.h"

void pageit(Pentry q[MAXPROCESSES]) { 
    static int initialized = 0;
    static int tick = 1; // artificial time
    static int timestamps[MAXPROCESSES][MAXPROCPAGES];

    int proctmp;
    int pagetmp;
    int currpage;
    int oldestpg;
    int lrupg;

    /* initialize static vars on first run */
    if(!initialized){
	for(proctmp=0; proctmp < MAXPROCESSES; proctmp++){
	    for(pagetmp=0; pagetmp < MAXPROCPAGES; pagetmp++){
		timestamps[proctmp][pagetmp] = 0; 
	    }
	}
	initialized = 1;
    }

    for (int i = 0; i < MAXPROCESSES; ++i) { //iterate through each process
        if (q[i].active) { //if process is active
	    currpage = q[i].pc / PAGESIZE; //get current page
	    timestamps[i][currpage] = tick; //set timestamp for page
	    if (q[i].pages[currpage] == 0) { //if page unallocated
		if (pagein(i, currpage) == 0) { //on pagein for a full cache
		    oldestpg = -1; //tracks timestamp of oldest page
		    for (pagetmp = 0; pagetmp < MAXPROCPAGES; ++pagetmp) { //iterate through pages for current process
		        if (q[i].pages[pagetmp] == 1 && oldestpg < tick - timestamps[i][pagetmp]) { //if the page is allocated and its timestamp is older than the current oldest page
		      	    oldestpg = tick - timestamps[i][pagetmp]; //set oldest timestamp to be (current tick - timestamp of current page = age since paged in)
		            lrupg = pagetmp; //save the current page as the lru page
			}
		    }
		    pageout(i, lrupg); //page out lru page of current process
		}
	    }
	}
    }

    /* advance time for next pageit iteration */
    tick++;
}
