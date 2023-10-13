#include <cstdlib>
#include <iostream>
#include "lib/image.h"
#include "list.hpp"
#include "queue.hpp"

int main(int argc, char *argv[])
{
  // get input/output file names from command line arguments
  if (argc != 3) {
    std::cout << "Usage: pathfinder "
              << "<first_input_filename> <second_output_filename>\n"
              << std::endl;
    return EXIT_FAILURE;
  }

  std::string input_file = argv[1];
  std::string output_file = argv[2];

  // Read input image from file
  Image<Pixel> image;
  try{//file not read exception catching
    image=readFromFile(input_file);
  } 
  catch (std::exception &ex) {
    std::cerr << "Error" << std::endl;
    return EXIT_FAILURE;
  }

  // TODO
  int w=image.width();//integer to keep track of the horizontal block count
  int h=image.height();//integer to keep track of the vertical block count
  int red=0;//integer to keep track of how many starting red blocks: if more than one, should print "Error" and return "EXIT_FAILURE"
  bool green=false;//initial condition false
  bool visited[w][h];//"visited" array the same size as our map, to test if a block has been visited already
  //bool green must be true if solution exists, exit block should be marked green
  //Need nested loop initially to search for red pixels and their x,y coordinates
  int x,y;//starting cell coordinates
  //nextrow=(row+1,column) & next column=(row,column+1)

  for(int col=0;col<w;col++)//where i is the column
    {
      for(int row=0;row<h;row++)//j is the row
        { //if a coordinate has an invalid color: ie it isnt red,white, or black, then must exit with error
          if(image(row,col)!=RED && image(row,col)!=WHITE && image(row,col)!=BLACK && image(row,col)!=GREEN)//kinda make i,j flipped, but should work fine
            {
              //print error using "std::cerr"
              std::cerr<<"Unexpcted Color Error"<<std::endl;
              return EXIT_FAILURE;
            }
          else if(image(row,col)==RED)//if red found
            {
              //save coordinates
              x=row;
              y=col;
              //increment red counter
              red++;
            }
        }
      if(red>1)//at anypoint in the looping if theres more than 1 red pixel found, exit
        {//did within looping instead of after the looping to make it faster instead of finishing looping for no reason
          std::cerr<<"More than one red pixel"<<std::endl;
          return EXIT_FAILURE;
        }
    }
  // if(red==0)
  //   {
  //     std::cerr<<"No Starting Point"<<std::endl;
  //     return EXIT_FAILURE;
  //   }
  
  //*
  //Queue<Pixel,Pixel> cue;//cue of type "Pixel" to queue pixels
  //add red coordinates to queue;
  //cue.enqueue();//enqueue requires a type "item" to queue, how should i do this with two integer coordinates?
  //cue.enqueue(image(x,y));//enqueueing a "Pixel" item, put in queue as first item and so I know the first item is the starting point
  //^ I may need to do this as a queue of x and y coordinates instead, as I don't completely understand the image and pixel class and struct
  Queue<int,int> xue,yue;//a queue for x and y coordinates respectively
  xue.enqueue(x);//adding x coordinate to queue
  yue.enqueue(y);//adding y coordinate to queue
  //visited[x][y]==true;//set starting block as "visited"
  //nearest exit is white cell on maze border closest to red block.
  //write breadth_First_Search algorithm
  //directional arrays for row and column
  int dr[4]={-1,1,0,0};
  int dc[4]={0,0,1,-1};
  int dx=0;
  int dy=0;//just incase, so that the x and y coordinates of red block aren't changed
  int exp_x,exp_y;//extra variables to store neighbor coordinates
  green=false;
  while(!xue.isEmpty())//keep running until solution found
    {
      // if(runcounter>=w*h)//implementing to prevent segfault. 
      //   {
      //     std::cerr<<"No solution found, still print"<<std::endl;
      //     break;
      //   }
      dx=xue.peekFront();//access
      xue.dequeue();//remove
      dy=yue.peekFront();//access
      yue.dequeue();//remove
      visited[dx][dy]=true;
      if(dx==0 || dy==0 || dx==h-1 || dy==w-1)//if the block in the queue is at the perimeter, then it is the solution and I set the block to green and my boolean "green" to true
        {
          //image(dx,dy)==GREEN;
          green=true;
          break;
          //return EXIT_SUCCESS;//return success statement as exit has been found
        }
      //if tested pixel isn't the solution, go into adding neighbors into queue.
      //no clue why my implementation with coordinate array doesn't work
      // for(int i=0;i<4;i++) 
      //   {
      //     exp_x=dx+dr[i];//offset x coord
      //     exp_y=dy+dc[i];//offset y coord
      //     if(image(exp_x,exp_y)==WHITE && visited[exp_x][exp_y]==false)//only check the white blocks, and if they haven't been visited
      //       {
      //         if(exp_x==0 || exp_x==w-1 || exp_y==0 || exp_y==h-1)//conditional escape condition, if next white block is on the perimeter, meaning solution found.
      //           {
      //             green==true;//green boolean set to true
      //             image(exp_x,exp_y)=GREEN;
      //             return EXIT_SUCCESS;
      //           }
      //         else if(dx>0&&dy>0)//if white block isn't a solution, add to queue and loop
      //           {
      //             xue.enqueue(exp_x);
      //             yue.enqueue(exp_y);
      //             visited[exp_x][exp_y]==true;//set visited block to true
      //           }
      //       }
        if(image(dx,dy) == WHITE && (dx == 0 || dx == h || dy == 0 || dy == h)) 
          {

            green = true;
            //image(dx,dy) = GREEN;
            //writeToFile(image, output_file);
            break;
          }
          //case table for checking left, right, up, down respectively
        if (image(dx+1,dy) == WHITE && !visited[dx+1][dy]) 
          {
            xue.enqueue(dx+1);
            yue.enqueue(dy);
            visited[dx+1][dy] = true;
          }
        if (image(dx,dy-1) == WHITE && !visited[dx][dy-1]) 
          {
            xue.enqueue(dx);
            yue.enqueue(dy-1);
            visited[dx][dy-1] = true;
          }
        if (image(dx-1,dy) == WHITE && !visited[dx-1][dy]) 
          {
            xue.enqueue(dx-1);
            yue.enqueue(dy);
            visited[dx-1][dy] = true;
          }
       
        if (image(dx,dy+1) == WHITE && !visited[dx][dy+1]) 
          {
            xue.enqueue(dx);
            yue.enqueue(dy+1);
            visited[dx][dy+1] = true;
          }
      //queue should be updated with all the "next" paths to test for and loop through again
    }
  //^adding to my queue what paths around the red pixel are available to traverse
  // Write solution image to file
  //image(dx,dy)=GREEN;//just learned that it goes row#, column# (y,x)...shouldnt matter though??
  if(green==true)
    {
      image(dx,dy)=GREEN;
      writeToFile(image, output_file);
      std::cout<<"Solution Exists"<<std::endl;
      return EXIT_SUCCESS;
    }
  else
    {
      writeToFile(image, output_file);
      std::cout<<"No Solution"<<std::endl;
      return EXIT_SUCCESS;
    }
  return EXIT_SUCCESS;
}
