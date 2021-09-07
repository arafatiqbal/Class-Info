//Arafat Iqbal
//Main File
//CS202 
//Program 3

//This file is the main file or the user interface,
//All functions are called from this file

#include "class.h"
#include "bst.h"

using namespace std;

int main()
{
	//Menu Variables
	int option = 0;
	int choice = 0;

	//Temp variables
	int len = 0;
	int num = 0;

	char temp[MAX];
	char temp2[MAX];
	char temp3[MAX];

	//Class objects
	bst the_tree;
	node the_node;

	//Reading in from file	
	ifstream file;
	file.open("info.txt");

	//If FIle empty	
	if(!file)
	{
		cout << "Error" << endl;
	}	
	else
	{
		cout << "Reading in..." << endl;
	}
	//While its in the file and there are items
	while(file >> option)
	{
		if(choice == 1)	
		{
			//Reading in Category
			file.ignore();
			file.getline(temp,100,',');
			file.ignore(100,',');
			
			//Reading in number
			file >> num;
			file.ignore(100,',');
	
			//Reading in date
			file.getline(temp2,100,',');
			file.ignore(100,',');

			//Reading in url
			file.getline(temp3,100,',');
			file.ignore(100,',');

			zoom my_zoom(temp,num,temp2,temp3);
			the_tree.input(&my_zoom);	
		}
		if(choice == 2)
		{
			//Reading in category
			file.ignore();
			file.getline(temp,100,',');
			file.ignore(100,',');

			//Reading in number
			file >> num;
			file.ignore(100,',');
	
			//Reading in assignment	
			file.getline(temp2,100,',');
			file.ignore(100,',');
			project my_project(temp,num,temp2);
			the_tree.input(&my_project);			
		}

		if(choice == 3)
		{
			//Reading in category
			file.ignore();
			file.getline(temp,100,',');
			file.ignore(100,',');

			//Reading in number
			file >> num;
			file.ignore(100,',');	

			//Reading in topic
			file.getline(temp2,100,',');
			file.ignore(100,',');

			//Reading in length	
			file >> len;
			file.ignore(100,',');
			lecture my_lecture(temp,num,temp2,len);
			the_tree.input(&my_lecture);
		}
	}
	//Make sure it read in 100%
	cout << "Reading in Complete! 100%" << endl;
	file.close();

	//Menu for inserting after reading in
	int menu = 0;
	do
	{
		cout<<" " <<endl;
		cout<<"Welcome!" <<endl;
		cout<<"Select Option Below: " << endl <<endl;
		cout<<"\t1 - Add " <<endl;
		cout<<"\t2 -  " <<endl;
		cout<<"\t3 - "<<endl;
		cout<<"\t4 - Display" << endl;
		cout<<"\t5 - Exit "<<endl <<endl;

		cout<<"Menu Option : ";
		cin>>menu; //Read in from the user

		if(menu == 1)
		{
			option = 0;
			//Add More Information in/ Update Thigns
			cout << "What would you like to add?" << endl;
			cout << "\t1 - Zoom Meeting Info" << endl;
			cout << "\t2 - Homework Info" << endl;
			cout << "\t3 - Lecture Info" << endl;
			
			//Read in option		
			cin >> option;
			cin.ignore(100,'\n');

			if(option == 1)
			{
				//Creates Object,and uses operator overloading
				//To Insert

				//Getting a seg fault when inserting?? 
				//Memory leak somewhere can't find it...
				zoom the_zoom;
				cin >> the_zoom;
				the_tree.input(&the_zoom);		

			}
			else if(option == 2)
			{
				//Creates Object,and uses operator overloading
				//To Insert
				project the_project;
				cin >> the_project;
				the_tree.input(&the_project);	

			}
			else if(option == 3)
			{
				//Creates Object,and uses operator overloading
				//To Insert
				lecture the_lecture;
				cin >> the_lecture;
				the_tree.input(&the_lecture);

			}
		}

		if(menu == 2)
		{

		}

		if(menu == 3)
		{

		}

		if(menu == 4)
		{
			the_tree.display();
		}

	}
	while(menu != 5);

	return 1;
}

