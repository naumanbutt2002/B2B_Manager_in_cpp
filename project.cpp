#include <iostream>
#include <iomanip>

#include <conio.h>
#include <string>
#include <sstream>
#include <windows.h>
#include "animation.h"
#include "my_stack.h"
#include "my_queue.h"
#include "admin_manufac.h"
#include "admin_retail.h"
#include "customer.h"
int attempts1 = 0;
int attempts2 = 0;
using namespace std;
bool checkUsername_pass(string s)
{
	if (!s.empty())
	{

		for (int i = 0; i < s.length(); i++)
		{
			if (!((s.at(i) >= 'a' && s.at(i) <= 'z') || (s.at(i) >= 'A' && s.at(i) <= 'Z') && (s[i] >= '0' && s[i] <= '9') && (s.length() >= 8 && s.length() <= 16)))

			{

				return false;
			}
		}

		return true;
	}
}

void login1()
{
	while (attempts1 < 3)
	{
		int count = 0;
		string user, pass, u, p;
		char ch;
		system("cls");
		cout << "\nUSERNAME AND PASSWORD MUST CONTAIN ALPHABETS(CAPITAL OR SMALL) AND DIGITS OF LENGTH 8 TO 16." << endl
			 << endl;
	user1_label:
		cout << "ENTER USERNAME :";
		user = "";
		cin >> user;

		if (checkUsername_pass(user))
		{
			cout << "INVALID USERNAME" << endl;
			goto user1_label;
		}
		else
		{
		pass1_label:
			cout << "ENTER PASSWORD :";
			pass = "";
			while (ch != 17)
			{
				ch = getch();
				if (ch == '\b')
				{
					cout << "\b \b";
				}
				else if (ch == '\r')
				{
					cout << '\0';
					break;
				}
				else
				{
					pass.push_back(ch);
					cout << '*';
				}
			}

			if (checkUsername_pass(pass))
			{
				cout << "\nINVALID PASSWORD" << endl;
				goto pass1_label;
			}
			else
			{
				ifstream input("man_login.txt");

				input >> u >> p;
				if (u == user && p == pass)

				{
					count = 1;
					system("cls");
				}

				if (count == 1)
				{
					cout << "\nHELLO " << user << "\nLOGIN IS SUCESSFULL\nTHANKS FOR LOGGING IN...\n"
						 << endl;
					string check = "0";
					cout << "IF WANT TO CHANGE YOUR USERNAME AND PASSWORD\nPRESS 1\nIF NOT PRESS ANY INPUT\t" << endl;
					cin >> check;

					if (check == "1")
					{
						cout << "\nCHANGE USERNAME AND PASSWORD IMMEDIATELY FOR SECURE USE" << endl;
						cout << "PLEASE ENTER THE FOLLOWING DETAILS:-" << endl;
					user11_label:
						cout << "ENTER USERNAME :";
						user = "";
						cin >> u;
						if (checkUsername_pass(u))
						{
							cout << "INVALID USERNAME" << endl;
							goto user11_label;
						}
					pass11_label:
						cout << "ENTER PASSWORD :";
						pass = "";
						while (ch != 17)
						{
							ch = getch();
							if (ch == '\b')
							{
								cout << "\b \b";
							}
							else if (ch == '\r')
							{
								cout << '\0';
								break;
							}
							else
							{
								p.push_back(ch);
								cout << '*';
							}
						}
						if (checkUsername_pass(p))
						{
							cout << "\nINVALID PASSWORD" << endl;
							goto pass11_label;
						}

						ofstream change_pas("man_login.txt");
						change_pas << u << ' ' << p << endl;
					}
					else
					{
						cout << "OK YOUR LOGIN INFO WILL NOT BE CHANGED..." << endl;
					}
					system("pause");

					break;
				}
				else
				{
					cout << "\nLOGIN ERROR\nPlease check your username and password\n";
					attempts1++;

					cout << "\nATTEMPTS REMAINING " << 3 - attempts1 << "\n";
					system("pause");
				}

				input.close();
			}
		}
	}
	if (attempts1 >= 3)
	{
		cout << "\nOut of attempts, access denied." << endl;
	}
}
void login2()
{
	while (attempts2 < 3)
	{
		char ch;
		int count = 0;
		string user, pass, u, p;
		system("cls");
		cout << "\nUSERNAME AND PASSWORD MUST CONTAIN ALPHABETS(CAPITAL OR SMALL) AND DIGITS OF LENGTH 8 TO 16." << endl
			 << endl;
	user2_label:
		cout << "ENTER USERNAME :";
		user = "";
		cin >> user;
		if (checkUsername_pass(user))
		{
			cout << "INVALID USERNAME" << endl;
			goto user2_label;
		}
		else
		{
		pass2_label:
			cout << "ENTER PASSWORD :";
			pass = "";
			while (ch != 17)
			{
				ch = getch();
				if (ch == '\b')
				{
					cout << "\b \b";
				}
				else if (ch == '\r')
				{
					cout << '\0';
					break;
				}
				else
				{
					pass.push_back(ch);
					cout << '*';
				}
			}
			if (checkUsername_pass(pass))
			{
				cout << "\nINVALID PASSWORD" << endl;
				goto pass2_label;
			}
			else
			{
				ifstream input("retail_login.txt");

				input >> u >> p;
				if (u == user && p == pass)

				{
					count = 1;
					system("cls");
				}

				if (count == 1)
				{
					cout << "\nHello " << user << "\nLOGIN SUCESS\nWe're glad that you're here.\nThanks for logging in\n"
						 << endl;
					string check;
					cout << "IF WANT TO CHANGE YOUR USERNAME AND PASSWORD\nPRESS 1\nIF NOT PRESS ANY INPUT\t" << endl;
					cin >> check;

					if (check == "1")
					{
						cout << "\nCHANGE USERNAME AND PASSWORD IMMEDIATELY FOR SECURE USE" << endl;
						cout << "please enter the following details" << endl;
					user21_label:
						cout << "ENTER USERNAME :";
						user = "";
						cin >> u;
						if (checkUsername_pass(u))
						{
							cout << "INVALID USERNAME" << endl;
							goto user21_label;
						}
					pass21_label:
						cout << "ENTER PASSWORD :";
						pass = "";
						while (ch != 17)
						{
							ch = getch();
							if (ch == '\b')
							{
								cout << "\b \b";
							}
							else if (ch == '\r')
							{
								cout << '\0';
								break;
							}
							else
							{
								p.push_back(ch);
								cout << '*';
							}
						}
						if (checkUsername_pass(p))
						{
							cout << "\nINVALID PASSWORD" << endl;
							goto pass21_label;
						}

						ofstream change_pas("retail_login.txt");
						change_pas << u << ' ' << p << endl;
					}
					else
					{
						cout << "OK YOUR LOGIN INFO WILL NOT BE CHANGED..." << endl;
					}

					system("cls");
					break;
				}
				else
				{
					cout << "\nLOGIN ERROR\nPlease check your username and password\n";
					attempts2++;

					cout << "\nAttempts remaining: " << 3 - attempts2 << "\n";
					system("pause");
				}

				input.close();
			}
		}
	}
	if (attempts2 >= 3)
	{
		cout << "\nOut of attempts, access denied." << endl;
	}
}
void manufac_admin()
{
	ifstream reg;
	reg.open("man_login.txt");
	if (!reg)
	{
		string reguser = "manufac123", regpass = "password123";
		ofstream reg("man_login.txt", ios::app);
		reg << reguser << ' ' << regpass << endl;
	}
	 login1();
	ManufecturOrder man_obj;

	system("cls");
	string ch;

	do
	{

		//            choice for below message

		Sleep(300);
		cout << "\t\t===================================================" << endl;
		cout << "\t\t|                MANUFACTURER PANEL               |" << endl;
		cout << "\t\t===================================================" << endl;
		cout << "\t\t     PRESS 0 TO EXIT    " << endl;
		cout << "\t\t     PRESS 1 TO ADD A NEW RETAILER    " << endl;
		cout << "\t\t     PRESS 2 TO DISPLAY ALL REATAILERS RECORD  " << endl;
		cout << "\t\t     PRESS 3 TO MODIFY EXISTING RECORD" << endl;
		cout << "\t\t     PRESS 4 TO DELETE A PARTICULAR RECORD" << endl;
		cout << "\t\t     PRESS 5 TO SEARCH A PARTICULAR RECORD" << endl;

		cout << "\nEnter Your choice >>>";
		cin >> ch;
		if (ch == "1")
		{
			man_obj.RetailerDataInsertion();
			system("pause");
			system("cls");
		}
		else if (ch == "2")

		{
			man_obj.RetailerDataTRAVER();
			system("pause");
			system("cls");
		}

		
		else if (ch == "3")
		{
			man_obj.ModifyRetailerData();
			system("pause");
			system("cls");
		}
		else if (ch == "4")
		{
			man_obj.DeleteRetailerData();
			system("pause");
			system("cls");
		}
		else if (ch == "5")
		{
			man_obj.SearchRetailerData();
			system("pause");
			system("cls");
		}
		
		else if (ch == "0")
		{
			system("cls");
		}

		else
		{
			cout << "INVALID INPUT" << endl;
			system("pause");
			system("cls");
		}

	} while (ch != "0");
}

