/*Main code file carrying the code to be tested.

*/
#ifndef SUBHEADERS
#define SUBHEADERS
#include "main_headers.h"
//#include "cpptest/gtest.h"

#endif //SUBHEADERS

// The DataBaseConnect interface from the Original Development side code. This interface will be used in the component, for which the test case will be written
class DataBaseConnect  //rename into a generic form---> dbc + ic  //ic = internet connectivity
{
public:
      virtual bool login(string username, string password)
      {
            
            return true;
      }
      virtual bool logout(string username)
      {
            return true;
      }
      virtual int fetchRecord() { return -1; }

      //Add functions for Network connectivity...
};
class Network{
      public:
      virtual int checkConnectivity(string destinationIP,int destinationPort){
            return 1;
      }
};
//New class to validate Exception/throw/if else conditions, memory fault, segmentation faults etc...

/* Need for mock: MyDatabase class uses DataBaseConnect, and But in the real life this DataBaseConnect maybe using some Database
which is at some remote location and for Unit Test purposes yet we cannot have much dependency that's why we write mock for this class.
*/

// PreMock class Component, that uses DataBaseConnect interface and Internet Interface.
class PreMock
{
      // creating a reference for DataBaseConnect as dbC
      DataBaseConnect &dbC;
      Network &net;

public:
      // since its a reference, so we'll have to pass it into a condtructor initalizer list and assign it to dbC
      PreMock(DataBaseConnect &_dbC,Network &_net) : dbC(_dbC),net(_net){}
      int Init(string username, string password,string destinationIP,int destinationPort)
      {
            int retValue=0;
            
            if(net.checkConnectivity(destinationIP,destinationPort)!=1)
            {
                  cout << "Connectivity Failure" << endl;
                  retValue=-1;
            }
            else{
                  cout<<"Network is connected"<<endl;
                  retValue=1;
            }
            if (dbC.login(username, password) != true)
            {
                  cout << "DB Failure" << endl;
                  retValue=-1;
            }
            else{
                  cout << "DB Success" << endl;
                  retValue=1;
            }
            return retValue;
      }
    
};

//to check precommit
double squareRoot(const double a) {
    double b = sqrt(a);
    if(b != b) { // nan check if a ff
        return -1.0;
    }else{  
        return sqrt(a);
    }
}

// Test Cases