#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Passenger{
	public:
	string name;
	string surname;
	
	Passenger(string name,string surname){
		
		this->name = name;
		this->surname = surname;
		 }
	string getName() const { return name; }
    string getsurName() const { return surname; }
		    
};



class Flight  {
	public:
    string flightNo;
    const int maxSeats;
    int numPassengers;
	vector<Passenger> passengerList;
	
	
Flight(string fNo, int max)
        : flightNo(fNo), maxSeats(max), numPassengers(0) {}
	
	 bool reserveSeat(const Passenger& passenger) {
        if (numPassengers < maxSeats) {
            passengerList.push_back(passenger);
            numPassengers++;
            return true;
        } else {
            cout << "Flight is full. Seat reservation failed.\n";
            return false;
        }
    }
    
     int numberPassengers() const {
        return numPassengers;
    }
    
    
  bool cancelSeat(string name) {
    for (auto it = passengerList.begin(); it != passengerList.end(); it++) {
        if (it->getName()==name) {
            passengerList.erase(it);
            numPassengers--;
            return true;
        }
    }
    cout << "Passenger not found. Cancellation failed.\n";
    return false;
}
    
	
	void printPassengers() const {
    vector<Passenger> tempList = passengerList;

    for (size_t i = 0; i < tempList.size(); ++i) {
        for (size_t j = i + 1; j < tempList.size(); ++j) {
            if (tempList[i].getsurName() > tempList[j].getsurName()) {
                swap(tempList[i], tempList[j]);
            }
        }
    }

    for (const auto& passenger : tempList) {
        cout << passenger.getsurName() << ", " << passenger.getName() << endl<<endl;
        
    }
    
}
    
 };




int main(int argc, char** argv) {
	int choose;
	string name;
	string surname;
	Flight flight("JKS622", 25);
	
	do{
	  
	cout<<"Flight Menu"<<endl<<endl;
	cout<<"1.Reserve a Ticket"<<endl<<"2.Cancel Reservation"<<endl<<"3.Number of passengers"<<endl<<"4.Display Reservation"<<endl<<"5.Exit"<<endl;
	cin >> choose;
	
	switch(choose){
		
		case 1:
		
		cout<<"Enter name and surname"<<endl;
		cin>>name;
		cin>>surname;
		cout<<endl<<endl;
		flight.reserveSeat(Passenger(name, surname ));
		        break;
		
		case 2:
			
		         break;
		
		case 3:
        
		cout << "Number of passengers: " << flight.numberPassengers() << endl<<endl<<endl;
                break;
		
		case 4:
                flight.printPassengers();
                break;
                
        case 5:
                cout << "Exiting program"<<endl<<endl;
                break;    
		}

}
    while(choose != 5);


	return 0;
}