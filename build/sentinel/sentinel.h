#ifndef SENTINEL_H
#define SENTINEL_H

#include "../../includes/includes.h"

Sentinel createSentinel(const unsigned int numLanes);

void freeSentinel(Sentinel s);


unsigned int sentinelPlusOneLane(Sentinel * s); // 0 : success, 1 : fail

unsigned int sentinel(Node * head, Sentinel * s);



#endif