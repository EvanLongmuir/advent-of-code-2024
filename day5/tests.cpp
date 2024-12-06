#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#define private public //needed to test private member functions
#include "functions.h"

TEST_CASE("add page function","[addPage]"){
    Manual::Update update = Manual::Update();

    INFO("adding 1st page");
    auto i = GENERATE(1, 10, 50, 99);
    update.addPage(i);

    REQUIRE(update.pages->last == nullptr);
    REQUIRE(update.pages->value == i);
    REQUIRE(update.pages->next == nullptr);

    REQUIRE(update.numPages == 1);


    INFO("adding 2nd page");
    auto j = GENERATE(1, 10, 50, 99);
    update.addPage(j);

    REQUIRE(update.pages->last == nullptr);
    REQUIRE(update.pages->value == i);
    REQUIRE(update.pages->next->last->value == i);
    REQUIRE(update.pages->next->value == j);
    REQUIRE(update.pages->next->next == nullptr);

    REQUIRE(update.numPages == 2);


    INFO("adding 3rd page");
    auto k = GENERATE(1, 10, 50, 99);
    update.addPage(k);

    REQUIRE(update.pages->last == nullptr);
    REQUIRE(update.pages->value == i);
    REQUIRE(update.pages->next->last->value == i);
    REQUIRE(update.pages->next->value == j);
    REQUIRE(update.pages->next->next->last->value == j);
    REQUIRE(update.pages->next->next->value == k);
    REQUIRE(update.pages->next->next->next == nullptr);

    REQUIRE(update.numPages == 3);
}

TEST_CASE("add rule function","[addRule]"){
    Manual manual = Manual();

    std::string combination;

    INFO("adding 1st rule");
    auto a = GENERATE(1, 10, 50, 99);
    auto b = GENERATE(1, 10, 50, 99);
    combination = std::to_string(a) + "|" + std::to_string(b);
    manual.addRule(combination);

    REQUIRE(manual.rules->rules[0] == a);
    REQUIRE(manual.rules->rules[1] == b);
    REQUIRE(manual.rules->next == nullptr);


    INFO("adding 2nd rule");
    auto c = GENERATE(1, 10, 50, 99);
    auto d = GENERATE(1, 10, 50, 99);
    combination = std::to_string(c) + "|" + std::to_string(d);
    manual.addRule(combination);

    REQUIRE(manual.rules->rules[0] == a);
    REQUIRE(manual.rules->rules[1] == b);
    REQUIRE(manual.rules->next->rules[0] == c);
    REQUIRE(manual.rules->next->rules[1] == d);
    REQUIRE(manual.rules->next->next == nullptr);


    INFO("adding 3rd rule");
    auto e = GENERATE(1, 10, 50, 99);
    auto f = GENERATE(1, 10, 50, 99);
    combination = std::to_string(e) + "|" + std::to_string(f);
    manual.addRule(combination);

    REQUIRE(manual.rules->rules[0] == a);
    REQUIRE(manual.rules->rules[1] == b);
    REQUIRE(manual.rules->next->rules[0] == c);
    REQUIRE(manual.rules->next->rules[1] == d);
    REQUIRE(manual.rules->next->next->rules[0] == e);
    REQUIRE(manual.rules->next->next->rules[1] == f);
    REQUIRE(manual.rules->next->next->next == nullptr);
}

TEST_CASE("add update function","[addUpdate]"){
    Manual manual = Manual();

    std::string combination;

    INFO("adding 1st update");
    auto a = GENERATE(1, 10, 50, 99);
    auto b = GENERATE(1, 10, 50, 99);
    auto c = GENERATE(1, 10, 50, 99);
    combination = std::to_string(a) + "," + std::to_string(b) + "," + std::to_string(c);
    manual.addUpdate(combination);

    REQUIRE(manual.updates->pages->value == a);
    REQUIRE(manual.updates->pages->next->value == b);
    REQUIRE(manual.updates->pages->next->next->value == c);
    REQUIRE(manual.updates->next == nullptr);

    REQUIRE(manual.updates->middleValue == b);

    INFO("adding 2nd update");
    auto d = GENERATE(1, 10, 50, 99);
    auto e = GENERATE(1, 10, 50, 99);
    auto f = GENERATE(1, 10, 50, 99);
    auto g = GENERATE(1, 10, 50, 99);
    combination = std::to_string(d) + "," + std::to_string(e) + "," + std::to_string(f) + "," + std::to_string(g);
    manual.addUpdate(combination);

    REQUIRE(manual.updates->pages->value == a);
    REQUIRE(manual.updates->pages->next->value == b);
    REQUIRE(manual.updates->pages->next->next->value == c);
    REQUIRE(manual.updates->next->pages->value == d);
    REQUIRE(manual.updates->next->pages->next->value == e);
    REQUIRE(manual.updates->next->pages->next->next->value == f);
    REQUIRE(manual.updates->next->pages->next->next->next->value == g);
    REQUIRE(manual.updates->next->next == nullptr);

    REQUIRE(manual.updates->next->middleValue == f);


    INFO("adding 3rd update");
    auto h = GENERATE(1, 10, 50, 99);
    auto i = GENERATE(1, 10, 50, 99);
    combination = std::to_string(h) + "," + std::to_string(i);
    manual.addUpdate(combination);

    REQUIRE(manual.updates->pages->value == a);
    REQUIRE(manual.updates->pages->next->value == b);
    REQUIRE(manual.updates->pages->next->next->value == c);
    REQUIRE(manual.updates->next->pages->value == d);
    REQUIRE(manual.updates->next->pages->next->value == e);
    REQUIRE(manual.updates->next->pages->next->next->value == f);
    REQUIRE(manual.updates->next->pages->next->next->next->value == g);
    REQUIRE(manual.updates->next->next->pages->value == h);
    REQUIRE(manual.updates->next->next->pages->next->value == i);
    REQUIRE(manual.updates->next->next->next == nullptr);

    REQUIRE(manual.updates->next->next->middleValue == i);
}

