#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <time.h>
using namespace std;

void welcomeScr();
void adminScr();
void userScr();


class myCar
{
public:
   void setData(string n, string n_plate, int p, int c)
   {
      name = n;
      num_plate = n_plate;
      price = p;
      capacity = c;
   }

   void addToFile()
   {
      ofstream file;
      file.open("cars.txt", ios::app);
      file << "NAME: " << name << endl
           << "PLATE NUMBER: " << num_plate << endl
           << "PRICE: " << price << "$" << endl
           << "CAPACITY: " << capacity << endl
           << endl;
      file.close();
   }

private:
   string name;
   string num_plate;
   int price;
   int capacity;
};

bool numPlateAvailable(string num)
{
   string n;
   string t = "PLATE NUMBER: " + num;
   ifstream file("cars.txt");
   while (getline(file, n))
   {
      if (n == t)
      {
         return true;
      }
   }
   return false;
}

// Function used to validate login credentials
bool isRegistered(string username, string password, int val)
{
   string un, pw;
   if (val == 1)
   {
      ifstream read(username + "_admin.txt");
      getline(read, un);
      getline(read, pw);

      if (un == username && pw == password)
      {
         return true;
      }
   }
   else
   {
      ifstream read(username + ".txt");
      getline(read, un);
      getline(read, pw);

      if (un == username && pw == password)
      {
         return true;
      }
   }
   return false;
}

// function to check if user is already registered
bool fileExists(string username)
{
   string un;
   ifstream read(username + ".txt");
   getline(read, un);

   if (un == username)
   {
      return true;
   }
   return false;
}

bool adminFileExists(string username)
{
   string un;
   ifstream read(username + "_admin.txt");
   getline(read, un);

   if (un == username)
   {
      return true;
   }
   return false;
}

void clrScr()
{
   cout << "\033[2J\033[1;1H";
}

void loading()
{
   cout << "\t\t\t\t\t\t\tWELCOME TO \"CITYVIEW\" CAR RENTALS!\n\n";
   cout << "\t\t\t\t\t\t\tLoading";
   for (int i = 0; i < 7; i++)
   {
      Sleep(1000);
      cout << '.';
   }
   system("cls");
   Sleep(1000);
   string s = "\t\t\t\t\t\t\tInitializing Welcome Screen";
   for (int i = 0; i < s.length(); i++)
   {
      Sleep(100);
      cout << s[i];
   }
   for (int i = 0; i < 6; i++)
   {
      Sleep(1000);
      cout << '.';
   }
   system("cls");
}

void registerLogin(int ans)
{
   string username, password;
   if (ans == 1 || ans == 2)
   {
      cout << "\t\t\t\t\t\t\tEnter you Username: ";
      cin >> username;
      cout << "\t\t\t\t\t\t\tEnter you Password: ";
      cin >> password;

      // checking if username and password matches our database
      if (isRegistered(username, password, ans))
      {
         cout << "\t\t\t\t\t\t\tSuccessfull Login\n\t\t\t\t\t\t\t";
         Sleep(1000);
         system("cls");
         if (ans == 1)
         {
            cout << "\t\t\t\t\t\t\tWelcome Admin\n";
            adminScr();
         }
         else if (ans == 2)
         {
            cout << "\t\t\t\t\t\t\tWelcome User\n";
            userScr();
         }
         system("PAUSE");
      }
      else
      {
         system("cls");
         cout << "\t\t\t\t\t\t\tUsername or Password doesn't match the database.\n";

         cout << "\n\t\t\t\t\t\t\tEnter 1 for Main menu" << endl
              << "\t\t\t\t\t\t\tEnter 2 for exit" << endl;
         int a;
         cout << "\n\t\t\t\t\t\t\tINPUT: ";
         cin >> a;
         system("cls");

         // break code
         if (a == 1)
         {
            welcomeScr();
         }
         else if (a == 2)
         {
            cout << "\t\t\t\t\t\t\tThanks for using CityView car rental!\n";
            Sleep(1000);
            system("exit");
         }
      }
   }
   // Registeration for new customers
   else if (ans == 3)
   {
      cout << "\t\t\t\t\t\t\tChoose Username: ";
      cin >> username;
      cout << "\t\t\t\t\t\t\tChoose Password: ";
      cin >> password;

      // checking if user is already registered
      if (fileExists(username))
      {
         system("cls");
         cout << "\t\t\t\t\t\t\tUser already Registered" << endl;
         Sleep(1000);

         cout << "\n\t\t\t\t\t\t\tEnter 1 for Main menu" << endl
              << "\t\t\t\t\t\t\tEnter 2 for exit" << endl;
         int a;
         cout << "\n\t\t\t\t\t\t\tINPUT: ";
         cin >> a;
         system("cls");

         // break code
         if (a == 1)
         {
            welcomeScr();
         }
         else if (a == 2)
         {
            cout << "\t\t\t\t\t\t\tThanks for using CityView car rental!\n";
            Sleep(3000);
            system("exit");
         }
      }

      ofstream file;
      file.open(username + ".txt");
      file << username << endl
           << password;
      file.close();

      cout << "\t\t\t\t\t\t\tSuccessfull registration!\n";
      cout << "\n\t\t\t\t\t\t\tEnter 1 for Main menu" << endl
           << "\t\t\t\t\t\t\tEnter 2 for exit" << endl;
      int a;
      cout << "\n\t\t\t\t\t\t\tINPUT: ";
      cin >> a;
      system("cls");

      // break code
      if (a == 1)
      {
         welcomeScr();
      }
      else if (a == 2)
      {
         cout << "\t\t\t\t\t\t\tThanks for using CityView car rental!\n";
         Sleep(3000);
         system("exit");
      }
   }
   else
   {
      system("cls");
      cout << "\t\t\t\t\t\t\tInvalid value\n";
      Sleep(500);

      cout << "\n\t\t\t\t\t\t\tEnter 1 for Main menu" << endl
           << "\t\t\t\t\t\t\tEnter 2 for exit" << endl;
      int a;
      cout << "\n\t\t\t\t\t\t\tINPUT: ";
      cin >> a;
      system("cls");

      // break code
      if (a == 1)
      {
         welcomeScr();
      }
      else if (a == 2)
      {
         cout << "\t\t\t\t\t\t\tThanks for using CityView car rental!\n";
         Sleep(3000);
         system("exit");
      }
   }
}

