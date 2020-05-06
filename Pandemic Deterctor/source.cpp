#include<bits/stdc++.h>
using namespace std;
class Database{
	private:
		string Disease;
		string Patient_ID;
		string Country_Name;
		string State_Name;
		string City_Name;
		string Patient_State;
	public:
		Database(){}
		Database(string disease_name, string patient_id, string country_name, string state_name, string city_name, string patient_state){
			Disease = disease_name;
			Patient_ID = patient_id;
			Country_Name = country_name;
			State_Name = state_name;
			City_Name = city_name;
			Patient_State = patient_state;
		}
		string getDisease(){
			return Disease;
		}
		string getPatientID(){
			return Patient_ID;
		}
		string getCountryName(){
			return Country_Name;
		}
		string getStateName(){
			return State_Name;
		}
		string getCityName(){
			return City_Name;
		}
		string getPatientState(){
			return Patient_State;
		}
};
class Table{
	private:
		map<int, Database> db;
		int slNodb = 1;
		string donedisease = "default";
		string donecountry = "default";
		string donestate = "default";
	public:
		void insertActiveData(string disease, string patient_id, string country_name, string state_name, string city_name, string patient_state){
			db.insert({slNodb++, Database(disease, patient_id, country_name, state_name, city_name, patient_state)});
		}
		void insertCureData(string disease, string patient_id, string country_name, string state_name, string city_name, string patient_state){
			db.insert({slNodb++, Database(disease, patient_id, country_name, state_name, city_name, patient_state)});
		}
		void insertFatalityData(string disease, string patient_id, string country_name, string state_name, string city_name, string patient_state){
		    db.insert({slNodb++, Database(disease, patient_id, country_name, state_name, city_name, patient_state)});
		}
		void insertDeathData(string disease, string patient_id, string country_name, string state_name, string city_name, string patient_state){
		    db.insert({slNodb++, Database(disease, patient_id, country_name, state_name, city_name, patient_state)});
		}
		void showWorldSummaryDiseasesBreakupUtil(string disease, int searchslNo){
			int countActive = 0;
			int countCured = 0;
			int countFatality = 0;
			int countTotal = 0;
			if(donedisease != disease){
				cout<<disease<<":"<<endl;
				for(auto itr = db.find(searchslNo); itr != db.end(); itr++){
					if(itr->second.getDisease() == disease){
						if(itr->second.getPatientState() == "Active")
							countActive++;
						else if(itr->second.getPatientState() == "Cure")
							countCured++;
						else if(itr->second.getPatientState() == "Fatality")
							countFatality++;
						countTotal++;
					}
				}
				cout<<"Active"<<" "<<countActive<<endl;
				cout<<"Cure"<<" "<<countCured<<endl;
				cout<<"Fatality"<<" "<<countFatality<<endl;
				cout<<"Total"<<" "<<countTotal<<endl;
				donedisease = disease;
				cout<<endl;
			}
		}
		int showCountryBreakupUtil(string country, int searchslNo, string disease, int check){
			int countActive = 0;
			int countCured = 0;
			int countFatality = 0;
			int countTotal = 0;
			if(donecountry != country){
				cout<<country<<":"<<endl;
				for(auto itr = db.find(searchslNo); itr != db.end(); itr++){
					if(itr->second.getCountryName() == country && itr->second.getDisease() == disease){
						if(itr->second.getPatientState() == "Active")
							countActive++;
						else if(itr->second.getPatientState() == "Cure")
							countCured++;
						else if(itr->second.getPatientState() == "Fatality")
							countFatality++;
						countTotal++;
					}
				}
				cout<<"Active"<<" "<<countActive<<endl;
				cout<<"Cure"<<" "<<countCured<<endl;
				cout<<"Fatality"<<" "<<countFatality<<endl;
				cout<<"Total"<<" "<<countTotal<<endl;
				donecountry = country;
				cout<<endl;
			}
			return check;
		}
		void showWorldSummary(){
			int countActive = 0;
			int countCured = 0;
			int countFatality = 0;
			int countTotal = 0;
			cout<<"Overall"<<":"<<endl;
			for(auto itr = db.begin(); itr != db.end(); itr++){
				if(itr->second.getPatientState() == "Active")
					countActive++;
				else if(itr->second.getPatientState() == "Cure")
					countCured++;
				else if(itr->second.getPatientState() == "Fatality")
					countFatality++;
				countTotal++;
			}
			cout<<"Active"<<" "<<countActive<<endl;
			cout<<"Cure"<<" "<<countCured<<endl;
			cout<<"Fatality"<<" "<<countFatality<<endl;
			cout<<"Total"<<" "<<countTotal<<endl;
		}
		int showStateBreakupUtil(string state, int searchslNo, string country, int check){
			int countActive = 0;
			int countCured = 0;
			int countFatality = 0;
			int countTotal = 0;
			if(donestate != state){
				cout<<state<<":"<<endl;
				for(auto itr = db.find(searchslNo); itr != db.end(); itr++){
					if(itr->second.getStateName() == state){
						if(itr->second.getPatientState() == "Active")
							countActive++;
						else if(itr->second.getPatientState() == "Cure")
							countCured++;
						else if(itr->second.getPatientState() == "Fatality")
							countFatality++;
						countTotal++;
					}
				}
				cout<<"Active"<<" "<<countActive<<endl;
				cout<<"Cure"<<" "<<countCured<<endl;
				cout<<"Fatality"<<" "<<countFatality<<endl;
				cout<<"Total"<<" "<<countTotal<<endl;
				donestate = state;
				cout<<endl;
			}
			return check;
		}
		void showWorldSummaryDiseasesBreakup(){
		    for(auto itr = db.begin(); itr != db.end(); itr++){
				auto searchdisease = itr->second.getDisease();
				auto searchslNo = itr->first;
				showWorldSummaryDiseasesBreakupUtil(searchdisease, searchslNo);
			}
		}
		void showCountryBreakup(string disease){
		    int check = 0;
		    for(auto itr = db.begin(); itr != db.end(); itr++){
		        auto searchcountry = itr->second.getCountryName();
		        auto searchdisease = itr->second.getDisease();
		        auto searchslNo = itr->first;
		        if(searchdisease == disease){
		            check = showCountryBreakupUtil(searchcountry, searchslNo, disease, 0);
		        }
		        else{
		            check = 1;
		        }
		    }
		    if(check == 1)
		       cout<<"No such Disease exists in the Country"<<endl; 
		}
		void showStateBreakup(string disease, string country){
		    int check = 0;
		    for(auto itr = db.begin(); itr != db.end(); itr++){
		        auto searchcountry = itr->second.getCountryName();
		        auto searchdisease = itr->second.getDisease();
		        if(searchcountry == country && searchdisease == disease){
		           auto searchstate = itr->second.getStateName();
		           auto searchslNo = itr->first;
		           check = showStateBreakupUtil(searchstate, searchslNo, country, 0);
		        }
		        else{
		            check = 1;
		        }
		    }
		    if(check == 1)
		        cout<<"No such Disease exists in the State"<<endl;
		}
		void showCompleteData(){
			for(auto itr = db.begin(); itr != db.end(); itr++){
				cout<<itr->second.getDisease()<<" "<<itr->second.getPatientID()<<" "<<itr->second.getCountryName()<<" "<<itr->second.getStateName()<<" "<<itr->second.getCityName()<<" "<<itr->second.getPatientState()<<endl;
			}
		}
};
int main()
{
    Table m;
    int reportmenunumber;
    int viewmenunumber;
    int entryreport = 1;
    cout<<"*****Welcome To Pendamic Tracker Application*****"<<endl;
    while(entryreport){
    	string disease;
    	string country;
    	string patientid;
    	string statename;
    	string cityname;
    	cout<<"Press 1 to report a ACTIVE CASE"<<endl;
    	cout<<"Press 2 to report a CURED CASE"<<endl;
    	cout<<"Press 3 to report a FATALITY CASE"<<endl;
    	cout<<"Press 4 to exit"<<endl;
    	cin>>reportmenunumber;
    	if(reportmenunumber == 4)
    	    return 0;
    	if(reportmenunumber == 1){
    		cout<<"*****Enter data of patient to report an ACTIVE CASE*****"<<endl;
    		cout<<"Enter DISEASE you want to report"<<endl;
    		cin>>disease;
    		cout<<"Enter PATIENTID you want to report"<<endl;
    		cin>>patientid;
    		cout<<"Enter COUNTRY you want to report"<<endl;
    		cin>>country;
    		cout<<"Enter STATE you want to report"<<endl;
    		cin>>statename;
    		cout<<"Enter CITY you want to report"<<endl;
    		cin>>cityname;
    		m.insertActiveData(disease, patientid, country, statename, cityname, "Active");
    	}
    	else if(reportmenunumber == 2){
    		cout<<"*****Enter data of patient to report an CURE CASE*****"<<endl;
    		cout<<"Enter DISEASE you want to report"<<endl;
    		cin>>disease;
    		cout<<"Enter PATIENTID you want to report"<<endl;
    		cin>>patientid;
    		cout<<"Enter COUNTRY you want to report"<<endl;
    		cin>>country;
    		cout<<"Enter STATE you want to report"<<endl;
    		cin>>statename;
    		cout<<"Enter CITY you want to report"<<endl;
    		cin>>cityname;
    		m.insertCureData(disease, patientid, country, statename, cityname, "Cure");
    	}
    	else if(reportmenunumber == 3){
    		cout<<"*****Enter data of patient to report an FATALITY CASE*****"<<endl;
    		cout<<"Enter DISEASE you want to report"<<endl;
    		cin>>disease;
    		cout<<"Enter PATIENTID you want to report"<<endl;
    		cin>>patientid;
    		cout<<"Enter COUNTRY you want to report"<<endl;
    		cin>>country;
    		cout<<"Enter STATE you want to report"<<endl;
    		cin>>statename;
    		cout<<"Enter CITY you want to report"<<endl;
    		cin>>cityname;
    		m.insertCureData(disease, patientid, country, statename, cityname, "Fatality");
    	}
    	cout<<"Do you wish to report more cases?, Type 0 to exit else 1 to continue"<<endl;
    	cin>>entryreport;
    	if(entryreport == 0)
    		break;
    }
    cout<<"*****View records database of patients*****"<<endl;
    cout<<"Press 5 to view the complete database of patient"<<endl;
    cout<<"Press 6 to view world summary disease breakup"<<endl;
    cout<<"Press 7 to view country breakup"<<endl;
    cout<<"Press 8 to view state breakup"<<endl;
    cout<<"Press 9 to view the world summary"<<endl;
    cin>>viewmenunumber;
    int entryview = 1;
    while(entryview){
        if(viewmenunumber == 5){
            m.showCompleteData();
            cout<<endl;
        }
        else if(viewmenunumber == 6){
            m.showWorldSummaryDiseasesBreakup();
            cout<<endl;
        }
        else if(viewmenunumber == 7){
            cout<<"Enter the disease for which you wish to view country breakup"<<endl;
            string disease;
            cin>>disease;
            m.showCountryBreakup(disease);
            cout<<endl;
        }
        else if(viewmenunumber == 8){
            cout<<"Enter the disease and country for which yoou wish to view state breakup"<<endl;
            string disease, country;
            cin>>disease>>country;
            m.showStateBreakup(disease, country);
            cout<<endl;
        }
        else if(viewmenunumber == 9){
        	m.showWorldSummary();
        	cout<<endl;
        }
        cout<<"Do you wish to continue? Type 0 to exit else 1 to continue"<<endl;
        cin>>entryview;
        if(entryview == 0)
            break;
    }
    return 0;
}
