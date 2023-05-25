#include<iostream>
#include<cstdlib>
#include<cstdbool>
#include <cmath>
#include <thread>// std::this_thread::sleep_for
#include <chrono>// std::chrono::seconds

using namespace std;

#ifndef ELEVATOR_H
#define ELEVATOR_H

class Elevator
{
   public:
   Elevator(){};
   ~Elevator(){};
   int move(const int, const int);
   void display_floor(const int); //show current floor

};


void Elevator::display_floor(const int elevator_floor)
{
   cout<<elevator_floor;
}

int Elevator::move(int current, int target)
{
   int i;
   
   if(current==target)
   {
      display_floor(current);
      cout<<"\n";
      return current;
   }
   if(current>target)
   {
      for(i=current;i>=target;i--)
      {
         display_floor(i);
         cout<<"\n";
         this_thread::sleep_for(chrono::seconds(1)); // sleep 1秒(seconds)             
      }
      return i+1;
   }
   else
   {
      for(i=current;i<=target;i++)
      {
         display_floor(i);
         cout<<"\n";
         this_thread::sleep_for(chrono::seconds(1)); // sleep 1秒(seconds)               
      }
      return i-1;
   }
}

#endif
