###############################################################################
# Compiler
###############################################################################

CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -pedantic -g -fsanitize=address

###############################################################################
# Directories
###############################################################################
SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build
APP_BUILD = $(BUILD_DIR)/app
TEST_BUILD = $(BUILD_DIR)/tests

###############################################################################
# Source Files
###############################################################################
DOMAIN_SRC = \
$(SRC_DIR)/domain/Date.cpp \
$(SRC_DIR)/domain/Time.cpp \
$(SRC_DIR)/domain/DateTime.cpp \
$(SRC_DIR)/domain/Event.cpp

APPLICATION_SRC = \
$(SRC_DIR)/application/CalendarService.cpp

###############################################################################
# Test Framework
###############################################################################
TEST_SRC = \
$(TEST_DIR)/TestRunner.cpp \
$(TEST_DIR)/domain/DateTests.cpp \
$(TEST_DIR)/domain/TimeTests.cpp \
$(TEST_DIR)/domain/DateTimeTests.cpp \
$(TEST_DIR)/domain/EventTests.cpp \
$(TEST_DIR)/application/CalendarServiceTests.cpp

TEST_EXE = test
###############################################################################
# Application
###############################################################################

APP_SRC = $(SRC_DIR)/main.cpp
APP_EXE = calendar

###############################################################################
# Targets
###############################################################################
.PHONY: all calendar tests clean
all: tests
calendar: $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) \
	$(DOMAIN_SRC) \
	$(APPLICATION_SRC) \
	$(APP_SRC) \
	-o $(APP_EXE)

tests: $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) \
	$(DOMAIN_SRC) \
	$(APPLICATION_SRC) \
	$(TEST_SRC) \
	-o $(TEST_EXE)
	./$(TEST_EXE)

###############################################################################
# Build Directory
###############################################################################

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

###############################################################################
# Cleanup
###############################################################################

clean:
	rm -rf $(BUILD_DIR)
	rm -f $(APP_EXE)
	rm -f $(TEST_EXE)