void welcomeScr()
{
   cout << "             --------------------------------------------- Welcome To CityView Car Rental System ---------------------------------------------" << endl;
   cout << "\n\t\t  \t\t\t\t1. MINIMUM RENT TIME IS 3 HOURS";
   cout << "\n\t\t  \t\t\t\t2. CAR ONCE BOOKED CAN'T BE CANCELED";
   cout << "\n\t\t  \t\t\t\t3. RISK BY YOUR OWN";
   cout << "\n\t\t  \t\t\t\t4. INCASE ACCIDENT, ALL COSTING IS PAID BY THE DRIVER";
   cout << "\n\t\t  \t\t\t\t5. PREPARE ITEM AS BELOW";
   cout << "\n\t\t  \t\t\t\t     \3COPY OF IC, LICENSE";
   cout << "\n\t\t  \t\t\t\t     \3DEPOSIT (BASED ON CAR TYPE)";
   cout << "\n\t\t  \t\t\t\t6. ADDITIONAL CHARGE IF LATE";
   cout << "\n\t\t  \t\t\t\t7. SAFE DRIVE!";
   cout << "\n\n\n\n\t\t  \t\t\t PRESS ANY KEY TO CONTINUE :)";
   cout << "\n\t\t  \t\t\t\t\t                                                            ";
   cin.get();
   system("cls");
   
   string desiredOpt = "\t\t\t\t\t\t\tPress the key corresponding to Desired option =>";
   for (int i = 0; i < desiredOpt.length(); i++)
   {
      Sleep(20);
      cout << desiredOpt[i];
   }
   cout << endl;
   cout << "\t\t\t\t\t\t\tAdmin Login: 1" << endl
        << "\t\t\t\t\t\t\tCustomer Login: 2" << endl
        << "\t\t\t\t\t\t\tRegister New customer account: 3" << endl
        << "\t\t\t\t\t\t\tExit: 4" << endl
        << "\t\t\t\t\t\t\tINPUT: ";
   int ans;
   cin >> ans;
   system("cls");
   if (ans == 1 || ans == 2 || ans == 3)
   {
      system("cls");
      registerLogin(ans);
   }
   else if(ans == 4){
      system("cls");
      cout << "\n\t\t\t\t\t\t\tTHANKS FOR USING OUR APPLICATION!\n";
      Sleep(4000);
      system("exit");
   }
   else{
      system("cls");
      cout << "\t\t\t\t\t\t\tINVALID INPUT!";
      Sleep(2000);
      system("cls");
      welcomeScr();
   }
}