TEST_CASE("read line function","[readLine]"){
    Manual manual = Manual();

    std::string combination;
    auto a = GENERATE(1, 10, 50, 99);
    auto b = GENERATE(1, 10, 50, 99);
    auto c = GENERATE(1, 10, 50, 99);
    auto d = GENERATE(1, 10, 50, 99);

    INFO("adding rule");
    combination = std::to_string(a) + "|" + std::to_string(b);
    manual.readLine(combination);

    REQUIRE(manual.rules->rules[0] == a);
    REQUIRE(manual.rules->rules[1] == b);


    INFO("adding update");
    combination = std::to_string(a) + "," + std::to_string(b) + "," + std::to_string(c) + "," + std::to_string(d);
    manual.readLine(combination);
    REQUIRE(manual.updates->pages->value == a);
    REQUIRE(manual.updates->pages->next->value == b);
    REQUIRE(manual.updates->pages->next->next->value == c);
    REQUIRE(manual.updates->pages->next->next->next->value == d);
}

TEST_CASE("stress test middle values to look for seg fault", "[full]"){
    Manual manual = Manual();

    std::string combination;
    auto a = GENERATE(1, 10, 50, 99);
    auto b = GENERATE(1, 10, 50, 99);
    auto c = GENERATE(1, 10, 50, 99);
    auto d = GENERATE(1, 10, 50, 99);
    auto e = GENERATE(1, 10, 50, 99);
    auto f = GENERATE(1, 10, 50, 99);
    auto g = GENERATE(1, 10, 50, 99);
    auto h = GENERATE(1, 10, 50, 99);
    auto i = GENERATE(1, 10, 50, 99);

    INFO(a);
    INFO(b);
    INFO(c);
    INFO(d);
    INFO(e);
    INFO(f);
    INFO(g);
    INFO(h);
    INFO(i);

    combination = std::to_string(a) + "|" + std::to_string(b);
    manual.readLine(combination);

    combination = std::to_string(c) + "|" + std::to_string(d);
    manual.readLine(combination);

    combination = std::to_string(e) + "," + std::to_string(f) + "," + std::to_string(g) + "," + std::to_string(h) + "," + std::to_string(i);
    manual.readLine(combination);

    INFO(manual.addMiddleValues(true));
    INFO(manual.addMiddleValues(false));
}

TEST_CASE("example from website", "[example]"){
    Manual manual = Manual();

    manual.readLine("47|53");
    manual.readLine("97|13");
    manual.readLine("97|61");
    manual.readLine("97|47");
    manual.readLine("75|29");
    manual.readLine("61|13");
    manual.readLine("75|53");
    manual.readLine("29|13");
    manual.readLine("97|29");
    manual.readLine("53|29");
    manual.readLine("61|53");
    manual.readLine("97|53");
    manual.readLine("61|29");
    manual.readLine("47|13");
    manual.readLine("75|47");
    manual.readLine("97|75");
    manual.readLine("47|61");
    manual.readLine("75|61");
    manual.readLine("47|29");
    manual.readLine("75|13");
    manual.readLine("53|13");
    manual.readLine("");
    manual.readLine("75,47,61,53,29");
    manual.readLine("97,61,53,29,13");
    manual.readLine("75,29,13      ");
    manual.readLine("75,97,47,61,53");
    manual.readLine("61,13,29      ");
    manual.readLine("97,13,75,29,47");


    CHECK(manual.addMiddleValues(true) == 143);
    CHECK(manual.addMiddleValues(false) == 123);

    CHECK(manual.updates->valid == true);
    CHECK(manual.updates->middleValue == 61);
    CHECK(manual.updates->next->valid == true);
    CHECK(manual.updates->next->middleValue == 53);
    CHECK(manual.updates->next->next->valid == true);
    CHECK(manual.updates->next->next->middleValue == 29);
    CHECK(manual.updates->next->next->next->valid == false);
    CHECK(manual.updates->next->next->next->middleValue == 47);
    CHECK(manual.updates->next->next->next->next->valid == false);
    CHECK(manual.updates->next->next->next->next->middleValue == 29);
    CHECK(manual.updates->next->next->next->next->next->valid == false);
    REQUIRE(manual.updates->next->next->next->next->next->middleValue == 47);
}
