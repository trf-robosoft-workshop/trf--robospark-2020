#include<bits/stdc++.h>
using namespace std;
class Personal
{
protected:
    string name, surname, address, dob;
    int *mob = new int[10];
public:
    Personal()
    {    cout << "Pers Construct" << endl;
        
    }
    Personal(string firstname, string lastname , string address , int *mob ,string dob)
    {
        this -> name = name;
        this -> surname = surname;
        this -> address = address;
        this -> dob = dob;
        for(int i = 0;i < 10; i++)
        {
            mob[i] = 0;
        }
    }
    ~Personal()
    {
        delete []mob;
    }
    void getInput()
    {
        cout << "Insert Personal Data" << endl;
        cout << "Insert Name: " ;
        cin >> name;
        cout << "Insert Surname: " ;
        cin >> surname;
        cout << "Insert Addrsss: " ;
        cin >> address;
        cout << "Insert Data of Birth: " ;
        cin >> dob;
        cout << "Insert Moblie Number: " ;
        for(int i= 0; i < 10; i++)
            cin >> mob[i];

        fflush(stdin);
    }

};


class Professional
{
protected:
    string org_name, job_profile , project;
public:
    Professional()
    {    cout << "Pro Constr" << endl;
        
    }
    Professional(string org_name, string job_profile , string project )
    {
        this -> org_name = org_name;
        this -> job_profile = job_profile;
        this -> project = project;

    }
    void getInput()
    {
        cout << "Insert Professional Data" << endl;
        cout << "Insert the name of the Organization: " ;
        cin >> org_name ;
        cout << "Insert Job Profile: " ;
        cin >> job_profile;
        cout << "Insert Project: " ;
        cin >> project;
    }

};

class Academic
{
protected:
    string college_name , branch;
    int year , cgpa ;
public:
    Academic()
    {   cout << "Acad Constr" << endl;
        //default constructor;
    }
    Academic(string college_name, int year , int cgpa , string branch )
    {
        this -> college_name = college_name;
        this -> year = year;
        this -> cgpa = cgpa;
        this -> branch = branch;

    }
    void getInput()
    {
        cout << "Insert Academic Data" << endl;
        cout << "Insert the name of the College: " ;
        cin >> college_name ;
        cout << "Insert year of passing: " ;
        cin >> year;
        cout << "Insert CGPA: " ;
        cin >> cgpa;
        cout << "Insert branch: ";
        cin >> branch;

    }

};

class Biodata :public Personal,public Professional,public Academic
{
public:
    Biodata()
    {
        cout << "Bio Constr" << endl;
    }
    void getInput()
    {
         Personal :: getInput();
         Professional :: getInput();
         Academic :: getInput();
        }
   void Display()
   {
       cout << "DATA : " << endl << endl;
       cout << "Your Data" << endl;
        cout << "Name: " <<  name<< endl;
        cout << "Surname: " << surname << endl;
        cout << "Addrsss: " << address<< endl;
        cout << "Data of Birth: " << dob << endl;
        cout << "Professional Data" << endl;
        cout << "Name of the Organization: "<< org_name << endl ;

        cout << "Job Profile: " << org_name << endl;
        cout << "Project: " <<  project << endl;
        cout << "Academic Data" << endl;
       
        cout << "Insert CGPA: " << cgpa << endl;
        cout << "Insert branch: " << branch << endl;
        cout << "College: " << college_name << endl;
        cout << "Year of passing: " << year << endl;}


};
int main()
{
    Biodata b1;
    b1.getInput();
    b1.Display();

}





