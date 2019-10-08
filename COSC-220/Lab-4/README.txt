Blaine Mason
Lab-4

To Compile:
1) Navigate to the directory where the file is located.
2) Enter in "g++ -std=c++11 payrolllist.cpp payroll.cpp main.cpp -o main"
To Run:
1) Enter in "./main" to run the program

The program works by using the PayRollList class to hold the nodes which are
payroll objects.  The information for these objects are read in from the file
"payroll.txt" then inserted from least to greatest by payRate.

The Format of payroll.txt:
1:Size of the list
2:Name of employee
3:The hours the employee worked
4:The pay rate of the employee

An Example:
1
"John Doe"
40
12
