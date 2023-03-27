// ***************************************************
// Projekt:     Parkghaus ZHNORD
// Copyright:    
// Author:		Landry Rutalindwa       
// Datum:       18.1.23 
// Programmname:Parkautomat 
// ***************************************************
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include <time.h>

using namespace std;
//Globale Variabeln
unsigned int totalBesucherPP;
unsigned int totalVermietPP;
int maximum1;
int maximum;


//Funktionen/Prototypen

void begruessung();
void start();
void einstellungen();
void prg();
void hauptsteuerung();
int textAusfahrt();
int textEinfahrt();
int mieterAusfahrt();
int mieterEinfahrt();
void schreiben();
void lesen();
int setVar();
//Mainprogramm
int main()
{  
//text();
begruessung();
start();
getchar();
//system("PAUSE");  
return 0;
}//Ende
//Funktionen/Prototypen
void begruessung()
{
cout<<"---------------------------------"<<endl;
cout<<"Parkhaus Zuerich Nord Willkommen."<<endl;
cout<<"---------------------------------"<<endl;
cout<<"1 = Prg. Start"<<endl;
cout<<"2 = Einstellungen"<<endl;
cout<<"0 = Beenden"<<endl;
};
//Einstellungen für die verfuegbaren Parkplaetze
void einstellungen()
{
    cout<<"Einstellungen."<<endl;
    cout<<"Azahl Besucher-Parkplaetze:";
    cin>>totalBesucherPP;
    
    fflush (stdin);  
    if (totalBesucherPP == 0)
    {
        cout<<"Hiermit werden die EInstellungen beendent."<<endl;
        system("PAUSE");
        system("CLS");
        begruessung();
        start();
        einstellungen();
    }
    cout<<"Anzahl Vermietete-Parkplaetze:";
    cin>>totalVermietPP;
    
    fflush (stdin);
    if (totalVermietPP == 0)
    {
        cout<<"Hiermit werden die EInstellungen beendent."<<endl;
        system("PAUSE");
        system("CLS");
        begruessung();
        start();
        einstellungen();
    }	
    	setVar();
        system("PAUSE");
        system("CLS");
        
        hauptsteuerung();
        
     	
        
    
        
       
};

void start()//Start auswahl
{
        int eingabe;
        cin>>eingabe;
        switch (eingabe)
    {
        case 1: lesen(); setVar(); hauptsteuerung();//programm starten
        break;
        case 2: einstellungen();//in die einstellungen
        break;
        case 0: cout<<"Sie beenden hiermit das Programm, auf wiedersehen."<<endl;
        		exit(3);//Beenden des Programms
        break;
        default: cout<<"Fehleingabe, bitte versuchen Sie es erneut."<<endl;
        system("CLS");
        start();
        break;
    }
}

void hauptsteuerung()//hausptsteuerung fürs den verkehr an der schranke und rechenen der parkplätze
{   
    char eingabe;  
   

	
	
    cout<<"--------------"<<endl;
    cout<<"Hauptsteuerung"<<endl;
    cout<<"--------------"<<endl;
    cout<<"1.Besucher Ein- 2.Besucher Aus- 3. Mieter Aus- 4. Mieter Ein- 0. Exit"<<endl;
    cout<<"---------------------------------------------------------------------"<<endl<<endl<<endl;
    eingabe=getch();
 
    do//Hauptprogramm eingabe in eine schleife
    { 
     
      switch (eingabe)
      
    {
        		case '1':if (totalBesucherPP >0) 
				{
        		totalBesucherPP--;
        		textEinfahrt();      		
        		cout << "Willkommen Besucher." << endl;
        		cout << "Lampe ist gruen." << endl;
        		} 		
				if(totalBesucherPP<1) 
				{
        		cout << "Lampe ist rot." << endl;
        		cout << "Alle Besucherparkplaetze sind belegt." << endl;
      }
      			cout << "Aktuelle Besucher: " << totalBesucherPP << endl;
      			cout << "Aktuelle Mieter: " <<totalVermietPP << endl;
      
                
                system("PAUSE");
                system("CLS");
                hauptsteuerung();
        break;
        case '2': 	if (totalBesucherPP<maximum)
			{
				totalBesucherPP++ ;	
				textAusfahrt();			     			
        		cout<<"Vielen Dank Besucher."<<endl;
        		cout << "Lampe ist gruen." << endl;
								
			} else
			{			
				cout<<"Keine Besucher mehr im Parkhaus."<<endl;
				cout<<"Lampe ist gruen"<<endl;
				
			}	
				cout<<"Besucher aktuell "<<totalBesucherPP<<endl; 
				cout << "Aktuelle Mieter: " <<totalVermietPP << endl;

				system("PAUSE");
                system("CLS");
                hauptsteuerung();
        break;
        case '3':if (totalVermietPP > 0) 
			{
        		totalVermietPP--;
        		mieterEinfahrt();
        		cout << "Willkommen Mieter." << endl;
        		
      		} 		
	  			if(totalVermietPP<1) 
			{
        		
        		cout << "Alle Mieterparkplaetze sind belegt." << endl;
      		}
      			cout<<"Besucher aktuell "<<totalBesucherPP<<endl; 
				cout << "Aktuelle Mieter: " <<totalVermietPP << endl;

                system("PAUSE");
                system("CLS");
                hauptsteuerung();
        break;
        case '4': 	if (totalVermietPP<maximum1)
			{
				totalVermietPP++ ;	
				mieterAusfahrt();			     			
        		cout<<"Vielen Dank Mieter."<<endl;
								
			} else
			{			
				cout<<"Keine Mieter mehr im Parkhaus."<<endl;
				
			}	
				cout<<"Besucher aktuell "<<totalBesucherPP<<endl; 
				cout << "Aktuelle Mieter: " <<totalVermietPP << endl;
				
				system("PAUSE");
                system("CLS");
                hauptsteuerung();

        break;      
        case '0':cout<<"Das Hauptprogramm wird beendet!"<<endl;
                system("PAUSE");
                system("CLS");
                begruessung();
                start();   
        default:cout<<"falsche Eingabe, bitte versichen Sie es erneut."<<endl;
                system("PAUSE");
                system("CLS");
                hauptsteuerung();
    }  }
        while(eingabe);
        
};


