#ifndef BIGRAMDYN_H
#define	BIGRAMDYN_H

#include <iostream>
#include <string>
#include <fstream>
#include "Bigram.h"
#include "myException.h"
using namespace std;

template<class T>
class BigramDyn: public Bigram<T>{

public:
	BigramDyn(int t);
	~BigramDyn(){delete [] myBigrams;}
	void readFile(string name);
	int numGrams ()const ;
	int numOfGrams(T x, T y)const;
	pair<T, T> maxGrams();
	void printBigrams(ostream& out)const;
	pair<T,T> getABigram(int index)const{return myBigrams[index];}	
	pair <T,T>* getBigrams() const{return myBigrams;}
	void setBigrams(int index,pair<T,T> val){myBigrams[index]=val;}
	int getTotal() const {return totalElements;}
	void setTotal(int value){totalElements=value;}
private:
string filename;
pair <T,T> *myBigrams;
int totalElements;
int data;
};

#endif
