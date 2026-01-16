/*
============================================================================
Name        : main.cpp
Author      : Group 2
Subject     : Object Oriented Programming with CPP
Batch       : B2
Description : Mini Project
============================================================================
*/


#include <iostream>
#include <string>


using namespace std;

int bk = 0, supp = 0, pur = 0, emp = 0, mem = 0;

// CLASSES

class books {
	public:
		int id;
		string name;
		string author;
		int price;
		int qty;

		void add();
		bool verifyBook(int);
		void update_price();
		void search();
		void display();
};

books book[20];

class suppliers {
	public:
		int id;
		string name;
		long phn;
		string addr_line1;
		string addr_line2;
		string addr_city;
		string addr_state;

		void add_sup();
		bool verifySupplier(int);
		void search_id();
		void view();
};
suppliers supplier[20];

class purchases {
	public:
		int ord_id;
		int book_id;
		int sup_id;
		int qty;
		int eta;

		bool verifyPurchase(int);
		void new_ord();
		void view();
};
purchases purchase[20];

class employees {
	public:
		int id;				//Primary Key
		string name;
		string addr_line1;
		string addr_line2;
		string addr_city;
		string addr_state;
		long phn;
		long salary;

		bool verifyEmployee(int);
		void add_emp();
		void search_emp();
		void display();
		void update_sal();
};
employees employee[20];

class members {
	public:
		int id;
		string name;
		string addr_line1;
		string addr_line2;
		string addr_city;
		string addr_state;
		long phn;

		void add_mem();
		bool verifyMember(int);
		void search_mem();
		void display();
};
members member[20];


// CLASS FUNCTIONS
bool books::verifyBook(int id) {
	for (int i = 0; i < bk; i++) {
		if(book[i].id == id) {
			return false;
		}
	}
	return true;
}
void books::add() {

	char c;
	int bid;
	do {
		cout << endl << "Enter the Unique id of the book : " << flush;
		setbuf(stdout, NULL);
		cin >> bid;
		if(verifyBook(bid) == false) {
			cout << endl << "Book already Registered" << endl << flush;
		}
		else {
			book[bk].id = bid;
			cout << "Enter the name of the book:" << flush;
			setbuf(stdout, NULL);
			cin >> book[bk].name;
			cout << "Enter the name of the author: " << flush;
			setbuf(stdout, NULL);
			cin >> book[bk].author;
			cout << "Enter the Price : " << flush;
			setbuf(stdout, NULL);
			cin >> book[bk].price;
			cout << "Enter the Qty Received : " << flush;
			setbuf(stdout, NULL);
			cin >> book[bk].qty;

			bk++;
		}

		cout << "Enter y to add another book: " << flush;
		setbuf(stdout, NULL);
		cin >> c;
	}while(c == 'y' || c == 'Y');
}

void books::update_price(){
    cout << "Enter the id of the book for update in price : " << flush;
    setbuf(stdout, NULL);
    cin >> id;

    int j, p;

    for (p = 0; p <= bk; p++) {

    	if(book[p].id == id) {
    		j = p;
            cout << "The Name of the book is : " << book[p].name << endl << flush;
            cout << "The current price of the book is : " << book[p].price << endl << flush;
            cout << "Do you Want to Update the Price [y/n] : " << flush;
            char choice;
        	cin >> choice;

    		if (choice == 'y' || choice == 'Y') {
    			cout << "Enter the new price : " << flush;
    			setbuf(stdout, NULL);
    			cin >> book[p].price;
        		cout << endl << "Book Price Updated Successfully" << endl << endl << endl << flush;
    		}
    		else {
    			cout << "No changes Made!!" << endl << endl << flush;
    		}

    		break;
    	}
    }

    try {
    	if(j != p){
    		throw "No book found";
    	}
    }

    catch(const char *msg) {
    	cout << endl << msg << endl << endl << flush;
    }
}

void books::search() {
	cout << "Enter book id for details : " << flush;
	setbuf(stdout, NULL);
	cin >> id;

	int p, j;

    for (p = 0; p <= bk; p++) {

    	if(book[p].id == id) {
    		j = p;
    		cout << "The Unique id of the book is : " << book[p].id << endl << flush;
            cout << "The Name of the book is : " << book[p].name << endl << flush;
            cout << "The Author of the book is : " << book[p].author << endl << flush;
            cout << "The Price of the book is : " << book[p].price << endl << flush;
            cout << "Number of available copies : " << book[p].qty << endl << flush;

    		break;
    	}
    }

    try {
    	if(j != p){
    		throw "No book found";
    	}
    }

    catch(const char *msg) {
    	cout << endl << msg << endl << endl << flush;
    }
}

