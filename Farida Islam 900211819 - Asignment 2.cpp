#include <iostream>
//#include <bits/stdc++.h>
#include <fstream>
#include <vector>
using namespace std;


class Person  //Person class
{
private:
    string name;
    int id, age;
public:
    Person() {}
    Person(int id, string name, int age)  
    {
        setName(name);
        setAge(age);
        setId(id);
    }
    void setName(string n)  //setters
    {
        name = n;
    }
    void setId(int i)
    {
        id = i;
    }
    void setAge(int a)
    {
        age = a;

    }
    string getName() 
    {
        return name;
    }
    int getId()
    {
        return id;
    }
    int getAge()
    {
        return age;
    }
    void printInfo()
    {
        cout << name << "has the ID number: " << id << " and is " << age << " years old." << endl;

    }


};

struct appointment
{
    int hours, minutes;
};

class Customer : public Person  //inherited Customer class from Person
{
    appointment app;
    int mechanicId;
public:
    Customer() :Person() {}
    Customer(int id, string name, int age, appointment a) : Person(id, name, age)
    {
        app = a;
    }
    Customer(int id, string name, int age) : Person(id, name, age)
    {}
    void setmechanicId(int id)
    {
        mechanicId = id;
    }
    void setAppointment(int hrs, int mins)
    {
        app.hours = hrs;
        app.minutes = mins;
    }

    bool operator < (Customer x)
    {
        if (app.hours < x.app.hours) {
            return true;
        }
        else if (app.hours > x.app.hours) {
            return false;
        }
        else if (app.hours == x.app.hours) {
            if (app.minutes < x.app.minutes){
                return true;
                }
            else {
                return false;
            }
        }
    }

    bool operator > (Customer x)
    {
        if (app.hours > x.app.hours) {
            return true;
        }
        else if (app.hours < x.app.hours) {
            return false;
        }
        else if (app.hours == x.app.hours) {
            if (app.minutes > x.app.minutes) {
                return true;
            }
            else {
                return false;
            }
        }
    }

    bool operator == (Customer x)
    {
        if (app.hours == x.app.hours) {
            if (app.minutes == x.app.minutes) {
                return true;
            }
        }
            return false;
    }


    int getAppointment()
    {
        return app.hours << app.minutes;
    }
    int getmechanicId()
    {
        return mechanicId;
    }

};

class Mechanic : public Person
{
    int counter = 0;
    appointment apps[100];
    
public:
    Mechanic() :Person() {}
    Mechanic(int id, string name, int age) : Person(id, name, age)
    {
        
    }
    bool isAvailable(appointment a, vector <appointment> v)
    {
        for (int i = 0; i <= v.size(); i++)
        {
            if (a.hours == apps[i].hours && a.minutes == apps[i].minutes)
                return true;
        }
        return false;
    }

    void setAppointments(appointment app)
    {
        apps[counter].hours = app.hours;
        apps[counter].minutes = app.minutes;
        counter++;
    }

    int getCounter()
    {
        return counter;
    }

    appointment getAppointment(int i)
    {
        return apps[i];
    }
};

