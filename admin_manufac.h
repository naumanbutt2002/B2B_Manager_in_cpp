#include <iostream>
#include <iomanip>

#include <cstring>
#include <fstream>
using namespace std;
struct Manu
{
	string RetailerName;
	string MobileModle, LaptopModle;
	unsigned int MobileAmount, LaptopAmount;
	unsigned int RetailerID;
	long int Investment = 0;
	Manu *Nptr, *Pptr;
};
class ManufecturOrder
{
private:
	Manu *start, *current, *next;
	string rn, mm, lm;
	unsigned int ma, la, ri;
	bool found;
	int Invest, keyID;
	int counter=0;
	;
	ifstream read;
	ofstream write;
	bool correctinput = true;
	string mobile_models[10] = {"A72", "A22", "A20", "A30", "A52","S72", "S22", "S20", "S30", "S52"};
	string laptop_models[10] = {"Corei2", "Pent4", "Corei3", "Corei4", "Corei5","Corei6", "Corei7", "Corei8", "Corei9", "Corei10"};

public:
	ManufecturOrder()
	{
		start = current = next = NULL;
	}
	bool checkString(string s)
	{
		if (!s.empty())
		{
			for (int i = 0; i < s.length(); i++)
			{
				if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) || (s[i] == ' '))
				{
					return true;
				}
			}
		}
		return false;
	}
	bool check_number(int no)
	{
		if (no <= 0)
			return false;
		return true;
	}

	void ReadFile()
	{	

		start = NULL;
		read.open("RetailerData.txt");
		while (read >> rn >> ri >> mm >> ma >> lm >> la >> Invest)
		{
			if (start == NULL)
			{
				next = new Manu;
				next->RetailerName = rn;
				next->RetailerID = ri;
				next->MobileModle = mm;
				next->MobileAmount = ma;
				next->LaptopModle = lm;
				next->LaptopAmount = la;
				next->Investment = Invest;
				next->Nptr = NULL;
				next->Pptr = NULL;
				current = next;
				start = next;
			}
			else
			{
				next = new Manu;
				next->RetailerName = rn;
				next->RetailerID = ri;
				next->MobileModle = mm;
				next->MobileAmount = ma;
				next->LaptopModle = lm;
				next->LaptopAmount = la;
				next->Investment = Invest;
				next->Nptr = NULL;
				next->Pptr = current;
				current->Nptr = next;
				current = next;
			}
			counter++;
		}
		read.close();
	}

	int MobilePrices(string MbMD, int amount)
	{
		if (MbMD == mobile_models[0])
		{
			correctinput = true;
			return amount * 50000;
		}
		else if (MbMD == mobile_models[1])
		{
			correctinput = true;
			return amount * 40000;
		}
		else if (MbMD == mobile_models[2])
		{
			correctinput = true;
			return amount * 200000;
		}
		else if (MbMD == mobile_models[3])
		{
			correctinput = true;
			return amount * 40000;
		}
		else if (MbMD == mobile_models[4])
		{
			correctinput = true;
			return amount * 100000;
		}
		else if (MbMD == mobile_models[5])
		{
			correctinput = true;
			return amount * 50000;
		}
		else if (MbMD == mobile_models[6])
		{
			correctinput = true;
			return amount * 200000;
		}
		else if (MbMD == mobile_models[7])
		{
			correctinput = true;
			return amount * 30000;
		}
		else if (MbMD == mobile_models[8])
		{
			correctinput = true;
			return amount * 200000;
		}
		else if (MbMD == mobile_models[9])
		{
			correctinput = true;
			return amount * 100000;
		}
		else
		{
			// cout << "Mobile Model Does Not Exit\n\n";
			correctinput = false;
			return 0;
		}
	}
	int LaptopPrices(string LpMD, int amount)
	{
		if (LpMD == laptop_models[0])
		{
			correctinput = true;
			return amount * 50000;
		}
		else if (LpMD == laptop_models[1])
		{
			correctinput = true;
			return amount * 60000;
		}
		else if (LpMD == laptop_models[2])
		{
			correctinput = true;
			return amount * 75000;
		}
		else if (LpMD == laptop_models[3])
		{
			correctinput = true;
			return amount * 60000;
		}
		else if (LpMD == laptop_models[4])
		{
			correctinput = true;
			return amount * 85000;
		}
		else if (LpMD == laptop_models[5])
		{
			correctinput = true;
			return amount * 60000;
		}
		else if (LpMD == laptop_models[6])
		{
			correctinput = true;
			return amount * 75000;
		}
		else if (LpMD == laptop_models[7])
		{
			correctinput = true;
			return amount * 72000;
		}
		else if (LpMD == laptop_models[8])
		{
			correctinput = true;
			return amount * 100000;
		}
		else if (LpMD == laptop_models[9])
		{
			correctinput = true;
			return amount * 95000;
		}
		else
		{
			// cout << "Laptop Model Does Not Exit\n\n";
			correctinput = false;
			return 0;
		}
	}
	void show_available_items()
	{
		cout << "\n\tMOBILES THAT ARE AVAILABLE ARE:-" << endl;
		for (int i = 0; i < 10; i++)
		{
			cout << mobile_models[i] << "   ";
		}
		cout << endl
			 << endl;
		cout << "\tLAPTOPS THAT ARE AVAILABLE ARE:-" << endl;
		for (int i = 0; i < 10; i++)
		{
			cout << laptop_models[i] << "   ";
		}
		cout << endl
			 << endl;
	}
	void RetailerDataInsertion()
	{
		string check;
		bool id_found = false;
		bool id_found2 = false;

		ReadFile();
		write.open("RetailerData.txt", ios::app);
		show_available_items();
		if (start == NULL)
		{
			next = new Manu;
			cout << "\nEnter the Name of New Retailer: ";
			cin.ignore();
			cin >> next->RetailerName;
			while (checkString(next->RetailerName))
			{
				cout << "\t\tINVALID NAME\n\t\tEnter the Valid Name of New Retailer: ";
				cin >> next->RetailerName;
			}
			write << next->RetailerName << setw(25);

			cout << "Enter the ID of New Retailer: ";
			cin.ignore();
		ret_id_label1:
			cin >> next->RetailerID;
			id_found = false;

			while (cin.fail())
			{

				cout << "\tINVALID ID\n\tEnter the Valid ID of New Retailer: ";
				cin.clear();
				cin.ignore(256, '\n');
				cin >> next->RetailerID;
			}
			if (next->RetailerID < 1)
			{
				cout << "\tINVALID ID\n\tEnter the Valid ID of New Retailer: ";
				goto ret_id_label1;
			}
			read.open("RetailerData.txt", ios::app);
			while (read >> rn >> ri >> mm >> ma >> lm >> la >> Invest)
			{
				if (ri == next->RetailerID)
				{
					id_found = true;
					break;
				}
			}
			read.close();

			if (id_found == true)
			{
				cout << endl
					 << next->RetailerID << "\tIS ALREADY EXIST!\n\nEnter the Valid ID of New Retailer: ";
				goto ret_id_label1;
			}

			write << next->RetailerID << setw(25);
		mobile_insert1:
			cout << "\nPRESS 1 TO BUY MOBILES\nPRESS 0 FOR NOT\n\t\t";
			cin >> check;
			if (check == "1")
			{
				cout << "Enter Mobile Model: ";
				cin >> next->MobileModle;
				cout << "Enter the Number of Mobiles Retailer Bought: ";

				cin.ignore();
			mob_label1:
				cin >> next->MobileAmount;
				while (cin.fail())
				{

					cout << "\tINVALID AMOUNT\n\tEnter the Valid Number of Mobiles Retailer Bought: ";
					cin.clear();
					cin.ignore(256, '\n');
					cin >> next->MobileAmount;
				}
				if (next->MobileAmount < 1)
				{
					cout << "\tINVALID AMOUNT\n\tEnter the Valid Number of Mobiles Retailer Bought: ";
					goto mob_label1;
				}

				next->Investment += MobilePrices(next->MobileModle, next->MobileAmount);
				if (correctinput == true)
				{
					write << next->MobileModle << setw(25) << next->MobileAmount << setw(25);
				}
				else
				{
					next->MobileModle = "NIL";
					next->MobileAmount = 0;
					write << next->MobileModle << setw(25) << next->MobileAmount << setw(25);
				}
			}

			else if (check == "0")
			{
			}
			else
			{
				cout << "INVALID INPUT" << endl;
				goto mobile_insert1;
			}

		lap_insert1:
			cout << "\nPRESS 1 TO BUY LAPTOPS\nPRESS 0 FOR NOT\n\t\t";
			cin >> check;
			if (check == "1")
			{
				cout << "\n\nEnter Laptop Model: ";
				cin >> next->LaptopModle;
				cout << "Enter the Number of Laptop Retailer Bought: ";
				cin.ignore();
			lap_label1:
				cin >> next->LaptopAmount;
				while (cin.fail())
				{

					cout << "\tINVALID AMOUNT\n\tEnter the Valid Number of Laptops Retailer Bought: ";
					cin.clear();
					cin.ignore(256, '\n');
					cin >> next->LaptopAmount;
				}
				if (next->LaptopAmount < 1)
				{
					cout << "\tINVALID AMOUNT\n\tEnter the Valid Number of Laptops Retailer Bought: ";
					goto lap_label1;
				}

				next->Investment += LaptopPrices(next->LaptopModle, next->LaptopAmount);
				if (correctinput == true)
				{
					write << next->LaptopModle << setw(25) << next->LaptopAmount << setw(25);
				}
				else
				{
					next->LaptopModle = "NIL";
					next->LaptopAmount = 0;
					write << next->LaptopModle << setw(25) << next->LaptopAmount << setw(25);
				}
			}
			else if (check == "0")
			{
			}
			else
			{
				cout << "INVALID INPUT" << endl;
				goto lap_insert1;
			}

			write << next->Investment << endl;

			next->Nptr = NULL;
			next->Pptr = NULL;
			current = next;
			start = next;
		}
		else
		{
			next = new Manu;
			cout << "\nEnter the Name of New Retailer: ";
			cin.ignore();
			cin >> next->RetailerName;
			while (checkString(next->RetailerName))
			{
				cout << "\t\tINVALID NAME\n\t\tEnter the Valid Name of New Retailer: ";
				cin >> next->RetailerName;
			}
			write << next->RetailerName << setw(25);

			cout << "Enter the ID of New Retailer: ";
			cin.ignore();
		ret_id_label2:
			cin >> next->RetailerID;
			id_found2 = false;
			while (cin.fail())
			{

				cout << "\tINVALID ID\n\tEnter the Valid ID of New Retailer: ";
				cin.clear();
				cin.ignore(256, '\n');
				cin >> next->RetailerID;
			}
			if (next->RetailerID < 1)
			{
				cout << "\tINVALID ID\n\tEnter the Valid ID of New Retailer: ";
				goto ret_id_label2;
			}
			read.open("RetailerData.txt", ios::app);

			while (read >> rn >> ri >> mm >> ma >> lm >> la >> Invest)
			{
				if (ri == next->RetailerID)
				{
					id_found2 = true;
					break;
				}
			}
			read.close();
			if (id_found2 == true)
			{
				cout << endl
					 << next->RetailerID << "\tIS ALREADY EXIST!\n\nEnter Valid the ID of New Retailer: ";
				goto ret_id_label2;
			}

			write << next->RetailerID << setw(25);
		mobile_insert2:
			cout << "\nPRESS 1 TO BUY MOBILES\nPRESS 0 FOR NOT\n\t\t";
			cin >> check;
			if (check == "1")
			{
				cout << "Enter Mobile Model: ";
				cin >> next->MobileModle;
				cout << "Enter the Number of Mobiles Retailer Bought: ";

				cin.ignore();
			mob_label2:
				cin >> next->MobileAmount;
				while (cin.fail())
				{

					cout << "\tINVALID AMOUNT\n\tEnter the Valid Number of Mobiles Retailer Bought: ";
					cin.clear();
					cin.ignore(256, '\n');
					cin >> next->MobileAmount;
				}
				if (next->MobileAmount < 1)
				{
					cout << "\tINVALID AMOUNT\n\tEnter the Valid Number of Mobiles Retailer Bought: ";
					goto mob_label2;
				}

				next->Investment += MobilePrices(next->MobileModle, next->MobileAmount);
				if (correctinput == true)
				{
					write << next->MobileModle << setw(25) << next->MobileAmount << setw(25);
				}
				else
				{
					next->MobileModle = "NIL";
					next->MobileAmount = 0;
					write << next->MobileModle << setw(25) << next->MobileAmount << setw(25);
				}
			}

			else if (check == "0")
			{
			}
			else
			{
				cout << "INVALID INPUT" << endl;
				goto mobile_insert2;
			}

		lap_insert2:
			cout << "\nPRESS 1 TO BUY LAPTOPS\nPRESS 0 FOR NOT\n\t\t";
			cin >> check;
			if (check == "1")
			{
				cout << "\n\nEnter Laptop Model: ";
				cin >> next->LaptopModle;
				cout << "Enter the Number of Laptop Retailer Bought: ";
				cin.ignore();
			lap_label2:
				cin >> next->LaptopAmount;
				while (cin.fail())
				{

					cout << "\tINVALID AMOUNT\n\tEnter the Valid Number of Laptops Retailer Bought: ";
					cin.clear();
					cin.ignore(256, '\n');
					cin >> next->LaptopAmount;
				}
				if (next->LaptopAmount < 1)
				{
					cout << "\tINVALID AMOUNT\n\tEnter the Valid Number of Laptops Retailer Bought: ";
					goto lap_label2;
				}

				next->Investment += LaptopPrices(next->LaptopModle, next->LaptopAmount);
				if (correctinput == true)
				{
					write << next->LaptopModle << setw(25) << next->LaptopAmount << setw(25);
				}
				else
				{
					next->LaptopModle = "NIL";
					next->LaptopAmount = 0;
					write << next->LaptopModle << setw(25) << next->LaptopAmount << setw(25);
				}
			}
			else if (check == "0")
			{
			}
			else
			{
				cout << "INVALID INPUT" << endl;
				goto lap_insert2;
			}

			write << next->Investment << endl;
			next->Nptr = NULL;
			next->Pptr = current;
			current->Nptr = next;
			current = next;
		}
		write.close();
	}
	void DeleteRetailerData()
	{
		ManufecturOrder obj;
		ReadFile();
		ofstream write2;
		found = false;
		cout << "EXISTING PRODUCTS RECORD LIST:-" << endl
			 << endl;
		obj.RetailerDataTRAVER();
		cout << "Enter the Retailer ID You want to DELETE: ";
		cin.ignore();
	del_id_label1:
		cin >> keyID;

		while (cin.fail())
		{

			cout << "\tINVALID ID\n\tEnter the Valid Retailer ID you want to Delete: ";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> keyID;
		}
		if (keyID < 1)
		{
			cout << "\tINVALID ID\n\tEnter the Valid Retailer ID you want to Delete: ";
			goto del_id_label1;
		}
		read.open("RetailerData.txt", ios::app);
		write2.open("RetailerData2.txt", ios::app);

		
		while (read >> rn >> ri >> mm >> ma >> lm >> la >> Invest)
		{
			if (ri == keyID)
			{
				cout << endl
					 << "   Retailer Data is Deleted of ID "<<ri<<endl<<endl;
				found = true;
			}
			else
			{
				write2 << rn << setw(25);
				write2 << ri << setw(25);
				write2 << mm << setw(25) << ma << setw(25);
				write2 << lm << setw(25) << la << setw(25);
				write2 << Invest << endl;
			}
		}
		if (found == false)
		{
			cout << "Retailer ID is INVALID\n\n";
		}
		cout<<"NOTE:-\tIF YOU WANT TO DELETE ONLY MOBILES OR LAPTOPS YOU CAN USE MODIFY OPTION\nAND THEN GIVE NULL VALUES TO DELETE SPECIFIC..."<<endl<<endl;

		read.close();
		write2.close();
		remove("RetailerData.txt");
		rename("RetailerData2.txt", "RetailerData.txt");
		ReadFile();
	}
	void SearchRetailerData()
	{
		ManufecturOrder obj;
		ReadFile();
		found = false;
		obj.show_record_ids();
		cout << "\n\nEnter the ID You want to search: ";
		cin.ignore();
	search_id_label1:
		cin >> keyID;

		while (cin.fail())
		{

			cout << "\tINVALID ID\n\tEnter the Valid Retailer ID you want to Search: ";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> keyID;
		}
		if (keyID < 1)
		{
			cout << "\tINVALID ID\n\tEnter the Valid Retailer ID you want to Search: ";
			goto search_id_label1;
		}
		current = start;
		while (current != NULL)
		{
			if (keyID == current->RetailerID)
			{
				found = true;
				break;
			}
			current = current->Nptr;
		}
		if (found == false)
		{
			cout << "ID Not Found\n\n";
		}
		else
		{
			cout << "    "
				 << "Name      |      "
				 << "ID     |      "
				 << "Laptop     |     "
				 << "Amount   |      "
				 << "Mobile     |      "
				 << "Amount     |     "
				 << "Investment\n";
			cout << "______________|_____________|_________________|______________|_________________|_________________|_____________________\n";
			cout << "     " << current->RetailerName << "          " << current->RetailerID << "           " << current->LaptopModle << "                 " << current->LaptopAmount;
			cout << "                " << current->MobileModle << "               " << current->MobileAmount;
			cout << "                " << current->Investment << endl
				 << endl;
			cout << "______________|_____________|_________________|______________|_________________|_________________|_____________________\n";
		}
	}

	void RetailerDataTRAVER()
	{
		ReadFile();
		unsigned short int numbernig = 1;
		if (start == NULL)
		{
			cout << "No Retailer Data to Show\n\n";
		}
		else
		{
			current = start;

			cout << "    "
				 << "Name      |      "
				 << "ID     |      "
				 << "Laptop     |     "
				 << "Amount   |      "
				 << "Mobile     |      "
				 << "Amount     |     "
				 << "Investment\n";
			cout << "______________|_____________|_________________|______________|_________________|_________________|______________________\n";
			while (current != NULL)
			{
				cout << numbernig << ".  " << current->RetailerName << "          " << current->RetailerID << "           " << current->LaptopModle << "                 " << current->LaptopAmount;
				cout << "                " << current->MobileModle << "               " << current->MobileAmount;
				cout << "                " << current->Investment << endl
					 << endl;
				cout << "______________|_____________|_________________|______________|_________________|_________________|______________________\n";

				current = current->Nptr;
				numbernig++;
			}
			string check;
		cout<<"\nPRESS 1 FOR SORTING DATA BY IDs\nPRESS 0 FOR NOT\n\t\t";
		cin>>check;
		if(check=="1")
			{AscendingIDs(numbernig);}
		else if(check=="0")
		{

		}
		else
		{
			cout<<"INVALID INPUT"<<endl;
		}
		}
		
	}

	void AscendingIDs(int n)
	{
		
		ReadFile();
		int array[n];
		int i=0,minimum,pos,temp;
		current=start;
		while(current!=NULL)
		{
			array[i]=current->RetailerID;
			i++;
			current=current->Nptr;
		}
		for(i=0;i<n-1;i++)
		{
			minimum=array[i];
			pos=i;
			for(int j=i+1;j<n;j++)
			{
				if(minimum>array[j])
				{
					minimum=array[j];
					pos=j;
				}
			}
			temp=array[i];
			array[i]=array[pos];
			array[pos]=temp;
		}
		current=start;
		i=0;
		while(current!=NULL)
		{
			current->RetailerID=array[i];
			i++;
			current=current->Nptr;
		}
		current=start;
		while(current!=NULL)
		{
		read.open("RetailerData.txt");
			while ((read >> rn >> ri >> mm >> ma >> lm >> la >> Invest)&&(current!=NULL))
			{
				if(current->RetailerID==ri)
				{
					current->RetailerName=rn;
					current->Investment=Invest;
					current->LaptopAmount=la;
					current->LaptopModle=lm;
					current->MobileAmount=ma;
					current->MobileModle=mm;
					read.close();
				}
			}
			current=current->Nptr;	
		}
		unsigned short int c = 1;
		cout<<"\n\t\t\t\tSorted Data:\n\n ";
		
		current = start;
			
			cout << "    "
				 << "Name      |      "
				 << "ID     |      "
				 << "Laptop     |     "
				 << "Amount   |      "
				 << "Mobile     |      "
				 << "Amount     |     "
				 << "Investment\n";
			cout << "_______________|_____________|_________________|______________|_________________|_________________|______________________\n";
			while (current != NULL)
			{
				cout << c << ".  " << current->RetailerName << "          " << current->RetailerID << "           " << current->LaptopModle << "                 " << current->LaptopAmount;
				cout << "                " << current->MobileModle << "               " << current->MobileAmount;
				cout << "                " << current->Investment << endl
					 << endl;
				cout << "______________|_____________|_________________|______________|_________________|_________________|______________________\n";

				current = current->Nptr;
				c++;
			}
	}
	void ModifyRetailerData()
	{	
		ManufecturOrder obj;
		string check;
		cout << "EXISTING PRODUCTS RECORD LIST:-" << endl
			 << endl;
		obj.RetailerDataTRAVER();
		ofstream write2;
		found = false;
		cout << "\nEnter the Retailer ID you want to Modify: ";

		cin.ignore();
	mod_id_label1:
		cin >> keyID;

		while (cin.fail())
		{

			cout << "\tINVALID ID\n\tEnter the Valid Retailer ID you want to Modify: ";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> keyID;
		}
		if (keyID < 1)
		{
			cout << "\tINVALID ID\n\tEnter the Valid Retailer ID you want to Modify: ";
			goto mod_id_label1;
		}

		read.open("RetailerData.txt", ios::app);
		write2.open("RetailerData2.txt", ios::app);
		while (read >> rn >> ri >> mm >> ma >> lm >> la >> Invest)
		{
			if (ri == keyID)
			{
				show_available_items();
				Invest = 0;
				found = true;
				cout << "\nEnter the New Retailer Name: ";

				cin.ignore();
				cin >> rn;
				while (checkString(rn))
				{
					cout << "\t\tINVALID NAME\n\t\tEnter the Valid Name of New Retailer: ";
					cin >> rn;
				}
				write2 << rn << setw(25);

				cout << "Enter the New Retailer ID: ";
//				cin.ignore();
			mod_id_label2:
				cin >> ri;

				while (cin.fail())
				{

					cout << "\tINVALID ID\n\tEnter the Valid ID of New Retailer: ";
					cin.clear();
					cin.ignore(256, '\n');
					cin >> ri;
				}
				if (ri < 1)
				{
					cout << "\tINVALID ID\n\tEnter the Valid ID of New Retailer: ";
					goto mod_id_label2;
				}
				
				write2 << ri << setw(25);

				modify_mobile_insert1:
			cout << "\nPRESS 1 TO BUY MOBILES\nPRESS 0 FOR NOT\n\t\t";
			cin >> check;
			if (check == "1")
			{
				cout << "Enter the New Mobile Model: ";
				cin >> mm;
				cout << "Enter the New Mobile Amount: ";

				cin.ignore();
			mob_label1:
				cin >> ma;
				while (cin.fail())
				{

					cout << "\tINVALID AMOUNT\n\tEnter the Valid Number of Mobiles Retailer Bought: ";
					cin.clear();
					cin.ignore(256, '\n');
					cin >> ma;
				}
				if (ma < 1)
				{
					cout << "\tINVALID AMOUNT\n\tEnter the Valid Number of Mobiles Retailer Bought: ";
					goto mob_label1;
				}
				
				Invest += MobilePrices(mm, ma);
				if (correctinput == true)
				{
					write2 << mm << setw(25) << ma << setw(25);
				}
				else
				{
					mm = "NIL";
					ma = 0;
					write2 << mm << setw(25) << ma << setw(25);
				}
			}

			else if (check == "0")
			{
			}
			else
			{
				cout << "INVALID INPUT" << endl;
				goto modify_mobile_insert1;
			}
				
				laptop_mobile_insert1:
			cout << "\nPRESS 1 TO BUY LAPTOPS\nPRESS 0 FOR NOT\n\t\t";
			cin >> check;
			if (check == "1")
			{
				cout << "\nEnter the New Laptop Model: ";
				cin >> lm;
				cout << "Enter the New Laptop Amount: ";
				cin.ignore();
			lap_label1:
				cin >> la;
				while (cin.fail())
				{

					cout << "\tINVALID AMOUNT\n\tEnter the Valid Number of Laptops Retailer Bought: ";
					cin.clear();
					cin.ignore(256, '\n');
					cin >> la;
				}
				if (la < 1)
				{
					cout << "\tINVALID AMOUNT\n\tEnter the Valid Number of Laptops Retailer Bought: ";
					goto lap_label1;
				}
				Invest += LaptopPrices(lm, la);
				if (correctinput == true)
				{
					write2 << lm << setw(25) << la << setw(25);
				}
				else
				{
					lm = "NIL";
					la = 0;
					write2 << lm << setw(25) << la << setw(25);
				}
				write2 << Invest << endl;
			}

			else if (check == "0")
			{
			}
			else
			{
				cout << "INVALID INPUT" << endl;
				goto laptop_mobile_insert1;
			}
				
			}
			else
			{
				write2 << rn << setw(25);
				write2 << ri << setw(25);
				write2 << mm << setw(25) << ma << setw(25);
				write2 << lm << setw(25) << la << setw(25);
				write2 << Invest << endl;
			}
		}
		write2.close();
		if (found == false)
		{
			cout << "Retailer ID is INVALID\n\n";
		}
		read.close();
		remove("RetailerData.txt");
		rename("RetailerData2.txt", "RetailerData.txt");
		ReadFile();
	}

	void show_record_ids()
	{
		ReadFile();

		if (start == NULL)
		{
			cout << "THERE IS NO RECORD EXIST...\n\n";
		}
		else
		{
			current = start;

			cout << "THE IDs THAT ARE AVAILABLE TO SEARCH:" << endl;
			while (current != NULL)
			{

				cout << current->RetailerID << "  ";

				current = current->Nptr;
			}
		}
	}
	


};
