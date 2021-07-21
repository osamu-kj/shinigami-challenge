#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

// global variables 
//char* sys_username = "admkevinj"; 
//char* sys_password = "password123"; 

#define prefix 189453; 

// defines 
#define one_margin_1 10; 
#define two_margin_1 245; 
#define three_margin_1 984; 
#define four_margin_1 one_margin_1 - three_margin_1 * (0 - two_margin_1); 

#define one_margin_2 one_margin_1 * two_margin_1 * prefix; 
#define two_margin_2 (prefix % two_margin_1) * one_margin_2; 
#define three_margin_2 ((((prefix && prefix) * prefix ) / prefix) * prefix) - one_margin_1 + (two_margin_1 * four_margin_1) / one_margin_2;
#define four_margin_2 (four_margin_1 % one_margin_2) - one_margin_2 * ((two_margin_2 % three_margin_2) * four_margin_1);
#define five_margin_2 (one_margin_2 * two_margin_2) && (one_margin_2 * two_margin_2) / (four_margin_2 + ((one_margin_1 * four_margin_1) / prefix) + one_margin_1) * prefix;

// functions 
void output_line() {printf("--------------------------------------------------------------------------------------------\n");}
void banner() {printf("  __ _     _       _                       _     ___\n / _\\ |__ (_)_ __ (_) __ _  __ _ _ __ ___ (_)   / _ \\_ __ ___   __ _ _ __ __ _ _ __ ___\n \\ \\| '_ \\| | '_ \\| |/ _` |/ _` | '_ ` _ \\| |  / /_)/ '__/ _ \\ / _` | '__/ _` | '_ ` _ \\ \n _\\ \\ | | | | | | | | (_| | (_| | | | | | | | / ___/| | | (_) | (_| | | | (_| | | | | | |\n \\__/_| |_|_|_| |_|_|\\__, |\\__,_|_| |_| |_|_| \\/    |_|  \\___/ \\__, |_|  \\__,_|_| |_| |_| \n                     |___/                                     |___/\n");}
void break_line() {printf("\n");}

int exit_program (char* message, int exit_code) {
	printf("[!!] %s", message); 
	return exit_code; 
}
int help(int status) {
	printf("Help Page:\n -> To Try The Keys You've Found: ./shinigami <username> <password>\n -> To Get The Welcome Message: ./shinigami message\n");
	
	// debug stuff 
	// printf("Return Status: %d\n", status); 
	return status;
}
void imp_message(char* message) {printf("[!!] %s\n", message); }

// check function
int check_keys(char* key1, char* key2) {
	// 1.1) check for the first character in string 
	
	if (sizeof(key1) < 3) return 0; 

	int first_char = (int) key1[0]; 
	int first_result = first_char * one_margin_1; 
	
	int 

	if (first_result == 970)
		printf("Good!");
	else
		printf("Not good!");
	printf ("%d\n", first_result); 
	
	return 1; 
}

// the main function
int main(int argc, char *argv[]) {
	banner(); 
	output_line(); 
	break_line(); 
	if (argc != 3 && argc != 2) return help(1);
	if (argc == 2 && strcmp(argv[1], "message")==0) { help(1); break_line(); return exit_program("Welcome to the deadland stranger! I am your shinigami, I'll be guiding you through the land and teach you the basics on how to survive in here\nBut to get inside you first have to crack down these big metal doors - get the two keys and become the next deadland's king! Good luck ;)! ", 1);} 
	else
		if (argc!=3) return help(2);
	
		char* username = (char*) argv[1]; 
		char* password = (char*) argv[2]; 
		imp_message("Validating the given keys..");

		// 1) validate the username 
		// 	- 1.1) check for the first character
		// 	- 1.2) check for the next 2 characters
		// 	- 1.3) check for the remaining characters
		// 	- 1.4) check if the odd bytes's sum is correct 
		// 2) validate the password 
		// 	- 2.1) check for the first 5 characters
		// 	- 2.2) check for the last 5 characters 
		// 	- 2.3) check if the odd bytes's sum is NOT correct 
		// 	- 2.4) check if the sum of all bytes is equal to 
		// 	- 2.5) check if the sum of a random sequence is correct  
	
		if (check_keys(username, password)==1) return exit_program("Congratulations! You have successfully entered the deadland, the next steps will be taken in the next challenge. Cya ;)", 0);
		else return exit_program("The two keys are wrong!", 0); 
	// normal exit 
	return 0; 
}