void books::display()
{
	int p = 0;

	for (p = 0; p < bk; p++) {
		cout << endl << "Book " << p + 1 << endl << flush;
		cout << "The Unique id of the book is : " << book[p].id << endl << flush;
        cout << "The Name of the book is : " << book[p].name << endl << flush;
        cout << "The Author of the book is : " << book[p].author << endl << flush;
        cout << "The Price of the book is : " << book[p].price << endl << flush;
        cout << "Number of available copies : " << book[p].qty << endl << flush;
	}
}


bool suppliers::verifySupplier(int sid){
	for(int i = 0; i < supp; i++) {
		if(supplier[i].id == id) {
			return false;
		}
	}
	return true;
}

void suppliers::add_sup() {

	char c;
	int sid;
	do {
		cout << endl << "Enter the Supplier id : " << flush;
		setbuf(stdout, NULL);
		cin >> sid;
		if(verifySupplier(sid) == false) {
			cout << endl << "Supplier already Registered" << endl << flush;
		}
		else {
			supplier[supp].id = sid;
			cout << "Enter the Supplier Name : " << flush;
			setbuf(stdout, NULL);
			cin >> supplier[supp].name;
			cout << "Enter Phone no. : " << flush;
			setbuf(stdout, NULL);
			cin >> supplier[supp].phn;
			cout << "Enter the address (in 3 lines) : " << flush;
			setbuf(stdout, NULL);
			cin >> supplier[supp].addr_line1;
			cin >> supplier[supp].addr_line2;
			cin >> supplier[supp].addr_city;
			cout << "Enter State : " << flush;
			setbuf(stdout, NULL);
			cin >> supplier[supp].addr_state;

			supp++;
		}
		cout << "Enter y to add another supplier:" << flush;
		setbuf(stdout, NULL);
		cin >> c;
	}while(c == 'y' || c == 'Y');
}


void suppliers::search_id()
{
	cout << "Enter the supplier id to find the Supplier details : " << flush;
	setbuf(stdout, NULL);
	cin >>  id;

	int p, j;

    for (p = 0; p <= supp; p++) {

    	if(supplier[p].id == id) {
    		j = p;
    		cout << "The Unique id of the supplier is : " << supplier[p].id << endl << flush;
            cout << "The Name of the supplier is : " << supplier[p].name << endl << flush;
            cout << "The Phone Number of the supplier is : " << supplier[p].phn << endl<< flush;
            cout << "The Address of the supplier is : " << supplier[p].addr_line1 << ", " << supplier[p].addr_line2 << ", " << supplier[p].addr_city << ", " << supplier[p].addr_state << endl << flush;

    		break;
    	}
    }

    try {
    	if(j != p){
    		throw "Record not found";
    	}
    }

    catch(const char *msg) {
    	cout << endl << msg << endl << endl << flush;
    }
}

void suppliers::view() {

	for(int p = 0; p < supp; p++) {
		cout << endl << "Supplier " << p + 1 << endl << flush;
		cout << "The Unique id of the supplier is : " << supplier[p].id << endl << flush;
        cout << "The Name of the supplier is : " << supplier[p].name << endl << flush;
        cout << "The Phone Number of the supplier is : " << supplier[p].phn << endl<< flush;
        cout << "The Address of the supplier is : " << supplier[p].addr_line1 << ", " << supplier[p].addr_line2 << ", " << supplier[p].addr_city << ", " << supplier[p].addr_state << endl << flush;
	}
}


bool purchases::verifyPurchase(int pid){
	for(int i = 0; i < pur; i++) {
		if(purchase[i].ord_id == pid) {
			return false;
		}
	}
	return true;
}

void purchases::new_ord() {

	char c;
	int pid;
	do {
		cout << endl << "Enter the order Id : " << flush;
		setbuf(stdout, NULL);
		cin >> pid;

		if(verifyPurchase(pid) == false) {
			cout << endl << "Purchase already Registered" << endl << flush;
		}
		else{
			purchase[pur].ord_id = pid;
			cout << "Enter the Book Id : " << flush;
			setbuf(stdout, NULL);
			cin >> purchase[pur].book_id;
			cout << "Enter Supplier Id : " << flush;
			setbuf(stdout, NULL);
			cin >> sup_id;
			cout << "Enter the Quantity : " << flush;
			setbuf(stdout, NULL);
			cin >> qty;
			cout << "Estimated expected Delivery (in days) : " << flush;
			setbuf(stdout, NULL);
			cin >> eta;

			pur++;
		}

		cout << "Enter y to add another purchase:" << flush;
		setbuf(stdout, NULL);
		cin >> c;
	}while(c == 'y' || c == 'Y');
}

