#include<iostream>
#include<string>
using namespace std;

string ReadString(string message) {
	string word;

	cout << message << endl;
    getline(cin, word);


	return word;
}
string EncryptText(string text, short encryptionKey) {
	for (int i = 0;i <= text.length();i++) {
		text[i] = char((int)text[i] + encryptionKey);

	}
	return text;
}
string DecryptText(string text, short encryptionKey) {
	for (int i = 0;i <= text.length();i++) {
		text[i] = char((int)text[i] - encryptionKey);

	}
	return text;
}


int main() {
    const short EncryptionKey = 2; // Define a constant encryption key to be used for both encryption and decryption.

    string TextAfterEncryption, TextAfterDecryption;  // Variables to store the encrypted and decrypted text.

    // Read the original text from the user.
    string Text = ReadString("please enter a text : ");

    // Encrypt the text using the specified encryption key.
    TextAfterEncryption = EncryptText(Text, EncryptionKey);

    // Decrypt the text back to its original form using the same encryption key.
    TextAfterDecryption = DecryptText(TextAfterEncryption, EncryptionKey);

    // Display the original text.
    cout << "\nText Before Encryption : " << Text << endl;
    // Display the encrypted text.
    cout << "Text After Encryption  : " << TextAfterEncryption << endl;
    // Display the decrypted text.
    cout << "Text After Decryption  : " << TextAfterDecryption << endl;

    return 0;
	return 0;
}