// C++ Program to implement
// map of functions
#include <bits/stdc++.h>
using namespace std;

// Define a type alias for a function that takes two longs
// and returns a long
using func = function<long(long, long)>;

// Create a map that maps strings to functions
map<string, func> mp{
	// Plus function from functools
	{ "+", plus<long>() },
	// Minus function from functools
	{ "-", minus<long>() },
	// Divides function from functools
	{ "/", divides<long>() },
	// Multiplies function from functools
	{ "*", multiplies<long>() }
};

// Function to evaluate a Reverse Polish Notation (RPN)
// expression
int evalRPN(vector<string>& A)
{
	// Create a stack to store the operands
	stack<long> s;

	// Iterate over the elements in the RPN expression
	for (auto i : A) {
		// If the element is not an operator, it is an
		// operand Convert it to an integer and push it onto
		// the stack
		if (!mp[i]) {
			s.push(stoi(i));
		}
		// If the element is an operator, pop the top two
		// operands from the stack Perform the operation and
		// push the result back onto the stack
		else {
			auto num1 = s.top();
			s.pop();
			auto num2 = s.top();
			s.pop();
			s.push(mp[i](num2, num1));
		}
	}

	// Return the result, which is the top element of the
	// stack
	return s.top();
}

int main()
{
	// Test the evalRPN function with an RPN expression
	vector<string> A
		= { "10", "6", "9", "3", "+", "-11", "*",
			"/", "*", "17", "+", "5", "+" };

	int answer = evalRPN(A);
	cout << answer << endl;

	return 0;
}
