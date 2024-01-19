/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 10
// Version 1.0
// Description
// tester program
// This file tests the lab section of your workshop
// Modify the main function as stated in the workshop description
// and the comments stated in the main function
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Car.h"
#include "Employee.h"
#include "ReadWrite.h"
#include "Student.h"
#include "Collection.h"
#include "searchNlist.h"
using namespace std;
using namespace sdds;
int main() {
   // Create an array of cars
   Car C[8] = { Car("GVFGHI", "Tesla Model S"), Car("ABCDEF", "BMW 320"), Car("CDEFGH", "Ford Festiva"), 
                Car("BCDEFG", "Ford Festiva"),Car("GVDGHI", "Tesla Model 3"), Car("EFGHIJ", "Nissan Maxima"), 
                Car("GVDEFG", "Tesla Model X") };

   // Create an array of students
   Student S[6] = { Student(23456, "Lisa Simpson", 4.0), Student(45678, "Ralph Wiggum", 2.1), Student(56789, "Milhouse Van Houten", 4.0), 
                Student(67890, "Todd Flanders", 3.5), Student(34567, "Nelson Muntz", 3.0), Student(12345, "Bart Simpson", 1.5) };

   // Create an array of employees
   Employee E[6] = { Employee(213456, "Carl Carlson", 62344.56, 111), Employee(122345, "Mindy Simmons", 65432.44, 222), 
                Employee(435678, "Lenny Leonard", 43213.22, 111), Employee(546789, "Waylon Smithers", 654321.55, 333), 
                Employee(657890, "Frank Grimes", 34567.88, 333), Employee(364567, "Homer Simpson", 55432.11, 111) };

   // Create collections for cars, students, and employees
   Collection<Car> Cres;
   Collection<Student> Sres;
   Collection<Employee> Eres;

   // List all cars
   listArrayElements("All the cars:", C, sizeof(C) / sizeof(*C) - 1);

   // Search for cars with "Tesla" in their make/model and store the results in 
   cout << "Searching for Tesla cars: " << endl;
   if (search(C, sizeof(C) / sizeof(*C), "Tesla", Cres)) {
      cout << Cres.size() << " match" << (Cres.size() == 1 ? "" : "es") << " found:" << endl;
      for (int i = 0; i < Cres.size(); i++) {
         cout << (i + 1) << ": " << Cres[i] << endl;
      }
   }
   else {
      cout << "No matches found!" << endl;
   }
   cout << endl;

   // List all students
   listArrayElements("All students:", S, sizeof(S) / sizeof(*S));

   // Search for students with a GPA of 4.0
   cout << "Searching for students with 4.0 GPA:" << endl;
   if (search(S, sizeof(S) / sizeof(*S), 4.0, Sres)) {
      cout << Sres.size() << " match" << (Sres.size() == 1 ? "" : "es") << " found:" << endl;
      for (int i = 0; i < Sres.size(); i++) {
         cout << (i + 1) << ": " << Sres[i] << endl;
      }
   }
   else {
      cout << "No matches found!" << endl;
   }
   cout << endl;

   // List all employees
   listArrayElements("All employees:", E, sizeof(E) / sizeof(*E));

   // Search for employees who share office number 111
   cout << "Searching for employees who share office number 111:" << endl;
   if (search(E, sizeof(E) / sizeof(*E), 111, Eres)) {
      cout << Eres.size() << " match" << (Eres.size() == 1 ? "" : "es") << " found:" << endl;
      for (int i = 0; i < Eres.size(); i++) {
         cout << (i + 1) << ": " << Eres[i] << endl;
      }
   }
   else {
      cout << "No matches found!" << endl;
   }
   cout << endl;

   // Search for employees who share office number 555
   cout << "Searching for employees who share office number 555:" << endl;
   if (search(E, sizeof(E) / sizeof(*E), 555, Eres)) {
      cout << Eres.size() << " match" << (Eres.size() == 1 ? "" : "es") << " found:" << endl;
      for (int i = 0; i < Eres.size(); i++) {
         cout << (i + 1) << ": " << Eres[i] << endl;
      }
   }
   else {
      cout << "No matches found!" << endl;
   }
   cout << endl;

   // Array of integers
   int a[]{ 10,20,30,40,50,60 };

   // List all integers
   listArrayElements("INTEGERS", a, sizeof(a) / sizeof(*a));

   return 0;
}
