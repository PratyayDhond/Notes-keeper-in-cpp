# Notes-in-cpp

This is a notes app using concept of files in cpp.
used libraries : 
                
        #include<iostream>
        #include<fstream>
        #include<cstring>
        #include<ctime>
        
time library was used for generating the current time :

      string curTime(){
        	time_t Time = time(NULL);
        	return ctime(&Time);  
       }
       
Used a showAll file to show all the available notes. inspired from ls function of git bash

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
