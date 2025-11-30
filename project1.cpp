#include <iostream> 
#include <iomanip> 
#include <ctime> 
#include <string> 
#include <conio.h> 
using namespace std; 
time_t now = time(0); 
# pragma warning(suppress : 4996) 
tm* ltm = localtime(&now); 
int cday = ltm->tm_mday; 
int cmonth = 1+ ltm->tm_mon; 
int cyear = 1900 + ltm->tm_year; 
class calender 
{ 
public: 
int day; 
int month; 
int year; 
int weekday; 
calender() 
{ 
    day = month = year = weekday = 0; 
} 
bool checkLeapYear(int year) 
{ 
  if (year % 400 == 0) 
   return true; 
  else if (year % 100 == 0) 
   return false; 
  else if (year % 4 == 0) 
   return true; 
  else 
   return false; 
 } 
 
 void showMonth(int month, int year) 
 { 
  if (month <= 12 || year >= 1900) 
  { 
   int days = 1; 
   this->line(); 
   cout <<"|" <<setw(18) << this->monthname(month) << "    " << year  
 << "    | \n"; 
   this->line(); 
   cout << "|   M   T   W   T   F   S   S   |\n" ; 
   this->line(); 
   cout << " "; 
 
   for (int i = 1; days <= this->calculatingmonth(month, year); i++) 
   { 
    if (i < this->calculatingday(month, year, this->calculatingWeekDay(year)) + 1) 
    { 
     cout << setw(4) << " "; 
    } 
    else 
    { 
     cout << setw(4) << days; 
     if (days == cday && year == cyear && month == 
cmonth) 
      cout << "*"; 
     days++; 
    } 
    if (i % 7 == 0) 
     cout << " " << endl << " "; 
   } 
   cout << endl << "\b"; 
   this->line(); 
  } 
  else 
   cout << "Invalid Month or Year.\n"; 
 } 
 
void line() 
{ 
    cout << "--------------------------------\n"; 
} 
int calculatingday(int month,int year, int weekday) 
{ 
    int temp = weekday; 
    for (int i = 1; i < month; i++) 
    { 
        temp += this->calculatingmonth(i, year); 
    } 
    return temp % 7; 
} 
int calculatingmonth(int month,int year) 
{ 
if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || 
month == 10 || month == 12) 
return 31; 
else if (month == 4 || month == 6 || month == 9 || month == 11) 
   return 30; 
  else if (month == 2) 
  { 
   if (checkLeapYear(year)) 
    return 29; 
   else 
    return 28; 
  } 
  return month; 
 } 
 
 int calculatingWeekDay(int year) 
 { 
  int diff = 0,defaultday = 1900; 
  weekday = 0; 
  diff = year - 1900; 
 
  for (int i = 0; i < diff; i++) 
  { 
   if (checkLeapYear(defaultday)) 
    weekday += 366; 
   else if (!checkLeapYear(defaultday)) 
    weekday += 365; 
 
   defaultday++; 
  } 
 
  return weekday % 7; 
 } 
 
 
 string monthname(int month) 
 { 
  if (month == 1) 
   return "January"; 
  else if (month == 2) 
   return "Feburary"; 
  else if (month == 3) 
   return "March"; 
  else if (month == 4) 
   return "April"; 
  else if (month == 5) 
   return "May"; 
  else if (month == 6) 
   return "June"; 
  else if (month == 7) 
   return "July"; 
  else if (month == 8) 
   return "August"; 
  else if (month == 9) 
   return "September"; 
  else if (month == 10) 
   return "October"; 
  else if (month == 11) 
   return "November"; 
  else if (month == 12) 
   return "December";  
 } 
 
 void printLeapYears(int from,int to) 
 { 
   
  for (int i = from; i <= to; i++) 
  { 
   if (checkLeapYear(i)) 
    cout << i << " "; 
   if (i % 20 == 0) 
    cout << endl; 
  } 
 } 
 
}; 
class Event 
{ 
public: 
string title; 
string description; 
int day, month, year; 
string location; 
Event* left, * right,*parent; 
Event() : title(""), description(""), location(""), day(0), month(0), year(0),left(NULL), 
right(NULL), parent(NULL) {}; 
friend Event* newEvent(string title, string description, int day, int month, int year, 
string location); 
friend Event* binarySearchTree(Event* root, Event* newNode); 
friend void inorderTraversal(Event* root); 
friend void pushingElemetsInQueue(Event* root); 
friend void showSchedule(Event* root); 
friend void showDetails(Event* det); 
friend Event* deleteEvent(Event* root, int day, int month, int year); 
friend Event* minValueNode(Event* root); 
friend void UpdateAnEvent(Event* root); 
friend void EditDetails(Event* root); 
}; 
Event* newEvent(string title,string description,int day,int month,int year,string location) 
{ 
Event* newNode = new Event(); 
newNode->title = title; 
newNode->description = description; 
newNode->location = location; 
newNode->day = day; 
newNode->month = month; 
newNode->year = year; 
newNode->left = NULL; 
newNode->right = NULL; 
newNode->parent = NULL; 
return newNode; 
} 
Event* eventData() 
{ 
string title, description, location; 
int day, month=0, year=0; 
cout << "Enter the Title : "; 
cin >> ws; 
getline(cin, title); 
cout << "Enter the Description : "; 
cin >> ws; 
getline(cin, description); 
cout << "Enter the location : "; 
cin >> ws; 
getline(cin, location); 
cout << "Enter the day : "; 
cin >> day; 
cout << "Enter the month : "; 
cin >> month; 
cout << "Enter the year : "; 
cin >> year; 
return newEvent(title, description, day, month, year, location); 
} 
Event* binarySearchTree(Event* root,Event *newNode) 
{ 
if (root == NULL) 
{ 
    return newNode; 
} 
else if (root->year >= newNode->year) 
{ 
if (root->year == newNode->year) 
{ 
if (root->month >= newNode->month) 
{ 
    if(root->day > newNode->day) 
     root->left = binarySearchTree(root->left, newNode); 
    else 
     root->right = binarySearchTree(root->right, newNode); 
   } 
   else 
   { 
    root->right = binarySearchTree(root->right, newNode); 
   } 
  } 
  else 
   root->left = binarySearchTree(root->left, newNode); 
 } 
 else  
 { 
  root->right = binarySearchTree(root->right, newNode); 
 } 
  
  return root; 
 
} 
 
