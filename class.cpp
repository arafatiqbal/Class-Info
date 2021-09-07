//Arafat Iqbal
//Functions for my classes.
//All functions stored in the class.h file.

#include "class.h"

//Info Functions
info::info():category(nullptr),number(0)
{


}
info::info(char * category,int number)
{
	this->category = new char[strlen(category)+1];
	strcpy(this->category,category);
	
	this->number = number;
}
info::info(const info & to_copy)
{
	category = new char[strlen(to_copy.category)+1];
	strcpy(category,to_copy.category);

	number = to_copy.number;	
}
info::~info()
{
	delete [] category;
	category = NULL;
	
	number = 0;
}
//getters
char * info:: get_category()
{
	return this->category;
}
int info:: get_number()
{
	return this->number;
}
bool info::operator <(const info & p) const
{
	return strcmp(this->category,p.category);
}
istream & operator >> (istream & go, info & p)
{
	p.insert(go);
	return go;
} 
ostream & operator << (ostream & out, info & p)
{
	p.display(out);
	return out;
}
//Display Function
void info::display()
{
	cout << "\tCategory: " << this->category << endl;
	cout << "\tCategory Number: " << this->number << endl;
	return;
}
void info::insert()
{

}
//Zoom Functions
zoom::zoom():date(nullptr),url(nullptr)
{

}
zoom::zoom(char * category,int number,char * date,char * url):info(category,number)
{
	this->date = new char[strlen(date)+1];
	strcpy(this->date,date);	

	this->url = new char[strlen(url)+1];
	strcpy(this->url,url);		
}
zoom::zoom(const zoom & to_copy):info(to_copy)
{
	date = new char[strlen(to_copy.date)+1];
	strcpy(date,to_copy.date);

	url = new char[strlen(to_copy.url)+1];
	strcpy(url,to_copy.url);
}
zoom::~zoom()
{
	delete date;
	date = NULL;

	delete url;
	url = NULL;
}
//Zoom Display Function
void zoom::display(ostream& out)
{
	info::display();
	out << "\tThe Date of Meeting: " << this->date << endl;
	out << "\tMeeting URL: " << this->url << endl;
	return;
}
//Zoom insert Function
void zoom::insert(istream & go)
{
	char the_category[MAX];
	char the_date[MAX]; 
	char the_url[MAX];
	int num = 0;

	cout << "What's the Category?: " << endl;
	go.get(the_category,100,'\n');
	go.ignore(100,'\n');

	this->category = new char[strlen(the_category) + 1];
	strcpy(this->category,the_category);
	
	cout << "Enter The Category Number: " << endl;
	go >> num;
	go.ignore();
	this->number = num;

	cout << "Enter In The Date of Meeting: " << endl;	
	go.get(the_date,100,'\n');
	go.ignore(100,'\n');
	this->date = new char[strlen(the_date) + 1];
	strcpy(this->date,the_date);

	cout << "Enter In The Meeting URL: " << endl;
	go.get(the_url,100,'\n');
	go.ignore(100, '\n');
	this->url = new char[strlen(the_url) + 1];
	strcpy(this->url,the_url);
	
	ofstream file;
	file.open("info.txt");
	file<<1<<','<< this->category<<','<<this->number<<','<<this->date<<','<<this->url<<endl;
	file.close();

}
//Homework Functions
project::project():assignment(nullptr)
{

}
project::project(char * category,int number,char * assignment):info(category,number)
{
	this->assignment = new char[strlen(assignment)+1];
	strcpy(this->assignment,assignment);	

}
project::project(const project & to_copy):info(to_copy)
{
	assignment = new char[strlen(to_copy.assignment)+1];
	strcpy(assignment,to_copy.assignment);

}
project::~project()
{
	delete assignment;
	assignment = NULL;
}
//Display Homework
void project::display(ostream & out)
{
	info::display();
	out << "\tThe Assignment Description: " << this->assignment << endl;
	return;
}
//Insert Homework
void project::insert(istream & go)
{
	char the_category[MAX];
	char the_assignment[MAX];
	int num = 0;

	cout << "What's the Category?: " << endl;
	go.get(the_category,100,'\n');
	go.ignore(100,'\n');

	this->category = new char[strlen(the_category) + 1];
	strcpy(this->category,the_category);
	
	cout << "Enter The Category Number: " << endl;
	go >> num;
	go.ignore();
	this->number = num;

	cout << "Enter In The Assignment Description: " << endl;	
	go.get(the_assignment,100,'\n');
	go.ignore(100,'\n');
	this->assignment = new char[strlen(the_assignment) + 1];
	strcpy(this->assignment,the_assignment);

	ofstream file;
	file.open("info.txt",ios::app);
	file<<2<<','<< this->category<<','<<this->number<<','<<this->assignment<<endl;
	file.close();
	
}
//Lecture functions
lecture::lecture():topic(nullptr),length(0)
{

}
lecture::lecture(char * category,int number, char * topic,int length):info(category,number)
{
	this->topic = new char[strlen(topic)+1];
	strcpy(this->topic,topic);
	
	this->length = length;	

}
lecture::lecture(const lecture & to_copy):info(to_copy)
{
	topic = new char[strlen(to_copy.topic)+1];
	strcpy(topic,to_copy.topic);
	
	length = to_copy.length;
}
lecture::~lecture()
{
	delete topic;
	topic = NULL;
	
	length = 0;
}
//Lecture Display function
void lecture::display(ostream & out)
{
	info::display();
	out << "\tThe Lecture Topic: " << this->topic << endl;
	out << "\tThe Length Of Video: " << this->length << endl;
	return;
}
//Lecture Insert Function
void lecture::insert(istream & go)
{
	char the_category[MAX];
	char the_topic[MAX]; 
	int num = 0;
	int len = 0;
	cout << "What's the Category?: " << endl;
	go.get(the_category,100,'\n');
	go.ignore(100,'\n');

	this->category = new char[strlen(the_category) + 1];
	strcpy(this->category,the_category);
	
	cout << "Enter The Category Number: " << endl;
	go >> num;
	go.ignore();
	this->number = num;

	cout << "Enter In The Lecture Topic " << endl;	
	go.get(the_topic,100,'\n');
	go.ignore(100,'\n');
	this->topic = new char[strlen(the_topic) + 1];
	strcpy(this->topic,the_topic);

	cout << "Enter The Lecture Video Length: " << endl;
	go >> len;
	go.ignore();
	this->length = len;

	ofstream file;
	file.open("info.txt");
	file<<2<<','<< this->category<<','<<this->number<<','<<this->topic<<','<<this->length<<endl;
	file.close();
		
}
