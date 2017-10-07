#include <string>
#include <math.h>
#include <iostream>
using namespace std;

void Encrypt(string, string, string&);
int KeyGen();
string Decrypt();

int main() {

	string userInput;
	string returnData;
	string eKey = "";
	//char test = 'a';
	//char test2 = test + 1;
	
	//test
	for (int i = 0; i < 24; i++) {
		eKey += to_string(KeyGen());
	}
	cout << "Your encryption key, **KEEP THIS**:  " << eKey << endl;

	cout << "Enter in a string to be 'encrypted' (No +'s): ";
	cin >> userInput;

	Encrypt(eKey, userInput, returnData);

	cout << endl << "Here is your encryped string :  " << returnData << endl;

	cin >> eKey;
	return NULL;
}

void Encrypt(string eKey, string data, string& returnData) {

	char backLetter;
	char tempLetter;
	string eKeyBackup = eKey;
	int currKey = NULL;

	//Convert the string into a char array
	//>>>>>>>>>>>>COME BACK TO THIS<<<<<<<<<<<<
	/*char cArray[1024];
	strncpy(cArray, data.c_str(), sizeof(cArray));
	cArray[sizeof(cArray) - 1] = 0;*/

	while (data.length() > 0) {

		if (eKey.length() == 0) {
			eKey = eKeyBackup;
		}

		if (data.back() == ' ') {
			backLetter = '+';
			data.pop_back();
		}

		else {
			backLetter = data.back();

			cout << "backLetter = " << backLetter << endl; //DEBUG
			data.pop_back();

			eKey.back() >> currKey;
			cout << "currKey = " << currKey << ", eKey.back() = " << eKey.back() << endl; //DEBUG
			backLetter = backLetter + eKey.back();
			eKey.pop_back();
		}
		

		tempLetter = backLetter;
		returnData += tempLetter;

	}

}

int KeyGen() {

	int key = NULL;

	key = rand() % 9;

	return key;
}

string Decrypt() {


	return NULL; //return NULL for now
}