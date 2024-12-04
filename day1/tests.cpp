#include <catch2/catch_test_macros.hpp>
#define private public //needed to test private member functions
#include "functions.h"

TEST_CASE( "nodes are sorted when added to list", "[list]"){
    Day1::List testlist = Day1::List();

    SECTION( "add one object" ){
        testlist.addSortedNode(1);

        REQUIRE( testlist.head->value == 1 );
    }

    SECTION( "add a smaller node 2nd" ){
        testlist.addSortedNode(5);
        testlist.addSortedNode(1);

        REQUIRE( testlist.head->value == 1 );
        REQUIRE( testlist.head->next->value == 5 );
    }

    SECTION( "add a larger node 2nd" ){
        testlist.addSortedNode(1);
        testlist.addSortedNode(5);

        REQUIRE( testlist.head->value == 1 );
        REQUIRE( testlist.head->next->value == 5 );
    }

    SECTION( "add a 3 nodes" ){
        testlist.addSortedNode(3);
        testlist.addSortedNode(2);
        testlist.addSortedNode(4);

        REQUIRE( testlist.head->value == 2 );
        REQUIRE( testlist.head->next->value == 3 );
        REQUIRE( testlist.head->next->next->value == 4 );
    }
}

TEST_CASE( "getTotalDiff works as expected", "[TotalDiff]"){
    Day1 testObject = Day1();

    SECTION( "List of size 1" ){
        testObject.addNodePair(1, 3);

        REQUIRE( testObject.getTotalDiff() == 2); //3 - 1
    }

    SECTION( "List of size 3 added in order" ){
        testObject.addNodePair(1, 3);   // 3 - 1 = 2
        testObject.addNodePair(2, 5);   // 5 - 2 = 3
        testObject.addNodePair(33, 10); // 33 - 10 = 23

        REQUIRE( testObject.getTotalDiff() == 28); //2 + 3 + 23
    }

    SECTION( "List of size 3 added in reverse order" ){
        testObject.addNodePair(1, 3);   // 3 - 1 = 2
        testObject.addNodePair(2, 5);   // 5 - 2 = 3
        testObject.addNodePair(33, 10); // 33 - 10 = 23

        REQUIRE( testObject.getTotalDiff() == 28); //2 + 3 + 23
    }

    SECTION( "List of size 10 added in random order" ){
        testObject.addNodePair(65, 26); // |20 - 10| = 10
        testObject.addNodePair(97, 24); // |21 - 24| = 3
        testObject.addNodePair(42, 76); // |25 - 26| = 1
        testObject.addNodePair(21, 10); // |36 - 27| = 9
        testObject.addNodePair(25, 99); // |42 - 28| = 14
        testObject.addNodePair(20, 28); // |43 - 61| = 18
        testObject.addNodePair(43, 81); // |57 - 73| = 16
        testObject.addNodePair(36, 73); // |65 - 76| = 11
        testObject.addNodePair(78, 27); // |78 - 81| = 3
        testObject.addNodePair(57, 61); // |97 - 99| = 2

        REQUIRE( testObject.getTotalDiff() == 87);
    }
}
