/*
 * File: pager-basic.c
 * Author:       Andy Sayler
 *               http://www.andysayler.com
 * Adopted From: Dr. Alva Couch
 *               http://www.cs.tufts.edu/~couch/
 *
 * Project: CSCI 3753 Programming Assignment 4
 * Create Date: Unknown
 * Modify Date: 2012/04/03
 * Description:
 * 	This file contains a simple pageit
 *      implmentation at performs very poorly, but
 *      provided a basic idea of how to user the
 *      simulator interface. Your job is to improve
 *      upon this implmentation.
 */

#include "simulator.h"
#include <stdio.h>
#include <stdlib.h>

void pageit(Pentry q[MAXPROCESSES]) {
	for (int i = 0; i < MAXPROCESSES; ++i) {
		int curpage = q[i].pc / PAGESIZE;
		for (int j = 0; j < MAXPROCPAGES; ++j) {
			(j == curpage) ? pagein(i,j) : pageout(i,j);
		}
	}
}