void inorderTraversal(Event* root) 
{ 
if (root == NULL) 
return; 
inorderTraversal(root->left); 
cout << root->day << endl; 
inorderTraversal(root->right); 
} 
class QueNode 
{ 
public: 
Event* address; 
QueNode* next; 
QueNode()  
{ 
address  = NULL; 
next = NULL; 
} 
}; 
class Queue 
{ 
public: 
QueNode* front, * rear; 
Queue() 
{ 
    front = rear = NULL; 
} 
void enQueue(Event* obj) 
{ 
QueNode *que = new QueNode; 
que->address = obj; 
que->next = NULL; 
if (front == NULL) 
   front = que; 
  else 
   rear->next = que; 
 
  rear = que; 
 } 
 
 Event* deQueue() 
 { 
  Event* temp = NULL; 
  if(front != NULL) 
  { 
   temp = front->address; 
   front = front->next; 
  } 
  return temp; 
 } 
 
 
 friend void showEvent(int num); 
 friend void UpdateAnEvent(Event* root); 
}; 
 
void title(string titlename) 
{ 
    cout << "\n"; 
    cout << "|" << setw(30) << titlename << setw(20) << "  |\n"; 
    cout << "\n\n"; 
} 
Queue obj; 
void pushingElemetsInQueue(Event * root) 
{ 
    if (root == NULL) 
    return; 
    pushingElemetsInQueue(root->left); 
    obj.enQueue(root); 
    pushingElemetsInQueue(root->right); 
} 
void showDetails(Event* det) 
{ 
    system("cls"); 
    title(det->title + "Details"); 
    cout << endl; 
    cout << "Date : " << det->day << " - " << det->month << " - " << det->year << endl; 
    cout << "Title : " << det->title << endl; 
    cout << "Location : " << det->location << endl; 
    cout << "Description : " << det->description << endl; 
    cout << "\nPress any key to exit : "; 
    char ch = _getch(); 
} 
void showEvent(int num) 
{ 
QueNode* temp = obj.front; 
 if (num == 1) 
 { 
  showDetails(temp->address); 
 } 
 else 
 { 
  for (int i = 1; i < num && temp != NULL; i++) 
  { 
   temp = temp->next; 
  } 
  if (temp == NULL) 
  { 
   cout << "Invalid Entry.\n"; 
  } 
  else 
  { 
   showDetails(temp->address); 
  } 
 } 
 
 Event* temporary = obj.deQueue(); 
 
 while (temporary != NULL) 
 { 
temporary = obj.deQueue(); 
} 
} 
void showSchedule(Event * root) 
{ 
calender caobj; 
system("cls"); 
title("Show Events"); 
pushingElemetsInQueue(root); 
Event* temp = obj.deQueue(); 
int i = 1; 
while(temp != NULL) 
{  
cout << endl; 
cout << i << " . \n"; 
cout << "Date : " << caobj.monthname(temp->month) << " " << temp->day 
<< ", " << temp->year << endl; 
cout << "Title : " << temp->title << endl; 
i++; 
temp = obj.deQueue(); 
} 
int num = 0; 
cout << "\nEnter the number to see event details : "; 
cin >> num; 
pushingElemetsInQueue(root); 
showEvent(num); 
} 
void exit() 
{ 
    char ch; 
    cout << "Enter any key to exit : "; 
    cin >> ch; 
} 
void CurrentDate(calender obj) 
{ 
system("cls"); 
title("Current Date"); 
cout << "Date : " << obj.monthname(cmonth) << "  " << cday << ", " <<  cyear << 
endl << endl; 
 obj.showMonth(cmonth, cyear); 
 cout << "Press any key to exit : "; 
 char ch = _getch(); 
} 
 
