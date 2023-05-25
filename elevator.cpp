#include<iostream>
#include<cstdlib>
#include<cstdbool>
#include <cmath>
#include "elevator.h"

using namespace std;

bool checkValidFloor(int enter_floor,int min_floor, int max_floor)
{
   if(enter_floor<min_floor || enter_floor>max_floor)
   {
      cout << "This floor does not exist\n";
      cout << "Please enter again\n";
      return 1;
   }
   else
      return 0;
}

int main()
{
   //給定最低樓層及最高樓層
   int min_floor_num,max_floor_num;
   int elevator1_floor_now=0;
   int elevator2_floor_now=0;
   int user_current_floor,user_desired_floor;
   cout<<"Enter minimum floor number, maximum floor number in the building.\n";
   cout<<"minimum floor number:";
   cin>>min_floor_num;
   cout<<"maximum floor number:";
   cin>>max_floor_num;
   
   Elevator elevator1;
   Elevator elevator2;
   
   while(max_floor_num!=0 || min_floor_num!=0)
   {
      srand(time(NULL));
      elevator1_floor_now=rand()%(max_floor_num-min_floor_num+1)+min_floor_num;
      elevator2_floor_now=rand()%(max_floor_num-min_floor_num+1)+min_floor_num;
      
      cout<<"elevator1: ";
      elevator1.display_floor(elevator1_floor_now);
      cout<<" floor";
      cout<<"   elevator2: ";
      elevator2.display_floor(elevator2_floor_now);
      cout<<" floor\n";
      
      //check input is valid
      do
      {
         cout<<"Please input your current floor:";
         cin>>user_current_floor;
      }while(checkValidFloor(user_current_floor,min_floor_num,max_floor_num));
      
      do     
      {
         cout<<"Please input your desired floor:";
         cin>>user_desired_floor;
      }while(checkValidFloor(user_desired_floor,min_floor_num,max_floor_num));
      
      if(abs(elevator1_floor_now-user_current_floor)
      >=abs(elevator2_floor_now-user_current_floor))
      {
         cout<<"elevator2:"<<endl;
         //判斷電梯所在樓層與使用者是否在同一層
         if(abs(elevator2_floor_now-user_current_floor)!=0)
         {
            elevator2_floor_now=elevator2.move(elevator2_floor_now,user_current_floor);
            cout<<"The user has entered the elevator."<<endl; 
            elevator2_floor_now=elevator2.move(elevator2_floor_now,user_desired_floor);
         }
         else
         {
            cout<<"The user has entered the elevator."<<endl;
            elevator2_floor_now=elevator2.move(elevator2_floor_now,user_desired_floor);
         }
      }
      else
      {
         cout<<"elevator1:"<<endl;
         //判斷電梯所在樓層與使用者是否在同一層
         if(abs(elevator1_floor_now-user_current_floor)!=0)
         {
            elevator1_floor_now=elevator1.move(elevator1_floor_now,user_current_floor);
            cout<<"The user has entered the elevator."<<endl; 
            elevator1_floor_now=elevator1.move(elevator1_floor_now,user_desired_floor);
         }
         else
         {
            cout<<"The user has entered the elevator."<<endl;
            elevator1_floor_now=elevator1.move(elevator1_floor_now,user_desired_floor);
         }
      }
      cout<<"\n\n";
   }


}
