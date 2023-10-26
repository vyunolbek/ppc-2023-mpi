#include <gtest/gtest.h>

#include <boost/mpi/communicator.hpp>
#include <boost/mpi/environment.hpp>
#include <vector>

#include "int_tr.h"

TEST(Parallel_Min_In_Matrix_MPI, Test_Random) {
    boost::mpi::communicator world;
    const int N = 100000000;
    const double a = 1, b = 10;

    double global_sum = getParallelOperations(a, b, N, function);

    if (world.rank() == 0) {
//        int reference_sum = getSequentialOperations(global_vec, "+");
        std::cout << "Proc id = " << world.rank() << " global_sum = " << global_sum << std::endl;
    }
}

TEST(Parallel_Min_In_Matrix_MPI, Test_Random2) {
    ASSERT_EQ(1, 1);
}

TEST(Parallel_Min_In_Matrix_MPI, Test_Manual) {
    ASSERT_EQ(1, 1);
}

TEST(Parallel_Min_In_Matrix_MPI, Test_ManualOneRow) {
    ASSERT_EQ(1, 1);
}

TEST(Parallel_Min_In_Matrix_MPI, Test_ManualAllEQ) {
    ASSERT_EQ(1, 1);
}

int main(int argc, char** argv) {
    boost::mpi::environment env(argc, argv);
    boost::mpi::communicator world;
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::TestEventListeners& listeners = ::testing::UnitTest::GetInstance()->listeners();
    if (world.rank() != 0) {
        delete listeners.Release(listeners.default_result_printer());
    }
    return RUN_ALL_TESTS();
}