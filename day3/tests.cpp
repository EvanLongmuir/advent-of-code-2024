#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#define private public //needed to test private member functions
#include "functions.h"

TEST_CASE("Mul Constructor","[Mul]"){
    auto i = GENERATE(1, 5, 10, 50, 100, 500, 999);
    auto j = GENERATE(1, 5, 10, 50, 100, 500, 999);

    MemoryReader::Mul mul = MemoryReader::Mul(i, j);

    CHECK(mul.num1 == i);
    CHECK(mul.num2 == j);
    CHECK(mul.product == i*j);
}

TEST_CASE("Add Mul and getSum functions","[addMul]"){
    auto i = GENERATE(1, 5, 10, 50, 100, 500, 999);
    auto j = GENERATE(1, 5, 10, 50, 100, 500, 999);
    auto k = GENERATE(1, 5, 10, 50, 100, 500, 999);
    auto l = GENERATE(1, 5, 10, 50, 100, 500, 999);
    auto m = GENERATE(1, 5, 10, 50, 100, 500, 999);
    auto n = GENERATE(1, 5, 10, 50, 100, 500, 999);

    MemoryReader reader = MemoryReader();

    INFO("add 1");

    reader.addMul(i, j);
    
    CHECK(reader.head->num1 == i);
    CHECK(reader.head->num2 == j);
    CHECK(reader.head->product == i*j);
    CHECK(reader.getSum() == i*j);

    INFO("add 2");

    reader.addMul(k, l);
    
    CHECK(reader.head->num1 == k);
    CHECK(reader.head->num2 == l);
    CHECK(reader.head->product == k*l);
    CHECK(reader.getSum() == i*j + k*l);

    INFO("add 3");

    reader.addMul(m, n);
    
    CHECK(reader.head->num1 == m);
    CHECK(reader.head->num2 == n);
    CHECK(reader.head->product == m*n);
    CHECK(reader.getSum() == i*j + k*l + m*n);
}

TEST_CASE("String from website","[websiteStr]"){
    MemoryReader reader = MemoryReader();

    std::string testString = "xmul(2,4)%&mul[3,7]!@^do_not_mul(5,5)+mul(32,64]then(mul(11,8)mul(8,5))";
    // m's at: 1, 11, 29, 38, 53, 62

    SECTION("testing just onCharM"){

        INFO("1st m");
        int i = 1;
        CHECK(reader.onCharM(testString, i) - i == 7);
        CHECK(reader.head->num1 == 2);
        CHECK(reader.head->num2 == 4);
        CHECK(reader.getSum() == 8);

        INFO("2nd m");
        i = 11;
        CHECK(reader.onCharM(testString, i) - i == 2);
        CHECK(reader.head->num1 == 2);
        CHECK(reader.head->num2 == 4);
        CHECK(reader.getSum() == 8);

        INFO("3rd m");
        i = 29;
        CHECK(reader.onCharM(testString, i) - i == 7);
        CHECK(reader.head->num1 == 5);
        CHECK(reader.head->num2 == 5);
        CHECK(reader.getSum() == 33);

        INFO("4th m");
        i = 38;
        CHECK(reader.onCharM(testString, i) - i == 8);
        CHECK(reader.head->num1 == 5);
        CHECK(reader.head->num2 == 5);
        CHECK(reader.getSum() == 33);

        INFO("5th m");
        i = 53;
        CHECK(reader.onCharM(testString, i) - i == 8);
        CHECK(reader.head->num1 == 11);
        CHECK(reader.head->num2 == 8);
        CHECK(reader.getSum() == 121);

        INFO("6th m");
        i = 62;
        CHECK(reader.onCharM(testString, i) - i == 7);
        CHECK(reader.head->num1 == 8);
        CHECK(reader.head->num2 == 5);
        CHECK(reader.getSum() == 161);
    }

    SECTION("testing readLine"){
        reader.readLine(testString);

        CHECK(reader.head->num1 == 8);
        CHECK(reader.head->num2 == 5);
        CHECK(reader.getSum() == 161);
    }
}

TEST_CASE("String from part2","[part2]"){
    MemoryReader reader = MemoryReader();

    std::string testString = "xmul(2,4)&mul[3,7]!^don't()_mul(5,5)+mul(32,64](mul(11,8)undo()?mul(8,5))";
    //d's at : 20, 59

    SECTION("testing just onCharD"){

        INFO("1st d");
        int i = 20;
        reader.onCharD(testString, i);
        CHECK(reader.enable == false);

        INFO("2nd d");
        i = 59;
        reader.onCharD(testString, i);
        CHECK(reader.enable == true);
    }

    SECTION("testing readLine with enable"){
        reader.readLine(testString);

        CHECK(reader.head->num1 == 8);
        CHECK(reader.head->num2 == 5);
        CHECK(reader.getSum() == 48);
    }
}
