#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Scheduler {

    public:

    Scheduler(){}

    ~Scheduler(){}

    string FCFS(){
        
        return "";
    }

    string SJF(){

        return "";
    }

    string priority(){

        return "";
    }

};


int main(){

    Scheduler scheduler = Scheduler();

    cout << "Hello world" << endl;

    //string output = scheduler.FCFS();

    // Open the input file named "input.txt" 
    ifstream inputFile("tester.csv"); 
  
    // Check if the file is successfully opened 
    if (!inputFile.is_open()) { 
        cerr << "Error opening the file!" << endl; 
        return 1; 
    } 

    string line; // store each line of the file 
  
    // read each line of the file and print it
    cout << "File Content Test: " << endl; 

    while (getline(inputFile, line)) { 
        cout << line << endl; // print the current line 
    } 
  
    inputFile.close(); 

    return 0;
}