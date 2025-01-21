//cpp program for hospital 
//management

#include<bits/stdc++.h>
using namespace std;

//class to store data of Hospital
class Hospital
{
  public: 
  string H_name;
  string location;
  int available_beds;
  float rating; 
  string contact; 
  string doctor_name;  
  int price;
  int distance;	
};

//class to store data of Patient
class Patient: public Hospital
{
  public:	
  string P_name;
  int P_id;  	
};

//Hospital Data 
void PrintHospitalData(vector<Hospital> &hospitals)
{ 
	
	cout << "PRINT hospitals DATA:" << endl; 
	
	cout <<"HospitalName     " 
	     <<"Location     "
		 <<"Beds_Available     "
		 <<"Rating     "
		 <<"Hospital_Contact     "
		 <<"Doctor_Name     "
		 <<"Price_Per_Bed     "
		 <<"Distance_From_Central     \n"; 
 

	for (int i = 0; i < hospitals.size(); i++) { 
	 
		cout << hospitals[i].H_name<<"               " 
			 << hospitals[i].location<<"           "
			 << hospitals[i].available_beds<<"           "
			 << hospitals[i].rating<<"            "
			 << hospitals[i].contact<<"          "
			 << hospitals[i].doctor_name<<"              "
			 << hospitals[i].price<<"            "
			 << hospitals[i].distance<<"            "
			 << endl;  
	} 
	cout << endl<<endl; 
}


//patient data
void PrintPatientData(vector<Patient> &patients,vector<Hospital> &hospitals)
{ 
	
	cout << "PRINT patients DATA:" << endl; 
	
	cout <<"Patient_Name     " 
	     <<"Patient_Id     "
		 <<"Patient_Contact     "
		 <<"Alloted_Hospital     "
		 <<"Patient_Expenditure     "
		 <<"Patient_Distance_From_Central     \n";  
 

	for (int i = 0; i < patients.size(); i++) { 
	 
		cout << patients[i].P_name<<"               " 
			 << patients[i].P_id<<"              "
			 << patients[i].contact<<"           "
			 << hospitals[i].H_name<<"                   " 
			 << patients[i].price<<"                       "
			 << patients[i].distance<<"            "
			 << endl; 
	} 
	cout << endl <<endl; 
}

// by name
bool name(Hospital& A, Hospital& B) 
{ 
	return A.H_name > B.H_name; 
} 
//Sort Hospital By Name 
void SortHospitalByName(vector<Hospital> hospitals)
{
  sort(hospitals.begin(),hospitals.end(),name);
  cout << "SORT BY NAME:" << endl<< endl;
  PrintHospitalData(hospitals);	
} 


//by rating
bool rating(Hospital& A, Hospital& B) 
{ 
	return A.rating > B.rating; 
} 
//Sort Hospital By rating
void SortHospitalByRating(vector<Hospital> hospitals)
{
  sort(hospitals.begin(),hospitals.end(),rating);
  cout << "SORT BY Highest Rating:" << endl<< endl;
  PrintHospitalData(hospitals);	
}

//by beds available
bool beds(Hospital& A, Hospital& B) 
{ 
	return A.available_beds > B.available_beds; 
} 
//Sort Hospital beds available
void SortByBedsAvailable(vector<Hospital> hospitals)
{
  sort(hospitals.begin(),hospitals.end(),beds);
  cout << "SORT BY Number of Available Beds:" << endl<< endl;
  PrintHospitalData(hospitals);	
}  


//by beds Price
bool beds_price(Hospital& A, Hospital& B) 
{ 
	return A.price < B.price; 
} 
//Sort Hospital beds available
void SortByBedsPrice(vector<Hospital> hospitals)
{
  sort(hospitals.begin(),hospitals.end(),beds_price);
  cout << "SORT BY Available Minimum Beds Price:" << endl<< endl;
  PrintHospitalData(hospitals);	
} 

//by distance
bool distt(Hospital A, Hospital B) 
{ 
	return A.distance < B.distance; 
} 
//Sort nearest distance from hospital to patient
void SortBynearestdistance(vector<Hospital> hospitals, int dis, string name)
{
	for(int i=0;i<4;i++)
	{
	  hospitals[i].distance+=dis;
	}
  sort(hospitals.begin(),hospitals.end(),distt);
  cout << "Nearest hospital from Patient "<<name<<" :" << endl<< endl;
  PrintHospitalData(hospitals);	
}  


