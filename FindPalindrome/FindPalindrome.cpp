#include <string>
#include <vector>
#include <iostream>
#include "FindPalindrome.hpp"

using namespace std;

//------------------- HELPER FUNCTIONS -----------------------------------------

// non-class helper functions go here, should be declared as "static" so that
// their scope is limited

// helper function to convert string to lower case
static void convertToLowerCase(string & value)
{
    for (int i=0; i<value.size(); i++) {
        value[i] = tolower(value[i]);
    }
}

//------------------- PRIVATE CLASS METHODS ------------------------------------

// private recursive function. Must use this signature!
void FindPalindrome::recursiveFindPalindromes(vector<string>
           candidateStringVector, vector<string> currentStringVector)
{
    int canlen = candidateStringVector.size();
    int curlen = currentStringVector.size();

    if(!(currentStringVector.empty())) //until base case
    {
        for(int i = 0; i < curlen; i++)
        {
            vector<string> subvec1 = candidateStringVector; //temporary string vectors to operate on
            vector<string> subvec2 = currentStringVector;

            subvec1.push_back(subvec2[i]);
            subvec2.erase(subvec2.begin() + i);

            if(cutTest2(subvec1, subvec2))
            {
                recursiveFindPalindromes(subvec1, subvec2); //recursive call if it makes sense
            }
        }
    }
    else if((currentStringVector.empty()) && cutTest1(candidateStringVector)) //at base case where all words in candidate to check
    {
        string temp;//
        
        for(int i = 0; i < canlen; i++)
        {
            temp = temp + candidateStringVector[i]; //copy over candidateStringVector
        }

        if(isPalindrome(temp))
        {
            storepals.push_back(candidateStringVector); //add to list
        }
    }
}


// if(cansize%2==0)
	// 	{
	// 		for(int j=0;j<cansize/2;j++)
	// 			{	
	// 				sub1.push_back(candidateStringVector[j]);
	// 				sub2.push_back(candidateStringVector[j+cansize/2-1]);
	// 			}
	// 	}
	// else
	// 	{
	// 		for(int k=0;k<cansize/2+1;k++)//cuts off 1 odd # index
	// 			{
	// 				if(k!=cansize/2)//so that the smaller vector doesn't read in middle value
	// 				{
	// 				sub1.push_back(candidateStringVector[k]);//smaller vector 
	// 				}
	// 				sub2.push_back(candidateStringVector[k+cansize/2]);//when j=0, starts at middle index
	// 			}
	// 	}

			// if(!cutTest1(candidateStringVector)||!cutTest2(sub1,sub2))//if either tests failed, must permutate recursively
			// 	{
			// 		next_permutation(candidateStringVector.begin(),candidateStringVector.end());
			// 		recursiveFindPalindromes(candidateStringVector,currentStringVector);
			// 		prev_permutation(candidateStringVector.begin(),candidateStringVector.end());//go back
			// 	}
			// else
			// 	{
			// 		storepals.push_back(candidateStringVector);//store to private vector of palindromes
			// 		numpal++;
			// 		//swap(candidateStringVector,currentStringVector);
			// 	}
		





// private function to determine if a string is a palindrome (given, you
// may change this if you want)
bool FindPalindrome::isPalindrome(string currentString) const
{
    locale loc;
    // make sure that the string is lower case...
    convertToLowerCase(currentString);
    // see if the characters are symmetric...
    int stringLength = currentString.size();
    for (int i=0; i<stringLength/2; i++) {
        if (currentString[i] != currentString[stringLength - i - 1]) {
            return false;
        }
    }
    return true;
}

//------------------- PUBLIC CLASS METHODS -------------------------------------

FindPalindrome::FindPalindrome()
{
}

FindPalindrome::~FindPalindrome()
{
    pals.clear();
    storepals.clear();
}

int FindPalindrome::number() const
{
    return storepals.size();
}

void FindPalindrome::clear()
{
    pals.clear();
    storepals.clear();
}

