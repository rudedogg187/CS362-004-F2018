CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testWhoseTurn: unittest1.c dominion.o	rngs.o
	gcc -o testWhoseTurn -g unittest1.c dominion.o rngs.o $(CFLAGS)

testFullDeckCount: unittest2.c dominion.o	rngs.o
	gcc -o testFullDeckCount -g unittest2.c dominion.o rngs.o $(CFLAGS)

testGetCost: unittest3.c dominion.o	rngs.o
	gcc -o testGetCost -g unittest3.c dominion.o rngs.o $(CFLAGS)

testIsGameOver: unittest4.c dominion.o	rngs.o
	gcc -o testIsGameOver -g unittest4.c dominion.o rngs.o $(CFLAGS)

testCardAdventurer: cardtest1.c dominion.o	rngs.o
	gcc -o testCardAdventurer -g cardtest1.c dominion.o rngs.o $(CFLAGS)

testCardSmithy: cardtest2.c dominion.o	rngs.o
	gcc -o testCardSmithy -g -coverage cardtest2.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

randomTestAdventurer1: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomTestAdventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)

randomTestAdventurer: randomTestAdventurer1
	./randomTestAdventurer &> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

randomTestCard1_1: randomtestcard1.c dominion.o rngs.o
	gcc -o randomTestCard1 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)

randomTestCard1: randomTestCard1_1
	./randomTestCard1 &> randomtestcard1.out
	gcov dominion.c >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out

randomTestCard2_1: randomtestcard2.c dominion.o rngs.o
	gcc -o randomTestCard2 -g randomtestcard2.c dominion.o rngs.o $(CFLAGS)

randomTestCard2: randomTestCard2_1
	./randomTestCard2 &> randomtestcard2.out
	gcov dominion.c >> randomtestcard2.out
	cat dominion.c.gcov >> randomtestcard2.out

randomTestResults: randomTestAdventurer randomTestCard1 randomTestCard2
	./randomTestCard1 &> randomtestresults.out
	./randomTestCard2 &> randomtestresults.out
	gcov dominion.c >> randomtestresults.out
	cat dominion.c.gcov >> randomtestresults.out

unittestresults: testWhoseTurn testFullDeckCount testGetCost testIsGameOver testCardAdventurer testCardSmithy
	./testWhoseTurn &> unittestresults.out
	./testFullDeckCount &> unittestresults.out
	./testGetCost &> unittestresults.out
	./testIsGameOver &> unittestresults.out
	./testCardAdventurer &> unittestresults.out
	./testCardSmithy &> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out


runtests: testDrawCard
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
