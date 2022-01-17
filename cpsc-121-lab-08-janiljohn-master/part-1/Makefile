# Your Name
# CPSC 121-99
# Lab ??
# 2020-03-19
# Your.Email@Address.Please
#
# What does this program do? What is it's title?
#

CXX = clang++
CFLAGS += -g -Wall -pipe -std=c++14 $(INCLUDES)
LDFLAGS += -g -Wall -pipe -std=c++14

FORMAT = clang-format
FORMATFLAGS += -style=Google --Werror

TIDY = clang-tidy
TIDYFLAGS += -checks=*,-google-build-using-namespace,-fuchsia-default-arguments,-llvm-header-guard,-cppcoreguidelines-owning-memory,-modernize-use-nodiscard,-readability-magic-numbers,-cppcoreguidelines-avoid-magic-numbers,-modernize-pass-by-value,-fuchsia-overloaded-operator,-hicpp-special-member-functions,-google-explicit-constructor,-hicpp-explicit-conversions,-cppcoreguidelines-special-member-functions,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-hicpp-exception-baseclass

TARGET = gofish
# C++ Files
CXXFILES = Card.cpp Deck.cpp Hand.cpp Packet.cpp go_fish.cpp
# Headers
HEADERS = Card.hpp Deck.hpp Hand.hpp Packet.hpp

OBJECTS = $(CXXFILES:.cpp=.o)

DEP = $(CXXFILES:.cpp=.d)

default all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $(TARGET) $(OBJECTS) $(LLDLIBS)

-include $(DEP)

%.d: %.cpp
	set -e; $(CXX) -MM $(CFLAGS) $< \
	| sed 's/\($*\)\.o[ :]*/\1.o $@ : /g' > $@; \
	[ -s $@ ] || rm -f $@

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $<

clean:
	-rm -f $(OBJECTS) core $(TARGET).core

spotless: clean
	-rm -f $(TARGET) $(DEP)

format:
	@echo "Lines starting with '<' are from your file."
	@echo "Lines starting with '>' are what you should have written"
	@echo "  according to the Google C++ Style Guide."
	$(eval FORMATOUT := $(shell mktemp))
	for i in $(CXXFILES) $(HEADERS); do \
		echo "Checking $$i"; \
		$(FORMAT) $(FORMATFLAGS) $$i > $(FORMATOUT); \
		diff $$i $(FORMATOUT) || \
			echo "\nYour file does not conform to the Google C++ Style." \
			"Please edit your code until this message is removed.\n"; \
			rm $(FORMATOUT); \
	done

tidy:
	for i in $(CXXFILES) $(HEADERS); do \
		echo "Checking $$i"; \
		$(TIDY) $$i $(TIDYFLAGS); \
	done

