#include <catch2/catch_test_macros.hpp>
#define private public //needed to test private member functions
#include "functions.h"

TEST_CASE( "test list struct functionality", "[list]"){
    Day1::List testlist = Day1::List();

    SECTION( "add one object" ){
        testlist.addSortedNode(1);

        CHECK( testlist.head->value == 1 );
    }

    SECTION( "add a smaller node 2nd" ){
        testlist.addSortedNode(5);
        testlist.addSortedNode(1);

        CHECK( testlist.head->value == 1 );
        CHECK( testlist.head->next->value == 5 );
    }

    SECTION( "add a larger node 2nd" ){
        testlist.addSortedNode(1);
        testlist.addSortedNode(5);

        CHECK( testlist.head->value == 1 );
        CHECK( testlist.head->next->value == 5 );
    }

    SECTION( "add a 3 nodes" ){
        testlist.addSortedNode(3);
        testlist.addSortedNode(2);
        testlist.addSortedNode(4);

        CHECK( testlist.head->value == 2 );
        CHECK( testlist.head->next->value == 3 );
        CHECK( testlist.head->next->next->value == 4 );
    }
}

TEST_CASE( "test Day1 class functionality", "[Day1]"){
    Day1 testObject = Day1();

    SECTION( "getTotalDiff: List of size 1" ){
        testObject.addNodePair(1, 3);

        CHECK( testObject.getTotalDiff() == 2); //3 - 1
    }

    SECTION( "getTotalDiff: List of size 3 added in order" ){
        testObject.addNodePair(1, 3);   // 3 - 1 = 2
        testObject.addNodePair(2, 5);   // 5 - 2 = 3
        testObject.addNodePair(33, 10); // 33 - 10 = 23

        CHECK( testObject.getTotalDiff() == 28); //2 + 3 + 23
    }

    SECTION( "getTotalDiff: List of size 3 added in reverse order" ){
        testObject.addNodePair(1, 3);   // 3 - 1 = 2
        testObject.addNodePair(2, 5);   // 5 - 2 = 3
        testObject.addNodePair(33, 10); // 33 - 10 = 23

        CHECK( testObject.getTotalDiff() == 28); //2 + 3 + 23
    }

    SECTION( "getTotalDiff: List of size 10 added in random order" ){
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

        CHECK( testObject.getTotalDiff() == 87);
    }


    SECTION( "calculateSimularityScore: List of size 1 different values" ){
        testObject.addNodePair(1, 3);
        testObject.calculateSimularityScore();
        
        CHECK( testObject.list1.head->simularityScore == 0);
        CHECK( testObject.getTotalSimularityScore() == 0);
    }

    SECTION( "calculateSimularityScore: List of size 1 same values" ){
        testObject.addNodePair(2, 2);
        testObject.calculateSimularityScore();
        
        CHECK( testObject.list1.head->simularityScore == 1);
        CHECK( testObject.getTotalSimularityScore() == 2);
    }

    SECTION( "calculateSimularityScore: List of size 2, left different values, right same as 1st left" ){
        testObject.addNodePair(1, 1);
        testObject.addNodePair(2, 1);
        testObject.calculateSimularityScore();
        
        CHECK( testObject.list1.head->simularityScore == 2);
        CHECK( testObject.list1.head->next->simularityScore == 0);
        CHECK( testObject.getTotalSimularityScore() == 2);
    }

    SECTION( "calculateSimularityScore: List of size 2, left different values, right same as 2nd left" ){
        testObject.addNodePair(1, 2);
        testObject.addNodePair(2, 2);
        testObject.calculateSimularityScore();
        
        CHECK( testObject.list1.head->simularityScore == 0);
        CHECK( testObject.list1.head->next->simularityScore == 2);
        CHECK( testObject.getTotalSimularityScore() == 4);
    }

    SECTION( "calculateSimularityScore: List of size 2, left same values, right same" ){
        testObject.addNodePair(2, 2);
        testObject.addNodePair(2, 2);
        testObject.calculateSimularityScore();
        
        CHECK( testObject.list1.head->simularityScore == 2);
        CHECK( testObject.list1.head->next->simularityScore == 2);
        CHECK( testObject.getTotalSimularityScore() == 8);
    }

    SECTION( "calculateSimularityScore: List of size 2, left same values, right different" ){
        testObject.addNodePair(1, 2);
        testObject.addNodePair(1, 2);
        testObject.calculateSimularityScore();
        
        CHECK( testObject.list1.head->simularityScore == 0);
        CHECK( testObject.list1.head->next->simularityScore == 0);
        CHECK( testObject.getTotalSimularityScore() == 0);
    }

    SECTION( "calculateSimularityScore: List of size 3, left 2 same 1 different, right same as 2" ){
        testObject.addNodePair(1, 1);
        testObject.addNodePair(1, 1);
        testObject.addNodePair(2, 1);
        testObject.calculateSimularityScore();
        
        CHECK( testObject.list1.head->simularityScore == 3);
        CHECK( testObject.list1.head->next->simularityScore == 3);
        CHECK( testObject.list1.head->next->next->simularityScore == 0);
        CHECK( testObject.getTotalSimularityScore() == 6);
    }

}
