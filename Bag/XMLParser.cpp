// Project 3 -- XML Parsing Project

/** XML parsing class implementation.
    @file XMLParser.cpp */

#include <string>
#include <assert.h>
#include "XMLParser.hpp"

// TODO: Implement the constructor here
XMLParser::XMLParser()
{//nothing to write?
}  // end default constructor

// TODO: Implement the destructor here
XMLParser::~XMLParser()
{
}  // end destructor

// TODO: Implement the tokenizeInputString method
bool XMLParser::tokenizeInputString(const std::string &inputString)
{//scanner: true if successful, false otherwise, then stores tokens in class
	//try to implement recursively
	//think this is just all for validity checking?
	std::string content;//to store contents
	_TokenStruct_ StoreTok;
	StoreTok.tokenType=START_TAG;//initialized to start_tag, will be changed later accordingly in if statements

	char invname[29]={'!',34,'$','%','&',39,'(',')','*','+',',','/',';','<','=','>','?','@',91,92,93,'^','`','{','}','|','~'};//just creating an array ot loop through for checking
	//^^ mistake ig, this is still for tags which I thought maybe it was for "contents" instead bc it was the 
	//singular inctance on the instructions that say just "names" instead of "tag names", and also why are the 
	//"-"",""." separated why state seperately!!!?!?
	if(inputString.length()!=0&&hack==false)
		{
			int startang=inputString.find_first_of('<');//finds first '<' char
			int endang=inputString.find_first_of('>');
			int space;
			if(inputString.find_first_of(' ')!=-1)
				{
					space=inputString.find_first_of(' ');//finds first whitespace
				}
			else
				{
					space=endang+1;
				}
			int end;
			int start;
			// if(inputString[0]=='<')
			// 	{
					
			// 	}
			// if(inputString[0]=='>')
			// 	{

			// 	}
			if(inputString[0]=='\n')
				{
					tokenizeInputString(inputString.substr(1,inputString.length()));//error checking so the next-line character doesn't get read
					tokened=true;
					return true;
				}
			if(inputString[0]!='<')//if doesn't start with tag
				{
					content=inputString.substr(0,startang);//if not angle start, then read until angle
					// for(int i=0;i<content.length();i++)//if contents include the invalid special characters
					// 	{
					// 		if(content[i]>=44||content[i]<58)	
					// 			{
					// 				return false;//invalid content characters, must exit
					// 			}turns out this is actualyl for tag name too!!!
					// 		content can include all characters,
					// 	}
					//type of token and also content
					int spacecounter=0;
					bool error;
					for(int i=0;i<content.length();i++)
						{
							if(content[i]==' ')
								{
									spacecounter++;
								}
						}
					if(spacecounter!=content.length())//if contents aren't all whitespaces
						{
							StoreTok.tokenType=CONTENT;
							StoreTok.tokenString=content;
							tokenizedInputVector.push_back(StoreTok);
							std::string into=inputString.substr(startang,inputString.length());
								if(into.length()!=0)
									{
										tokenizeInputString(into);//recurisive call if not empty 
									}
							tokened=true;
							return true;
						}
					else
						{
							tokenizeInputString(inputString.substr(startang,inputString.length()));
						}
				}
			else//if is an angle start, then token will be 
				{//////
					if(endang>space)
						{
							start=startang+1;//exclude '<'
							end=space-1;//end of start tag name will be whatever comes first, ' ' in this case
						}
					else
						{
							start=startang+1;//exclude '<'
							end=endang-1;//exclude '>'
						}
				///////
					if(inputString[startang+1]=='/')//check for end tag
						{
							StoreTok.tokenType=END_TAG;
							start=startang+2;
							end--;//decrement to not read
						}
					else if(inputString[endang-1]=='/')//check for empty tag
						{
							StoreTok.tokenType=EMPTY_TAG;
							if(endang<space)//will only change end if ending angle comes before space
								{
									end=endang-2;//so that the '/' is skipped
								}
						}
					else if(inputString[startang+1]=='?'&&inputString[endang-1]=='?')
						{
							StoreTok.tokenType=DECLARATION;
							string dec=inputString.substr(startang+2,endang-3);
							StoreTok.tokenString=dec;
							tokenizedInputVector.push_back(StoreTok);
							std::string into=inputString.substr(endang+1,inputString.length()-1-(endang+1));
							if(into.length()!=0)
								{
									tokenizeInputString(into);//recurisive call if not empty 
								}
							tokened=true;
							return true;
						}
					
					
				////////	
					std::string tag=inputString.substr(start,end);//create substring for analysis
					//std::string tagoff=inputString.substr(endang,inputString.length()-1);//remove tag then read
					//int closeang=inputString.find_first_of('<');//this will signify start of closing angle
					//std::string data=tagoff.substr(0,closeang);//string between 
					//not going to extract attributes
					
					for(int i=0;i<tag.length();i++)//error checks the tag contents
						{	//if starts with ascii between [45,57] nametag invalid
							if((tag[i]>=45&&tag[i]<=57)||tag[i]=='-'||tag[i]==','||tag[i]=='.')	
								{
									return false;//invalid tag
								}
							for(int j=0;j<29;j++)//nested loop to check through my array of characters
								{
									if(tag[i]==invname[j])
										{
											return false;
										}
								}
						}
					StoreTok.tokenString=tag;
					tokenizedInputVector.push_back(StoreTok);
					std::string into=inputString.substr(endang+1,inputString.length()-1);
					if(into.length()!=0)
						{
							if((inputString.find_first_of('>'))==(inputString.find_last_of('>')))//index
								{
									std::string tog;
									//tokenizeInputString("");
									startang=inputString.find_last_of('<');
									endang=inputString.find_last_of('>');
									if(inputString[startang+1]=='/')
										{
											StoreTok.tokenType=END_TAG;
											tog=inputString.substr(startang+2,endang);
											StoreTok.tokenString=tog;
										}
									tokenizedInputVector.push_back(StoreTok);
									tokened==true;
									return true;
								} 
							else
								{
									tokenizeInputString(into);//recurisive call if not empty
									tokened==true;
									return true;
								}
							
							
						}
					tokened=true;
					return true;
				}
		
		}
	tokened=true;
	return true;
}  // end
	//OLD CODE**
					// StoreTok.tokenString=tag;
					// if(inputString.length()==endang+1)
					// 	{
					// 		tokenizedInputVector.push_back(StoreTok);
					// 		return true;
					// 	}
					// else
					// 	{
					// 		std::string into=inputString.substr(endang+1,inputString.length()-1);
					// 		if(into.length()!=0)
					// 			{
					// 				tokenizeInputString(into);
					// 				return true;
					// 			}

					// 	}
					// into=inputString.substr(endang+1,inputString.length()-1);
					// // if((inputString.length()-1-endang+1)!=0)
					// // 	{
					// // 	}
					// 	if(into.length()!=0)
					// 		{
					// 			tokenizeInputString(into);//recurisive call if not empty 
					// 			return true;
					// 		}
					//return true;
					
					


					//string temp=inputString.substr(first,close-first);//create substrng
					//.tokenType=temp;
					//tokenizedInputVector.push_back(temp)

					// if(hack==true)
					// 	{
					// 		StoreTok.tokenType=END_TAG;
					// 		for(int i=0;i<tag.length();i++)
					// 			{
					// 				if(!isalpha(tag[i]))
					// 					{
					// 						tag.erase(i,1);//erase front
					// 					}
					// 			}
					// 		StoreTok.tokenString=tag;
					// 		tokenizedInputVector.push_back(StoreTok);
					// 		into.erase(0,1);
					// 		StoreTok.tokenType=END_TAG;
					// 		return true;
					// 		// int dog=tag.find_first_of('/');
					// 		// std::string temp=tag.substr(dog,tag.length()-1);
					// 		// StoreTok.tokenType=END_TAG;
					// 		// StoreTok.tokenString=temp;
					// 		// tokenizedInputVector.push_back(StoreTok);
					// 		// return true;
					// 	}
					//  if(tokenizedInputVector.size()>0&&(inputString.find_first_of('>'))==(inputString.find_last_of('>')))
					// 	{	
					// 		//into=inputString.substr(endang+1,inputString.length()-1);
					// 		hack=true;
					// 		// for(int i=0;i<into.length();i++)
					// 		// 	{
					// 		// 		if(!isalpha(into[i]))
					// 		// 			{
					// 		// 				into.erase(i,1);//erase front
					// 		// 			}
					// 		// 	}
					// 		// into.erase(0,1);
					// 		// StoreTok.tokenType=END_TAG;
					// 		StoreTok.tokenString=into;
					// 		tokenizedInputVector.push_back(StoreTok);
					//  		return true;
					//  	}
					

