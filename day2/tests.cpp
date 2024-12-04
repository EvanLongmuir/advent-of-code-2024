#include <catch2/catch_test_macros.hpp>
#define private public //needed to test private member functions
#include "functions.h"

TEST_CASE("test report building functions", "[report]"){
    Day2::Report report = Day2::Report();

    CHECK(report.head == nullptr);
    CHECK(report.safe == true);

    SECTION("size 1"){
        report.addLevel(3);
        
        CHECK(report.head->value == 3);
        CHECK(report.head->next == nullptr);
        CHECK(report.head->last == nullptr);
        CHECK(report.safe == true);
    }

    SECTION("size 3"){
        report.addLevel(3);
        report.addLevel(5);
        report.addLevel(1);
        
        CHECK(report.head->last == nullptr);
        CHECK(report.head->value == 3);
        CHECK(report.head->next->value == 5);
        CHECK(report.head->next->next->value == 1);
        CHECK(report.head->next->next->next == nullptr);
    }
}

TEST_CASE("test report safe update value", "[safe]"){
    Day2::Report report = Day2::Report();

    SECTION("safe increase"){
        report.addLevel(1);
        report.addLevel(2);
        report.addLevel(4);
        report.addLevel(7);

        CHECK(report.safe == true);
    }
    
    SECTION("safe decrease"){
        report.addLevel(7);
        report.addLevel(6);
        report.addLevel(4);
        report.addLevel(1);

        CHECK(report.safe == true);
    }
    
    SECTION("1 unsafe decrease of 5"){
        report.addLevel(8); //remove this one
        report.addLevel(3);
        report.addLevel(2);
        report.addLevel(1);

        CHECK(report.safe == true);
    }
    
    SECTION("1 unsafe increase of 4"){
        report.addLevel(1);
        report.addLevel(2);
        report.addLevel(6); //remove this one
        report.addLevel(3);

        CHECK(report.safe == true);
    }
    
    SECTION("1 unsafe no change"){
        report.addLevel(7);
        report.addLevel(6); //remove either one
        report.addLevel(6); //remove either one
        report.addLevel(5);

        CHECK(report.safe == true);
    }
    
    SECTION("1 unsafe change direction"){
        report.addLevel(7);
        report.addLevel(6); //remove this one
        report.addLevel(8);
        report.addLevel(9);

        CHECK(report.safe == true);
    }

    SECTION("2 unsafe decrease of 5"){
        report.addLevel(12);
        report.addLevel(7);
        report.addLevel(2);
        report.addLevel(1);

        CHECK(report.safe == false);
    }
    
    SECTION("2 unsafe increase of 4"){
        report.addLevel(1);
        report.addLevel(2);
        report.addLevel(6);
        report.addLevel(10);

        CHECK(report.safe == false);
    }
    
    SECTION("2 unsafe no change"){
        report.addLevel(7);
        report.addLevel(6);
        report.addLevel(6);
        report.addLevel(6);

        CHECK(report.safe == false);
    }
    
    SECTION("2 unsafe change direction"){
        report.addLevel(7);
        report.addLevel(6);
        report.addLevel(8);
        report.addLevel(6);

        CHECK(report.safe == false);
    }
}

TEST_CASE("test day2 building functions", "[day2]"){
    Day2 day2 = Day2();

    CHECK(day2.head != nullptr);
    CHECK(day2.numSafe == 0);

    SECTION("2 reports of size 2"){
        day2.addToReport(1);
        day2.addToReport(2);

        day2.newReport();
        day2.addToReport(3);
        day2.addToReport(4);
        
        CHECK(day2.head->head->value == 3);
        CHECK(day2.head->head->next->value == 4);

        CHECK(day2.head->next->head->value == 1);
        CHECK(day2.head->next->head->next->value == 2);

        day2.newReport(); //have to do this to update numSafe with 2nd report 

        CHECK(day2.numSafe == 2);
    }
}
