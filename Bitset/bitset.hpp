#ifndef BITSET_HPP
#define BITSET_HPP
#include <stdint.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
//PUBLIC PORTION OF DEFINITION NOT TO BE EDITIED
class Bitset{
public:

  //Default constructor: Creates Bitset of size 8 - all bits set to 0.
  Bitset();

  //Overload constructor: Creates Bitset of size based on value of (intmax_t size).
  Bitset(intmax_t size);

  //Overload constructor: Creates Bitset of size based on length of string (binary string) value. 
  //Invalid if value is not 0 or 1. 
  Bitset(const std::string & value);

  //Destructor
  ~Bitset();
  
  //Deletes and unallocates a Bitset
  Bitset(const Bitset & ) = delete;
  Bitset & operator=(const Bitset &) = delete;

  //Returns the size of the Bitset in type 'intmax_t'.
  intmax_t size() const;

  //Determines if Bitset is valid: returns Boolean: true if valid, false if invalid.
  bool good() const;

  //Sets bit at paramter's index given by type 'intmax_t' to 1. 
  //If index isn't part of the bitset, then bitset becomes invalid.
  void set(intmax_t index);

  //Resets bit at paramter's index given by type 'intmax_t' to 0. 
  //If index isn't part of the bitset, then bitset becomes invalid.
  void reset(intmax_t index);

  //Toggles the bit at index given by type 'intmax_t' so that if the bit is 1, 
  //it becomes a 0 and vice-versa. Bitset becomes invalid if index is not part of the bitset.
  void toggle(intmax_t index);

  //Tests if a bit given by bit index of type 'intmax_t' is set to '1'. 
  //Returns true if set and false if not. If paramater given is not within bitset,
  // then returns false.
  bool test(intmax_t index);

  //Returns bitset as a std::string with contents being 0's and 1's. 
  //Left to right with Most-Significant Bit first
  std::string asString() const;

private:
  //validation variable
  bool valid=true;
  int *BitArray=nullptr;//null ptr 
  int len;//length variable

};

#endif
