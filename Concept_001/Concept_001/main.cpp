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

	//This generates each individal number that then becomes eKey (The actual encryption key)
	for (int i = 0; i < 24; i++) {
		eKey += to_string(KeyGen());
	}

	//Print out the encryption key to later decrypt the string
	cout << "Your encryption key, **KEEP THIS**:  " << eKey << endl;

	cout << "Enter in a string to be 'encrypted':  ";
	getline(cin, userInput);

	cout << "-=ENCRYPTION BEGIN=-" << endl; //DEBUG
	Encrypt(eKey, userInput, returnData);
	cout << "-=DECRYPTION BEGIN=-" << endl;
	uCrypt = Decrypt(eKey, returnData); //DEBUG

	cout << endl << "Here is your encryped string :  " << returnData << endl;
	cout << endl << "Here is the unencrypted string: " << uCrypt << endl;
	cin >> eKey;
	return NULL;
}

void Encrypt(string eKey, string data, string& returnData) {

	char backLetter;
	string eKeyBackup = eKey;
	int currKey = NULL;

	while (data.length() > 0) {

		if (eKey.length() == 0) {
			eKey = eKeyBackup;
		}

		backLetter = data.back();

		cout << "backLetter = " << backLetter << endl; //DEBUG
		data.pop_back();

		eKey.back() >> currKey;
		backLetter = backLetter + eKey.back();
		cout << "currKey = " << currKey << ", eKey.back() = " << eKey.back() << ", encryped letter = " << backLetter << ", data.length = " << data.length() << ", Run: " << runCount << endl; //DEBUG
		eKey.pop_back();
		runCount++; //Increase time ran by 1
		
		returnData += backLetter;

	}

}

int KeyGen() {

	int key = NULL;

	key = rand() % 9;

	return key;
}

string Decrypt(string eKey, string reverse) {

	char backLetter;
	string eKeyBackup = eKey;
	string uCrypt;
	string uCrypted;
	//string reverse;
	int currKey = NULL;

	//reset runCount to track decryption runs
	runCount = 1;

	while (reverse.length() > 0){
		uCrypt += reverse.back();
		reverse.pop_back();
	}


	while (uCrypt.length() > 0) {

		if (eKey.length() == 0) {
			eKey = eKeyBackup;
		}

		backLetter = uCrypt.back();

		cout << "backLetter = " << backLetter << endl; //DEBUG
		uCrypt.pop_back();

		eKey.back() >> currKey;
		backLetter = backLetter - eKey.back();
		cout << "currKey = " << currKey << ", eKey.back() = " << eKey.back() << ", unencryped letter = " << backLetter << ", data.length = " << uCrypt.length() << ", Run: " << runCount << endl; //DEBUG
		eKey.pop_back();
		runCount++; //Increase time ran by 1

		uCrypted += backLetter;

	}

	//This is needed to reverse the unencryped string because it is currently backwards
	while (uCrypted.length() > 0) {
		reverse += uCrypted.back();
		uCrypted.pop_back(); 
	}


	return reverse; //Returns the unencrypted string
}