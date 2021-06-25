#include <cctype>
#include <iostream>
#include <sstream>
#include <string>

#include "express.h"

bool _isdigit(int c) {
	return c >= '0' && c <= '9';
}

Express* getExpress(std::stringstream &ss, Express *root = nullptr) {

	std::string value, op;
	if (root == nullptr) {
		ss >> value;
		root = new ValueExp(std::stoi(value));
	}

	ss >> op;

	switch (op[0]) {
		case '+': {
				  auto exp = new AddExp(root, getExpress(ss));
				  return exp;
			  }
		case '-': {
				  auto exp = new SubExp(root, getExpress(ss));
				  return exp;
			  }
		case '*': {
				  ss >> value;
				  auto exp = new MulExp(root, new ValueExp(std::stoi(value)));
				  return getExpress(ss, exp);
			  }
		case '/': {
				  ss >> value;
				  auto exp = new DivExp(root, new ValueExp(std::stoi(value)));
				  return getExpress(ss, exp);
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
