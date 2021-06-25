#include <cctype>
#include <iostream>
#include <sstream>
#include <string>

#include "express.h"

bool _isdigit(int c) {
	return c >= '0' && c <= '9';
}

Express* getExpress(std::stringstream &ss, Express *root = nullptr, int parentheses = 0) {

	std::string _parentheses, value, op;
	if (root == nullptr) {
		ss >> value;
		if (value[0] == '(') {
			root = getExpress(ss, root, parentheses + 1);
		} else 
			root = new Value(std::stoi(value));
	}

	ss >> op;

	switch (op[0]) {
		case '+': {
				  auto exp = new Add(root, getExpress(ss));
				  return exp;
			  }
		case '-': {
				  auto exp = new Sub(root, getExpress(ss));
				  return exp;
			  }
		case '*': {
				  ss >> value;
				  auto exp = new Mul(root, new Value(std::stoi(value)));
				  return getExpress(ss, exp);
			  }
		case '/': {
				  ss >> value;
				  auto exp = new Div(root, new Value(std::stoi(value)));
				  return getExpress(ss, exp);
			  }
		case ')': {
				  return root;
			  }
		default: {
				 return root;
			 }
	}

}

int main() {
	std::stringstream ss;

	do {
		auto c = std::cin.get();
		if (c == EOF) {
			break;
		}

		if (c == '\n') {
			auto exp = getExpress(ss);
			std::cout << exp->calc() << '\n'; 
			delete exp;
			ss.clear();
			continue;
		} 

		ss << (char) c;

	} while (true);

}