void retailer_admin()
{
	ifstream reg;
	reg.open("retail_login.txt");
	if (!reg)
	{
		string reguser = "retail123", regpass = "password123";
		ofstream reg("retail_login.txt", ios::app);
		reg << reguser << ' ' << regpass << endl;
	}
	 login2();
	RetailerCustomer retail_obj;
	Customer cus_obj;
	system("cls");
	string ch;
	ManufecturOrder man_obj;
	do
	{

		//            choice for below message

		Sleep(300);
		cout << "\t\t===================================================" << endl;
		cout << "\t\t|                    RETAILER PANEL               |" << endl;
		cout << "\t\t===================================================" << endl;
		cout << "\t\t     PRESS 0 TO EXIT    " << endl;
		cout << "\t\t     PRESS 1 TO VIEW RETAILER'S RECORDS    " << endl;
		cout << "\t\t     PRESS 2 TO ORDER PRODUCTS FROM MANUFACTURER  " << endl;
		cout << "\t\t     PRESS 3 TO SET PRODUCT'S PRICES FOR CUSTOMERS" << endl;
		cout << "\t\t     PRESS 4 TO VIEW CUSTOMERS RECORD" << endl;
		cout << "\t\t     PRESS 5 TO DELETE CUSTOMERS RECORD" << endl;
		cout << "\t\t     PRESS 6 TO VIEW CURRENT CUSTOMER RECORD" << endl;

		cout << "\nEnter Your choice >>>";
		cin >> ch;
		if (ch == "1")
		{
			retail_obj.RetailerDataTRAVER();
			system("pause");
			system("cls");
		}
		else if (ch == "2")

		{
			man_obj.RetailerDataTRAVER();
			retail_obj.RetailerDataInsertion();
			system("pause");
			system("cls");
		}
		else if (ch == "3")
		{
			retail_obj.setProfitandprice();
			system("pause");
			system("cls");
		}

		else if (ch == "4")
		{

			cus_obj.CustomerRecordView();
			system("pause");
			system("cls");
		}
		else if (ch == "5")
		{

			retail_obj.DeleteCustomerData();
			system("pause");
			system("cls");
		}
		else if (ch == "6")
		{

			displayQueue();
			system("pause");
			system("cls");
		}
		else if (ch == "0")
		{
			system("cls");
		}

		else
		{
			cout << "INVALID INPUT" << endl;
			system("pause");
			system("cls");
		}

	} while (ch != "0");
}
void main_admin_panel()
{
	system("cls");
	string ch;
	

	do
	{

		//            choice for below message

		Sleep(300);
		cout << "\t\t============================================" << endl;
		cout << "\t\t|               ADMIN PANEL                |" << endl;
		cout << "\t\t============================================" << endl;
		cout << "\t\t     PRESS 0 TO EXIT" << endl;
		cout << "\t\t     PRESS 1 FOR MANUFACTURER" << endl;
		cout << "\t\t     PRESS 2 FOR RETAILER" << endl;
		cout << "\nEnter Your choice >>>";
		cin >> ch;
		if (ch == "0")
		{
			system("cls");
		}
		else if (ch == "1")
		{
			manufac_admin();
			system("pause");
			system("cls");
		}
		else if (ch == "2")

		{
			retailer_admin();
			system("pause");
			system("cls");
		}

		else
		{
			cout << "INVALID INPUT" << endl;
			system("pause");
			system("cls");
		}

	} while (ch != "0");
}

