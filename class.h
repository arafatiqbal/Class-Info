//Arafat Iqbal
//FIle for BST
//CS202
//Program 3

//File for the classes that are used in this program

#ifndef H_bst
#define H_bst

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <cctype>
#include <cstring>

const int MAX = 100;

using namespace std;

class info
{
	public:
		info();
		info(char * category,int number);
		info(const info & to_copy);
		virtual ~info();

		void display();
		void insert();
	
		char * get_category();
		int get_number();
		
		//Operator Overloading Functions

		//Compare to see where to insert
		bool operator <(const info & p) const;
	
		friend ostream& operator <<(ostream & out,info & p);
		friend istream& operator >>(istream & go, info & p);

	protected:		
		
		//Virtual display and insert
		virtual void display(ostream & out) = 0;
		virtual void insert(istream & go) = 0;
	
		//Data Members of Class Info
		char * category;
		int number;

};

class zoom:public info
{
	public:
		zoom();
		zoom(char * category,int number, char * date,char * url);
		zoom(const zoom & to_copy);
		~zoom();
		
	protected:

		char * date;
		char * url;

		void insert(istream & go);		
		void display(ostream & out);

};

class project:public info
{

	public:
		project();
		project(char * category,int number,char * assignment);
		project(const project & to_copy);
		~project();
	protected:

		char * assignment;

		void insert(istream & go);		
		void display(ostream & out);
};

class lecture:public info
{
	public:
		lecture();
		lecture(char * category,int number,char * topic,int length);
		lecture(const lecture & to_copy);
		~lecture();

	protected:

		char * topic;
		int length;

		void insert(istream & go);		
		void display(ostream & out);
};
#endif
