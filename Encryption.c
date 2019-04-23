/*
 * The Caeser Cipher takes a string of text and produces an encrypted version of the text. 
 * It achieves this through moving the letters in the alphabet to the right i.e a=b, b=c, ..., y=z
 * This shift is of k = 1. Meaning that the key (k) shifts the letters to the right by 1.
 * Each letter will be given an allocated number i.e a = 0, b = 1, c = 2, ..., z = 25. 
 * Uppercase letters have an ASCII value, i.e A=65, B=66, C=67, ..., Z=90 as do Lowercase letters i.e a=97, b=98, c=99, ..., z=122.
 */



#include<stdio.h>

/*
 * Encryption function prototype. definined as function to reduce the amount of typing. This function is void as it will return no value
 */
void encryption(char message[550], char encrypted[550], int key); //has the char for message, encrypted and key as these will be carried throught the main fucntion and the encryption function



int main()
{
	char message[550], encrypted[550]; // defining the arrays at a boundary of 550 elements so that it can encypt and decrypt the first assessment part of 500+ character with spaces
	int key; // key is needed so that an the user can input the amount of shift
	
	printf("Enter a message to encrypt: \n"); //prompt for user to input the message
	scanf("%[^\n]", message); // scans the message and will stop at end of the string inlcuding special characters due to'%[^\n]' 
	printf("Enter key: \n"); // prompt for user to input a key that will determine the shift in the message
	scanf("%d", &key); // scans and stores the input in int key
	
	encryption (message, encrypted, key); // calling the encryption function
	
	printf("Encrypted message: %s\n", encrypted); // using the array from inside the encryption function in the main function
	
	return 0; // int main needs a return value
}

/*
 * Definition for function encryption
 */
void encryption(char message[550], char encrypted[550], int key){
   int i, text; // i is the itterating variable used to read characters from the array. Text is the variable where the value for the letters in the array can change and then be stored back into the encrypted array
   
   for(i = 0; message[i] != '\0'; i++){ // using i to count every character in the array
    text = message[i]; // stores element i of the message in a variable so that it can be manipulated

    if(text >= 'a' && text <= 'z'){ // tells the compiler that as long as the element i is between an ascii value ranging between and including a-z then add the key to it.
        text = text + key;

        if(text > 'z'){
            text = text - 'z' + 'a' - 1; // if the letter is z then add the ascii vaule for a to it and remove 1 for the new value
        }

        encrypted[i] = text; // stores the new value of the letter in the message to a new array which can then be printed to the screen
    }
    else if(text >= 'A' && text <= 'Z'){ // tells the compiler that as long as the element i is between an ascii value ranging between and including A-Z then add the key to it.
        text = text + key;

        if(text > 'Z'){
            text = text - 'Z' + 'A' - 1; // if the letter is Z then add the ascii vaule for A to it and remove 1 for the new value
        }

        encrypted[i] = text; // stores the new value of the letter in the message to a new array which can then be printed to the screen
    }
    else if(text == ' '){ // == ' ' allows for spaces between character to be read but not changed
        encrypted[i] = text;
    }
    else if(text == '.'){ // == '.' allows for the character period read but not changed
        encrypted[i] = text;
    }
    else if(text == ':'){ // == ':' allows for the character colon read but not changed
        encrypted[i] = text;
    }

  }
  
  //printf("Encrypted message: %s\n", encrypted);
}	// Function is of data type void and therefor does not need a return value
