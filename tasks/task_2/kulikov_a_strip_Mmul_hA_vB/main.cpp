// Copyright 2023 Kulikov Artem
#include <gtest/gtest.h>
#include <vector>
#include "./strip_Mmul_hA_vB.h"
#include <boost/mpi/environment.hpp>
#include <boost/mpi/communicator.hpp>

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