void ShowMonth(calender obj) 
{ 
 int year = 0; 
 
 do 
 { 
  system("cls"); 
  title("Months"); 
  cout << "Enter a year between 1900 and 2100 : "; 
  cin >> year; 
 
  if (year >= 1900 && year <= 2100) 
  { 
   for (int i = 1; i <= 12; i++) 
   { 
    obj.showMonth(i, year); 
    cout << "\n\n"; 
   } 
   cout << "Press any key to exit.\n"; 
   char ch = _getch(); 
   break; 
  } 
  else 
  { 
   cout << "Invalid Input."; 
   cout << "Press any key to enter.\n"; 
   char ch = _getch(); 
  } 
 
 } while (true); 
} 
 
 
void SelectedDate(calender obj) 
{ 
 int year = 0,month = 0; 
 
 do 
 { 
  system("cls"); 
  title("Selected Month"); 
  cout << "Enter a year between 1900 and 2100 : "; 
  cin >> year; 
  cout << "Enter the month (1 to 12) : "; 
  cin >> month; 
 
  if (year >= 1900 && year <= 2100 && month >= 1 && month <= 12) 
  { 
   obj.showMonth(month, year); 
   cout << "Press any key to exit.\n"; 
   char ch = _getch(); 
   break; 
  } 
  else 
  { 
   cout << "Invalid Input."; 
   cout << "Press any key to enter.\n"; 
   char ch = _getch(); 
  } 
 
 } while (true); 
} 
 
 
Event* AddEvent(Event * root) 
{ 
 system("cls"); 
title("Add Event"); 
root = binarySearchTree(root, eventData()); 
cout << "\nEvent Added Successfully.\n"; 
cout << "Press any key to exit."; 
char ch = _getch(); 
return root; 
} 
Event* minValueNode(Event* root) 
{ 
    Event* Current = root; 
    while (Current && Current->left != NULL) 
    { 
        Current = Current->left; 
        return  Current; 
    } 
} 
Event* deleteEvent(Event* root,int day,int month,int year) 
{ 
 if (root == NULL) 
 { 
  return root; 
 } 
 else if (root->year > year) 
 { 
  root->left = deleteEvent(root->left, day,month,year); 
 } 
 else if (root->year < year) 
 { 
  root->right = deleteEvent(root->right, day, month, year); 
 } 
 else 
 { 
  if (root->month > month) 
  { 
   root->left = deleteEvent(root->left, day, month, year); 
  } 
  else if (root->month< month) 
  { 
   root->right = deleteEvent(root->right, day, month, year); 
  } 
  else 
  { 
   if (root->day > day) 
   { 
    root->left = deleteEvent(root->left, day, month, year); 
   } 
   else if (root->day < day) 
   { 
    root->right = deleteEvent(root->right, day, month, year); 
   } 
   else 
   { 
    if (root->left == NULL) { 
     Event* temp = root->right; 
     delete root; 
     root = NULL; 
     return temp; 
    } 
    else if (root->right == NULL) { 
     Event* temp = root->left; 
     delete root; 
     root = NULL; 
     return temp; 
    } 
 
     
    Event* temp = minValueNode(root->right); 
 
    root->day = temp->day; 
    root->month = temp->month; 
    root->year = temp->year; 
    root->title = temp ->title; 
    root->description = temp->description; 
    root->location = temp->location; 
 
    root->right = deleteEvent(root->right, temp->day, temp->month, temp->year); 
     
   } 
  } 
 } 
 return root; 
} 
 