void addAdmin()
{
   string username, password;
   cout << "\t\t\t\t\t\t\tChoose Admin Username: ";
   cin >> username;
   cout << "\t\t\t\t\t\t\tChoose Admin Password: ";
   cin >> password;

   // checking if user is already registered
   if (adminFileExists(username))
   {
      system("cls");
      cout << "\t\t\t\t\t\t\tUser already Registered" << endl;
      Sleep(1000);

      cout << "\n\t\t\t\t\t\t\tEnter 1 for Main menu" << endl
           << "\t\t\t\t\t\t\tEnter 2 for exit" << endl;
      int a;
      cout << "\n\t\t\t\t\t\t\tINPUT: ";
      cin >> a;
      system("cls");

      // break code
      if (a == 1)
      {
         welcomeScr();
      }
      else if (a == 2)
      {
         cout << "\t\t\t\t\t\t\tThanks for using CityView car rental!\n";
         Sleep(3000);
         system("exit");
      }
   }

   ofstream file;
   file.open(username + "_admin.txt");
   file << username << endl
        << password;
   file.close();

   cout << "\t\t\t\t\t\t\tSuccessful Admin Registration!\n\t\t\t\t\t\t\t";

   system("PAUSE");
   system("cls");

   // break code
   adminScr();
}

void showCars()
{
   int flag = 0;
   ifstream file("cars.txt");
   if (!file || file.peek() == EOF)
   {
      cout << "\t\t\t\t\t\t\tNo Cars Available\n";
      flag = 1;
      system("PAUSE");
   }
   file.close();

   if (flag == 1)
   {
      return;
   }
   ifstream read("cars.txt");
   string line;
   while (getline(read, line))
   {
      cout << line << endl;
   }

   cout << "\n\n \t\t\t\t\t\t\tEND OF DATA\n";
   system("PAUSE");
}

void addCar(string name)
{
   string num_plate;
   int price, capacity;
   cout << "\n\t\t\t\t\t\t\tEnter the number plate of the car: ";
   cin >> num_plate;
   cout << "\n\t\t\t\t\t\t\tEnter the price tag for the car: ";
   cin >> price;
   cout << "\n\t\t\t\t\t\t\tEnter the Passenger Capacity of the car: ";
   cin >> capacity;

   myCar temp;
   temp.setData(name, num_plate, price, capacity);
   temp.addToFile();

   string s = "\n\t\t\t\t\t\t\tCar Added Successfully!\n\t\t\t\t\t\t\t";
   for (int i = 0; i < s.length(); i++)
   {
      Sleep(10);
      cout << s[i];
   }
   system("PAUSE");
   system("cls");
   adminScr();
}

void rewrite()
{
   string line;
   ofstream file1("cars.txt");

   ifstream filet1("cars_temp.txt");
   while (getline(filet1, line))
   {
      file1 << line << endl;
   }
   filet1.close();
   file1.close();
}

void deleteCar(string num_plate)
{
   if (!numPlateAvailable(num_plate))
   {
      cout << "\n\t\t\t\t\t\t\tInvalid Plate Number!\n";
      system("PAUSE");
      system("cls");
      adminScr();
   }
   else
   {
      string line1, line2, line3;
      int count = 1;

      string numTemp = "PLATE NUMBER: " + num_plate;

      ifstream filen("cars.txt");
      while (getline(filen, line3))
      {
         if (line3 == numTemp)
         {
            break;
         }
         count++;
      }
      filen.close();

      count -= 2;

      if (count <= 0)
      {
         count = 1;
      }

      int line = 1;
      string cline;

      ofstream filet("cars_temp.txt");

      ifstream file("cars.txt");
      while (getline(file, cline))
      {
         if (line == count)
         {
            break;
         }
         filet << cline << endl;
         line++;
      }

      for (int i = 0; i < 4; i++)
      {
         getline(file, cline);
      }

      while (getline(file, cline))
      {
         filet << cline << endl;
      }
      file.close();

      filet.close();
      rewrite();
   }
}

void resetCar(string num_plate, int new_p)
{
   if (!numPlateAvailable(num_plate))
   {
      cout << "\n\t\t\t\t\t\t\tInvalid Plate Number!\n";
      system("PAUSE");
      system("cls");
      adminScr();
   }
   else
   {
      string t = "PLATE NUMBER: " + num_plate;
      string line3;
      int count = 1;

      ifstream filen("cars.txt");
      while (getline(filen, line3))
      {
         if (line3 == t)
         {
            break;
         }
         count++;
      }
      filen.close();

      count += 1;

      if (count <= 0)
      {
         count = 1;
      }

      string line;
      ofstream filet("cars_temp.txt");
      ifstream file1("cars.txt");
      while (count > 1)
      {
         getline(file1, line);
         filet << line << endl;
         count--;
      }
      getline(file1, line);
      filet << "PRICE: " << new_p << "$" << endl;
      while (getline(file1, line))
      {
         filet << line << endl;
      }
      file1.close();
      filet.close();

      rewrite();
      system("cls");
      cout << "\t\t\t\t\t\t\tCar Price Reset Successfully!\n\t\t\t\t\t\t\t";
      system("PAUSE");
      system("cls");
      adminScr();
   }
}

