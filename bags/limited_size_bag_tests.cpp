#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "limited_size_bag.hpp"

// force template expansion for ints
template class LimitedSizeBag<int>;

TEST_CASE("Calling all public members", "[LimitedSizeBag]"){
  LimitedSizeBag<int> b;

  b.add(0);
  b.remove(0);
  b.isEmpty();
  b.getCurrentSize();
  b.clear();
  b.getFrequencyOf(0);
  b.contains(0);

}

TEST_CASE("Frequency test"){
  LimitedSizeBag<std::string> b;
  b.add("Dog");
  b.add("Cat");
  b.add("Dog");
  REQUIRE(b.getFrequencyOf("Dog") == 2);
}

TEST_CASE("Copy and frequency tester"){
  LimitedSizeBag<std::string> a;

  REQUIRE(a.isEmpty());

  a.add("Monkey");
  a.add("Giraffe");
  a.add("Lion");
  a.add("Horse");
  a.add("Monkey");
  REQUIRE_FALSE(a.isEmpty());
  LimitedSizeBag<std::string> b = a;
  REQUIRE_FALSE(b.isEmpty());
  REQUIRE(b.add("Monkey"));
  REQUIRE(b.getFrequencyOf("Monkey") == 3);

}

TEST_CASE("Frequency, size, and remove tester"){
  LimitedSizeBag<std::string> a;
  a.add("Ball");
  a.add("Boot");
  a.add("Cookie");
  a.add("Rock");
  a.add("Doll");
  a.add("Cheese");
  a.add("Ball");
  REQUIRE(a.getFrequencyOf("Ball") == 2);
  REQUIRE(a.getCurrentSize() == 7);
  REQUIRE(a.remove("Boot"));
  REQUIRE_FALSE(a.remove("Boot"));
  REQUIRE(a.getFrequencyOf("Boot") == 0);
}

TEST_CASE("clear tester"){
  LimitedSizeBag<std::string> a;
  a.add("Toenail");
  a.add("Pepperoni");
  a.add("Burgerking Foot Lettuce");
  a.add("Acne");
  a.add("Flies");
  a.add("Cockroach");
  a.add("Teeth");
  a.add("Mold");
  a.clear();
  REQUIRE(a.getCurrentSize() == 0);
}

TEST_CASE ("Add, Contains, Frequency tester"){
  LimitedSizeBag<std::string> b;
  for(int i = 0; i < 100; i++){
    b.add("Rice grain");
  }
  REQUIRE(b.contains("Rice grain"));
  REQUIRE(b.getFrequencyOf("Rice grain") == 100);
  REQUIRE(b.getCurrentSize() == 100);
  std::cout << b.getCurrentSize() << "\n";
  REQUIRE_FALSE(b.add("Rice grain"));
}