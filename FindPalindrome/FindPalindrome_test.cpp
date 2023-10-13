#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"

// There should be at least one test per FindPalindrome method

TEST_CASE( "Test adding a non-allowable word")
{
	FindPalindrome b;
	REQUIRE(!b.add("vroooooom"));
}

TEST_CASE("test recursion"){
	FindPalindrome b;

	REQUIRE(b.add("B"));
	REQUIRE(b.add("b"));
	REQUIRE(b.add("bbb"));
	REQUIRE(b.number() == 6);
}

TEST_CASE("test clear"){
	FindPalindrome b;

	REQUIRE(b.add("b"));
	REQUIRE(b.add("AA"));
	REQUIRE(b.add("BaA"));

	b.clear();

	REQUIRE(b.number() == 0);
}

TEST_CASE("test no  palindromes"){
	FindPalindrome b;

	REQUIRE(b.add("a"));
	REQUIRE(b.add("BC"));
	REQUIRE(b.add("DeF"));
	REQUIRE(b.number() == 0);
}

TEST_CASE("cuttest1"){
	FindPalindrome b;

	std::vector<std::string> test;
	test.push_back("kayak");
	test.push_back("doodood");
	test.push_back("cheeseeseehc");

	REQUIRE(b.cutTest1(test));
}

TEST_CASE("false cuttest1"){
	FindPalindrome b;

	std::vector<std::string> test;
	test.push_back("cooties");
	test.push_back("rat");
	test.push_back("dog");

	REQUIRE(!b.cutTest1(test));
}

TEST_CASE("test cuttest2"){
	FindPalindrome b;

	std::vector<std::string> test;
	test.push_back("tikkit");
	test.push_back("doodood");
	test.push_back("cheeseseehc");

	std::vector<std::string> test2;
	test2.push_back("tokkot");
	test2.push_back("tookoot");
	test2.push_back("tootoot");

	REQUIRE(b.cutTest2(test, test2));
}

TEST_CASE("test false cuttest2"){
	FindPalindrome b;

	std::vector<std::string> test;
	test.push_back("tokkot");
	test.push_back("tookoot");
	test.push_back("tootoot");

	std::vector<std::string> test2;
	test2.push_back("tokkot");
	test2.push_back("tookoot");
	test2.push_back("tootoot");

	REQUIRE(!b.cutTest2(test, test2));
}