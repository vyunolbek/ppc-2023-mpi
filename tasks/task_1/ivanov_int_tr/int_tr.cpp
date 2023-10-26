#include "int_tr.h"
#include "cmath"
#include <boost/mpi/communicator.hpp>
#include <boost/mpi/collectives.hpp>

double function(double x){
    return sin(x);
}

double trapezium(double a, double b, func f){
    return (f(a)+f(b))*(b-a)/2;
}

double get_area(double a, func f, int steps_count, double step){
    double res = 0;
    for (int i = 0; i < steps_count; i++) {
        res += trapezium(a + i * step, a + (i + 1) * step, f);
    }
    return res;
}

double getParallelOperations(double a, double b, int N, func f) {
    boost::mpi::communicator world;
    const double slice_count = (b-a) / world.size();
    const double step = (b-a) / N;
    const int steps_count = N / world.size();

    std::cout << "slice_count = " << slice_count << std::endl;

    if (world.rank() == 0) {
        for (int proc = 1; proc < world.size(); proc++) {
            world.send(proc, 0, a + slice_count * proc);
        }
    }

    double local_val;
    if (world.rank() == 0) {
        local_val = a;
    } else {
        world.recv(0, 0, local_val);
    }
//
    double global_area = 0;
//    std::cout << "Proc id = " << world.rank() << " start_val = " << local_val << " end_val = " << local_val + step <<std::endl;
    double local_area = get_area(local_val, f, steps_count, step);
    reduce(world, local_area, global_area, std::plus<double>(), 0);
    return global_area;
}