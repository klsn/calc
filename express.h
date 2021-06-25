
#pragma once

#include <iostream>

class Express {

	public:
		virtual int calc() {return 0;}
		virtual ~Express() {}
};

class BinaryExpress : public Express {
	protected:Express *left, *right;

	public:
		  BinaryExpress(Express *left, Express *right) : left(left), right(right) {}
		  ~BinaryExpress() {
			  delete left;
			  delete right;
		  }
};

class AddExp : public BinaryExpress {
	public:
		AddExp(Express *left, Express *right) : BinaryExpress(left, right) {
		}
		int calc() {
			return left->calc() + right->calc();
		}
};

class SubExp : public BinaryExpress {
	public:
		SubExp(Express *left, Express *right) : BinaryExpress(left, right) {}
		int calc() {
			return left->calc() - right->calc();
		}
};

class MulExp : public BinaryExpress {
	public:
		MulExp(Express *left, Express *right) : BinaryExpress(left, right) {}
		int calc() {
			return left->calc() * right->calc();
		}
};
class DivExp : public BinaryExpress {
	public:
		DivExp(Express *left, Express *right) : BinaryExpress(left, right) {}
		int calc() {
			return left->calc() / right->calc();
		}
};

class ValueExp : public Express {
	int value;

	public:
	ValueExp(int value) :value(value) {}
	int calc() {return value;}
	~ValueExp() = default;
};
