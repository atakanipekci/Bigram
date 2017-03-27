#include "BigramMap.h"

//Function explanations are made in the .h file */
template <class T>
BigramMap<T> ::BigramMap(int t){

data=t;

}

template <class T>
void BigramMap<T> :: readFile(string name){
	int i =0,flag=0,flag2=0,count=0,count2=0;
	T temp1,temp2,temp3;
	string temp4;
	ifstream inputFile(name);
/*First taking all the elements to a string variable. This way we can read all
of them no matter the type. Stores the amount of elements in count*/
	if(inputFile.is_open())
    {
		while(inputFile>>temp4)
		{
			count++;
			
			
		}
		if(count<2)
		throw myException("There is not enough elements in file to create a bigram");	

	
	}

	else
	throw myException("File not found");
	/*Going back to the start of the file to actually read and store this time*/
	inputFile.clear();
	inputFile.seekg(0, inputFile.beg);

	if(inputFile.is_open())
    {
		while(inputFile>>temp1)
		{
			count2++;
				
			if(flag ==0)
			{
				flag=1;
				temp2=temp1;
			}			
			else
			{
				if(flag2 == 0)
				{
				
				setBigrams(i,make_pair(temp2,temp1));
				temp3=temp1;
				
				flag2=1;
				i++;
				}
				else
				{
				
				setBigrams(i,make_pair(temp3,temp1));
				temp2=temp3;
				temp3=temp1;
				i++;

				}
			}
			}

	/*If the amount we read to our T type variable is not the same as the one we
	read to our string variable then it means the file contains atleast 1 wrong
	type of data. Which is accepted as an exception*/
	if(count != count2)
	throw myException("The file contains wrong types of data");	

	inputFile.close();

	
	}

	
}





template <class T>
int BigramMap<T> :: numGrams ()const {

return getBigrams().size();
}

template <class T>
int BigramMap<T> :: numOfGrams(T x, T y)const {
int count=0;
	for (auto &t : getBigrams())	/*Basically an iterator search in a loop but auto makes it a lot easier. */
	{
		if(t.second.first == x && t.second.second == y)
			count++;
	}

return count;
}


template <class T>
pair<T, T> BigramMap<T> :: maxGrams(){
int max=0;
int temp;

pair<T,T> common;	
for (auto &t : getBigrams())
	{
		temp=0;
		for(auto &t2 : getBigrams())
		{
			if(t.second.first == t2.second.first && t.second.second == t2.second.second)
			{
				temp++;
						
			}
		if(temp > max)
		{
			common=t.second;
			max = temp;
		}
		}
		
	}

return common;
}
template <class T>
void BigramMap<T> :: printBigrams(ostream& out)const{
multimap <int ,pair <T,T>,greater<int>> temp;
multimap <int ,pair <T,T>,greater<int>> temp2;
int flag;
	for (auto &t : getBigrams())
	{
		int count=0;
		for(auto &t2 : getBigrams())/*Stores the occurance amount of a bigram in count*/
		{
			if(t.second.first == t2.second.first && t.second.second == t2.second.second)
			{
				count++;
						
			}
		
		
		}/*Inserting the bigram with its occurance amount to a temporary map*/
		temp.insert(pair<int, pair<T,T>>(count, t.second));
	}
	
	
/*The loop below checks if the bigram in temp exists in temp2. If not it prints it and adds it to temp2.
If it already exists then it means there is more then one of the same bigram so it doesn't prints it again*/
	for (auto &t3 : temp)
	{
    	flag=0;
		for (auto &t4 : temp2)
		{
					
			
			if(t3.second.first == t4.second.first && t3.second.second == t4.second.second)
			{
				
				flag=1;	
			}
		
		}

		if(flag != 1)
		{
		out << '(' << t3.second.first <<','<< t3.second.second <<')'<<"occured "<<t3.first<<" times."<< "\n";
		}		
		temp2.insert(pair<int, pair<T,T>>(t3.first, t3.second));	
	}

}










