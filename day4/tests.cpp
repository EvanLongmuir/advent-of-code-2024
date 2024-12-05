#include <catch2/catch_test_macros.hpp>
#define private public //needed to test private member functions
#include "functions.h"

TEST_CASE("find word function", "[findWord]"){
    
    SECTION("only straight line left"){
        Crossword::Letter* head = new Crossword::Letter('X');

        head->left = new Crossword::Letter('M');
        head->left->left = new Crossword::Letter('A');
        head->left->left->left = new Crossword::Letter('S');

        CHECK(head->findWordsLeft() == true);
        CHECK(head->findWords() == 1);
    }
    
    SECTION("only straight line left incomplete"){
        Crossword::Letter* head = new Crossword::Letter('X');

        head->left = new Crossword::Letter('M');
        head->left->left = new Crossword::Letter('A');

        CHECK(head->findWordsLeft() == false);
        CHECK(head->findWords() == 0);
    }

    SECTION("only straight line left wrong spelling"){
        Crossword::Letter* head = new Crossword::Letter('X');

        head->left = new Crossword::Letter('.');
        head->left->left = new Crossword::Letter('A');
        head->left->left->left = new Crossword::Letter('S');

        CHECK(head->findWordsLeft() == false);
        CHECK(head->findWords() == 0);
    }
    
    SECTION("only straight line left backwards"){
        Crossword::Letter* head = new Crossword::Letter('S');

        head->left = new Crossword::Letter('A');
        head->left->left = new Crossword::Letter('M');
        head->left->left->left = new Crossword::Letter('X');

        CHECK(head->findWordsLeft() == true);
        CHECK(head->findWords() == 1);
    }
    
    SECTION("only straight line left backwards incomplete"){
        Crossword::Letter* head = new Crossword::Letter('S');

        head->left = new Crossword::Letter('A');
        head->left->left = new Crossword::Letter('M');

        CHECK(head->findWordsLeft() == false);
        CHECK(head->findWords() == 0);
    }

    SECTION("only straight line left backwards wrong spelling"){
        Crossword::Letter* head = new Crossword::Letter('S');

        head->left = new Crossword::Letter('.');
        head->left->left = new Crossword::Letter('M');
        head->left->left->left = new Crossword::Letter('X');

        CHECK(head->findWordsLeft() == false);
        CHECK(head->findWords() == 0);
    }
    
    SECTION("only straight line diagL"){
        Crossword::Letter* head = new Crossword::Letter('X');

        head->diagL = new Crossword::Letter('M');
        head->diagL->diagL = new Crossword::Letter('A');
        head->diagL->diagL->diagL = new Crossword::Letter('S');

        CHECK(head->findWordsDiagL() == true);
        CHECK(head->findWords() == 1);
    }
    
    SECTION("only straight line diagL incomplete"){
        Crossword::Letter* head = new Crossword::Letter('X');

        head->diagL = new Crossword::Letter('M');
        head->diagL->diagL = new Crossword::Letter('A');

        CHECK(head->findWordsDiagL() == false);
        CHECK(head->findWords() == 0);
    }

    SECTION("only straight line diagL wrong spelling"){
        Crossword::Letter* head = new Crossword::Letter('X');

        head->diagL = new Crossword::Letter('.');
        head->diagL->diagL = new Crossword::Letter('A');
        head->diagL->diagL->diagL = new Crossword::Letter('S');

        CHECK(head->findWordsDiagL() == false);
        CHECK(head->findWords() == 0);
    }
    
    SECTION("only straight line diagL backwards"){
        Crossword::Letter* head = new Crossword::Letter('S');

        head->diagL = new Crossword::Letter('A');
        head->diagL->diagL = new Crossword::Letter('M');
        head->diagL->diagL->diagL = new Crossword::Letter('X');

        CHECK(head->findWordsDiagL() == true);
        CHECK(head->findWords() == 1);
    }
    
    SECTION("only straight line diagL backwards incomplete"){
        Crossword::Letter* head = new Crossword::Letter('S');

        head->diagL = new Crossword::Letter('A');
        head->diagL->diagL = new Crossword::Letter('M');

        CHECK(head->findWordsDiagL() == false);
        CHECK(head->findWords() == 0);
    }

    SECTION("only straight line diagL backwards wrong spelling"){
        Crossword::Letter* head = new Crossword::Letter('S');

        head->diagL = new Crossword::Letter('.');
        head->diagL->diagL = new Crossword::Letter('M');
        head->diagL->diagL->diagL = new Crossword::Letter('X');

        CHECK(head->findWordsDiagL() == false);
        CHECK(head->findWords() == 0);
    }
    
    SECTION("only straight line up"){
        Crossword::Letter* head = new Crossword::Letter('X');

        head->up = new Crossword::Letter('M');
        head->up->up = new Crossword::Letter('A');
        head->up->up->up = new Crossword::Letter('S');

        CHECK(head->findWordsUp() == true);
        CHECK(head->findWords() == 1);
    }
    
    SECTION("only straight line up incomplete"){
        Crossword::Letter* head = new Crossword::Letter('X');

        head->up = new Crossword::Letter('M');
        head->up->up = new Crossword::Letter('A');

        CHECK(head->findWordsUp() == false);
        CHECK(head->findWords() == 0);
    }

    SECTION("only straight line up wrong spelling"){
        Crossword::Letter* head = new Crossword::Letter('X');

        head->up = new Crossword::Letter('.');
        head->up->up = new Crossword::Letter('A');
        head->up->up->up = new Crossword::Letter('S');

        CHECK(head->findWordsUp() == false);
        CHECK(head->findWords() == 0);
    }
    
    SECTION("only straight line up backwards"){
        Crossword::Letter* head = new Crossword::Letter('S');

        head->up = new Crossword::Letter('A');
        head->up->up = new Crossword::Letter('M');
        head->up->up->up = new Crossword::Letter('X');

        CHECK(head->findWordsUp() == true);
        CHECK(head->findWords() == 1);
    }
    
    SECTION("only straight line up backwards incomplete"){
        Crossword::Letter* head = new Crossword::Letter('S');

        head->up = new Crossword::Letter('A');
        head->up->up = new Crossword::Letter('M');

        CHECK(head->findWordsUp() == false);
        CHECK(head->findWords() == 0);
    }

    SECTION("only straight line up backwards wrong spelling"){
        Crossword::Letter* head = new Crossword::Letter('S');

        head->up = new Crossword::Letter('.');
        head->up->up = new Crossword::Letter('M');
        head->up->up->up = new Crossword::Letter('X');

        CHECK(head->findWordsUp() == false);
        CHECK(head->findWords() == 0);
    }
    
    SECTION("only straight line diagR"){
        Crossword::Letter* head = new Crossword::Letter('X');

        head->diagR = new Crossword::Letter('M');
        head->diagR->diagR = new Crossword::Letter('A');
        head->diagR->diagR->diagR = new Crossword::Letter('S');

        CHECK(head->findWordsDiagR() == true);
        CHECK(head->findWords() == 1);
    }
    
    SECTION("only straight line diagR incomplete"){
        Crossword::Letter* head = new Crossword::Letter('X');

        head->diagR = new Crossword::Letter('M');
        head->diagR->diagR = new Crossword::Letter('A');

        CHECK(head->findWordsDiagR() == false);
        CHECK(head->findWords() == 0);
    }

    SECTION("only straight line diagR wrong spelling"){
        Crossword::Letter* head = new Crossword::Letter('X');

        head->diagR = new Crossword::Letter('.');
        head->diagR->diagR = new Crossword::Letter('A');
        head->diagR->diagR->diagR = new Crossword::Letter('S');

        CHECK(head->findWordsDiagR() == false);
        CHECK(head->findWords() == 0);
    }
    
    SECTION("only straight line diagR backwards"){
        Crossword::Letter* head = new Crossword::Letter('S');

        head->diagR = new Crossword::Letter('A');
        head->diagR->diagR = new Crossword::Letter('M');
        head->diagR->diagR->diagR = new Crossword::Letter('X');

        CHECK(head->findWordsDiagR() == true);
        CHECK(head->findWords() == 1);
    }
    
    SECTION("only straight line diagR backwards incomplete"){
        Crossword::Letter* head = new Crossword::Letter('S');

        head->diagR = new Crossword::Letter('A');
        head->diagR->diagR = new Crossword::Letter('M');

        CHECK(head->findWordsDiagR() == false);
        CHECK(head->findWords() == 0);
    }

    SECTION("only straight line diagR backwards wrong spelling"){
        Crossword::Letter* head = new Crossword::Letter('S');

        head->diagR = new Crossword::Letter('.');
        head->diagR->diagR = new Crossword::Letter('M');
        head->diagR->diagR->diagR = new Crossword::Letter('X');

        CHECK(head->findWordsDiagR() == false);
        CHECK(head->findWords() == 0);
    }
}

