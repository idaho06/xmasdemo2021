#include <stdlib.h>
#include "akinorandom.h"

// https://stackoverflow.com/questions/13408990/how-to-generate-random-float-number-in-c
float akinorandom(const float max) {
	double rawRandom = (double)rand();
	float ratioRandom = (float)RAND_MAX / max;
	double doubleRandom = rawRandom / (double)ratioRandom;
	return (float)doubleRandom;
	// return float((double)rand() / (double)((float)RAND_MAX / max));
}