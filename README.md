# demo_project

There are 4 sub-directories in **demo_project**, which are as follows:
1) **src** //containing the main code files, for which the test cases will be written  
  i) what_to_test.cpp  
  ii) main_headers.h  
2) **test** //containing 2 sub-folders which are as:  
  2.1) **test_data** //containing the generated data which will be used for testing  
  2.2) **test_cases** //containing all the test cases written for main what_to_test.cpp (i.e., file in src directory)  
       i) test_suit_01.cpp  
  
3) **build** //build directory contains all the build files that are being used for compile and run.  
4) **proj_documentation** //the documentation directory, containing the detailed report about the project with descriptive information.  
-----
**To Run:**
It is assumed that you will be following the same directory architecture as listed above.  
Open the terminal in main **demo_project**:  
The following commands will be used to run the project.  
Home/demo_project:\~$ g++ -o ./build/test_suit_01.out test/test_cases/test_suit_01.cpp -std=c++11 -lgtest -lgtest_main -lgmock -pthread
Home/demo_project:\~$ ./build/test_suit_01.out  
