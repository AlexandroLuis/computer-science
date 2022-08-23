#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>
#include <omp.h>


double func(double x){
	return (4.0 / (1.0 + x * x));
}

/* Main Program */

int 
main(int argc, char *argv[]){
	int NoIntervals, interval, ScatterSize, Noofthreads, MyRank, Numprocs,threadid,start,end, iproc, Root = 0, valid, Source, Source_tag, Destination, Destination_tag;
	double PI25DT = 3.141592653589793238462643;
	double mypi, pi, h, totalsum, x,partialsum,finalsum;
	MPI_Status status;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &Numprocs);
	MPI_Comm_rank(MPI_COMM_WORLD, &MyRank);

	if (MyRank == Root) {
		printf("Enter The NoIntervals Of Intervals: ");
	        /*               scanf("%d", &NoIntervals); */
	        NoIntervals=1000;
	}
	MPI_Bcast(&NoIntervals, 1, MPI_INT, Root, MPI_COMM_WORLD);

	if (NoIntervals <= 0) {
		if (MyRank == Root)
			printf("Invalid Value For Number Of Intervals .....\n");
		MPI_Finalize();
		exit(-1);
	}
	/* Checking For Equal Division Of Intervals Across The Processors */

	if (NoIntervals % Numprocs != 0) {
		if (MyRank == Root)
			printf("NoofIntervals Cannot Be Evenly Distributed \n");
		MPI_Finalize();
		exit(0);
	}
	if (MyRank == Root)
		ScatterSize = NoIntervals / Numprocs;


	MPI_Bcast(&ScatterSize, 1, MPI_INT, Root, MPI_COMM_WORLD);

	/*printf("the ScatterSize is %d",ScatterSize);*/
	h = 1.0 / (double) NoIntervals;
	totalsum = 0.0;
	finalsum = 0.0;

	/* OpenMP Parallel For Directive  And Critical Section */

partialsum=0.0;

start=MyRank * ScatterSize + 1 ;
end=MyRank * ScatterSize + ScatterSize; 

omp_set_num_threads(4);
#pragma omp parallel for private(x,interval)
	for (interval = start; interval <= end; interval=interval+1)
		{
		x = h * ((double) interval - 0.5);
                #pragma omp critical
                partialsum = partialsum + func(x);
		/*printf("the threadid Myrank and partial sum for each threadis %d %d %f\n",omp_get_thread_num(),MyRank,partialsum); */
		}

	mypi = partialsum * h;
/* printf("the each process totalsum and mypi value for each rank is %f %f %d\n",totalsum,mypi,MyRank); */
	/* ....Collect The Areas Calculated In P0,P1.... */
	MPI_Reduce(&mypi, &pi, 1, MPI_DOUBLE, MPI_SUM, Root, MPI_COMM_WORLD);

	
	if (MyRank == Root) {
		printf("\nPi Is Approximately %.16f, Error Is %.16f \n",
		       pi, fabs(pi - PI25DT));
	}
	/* MPI_Termination */

	MPI_Finalize();

}