void purchases::view() {

	int i;
	for(i = 0; i < pur; i++) {
		cout << endl << "Order " << i+1 << endl << flush;
		cout << "Order ID: " << purchase[i].ord_id << endl << flush;
		cout << "Book ID:" << purchase[i].book_id << endl << flush;
		cout << "Supplier ID: " << purchase[i].sup_id << endl << flush;
		cout << "Quantity: " << purchase[i].sup_id << endl << flush;
		cout << "Delivery in: " << purchase[i].eta << " days" << endl << flush;
	}
}


bool employees::verifyEmployee(int eid){
	for(int i = 0; i < emp; i++) {
		if(employee[i].id == eid) {
			return false;
		}
	}
	return true;
}

void employees::add_emp() {

	char c;
	int eid;
	do {
		cout << endl << "Enter the Employee Id: " << flush;
		setbuf(stdout, NULL);
		cin >> eid;

		if(verifyEmployee(eid) == false) {
			cout << endl << "Employee already Registered" << endl << flush;
		}
		else {
			employee[emp] = eid;
			cout << "Enter the Employee Name : " << flush;
			setbuf(stdout, NULL);
			cin >> employee[emp].name;
			cout << "Enter Phone no. : " << flush;
			setbuf(stdout, NULL);
			cin >> employee[emp].phn;
			cout << "Enter the address (in 3 lines) : " << flush;
			setbuf(stdout, NULL);
			cin >> employee[emp].addr_line1;
			cin >> employee[emp].addr_line2;
			cin >> employee[emp].addr_city;
			cout << "Enter State : " << flush;
			setbuf(stdout, NULL);
			cin >> employee[emp].addr_state;
			cout << "Enter Employee Salary: " << flush;
			setbuf(stdout, NULL);
			cin >> employee[emp].salary;

			emp++;
		}

		cout << "Enter y to add another employee:" << flush;
		setbuf(stdout, NULL);
		cin >> c;
	} while(c == 'y' || c == 'Y');
}

void employees::search_emp()
{
	cout << "Enter the id for searching an employee : " << flush;
	setbuf(stdout, NULL);
	cin >> id;

	int j, p;
    for (p = 0; p <= emp; p++) {

    	if(employee[p].id == id) {
    		j = p;
    		cout << "Employee ID: " << employee[p].id << endl << flush;
            cout << "Employee Name: " << employee[p].name << endl << flush;
            cout << "Employee Number: " << employee[p].phn << endl << flush;
            cout << "Employee Address: " << employee[p].addr_line1 << ", " << employee[p].addr_line2 << ", " << employee[p].addr_city << ", " << employee[p].addr_state << endl << flush;
            cout << "Employee Salary: " << employee[p].salary << endl << flush;

    		break;
    	}
    }

    try {
    	if(j != p){
    		throw "Record not found";
    	}
    }

    catch(const char *msg) {
    	cout << endl << msg << endl << endl << flush;
    }
}

void employees::display() {

	int i;
	for(i = 0; i < emp; i++) {
		cout << endl << "Employee " << i+1 << endl << flush;
		cout << "Employee ID: " << employee[i].id << endl << flush;
        cout << "Employee Name: " << employee[i].name << endl << flush;
        cout << "Employee Number: " << employee[i].phn << endl << flush;
        cout << "Employee Address: " << employee[i].addr_line1 << ", " << employee[i].addr_line2 << ", " << employee[i].addr_city << ", " << employee[i].addr_state << endl << flush;
        cout << "Employee Salary: " << employee[i].salary << endl << flush;
	}
}

void employees::update_sal() {

    cout << "Enter the id of the employee for update in salary : " << flush;
    setbuf(stdout, NULL);
    cin >> id;

    int j, p;

    for (p = 0; p <= emp; p++) {

    	if(employee[p].id == id) {
    		j = p;
            cout << "The Name of the employee is : " << employee[p].name << endl << flush;
            cout << "The current salary of the employee is : " << employee[p].salary << endl << flush;
            cout << "Do you Want to Update the Salary [y/n] : " << flush;
            setbuf(stdout, NULL);
            char choice;
        	cin >> choice;

    		if (choice == 'y' || choice == 'Y') {
    			cout << "Enter the new salary : " << flush;
    			setbuf(stdout, NULL);
    			cin >> employee[p].salary;
        		cout << endl << "Employee Salary Updated Successfully" << endl << endl << endl << flush;
    		}
    		else {
    			cout << "No changes Made!!" << endl << endl << flush;
    		}

    		break;
    	}
    }

    try {
    	if(j != p){
    		throw "Record not found";
    	}
    }

    catch(const char *msg) {
    	cout << endl << msg << endl << endl << flush;
    }
}