void adminScr()
{
   cout << "\t\t\t\t\t\t\t1. ADD ADMIN\n"
        << "\t\t\t\t\t\t\t2. SHOW CARS\n"
        << "\t\t\t\t\t\t\t3. ADD CAR\n"
        << "\t\t\t\t\t\t\t4. DELETE CAR\n"
        << "\t\t\t\t\t\t\t5. RESET AVAILABLE CAR\n"
        << "\t\t\t\t\t\t\t6. LOG OFF\n\n"
        << "\t\t\t\t\t\t\tINPUT: ";
   int ans;
   cin >> ans;
   if (ans == 1)
   {
      system("cls");
      addAdmin();
   }
   else if (ans == 2)
   {
      system("cls");
      showCars();
      system("cls");
      adminScr();
   }
   else if (ans == 3)
   {
      system("cls");
      string name;
      cout << "\t\t\t\t\t\t\tEnter the name of the Car: ";
      cin >> name;
      addCar(name);
   }
   else if (ans == 4)
   {
      system("cls");
      string num;
      cout << "\t\t\t\t\t\t\tEnter the Plate number of the Car: ";
      cin >> num;
      deleteCar(num);
      cout << "\n\t\t\t\t\t\t\tCar DELETED successfully!\n\t\t\t\t\t\t\t";
      system("PAUSE");
      system("cls");
      adminScr();
   }
   else if (ans == 5)
   {
      system("cls");
      cout << "\t\t\t\t\t\t\tYou can only reset the Price Tag of a particular Tag!\n"
           << "\n\t\t\t\t\t\t\tTo reset anything else first delete the car and have fresh entry!\n";
      string num;
      cout << "\n\t\t\t\t\t\t\tEnter the Number Plate of the Car: ";
      cin >> num;
      int price;
      cout << "\n\t\t\t\t\t\t\tEnter the New Price Tag for the Car: ";
      cin >> price;
      resetCar(num, price);
   }
   else if (ans == 6)
   {
      system("cls");
      string logout = "\t\t\t\t\t\t\tThanks for visiting CityView Car Rentals\n \n\t\t\t\t\t\t\tREDIRECTING TO MAIN MENU!\n";
      for (int i = 0; i < logout.length(); i++)
      {
         Sleep(20);
         cout << logout[i];
      }
      string last = "\n\t\t\t\t\t\t\tREDIRECTING";
      for (int i = 0; i < last.length(); i++)
      {
         cout << last[i];
      }
      for (int i = 0; i < 4; i++)
      {
         Sleep(1000);
         cout << '.';
      }
      welcomeScr();
   }
   else
   {
      system("cls");
      cout << "\t\t\t\t\t\t\tINVALID INPUT!\n\n"
           << "\t\t\t\t\t\t\tRedirecting to Admin Console\n";
      Sleep(3000);
      system("cls");
      adminScr();
   }
}

int estimateFair(int time, string driver)
{
   string temp = "";
   for (int i = 0; i < driver.length(); i++)
   {
      temp += tolower(driver[i]);
   }
   int price = 0;
   if (temp == "yes" || temp == "y")
   {
      price += 500;
   }
   price += (time * 249);
   return price;
}

