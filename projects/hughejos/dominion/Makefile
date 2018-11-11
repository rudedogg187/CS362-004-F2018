CFLAGS= -Wall -fpic -coverage -lm -std=c99
TEST_OUT=unittestresults.out
RAND_0=randomtestadventurer
RAND_1=randomtest1
RAND_2=randomtest2

randomtest0: $(RAND_0).c dominion.o rngs.o
	gcc -o $(RAND_0) $(RAND_0).c dominion.o rngs.o $(CFLAGS)		#compile random test with gcov flags
	./$(RAND_0) #>> $(RAND_0).out

randomtest1: randomtestadventurer.c dominion.o rngs.o
	gcc -o $(RAND_1) $(RAND_1).c dominion.o rngs.o $(CFLAGS)		#compile random test with gcov flags
	./$(RAND_1) >> $(RAND_1).out

unittestresults: cardtest1 cardtest2 cardtest3 cardtest4 unittest1 unittest2 unittest3 unittest4
	#create output file to display test results
	echo "Results for HUGHEJOS Assignment 3 Unit Tests" > $(TEST_OUT)

	#card test 1 start
	echo "************" >> $(TEST_OUT)
	echo "Card 1 (cardtest1.c):" >> $(TEST_OUT)	#add unit test to output file
	./cardtest1 >> $(TEST_OUT)				#run and write output of unit test to output file
	echo "\n" >> $(TEST_OUT)
	gcov cardtest1.c >> $(TEST_OUT)				#write gcov results to output file

	#card test 2 start
	echo "************" >> $(TEST_OUT)
	echo "Card 2 (cardtest2.c):" >> $(TEST_OUT)	#add unit test to output file
	./cardtest2 >> $(TEST_OUT)				#run and write output of unit test to output file
	echo "\n" >> $(TEST_OUT)
	gcov cardtest2.c >> $(TEST_OUT)				#write gcov results to output file

	#card test 3 start
	echo "************" >> $(TEST_OUT)
	echo "Card 3 (cardtest3.c):" >> $(TEST_OUT)	#add unit test to output file
	./cardtest3 >> $(TEST_OUT)				#run and write output of unit test to output file
	echo "\n" >> $(TEST_OUT)
	gcov cardtest3.c >> $(TEST_OUT)				#write gcov results to output file

	#card test 4 start
	echo "************" >> $(TEST_OUT)
	echo "Card 4 (cardtest4.c):" >> $(TEST_OUT)	#add unit test to output file
	./cardtest4 >> $(TEST_OUT)				#run and write output of unit test to output file
	echo "\n" >> $(TEST_OUT)
	gcov cardtest4.c >> $(TEST_OUT)				#write gcov results to output file

	#function test 1 start
	echo "************" >> $(TEST_OUT)
	echo "Function 1 (unittest1.c):" >> $(TEST_OUT)	#add unit test to output file
	./unittest1 >> $(TEST_OUT)				#run and write output of unit test to output file
	echo "\n" >> $(TEST_OUT)
	gcov unittest1.c >> $(TEST_OUT)				#write gcov results to output file

	#function test 2 start
	echo "************" >> $(TEST_OUT)
	echo "Function 2 (unittest2.c):" >> $(TEST_OUT)	#add unit test to output file
	./unittest2 >> $(TEST_OUT)				#run and write output of unit test to output file
	echo "\n" >> $(TEST_OUT)
	gcov unittest2.c >> $(TEST_OUT)				#write gcov results to output file

	#function test 3 start
	echo "************" >> $(TEST_OUT)
	echo "Function 3 (unittest3.c):" >> $(TEST_OUT)	#add unit test to output file
	./unittest3 >> $(TEST_OUT)				#run and write output of unit test to output file
	echo "\n" >> $(TEST_OUT)
	gcov unittest3.c >> $(TEST_OUT)				#write gcov results to output file

	#function test 4 start
	echo "************" >> $(TEST_OUT)
	echo "Function 4 (unittest4.c):" >> $(TEST_OUT)	#add unit test to output file
	./unittest4 >> $(TEST_OUT)				#run and write output of unit test to output file
	echo "\n" >> $(TEST_OUT)
	gcov unittest4.c >> $(TEST_OUT)				#write gcov results to output file

	#dominion.c coverage
	echo "************" >> $(TEST_OUT)
	echo "dominion.c Coverage:" >> $(TEST_OUT)	#add unit test to output file
	gcov  dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

