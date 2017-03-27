#include "BigramDyn.h"
/*Does the same thing as BigramMap without using map.*/
/*The algorithms are not going to be explained here because they are already explained in BigramMap.*/
template <class T>
BigramDyn<T> ::BigramDyn(int t){
totalElements=0;
data = t;
myBigrams = NULL;
}

template <class T>
void BigramDyn<T> :: readFile(string name){
	int i =0,flag=0,flag2=0,count=0,count2=0;
	T temp1,temp2,temp3;
	string temp4;
	ifstream inputFile(name);

	
	if(inputFile.is_open())
    {
		while(inputFile>>temp4)
		{
			count++;
			setTotal(getTotal()+1);

		
			
			
		}
	
		if(count<2)
		throw myException("There is not enough elements in file to create a bigram");	
	}

	else
	throw myException("File not found");
	

	myBigrams= new pair<T,T>[getTotal()-1];
	inputFile.clear();
	inputFile.seekg(0, inputFile.beg);
	
	
	if(inputFile.is_open())
    {
		while(inputFile>>temp1)
		{count2++;
				
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

	if(count != count2)
	throw myException("The file contains wrong types of data");
			

	inputFile.close();

	
	}

	/*cout << "Read File" << endl;
	for (int i=0; i<getTotal()-1; i++ )
	{
		cout<<i<<"//"<<getABigram(i).first<<","<<getABigram(i).second<<endl; 
			
	}*/
}





template <class T>
int BigramDyn<T> :: numGrams ()const {

return getTotal()-1;
}

template <class T>
int BigramDyn<T> :: numOfGrams(T x, T y)const {
int count=0,i;
	for (i=0; i<getTotal()-1; i++ )
	{
		if(getABigram(i).first == x && getABigram(i).second == y)
			count++;
	}

return count;
}


template <class T>
pair<T, T> BigramDyn<T> :: maxGrams(){
int max=0,i,j;
int temp;

pair<T,T> common;	
for (i=0; i<getTotal()-1; i++)
	{
		temp=0;
		for(j=0; j<getTotal()-1; j++)
		{
			if(getABigram(i).first == getABigram(j).first && getABigram(i).second == getABigram(j).second)
			{
				temp++;
						
			}
		if(temp > max)
		{
			common=getABigram(i);
			max = temp;
		}
		}
		
	}

return common;
}
template <class T>
void BigramDyn<T> :: printBigrams(ostream& out)const{
pair <T,T>* temp = new pair<T,T>[getTotal()-1];
pair <T,T>* temp2 = new pair<T,T>[getTotal()-1];
pair <T,T> t;
int flag,i,j;
	
temp=myBigrams;

	for (i=0; i<getTotal()-1; i++)
	{
	temp[i]=getABigram(i);
	}
	

	for (i=0; i<getTotal()-1; i++)
	{
		
		for(j=0; j<getTotal()-1-1; j++)
		{
			if(numOfGrams(temp[j].first, temp[j].second) < numOfGrams(temp[j+1].first, temp[j+1].second) )
			{
				t=temp[j];
				temp[j] = temp[j+1];
				temp[j+1] = t;
						
			}
		
		
		}
		
	}
	
	
	/*for (i=0; i<getTotal()-1; i++)
	{
	cout<<"("<<getABigram(i).first<<","<<getABigram(i).second<<")"<<"occured "<<numOfGrams(getABigram(i).first, getABigram(i).second)<<"times." <<endl; 
	}*/
	

	for (i=0; i<getTotal()-1; i++)
	{
    	flag=0;
		for (j=0; j<getTotal()-1-1; j++)
		{
					
			if(temp[i].first==temp2[j].first && temp[i].second==temp2[j].second)
			
			{
				
				flag=1;	
			}
		
		}

		if(flag != 1)
		{
			cout<<"("<<getABigram(i).first<<","<<getABigram(i).second<<")"<<"occured "<<numOfGrams(getABigram(i).first, getABigram(i).second)<<" times." <<endl; 
		}	
		temp2[i] = temp[i];	
			
	}

}










