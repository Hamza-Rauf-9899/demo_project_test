/*
To run the test_suit_01.cpp:
demo_project:~$ g++ test/test_cases/test_suit_01.cpp -std=c++11 -lgtest -lgtest_main -lgmock -pthread -o ./build/test_suit_01.out
demo_project:~$ ./build/test_suit_01.out
*/

#include "../../src/main_headers.h"
#include "../../src/what_to_test.cpp"

// #include "main_headers.h"
// #include "what_to_test.cpp"


/* Need for mock: MyDatabase class uses DataBaseConnect, and But in the real life this DataBaseConnect maybe using some Database
which is at some remote location and for Unit Test purposes yet we cannot have much dependency that's why we write mock for this class.
*/

//comment to check commit

class Mock : public DataBaseConnect, public  Network
{
public:
      // Mock Macros...
      MOCK_METHOD2(login, bool(string username, string password));
      MOCK_METHOD2(checkConnectivity,int(string destinationIP,int destinationPort));
};

// Test Cases
// TEST(MyDBTest, loginTest)
// {
//       MockDB mdb;
//       MyDatabase db(mdb);

//       EXPECT_CALL(mdb, login("Terminator", "I'm Back"))
//           .Times(1)
//           .WillOnce(Return(true));
//       // Act
//       int retValue = db.Init("Terminator", "I'm Back");
//       // ASSERT
//       EXPECT_EQ(retValue, 1);
// }
//

TEST(MyDB_Network_Test, login_ConnectionTest_Success)
{
      Mock _dbC,_net;
      
      PreMock pm(_dbC,_net);

      EXPECT_CALL(_dbC, login("Terminator", "I'm Back"))
          .Times(1)
          .WillOnce(Return(true));
      EXPECT_CALL(_net, checkConnectivity("192.168.1.1",1234))
            .Times(1)
            .WillOnce(Return(true));
      // Act
      int retValue = pm.Init("Terminator", "I'm Back","192.168.1.1",1234);
      // ASSERT
      EXPECT_EQ(retValue, 1);
}
TEST(MyDB_Network_Test, login_ConnectionTest_Failure)
{
      Mock _dbC,_net;
      
      PreMock pm(_dbC,_net);
      EXPECT_CALL(_dbC, login("Terminator", "I'm Back"))
          .Times(1)
          .WillOnce(Return(true));
      EXPECT_CALL(_net, checkConnectivity("192.168.1.1",1234))
            .Times(1)
            .WillOnce(Return(false));
      // Act
      int retValue = pm.Init("Terminator", "I'm Back","192.168.1.1",1234);
      // ASSERT
      EXPECT_EQ(retValue, 1);
}

//just for the precommit checking
TEST(SquareRootTest, PositiveNos) { 
    ASSERT_EQ(6, squareRoot(36.0));
    ASSERT_EQ(18.0, squareRoot(324.0));
    GTEST_SKIP() << "Skipping two tests";
    ASSERT_EQ(25.4, squareRoot(645.16));
    
}

int main()
{
      testing::InitGoogleTest();
      return RUN_ALL_TESTS();
}