bool FindPalindrome::cutTest1(const vector<string> & stringVector)
{
 //extra variables used
    vector<int> countalpha; //vector to store the amount of each letter
    int length = stringVector.size(); 
    vector<string> lowerStringVector = stringVector; //create new string vector for lower case version of stringVector
    int count = 0; //int value for total number of characters
    int Odd = 0; //int value for counting odd amounts

    //setting up vectors for checking
    for(int i = 0; i < 26; i++)
    {
        countalpha.push_back(0); //initialize with zero of each lettere
    }
    string str1;
    for(int i=0;i<stringVector.size();i++)
        {
            str1=str1+stringVector[i];
        }
    convertToLowerCase(str1);
    for(int i = 0; i <str1.length(); i++)
    {
        {
            if(!isalpha(str1[i]))//if not alphabet
            {
                return false;
            }
            countalpha[str1[i] - 97]++; //61 is the alpha ascii for char,+26 indexes, to get a:z, subtract 97 from char value
            count++;
        }
    }

    for(int i = 0; i < 26; i++)
    {
        if((countalpha[i] % 2)) //count to see if the number of instances counted from a letter is odd
        {
            Odd++;
        }
    }
    
    //determine if this vector will work
    if(((count % 2 == 1) && Odd > 1))//if odd and odd count greater than 1
        {
        return false;
        }
    if((count % 2 == 0) && Odd > 0)//if even cant have any odd counts
        {
        return false;
        }

    return true;
}

// 	string temp;
	
// 	for(int i=0;i<stringVector.size();i++)
// 		{
// 			temp=temp+stringVector[i];//copying to string
// 		}
// 	for(int i=0;i<temp.length();i++)
// 		{
// 			if(!isalpha(temp[i]))//if not all consisting of alphabet characters
// 				{
// 					return false;//returns false for not a palindrome
// 				}
// 		}
// 	convertToLowerCase(temp);//make all lowercase for comparisons
// 	if(stringVector.size()%2==0)//if even
// 		{
// 		for(int i=0;i<stringVector.size();i++)//letter pickerd
// 			{
// 				int lettercounter=0;//counter
// 			for(int j=0;j<stringVector.size()-1;j++)//comparison looper
// 				{
// 				if(temp[j]==temp[i])//if comparision looper == letter picker
// 					{
// 					lettercounter++;//count number of instances of letter
// 					if(j==stringVector.size()-1)//if all checked
// 						{
// 						if(lettercounter%2!=0)//and letter isn't even, return false as instantly known that it isn't a palindrome
// 							{
// 								lettercounter=0;
// 								return false;
// 							}
// 						}
// 					}
// 				}
// 			}
// 		}
// 	else//if not even (odd)
// 		{
// 		int middle=stringVector.size()/2;//if odd, locate the index of odd wor
// 		int midcounter;
// 		for(int i=0;i<stringVector.size();i++)//letter picker
// 			{
// 			for(int j=0;j<stringVector.size()-1;j++)//comparison looper
// 				{
// 				int lettercounter=0;//within this instance of looper
// 				int midcounter=0;
// 				if(temp[j]==temp[i])//if comparision looper == letter picker && is the character in the middle,
// 					{
// 						if(i!=middle)//if not middle character
// 						{
// 						lettercounter++;//count number of instances of letter
// 						if(j==stringVector.size()-1)//if all checked
// 							{
// 							if(lettercounter%2!=0)//and letter isn't even, return false as instantly known that it isn't a palindrome
// 								{
// 									return false;
// 								}
// 							}
// 						}
// 						else//if is middle character
// 						{
// 							midcounter++;//within for loop for checking a match, but not for checking if is the middle char
// 							if(j==stringVector.size()-1)//if all checked
// 								{
// 									if(midcounter%2==0)
// 										{
// 											return false;//returns false if it is an even number
// 										}
// 								}
// 						}
// 					}
// 				}
// 			}
// 		}
// 	return true;
//also will reimplement using alphabet number storage vector
// 	vector<int> alpha;
// 	int count,odd;
// 	for(int i=0;i<26;i++)
// 		{
// 			alpha.push_back(0);//initializing to 0 registers of each alphabet letter
// 		}
// 	string lower;
// 	for(int i=0;i<stringVector.size();i++)
// 		{
// 			lower=lower+stringVector[i];
// 		}
// 	convertToLowerCase(lower);//make lower for comparison
// 	for(int i=0;i<lower.length();i++)
// 		{
// 			if(!isalpha(lower[i]))//if char read in isn't alphabet
// 				{
// 					return false;//return false as is invalid
// 				}
// 			alpha[lower[i]-97]++;
// 			count++;
// 		}
// 		for(int i=0;i<alpha.size();i++)
// 			{
// 				if(alpha[i]%2!=0)//if even and all the letters arent even counts
// 					{
// 						odd++;
// 					}
// 			}
// 		if(count%2==0&&odd>0)//if even, but has an odd occurance of a letter
// 			{
// 				return false;
// 			}
// 		if(count%2!=0&&odd>1)//if odd length, but has more than 1 odd amount of chars
// 			{
// 				return false;
// 			}
// 	return true;//return true if all cases of invalidity bypassed;
// }

bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
    //extra variables used    vector<int> countalpha1; //vector to store the amount of each letter in vector 1
    vector<int> countalpha1;//store vector 1
    vector<int> countalpha2; //store vector 2
    int length1 = stringVector1.size(); 
    int length2 = stringVector2.size(); 
    vector<string> low1 = stringVector1; //create new string vector for lower case version of stringVector1
    vector<string> low2 = stringVector2; //create new string vector for lower case version of stringVector2
    int count1 = 0; //int to count total number of characters in vector 1
    int count2 = 0; //int to count total number of characters in vector 2

    //setting up vectors for checking
    for(int i = 0; i < 26; i++)
    {
        countalpha1.push_back(0); //initialize with zero of each lettere
        countalpha2.push_back(0); //initialize with zero of each lettere
    }

    for(int i = 0; i < length1; i++)
    {
        convertToLowerCase(low1[i]); //convert complete lower case vector1
    }

    for(int i = 0; i < length2; i++)
    {
        convertToLowerCase(low2[i]); //convert complete lower case vector2
    }


    string one;
    string two;
    for(int i=0;i<length1;i++)
        {
            one=one+low1[i];
        }
     for(int i=0;i<length2;i++)
        {
            two=two+low2[i];
        }
            
   

        for(int i = 0; i < one.length(); i++) //nested for loop to look at each character of each string
        {
            if(!isalpha(one[i]))
            {
                return false;
            }
            
            countalpha1[one[i] - 97]++; ///same methodology as above for ascii code

            count1++;
        }
    


        for(int i = 0; i < two.length(); i++) //nested for loop to look at each character of each string
        {
            if(!isalpha(two[i]))
            {
                return false;
            }
            
            countalpha2[two[i] - 97]++; //same idea as above with 61 ascii code and 26 indexes for alphabet
            count2++;
        }


    //determine if these vectors will work
    if(count1 > count2)//for the case that 1 is bigger than 2
    {
        for(int i = 0; i < 26; i++)
        {
            if(countalpha1[i] < countalpha2[i])//no letter from smaller vector can ever be greater than the bigger vector
            {
                return false;
            }
        }
    }
    if(count2 > count1)//vice versa case
    {
        for(int i = 0; i < 26; i++)
        {
            if(countalpha2[i] < countalpha1[i])//same as above
            {
                return false;
            }
        }
    }
    if(count1==count2)//if they are equa;
    {
        for(int i = 0; i < 26; i++)
        {
            if(countalpha1[i] != countalpha2[i])//they can never be not equal in instances of alphabet letters
            {
                return false;
            }
        }
    }

    return true;
}


	// TODO need to implement this...
	//two substring, all characters in <=substring must be present in all >substring
	// int size1=stringVector1.size();
	// int size2=stringVector2.size();
	// vector<string> subvec1=stringVector1;
	// vector<string> subvec2=stringVector2;
	// bool bigger1=(size1>size2);
	// string strvec1;
	// string strvec2;
	// for(int i=0;i<size1;i++)//storing in strings
	// 	{
	// 		strvec1=strvec1+stringVector1[i];
	// 	}
	// for(int i=0;i<size2;i++)//storing in strings
	// 	{
	// 		strvec2=strvec2+stringVector2[i];
	// 	}
	// convertToLowerCase(strvec1);
	// convertToLowerCase(strvec2);
    // if(bigger1==1)//if 1st vector is greater, then second vector must all have values present in vector 1
    //     {
    //         for(int i=0;i<strvec2.length();i++)//iterator for smaller or = vector2
    //             { int counter;
    //             for(int j=0;j<strvec1.length();j++)//iterator for comparing with all values of vector 1
    //                 {
    //                 if(i==size1-1&&counter==0)//if at the last interation of comparision and counter ==0
    //                     {
    //                         return false;
    //                     }
    //                 else
    //                     {
    //                         if(strvec2[i]==strvec1[j])//if vector2 char found in vector 1
    //                             {
    //                                 counter++;
    //                             }
    //                     }
    //                 }
    //             }
    //     }
    // else if (bigger1>=0)//do the same but reverse case
    // {
    //         for(int i=0;i<strvec1.size();i++)//iterator for smaller or = vector2
    //             { int counter;
    //             for(int j=0;j<strvec2.size();j++)//iterator for comparing with all values of vector 1
    //                 {
    //                 if(i==strvec2.size()-1&&counter==0)//if at the last interation of comparision and counter ==0
    //                     {
    //                         return false;
    //                     }
    //                 else
    //                     {
    //                         if(strvec2[i]==strvec1[j])//if vector2 char found in vector 1
    //                             {
    //                                 counter++;
    //                             }
    //                     }
    //                 }
    //             }
    // }
    
    // else
    //     {
    //         return true;
    //     }

    // return false;
