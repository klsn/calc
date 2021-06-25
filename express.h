
#pragma once

#include <iostream>

class Express {

	public:
		virtual int calc() {return 0;}
		virtual ~Express() {}
};

class Binary: public Express {
	protected:
		Express *left, *right;

	public:
		  Binary(Express *left, Express *right) : left(left), right(right) {}
		  ~Binary() {
			  delete left;
			  delete right;
		  }
};

class Parentheses : public Express {
	protected:
		Express *exp;

	public:
		Parentheses(Express *exp) : exp(exp) {}
		~Parentheses() {
			delete exp;
		}

		int calc() {
			return exp->calc();
		}

};

class Add : public Binary {
	public:
		Add(Express *left, Express *right) : Binary(left, right) {
		}
		int calc() {
			return left->calc() + right->calc();
		}
};

class Sub : public Binary {
	public:
		Sub(Express *left, Express *right) : Binary(left, right) {}
		int calc() {
			return left->calc() - right->calc();
		}
};

class Mul : public Binary {
	public:
		Mul(Express *left, Express *right) : Binary(left, right) {}
		int calc() {
			return left->calc() * right->calc();
		}
};
class Div : public Binary {
	public:
		Div(Express *left, Express *right) : Binary(left, right) {}
		int calc() {
			return left->calc() / right->calc();
		}
};

class Value : public Express {
	int value;

	public:
	Value(int value) :value(value) {}
	int calc() {return value;}
	~Value() = default;
};
