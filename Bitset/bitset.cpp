#include "bitset.hpp"

Bitset::Bitset() {
   //Allocate memory for an array of bits and fill with 0. 
    len=8;
    BitArray=new int[8];
    for (int i=0;i<len;i++)//loop to fill bitarray with 0's
      {
        BitArray[i]=0;
      }
}

Bitset::Bitset(intmax_t size) {
    //Allocate memory for array of bits of size 'size' and fill with 0.
    len=size;
    if(size>0)//run only if size is larger than 0;
    {
    BitArray=new int[size];
     for (int i=0;i<size;i++)//loop to fill bit array of input size w 0's
      {
        BitArray[i]=0;
      }
    }
    else
    {
      valid=false;//if size is not greater than 0, make bitset invalid
    }
}

Bitset::Bitset(const std::string & value) 
  {
    //Setting length of string as array size and copying the string bitset to BitArray.
    len=value.length();
    BitArray=new int[value.length()];//construct array
    for(int i=0;i<len;i++)//loop to fill BitArray with values based on what's read from string
      {
        if(value[i]=='1')
          {
            BitArray[i]=1;
          }
        else if(value[i]=='0')
          {
            BitArray[i]=0;
          }
        else
          {
            valid=false;//if value read if not 1 or 0, then is invalid
          }
      }
  }


Bitset::~Bitset() {
    //Destructor to delete Bitset
    delete [] BitArray;
}

//Returns the size of the Bitset in type 'intmax_t'.
intmax_t Bitset::size() const
{//getting length of bitset through address
    return len;
}

  //Determines if Bitset is valid: returns Boolean: true if valid, false if invalid.
bool Bitset::good() const
{
    return valid;//returns validating boolean
}

  //Sets bit at paramter's index given by type 'intmax_t' to 1. 
  //If index isn't part of the bitset, then bitset becomes invalid.
void Bitset::set(intmax_t index)
{
 if(index<size()&&index>=0)//if input is within index bounds
  {
    BitArray[index]=1;//set the value at the index to 1
  }
  else 
    {
      valid=false;//if not in the index bounds, then make the bitset invalid
    }
}

  //Resets bit at paramter's index given by type 'intmax_t' to 0. 
  //If index isn't part of the bitset, then bitset becomes invalid.
void Bitset::reset(intmax_t index)
{
  if(index<size()&&index>=0)//if index input is within bounds
  {
    BitArray[index]=0;//if valid, set value at index to 0
  }
  else 
    {
      valid=false;//if input not within bounds, set bitset invalid
    }
}

  //Toggles the bit at index given by type 'intmax_t' so that if the bit is 1, 
  //it becomes a 0 and vice-versa. Bitset becomes invalid if index is not part of the bitset.
void Bitset::toggle(intmax_t index)
{
  if (index>=len||index<0)//if outside bounds, make bitset invalid
    {
      valid=false;
    }
  else
  {
      if(BitArray[index]==1||BitArray[index]==0)//if array content is binary
        {
        if(BitArray[index]==0)//if 0, make 1
          {
            BitArray[index]=1;
          }
        else if(BitArray[index]==1)
          {
            BitArray[index]=0;//if not 0, make 0
          }
        }
      else
        {
          valid=false;//if not 1 or 0, valid checker=false
        }
    }
}

  //Tests if a bit given by bit index of type 'intmax_t' is set to '1'. 
  //Returns true if set and false if not. If paramater given is not within bitset,
  // then returns false.
bool Bitset::test(intmax_t index)
{
  bool temp;
 if(index>size()||index<0)//if input outside of bounds.
    {// make bitset invalid and set return variable to false also
      valid=false;
      temp=false;
    }
  else
    {
      if(BitArray[index]==1)//if value at the index is 1
        {//set return variable to true
          temp=true;
        }
      else 
        {//otherwise, set return variable to false
          temp=false;
        }
    }
  return temp;
}

  //Returns bitset as a std::string with contents being 0's and 1's. 
  //Left to right with Most-Significant Bit first
  std::string Bitset::asString() const
{   
  //unsure if im supposed to use <string> functions, but they wouldn't work for me
  std::string Sform="";//create String with no values
  //doesn't say to error check since in instructions, it'll run even with a negative length and probably cause error.
    if(valid)//adding error checking by running only if valid
      {
        for(int i=0;i<len;i++)//loop to fill empty string with values from the Bitset
        {
          if(BitArray[i]==0)//if bitset value is 0
            {
              Sform+='0';//Add a 0 to string
            }
          if(BitArray[i]==1)//if bitset value is 1
            {
              Sform+='1';//Add a 1 to string
            }
        }
      }
    else//if not valid, then return a string saying "Bitset Invalid"
      {
        Sform="Bitset Invalid";
      }
  return Sform;
}

 


// TODO: other methods
