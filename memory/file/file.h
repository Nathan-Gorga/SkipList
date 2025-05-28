#ifndef FILE_H
#define FILE_H

#include "../../includes/includes.h"
#include "../../build/list/list.h"

unsigned int serializeSkipList(Sentinel * s,char * path);

unsigned int deserializeSkipList(Sentinel * s,char * path);

#endif