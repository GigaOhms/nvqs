#include <stdio.h>

#define PIDATA_DEFAULTS                                                        \
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }

typedef struct {
	double Ref;
	double Fbk;
	double Out;
	double Kp;
	double Ki;
	double Umax;
	double Umin;
	double up;
	double ui;
	double v1;
	double i1;
	double w1;
} pid;

pid vdc = PIDATA_DEFAULTS;

void testF(pid *a) {
	a.Ref = 5;
}

int main() {
	vdc.Ref = 7;
	testF(&vdc);
	printf("%f\n", vdc.Ref);
	return 0;
}