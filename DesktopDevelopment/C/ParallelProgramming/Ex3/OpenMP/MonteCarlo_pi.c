#include <stdio.h>
#include <stdlib.h>
#include <math.h>   / 
#include <omp.h>
#define m 2147483647
#define a 16807
#define c 0
#include <sys/time.h>
    
double get_time() {
    struct timeval tv;
    struct timezone tz;
    if (gettimeofday(&tv, &tz) == 0) 
        return (double) tv.tv_sec + ((double) tv.tv_usec / (double) 1000000);
    else
        return 0.0;
}

double generate(unsigned long *input){
    *input = ((a*(*input))+c)%m;
    return (double) (*input)/m;
}

int main(int argc, char* argv[]) {
	int num_samples, count =0, i;
	long seed=0,orig_seed;
	double start_time, end_time, x, y, pi;

	if (argc != 3)
		exit(EXIT_FAILURE);
	
	num_samples = atoi(argv[1]);
	orig_seed = seed = atoi(argv[2]);
	
	if ((num_samples <= 0) || (seed <= 0)) 
		exit(EXIT_FAILURE);
	
	#pragma omp parallel
	{
		start_time = get_time();
		long locSeed = seed + 3  *( (omp_get_thread_num()) +1);

		#pragma omp for private(x,y) reduction(+:count) schedule(static)
    		for (i = 0; i < num_samples; ++i) {
        		x = generate(&locSeed);
        		y = generate(&locSeed);

    	    	if ((x*x + y*y) <= 1.0){
	        	    ++count;
					if(count == 0)
						printf("count equals 0");
				}
	    	}

		}
		pi = 4.0 * (double) count / (double) num_samples;

		// tempo gasto 
		end_time = get_time();
	
		printf("samples = %d, seed = %d\n", num_samples, orig_seed);
		printf("pi estimado = %12.10f\n", pi);
		printf("error pi = %12.10f\n", fabs(pi - M_PI));
		printf("tempo gasto = %g segundos\n", end_time - start_time);
	

    return 0;
}
