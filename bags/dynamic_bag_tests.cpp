#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "dynamic_bag.hpp"

// force template expansion for ints
template class DynamicBag<int>;

TEST_CASE("Calling all public members", "[DynamicBag]"){
  DynamicBag<int> b;

  b.add(0);
  b.remove(0);
  b.isEmpty();
  b.getCurrentSize();
  b.clear();
  b.getFrequencyOf(0);
  b.contains(0);
}

TEST_CASE("Testing Copy Constructor and also Frequency")
  {
    DynamicBag<int> a;
    a.add(1);
    a.add(1);
    a.add(1);
    a.add(1);
    bool ye;
    DynamicBag<int> b(a);
    int matchcounter=0;
    if(b.getFrequencyOf(1)==4)
      {
        ye=true;
      }
    REQUIRE(ye);
  }

TEST_CASE("Testing = overload Constructor with instructed method")
  {
    DynamicBag<int> a;
    a.add(1);
    a.add(1);
    a.add(1);
    a.add(1);
    DynamicBag<int> b=a;
    bool ye;
     int matchcounter=0;
    if(b.getFrequencyOf(1)==4)
      {
        ye=true;
      }
    REQUIRE(ye);
  }

TEST_CASE("Testing Copy Construcor With Strings")
  {
    DynamicBag<std::string> a;

    REQUIRE(a.isEmpty());

    a.add("Rat Meat");
    a.add("Rat Meat");
    a.add("Roadkill");
    a.add("Testicles");
    a.add("Unborn Fetus");
    DynamicBag<std::string> b = a;
    REQUIRE_FALSE(b.isEmpty());
    REQUIRE(b.getFrequencyOf("Rat Meat") == 2);
    REQUIRE(b.getFrequencyOf("Unborn Fetus")==1);
  }
//test remove function
TEST_CASE("Test remove()")
  {
    DynamicBag<std::string> a;
    a.add("Government Secret");
    a.add("Victoria's Secret");
    a.add("Victoria's Secret");
    a.add("Victoria's Secret");
    a.add("Government Secret");
    a.remove("Government Secret");//remove government secret item
    a.remove("Victoria's Secret");
    a.remove("Victoria's Secret");
    REQUIRE(a.getFrequencyOf("Government Secret")==1);//after removing gov secret, should only be one.
    REQUIRE(a.getFrequencyOf("Victoria's Secret")==1);//after removing 2 Victoria's Secrets, should only be on.
    REQUIRE(a.getCurrentSize()==2);//size must be 2 after removals
  }

TEST_CASE("Test Remove when size 0")
  {
    DynamicBag<std::string> a;
    REQUIRE_FALSE(a.remove("George W. Bush"));
  }

TEST_CASE("Test clear()")
  {
    DynamicBag<std::string> a;
    a.add("Jeffrey Epstein");
    a.add("Hilary Clinton");
    a.add("Peter Dinklage");
    a.clear();
    REQUIRE(a.getCurrentSize()==0);
  }

TEST_CASE("Test Contains")
  {
    DynamicBag<std::string> a;
    a.add("Raw Chicken");
    a.add("Viagra");//0.0
    REQUIRE(a.contains("Raw Chicken"));
  }

TEST_CASE("Testing default constructor")
  {
    DynamicBag<std::string> a;
    REQUIRE(a.getCurrentSize()==0);
  }

TEST_CASE("Test swap()")
  {
    DynamicBag<std::string> a;
    DynamicBag<std::string> b;
    //already tested copy constructor, so
    a.add("Urn");
    a.add("Grandma");
    a.add("Grandpa");
    a.add("Juice Wrld");
    a.add("Steve Irwin");
    b.add("Kirby");
    b.add("Refugees");
    b.add("Sweatshop Children");
    b.add("Unemployed Business Major");
    a.swap(b);
    REQUIRE(b.getCurrentSize()==5);//size check
    REQUIRE(a.getCurrentSize()==4);//size check
    REQUIRE(b.contains("Urn"));
    REQUIRE(a.contains("Refugees"));
  }
//buncha remove testcases to try and find error
TEST_CASE("Test remove() with frequency")
  {
    DynamicBag<std::string> a;
    a.add("Urn");
    a.add("Grandma");
    a.add("Grandpa");
    a.add("Juice Wrld");
    a.add("Steve Irwin");
    a.remove("Grandma");
    a.remove("Grandpa");
    REQUIRE(a.getFrequencyOf("Grandma")==0);
    REQUIRE(a.getFrequencyOf("Grandpa")==0);
  }

TEST_CASE("Test remove() if successful")
  {
    DynamicBag<std::string> a;
    a.add("Goop");
    a.add("Goop");
    a.add("Goop");
    a.add("Goop");
    a.add("Poop");
    a.add("Poop");
    a.add("Poop");
    REQUIRE(a.remove("Goop"));
    REQUIRE(a.getCurrentSize()==6);
    REQUIRE(a.remove("Goop"));
    REQUIRE(a.remove("Goop"));
    REQUIRE(a.remove("Goop"));
    REQUIRE_FALSE(a.remove("Goop"));
    REQUIRE_FALSE(a.remove("Soup"));
  }

TEST_CASE("Test emojis")
  {
    DynamicBag<std::string> a;
    std::string 💀="💀💀💀💀💀";
    a.add(💀);
    std::cout<<💀;
  }