TEST_CASE("add Letter Function", "[addLetter]"){
    Crossword puzzle = Crossword();

    SECTION("add one letter"){
        CHECK(puzzle.addLetter('X') == 0);
        CHECK(puzzle.head->value == 'X');
    }

    SECTION("add two letters"){
        CHECK(puzzle.addLetter('X') == 0);
        CHECK(puzzle.addLetter('M') == 0);

        CHECK(puzzle.head->value == 'X');
        CHECK(puzzle.head->right != nullptr);
        CHECK(puzzle.head->right->value == 'M');
    }

    SECTION("add full word"){
        CHECK(puzzle.addLetter('X') == 0);
        CHECK(puzzle.addLetter('M') == 0);
        CHECK(puzzle.addLetter('A') == 0);
        CHECK(puzzle.addLetter('S') == 1);

        CHECK(puzzle.head->value == 'X');
        CHECK(puzzle.head->right->value == 'M');
        CHECK(puzzle.head->right->right->value == 'A');
        CHECK(puzzle.head->right->right->right->value == 'S');
    }
}

TEST_CASE("add Line Function", "[addLine]"){
    Crossword puzzle = Crossword();

    SECTION("add one line of size 2"){
        puzzle.addLine("XM");
        CHECK(puzzle.head->value == 'X');
        CHECK(puzzle.head->right->value == 'M');
        CHECK(puzzle.words == 0);
    }

    SECTION("add 2x2 grid"){
        puzzle.addLine("XM");
        puzzle.addLine("AS");

        CHECK(puzzle.head->value == 'A');
        CHECK(puzzle.head->right->value == 'S');
        CHECK(puzzle.head->up->value == 'X');
        CHECK(puzzle.head->right->diagL->value == 'X');
        CHECK(puzzle.head->diagR->value == 'M');
        CHECK(puzzle.head->right->up->value == 'M');

        CHECK(puzzle.words == 0);
    }

    SECTION("example from website with dots"){
        puzzle.addLine("....XXMAS.");
        puzzle.addLine(".SAMXMS...");
        puzzle.addLine("...S..A...");
        puzzle.addLine("..A.A.MS.X");
        puzzle.addLine("XMASAMX.MM");
        puzzle.addLine("X.....XA.A");
        puzzle.addLine("S.S.S.S.SS");
        puzzle.addLine(".A.A.A.A.A");
        puzzle.addLine("..M.M.M.MM");
        puzzle.addLine(".X.X.XMASX");

        CHECK(puzzle.words == 18);
    }

    SECTION("example from website no dots"){
        puzzle.addLine("MMMSXXMASM");
        puzzle.addLine("MSAMXMSMSA");
        puzzle.addLine("AMXSXMAAMM");
        puzzle.addLine("MSAMASMSMX");
        puzzle.addLine("XMASAMXAMM");
        puzzle.addLine("XXAMMXXAMA");
        puzzle.addLine("SMSMSASXSS");
        puzzle.addLine("SAXAMASAAA");
        puzzle.addLine("MAMMMXMMMM");
        puzzle.addLine("MXMXAXMASX");

        CHECK(puzzle.words == 18);
    }

    SECTION("part 2 example"){
        puzzle.addLine(".M.S......");
        puzzle.addLine("..A..MSMS.");
        puzzle.addLine(".M.S.MAA..");
        puzzle.addLine("..A.ASMSM.");
        puzzle.addLine(".M.S.M....");
        puzzle.addLine("..........");
        puzzle.addLine("S.S.S.S.S.");
        puzzle.addLine(".A.A.A.A..");
        puzzle.addLine("M.M.M.M.M.");
        puzzle.addLine("..........");

        CHECK(puzzle.xs == 9);
    }
}
