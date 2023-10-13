#include <string>
using std::string;

#include <iostream>

#include <cctype> // for isalpha
#include <cstring>
#include "algebraic_expressions.hpp"
#include <vector>

bool isoperator(char ch) {
  return ((ch == '+') || (ch == '-') || (ch == '/') || (ch == '*'));
}

int endPost(string s, int last) {//gives index of last valid postfix expression
  int first = 0;

  if ((first > last)) {
    return -1;
  }

  char ch = s[last];
  if (isalpha(ch)) {
    return last;
  } else {
    if (isoperator(ch)) {
      int lastEnd = endPost(s, last - 1);
      if (lastEnd > -1) {
        return endPost(s, lastEnd - 1);
      } else {
        return -1;
      }
    } else {
      return -1;
    }
  }
}

bool isPost(string s) {
  int firstChar = endPost(s, s.size() - 1);

  return (firstChar == 0);
}

void convert(string &postfix, string &prefix) {
  //     //⭐//trying to remake whole function properly, 👍👍👍simplified it alot!!
      int postlength=postfix.length();//store postfix length
      char last=postfix[postlength-1];//start from back of postfix array
      char oper=0;//to store operator later
      //prefix string already given
          if(isalpha(last))//back is alpha
            {      
              prefix=last+prefix;//add to front, so that if in form of ab in postfix, b is put into prefix, then a+prefix results in ab
              if(postlength!=0)//so that it doesn't pop_back when postlength is already 0 somehow
              postfix.pop_back();//removes the char that was added into prefix

            }
          else//if it wasn't an alphabet letter, then keep track of it
            {
              oper=last;//stores the char in operator
              if(postlength!=0)//segmentation protection
              postfix.pop_back();//removes from postfix
              //convert(postfix,prefix);//recursively calls if it wasn't alphabet  if(oper!=0)
            }
          if(oper!=0)//if operator saved, recursively runs again, if empty and last is an operator, then it stores it to the front of the prefix.
            {//**runs till oper is not 
              convert(postfix,prefix);//takes in prefix that has current operator removed, it reset op to 0, then if it is an op again, recurse until not.
              if(postlength==0)
              prefix=oper+prefix;//only stores operator if postfix is empty
            }//everytime there is an operator, prefix gets reduced and put into this if
          //^^won't exit top statement until recursion is done, which is when it doesn't read an operator next,
          //when the last convert recursion ends at postlength==0, then all other instances exit this first if statement,
          if(oper!=0)//if there is still an operator at the end, then run through again and the first if statement should take care of stray operator at the end.
           {
              convert(postfix,prefix);
              if(oper!=0)
              prefix=oper+prefix;
           }
          
}
//OLD CODE
//converting postfix to prefix
  //notes: postfix should have the - at the front instead of end
  // //<postfix1><prefix2><operator> to <operator><prefix1><prefix2>
  //     int postlength=postfix.length();//length of postfix
  //     char op=postfix[0];
  //     //prefix string already set as an input.
  //     if(isoperator(op)&&op!='('&&op!=')')//checking if is not a char
  //       {
  //         //prefix.push_back('(');//is it is a lowerchase #, adds operator infront
  //         prefix.push_back(op);//is it is a lowerchase #, adds operator infront
  //         //prefix.push_back(')');//is it is a lowerchase #, adds operator infront
  //         //postfix.pop_back();//remove it from postfix
  //         if(postlength!=0)
  //         postfix.erase(postfix.begin());
  //          else
  //          {
  //           // prefix.push_back(prefix[prefix.length()-1]);
  //            prefix=prefix[prefix.length()-1]+prefix;
  //            prefix.pop_back();
  //          }
  //       }
  //     else //if is not in correct form yet...recursively change
  //       {
  //         //find end of postfix1
  //         //int lastEnd=endPost(postfix,postlength-1);
  //         //convert <postfix1> into prefix form
  //         if(postlength!=0)
  //         //prefix=prefix+"("+op+")";
  //         prefix=prefix+op;
  //        // postfix.pop_back();
  //         if(postlength!=0)
  //         postfix.erase(postfix.begin());
  //         else if(prefix[prefix.length()-1]!='('&&prefix[prefix.length()-1]!=')')
  //           {
  //            //prefix.push_back(prefix[prefix.length()-1]);
  //            prefix=prefix[prefix.length()-1]+prefix;
  //            prefix.pop_back();
  //           }
  //         else
  //         {
  //            prefix=prefix[prefix.length()-2]+prefix;
  //            prefix.pop_back();
  //         }

  //       }
  //     if(!isoperator(prefix[0]))
  //     {
  //     index++;
  //     convert(postfix,prefix);
  //     }
  //     else
  //     //prefix="("+prefix;
  //     EXIT_SUCCESS;