int setVar()
{
		
    	maximum1=totalVermietPP;
    	maximum=totalBesucherPP;
    	schreiben();
    	
};
    
int textEinfahrt()
{
 ofstream file("Protokoll.txt",ios::app); // Öffnen der Datei "time.txt" zum Schreiben
    if (file.is_open()) {
        time_t currentTime = time(nullptr); // Aktuelle Zeit erhalten
        file << ctime(&currentTime)<< "Einfahrt Besucher <---" << endl; // Zeit in die Datei schreiben
        file.close(); // Datei schließen
        cout << "|||Einfahrt Besucher <---|||" << endl;
    } else {
        cout << "Fehler beim Oeffnen der Datei." << endl;
    }
};   

    

int textAusfahrt()
{
 ofstream file("Protokoll.txt",ios::app); // Öffnen der Datei "time.txt" zum Schreiben
    if (file.is_open()) {
        time_t currentTime = time(nullptr); // Aktuelle Zeit erhalten
        file << ctime(&currentTime)<< "Ausfahrt Besucher --->" << endl; // Zeit in die Datei schreiben
        file.close(); // Datei schließen
        cout << "|||Ausfahrt Besucher --->|||" << endl;
    } else {
        cout << "Fehler beim Oeffnen der Datei." << endl;
    }
};   


int mieterEinfahrt()
{
 ofstream file("Protokoll.txt",ios::app); // Öffnen der Datei "time.txt" zum Schreiben
    if (file.is_open()) {
        time_t currentTime = time(nullptr); // Aktuelle Zeit erhalten
        file << ctime(&currentTime)<< "Einfahrt Mieter <---" << endl; // Zeit in die Datei schreiben
        file.close(); // Datei schließen
        cout << "|||Einfahrt Mieter <---|||" << endl;
    } else {
        cout << "Fehler beim Oeffnen der Datei." << endl;
    }
};   


int mieterAusfahrt()
{
 ofstream file("Protokoll.txt",ios::app); // Öffnen der Datei "time.txt" zum Schreiben
    if (file.is_open()) {
        time_t currentTime = time(nullptr); // Aktuelle Zeit erhalten
        file << ctime(&currentTime)<< "Ausfahrt Mieter --->" << endl; // Zeit in die Datei schreiben
        file.close(); // Datei schließen
        cout << "|||Ausfahrt Mieter --->|||" << endl;
    } else {
        cout << "Fehler beim Oeffnen der Datei." << endl;
    }
};   

void schreiben()
{
	{	
	ofstream MeineDaten;
	MeineDaten.open("Einstellungen.txt");
	
	
	if(MeineDaten)
	{cout<<totalBesucherPP <<" Besucher Parkplaetze "<<totalVermietPP<<" Vermietete Parkplaetze"<<endl;
	MeineDaten <<totalBesucherPP<< " " <<totalVermietPP<< endl;
	MeineDaten.close();
	}
	else
	{
		cout<<"FEHLER!"<<endl;
		
        system("PAUSE");
        system("CLS");
		begruessung();
        start();
        einstellungen();
		
	}
	
	
}
};

void lesen()
{
	ifstream MeineDaten("Einstellungen.txt");
    
    if (MeineDaten) {
        MeineDaten >> totalBesucherPP >> totalVermietPP;
        
        MeineDaten.close();
    } else {
        cout << "FEHLER!" << endl;
        
        
		system("PAUSE");
        system("CLS");
		begruessung();
        start();
        einstellungen();
    }

		
	
};



