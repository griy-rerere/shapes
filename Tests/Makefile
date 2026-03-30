RESULT_APP = shapes
TEST_APP = test

COMPILER_OPTIONS = -c -ISource

SOURCE_FILES = shapes.cpp Source/App.cpp Source/Identi.cpp
OBJ_FILES = $(SOURCE_FILES:.cpp=.o)

# --- Google Test ---
GTEST_SRC = ../googletest/googletest/src/gtest-all.cc
GTEST_MAIN = ../googletest/googletest/src/gtest_main.cc

TEST_SRC = test.cpp Matrix.cpp
TEST_OBJ = $(TEST_SRC:.cpp=.o) gtest-all.o gtest_main.o

# --- test app ---
test: $(TEST_APP)

$(TEST_APP): $(TEST_OBJ)
	g++ $(TEST_OBJ) -o $@

clean:
	rm -f *.o $(TEST_APP)

debug:
	echo $(TEST_APP)
	echo $(COMPILER_OPTIONS)
	echo $(TEST_SRC)
	echo $(TEST_OBJ)