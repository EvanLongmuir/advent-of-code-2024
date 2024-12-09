#include <catch2/catch_test_macros.hpp>
#define private public //needed to test private member functions
#include "functions.h"

TEST_CASE("read line", "[read]"){
    Grid grid = Grid();

    grid.readLine("....#.....");
    grid.readLine(".........#");
    grid.readLine("..........");
    grid.readLine("..#.......");
    grid.readLine(".......#..");
    grid.readLine("..........");
    grid.readLine(".#..^.....");
    grid.readLine("........#.");
    grid.readLine("#.........");
    grid.readLine("......#...");

    CHECK(grid.getNodesVisted() == 41);
    CHECK(grid.getLoopNodes() == 6);
}
