#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include <iostream>
#include "bitset.hpp"

TEST_CASE( "Test bitset default construction", "[bitset]" ) {

    Bitset b;  
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
}

TEST_CASE( "Test bitset construction with asString", "[bitset]" ) {
    Bitset b;
    REQUIRE(b.asString().compare("00000000") == 0);
}

TEST_CASE( "Test bitset construction size", "[bitset]" ) {
    Bitset b(64);
    std::string s(64, '0');
    REQUIRE(b.size() == 64);
    REQUIRE(b.good());
}

TEST_CASE( "Test bitset construction string", "[bitset]" ) {
    std::string s("00101110000011000001101000001");
    Bitset b(s);
    REQUIRE(b.size() == s.size());
    REQUIRE(b.good());
    REQUIRE(b.asString().compare(s) == 0);
}

TEST_CASE( "Test bitset construction invalid string", "[bitset]" ) {
    std::string s("00101110000011002001101000001");
    Bitset b(s);
    REQUIRE_FALSE(b.good());
}

TEST_CASE( "Test set", "[bitset]" ) {
    std::string s("00010001");
    Bitset b;
    b.set(3);
    b.set(7);
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
    REQUIRE(b.asString().compare(s) == 0);
}

TEST_CASE( "Test set with default init", "[bitset]" ) {
    std::string s("00010001");
    Bitset b;
    b.set(3);
    b.set(7);
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
    REQUIRE(b.asString().compare(s) == 0);
}

TEST_CASE( "Test set with size init", "[bitset]" ) {
    std::string s("00010");
    Bitset b(5);
    b.set(3);
    REQUIRE(b.size() == 5);
    REQUIRE(b.good());
    REQUIRE(b.asString().compare(s) == 0);
}

TEST_CASE( "Test combined", "[bitset]" ) {
    std::string s((1<<15) + 3, '0');
    Bitset b(s);
    REQUIRE(b.size() == s.size());
    REQUIRE(b.good());
    REQUIRE(b.asString().compare(s) == 0);

    for (int i = 1; i < (1<<10); i++) {
        b.set(i);
        b.reset(i + (1<<10));
        b.toggle(i + (1<<11));
        REQUIRE(b.good());
        REQUIRE(b.test(i));
        REQUIRE_FALSE(b.test(i + (1<<10)));
        REQUIRE(((b.test(i + (1<<11)) == true && s.at(i + (1<<11)) == '0') || (b.test(i + (1<<11)) == false && s.at(i + (1<<11)) == '1')));
    }
}
//My own test cases start here.
TEST_CASE("Test with negative input size")
    {//also testing functionality of size() with negative size.
        Bitset b(-10);
        REQUIRE(b.size()==-10);
        REQUIRE_FALSE(b.good());
    }
//since the string constructor was tested alot already, I'll skip
TEST_CASE("Test out of bounds index with set()")
    {
        Bitset b;//bitset with default size 8
        b.set(69);//trying to set index way out of bounds
        REQUIRE_FALSE(b.good());//must be invalid bitset
    }
TEST_CASE("Test out of bounds index with reset()")
    {
        Bitset b;//bitset with default size 8
        b.reset(69);//trying to set index way out of bounds
        REQUIRE_FALSE(b.good());//must be invalid bitset
    }
TEST_CASE("Toggling entire bitset")
    {
        Bitset b;//bitset with default size 8
        for(int i=0;i<b.size();i++)
            {
             b.toggle(i);//looping through and toggling every bit
            }
        REQUIRE(b.asString()=="11111111");//as string should show 8 character string of all 1's
    }
TEST_CASE("Test test() using index far out of bounds")
    {
        Bitset b;//bitset with default size 8
        b.test(69);//trying to test index way out of bounds
        REQUIRE_FALSE(b.good());//must be invalid bitset
    }
TEST_CASE("Test what happens if asString() with invalid bitset")
    {
        Bitset b;//bitset with default size 8
        b.set(69);//trying to set index way out of bounds
        REQUIRE(b.asString()=="Bitset Invalid");//must be invalid bitset
    }
TEST_CASE("Test what happens if string input isn't of 1's and 0's")//7 New test cases at this point (I can't think of any that wouldn't be redundant with the existing tests.)
    {
        std::string Tester="RandomTestString";//test string
        Bitset b(Tester);//make bitset
        REQUIRE_FALSE(b.good());//must be invalid bitset
    }
TEST_CASE("Test what happens if size 0 is plugged in")
    {
        Bitset b(0);
        REQUIRE_FALSE(b.good());
    }
TEST_CASE("Test a humungous string")//test #9
    {
        std::string Huge="10101010101010010101010101010100101010101001010100101010101001010000101010010101010010101";//very big string
        Bitset b(Huge);
        REQUIRE(Huge.length()==b.size());//must still work 
    }
