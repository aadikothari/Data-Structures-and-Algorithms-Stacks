#include "catch.hpp"
#include "Stack.hpp"

// giventest
TEST_CASE( "Peak at empty stack", "[Stack]" )
{
  Stack<int> s;
  
  REQUIRE_THROWS_AS(s.peek(), std::range_error);
  REQUIRE_THROWS_AS(s.peekPop(), std::range_error);
}

// Test case for default constructor
TEST_CASE("Default Constructor") {
	Stack<int> s;
	Stack<int> sEmpty;

	// create s stack, and add {1,2,3,4,5}, while keeping sEmpty empty
	s.push(5);
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);

	// sEmpty should be empty, meaning default constructor works
	REQUIRE_FALSE(s.isEmpty());
	REQUIRE(sEmpty.isEmpty());
}

// copy constructor and operator= method test case
TEST_CASE("Copy Constructor and Operator='s") {
	Stack<int> s;
	Stack<int> sTwo;
	Stack<int> sThree;

	// same thing, add 5 elements
	s.push(5);
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);

	Stack<int> sCopy(s);

	// size for second stack should be 0, since nothing was added.
	REQUIRE(sTwo.size() == 0);
	REQUIRE(s.size() == 5);

	// now, the values of s should be transferred in stack two
	sTwo = s;

	// as seen, size isnow 5 for both
	REQUIRE(sTwo.size() == 5);
	REQUIRE(s.size() == 5);
	REQUIRE(sCopy.size() == 5);
}

// testing for size() method
TEST_CASE("Size") {
	// create 4 stacks
	Stack<int> s;
	Stack<int> sTwo;
	Stack<int> sThree;
	Stack<int> sEmpty;

	// add 5 elements to stack 1
	s.push(5);
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);

	// add 3 elements to stack 2
	sTwo.push(3);
	sTwo.push(2);
	sTwo.push(1);

	// add 2 elements to stack 1
	sThree.push(0);
	sThree.push(0);

	// checking sizesfor all, returns the correct value
	REQUIRE(s.size() == 5);
	REQUIRE(sTwo.size() == 3);
	REQUIRE(sThree.size() == 2);
	REQUIRE(sEmpty.size() == 0);
}

// tesing the isEmpty() method
TEST_CASE("isEmpty()") {
	// creating two stacks,one empty, other not empty
	Stack<int> sEmpty;
	Stack<int> sNotEmpty;

	// push random element
	sNotEmpty.push(69420);

	// sEmpty is empty, sNotEmpty is not empty
	REQUIRE_FALSE(sNotEmpty.isEmpty());
	REQUIRE(sEmpty.isEmpty());
}

// push(), pop(), peek() methods are similar and can be all tested together
TEST_CASE("push(), pop(), and peek() methods") {
	Stack<int> s;
	
	s.push(5);
	// peek returns the top most element, without removing it.
	REQUIRE(s.peek() == 5);
	s.push(4);
	REQUIRE(s.peek() == 4);
	s.push(2);
	REQUIRE(s.peek() == 2);
	
	//popping will remove the element
	s.pop();

	// this will return 4, as 2 was removed
	REQUIRE(s.peek() == 4);
	s.push(3);
	REQUIRE(s.peek() == 3);
	s.push(2);
	REQUIRE(s.peek() == 2);
	s.push(69);
	REQUIRE(s.peek() == 69);
	
	// again, pop 69
	s.pop();

	// peeking this will return 2 as 69 was popped
	REQUIRE(s.peek() == 2);

	s.push(1);
	REQUIRE(s.peek() == 1);

	// size will be 5, as there were 7 pushes, 2 pops. and peek() doesn't affect elements, only returns topmost element
	REQUIRE(s.size() == 5);
}

// testing peekpop, that will remove and return the topmost element that it removes
TEST_CASE("peekpop() method") {
	Stack<int> s;

	s.push(2);
	// peekPop will return 2, AND remove 2
	REQUIRE(s.peekPop() == 2);

	// now size should be 0
	REQUIRE(s.size() == 0);

	s.push(3);
	s.push(2);
	s.push(1);

	// add3 elements and size becomes 3 again
	REQUIRE(s.size() == 3);
}

// clear() method test cases
TEST_CASE("clear() method") {
	Stack<int> s;

	// add 5 elements on the stack
	s.push(3);
	s.push(3);
	s.push(3);
	s.push(3);
	s.push(3);

	// size will be 5.
	REQUIRE(s.size() == 5);

	// clearing the stack deletes all the element at once
	s.clear();

	// now size will be 0
	REQUIRE(s.size() == 0);
}

// test case for swap() method
TEST_CASE("swap() method") {
	Stack<int> s;
	// create sSwap that will be empty and used to swap the values of original s stack
	Stack<int> sSwap;

	// push 3 elementsin the stack
	s.push(3);
	s.push(2);
	s.push(1);

	// size for s should be 3, and sSwap is empty currently
	REQUIRE(s.size() == 3);
	REQUIRE(sSwap.size() == 0);

	// this swaps s and sSwap values. so now sSwap has s' value, and vice-versa
	s.swap(s, sSwap);

	// checking that, and that is exactly true\
	REQUIRE(s.size() == 0);
	REQUIRE(sSwap.size() == 3);

}