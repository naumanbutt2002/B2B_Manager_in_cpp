#include <iostream>
#include <iomanip>

#include <cstring>
#include <fstream>
using namespace std;
class RetailerCustomer : public ManufecturOrder
{
private:
	Manu *start, *current, *next;
	ifstream read2,read5;
	ofstream write2;
	string rn, mm, lm;
	unsigned int ma, la, ri, Invest;
	unsigned int lp, mp;
	int profit;
	bool found;
	bool correctinput = true;

public:
	RetailerCustomer()
	{
		start = current = next = NULL;
		lp = mp = 0;
		profit = 0;
	}

	
	void setProfitandprice()
	{
		string lmm="0",mmm="0";
		unsigned int nla,nlp,nma,nmp;
		cout << "Enter the Percentage of Profit: ";
		cin.ignore();


		profit_label1:
		cin >> profit;

			while (cin.fail())
			{

				cout << "\tINVALID INPUT\n\tEnter the Valid Percentage of Profit: ";
				cin.clear();
				cin.ignore(256, '\n');
				cin >> profit;
			}
			if (profit < 1)
			{
				cout << "\tINVALID INPUT\n\tEnter the Valid Percentage of Profit: ";
				goto profit_label1;
			}

		write2.open("RetailerCustomer_profit.txt", ios::app);

		int c = 0;
		cout << "\t\t\t\tAll the Devices Are Given Below:\n\n";
		read2.open("RetailerData.txt", ios::app);
		cout << "    "
			 << "ID         |     "
			 << "Laptop     |     "
			 << "Amount   |      "
			 << "Unit Price   |      "
			 << "Mobile     |      "
			 << "Amount     |     "
			 << "Unit Price       |      " << endl;
		cout << "_______________|________________|______________|___________________|_________________|_________________|______________________\n";

		while (read2 >> rn >> ri >> mm >> ma >> lm >> la >> Invest)
		{
			if(lmm!=lm)
			{
			write2 << setw(15)<< ri ;
			write2 << setw(15)<< lm;

			lmm=lm;
			lp = LaptopPrices(lm, 1);
			lp += (lp * profit) / 100;
			nla=la;
			nlp=lp;
			write2 << setw(15)<<la ;
			write2 << setw(15)<<lp;
			}

			else 
			{
			write2 <<setw(15)<< lm ;

			lp = LaptopPrices(lm, 1);
			lp += (lp * profit) / 100;
			write2 <<setw(15)<< nla+la ;
			write2 <<setw(15)<< nlp+lp ;
			
			}
			if(mmm!=mm)
			{
			
			write2 <<setw(15)<< mm;

				mmm=mm;
			mp = MobilePrices(mm, 1);
			mp += (mp * profit) / 100;
			nma=ma;
			nmp=mp;
			write2 <<setw(15)<< ma ;
			write2 << setw(15)<<mp << endl;
			c++;
			}
			else
			{
						write2 << setw(15)<<mm ;

			mp = MobilePrices(mm, 1);
			mp += (mp * profit) / 100;

			write2 << setw(15)<<nma+ma ;
			write2 << setw(15)<<nmp+mp <<endl;
			}
			cout <<setw(10) << ri <<setw(15) << lm << setw(15)<< la <<setw(15)<< lp <<setw(20)<< mm <<setw(18)<< ma << setw(20)<< mp << endl;
			cout << "_______________|________________|______________|___________________|_________________|_________________|______________________|" << endl;
			
		}
		cout << "\nTotal products  is / are : " << c << "\n\n";
		read2.close();
		write2.close();
	}
	
	void CustomerView()
	{
		int c = 0;
		cout << "\t\t\t\tAll the Devices Are Given Below:\n\n";
		read2.open("RetailerCustomer_profit.txt", ios::app);
		cout << "    "
			 << "Laptop     |     "
			 << "Amount   |      "
			 << "Unit Price   |      "
			 << "Mobile     |      "
			 << "Amount     |     "
			 << "Unit Price          |      " << endl;
		cout << "_______________|______________|___________________|_________________|_________________|__________________________\n";

		while (read2  >> ri >>lm >> la>> lp>> mm >> ma  >> mp)
		{
			
			cout  << lm << setw(20)<< la << setw(20)<< lp <<setw(20)<< mm <<setw(20)<< ma <<setw(22)<< mp << endl;
			cout << "_______________|______________|___________________|_________________|_________________|_________________________|" << endl;
			c++;
		}
		cout << "\nTotal products in our store is / are : " << c << "\n\n";
		read2.close();
	}

	void DeleteCustomerData()
	{
		ReadFile();
		

		ofstream write3;
		string key;
		found = false;
		cout << "EXISTING PRODUCTS RECORD LIST:-" << endl
			 << endl;
		
		cout << "Enter the Customer Name You want to DELETE: ";
		cin.ignore();
		cin >> key;

		while (cin.fail())
		{

			cout << "\tINVALID ID\n\tEnter the Valid Customer Name you want to Delete: ";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> key;
		}
		
		read5.open("CustomerData.txt", ios::app);
		write3.open("CustomerData2.txt", ios::app);

		
		while (read5 >> rn  >> mm >> ma  >> Invest)
		{
			if (rn == key)
			{
				cout <<"\nCustomer Data is Deleted of NAME "<<rn;
				cout<<endl<<endl;
				found = true;
			}
			else
			{
				write3 << rn << setw(25);
				write3 << mm << setw(25);
				write3 << ma << setw(25);
				write3 << Invest << endl;
			}
		}
		if (found == false)
		{
			cout << "Customer Name is not Found\n\n";
		}

		read5.close();
		write3.close();
		remove("CustomerData.txt");
		rename("CustomerData2.txt", "CustomerData.txt");
		ReadFile();
	}
};
