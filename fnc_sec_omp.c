//(Q).	Write OpenMP code that is able to execute four different functions using OpenMP Sections.

//Compile:      gcc -o <output> -fopenmp <fileName>.c
//Execute:      ./output
//----OR-----
//Compile:      gcc <fileName>.c -fopenmp 
//Execute:      ./a.out

#include <stdio.h>
#include <omp.h>
void function1();
void function2();
void function3();
void function4();

int main(int argc, char *argv[]) 
{
        #pragma omp parallel
        {
                #pragma omp sections
                {
                        #pragma omp section
                        (void) function1();

                        #pragma omp section
                        (void) function2();

                        #pragma omp section
                        (void) function3();

                        #pragma omp section
                        (void) function4();


                } /*-- End of sections block --*/
        } /*-- End of parallel region --*/

}

void function1()
{
        printf("In function1: Executed by thread %d\n",omp_get_thread_num());

}
void function2()
{
        printf("In function2: Executed by thread %d\n",omp_get_thread_num());
}

void function3()
{
        printf("In function3: Executed by thread %d\n",omp_get_thread_num());
}
void function4()
{
        printf("In function4: Executed by thread %d\n",omp_get_thread_num());
}