cardtest0: cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 cardtest1.c dominion.o rngs.o $(CFLAGS)			#compile unit test with gcov flags
	./cardtest1 >> $(TEST_OUT)				#run and write output of unit test to output file

cardtest1: cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 -g cardtest1.c dominion.o rngs.o $(CFLAGS)			#compile unit test with gcov flags

cardtest2: cardtest2.c dominion.o rngs.o
	gcc -o cardtest2 -g cardtest2.c dominion.o rngs.o $(CFLAGS)			#compile unit test with gcov flags

cardtest3: cardtest3.c dominion.o rngs.o
	gcc -o cardtest3 -g cardtest3.c dominion.o rngs.o $(CFLAGS)			#compile unit test with gcov flags

cardtest4: cardtest4.c dominion.o rngs.o
	gcc -o cardtest4 -g cardtest4.c dominion.o rngs.o $(CFLAGS)			#compile unit test with gcov flags

#drawCardExample
unittest0: unittest0.c dominion.o rngs.o
	gcc -o unittest0 -g unittest0.c dominion.o rngs.o $(CFLAGS)			#compile unit test with gcov flags

unittest1: unittest1.c dominion.o rngs.o
	gcc -o unittest1 -g unittest1.c dominion.o rngs.o $(CFLAGS)			#compile unit test with gcov flags

unittest2: unittest2.c dominion.o rngs.o
	gcc -o unittest2 -g unittest2.c dominion.o rngs.o $(CFLAGS)			#compile unit test with gcov flags

unittest3: unittest3.c dominion.o rngs.o
	gcc -o unittest3 -g unittest3.c dominion.o rngs.o $(CFLAGS)			#compile unit test with gcov flags

unittest4: unittest4.c dominion.o rngs.o
	gcc -o unittest4 -g unittest4.c dominion.o rngs.o $(CFLAGS)			#compile unit test with gcov flags

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)


all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe

cleanrandomtest0:
	rm $(RAND_0).out randomtestadventurer *.gcov *.gcno *.gcda

cleanrandomtest1:
	rm $(RAND_1).out randomtestadventurer *.gcov *.gcno *.gcda

cleanrandomtest2:
	rm $(RAND_2).out randomtestadventurer *.gcov *.gcno *.gcda



cleancardtest1:
	rm $(TEST_OUT) cardtest1 *.gcov *.gcno *.gcda

cleancardtest2:
	rm $(TEST_OUT) cardtest2 *.gcov *.gcno *.gcda

cleancardtest3:
	rm $(TEST_OUT) cardtest3 *.gcov *.gcno *.gcda

cleancardtest4:
	rm $(TEST_OUT) cardtest4 *.gcov *.gcno *.gcda

cleanunittest0:
	rm $(TEST_OUT) unittest0 *.gcov *.gcno *.gcda


cleanunittest1:
	rm $(TEST_OUT) unittest1 *.gcov *.gcno *.gcda

cleanunittest2:
	rm $(TEST_OUT) unittest2 *.gcov *.gcno *.gcda

cleanunittest3:
	rm $(TEST_OUT) unittest3 *.gcov *.gcno *.gcda

cleanunittest4:
	rm $(TEST_OUT) unittest4 *.gcov *.gcno *.gcda

cleanunittest:
	#remove test output file, all test executables and all gcov files
	rm $(TEST_OUT) cardtest1 cardtest2 cardtest3 cardtest4 unittest1 unittest2 unittest3 unittest4 *.gcov *.gcno *.gcda
