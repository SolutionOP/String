CC=gcc -std=c11 -D_GNU_SOURCE
TST_LIBS=-lcheck -lm -lpthread
GCOV_LIBS=--coverage
BUILD_PATH=./
SOURCES=s21_string.c
H=s21_string.h
LIBO=s21_string.o
LIBA=s21_string.a
EXE=test.out
OS:=$(shell uname -s)

ifeq ($(OS),Linux)
		CC+=-D LINUX_OS
	else
		ifeq ($(OS),Darwin)
			CC+=-D MAC_OS
		else
		CC+=-D LINUX_OS
		endif
endif

all: s21_string.a test gcov_report

clean:
	rm -rf *.a && rm -rf *.o
	rm -rf *.info && rm -rf *.gcda && rm -rf *.gcno &&  rm -rf *.gcov
	rm -rf report/ && rm -rf *.out

test: s21_string.a
	$(CC) test.c -L. $(LIBA) $(TST_LIBS) -o $(BUILD_PATH)$(EXE)
	$(BUILD_PATH)$(EXE)

rebuild: clean all

s21_string.a: clean
	$(CC) -c $(SOURCES) -o $(BUILD_PATH)$(LIBO)
	ar rcs $(LIBA) $(LIBO)
	ranlib $(LIBA)

gcov_report: s21_string.a
	$(CC) $(GCOV_LIBS) test.c $(SOURCES) $(LIBA) -L. $(LIBA) $(TST_LIBS) -o $(BUILD_PATH)$(EXE)
	$(BUILD_PATH)$(EXE)
	lcov -t "test" -c -d $(BUILD_PATH) --output-file $(BUILD_PATH)coverage.info
	genhtml $(BUILD_PATH)coverage.info --output-directory $(BUILD_PATH)report/

check:
	@echo
	@echo ===CPPCHECK===
	@echo
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h
	@echo
	@echo ===STYLE TEST===
	@echo
	python3 ../materials/linters/cpplint.py --extension=c *.c *.h
	@echo
	@echo ===LEAKS TEST===
	@echo
	CK_FORK=no leaks -atExit -- $(BUILD_PATH)$(EXE)
