#ifndef WORD_H_
#define WORD_H_

#include<vector>

#include "Card.h"

using std::vector;

class Word: public Card{
private:
	string word;
	vector<string> trans;
	void add();
public:
	Word(int id);
	~Word();
	virtual int print_test();
	virtual void print();
	virtual void init();
	virtual void option();
};

#endif /* WORD_H_ */