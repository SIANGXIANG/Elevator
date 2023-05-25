# 電梯模擬
## elevator.cpp說明
先定義最高樓層及最低樓層
```
cout<<"Enter minimum floor number, maximum floor number in the building.\n";
cout<<"minimum floor number:";
cin>>min_floor_num;
cout<<"maximum floor number:";
cin>>max_floor_num;
```
定義兩台電梯，elevator1與elevator2
```
Elevator elevator1;
Elevator elevator2;
```
3.如果最高樓層與最低樓層其中一個不為0的話，則進入迴圈
```
while(max_floor_num!=0 || min_floor_num!=0)
```
是用亂數產生電梯初始的樓層，並將樓層印出
```
srand(time(NULL));
elevator1_floor_now=rand()%(max_floor_num-min_floor_num+1)+min_floor_num;
elevator2_floor_now=rand()%(max_floor_num-min_floor_num+1)+min_floor_num;
      
cout<<"elevator1: ";
elevator1.display_floor(elevator1_floor_now);
cout<<" floor";
cout<<"   elevator2: ";
elevator2.display_floor(elevator2_floor_now);
cout<<" floor\n";
```
輸入使用者當下樓層及想到達的樓層，並同時判斷是否超出樓層範圍
```
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
```
checkValidFloor()函式判斷是否為有效樓層
```
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
```
判斷哪台電梯最靠近使用者的樓層，如果相同則使用elevator2
```
if(abs(elevator1_floor_now-user_current_floor)>=abs(elevator2_floor_now-user_current_floor))
{
   ,,,
}
else
{
   ,,,
}
```
判斷電梯所在樓層與使用者是否在同一層，如果位於不同層，電梯則需先到達使用者所在樓層
```
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
```
## elevator.h說明
一開始先定義類別Elevator，以及定義move()及display_floor()的函數原型
```
class Elevator
{
   public:
   Elevator(){};
   ~Elevator(){};
   int move(const int, const int);
   void display_floor(const int); //show current floor

};
```
move(int current, int target)表示電梯從current移動到target，並且設定每1秒移動一層樓
```
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
```
最後display_floor()為印出樓層，目的是為了模擬電梯顯示當下所在樓層
```
void Elevator::display_floor(const int elevator_floor)
{
   cout<<elevator_floor;
}
```
以上就是程式的說明