// TODO: Implement the parseTokenizedInput method here
bool XMLParser::parseTokenizedInput()
{
	int checkeven=0;
	//int matches;
	//int count;
	Stack<string> half;
	//vector<int> tagind;//vector to store indexes of the tags
	//vector<TokenStruct> temp;//temp vector to store tokens
	//vector<int> pairs;
	vector<TokenStruct> copyvec=tokenizedInputVector;
	//broad case, all start and end tags together must be an even number
	for(int i=0;i<tokenizedInputVector.size();i++)//check whole vector
		{
			if(tokenizedInputVector[i].tokenType==START_TAG||tokenizedInputVector[i].tokenType==END_TAG)
				{
					checkeven++;//start tags all must have a matching end tag, therefore an even number
					//tagind.push_back(i);
				}
		}		
	
	if(checkeven%2!=0)//if remainder after dividing by 2
		{
			return false;//string is invalid
		}
	else//go to deeper checking if even
		{//using stack here probably
			for(int i=0;i<copyvec.size();i++)
				{
					if(copyvec[i].tokenType!=START_TAG||copyvec[i].tokenType!=END_TAG)
						{
							copyvec.erase(copyvec.begin()+i);//erase if item at index isn't a start or end tag
						}
				}
			// //once vector of only tags are created, use stack to push 1/2, then check other half
			// for(int i=0;i<copyvec.size();i++)//
			// 	{
			// 		if(copyvec[i].tokenType==START_TAG)
			// 			{
			// 				half.push(copyvec[i].tokenString);//push the string of START_TAG's to stack
			// 			}
			// 	}
			for(int i=0;i<copyvec.size();i++)
				{
					if(copyvec[i].tokenType==START_TAG)
						{
							half.push(copyvec[i].tokenString);//pop if read
						}
					else if(copyvec[i].tokenType==END_TAG&&half.isEmpty()!=true)
						{
							if(copyvec[i].tokenString==half.peek())
								{
									half.pop();//
								}
						}
					else if(i==copyvec.size()&&half.isEmpty()!=true)
						{
							return false;//if a END_TAG is read as the very first token or one is read before a start tag of the same name, invalid
						}
				}
		}
	
	parsed=true;
	return true;
}
			
			
			// matches=checkeven/2;//how many matches there should be
			// for(int i=0;i<tokenizedInputVector.size()-1;i++)
			// 	{
			// 		for(int j=0;j<tagind.size();j++)
			// 			{
			// 				if(j=i)
			// 					{
			// 						i++;//skip over if same as index im checking
			// 					}
			// 				else if(tokenizedInputVector[tagind[j]].tokenString==tokenizedInputVector[i].tokenString)
			// 					{
			// 						pairs.push_back(tagind[j]);//create pair vector with indices of tokenizedInputVector
			// 						pairs.push_back(i);//
			// 						tagind.erase(j,1);//erase both instances from index array
			// 						int second=find(tagind.begin(),tagind.end());
			// 						tagind.erase(second);//second instance
			// 						count++;//pair found
			// 					}
			// 			}
			// 		//once pair vector created, can go into checking the order of the pairs - i.e. if end_tag comes before start_tag, then invalid
			// 	}
			// //once all pairs found, can first analyze if start tag comes first or not
			// for(int i=0;i<pairs.size();i=i+2)
			// 	{
			// 		if((pairs[i]<pairs[i+1])&&(tokenizedInputVector[pairs[i]].tokenType!=START_TAG))
			// 			{
			// 				return false;//returns false if the smaller index of the pair isn't start_tag
			// 			}
			// 		if(pairs[i]>pairs[i+1]&&(tokenizedInputVector[pairs[i]].tokenType!=END_TAG))
			// 			{
			// 				return false;
			// 			}
			// 	}
			// //if respective tag-type ordering isn't proper, false should have been hit at this point
			// //now test nesting order now that it is known the pairs are in the correct start:end order
			// for(int i=0;i<pairs.size();i=i+2)
			// 	{

			// 	}


// TODO: Implement the clear method here
void XMLParser::clear()
{
	tokenizedInputVector.clear();
}

vector<TokenStruct> XMLParser::returnTokenizedInput() const
{
	return tokenizedInputVector;
}

// TODO: Implement the containsElementName method
bool XMLParser::containsElementName(const std::string &inputString) const
{
	if(tokened!=true||parsed!=true)
		{
			throw std::logic_error("oopsie");
		}
	for(int i=0;i<tokenizedInputVector.size();i++)
		{
			if(tokenizedInputVector[i].tokenString==inputString&&tokenizedInputVector[i].tokenType==START_TAG)//if tokenString is equal to input
				{
					return true;
				}
		}
	return false;//return false otherwise
}

// TODO: Implement the frequencyElementName method
int XMLParser::frequencyElementName(const std::string &inputString) const
{
	if(tokened!=true||parsed!=true)
		{
			throw std::logic_error("oopsie");
		}
	int count=0;
	string temp=inputString;
	for(int i=0;i<tokenizedInputVector.size();i++)
		{
			if(tokenizedInputVector[i].tokenString==inputString&&tokenizedInputVector[i].tokenType==START_TAG)//if tokenString is equal to input
				{
					count++;
				}
		}
	//count=count/2;
	return count;
}

