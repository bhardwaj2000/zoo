#include<iostream>
using namespace std;
static int ticket_num=0;
class Zoo{
	private:
	int num_of_guest;
	int *Age_of_guest;
	public:
		Zoo(int num){
			num_of_guest=num;
			Age_of_guest=new int[num_of_guest];
		}
		~Zoo(){
			delete []Age_of_guest;
		}
		void setvalue();
		void Total_charge();
		void security_check();
		void warning();
};
void Zoo::setvalue(){
	cout<<"\n Enter age of all guest :"<<endl;
	for(int i=0;i<num_of_guest;i++){
		cin>>Age_of_guest[i];
	}
}
void Zoo::Total_charge(){
	int total_charge=0;
	for(int i=0;i<num_of_guest;i++){
		if(Age_of_guest[i]<=2)
            total_charge+=0;
        else if(Age_of_guest[i]>2 && Age_of_guest[i]<18)
            total_charge+=100;
        else if(Age_of_guest[i]>=18 && Age_of_guest[i]<60)
            total_charge+=500;
        else
            total_charge+=300;
	}
	cout<<"\n Total charge = "<<total_charge<<endl;
	ticket_num+=1;
}
void Zoo::warning(){
	int curr_ticket_num;
	cout<<"enter current ticket number :"<<endl;
	cin>>curr_ticket_num;
	 if(curr_ticket_num<ticket_num && curr_ticket_num>0){
        cout<<"\n Warning ! "<<endl;
        cout<<"Ticket has already been used in the past to enter into the zoo."<<endl;
        }
     else if(curr_ticket_num==ticket_num )
	 	cout<<"\nValid Ticket."<<endl;  
	else
		cout<<"This ticket not of my Zoo Software."<<endl;	  
}
void Zoo::security_check(){
    for(int i=0;i<num_of_guest;i++){
        cout<<"\n Guest "<<(i+1)<<" (age: "<<Age_of_guest[i]<<")"<<endl;
    }
    cout<<endl;
}
int main(){
	int choice;
	while(1)
	{		book_next_ticket:
			cout<<"\nWelcome to Zoo Software:"<<endl;
			cout<<"Enter details for Book ticket :"<<endl;
			int num;
			cout<<"Number of guest want to enter the zoo : ";
			cin>>num;
			Zoo person(num);
			person.setvalue();
			person.Total_charge();
			entrance:
			cout<<"\n1. for book next ticket";	
			cout<<"\n2. Security Check at Entrance of Zoo.";
			cout<<"\n3. Check ticket is already used or not.";
			cout<<"\n4. Exit from Zoo Software.";
			cout<<"\nEnter your choice : ";
			cin>>choice;
			switch(choice){
/* Part 1:*/			case 1:
						//jump to book_next_ticket
						goto book_next_ticket;
						break;
/* Part 2:*/			case 2:
						person.security_check();
						//jump to entrance
						goto entrance;
						break;
/* Part 2.1:*/			case 3:
						person.warning();
						//jump to entrance
						goto entrance;
						break;
				case 4:
						exit(0);
				default:
						cout<<"\nPlease Enter correct choice \n";					
			}
	}
}
