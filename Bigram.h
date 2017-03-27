/*Created by Taha Atakan İpekçi on 23.12.2016*/
/*Pure abstract class for bigrams*/
#ifndef BIGRAM_H
#define	BIGRAM_H

#include <iostream>
#include <string>

using namespace std;
template<class T>
class Bigram{

public:
	virtual void readFile(string name)=0;
	virtual int numGrams ()const =0;
	virtual int numOfGrams(T x, T y)const=0;
	virtual pair<T, T> maxGrams()=0;
	virtual void printBigrams(ostream& out)const=0;
	friend ostream& operator <<(ostream& out, const Bigram& bigram)
	{
	bigram.printBigrams(out);
	return out;
	}
};

#endif