int main() {

    //Mechanic mechanics[3];
    //ifstream newfile;
    //newfile.open("mechanics.txt");
    //Mechanic mechanics[3];
    //if (newfile.is_open()) {
            //string mech;
            //newfile >> mechanicsInfo;

    Mechanic mechanics[3];
    
    Mechanic Mahmoud(1, "Mahmoud Hatem", 43);
    Mechanic Ahmed(2, "Ahmed Khaled", 33);
    Mechanic Abdelrahman(3, "Abdelrahman", 38);
    mechanics[0] = Mahmoud;
    mechanics[1] = Ahmed;
    mechanics[2] = Abdelrahman;

    vector <appointment> m1_app;
    vector <appointment> m2_app;
    vector <appointment> m3_app;

    vector <Customer> vectorOfCustomers;


    int i = 0;


    char e;
    do {
        cout << "Please press C if you're a customer, M if you work in management or X to exit" << endl;
        cin >> e;
        if (e == 'C' || e == 'M' || e == 'X') {


            if (e == 'C') {
                //Customer customers[3];
                

                cout << "Please press R to make an appointment or X to exit." << endl;
                cin >> e;
                if (e == 'R' || e == 'X') {
                    if (e == 'R') {

                        cout << "Please enter your ID, name, age and desired appointment (hours & mins)" << endl;
                        int x, age, h, m;
                        string name;
                        cin >> x >> name >> age >> h >> m;
                        Customer customer(x, name, age);
                        appointment cAppointment;
                        cAppointment.hours = h;
                        cAppointment.minutes = m;

                        vectorOfCustomers.push_back(customer);
                        //customers[i].setId(x);
                        //customers[i].setName(name);
                        //customers[i].setAge(age);
                        //customers[i].setAppointment(h, m);

                       if (!Mahmoud.isAvailable(cAppointment, m1_app)){
                           m1_app.push_back(cAppointment);
                           cout << "Appointment confirmed with Mahmoud at " << customer.getAppointment()<< endl;

                           ofstream outdata;
                           outdata.open("mechanic1.txt");
                           if (!outdata) { 
                               cout << "Error: file could not be opened" << endl;
                           }
                           outdata << "Mahmoud has an appointment with " << customer.getName() << " at " << customer.getAppointment()<< endl;
                           outdata.close();
                       }
                       else if (!Ahmed.isAvailable(cAppointment,m2_app)) {
                           m1_app.push_back(cAppointment);
                           cout << "Appointment confirmed with Ahmed at " << customer.getAppointment()<< endl;

                           ofstream outdata;
                           outdata.open("mechanic2.txt");
                           if (!outdata) {
                               cout << "Error: file could not be opened" << endl;
                           }
                           outdata << "Ahmed has an appointment with " << customer.getName() << " at " << customer.getAppointment() << endl;
                           outdata.close();
                       }
                       else if (!Abdelrahman.isAvailable(cAppointment, m3_app)) {
                           m1_app.push_back(cAppointment);
                           cout << "Appointment confirmed with Abdelrahman at " << customer.getAppointment()<< endl;

                           ofstream outdata;
                           outdata.open("mechanic3.txt");
                           if (!outdata) {
                               cout << "Error: file could not be opened" << endl;
                           }
                           outdata << "Abdelrahman has an appointment with " << customer.getName() << " at " << customer.getAppointment() << endl;
                           outdata.close();
                       }
                       else {
                           cout << "Appointment unavailable, please come back tomorrow."<< endl;
                       }





                    }
                    else {
                        cout << "Exiting program.";
                    }
                }

            }
            else if (e == 'M') {
                cout << "Please press S to view an updated schedule or X to exit." << endl;
                cin >> e;
                if (e == 'S' || e == 'X') {
                    if (e == 'S') {
                        char f;
                        do {
                            cout << "Do you wish to view the updated schedule ?\n Type Y or N" << endl;
                            cin >> f;
                            if (f == 'Y') {
                                cout << "Do you wish to view Mahmoud's (1), Ahmed's (2) or Abdelrahman's (3) schedule?" << endl;
                                int d;
                                cin >> d;
                                if (d == 1) {
                                    ifstream myfile;
                                    myfile.open("mechanic1.txt");
                                    string mystring;
                                    if (myfile.is_open()) {
                                        myfile >> mystring;
                                        cout << mystring;

                                    }
                                }
                                else if (d == 2) {
                                    ifstream myfile;
                                    myfile.open("mechanic2.txt");
                                    string mystring;
                                    if (myfile.is_open()) {
                                        myfile >> mystring;
                                        cout << mystring;

                                    }
                                }
                                else if (d == 3) {
                                    ifstream myfile;
                                    myfile.open("mechanic3.txt");
                                    string mystring;
                                    if (myfile.is_open()) {
                                        myfile >> mystring;
                                        cout << mystring;

                                    }
                                }
                                else {
                                    cout << "This option is unavailable. Please enter your answer again.";
                                }
                            }
                        } while (f != 'N');


                    }
                    else {
                        cout << "Exiting program.";
                    }
                }

            }
            else if (e == 'X') {
                cout << "Exiting program.";
            }

        }
        else {
            cout << "This option is invalid. Exiting program.";
        }
    } while (e != 'X');
    return 0;
}