bool FindPalindrome::add(const string & value)
{
    //extra variables used in this method    
    string lower = value;
    int inlen = value.size();
    vector<string> lowerpals = pals;
    int numpals = pals.size();

    //reduce all strings to lower case for error checking
    convertToLowerCase(lower);

//
    for(int i = 0; i < inlen; i++) 
    {
        if(!isalpha(lower[i]))//checks if alphabet letter
        {
            return false;
        }
    }
    

    for(int i = 0; i < numpals; i++)
    {
        convertToLowerCase(lowerpals[i]); //convert complete lower case words vector
    }
    //uniqueness validity check
    for(int i = 0; i < numpals; i++)
    {
        if(lowerpals[i] == lower)
        {
            return false;
        }
    }

    pals.push_back(value);

    
    vector<string> copyOfWords = pals; //copy to protect against changing pals
    vector<string> emptyCandidate;

    storepals.clear(); //to be reset with recursive function
    
    recursiveFindPalindromes(emptyCandidate, copyOfWords);
    
    return true;
}



bool FindPalindrome::add(const vector<string> & stringVector)
{
    vector<string> lowerpals = pals;
    int palcount = pals.size();
    vector<string> lowstrvec = stringVector;
    vector<string> temp = stringVector; //temp storage of lowercase for comparison without changing original case-sensitive 
    int stringLength = stringVector.size();
    int templen = stringLength; //decrementing temp length
    int repeats = 0; //counter the repeats of certain letters

    //temp storage for comparision of lower-case letters
    for(int i = 0; i < palcount; i++)
    {
        convertToLowerCase(lowerpals[i]); //make lowercase
    }

    for(int i = 0; i < stringLength; i++)
    {
        convertToLowerCase(lowstrvec[i]); //make lowercase
    }

    for(int i = 0; i < stringLength; i++)
    {
        string strtemp = lowstrvec[i]; //strings at index i of the vector
        int strlen = strtemp.length();

        for(int x = 0; x < strlen; x++) //looping through all the chars in the string
        {
            if(!isalpha(strtemp[i]))//if not alphabet letter
            {
                return false;
            }
        }
    }
    
    //checking for uniqueness
    for(int i = 0; i < palcount; i++)
    {
        for(int x = 0; x < stringLength; x++) //nested for loop to check each string of each vector
        {
            if(lowerpals[i] == lowstrvec[x])
            {//returns false if match
                return false;
            }
        }
    }


    // //error checking
    // if(shortStringVector.empty()) //this means none of the strings were unique
    // {
    //  return false;
    // }

    //add values to pals
    for(int i = 0; i < templen; i++)
    {
        pals.push_back(temp[i]);
    }
    
    vector<string> newcur = pals; //pals holds case sensitive, we want to keep it safe
    vector<string> newcan;//empty for new candidate

    storepals.clear(); //reset to recalculate with new addition
    
    recursiveFindPalindromes(newcan, newcur);

    return true;
}

vector< vector<string> > FindPalindrome::toVector() const
{
    return storepals;
}


