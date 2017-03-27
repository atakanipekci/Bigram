#ifndef BIGRAMMAP_H
#define	BIGRAMMAP_H

#include <iostream>
#include <string>
#include <fstream>
#include "Bigram.h"
#include <map>
#include "myException.h"
using namespace std;

template<class T>
class BigramMap: public Bigram<T>{

public:
	/*Constructor that takes an integer to set the data type.
	  1 for int,2 for strings 3 for doubles*/
	BigramMap(int t);
	/*Reads elements from file*/
	void readFile(string name);
	/*Returns the total number of bigrams that are calculated*/
	int numGrams ()const ;
	/*Returns the occurance of a bigram that is taken as an input*/
	int numOfGrams(T x, T y)const;
	/*Returns the most common bigram*/
	pair<T, T> maxGrams();
	/*Used in << operator to print bigrams*/
	void printBigrams(ostream& out)const;
	/*Get and set functions for myBigrams*/	
	map <int ,pair <T,T>> getBigrams() const{return myBigrams;}
	void setBigrams(int index,pair<T,T> val){myBigrams[index]=val;}
private:
string filename;
map <int ,pair <T,T>> myBigrams;
int data;
};

#endif