bool members::verifyMember(int mid){
	for(int i = 0; i < mem; i++) {
		if(member[i].id == mid) {
			return false;
		}
	}
	return true;
}

void members::add_mem() {

	char c;
	int mid;
	do {
		cout << endl << "Enter the Id of the member" << flush;
		setbuf(stdout, NULL);
		cin >> member[mem].id;

		if(verifyMember(mid) == false) {
			cout << endl << "Member already Registered" << endl << flush;
		}
		else {
			member[mem].id = mid;
			cout << "Enter the name of the member:" << flush;
			setbuf(stdout, NULL);
			cin >> member[mem].name;
			cout << "Enter phone no. : " << flush;
			setbuf(stdout, NULL);
			cin >> member[mem].phn;
			cout << "Enter address (in 3 lines)" << endl << flush;
			setbuf(stdout, NULL);
			cin >> member[mem].addr_line1;
			cin >> member[mem].addr_line2;
			cin >> member[mem].addr_city;
			cout << "Enter the name of the state : " << flush;
			setbuf(stdout, NULL);
			cin >> member[mem].addr_state;

			mem++;
		}
		cout << "Enter y to add another member:" << flush;
		setbuf(stdout, NULL);
		cin >> c;
	}while(c == 'y' || c == 'Y');
}

void members::search_mem() {

	cout << "Enter member id for details : " << flush;
	setbuf(stdout, NULL);
	cin >> id;

	int p, j;

    for (p = 0; p <= mem; p++) {

    	if(member[p].id == id) {
    		j = p;
    		cout << "The Unique id of the member is : " << member[p].id << endl << flush;
    		cout << "The Name of the member is : " << member[p].name << endl << flush;
    		cout << "The Phone Number of the member is : " << member[p].phn << endl << flush;
    		cout << "The Address of the supplier is : " << member[p].addr_line1 << ", " << member[p].addr_line2 << ", " << member[p].addr_city << ", " << member[p].addr_state << endl << flush;
    		break;
    	}
    }

    try {
    	if(j != p){
    		throw "Record not found";
    	}
    }

    catch(const char *msg) {
    	cout << endl << msg << endl << endl << flush;
    }
}

void members::display() {
	for(int p = 0; p < mem; p++) {
		cout << endl << "Member " << p+1 << endl << flush;
		cout << "The Unique id of the member is : " << member[p].id << endl << flush;
		cout << "The Name of the member is : " << member[p].name << endl << flush;
		cout << "The Phone Number of the member is : " << member[p].phn << endl << flush;
		cout << "The Address of the supplier is : " << member[p].addr_line1 << ", " << member[p].addr_line2 << ", " << member[p].addr_city << ", " << member[p].addr_state << endl << flush;
	}
}


// MENU FUNCTIONS
void book_menu();
void sup_menu();
void pur_menu();
void emp_menu();
void mem_menu();

// main menu

void main_menu()
{
	int c;
	cout << endl << flush;
	cout << "*************************************************" << endl << flush;
	cout << "         LIBRARY MANGEMENT SYSTEM" << endl << flush;
	cout << "*************************************************" << endl << flush;
	cout << "   1. BOOKS" << endl << flush;
	cout << "   2. SUPPLIERS" << endl << flush;
	cout << "   3. PURCHASES" << endl << flush;
	cout << "   4. EMPLOYEES" << endl << flush;
	cout << "   5. MEMBERS" << endl << flush;
	cout << "   6. EXIT" << endl << endl << flush;
	cout << "Enter Your Choice : " << flush;
	setbuf(stdout, NULL);
	cin >> c;

	switch (c)
	{
		case 1:
			system("cls");
			book_menu();
			break;

		case 2:
			system("cls");
			sup_menu();
			break;

		case 3:
			system("cls");
			pur_menu();
			break;

		case 4:
			system("cls");
			emp_menu();
			break;

		case 5:
			system("cls");
			mem_menu();
			break;

		case 6:
			exit(1);

		default:
			system("cls");
			cout << "Wrong Input" << endl << endl << "Invalid input";
			break;
	}
	return;
}

// book menu

