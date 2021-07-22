#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

// global variables 
//char* sys_username = "DEVILJSDFO!#r)=(r#j)#rkorjs"; 
//char* sys_password = "J)OSKJDFdj)dj#$$opjko$ijRJRJfj()WJrWS"; 

#define prefix 189453 

// defines 
#define one_margin_1 10 
#define two_margin_1 245 
#define three_margin_1 984 
#define four_margin_1 (one_margin_1 - three_margin_1 * (0 - two_margin_1))

#define one_margin_2 ((one_margin_1 * two_margin_1 * prefix) % four_margin_1 + four_margin_1)
#define two_margin_2 (((prefix % two_margin_1) * one_margin_2) & one_margin_2 + four_margin_1)
#define three_margin_2 (((((prefix && prefix) * prefix ) / prefix) + prefix) % four_margin_1 + four_margin_1 - one_margin_1 + (two_margin_1 * four_margin_1) / one_margin_2)
#define four_margin_2 ((four_margin_1 % one_margin_2) - one_margin_2 * ((two_margin_2 % three_margin_2) / four_margin_1)) / one_margin_2 + four_margin_1
#define five_margin_2 ((one_margin_2 + two_margin_2 + (24 * four_margin_1)) + (one_margin_2 / two_margin_2) / (four_margin_2 + ((one_margin_1 * four_margin_1) / prefix) + one_margin_1) * prefix)

int sequence[5] = {1,4,2,5,6};

// functions 
void output_line() {printf("--------------------------------------------------------------------------------------------\n");}
void banner() {printf("  __ _     _       _                       _     ___\n / _\\ |__ (_)_ __ (_) __ _  __ _ _ __ ___ (_)   / _ \\_ __ ___   __ _ _ __ __ _ _ __ ___\n \\ \\| '_ \\| | '_ \\| |/ _` |/ _` | '_ ` _ \\| |  / /_)/ '__/ _ \\ / _` | '__/ _` | '_ ` _ \\ \n _\\ \\ | | | | | | | | (_| | (_| | | | | | | | / ___/| | | (_) | (_| | | | (_| | | | | | |\n \\__/_| |_|_|_| |_|_|\\__, |\\__,_|_| |_| |_|_| \\/    |_|  \\___/ \\__, |_|  \\__,_|_| |_| |_| \n                     |___/                                     |___/\n                    Built by: Kevin Jerebica AKA Osamu-KJ\n");}
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

int get_codes (char *string, int start, int end) {
	int distance = end - start;  
	int result = 0; 

	// format the two points 
	start--; end--; 

	for (int i = 0; i < distance+1; i++) {
		int tmp = (int) string[start + i]; 
		result += (int) tmp;
	}
	return result; 

}

int get_odd_codes(char *string) {
	int result = 0; 
	for (int i = 0; i < strlen(string); i++) {result += (int) string[i]; i++;}
	return result; 
}

int get_plus_odd_codes(char *string) {
	int result = 0; 
	for (int i = 1; i < strlen(string); i++) {result += (int) string[i]; i++;}
	return result; 
}

int get_all_codes(char *string) {
	int result = 0; 
	for (int i = 0; i < strlen(string); i++) {result += (int) string[i];}
	return result; 
}

int positive_out(int num) { int tmp = num; tmp = (tmp - num) + num; return tmp;}

// check function
int check_keys(char* key1, char* key2) {
	
	if (strlen(key1) < 3 || strlen(key2) < 5) return 0; 

	int first_char = (int) key1[0]; 
	int first_result = first_char * one_margin_1; 
	
	int second_result = get_codes(key1, 2, 3) * two_margin_1;

	int third_result = get_codes(key1, 4, strlen(key1)) * three_margin_1; 

	int fourth_result = get_odd_codes(key1) * four_margin_1; 

	// DEBUG STUFF 
	// printf(" - %d\n - %d\n - %d\n - %d\n", first_result, second_result, third_result, fourth_result);
	// printf(" ----- \n");
	
	
	// password checks 
	int one_layer_password = get_codes(key2, 1, 5) * one_margin_2;
	int two_layer_password = get_codes(key2, strlen(key2)-4, strlen(key2)) * two_margin_2;
	int three_layer_password = get_odd_codes(key2) * three_margin_2; 
	int four_layer_password = get_all_codes(key2) * four_margin_2; 
	int five_layer_password = get_plus_odd_codes(key2) * five_margin_2;

	// SOME MORE DEBUG STUFF 
	// printf(" - %d\n - %d\n - %d\n - %d\n - %d\n", one_layer_password, two_layer_password, three_layer_password, four_layer_password, five_layer_password);

	if (first_result == 680 && second_result == 41405 && third_result == 3475488 && fourth_result == 455901190 && one_layer_password == 116535650 && two_layer_password == 286785536 && three_layer_password == 406177447 && four_layer_password == 242600 && five_layer_password == 2007353218) return 1; 
	else return 0;
	return 0; 
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
	
		if (check_keys(username, password)==1) {
			printf("Congratulations! You have successfully entered the deadland, the next steps will be taken in the next challenge. Cya ;)\n - Credentials: \n  - Key 1 [Username]: %s\n  - Key 2 [Password]: %s\n", username, password);
			exit_program("Have a good day!", 0); 
		}
		else return exit_program("The two keys are wrong!", 0); 
	// normal exit 
	return 0; 
}
