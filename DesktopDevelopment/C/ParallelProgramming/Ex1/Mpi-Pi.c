#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
  int n, myid, numprocs, i, len;		
  double PI25DT = 3.141592653589793238462643;	 
  double mypi, pi, h, sum, x;										
  char hostname[MPI_MAX_PROCESSOR_NAME];			
  MPI_Init(&argc,&argv);						
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);		
  MPI_Comm_rank(MPI_COMM_WORLD, &myid);			
  MPI_Get_processor_name(&hostname, &len);

  while (1) {
     if (myid == 0) {
         printf("Digite o numero de intervalos: ");
         scanf("%d",&n);
     }

     MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

     if (n == 0)
         break;		
     else {
         h   = 1.0 / (double) n;
         sum = 0.0;

         for (i = myid + 1; i <= n; i += numprocs) {
             x = h * ((double)i - 0.5);													
             sum += (4.0 / (1.0 + x*x));													
             printf("%s \n", hostname);
         }
         mypi = h * sum;																	

         MPI_Reduce(&mypi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0,
                    MPI_COMM_WORLD);
         if (myid == 0)
             printf("pi é aproximadamente %.16f, O erro é %.16f\n",
                    pi, fabs(pi - PI25DT));
     }
  }
  MPI_Finalize();
  return 0;
}
