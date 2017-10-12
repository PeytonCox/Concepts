#include <string>
#include <math.h>
#include <iostream>
#include <time.h>
using namespace std;

void Encrypt(string, string, string&);
int KeyGen();
string Decrypt(string, string);
int runCount = 1; //For debugging how many times the while loop has run
int debug = 0; //Controls debugging (0 = Off, 1 = On)

int main() {

	srand(time(NULL)); //Initialize the seed

	//INITIALIZING VARIABLES IN MAIN()
	string userInput; //string to be encrypted
	string returnData; //Encrypted Data
	string uCrypt; //Unencrypted Data
	string eKey = ""; //Initialize encryption key

	//This generates each individal number that then becomes eKey (The actual encryption key)
	for (int i = 0; i < 24; i++) {
		eKey += to_string(KeyGen());
	}

	//Print out the encryption key to later decrypt the string
	cout << "Your encryption key, **KEEP THIS**:  " << eKey << endl;

	//Takes in the input to be encrypted
	cout << "Enter in a string to be 'encrypted':  ";
	getline(cin, userInput);

	if (debug == 1) {
		cout << "-=ENCRYPTION BEGIN=-" << endl; //DEBUG
	}
	Encrypt(eKey, userInput, returnData); //Calls function to encrypt the supplied string
	if (debug == 1) {
		cout << "-=DECRYPTION BEGIN=-" << endl; //DEBUG
	}
	uCrypt = Decrypt(eKey, returnData); //Calls function to decrypt the encrypted string

	//Print out the encrypted and decrypted strings
	cout << endl << "Here is your encryped string :  " << returnData << endl;
	cout << endl << "Here is the unencrypted string: " << uCrypt << endl;

	cin >> eKey; //Basically pauses the program at the end, probably will replace
	return NULL; //Main() function return
}

void Encrypt(string eKey, string data, string& returnData) {

	//INITIALIZING VARIABLES
	char backLetter; //The back letter of the string to be encrypted
	string eKeyBackup = eKey; //Backup of encryption key to replace when it's been completely run through

	//Encryption loop, runs until entire supplied string has been run through
	while (data.length() > 0) {

		//if the encryption key has been used reset it here
		if (eKey.length() == 0) {
			eKey = eKeyBackup;
		}

		backLetter = data.back(); //Supply last character of string to backLetter

		if (debug == 1) {
			cout << "backLetter = " << backLetter << endl; //DEBUG
		}
		data.pop_back(); //Pop back of supplied string to allow for using data.back() next run

		backLetter = backLetter + eKey.back(); //Increase backLetter's value by the last value in eKey
		if (debug == 1) {
			cout << "eKey.back() = " << eKey.back() << ", encryped letter = " << backLetter << ", data.length = " << data.length() << ", Run: " << runCount << endl; //DEBUG
		}
		eKey.pop_back(); //Pop back of key to allow use of eKey.back() next run

		if (debug == 1) {
			runCount++; //Increase time ran by 1 (Used by debug)
		}
		
		returnData += backLetter; //add encrypted character to string that will be called in main()

	}

}

//Just randomly generates a number for the encryption key's generation
int KeyGen() {

	int key = NULL; //Initalize key

	key = rand() % 9; //Generate random number from 0-9 for key

	return key; //return value to be added to the end of eKey
}

string Decrypt(string eKey, string reverse) {

	//INITIALIZING VARIABLES
	char backLetter; //The back letter of the string to be decrypted
	string eKeyBackup = eKey; //Backup of encryption key to replace when it's been completely run through
	string uCrypt; 
	string uCrypted;

	//reset runCount to track decryption runs
	runCount = 1;

	//reverses the encrypted string so it can be decrypted appropriately
	while (reverse.length() > 0){
		uCrypt += reverse.back();
		reverse.pop_back();
	}

	//Runs decryption until it has run all the way throught the encrypted string
	while (uCrypt.length() > 0) {

		//if the encryption key has been used reset it here
		if (eKey.length() == 0) {
			eKey = eKeyBackup;
		}
		
		//supply the last letter of the encrypted string to backLetter
		backLetter = uCrypt.back();

		if (debug == 1) {
			cout << "backLetter = " << backLetter << endl; //DEBUG
		}
		//pop back of uCrypt so uCrypt.back() can be used next run
		uCrypt.pop_back();

		//Decrypt backLetter given the current value in eKey
		backLetter = backLetter - eKey.back();

		if (debug == 1) {
			cout << "eKey.back() = " << eKey.back() << ", unencryped letter = " << backLetter << ", data.length = " << uCrypt.length() << ", Run: " << runCount << endl; //DEBUG
		}

		//pops the back of eKey so it can use the appropriate value next run
		eKey.pop_back();

		if (debug == 1) {
			runCount++; //Increase time ran by 1 (Used by debug)
		}

		//add the decrypted character to the decrypted end product (will be backwards here)
		uCrypted += backLetter;

	}

	//This is needed to reverse the unencryped string because it is currently backwards
	while (uCrypted.length() > 0) {
		reverse += uCrypted.back();
		uCrypted.pop_back(); 
	}


	return reverse; //Returns the unencrypted string
}