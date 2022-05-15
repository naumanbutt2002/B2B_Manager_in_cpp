// #include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;



class Customer : public RetailerCustomer
{
private:
	Manu *start, *current, *next;
	ifstream read3,read5,read6;
	ofstream write3,write5;

	string mm, lm,cn;
	unsigned int ma, la, ri;
	unsigned int lp, mp;
	ManufecturOrder temp;



public:
	Customer()
	{
		start = current = next = NULL;
	}

	void orderToRetailer()
	{
		string Pname;
		string cusname, check,pay;
		// ofstream write4;
		int price_bill,new_price_bill;

		bool cus_found = true;
		int price;
		cout << "Enter  NAME OF PRODUCT THAT YOU WANNA BUY: ";

		cin >> Pname;

		// write4.open(RetailerCustomer_profit.txt", ios::app);
		read3.open("RetailerCustomer_profit.txt", ios::app);
		while (read3 >> ri >> lm >> la >> lp >> mm >> ma >> mp)
		{
			if (Pname == lm || Pname == mm)
			{
				cus_found = false;
				break;
			}
		}
		if (cus_found == true)
		{
			cout << "The Name of Product you Entered is Invalid\n\n";
		}
		else
		{
			system("cls");
			CustomerView();
			write3.open("CustomerData.txt", ios::app);

			if (start == NULL)
			{
				next = new Manu;
				// next->RetailerID = cusID;
				cout << "Enter YOUR NAME: ";
				cin.ignore();
				cin >> cusname;
				while (checkString(cusname))
				{
					cout << "\t\tINVALID NAME\n\t\tEnter Your Valid Name: ";
					cin >> cusname;
				}

				next->RetailerName = cusname;

				

				write3 << next->RetailerName << " \t\t";
				if (Pname == mm)
				{
					next->MobileModle = mm;
					cout << "ENTER THE NO OF MOBILES YOU WANT TO BUY: ";

					cin.ignore();
				cus_mob_label1:
					cin >> next->MobileAmount;
					while (cin.fail())
					{

						cout << "\tINVALID AMOUNT\n\tEnter the Valid Number of Mobiles You Want To Buy: ";
						cin.clear();
						cin.ignore(256, '\n');
						cin >> next->MobileAmount;
					}
					if (next->MobileAmount < 1)
					{
						cout << "\tINVALID AMOUNT\n\tEnter the Valid Number of Mobiles You Want To Buy: ";
						goto cus_mob_label1;
					}
					
					ma -= next->MobileAmount;
					write3 << next->MobileModle << " \t\t";
					write3 << next->MobileAmount << " \t\t";
					price = mp * next->MobileAmount;
					read3.close();
					write3 << price << "\n";
					enqueue(cusname,next->MobileModle,next->MobileAmount,price);
				}
				else
				{
					next->LaptopModle = lm;
					cout << "ENTER THE NO OF LAPTOPS YOU WANT TO BUY: ";
					cin.ignore();
				cus_lap_label1:
					cin >> next->LaptopAmount;
					while (cin.fail())
					{

						cout << "\tINVALID AMOUNT\n\tEnter the Valid Number of Laptops You Want To Buy: ";
						cin.clear();
						cin.ignore(256, '\n');
						cin >> next->LaptopAmount;
					}
					if (next->LaptopAmount < 1)
					{
						cout << "\tINVALID AMOUNT\n\tEnter the Valid Number of Laptops You Want To Buy: ";
						goto cus_lap_label1;
					}

					la -= next->LaptopAmount;
					write3 << next->LaptopModle << " \t\t";
					write3 << next->LaptopAmount << " \t\t";
					price = lp * next->LaptopAmount;
					read3.close();
					write3 << price << "\n";
					enqueue(cusname,next->LaptopModle,next->LaptopAmount,price);

				}
				next->Nptr = NULL;
				next->Pptr = NULL;
				current = next;
				start = next;
			}
			else
			{
				next = new Manu;
				cout << "Enter YOUR NAME: ";
				cin.ignore();
				cin >> cusname;
				while (checkString(cusname))
				{
					cout << "\t\tINVALID NAME\n\t\tEnter Your Valid Name: ";
					cin >> cusname;
				}

				next->RetailerName = cusname;


				write3 << next->RetailerName << " \t\t";
				if (Pname == mm)
				{
					next->MobileModle = mm;
					cout << "ENTER THE NO OF MOBILES YOU WANT TO BUY: ";

					cin.ignore();
				cus_mob_label2:
					cin >> next->MobileAmount;
					while (cin.fail())
					{

						cout << "\tINVALID AMOUNT\n\tEnter the Valid Number of Mobiles You Want To Buy: ";
						cin.clear();
						cin.ignore(256, '\n');
						cin >> next->MobileAmount;
					}
					if (next->MobileAmount < 1)
					{
						cout << "\tINVALID AMOUNT\n\tEnter the Valid Number of Mobiles You Want To Buy: ";
						goto cus_mob_label2;
					}

					ma -= next->MobileAmount;
					write3 << next->MobileModle << " \t\t";
					write3 << next->MobileAmount << " \t\t";
					price = mp * next->MobileAmount;
					read3.close();
					write3 << price << "\n";
					enqueue(cusname,next->MobileModle,next->MobileAmount,price);

				}
				else
				{
					next->LaptopModle = lm;
					cout << "ENTER THE NO OF LAPTOPS YOU WANT TO BUY: ";
					cin.ignore();
				cus_lap_label2:
					cin >> next->LaptopAmount;
					while (cin.fail())
					{

						cout << "\tINVALID AMOUNT\n\tEnter the Valid Number of Laptops You Want To Buy: ";
						cin.clear();
						cin.ignore(256, '\n');
						cin >> next->LaptopAmount;
					}
					if (next->LaptopAmount < 1)
					{
						cout << "\tINVALID AMOUNT\n\tEnter the Valid Number of Laptops You Want To Buy: ";
						goto cus_lap_label2;
					}

					la -= next->LaptopAmount;
					write3 << next->LaptopModle << " \t\t";
					write3 << next->LaptopAmount << " \t\t";
					price = lp * next->LaptopAmount;
					read3.close();
					write3 << price << "\n";
					enqueue(cusname,next->LaptopModle,next->LaptopAmount,price);

				}
				next->Nptr = NULL;
				next->Pptr = current;
				current->Nptr = next;
				current = next;
			}
			write3.close();

			cout << "\n\n\t\t BILL SUMMARY\n";
			cout << "\n\t=> Customer Name:  " << cusname << endl;
			cout << "\t=> Device:  \t" << Pname << endl;
			cout << "\t=> Price:  \t" << price << endl<< endl;

			cout << "ENTER THE PRICE TO GET PRODUCTS= "; 
			
			
			cin.ignore();
		cus_price_label1:
			cin >>price_bill;
			while (cin.fail())
			{

				cout << "\tINVALID PRICE\n\tEnter the Valid PRICE to PAY: ";
				cin.clear();
				cin.ignore(256, '\n');
				cin >> price_bill;
			}
			if (price_bill < 1)
			{
				cout << "\tINVALID PRICE\n\tEnter the Valid PRICE to PAY: ";
				goto cus_price_label1;
			}
			
			
			if (price_bill >= price)
			{

				if (price_bill == price)
				{
					cout << "\nYOUR ORDER IS CONFIRMED..." << endl;
				}
				if (price_bill > price)
				{
					cout << "YOUR ORDER IS CONFIRMED..." << endl;
					cout << "AND YOUR REMAINNIG BALANCE IS= "<< price_bill - price << endl;
				}
				cout << "\nNOTE:: If You Want To Get the Receipt (Hard Form)" << endl;
			print_receipt:
				cout << "\nPRESS 1 TO CONT\nPRESS 0 FOR NOT\t\t" << endl
					 << endl;
				cin >> check;
				if (check == "1")
				{
					write3.open("Print_receipt.txt");

					write3 << "\n\n\t\t BILL SUMMARY\n";
					write3 << "\n\t=> Customer Name:  " << cusname << endl;
					write3 << "\t=> Device:  \t" << Pname << endl;
					write3 << "\t=> Price:  \t" << price << endl
						   << endl;
					write3.close();
					cout << "\tPRINTING RECEIPT..." << endl;

					system("notepad /p  Print_receipt.txt");
				}

				else if (check == "0")
				{
				}
				else
				{
					cout << "INVALID INPUT" << endl;
					goto print_receipt;
				}
				remove("Print_receipt.txt");
			}
		
		else
		{
			cout << "\nSORRY YOUR ORDER IS NOT CONFIRMED..." << endl;
			cout << "YOU HAVE TO PAY " << price - price_bill << " MORE..." << endl;
			cout << "\nPRESS 1 TO PAY\nPRESS 0 TO NOT\t\t" << endl;
			cin >> pay;

			if (pay == "1")
			{	
				do
				{
					cout << "\nENTER THE REMAINING PRICE TO GET PRODUCTS (Neither more Nor less)= ";
					cin.ignore();
		cus_price_label2:
			cin >>new_price_bill;
			while (cin.fail())
			{

				cout << "\tINVALID PRICE\n\tEnter the Valid PRICE to PAY: ";
				cin.clear();
				cin.ignore(256, '\n');
				cin >> new_price_bill;
			}
			if (new_price_bill < 1)
			{
				cout << "\tINVALID PRICE\n\tEnter the Valid PRICE to PAY: ";
				goto cus_price_label2;
			}
				
				}while(new_price_bill!=price - price_bill);
				
				
				cout << "\nNOTE:: If You Want To Get the Receipt (Hard Form)" << endl;
			print_receipt2:
				cout << "\nPRESS 1 TO CONT\nPRESS 0 FOR NOT\t\t" << endl
					 << endl;
				cin >> check;
				if (check == "1")
				{
					write3.open("Print_receipt.txt");

					write3 << "\n\n\t\t BILL SUMMARY\n";
					write3 << "\n\t=> Customer Name:  " << cusname << endl;
					write3 << "\t=> Device:  \t" << Pname << endl;
					write3 << "\t=> Price:  \t" << price << endl<< endl;
					write3.close();
					cout << "\tPRINTING RECEIPT..." << endl;

					system("notepad /p  Print_receipt.txt");
				}

				else if (check == "0")
				{
				}
				else
				{
					cout << "INVALID INPUT" << endl;
					goto print_receipt2;
				}
				remove("Print_receipt.txt");
			
		
			}
		else if (pay == "0")

		{
		}
		else
		{
			cout << "INVALID INPUT" << endl;
		}
	}
}
}

void CustomerRecordView()
	{
		cout << "\t\t\t\tAll the Customer's Records Are Given Below:\n\n";
		read6.open("CustomerData.txt", ios::app);
		cout << "    "
			 << "Laptop     |     "
			 << "Amount   |      "
			 << "Mobile       |      "
			 << "Amount     |     "<<endl;
		cout << "_______________|______________|___________________|_________________|\n";

		while (read6  >>cn >>  mm >> ma  >> mp)
		{
			
			cout  << cn << setw(23)<< mm << setw(15)<< ma <<setw(20)<< mp <<endl;
			cout << "_______________|______________|___________________|_________________|" << endl;
		}
		read6.close();
	}




};
