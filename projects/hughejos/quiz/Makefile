CFLAGS= -Wall -fpic -coverage -lm -std=c99
TEST_OUT=test_results.out

test: testme.c
	gcc -o testme testme.c $(CFLAGS)
	./testme > $(TEST_OUT)
	gcov testme.c >> $(TEST_OUT)


clean:
	rm testme *gcda *gcno *gcov $(TEST_OUT)