//Print Hospital by city
void PrintHospitalBycity(string city,vector<Hospital> hospitals)
{
	cout << "PRINT hospitals by Name :"<<city << endl; 
	
	cout <<"HospitalName     " 
	     <<"Location     "
		 <<"Beds_Available     "
		 <<"Rating     "
		 <<"Hospital_Contact     "
		 <<"Doctor_Name     "
		 <<"Price_Per_Bed     "
		 <<"Distance_From_Central     \n";   
 

	for (int i = 0; i < hospitals.size(); i++) { 
	   
	   if(hospitals[i].location!=city) continue;
		cout << hospitals[i].H_name<<"               " 
			 << hospitals[i].location<<"           "
			 << hospitals[i].available_beds<<"           "
			 << hospitals[i].rating<<"            "
			 << hospitals[i].contact<<"          "
			 << hospitals[i].doctor_name<<"              "
			 << hospitals[i].price<<"            "
			 << hospitals[i].distance<<"            "
			 << endl; 
	} 
	cout << endl<<endl; 
}
 
void HospitalManagement(string patient_Name[],int patient_Id[],string patient_Contact[],int bookingCost[],int P_distance_from_center[], 
					string hospital_Name[],string locations[],int beds[],float ratings[],string hospital_Contact[],
					string doctor_Name[],int prices[],int H_distance_from_center[]) 
{ 
	// Initialize arrays that stores 
	// Hospital data and user data 
	vector<Hospital> hospitals;  
	// Create Objects for 
	// hspital and user. 
	Hospital h;  
	// Initialise the data 
	for (int i = 0; i < 4; i++) { 
	
		h.H_name = hospital_Name[i]; 
		h.location = locations[i];
		h.available_beds = beds[i];  
		h.rating = ratings[i];
		h.contact=hospital_Contact[i];
		h.doctor_name=doctor_Name[i]; 
		h.price=prices[i]; 
		h.distance=H_distance_from_center[i];
		
		hospitals.push_back(h); 
	} 
	
	
	// Initialize arrays that stores 
	// Patient data 
	vector<Patient> patients; 
	Patient p;  
	// Initialise the data 
	for (int i = 0; i < 4; i++) { 
	
	    p.P_name= patient_Name[i]; 
		p.P_id= patient_Id[i];
		p.contact=patient_Contact[i];
		p.price=bookingCost[i];
		p.distance=P_distance_from_center[i];  
		patients.push_back(p); 
	}
	 
	cout << endl; 

	// Call the various operations 
	PrintHospitalData(hospitals); 
    PrintPatientData(patients,hospitals); 
    
    SortHospitalByName(hospitals); 
    SortHospitalByRating(hospitals); 
    SortBynearestdistance(hospitals, patients[0].distance,patients[0].P_name );
    PrintHospitalBycity("Bangalore",hospitals); 
    SortByBedsAvailable(hospitals); 
    SortByBedsPrice(hospitals);
} 
					


//Driver code
int main()
{
	cout<<"\t\t\t\t\t\t\t************************************************\n"
	    <<"\t\t\t\t\t\t\tPROJECT NAME: HOSPITAL MANAGEMENT\n\t\t\t\t\t\t\t        NAME: SAURAV KUMAR \n"
	    <<"\t\t\t\t\t\t\t     ROLL NO: 1911215 \n\t\t\t\t\t\t\t     SUBJECT: PRINCIPAL OF PROGRAMMING LANGUAGE \n"
		<<"\t\t\t\t\t\t\t************************************************\n";
	// Initialize variables to stores 
	// hospital data and user data. 
	
	string patient_Name[] = { "P1", "P2", "P3","P4" }; 
	int patient_Id[] = { 2, 3, 4,1 };
	string patient_Contact[] ={"234534XXX7","234576XXX2","857465XXX9","567657XXX0"}; 
	int bookingCost[] = { 1000, 1200, 1100 ,600};
	int P_distance_from_center[] = { 300, 100, 1100 ,400};
	
	
	string hospital_Name[] = { "H1", "H2", "H4", "H3" };
	string locations[] = { "Bangalore", "Bangalore", "Mumbai   ", "Prayagraj" };
	int beds[] = { 4, 5, 6 ,9};
	float ratings[] = { 5.2, 4.1, 3.4, 5.9 };
	string hospital_Contact[] ={"657534XXX7","998766XXX2","824565XXX9","343456XXX4"}; 
	string doctor_Name[] = { "D1", "D4", "D3","D2" };  
	int prices[] = { 100, 200, 100, 290 }; 
	int H_distance_from_center[] = { 100, 200, 190 ,600};

	// Function to perform operations 
	HospitalManagement(patient_Name, patient_Id,patient_Contact,bookingCost,P_distance_from_center,
	                   hospital_Name,locations,beds,ratings,hospital_Contact,doctor_Name,prices ,H_distance_from_center
					   ); 


   
	return 0; 
}

//contributed by saurav6234488

