#include<iostream>
#include<fstream>
#include<cstring>
#include<ctime>
using namespace std;

string curTime(){
	time_t Time = time(NULL);
	return ctime(&Time);
}

void createFile(){

	string filename;
	bool flag;
	do{
	cout<<"Enter today's date : Format : DD-MM-YYYY"<<endl<<"Date : ";
	cin>>filename;
	
	if(filename[2] == '-' && filename[5] == '-' && filename.size()<11){
				flag = true;
			}else{
				cout<<"Enter a valid date"<<endl;
				flag = false;
				system("pause");
				system("cls");
			}
		}while(flag != true);
		
	string date = filename;
	filename += ".txt";	
	
	ifstream fin(filename);
	if(fin.good()){	
		cout<<"File already exists"<<endl;									// checks if file already exists
		fin.close();
		int choice1;
		do{
			
			cout<<"Press 1. to append to file"<<endl
			<<"Press 2. to delete data "<<endl
			<<"Press 3. to exit"<<endl
			<<"Choice : ";
			cin>>choice1;
			system("pause");
			system("cls");
				
			switch(choice1){
				case 1:
						{
							ofstream fout;
							fout.open(filename,ios::app);
							string data;
							cout<<"Enter data to be inputted in the diary : "<<endl;
						//	cin.ignore();
							getline(cin,data);
							fout<<endl<<curTime()<<data<<endl;
							
						}
						break;
						
				case 2:
						{
							ofstream fout;
							fout.open(filename,ios::trunc);
							cout<<"data deleted successfully"<<endl;
						
						}
						break;
				case 3: 
						{	
							ofstream fout;
							if(fout.good()){
							fout.close();
						//	cout<<"File "<<filename<<"closed successfully"<<endl;
							}else{
								cout<<"No file open to be closed"<<endl;
							}	
						}
						
						break;
				default:
						cout<<"Choose a valid Option : "<<endl;				
			}
		}while(choice1!=3);
			
	}else{
		
		ofstream FOUT("AllRecord.txt",ios::app);
		FOUT<<date<<endl;
		FOUT.close();
		
		ofstream fout1;
		fout1.open(filename);						// Links file to object fout1;
		if(fout1.good()){
	//	cout<<"File"<<filename<<" created successfully."<<endl;											// Remainder Comment // //  Comment filename variable out out
		string data;
		cout<<"Enter data to be inputted in the diary : "<<endl;
	//	getline(cin,data);
		fflush(stdin);
		getline(cin,data);
		fout1<<curTime()<<data<<endl;
		return;
		//cin.ignore();
	}
	}
}



void showAllDates(){
	string print;
	ifstream fin("AllRecord.txt",ios::in);
	
		while(fin.eof() == 0){
			getline(fin,print);
			cout<<print<<endl;
	}
	cout<<endl;
	system("pause");
}

void accessFile(){
	char choice;
	do{
	cout<<"What action do you want to perform : "<<endl
		<<"1. Check all previous note names"<<endl
		<<"2. Search a note by date"<<endl
		<<"3. Press 3 to exit"<<endl
		<<"Choice : ";
	cin>>choice;
	system("pause");
	system("cls");
	if(choice == '1'){
		showAllDates();
		system("cls");
	}else if(choice == '2'){
		bool flag;
		string filename;
		do{
			cout<<"Enter date of the data you want to access : Format (DD-MM-YYYY) "<<endl
			<<"date : ";
			cin>>filename;
		//	cout<<filename.size();
			if(filename[2] == '-' && filename[5] == '-' && filename.size()<11){
				flag = true;
			}else{
				cout<<"Enter a valid date"<<endl;
				flag = false;
				system("pause");
				system("cls");
			}
		}while(flag != true);
//		cout<<filename;
		filename+=".txt";
		ifstream fin;
		fin.open(filename);
			
			do{
				
				string line;
				getline(fin,line);
				cout<<line<<endl;
				
			}while(fin);
		
		if((fin.good())){
				cout<<"Bad read, file couldn't be found."<<endl;
				}
			}else{
		cout<<"Enter a valid choice : "<<endl;
		system("pause");
		system("cls");
	}
	}while(choice != '3');
}

void showData(){
	
}

int main(){
	
	ifstream fin("AllRecord.txt",ios::in);
	if(fin.good()){
		fin.close();
	}else{
		fin.close();
		ofstream fin("AllRecord.txt");
		fin.close();
	}
	
	
	int choice;
	do{
		
		cout<<"Press 1 to input today's notes"<<endl
			<<"Press 2 to search previous notes"<<endl
			<<"Press 3 to exit program"<<endl
			<<"Choice : ";
			fflush(stdin);
		cin>>choice;
			system("pause");
			system("cls");	
			switch(choice){
			 	case 1:
			 			
			 			createFile();
			 			
			  			break;
				case 2:
						accessFile();
				
						break;
				case 3: 
			 			break;
				default:
						break;
			}

		system("pause");
		system("cls");
	}while(choice!=3);
	
	
system("pause");
return 0;
}