Event* deleteAnEvent(Event* root) 
{ 
 system("cls"); 
 title("Delete An Event"); 
 
 showSchedule(root); 
 int day, month, year; 
 cout << "\n\nEnter the day : "; 
cin >> day; 
cout << "Enter the month : "; 
cin >> month; 
cout << " Enter the Year : "; 
cin >> year; 
root = deleteEvent(root,day,month,year); 
return root; 
} 
void EditDetails(Event* root) 
{ 
system("cls"); 
title("Edit Details"); 
string title, description, location; 
int day, month = 0, year = 0; 
cout << "Enter the Title : "; 
cin >> ws; 
getline(cin, title); 
cout << "Enter the Description : "; 
cin >> ws; 
getline(cin, description); 
cout << "Enter the location : "; 
cin >> ws; 
getline(cin, location); 
cout << "Enter the day : "; 
cin >> day; 
cout << "Enter the month : "; 
cin >> month; 
cout << "Enter the year : "; 
cin >> year; 
root->day = day; 
root->month = month; 
root->year = year; 
root->title = title; 
root->description = description; 
root->location = location; 
cout << "Event updated successfully\n"; 
char ch = _getch(); 
} 
void UpdateAnEvent(Event* root) 
{ 
calender caobj; 
system("cls"); 
title("Show Events"); 
pushingElemetsInQueue(root); 
Event* temp = obj.deQueue(); 
int i = 1; 
while (temp != NULL) 
{ 
cout << endl; 
cout << i << " . \n"; 
cout << "Date : " << caobj.monthname(temp->month) << " " << temp->day 
<< ", " << temp->year << endl; 
cout << "Title : " << temp->title << endl; 
i++; 
temp = obj.deQueue(); 
} 
int num = 0; 
cout << "\nEnter the number to Edit An Event : "; 
cin >> num; 
pushingElemetsInQueue(root); 
QueNode* temporary = obj.front; 
if (num == 1) 
 { 
  EditDetails(temporary->address); 
 } 
 else 
 { 
  for (int i = 1; i < num && temporary != NULL; i++) 
  { 
   temporary = temporary->next; 
  } 
  if (temporary == NULL) 
  { 
   cout << "Invalid Entry.\n"; 
  } 
  else 
  { 
   EditDetails(temporary->address); 
  } 
 } 
 
 Event* temporary2 = obj.deQueue(); 
 
 while (temporary2 != NULL) 
 { 
 temporary2 = obj.deQueue(); 
 } 
} 
int main() 
{ 
calender obj; 
Event* root = NULL; 
int num = 0; 
do 
{ 
system("cls"); 
title("Calender"); 
cout << "1. Current Date.\n"; 
cout << "2. Show Months.\n"; 
cout << "3. Selected Date.\n"; 
  cout << "4. Add Event.\n"; 
  cout << "5. Show Events.\n"; 
  cout << "6. Delete Events.\n"; 
  cout << "7. Update Events.\n"; 
  cout << "8.Exit\n\n"; 
 
  int num; 
  cout << "Enter the choice : "; 
  cin >> num; 
 
  switch (num) 
  { 
  case 1:CurrentDate(obj); break; 
  case 2:ShowMonth(obj); break; 
  case 3:SelectedDate(obj); break; 
  case 4:root = AddEvent(root); break; 
  case 5:showSchedule(root); break; 
  case 6:root = deleteAnEvent(root); break; 
  case 7:UpdateAnEvent(root); break; 
  case 8:break; 
  default: cout << "Invalid input.\n"; 
  } 
 
 if (num == 8) 
 break; 
} while (true); 
return 0; 
}