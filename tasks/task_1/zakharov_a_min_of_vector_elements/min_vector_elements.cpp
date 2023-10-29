#include <vector>
#include <boost/mpi/communicator.hpp>
#include <boost/mpi/collectives.hpp>
#include "min_vector_elements.h"


int get_min_element(const std::vector<int>& init_vec, size_t vec_size){
    boost::mpi::communicator comm;
    int result;
    const size_t part_size = vec_size / comm.size();
    const size_t remain = vec_size % comm.size();
    std::vector<int> local_vec_sizes(comm.size(), (int)part_size);
    std::vector<int> local_vec(part_size);
    local_vec_sizes[0] += (int)remain;

    if (comm.rank() == 0){
        local_vec.resize(local_vec_sizes[0]);
        boost::mpi::scatterv(comm, init_vec, local_vec_sizes, local_vec.data(), 0);
    }
    else{
        boost::mpi::scatterv(comm, local_vec.data(), local_vec_sizes[comm.rank()], 0);
    }

    int min_val = *std::min_element(local_vec.begin(), local_vec.end());

    boost::mpi::reduce(comm, min_val, result, boost::mpi::minimum<int>(), 0);

    return result;
}
