#include <string>
#include <math.h>
#include <iostream>
#include <time.h>
using namespace std;

void Encrypt(string, string, string&);
int KeyGen();
int runCount = 1; //For debugging how many times the while loop has run
string Decrypt(string, string);

int main() {

	srand(time(NULL)); //Initialize the seed

	string userInput;
	string returnData;
	string uCrypt;
	string eKey = "";
	//char test = 'a';
	//char test2 = test + 1;
	
	//test
	for (int i = 0; i < 24; i++) {
		eKey += to_string(KeyGen());
	}
	cout << "Your encryption key, **KEEP THIS**:  " << eKey << endl;

	cout << "Enter in a string to be 'encrypted' (No +'s): ";
	getline(cin, userInput);

	Encrypt(eKey, userInput, returnData);
	uCrypt = Decrypt(eKey, returnData);

	cout << endl << "Here is your encryped string :  " << returnData << endl;
	cout << endl << "Here is the unencrypted string: " << uCrypt << endl;
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

		/*if (data.back() == ' ') {
			data.back() = '+';
			//backLetter = '+';
			backLetter = data.back();
			data.pop_back();
		}*/

		//else {
			//backLetter = scanf(" %[^\t\n]s", &data.back());
			backLetter = data.back();

			cout << "backLetter = " << backLetter << endl; //DEBUG
			data.pop_back();

			eKey.back() >> currKey;
			backLetter = backLetter + eKey.back();
			cout << "currKey = " << currKey << ", eKey.back() = " << eKey.back() << ", encryped letter = " << backLetter << ", data.length = " << data.length() << ", Run: " << runCount << endl; //DEBUG
			eKey.pop_back();
			runCount++; //Increase time ran by 1
		//}
		
		tempLetter = backLetter;
		returnData += tempLetter;

	}

}

int KeyGen() {

	int key = NULL;

	key = rand() % 9;

	return key;
}

string Decrypt(string eKey, string uCrypt) {

	char backLetter;
	char tempLetter;
	string eKeyBackup = "";
	string uCrypted;
	int currKey = NULL;

	eKeyBackup += eKey.back(); 
	eKey.pop_back();

	while (uCrypt.length() > 0) {

		if (eKey.length() == 0) {
			eKey = eKeyBackup;
		}

		backLetter = uCrypt.back();

		cout << "backLetter = " << backLetter << endl; //DEBUG
		uCrypt.pop_back();

		eKey.back() >> currKey;
		backLetter = backLetter - eKey.back();
		cout << "currKey = " << currKey << ", eKey.back() = " << eKey.back() << ", encryped letter = " << backLetter << ", data.length = " << uCrypt.length() << ", Run: " << runCount << endl; //DEBUG
		eKey.pop_back();
		runCount++; //Increase time ran by 1
					//}

		tempLetter = backLetter;
		uCrypted += tempLetter;

	}


	return uCrypted; //return NULL for now
}