void bookCar()
{
   string num_plate, cName, location, driver;
   int time;
   cout << "\t\t\t\t\t\t\tSelect a car from \"Show Available Cars\" Option and note down the Plate Number for convenience!\n";
   cout << "\n\t\t\t\t\t\t\tEnter the Number Plate of the car: ";
   cin >> num_plate;

   if (!numPlateAvailable(num_plate))
   {
      cout << "\n\t\t\t\t\t\t\tCar is not available, Please Select Another\n";
      cout << "\n \t\t\t\t\t\t\tRedirecting to User console\n\t\t\t\t\t\t\t";
      Sleep(3000);
      system("cls");
      userScr();
      system("cls");
   }
   else
   {
      cout << "\n\t\t\t\t\t\t\tEnter the Rent Time (in hours): ";
      cin >> time;
      if (time < 3)
      {
         cout << "\n\t\t\t\t\t\t\tMinimum Rent Time is 3 hours\n";
         cout << "\n\t\t\t\t\t\t\tRedirecting to User Console\n";
         Sleep(3000);
         system("cls");
         userScr();
      }
      else
      {
         cout << "\n\t\t\t\t\t\t\tIs Driver required: ";
         cin >> driver;
         cout << "\n\t\t\t\t\t\t\tEnter Your Name: ";
         cin >> cName;
         cout << "\n\t\t\t\t\t\t\tEnter the location: ";
         cin >> location;
         system("cls");
         string smessage = "\n\t\t\t\t\t\t\tCar Registered Successfully under customer name: ";
         string lomessage = "\n\t\t\t\t\t\t\tCar will be delivered to adress: ";
         string amountmessage = "\n\t\t\t\t\t\t\tRent amount is: ";
         for (int i = 0; i < smessage.length(); i++)
         {
            Sleep(20);
            cout << smessage[i];
         }
         cout << cName << endl;
         for (int i = 0; i < lomessage.length(); i++)
         {
            Sleep(20);
            cout << lomessage[i];
         }
         cout << location << endl;
         for (int i = 0; i < amountmessage.length(); i++)
         {
            Sleep(20);
            cout << amountmessage[i];
         }
         cout << estimateFair(time, driver) << "$" << endl;
         cout << "\n\n\n\n\t\t\t\t\t\t\tPlease keep your ID and Driving Licence ready\n"
              << "\n\t\t\t\t\t\t\tPay the Above amount after Car delivery\n";
         cout << "\n\n\t\t\t\t\t\t\tTHANK YOU FOR USING OUR SERVICES!\n\n\t\t\t\t\t\t\t";
         deleteCar(num_plate);
         system("PAUSE");
         system("cls");
         userScr();
      }
   }
}

void userScr()
{
   string services = "\t\t\t\t\t\t\tServices available =>";
   int ans;
   for (int i = 0; i < services.length(); i++)
   {
      Sleep(20);
      cout << services[i];
   }
   cout << endl;
   cout << "\t\t\t\t\t\t\t1. SHOW AVAILABLE CARS\n"
        << "\t\t\t\t\t\t\t2. BOOK A CAR\n"
        << "\t\t\t\t\t\t\t3. CALCULATE ESTIMATED FAIR\n"
        << "\t\t\t\t\t\t\t4. LOG OFF\n\n"
        << "\t\t\t\t\t\t\tINPUT: ";
   cin >> ans;

   if (ans == 1)
   {
      system("cls");
      showCars();
      system("cls");
      userScr();
   }
   else if (ans == 2)
   {
      system("cls");
      bookCar();
   }
   else if (ans == 3)
   {
      system("cls");
      cout << "\t\t\t\t\t\t\tMINIMUM RENT TIME IS 3 HOURS\n\n";
      int time;
      string driver;
      cout << "\t\t\t\t\t\t\tEnter the rent time (in hours): ";
      cin >> time;

      if (time < 3)
      {
         cout << "\n\t\t\t\t\t\t\tAS ALREADY MENTIONED, MINIMUM RENT TIME IS 3 HOURS\n";
         cout << "\t\t\t\t\t\t\tRedirecting to User Console....\n";
         Sleep(3000);
         system("cls");
         userScr();
      }
      else
      {
         cout << "\t\t\t\t\t\t\tIs driver required for the journey: ";
         cin >> driver;

         cout << "\t\t\t\t\t\t\tThe Estimated Rent for given time is :" << estimateFair(time, driver) << "$" << endl;
         cout << "\n\t\t\t\t\t\t\tPLEASE NOTE THAT THIS PRICE EXCLUDES THE CAR's COSTS\n\t\t\t\t\t\t\t";
         system("PAUSE");
         system("cls");
         userScr();
      }
   }
   else if (ans == 4)
   {
      system("cls");
      string logout = "\t\t\t\t\t\t\tThanks for visiting CityView Car Rentals\n \n\t\t\t\t\t\t\tREDIRECTING TO MAIN MENU!\n";
      for (int i = 0; i < logout.length(); i++)
      {
         Sleep(20);
         cout << logout[i];
      }
      string last = "\n\t\t\t\t\t\t\tREDIRECTING";
      for (int i = 0; i < last.length(); i++)
      {
         Sleep(500);
         cout << last[i];
      }
      for (int i = 0; i < 4; i++)
      {
         Sleep(1000);
         cout << '.';
      }
      welcomeScr();
   }
   else
   {
      system("cls");
      cout << "\t\t\t\t\t\t\tINVALID INPUT!\n\n"
           << "\t\t\t\t\t\t\tRedirecting to User Console\n";
      Sleep(3000);
      system("cls");
      userScr();
   }
}

int main()
{
   loading();
   welcomeScr();

   return 1;
}

// CODED BY ANSHUMAN SINGH
