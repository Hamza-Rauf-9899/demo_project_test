all:
	# g++ -std=c++17 totest.cpp -o totest
	# g++ -std=c++17 helloTest.cpp -lcppunit -o helloTest
	# g++ tests.cpp -std=c++17 -lgtest -lgtest_main -lgmock -pthread -o tests
	# g++ tests.cpp -std=c++17 -lgtest -lgtest_main -lgmock -pthread -o tests
	# g++ test_suit_01.cpp -std=c++17 -lgtest -lgtest_main -lgmock -pthread -o test_suit_01

	g++ ./test/test_cases/test_suit_01.cpp -std=c++17 -lgtest -lgtest_main -lgmock -pthread -o test_suit_01.out
	./test_suit_01.out

# test:
# 	./test_suit_01.out

clean:
	$(RM) test_suit_01
