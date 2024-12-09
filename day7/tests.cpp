#include <catch2/catch_test_macros.hpp>
#define private public //needed to test private member functions
#include "functions.h"

TEST_CASE("example from website", "[website]"){
    Calibrations calibration = Calibrations();

    calibration.readLine("190: 10 19");
    CHECK(calibration.head->value == 190);
    CHECK(calibration.head->head->value == 10);
    CHECK(calibration.head->head->next->value == 19);

    calibration.readLine("3267: 81 40 27");
    CHECK(calibration.head->value == 3267);
    CHECK(calibration.head->head->value == 81);
    CHECK(calibration.head->head->next->value == 40);
    CHECK(calibration.head->head->next->next->value == 27);
    CHECK(calibration.head->next->value == 190);
    CHECK(calibration.head->next->head->value == 10);
    CHECK(calibration.head->next->head->next->value == 19);

    calibration.readLine("83: 17 5");
    calibration.readLine("156: 15 6");
    calibration.readLine("7290: 6 8 6 15");
    calibration.readLine("161011: 16 10 13");
    calibration.readLine("192: 17 8 14");
    calibration.readLine("21037: 9 7 18 13");
    calibration.readLine("292: 11 6 16 20");

    CHECK(calibration.getSum() == 11387);
}

TEST_CASE("edge case", "[edge]"){
    Calibrations calibration = Calibrations();

    calibration.readLine("5: 2 5");
    CHECK(calibration.head->checkValid(calibration.head->head) == false);
}
