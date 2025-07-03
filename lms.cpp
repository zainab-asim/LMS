#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void signup(string usr, string pass) {
	string temp = usr + pass;
	fstream write;
	write.open("credentials.txt", ios::app);
	write << temp << endl;
	write.close();
}

void login(string usr, string pass) {
	bool status = false;
	string temp = usr + pass,temp2;
	fstream read;
	read.open("credentials.txt", ios::in);
	while (!read.eof()) {
		getline(read, temp2);
		if (temp == temp2) {
			status = true;
			break;
		}
	}
	if (status == false) {
		cout << "Account does not exist; consider signing up." << endl;
	}
	read.close();
}

int main() {
	int response;
	do {
		cout << "1. Log In." << endl;
		cout << "2. Sign Up." << endl;

		int answer;
		cout << "Enter your choice: ";
		cin >> answer;
		cout << endl;

		if (answer == 1) {
			string username, password;
			cout << "Enter Username: ";
			cin >> username;
			cout << "Enter Password: ";
			cin >> password;
			login(username, password);
		}
		else if (answer == 2) {
			string user1, pass1;
			cout << "Enter Username: ";
			cin >> user1;
			cout << "Enter Password: ";
			cin >> pass1;
			signup(user1, pass1);
		}

		cout << endl;
		cout << "Do you want to choose the options again?(1 for Yes 0 for No)" << endl;
		cin >> response;
	} while (response == 1);

	return 0;
}