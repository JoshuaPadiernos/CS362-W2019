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

unittest1.out: unittest1.c dominion.o rngs.o
	echo "Results for unittest1.c:" > unittest1.out
	gcc -o unittest1.bin dominion.o rngs.o unittest1.c $(CFLAGS)
	./unittest1.bin >> unittest1.out
	gcov dominion.o -f -b >> unittest1.out

unittest2.out: unittest2.c dominion.o rngs.o
	echo "Results for unittest2.c:" > unittest2.out
	gcc -o unittest2.bin dominion.o rngs.o unittest2.c $(CFLAGS)
	./unittest2.bin >> unittest2.out
	gcov dominion.o -f -b >> unittest2.out

unittest3.out: unittest3.c dominion.o rngs.o
	echo "Results for unittest3.c:" > unittest3.out
	gcc -o unittest3.bin dominion.o rngs.o unittest3.c $(CFLAGS)
	./unittest3.bin >> unittest3.out
	gcov dominion.o -f -b >> unittest3.out

unittest4.out: unittest4.c dominion.o rngs.o
	echo "Results for unittest4.c:" > unittest4.out
	gcc -o unittest4.bin dominion.o rngs.o unittest4.c $(CFLAGS)
	./unittest4.bin >> unittest4.out
	gcov dominion.o -f -b >> unittest4.out

cardtest1.out: cardtest1.c dominion.o rngs.o
	echo "Results for cardtest1.c:" > cardtest1.out
	gcc -o cardtest1.bin dominion.o rngs.o cardtest1.c $(CFLAGS)
	./cardtest1.bin >> cardtest1.out
	gcov dominion.o -f -b >> cardtest1.out

cardtest2.out: cardtest2.c dominion.o rngs.o
	echo "Results for cardtest2.c:" > cardtest2.out
	gcc -o cardtest2.bin dominion.o rngs.o cardtest2.c $(CFLAGS)
	./cardtest2.bin >> cardtest2.out
	gcov dominion.o -f -b >> cardtest2.out

cardtest3.out: cardtest3.c dominion.o rngs.o
	echo "Results for cardtest3.c:" > cardtest3.out
	gcc -o cardtest3.bin dominion.o rngs.o cardtest3.c $(CFLAGS)
	./cardtest3.bin >> cardtest3.out
	gcov dominion.o -f -b >> cardtest3.out

cardtest4.out: cardtest4.c dominion.o rngs.o
	echo "Results for cardtest4.c:" > cardtest4.out
	gcc -o cardtest4.bin dominion.o rngs.o cardtest4.c $(CFLAGS)
	./cardtest4.bin >> cardtest4.out
	gcov dominion.o -f -b >> cardtest4.out

randomtestadventurer.out: randomtestadventurer.c dominion.o rngs.o
	echo "Results for randomtestadventurer.c:" > randomtestadventurer.out
	gcc -o randomtestadventurer.bin dominion.o rngs.o randomtestadventurer.c $(CFLAGS)
	./randomtestadventurer.bin >> randomtestadventurer.out
	gcov dominion.o -f -b >> randomtestadventurer.out

randomtestcard1.out: randomtestcard1.c dominion.o rngs.o
	echo "Results for randomtestcard1.c:" > randomtestcard1.out
	gcc -o randomtestcard1.bin dominion.o rngs.o randomtestcard1.c $(CFLAGS)
	./randomtestcard1.bin >> randomtestcard1.out
	gcov dominion.o -f -b >> randomtestcard1.out

randomtestcard2.out: randomtestcard2.c dominion.o rngs.o
	echo "Results for randomtestcard2.c:" > randomtestcard2.out
	gcc -o randomtestcard2.bin dominion.o rngs.o randomtestcard2.c $(CFLAGS)
	./randomtestcard2.bin >> randomtestcard2.out
	gcov dominion.o -f -b >> randomtestcard2.out

allunittest: unittest1.out unittest2.out unittest3.out unittest4.out
allcardtest: cardtest1.out cardtest2.out cardtest3.out cardtest4.out 
allrandomtest: randomtestadventurer.out randomtestcard1.out randomtestcard2.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.bin *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