void book_menu()
{
	int c;
	cout << "*************************************************" << endl << flush;
	cout << "                  BOOK MENU" << endl << flush;
	cout << "*************************************************" << endl << flush;
	cout << "   1. ADD" << endl << flush;
	cout << "   2. UPDATE PRICE" << endl << flush;
	cout << "   3. SEARCH" << endl << flush;
	cout << "   4. DISPLAY ALL" << endl << flush;
	cout << "   5. RETURN TO MAIN MENU" << endl << endl << endl << flush;
	cout << "Enter Your Choice : " << flush;
	setbuf(stdout, NULL);
	cin >> c;

	switch (c){
		case 1:
			book[bk].add();
			break;
		case 2:
			book[bk].update_price();
			break;
		case 3:
			book[bk].search();
			break;
		case 4:
			book[bk].display();
			break;
		case 5:
			return;
			break;
		default:
			cout << "Wrong Input" << endl << "Invalid input" << flush;
			break;
	}
	return;
}

// supp menu

void sup_menu()
{
	int c;
	cout << "*************************************************" << endl << flush;
	cout << "                SUPPLIER MENU" << endl << flush;
	cout << "*************************************************" << endl <<flush;
	cout << "   1. ADD" << endl << flush;
	cout << "   2. SEARCH" << endl << flush;
	cout << "   3. DISPLAY" << endl << flush;
	cout << "   4. RETURN TO MAIN MENU" << endl << endl << endl << flush;
	cout << "Enter Your Choice : " << flush;
	setbuf(stdout, NULL);
	cin >> c;

	switch (c)
	{
		case 1:
			supplier[supp].add_sup();
			break;
		case 2:
			supplier[supp].search_id();
			break;
		case 3:
			supplier[supp].view();
			break;
		case 4:
			return;
		default:
			cout << "Wrong Input" << endl << "Invalid input";
			break;
	}
}

// purchase menu

void pur_menu()
{
	int c;
	cout << "*************************************************" << endl << flush;
	cout << "                PURCHASES MENU" << endl << flush;
	cout << "*************************************************" << endl << flush;
	cout << "   1. New Order" << endl << flush;
	cout << "   2. View All" << endl << flush;
	cout << "   3. RETURN TO MAIN MENU" << endl << endl << endl << flush;
	cout << "Enter Your Choice : " << flush;
	setbuf(stdout, NULL);
	cin >> c;

	switch (c)
	{
		case 1:
			purchase[pur].new_ord();
			break;
		case 2:
			purchase[pur].view();
			break;
		case 3:
			return;
		default:
			cout << "Wrong Input" << endl << "Invalid input";
			break;
	}
}

// emp_menu

void emp_menu()
{
	int c;
	cout << "*************************************************" << endl << flush;
	cout << "                 EMPLOYEE MENU" << endl << flush;
	cout << "*************************************************" << endl << flush;
	cout << "   1. New Employee" << endl << flush;
	cout << "   2. Search Employee" << endl << flush;
	cout << "   3. View All" << endl << flush;
	cout << "   4. Update Salary" << endl << flush;
	cout << "   5. RETURN TO MAIN MENU" << endl << endl << endl << flush;
	cout << "Enter Your Choice : " << flush;
	setbuf(stdout, NULL);
	cin >> c;

	switch (c)
	{
		case 1:
			employee[emp].add_emp();
			break;
		case 2:
			employee[emp].search_emp();
			break;

		case 3:
			employee[emp].display();
			break;
		case 4:
			employee[emp].update_sal();
			break;
		case 5:
			return;
		default:
			cout << "Wrong Input" << endl << "Invalid input" << flush;
			break;
	}
}


// mem menu

void mem_menu()
{
	int c;
	cout << "*************************************************" << endl << flush;
	cout << "                 MEMBERS MENU" << endl << flush;
	cout << "*************************************************" << endl << flush;
	cout << "   1. New Member" << endl << flush;
	cout << "   2. Search Member" << endl << flush;
	cout << "   3. Display Members" << endl << flush;
	cout << "   4. RETURN TO MAIN MENU" << endl << endl << endl << flush;
	cout << "Enter Your Choice : " << flush;
	setbuf(stdout, NULL);
	cin >> c;

	switch (c)
	{
		case 1:
			member[mem].add_mem();
			break;
		case 2:
			member[mem].search_mem();
			break;
		case 3:
			member[mem].display();
			break;
		case 4:
			return;
		default:
			cout << "Wrong Input" << endl << "Invalid input" << flush;
			break;
	}
}


int main() {

	while(1) {
		system("cls");
		main_menu();
	}

	return 0;
}
