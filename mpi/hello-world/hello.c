#include <stdio.h>
#include <mpi.h> // load library 


int main(int argc, char *argv[])
{

    int size, rank, len_name ; // needed for information
    char processor_name[MPI_MAX_PROCESSOR_NAME] ; 

    MPI_Init(&argc, &argv) ;  // start of MPI


    // get rank and size for each process
    MPI_Comm_size(MPI_COMM_WORLD, &size) ; 
    MPI_Comm_rank(MPI_COMM_WORLD, &rank) ; 

    // get name of processors 
    MPI_Get_processor_name(processor_name, &len_name) ; 

    // TODO: say hello! in parallel
    printf("Hello from %s!\n", processor_name) ;

    if (rank == 0){
	printf("My rank is %d ", rank) ;
    	printf("out of %d processes!\n", size) ;
    }
    if (rank > 0){
	printf("My rank is %d!\n", rank) ; 
    }



    MPI_Finalize() ; // end of MPI
}