void main_customer_panel()
{
	system("cls");
	string ch;

	do
	{

		//            choice for below message

		Sleep(300);
		cout << "\t\t============================================" << endl;
		cout << "\t\t|              CUSTOMER PANEL              |" << endl;
		cout << "\t\t============================================" << endl;
		cout << "\t\t     PRESS 0 TO EXIT" << endl;
		cout << "\t\t     PRESS 1 TO VIEW AVAILABLE PRODUCTS" << endl;
		cout << "\t\t     PRESS 2 TO BUY PRODUCTS" << endl;
		cout << "\nEnter Your choice >>>";
		cin >> ch;
		Customer cus_obj;
		if (ch == "0")
		{
			system("cls");
		}
		else if (ch == "1")
		{
			cus_obj.CustomerView();
			system("pause");
			system("cls");
		}
		else if (ch == "2")

		{
			cus_obj.CustomerView();
			bpop();
			cus_obj.orderToRetailer();
			system("pause");
			system("cls");
		}

		else
		{
			cout << "INVALID INPUT" << endl;
			system("pause");
			system("cls");
		}

	} while (ch != "0");
}

//        Main function
int main()
{
	for (int i = 0; i <= 51; i++)
	{

		push(i);
	}
		Sleep(300);
		//
		//  for console color
		gotoxy(60, 1);
		cout << "==================================================" << endl;
		gotoxy(60, 2);
		cout << "=                   B2B MANAGER                  =" << endl;
		gotoxy(60, 3);
		cout << "==================================================" << endl;
		Sleep(500);
		gotoxy(60, 6);
		cout << " PROJECT SUPERVISOR: ->> MS. Ayesha Rashid <<--   \n"
			 << endl;
		gotoxy(65, 8);
		cout << ">>>----Project Implemented By-----<<<" << endl;
		Sleep(500);
		gotoxy(66, 13);
		cout << "#-ROLL NUMBER    STUDENT NAME" << endl;
		Sleep(500);
		gotoxy(66, 15);
		cout << "20021519-051   MUHAMMAD YASEEN" << endl;
		Sleep(300);
		gotoxy(66, 17);
		cout << "20021519-090   MUHAMMAD NAUMAN" << endl;
		Sleep(300);
		gotoxy(66, 19);
		cout << "20021519-109   MUHAMMAD FAHAD" << endl;
		Sleep(300);
		gotoxy(66, 21);
		cout << "20021519-141   ASADULLAH NASEER" << endl
			 << endl;
		Sleep(300);
		gotoxy(60, 24);
		system("pause");
		system("cls");
	
		system("color 70");
		Sleep(100);
	
		string ch;
		do
		{
	
			//            choice for below message
			system("cls");
			cout << "\n\t\t|--------MAIN MENUS-----------|";
			cout << "\n\n";
			Sleep(200);
			cout << "\t\t 0=>EXIT\n";
			Sleep(200);
			cout << "\t\t 1=>ADMIN PANEL\n";
			Sleep(200);
			cout << "\t\t 2=>CUSTOMER PANEL\n";
			Sleep(200);
	
			cout << "\nENTER YOUR CHOICE= ";
			cin >> ch;
			if (ch == "0")
			{
				Sleep(150);
				cout << "\n\n\t\t\t\t\tThank You\t\t\t\t";
			}
	
			else if (ch == "1")
			{
	main_admin_panel();
			}
	
			else if (ch == "2")
			{
				main_customer_panel();
	
				system("pause");
			}
	
			else
			{
				Sleep(100);
				cout << "INVALID INPUT" << endl;
				system("pause");
				system("cls");
			}
	
		} while (ch != "0");

	return 0;
}
