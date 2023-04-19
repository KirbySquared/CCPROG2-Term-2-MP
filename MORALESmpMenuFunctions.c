#include <string.h>
#include <stdio.h>
/* This file will contain computations and other data assignments/data accessing code*/ 
typedef char String1[21];
typedef char String2[11];
typedef char QandA[81];
typedef char String3[31];
typedef char TimeString[7];
void UserRegistrationInput();
void SecondDoseInput();
void EditUserDetails();
void PrintAllUsers();
int IDChecker();
void AppReq();
int AppIDChecker();
void InitializeNoValStruct();
void EditAppDetails();
void DeleteAppRecord();
void PrintAllAppointments();
void InitializeChatBotQandA();
void PrintQandA();
void EditQandA();
void AddQandA();
int AppIDIndex();
void ExportUser();
void ExportApp();
void ExportChat();
void ImportUser();
void ImportApp();
void ImportChat();
int VaccineChecker();

struct UserRegistration
{
	long int nUserID;
	String2 sPassword;
	String1 sName;
	String3 sAddress;
	long long int nContact;
	String2 sSex;
	String2 sFirstDoseDate;
	String2 sFirstDoseVacc;
	String2 sFirstDoseLoc;
	String2 sSecondDoseDate;
	String2 sSecondDoseVacc;
	String2 sSecondDoseLoc;
	String2 sBoosterDoseDate;
	String2 sBoosterDoseVacc;
	String2 sBoosterDoseLoc;
}; //UserReg is alias to call and change data within struct UserRegistration

struct VaccinationAppointment
{
	long int nUserID;
	long int nAppID;
	String1 sName;
	String2 sLocation;
	String2 sVaccine;
	String2 sDate;
	String2 sDose;
	TimeString sTime;
}; //Appointment is alias to call and change data within struct UserRegistration

struct ChatBot
{
	QandA sQuestion;
	QandA sAnswer;
};
typedef struct UserRegistration FirstReg[100]; 
FirstReg UserReg;

typedef struct VaccinationAppointment SecondReg[100];
SecondReg Appointment;

typedef struct ChatBot ChatStuff[100];
ChatStuff Chatbot;

typedef struct UserRegistration TEMPUSER;
TEMPUSER TempUserReg;

typedef struct VaccinationAppointment TEMPVACC;
TEMPVACC TempApp;

typedef struct ChatBot CHAT;
CHAT TempChatbot;

typedef struct ChatBot DelQandA;
DelQandA DelQNA;

typedef struct VaccinationAppointment ClearApp;
ClearApp DelApp;

typedef struct UserRegistration Deletion;
Deletion DelReg;

/* AppReq sets a new appointment for a user by prompting the user to input information to be used for appointments.
@param int *NumOfUsers - pointer to the total number of users in the system.
@param int *AppCount - pointer to the total number of appointments in the system.
@return none since it is a void function
Pre-condition: The Appointment array and its elements are defined and initialized properly. The Appointment struct
contains fields for nUserID, nAppID, sName, sLocation, sVaccine, sDate, and sTime. User inputs data following the given formats
(no negatives) / within the string limitations.
 */
void
AppReq
(int *NumOfUsers, 
 int *AppCount)
{
	int ValidInput = 0;

	while (ValidInput == 0)
	{
		printf("\nCurrent user ID: %ld\n", Appointment[*AppCount].nUserID);

		printf("\nEnter App ID (Must be unique and numeric): ");
			scanf("%ld", &Appointment[*AppCount].nAppID);

		if (Appointment[*AppCount].nAppID <= 0)
		{
			printf("\nInvalid App ID!\n");
		}
		else if ( AppIDChecker(AppCount, Appointment[*AppCount].nAppID) == -2 || Appointment[*AppCount].nAppID == Appointment[(*AppCount)-1].nAppID)
		{
			printf("\nApp ID already exists!\n");
		}
		else
		ValidInput = 1;
	}
	ValidInput = 0;

	while (ValidInput == 0)
	{
		printf("Enter your name (maximum of 20 characters): ");
			scanf(" %[^\n]s", Appointment[*AppCount].sName);

		if (strlen (Appointment[*AppCount].sName) > 20)
		{
			printf("\nInvalid name!\n");
		}
		else
		ValidInput = 1;
	}
	ValidInput = 0;
	
	while (ValidInput == 0)
	{
		printf("Enter location of vaccination appointment: ");
			scanf(" %[^\n]", Appointment[*AppCount].sLocation);

		if ( strlen (Appointment[*AppCount].sLocation) > 10)
		{
			printf("\nInvalid location!\n");
		}
		else
		ValidInput = 1;
	}
	ValidInput = 0;

	while (ValidInput == 0)
	{
		printf("Enter your vaccine of choice: ");
			scanf(" %s", Appointment[*AppCount].sVaccine);

		if (strlen (Appointment[*AppCount].sVaccine) > 10 || VaccineChecker(Appointment[*AppCount].sVaccine) <= 0)
		{
			printf("Invalid vaccine!\n.");
		}
		else
		ValidInput = 1;
	}
	ValidInput = 0;							
	
	while (ValidInput == 0)
	{
		printf("Enter your vaccine date: ");
			scanf(" %s", Appointment[*AppCount].sDate);

			if (strlen (Appointment[*AppCount].sDate) > 11 || Appointment[*AppCount].sDate[4] != '-' 
		|| Appointment[*AppCount].sDate[7] != '-')
			{
				printf("\nInvalid vaccine date!\n");
			}
		else
		ValidInput = 1;
	}
	ValidInput = 0;							
								
	while (ValidInput == 0)
	{
		printf("Enter time for vaccination (24 hour format; 15:00 == 3:00 pm): ");
			scanf(" %s", Appointment[*AppCount].sTime);

			if (strlen (Appointment[*AppCount].sTime) > 5 || Appointment[*AppCount].sTime[2] != ':')
			{
				printf("\nInvalid vaccination time!\n");
			}
		else
		ValidInput = 1;
	}
	ValidInput = 0;							

	while (ValidInput == 0)
	{
		printf("Please indicate if this is your first, second, or booster dose: ");
			scanf(" %s", Appointment[*AppCount].sDose);

			if (strlen (Appointment[*AppCount].sDose) > 10 || ( stricmp(Appointment[*AppCount].sDose, "First") != 0 || 
			stricmp(Appointment[*AppCount].sDose, "Second") != 0 || stricmp(Appointment[*AppCount].sDose, "Booster") != 0 ) == 0)
			{
				printf("\nInvalid dose!\n");
			}
		else
		ValidInput = 1;
	}
	ValidInput = 0;														
						
		printf("\nYou have successfully set an appointment.");
		*AppCount += 1;
}

/* UserRegistrationInput prompts the user for new user information and adds it to the database.
User can choose if they want to add their second dose details or not.
@param int *NumOfUsers pointer to total number of users in the database
@return none since it is a void function
Pre-condition: The UserReg array and its elements are defined and initialized properly. The UserRegistration struct
contains fields for nUserID, sPassword, sName, sLocation, sAddress, nContact, sSex, sFirstDose, sFirstDoseVacc, sFirstDoseLocation.
User inputs data following the given formats (no negatives) / within the string limiations */
void 
UserRegistrationInput
(int *NumOfUsers)
{
	char cSecondDose;
	int ValidInput = 0;

	while (ValidInput == 0)
	{
		printf("\nEnter userID (Must be unique and numeric): ");
			scanf("%ld", &UserReg[*NumOfUsers].nUserID);

		if (UserReg[*NumOfUsers].nUserID <= 0)
		{
			printf("\nInvalid User ID!\n");
		}
		else if ( IDChecker(NumOfUsers, UserReg[*NumOfUsers].nUserID) == -2 || UserReg[*NumOfUsers].nUserID == UserReg[(*NumOfUsers)-1].nUserID)
		{
			printf("\nUser ID already exists!\n");
		}
		else
		ValidInput = 1;
	}
		ValidInput = 0;

	while (ValidInput == 0)
	{
		int z = 0;
		printf("Enter password (Maximum of 10 characters): ");
		//Loop to mask password being inputted
		while (  (UserReg[*NumOfUsers].sPassword[z] = getch() )  != 13 ) //13 = ASCII value of enter
		{
			if (UserReg[*NumOfUsers].sPassword[z] == 8 && z > 0)
       	 	{
            printf("\b \b");
            z--;
        	}
        else if (UserReg[*NumOfUsers].sPassword[z] != 8)
       		 {
            printf("*");
            z++;
       		 }
		}
		UserReg[*NumOfUsers].sPassword[z] ='\0';

		if ( strlen(UserReg[*NumOfUsers].sPassword) > 10)
		{
			printf("\nInvalid password!\n");
		}
		else
		ValidInput = 1;
	}
	ValidInput = 0;

	while (ValidInput == 0)
	{
		printf("\nEnter your name (Maximum of 20 characters): ");
			scanf(" %[^\n]s",UserReg[*NumOfUsers].sName);

			if (strlen(UserReg[*NumOfUsers].sName) > 20)	
			{
				printf("\nInvalid name!\n");
			}
			else
			ValidInput = 1;
	}
	ValidInput = 0;
				
	while (ValidInput == 0)
	{
		printf("Enter your address (Maximum of 30 characters): ");
			scanf(" %[^\n]s", UserReg[*NumOfUsers].sAddress);

			if(strlen(UserReg[*NumOfUsers].sAddress) > 30)
			{
				printf("\nInvalid address!\n");
			}
			else
			ValidInput = 1;
	}
	ValidInput = 0;
						
	while (ValidInput == 0)
	{
		printf("Enter your contact number (Must be numeric and a valid number): ");
			scanf("%lld", &UserReg[*NumOfUsers].nContact);

		if (UserReg[*NumOfUsers].nContact < 8130000000)
		printf("\nInvalid Contact No.!\n");
		else
		ValidInput = 1;
	}
	ValidInput = 0;
							
	while (ValidInput == 0)
	{
		printf("Enter your sex (Male / Female): ");
			scanf(" %s", UserReg[*NumOfUsers].sSex);

			if (stricmp(UserReg[*NumOfUsers].sSex, "Male") != 0 && stricmp(UserReg[*NumOfUsers].sSex, "Female") != 0)
			{
				printf("\nInvalid sex entered!\n");
			}
			else
			ValidInput = 1;
	}
	ValidInput = 0;
							
	while (ValidInput == 0)
	{
		printf("Enter your first dose date (YYYY-MM-DD): ");
			scanf(" %s", UserReg[*NumOfUsers].sFirstDoseDate);

		if (strlen (UserReg[*NumOfUsers].sFirstDoseDate) > 10 || UserReg[*NumOfUsers].sFirstDoseDate[4] != '-' 
		|| UserReg[*NumOfUsers].sFirstDoseDate[7] != '-')
		{
			printf("\nInvalid First Dose Date!\n");
		}	
		else
		ValidInput = 1;
	}
	ValidInput = 0;		
	
	while (ValidInput == 0)
	{
		printf("Enter your first dose vaccine (Moderna, Pfizer...): ");
			scanf(" %s", UserReg[*NumOfUsers].sFirstDoseVacc);

		if (strlen (UserReg[*NumOfUsers].sFirstDoseVacc) > 10 || VaccineChecker(UserReg[*NumOfUsers].sFirstDoseVacc) <= 0)
			{
				printf("\nInvalid First Dose Vaccine!\n");
			}
		else
		ValidInput = 1;
	}
	ValidInput = 0;
	
	while (ValidInput == 0)
	{
		printf("Enter your first dose location: ");
			scanf(" %s", UserReg[*NumOfUsers].sFirstDoseLoc);
										
				if (strlen(UserReg[*NumOfUsers].sFirstDoseLoc) > 10)
				{
					printf("\nInvalid First Dose Location!\n");
				}
		else
		ValidInput = 1;
	}
	ValidInput = 0;								
	
	while (cSecondDose != 'Y' && cSecondDose != 'y' && cSecondDose != 'N' && cSecondDose != 'n')
		{	
			printf("\nWould you like to register your second dose details? (Y/N): ");
				scanf(" %c", &cSecondDose);
													
				switch (cSecondDose)
				{
					case 'Y':
					case 'y': SecondDoseInput(NumOfUsers);
					break;
					case 'N': 
					case 'n': 
					printf("You have been successfully registered!");
					printf("\nGoing back to previous menu . . .");
					*NumOfUsers += 1;
					break;
					default: printf("\nInvalid Input. Please input again.");
					break;
				}
		}
			//printf("\nBEFORE NUM: %d", *NumOfUsers);
			//printf("\nCURRENT NUM: %d", *NumOfUsers);	
			/* if ( strcmp(TempUserReg.sFirstDoseLoc, "") == 0 && strcmp(TempUserReg.sFirstDoseDate, "") == 0 && strcmp(TempUserReg.sFirstDoseVacc, "") == 0)
			{
				strcpy(TempUserReg.sFirstDoseLoc, " ");
				strcpy(TempUserReg.sFirstDoseDate, " ");
				strcpy(TempUserReg.sFirstDoseVacc, " ");
			}
			if ( strcmp(TempUserReg.sSecondDoseLoc, "") == 0 && strcmp(TempUserReg.sSecondDoseDate, "") == 0 && strcmp(TempUserReg.sSecondDoseVacc, "") == 0)
			{
				strcpy(TempUserReg.sSecondDoseLoc, " ");
				strcpy(TempUserReg.sSecondDoseDate, " ");
				strcpy(TempUserReg.sSecondDoseVacc, " ");
			}
			if ( strcmp(TempUserReg.sBoosterDoseLoc, "") == 0 && strcmp(TempUserReg.sBoosterDoseDate, "") == 0 && strcmp(TempUserReg.sBoosterDoseVacc, "") == 0)
			{
				strcpy(TempUserReg.sBoosterDoseLoc, " ");
				strcpy(TempUserReg.sBoosterDoseDate, " ");
				strcpy(TempUserReg.sBoosterDoseVacc, " ");
			} */
}

/* SecondDoseInput prompts the user to input their second dose details including date, vaccine, and location. 
If the user opts to register a booster dose, the function will also prompt the user to input the booster dose details. 
Once all details have been successfully registered, the function updates the NumOfUsers count.
@paramint *NumOfUsers - pointer to the current number of registered users
@return none since it is a void function
Pre-condition: User chose to input their Second Dose details, UserReg array and its elements are properly initialized.
The UserRegistration struct contains the fields for the second / booster dose details 
User inputs data with the correct data format (no negatives) / within the string limiations*/
void 
SecondDoseInput
(int *NumOfUsers)
{
	char cOption;
	int ValidInput = 0;

	while (ValidInput == 0)
	{
		printf("\nEnter your second dose date (YYYY-MM-DD): ");
			scanf(" %s", UserReg[*NumOfUsers].sSecondDoseDate);

		if (strlen (UserReg[*NumOfUsers].sSecondDoseDate) > 10 || UserReg[*NumOfUsers].sSecondDoseDate[4] != '-' || 
		UserReg[*NumOfUsers].sSecondDoseDate[7] != '-')	
		{
			printf("\nInvalid Second Dose Date!\n");
		}
		else
		ValidInput = 1;
	}
	ValidInput = 0;	

	while (ValidInput == 0)
	{
		printf("Enter your second dose vaccine (Moderna, Pfizer...): ");
			scanf(" %s", UserReg[*NumOfUsers].sSecondDoseVacc);

		if (strlen(UserReg[*NumOfUsers].sSecondDoseVacc) > 10 || 
		stricmp(UserReg[*NumOfUsers].sFirstDoseVacc,UserReg[*NumOfUsers].sSecondDoseVacc) != 0)
		{
			printf("\nInvalid Second Dose Vaccine!\n");
		}
		else
		ValidInput = 1;
	}
	ValidInput = 0;	
	
	while (ValidInput == 0)
	{
		printf("Enter your second dose location: ");
			scanf(" %[^\n]s", UserReg[*NumOfUsers].sSecondDoseLoc);

		if (strlen(UserReg[*NumOfUsers].sSecondDoseLoc) > 10)
		{
			printf("\nInvalid Second Dose location!\n");
		}
		else
		ValidInput = 1;
	}
	ValidInput = 0;	
			
	while (cOption != 'Y' && cOption != 'y' && cOption != 'N' && cOption != 'n')
		{	
			printf("\nWould you like to register your booster dose details? (Y/N): ");
				scanf(" %c", &cOption);
					
				switch (cOption)
				{
					case 'Y':
					case 'y': 
					while (ValidInput == 0)
					{
						printf("\nEnter your booster dose date (YYYY-MM-DD): ");
							scanf(" %s", UserReg[*NumOfUsers].sBoosterDoseDate);

						if (strlen (UserReg[*NumOfUsers].sBoosterDoseDate) > 10 || UserReg[*NumOfUsers].sBoosterDoseDate[4] != '-' || 
						UserReg[*NumOfUsers].sSecondDoseDate[7] != '-')
						printf("\nInvalid Booster Dose Date!\n");
						else
						ValidInput = 1;
					}
						ValidInput = 0;	
					
					while (ValidInput == 0)
					{
						printf("Enter your booster dose vaccine (Moderna, Pfizer, etc...): ");
							scanf(" %s", UserReg[*NumOfUsers].sBoosterDoseVacc);

						if (strlen (UserReg[*NumOfUsers].sBoosterDoseVacc) > 10 || 
						stricmp(UserReg[*NumOfUsers].sFirstDoseVacc,UserReg[*NumOfUsers].sBoosterDoseVacc) != 0)
						{
							printf("\nInvalid Booster Dose Date!\n");
						}
						else
						ValidInput = 1;
					}
						ValidInput = 0;	

					while (ValidInput == 0)
					{
						printf("Enter your booster dose location: ");
							scanf(" %[^\n]s", UserReg[*NumOfUsers].sBoosterDoseLoc);

						if (strlen (UserReg[*NumOfUsers].sBoosterDoseLoc) > 10)
						{
							printf("\nInvalid Booster Dose Location!\n");
						}
						else
						ValidInput = 1;
					}
						ValidInput = 0;	
						
							printf("You have been successfully registered!");
							printf("\nGoing back to previous menu . . .");
							*NumOfUsers += 1;

						break;
						case 'N': 
						case 'n': 
								printf("You have been successfully registered!");
								printf("\nGoing back to previous menu . . .");
							*NumOfUsers += 1;
						break;
						default: printf("\nInvalid Input. Please input again.");
						break;
				}
		}	
}

/* EditUserDetails prompts the user to select a user to edit from the list of all registered users, and allows the user to modify their registration information.
If the selected user number is invalid, the function will prompt the user to try again.
The function will continue to allow the user to edit users until they choose to exit.
@param int *index - pointer to the current number of registered users
@return none since it is a void function
Pre-condition: User chose to edit their registration details, UserReg array and its elements are properly initialized.
The UserRegistration struct contains the fields for the registration details that can be edited. And all UserIDs are unique.
int *NumOfUsers is correct.
User inputs data following the given formats / within the string limiations*/
void EditUserDetails 
(int *index)
{
	int i = 0;
	char cOption;

	while (cOption != 'N' && cOption != 'n')
	{
		PrintAllUsers(index);
		if (*index > 0)
		{
			printf("\nSELECT WHICH USER YOU WANT TO EDIT: (INPUT USER #NUMBER ONLY)\n");
				scanf("%d", &i);
			i -= 1;
			if (i < *index && i >= 0)
			{
				UserRegistrationInput(&i);
				printf("\nWould you like to edit another user? (Y/N): ");
				scanf(" %c", &cOption);
			}
			else
			{
				printf("\nINVALID USER #NUMBER DETECTED. PLEASE TRY AGAIN.");
			}
		}
		else
		{
			printf("\nNO MORE USERS DETECTED!");
			cOption = 'N';
		}
	}

	printf("\nGoing back to previous menu . . . ");

}

/* DeleteUserRecord prompts the user to select a user to delete from the list of all registered users, and removes their registration information from the UserReg array.
If the selected user number is invalid, the function will prompt the user to try again.
The function will continue to allow the user to delete users until they choose to exit.
@param int *index - pointer to the current number of registered users
@return none since it is a void function
Pre-condition: User chose to delete a user's registration details which exists in the database,
UserReg array and its elements are properly initialized.
int *Index is correct. */
void 
DeleteUserRecord 
(int *index)
{
	int nDel = 0;
	int i;
	char cDeletion;

	while (cDeletion != 'N' && cDeletion != 'n')
	{
		cDeletion = 'Z';
		PrintAllUsers(index);
		if (*index > 0)
		{
			printf("\nSELECT WHICH USER YOU WANT TO DELETE: (INPUT USER #NUMBER ONLY)\n");
				scanf("%d", &nDel);
		
			nDel -= 1;
			for (i = nDel; i<*index-1; i++)
			{
				UserReg[i] = UserReg[i+1];
				UserReg[i+1] = DelReg;
			}
			*index -= 1;
			printf("\nDELETION COMPLETE.");
			printf("HERE IS THE UPDATED LIST: ");
			PrintAllUsers(index);
		}
		if(*index <= 0)
		{
			printf("\nNO MORE USERS DETECTED!");
			cDeletion = 'N';
		}
		else
		{
			while (cDeletion != 'N' && cDeletion != 'n' && cDeletion != 'Y' && cDeletion != 'y')
			{
				printf("\nWould you like to delete another users' details? (Y/N) ");
					scanf(" %c", &cDeletion);
				
				switch (cDeletion)
				{
					case 'N':
					case 'n': break;
					case 'Y':
					case 'y': break;
					default: printf("\nInvalid option. Please pick again."); break;
				}
			}
		}
			
	}

	printf("\nGoing back to the previous menu. . .");
	
}

/* IDIndex finds the index of the given userID in the UserReg array, and returns the index value.
If the given userID does not exist in the array, the function will return -1.
@param int *index - pointer to the current number of registered users
@param int InputtedID - the userID to search for in the UserReg array
@return int - the index of the given userID, or -1 if the userID does not exist in the array
Pre-condition: UserReg array and its elements are properly initialized.
The nUserID field of the UserRegistration struct is unique for each registered user.
int *Index is correct.
UserID is unique in the database, and numeric. */
int 
IDIndex
(int *index,
int InputtedID)
//Finds the index of the given userID, Precondition is that the given userID is already unique.
{
	int i = 0;
	int value = -1; //-1 if userID does not exist in the user ids.
	for (i = 0; i <= *index; i++)
	{
		if (UserReg[i].nUserID == InputtedID)
		{
			value = i;
			i = *index; // to stop the loop
		}
	}

	return value;
}

/* IDChecker checks if the given IDtoCheck already exists in the UserReg array.
If the given IDtoCheck exists in the array, the function will return the index of the ID.
If the given IDtoCheck does not exist in the array, the function will return -1.
If the given IDtoCheck exists in the array but is not unique, the function will return -2.
@param int *index - pointer to the current number of registered users
@param int IDtoCheck - the userID to check for in the UserReg array
@return int - the index of the given userID, or -1 if the userID does not exist in the array,
or -2 if the userID exists in the array but is not unique
Pre-condition: UserReg array and its elements are properly initialized.*/
int 
IDChecker
(int *index, 
int IDtoCheck)
{ //Checks if UserID in the user reg menu already exists or not
  //Returns the Index of userID being checked as long as it is a unique userID
  //This only checks the userIDS from indexes 0 -> TotalNumCoun;
	int i = 0;
	int value = -1;
	for (i = 0; i <= *index; i++)
	{
		if (UserReg[i].nUserID == IDtoCheck && i == *index)
		{
			value = i;
		}
		else if (UserReg[i].nUserID == IDtoCheck && i != *index)
		{
			value = -2;
			i = *index;
		}
	}

	return value;
}

/* AppIDIndex checks if the given AppID already exists in the Appointment array and returns its index if it does.
If the AppID is not found, the function returns -1.
@param int *AppCount - pointer to the current number of appointments
@param int AppIDCheck - the AppID to check for in the Appointment array
@return int value - the index of the AppID in the Appointment array, or -1 if the AppID is not found.
Pre-condition: The Appointment array is properly initialized with valid appointment records.
AppID is unique in the database and numeric */
int 
AppIDIndex
(int *AppCount, 
int AppIDCheck)
{ 
  //Checks if AppID in the user reg menu already exists or not
  //Returns the Index of AppID being checked as long as it is a unique AppID
  //This only checks the AppIDs from indexes 0 -> TotalNumCount;
	int i = 0;
	int value = -1;
	for (i = 0; i <= *AppCount; i++)
	{
		if (Appointment[i].nAppID == AppIDCheck)
		{
			value = i;
			i = *AppCount;
		}
	}

	return value;
}

/*
AppIDChecker checks if the given appointment ID already exists in the Appointment array or not.
If the appointment ID is already present in the Appointment array, the function will return the index of that appointment ID.
If the AppID does not exist, the function returns -1.
If the appointment ID is not unique, the function will return -2.
This only checks the AppIDs from indexes 0 -> TotalNumCount.
@param int *AppCount - pointer to the current number of appointments
@param int AppIDtoCheck - the appointment ID to be checked
@return int - the index of the appointment ID or -2 if the appointment ID is not unique.
Pre-condition: The Appointment array is properly initialized and contains valid appointment information up to *AppCount index.
*/
int 
AppIDChecker
(int *AppCount, 
int AppIDtoCheck)
{ 
  //Checks if AppID in the user reg menu already exists or not
  //Returns the Index of AppID being checked as long as it is a unique AppID
  //This only checks the AppIDs from indexes 0 -> TotalNumCount;
	int i = 0;
	int value = -1;
	for (i = 0; i <= *AppCount; i++)
	{
		if (Appointment[i].nAppID == AppIDtoCheck && i == *AppCount)
		{
			value = i;
		}
		else if (Appointment[i].nAppID == AppIDtoCheck && i != *AppCount) //If AppID is not unique, result gives back -2 instead of AppID Index
		{
			value = -2;
			i = *AppCount;
		}
	}

	return value;
}

/* PassChecker compares the password entered by the user to the password stored in the UserReg array at the specified index.
If the passwords match, the function returns 1, otherwise it returns 0.
@param int *index - pointer to the current number of registered users
@param char *c - pointer to the password entered by the user
@param int IDindex - the index of the user in the UserReg array whose password should be checked
@return 1 if the passwords match, 0 otherwise
Pre-condition: UserReg array and its elements are properly initialized. And the index passed 
is correct. */
int PassChecker(int *index, char *c, int IDindex)
{
	int value = 0;

			if ( strcmp(UserReg[IDindex].sPassword, c) == 0)
			value = 1;

	return value;
}

/* ManageAppointment is a function that allows a user to manage their appointment.
The user is prompted to enter their appointment ID, and if it exists, they are presented with a menu that allows them to
cancel their appointment, reschedule the date and time of their appointment, or change the vaccination center location and brand.
@param int *NumOfUsers - pointer to the number of users in the system
@param int *AppCount - pointer to the number of appointments in the system
Pre-condition: Appointment array and its elements are properly initialized. And the index passed
is correct. User also chose the manage appointment menu, and the data the user inputs follows the string limitations / 
data format*/
void 
ManageAppointment
(int *NumOfUsers, 
int *AppCount)
{
	int AppChoice = 0;
	long int IdTemp;
	int index = -1;
	char cChoice;

	while ( index == -1 && IdTemp != -999)
	{
		printf("\nInput your AppID (Input -999 if you wish to exit the menu): ");
			scanf("%ld", &IdTemp);
		if (IdTemp != -999)
		{
			if (AppIDIndex(AppCount, IdTemp) == -1)
			printf("\nApp ID does not exist. Enter again");
			else
			index = AppIDIndex(AppCount, IdTemp);
		}
	}

	if (IdTemp != -999)
	{
		while (AppChoice != 4)
		{
			cChoice = 'z';
			printf("\nUser ID: %ld, Name: %s, \nYou have an appointment on %s at %s", Appointment[index].nUserID,Appointment[index].sName, Appointment[index].sDate, 
			Appointment[index].sTime);
			printf("\nThis is your %s dose of the %s Vaccine.",  Appointment[index].sDose,  Appointment[index].sVaccine);
			printf("\nTo be administered at the location: %s\n",Appointment[index].sLocation);
		
			printf("\n1. Cancel Appointment");
			printf("\n2. Reschedule date and time");
			printf("\n3. Change Vaccination center location and Vaccination Brand");
			printf("\n4. Exit");

			printf("\nEnter your choice: ");
				scanf("%d", &AppChoice);

				switch (AppChoice)
				{
					case 1: printf("\nAre you sure you want to cancel your appointment? (Y/N): ");
					while ( cChoice != 'Y' && cChoice != 'y' && cChoice != 'N' && cChoice != 'n')
						{ 	printf("\nEnter your choice: ");
							scanf(" %c", &cChoice);

							switch (cChoice)
							{
								case 'Y':
								case 'y': Appointment[index] = DelApp;
								for (int i = index; i<*AppCount-1; i++)
								{
									Appointment[i] = Appointment[i+1];
								}
								*AppCount-=1;
								printf("\nAppointment cancelled."); 
								AppChoice = 4;
								break;
								case 'N':
								case 'n': printf("\nAppointment was NOT cancelled."); break;
								default: printf("\nInvalid option. Please pick again. ");
								break;
							}
						}
							break;
					case 2: printf("\nPlease input your new Date: ");
							scanf(" %s", Appointment[index].sDate);
							printf("Please input your new Time: ");
							scanf(" %s", Appointment[index].sTime);
								printf("\nUser ID: %ld, Name: %s, \nYou have an appointment on %s at %s", Appointment[index].nUserID,Appointment[index].sName, Appointment[index].sDate, 
									Appointment[index].sTime);
									printf("\nThis is your %s dose of the %s Vaccine.",  Appointment[index].sDose,  Appointment[index].sVaccine);
									printf("\nTo be administered at the location: %s\n",Appointment[index].sLocation);
							break;
					case 3: printf("Please input your new vaccination center location: ");
							scanf(" %[^\n]s", Appointment[index].sLocation);
							printf("\nPlease input your new vaccination Brand: ");
							scanf(" %s", Appointment[index].sVaccine);
								printf("\nUser ID: %ld, Name: %s, \nYou have an appointment on %s at %s", Appointment[index].nUserID,Appointment[index].sName, Appointment[index].sDate, 
									Appointment[index].sTime);
									printf("\nThis is your %s dose of the %s Vaccine.",  Appointment[index].sDose,  Appointment[index].sVaccine);
									printf("\nTo be administered at the location: %s\n",Appointment[index].sLocation);
							AppChoice = 4;
							break; 
					case 4: printf("\nGoing back to the previous menu. . .");
							break; 
					default: printf("\nInvalid option. Please pick again."); 
					break;
				}
		}
	}
}

/*
AddQandA prompts the user to input a new question and answer for the chatbot. 
The function ensures that the inputted question and answer are each less than or equal to 80 characters in length, and not case-sensitive.
The function then adds the new question and answer to the Chatbot array.
@param int *count - pointer to the current number of questions in the Chatbot array
@return none since it is a void function
Pre-condition: User has chosen to add a new question and answer to the Chatbot, 
Chatbot array and its elements are properly initialized, and the strings inputted are within the 80 character limit.
*/
void 
AddQandA
(int *count)
{
	int Valid = 0;
	while (Valid == 0)
	{
		printf("\nPLEASE INPUT YOUR QUESTION HERE (MAX OF 80 CHARACTERS AND NOT CASE SENSITIVE): \n");
		printf("\nQ%d: ", *count+1);
			scanf(" %[^\n]", Chatbot[*count].sQuestion);

		if (strlen(Chatbot[*count].sQuestion) <= 80)
		Valid = 1;
		else
		printf("\nYOU HAVE INPUTTED AN INVALID QUESTION. PLEASE TRY AGAIN");
	}
	Valid = 0;

	while (Valid == 0)
	{
			printf("\nPLEASE INPUT YOUR ANSWER HERE (MAX OF 80 CHARACTERS AND NOT CASE SENSITIVE): \n");
			printf("\nA%d: ", *count+1);
				scanf(" %[^\n]s", Chatbot[*count].sAnswer);

		if (strlen(Chatbot[*count].sAnswer) <= 80)
		Valid = 1;
		else
		printf("\nYOU HAVE INPUTTED AN INVALID ANSWER. PLEASE TRY AGAIN");
	}
	Valid = 0;

	*count += 1;
	printf("\nNEW QUESTIONS AND ANSWERS HAVE BEEN ADDED.\n");
	printf("Going back to previous menu . . .\n");
}

/*
EditQandA allows the user to select a previously added question from the Chatbot array and edit its corresponding answer.
The function first displays the current list of questions and answers in the Chatbot array.
The user is then prompted to input the number of the question they wish to edit.
If the input is valid, the AddQandA function is called to allow the user to input a new answer for the selected question.
The function then displays the updated list of questions and answers, and prompts the user to decide whether to edit another question or not.
@param int *count - pointer to the current number of questions in the Chatbot array
@return none since it is a void function
Pre-condition: User has chosen to edit a question and answer in the Chatbot.
Chatbot array and its elements are properly initialized, and the strings inputted are within the 80 character limit.
int *count is correct. User chooses to edit existing QandA
*/
void 
EditQandA
(int *count)
{
	int i = 0;
	char cOption;

	while (cOption != 'N' && cOption != 'n')
	{
		PrintQandA(count);
		if (*count > 0)
		{
			printf("\nSELECT WHICH QUESTION YOU WANT TO EDIT: (INPUT QUESTION #NUMBER ONLY)\n");
				scanf("%d", &i);
			i -= 1;
			if (i < *count && i >= 0)
			{	
				AddQandA(&i);
				printf("\nHERE IS THE UPDATED LIST OF QUESTIONS AND ANSWERS:\n");
				PrintQandA(count);
				cOption = 'Z';
				while (cOption != 'N' && cOption != 'n' && cOption != 'Y' && cOption != 'y')
				{
					printf("\nWould you like to edit another question? (Y/N): ");
					scanf(" %c", &cOption);

					switch (cOption)
					{
						case 'N':
						case 'n': break;
						case 'Y': 
						case 'y': break;
						default: printf("\nInvalid option. Please pick again."); break;
					}
				}
			}
			else
			{
				printf("\nINVALID QUESTION #NUMBER DETECTED. PLEASE TRY AGAIN.");
			}
		}
		else
		{
			printf("\nNO MORE QUESTIONS AND ANSWERS DETECTED!");
			cOption = 'N';
		}
	}

	printf("\nGoing back to previous menu . . . ");

}

/*
DeleteQandA allows the user to select and delete a question and its corresponding answer from the Chatbot array.
The function prompts the user to select a question by inputting the question's number, and then deletes the corresponding question and answer by shifting all subsequent questions and answers to the left in the array.
The function then prompts the user if they would like to delete another question, and continues deleting questions until the user chooses to stop.
@param int *count - pointer to the current number of questions in the Chatbot array
@return none since it is a void function
Pre-condition: User has chosen to delete a question and answer from the Chatbot, 
Chatbot array and its elements are properly initialized, int *count is correct.
User chooses to delete existing QandA
*/
void 
DeleteQandA
(int *count)
{
	int i = 0;
	char cOption;

	while (cOption != 'N' && cOption != 'n')
	{
		PrintQandA(count);
		if (*count > 0)
		{
			printf("\nSELECT WHICH QUESTION YOU WANT TO DELETE: (INPUT QUESTION #NUMBER ONLY)\n");
				scanf("%d", &i);
				i -= 1;

			if (i < *count && i >= 0)
			{	
				for (int j = i; j < *count-1; j++)
				{
					Chatbot[j] = Chatbot[j+1];
				}
				*count -= 1;
				printf("\nHERE IS THE UPDATED LIST OF QUESTIONS AND ANSWERS:\n");
				PrintQandA(count);

				if (*count <= 0)
				{
					printf("\nNO MORE USERS DETECTED!");
					cOption = 'N';
				}
				char cOption = 'Z';
				while (cOption != 'N' && cOption != 'n' && cOption != 'Y' && cOption != 'y')
				{
					printf("\nWould you like to delete another question? (Y/N): ");
					scanf(" %c", &cOption);

					switch (cOption)
					{
						case 'N':
						case 'n': break;
						case 'Y':
						case 'y': break;
						default: printf("\nInvalid option. Please pick again."); break;
					}
				}
			}
			else
			{
				printf("\nINVALID QUESTION #NUMBER DETECTED. PLEASE TRY AGAIN.");
			}
		}
		else
		{
			printf("\nNO MORE QUESTIONS AND ANSWERS DETECTED!");
			cOption = 'N';
		}
	}

	printf("\nGoing back to previous menu . . . ");

}

/*
DeleteAppRecord prompts the user to select a user to delete from the Appointment array.
The function removes the selected user's details from the array and updates the count of total appointments.
@param int *AppCount - pointer to the current number of appointments in the Appointment array
@return none since it is a void function
Pre-condition: User has chosen to delete an appointment, Appointment array and its elements are properly initialized.
int *AppCount is correct. User chooses to delete an existing appointment
*/
void
DeleteAppRecord
(int *AppCount)
{
	int nDel = 0;
	int i;
	char cDeletion;

	while (cDeletion != 'N' && cDeletion != 'n')
	{
		PrintAllAppointments(AppCount);
		if (*AppCount > 0)
		{
			printf("\nSELECT WHICH USER YOU WANT TO DELETE: (INPUT USER #NUMBER ONLY)\n");
				scanf("%d", &nDel);
		
			nDel -= 1;
			for (i = nDel; i<*AppCount-1; i++)
			{
				Appointment[i] = Appointment[i+1];
			}
			*AppCount -= 1;
			printf("\nDELETION COMPLETE.");
			printf("HERE IS THE UPDATED LIST: ");
			PrintAllAppointments(AppCount);
		}
		if(*AppCount <= 0)
		{
			printf("\nNO MORE USERS DETECTED!");
			cDeletion = 'N';
		}
		else
		{
			cDeletion = 'Z';
			while (cDeletion != 'N' && cDeletion != 'n' && cDeletion != 'Y' && cDeletion != 'y')
			{
				printf("\nWould you like to delete another users' details? (Y/N) ");
					scanf(" %c", &cDeletion);
				
				switch (cDeletion)
				{
					case 'N':
					case 'n': break;
					case 'Y':
					case 'y': break;
					default: printf("\nInvalid option. Please pick again."); break;
				}
			}
		}
			
	}

	printf("\nGoing back to the previous menu. . .");
}

/*
EditAppDetails prompts the user to select an appointment to edit by inputting the corresponding user number.
The function then calls the AppReq function to allow the user to make changes to the selected appointment's details.
@param int *NumOfUsers - pointer to the current number of users in the system
@param int *AppCount - pointer to the current number of appointments in the system
@return none since it is a void function
Pre-condition: User has chosen to edit an appointment, Appointments array and its elements are properly initialized.
User follows the correct data input formats (no negatives), and within the string limitations.
int *AppCount is correct.
*/
void
EditAppDetails
(int *NumOfUsers, int *AppCount)
{
	int i = 0;
	char cOption;

	while (cOption != 'N' && cOption != 'n')
	{
		PrintAllAppointments(AppCount);
		if (*AppCount > 0)
		{
			printf("\nSELECT WHICH USER YOU WANT TO EDIT: (INPUT USER #NUMBER ONLY)\n");
				scanf("%d", &i);
			i -= 1;
			if (i < *AppCount && i >= 0)
			{
				AppReq(NumOfUsers, &i);
				printf("\nWould you like to edit another user? (Y/N): ");
				scanf(" %c", &cOption);
			}
			else
			{
				printf("\nINVALID USER #NUMBER DETECTED. PLEASE TRY AGAIN.");
			}
		}
		else
		{
			printf("\nNO MORE USERS DETECTED!");
			cOption = 'N';
		}
	}

	printf("\nGoing back to previous menu . . . ");
}

/*
ChatBotQandA searches the Chatbot array for a question string that matches the inputted question.
If a match is found, it returns the index of the corresponding answer string in the array.
@param char *Question - pointer to the string containing the user's question
@return int value - the index of the corresponding answer string in the Chatbot array, or -1 if no match is found
Pre-condition: Chatbot array and its elements are properly initialized.
*/
int ChatBotQandA (char *Question) //To give the answer to the appropriate question string inputted
{
	int value = -1;
	for (int i = 0; i < 100; i++)
	{
		if (stricmp(Question, Chatbot[i].sQuestion) == 0)
		{
			value = i;
			i = 100;
		}
	}
	return value;
}

/*
InitializeNoValStruct initializes the DelReg, DelApp, and DelQNA structs to their default values.
The function sets all integer variables to 0, and all string variables to empty strings.
@return none since it is a void function
Pre-condition: The structs DelReg, DelApp, and DelQNA are defined with their respective variables properly initialized.
*/
void 
InitializeNoValStruct()
{
	DelReg.nUserID = 0;
	DelReg.nContact = 0;
	strcpy(DelReg.sAddress, "" );
	strcpy(DelReg.sBoosterDoseDate, "N/A" );
	strcpy(DelReg.sBoosterDoseLoc, "N/A" );
	strcpy(DelReg.sBoosterDoseVacc, "N/A" );
	strcpy(DelReg.sFirstDoseDate, "" );
	strcpy(DelReg.sFirstDoseLoc, "" );
	strcpy(DelReg.sFirstDoseVacc, "" );
	strcpy(DelReg.sName, "" );
	strcpy(DelReg.sPassword, "" );
	strcpy(DelReg.sSecondDoseDate, "N/A" );
	strcpy(DelReg.sSecondDoseLoc, "N/A" );
	strcpy(DelReg.sSecondDoseVacc, "N/A" );
	strcpy(DelReg.sSex, "" );

	DelApp.nAppID = 0;
	strcpy(DelApp.sDate, "" );
	strcpy(DelApp.sDose, "" );
	strcpy(DelApp.sLocation, "" );
	strcpy(DelApp.sName, "" );
	strcpy(DelApp.sTime, "" );
	strcpy(DelApp.sVaccine, "" );

	strcpy(DelQNA.sQuestion,"");
	strcpy(DelQNA.sAnswer, "");

}

/*
InitializeChatBotQandA initializes the Chatbot struct array with pre-set questions and answers.
@return none since it is a void function
Pre-condition: Chatbot struct array and its elements are properly initialized.
*/
void InitializeChatBotQandA()
{
	strcpy(Chatbot[0].sQuestion, "Is vaccination mandatory?");
	strcpy(Chatbot[0].sAnswer, "No, but it is highly recommended by the government.");

	strcpy(Chatbot[1].sQuestion, "What are the possible side effects of vaccination?");
	strcpy(Chatbot[1].sAnswer, "The possible side effects include pain, fever, fatigue and headache.");

	strcpy(Chatbot[2].sQuestion, "How many COVID cases are there as of April 2023 in the Philippines?");
	strcpy(Chatbot[2].sAnswer, "There have been 305 cases so far according to WHO.");

	strcpy(Chatbot[3].sQuestion, "When was the highest number of COVID cases in the Philippines?");
	strcpy(Chatbot[3].sAnswer, "The highest number of COVID cases was in January 10, 2022 with 231,502 cases.");

	strcpy(Chatbot[4].sQuestion, "Where can I get vaccinated in the Philippines?");
	strcpy(Chatbot[4].sAnswer, "You may refer to this link: https://doh.gov.ph/covid-19-vaccination-sites");

	strcpy(Chatbot[5].sQuestion, "What vaccines are available in the Philippines?");
	strcpy(Chatbot[5].sAnswer, "The available ones are Moderna, Pfizer, AstraZeneca, J&J, Sinovac, and Sputnik.");

	strcpy(Chatbot[6].sQuestion, "Am I still considered fully vaccinated if I dont get a booster?");
	strcpy(Chatbot[6].sAnswer, "Yes, you are fully vaccinated even if you have not gotten your booster yet");

	strcpy(Chatbot[7].sQuestion, "What are the possible effects of a booster?");
	strcpy(Chatbot[7].sAnswer, "Possible side effects are pain, fatigue, fever, headaches, or muscle pains.");

	strcpy(Chatbot[8].sQuestion, "How many vaccines have been administered in the Philippines?");
	strcpy(Chatbot[8].sAnswer, "According to WHO, as of March 8 2023, 170,690,206 vaccines were administered.");

}

/*
ExportUser prompts the user to input a name for the .txt file to export the user data to.
The function then writes the user data to the specified .txt file using a for loop to iterate through the UserReg array.
@param int *UserCount - pointer to the current number of users in the system
@return none since it is a void function
Pre-condition: User has chosen to export user data, UserReg array and its elements are properly initialized.
*/
void ExportUser(int *UserCount)
{
	char temp[31];
	int ValidInput = 0;

	//USERS.TXT EXPORT STARTS HERE*************	
		while (ValidInput == 0)
		{
			printf("\nSpecify name of .txt file for the Users.txt: ");
				scanf(" %[^\n]s", temp);

				if (strlen(temp) <= 25)
				{
					strcat(temp, ".txt");
					ValidInput = 1;
				}
				else
				printf("\nERROR! INVALID FILE NAME INPUTTED!\n");
		}
		ValidInput = 0;
		//Algo to store info from struct to text file named Users.txt
		FILE *fp;
		fp = fopen(temp, "w+");

			for (int i = 0; i < *UserCount; i++)
			{
				fprintf(fp, "%ld %s\n", UserReg[i].nUserID, UserReg[i].sPassword);
				fprintf(fp, "%s\n", UserReg[i].sName);
				fprintf(fp, "%s\n", UserReg[i].sAddress);
				fprintf(fp, "%lld\n", UserReg[i].nContact);
				fprintf(fp, "%s\n", UserReg[i].sSex);
				fprintf(fp, "%s %s %s\n", UserReg[i].sFirstDoseLoc, UserReg[i].sFirstDoseDate, UserReg[i].sFirstDoseVacc);
				fprintf(fp, "%s %s %s\n", UserReg[i].sSecondDoseLoc, UserReg[i].sSecondDoseDate, UserReg[i].sSecondDoseVacc);
				fprintf(fp, "%s %s %s\n", UserReg[i].sBoosterDoseLoc, UserReg[i].sBoosterDoseDate, UserReg[i].sBoosterDoseVacc);
				fprintf(fp, "\n");
			}
			printf("\nDATA SUCCESSFULLY EXPORTED.");
		fclose(fp);
//USERS.txt EXPORT ENDS HERE*************	
}

/*
ExportApp prompts the user to input the desired name for the text file that will store the appointment details.
The function then uses a loop to write the appointment information from the Appointment array to the text file.
@param int *AppCount - pointer to the current number of appointments in the system
@return none since it is a void function
Pre-condition: Appointments array and its elements are properly initialized.
*/
void ExportApp(int *AppCount)
{
	char temp[31];
	int ValidInput = 0;

	//EXPORT APPOINTMENT.txt STARTS HERE********
		while (ValidInput == 0)
		{
			printf("\nSpecify name of .txt file for the Appointment.txt: ");
				scanf(" %[^\n]s", temp);

				if (strlen(temp) <= 25)
				{
					strcat(temp, ".txt");
					ValidInput = 1;
				}
				else
				printf("\nERROR! INVALID FILE NAME INPUTTED!\n");
		}
		ValidInput = 0;
		//Algo to store info from struct to text file Appointment.txt	
			FILE *app;
			app = fopen(temp, "w+");
		
				for (int i = 0; i < *AppCount; i++)
				{
					fprintf(app, "%ld %ld\n", Appointment[i].nAppID, Appointment[i].nUserID);
					fprintf(app, "%s\n", Appointment[i].sName);
					fprintf(app, "%s\n", Appointment[i].sLocation);
					fprintf(app, "%s\n", Appointment[i].sVaccine);
					fprintf(app, "%s \n", Appointment[i].sDate);
					fprintf(app, "%s\n", Appointment[i].sTime);
					fprintf(app, "%s\n", Appointment[i].sDose);
					fprintf(app, "\n");
				}
					printf("\nDATA SUCCESSFULLY EXPORTED.");
			fclose(app);
		//EXPORT APPOINTMENT.txt ENDS HERE********
}

/*
ExportChat is a function that prompts the user to input a filename and exports the contents of the Chatbot array to a text file in the specified file name.
The function loops until a valid filename of 25 characters or less is inputted.
@param int *QandACount - pointer to the current number of questions and answers stored in the Chatbot array
@return none since it is a void function
Pre-condition: Chatbot array and its elements are properly initialized.
*/
void ExportChat(int *QandACount)
{
	char temp[31];
	int ValidInput = 0;

	// EXPORT CHATBOT.txt ENDS HERE********
		while (ValidInput == 0)
		{
			printf("\nSpecify name of .txt file for the Chatbot.txt: ");
				scanf(" %[^\n]s", temp);

				if (strlen(temp) <= 25)
				{
					strcat(temp, ".txt");
					ValidInput = 1;
				}
				else
				printf("\nERROR! INVALID FILE NAME INPUTTED!\n");
		}
		ValidInput = 0;

		FILE *chatbot;
		chatbot = fopen(temp, "w+");

			for (int i = 0; i < *QandACount; i++)
			{
				fprintf(chatbot, "%s\n", Chatbot[i].sQuestion);
				fprintf(chatbot, "%s\n", Chatbot[i].sAnswer);
			}
			printf("\nData sucessfully exported.");

		fclose(chatbot);
}

/*
ImportUser is a function that prompts the user to input a filename and imports the contents of the specified text file to the UserReg array.
The function loops until a valid filename of 25 characters or less is inputted and the file exists.
Each line of the text file corresponds to a user's information stored in the UserReg array.
The function displays each imported user's information and prompts the user to confirm whether or not to record the entry.
@param int *UserCount - pointer to the current number of users stored in the UserReg array
@return none since it is a void function
Pre-condition: UserReg array and its elements are properly initialized.
*/
void ImportUser(int *UserCount)
{
	char temp2[31];
	int ValidInput = 0;
	FILE *UsersImp;
	char Pick2;

	//START OF IMPORT USERS.TXT HERE**********************
	while (ValidInput == 0)
		{
			printf("\nSpecify name of .txt file for the Users.txt to import from: ");
				scanf(" %[^\n]", temp2);

				if (strlen(temp2) <= 25)
				{
					strcat(temp2, ".txt");
					ValidInput = 1;

					UsersImp = fopen(temp2, "r");
					if (UsersImp == NULL)
					{
						printf("\nERROR FILE DOES NOT EXIST.");
						fclose(UsersImp);
					}
					else
					ValidInput = 1;
				}
				else
				printf("\nERROR! INVALID FILE NAME INPUTTED!\n");
		}
		ValidInput = 0;

		while (fscanf(UsersImp, "%ld %[^\n]%*c", &TempUserReg.nUserID, TempUserReg.sPassword) == 2) 
		 {
			fscanf(UsersImp, "%[^\n]\n", TempUserReg.sName);
			fscanf(UsersImp, "%[^\n]\n", TempUserReg.sAddress);
			fscanf(UsersImp, "%lld\n", &TempUserReg.nContact);
			fscanf(UsersImp, "%s\n", TempUserReg.sSex);
			fscanf(UsersImp, "%s %s %s\n", TempUserReg.sFirstDoseLoc,TempUserReg.sFirstDoseDate,  TempUserReg.sFirstDoseVacc);
			fscanf(UsersImp, "%s %s %s\n", TempUserReg.sSecondDoseLoc,TempUserReg.sSecondDoseDate,  TempUserReg.sSecondDoseVacc);
			fscanf(UsersImp, "%s %s %s\n", TempUserReg.sBoosterDoseLoc,TempUserReg.sBoosterDoseDate,  TempUserReg.sBoosterDoseVacc);
			fscanf(UsersImp, "\n"); // Reads empty line 
		
			printf("\nUserID: %lld Password: %s", TempUserReg.nUserID, TempUserReg.sPassword);
			printf("\nName: %s", TempUserReg.sName);
			printf("\nAddress: %s", TempUserReg.sAddress);
			printf("\nContact No: %lld", TempUserReg.nContact);
			printf("\nSex: %s", TempUserReg.sSex);
			printf("\nVaccine 1: %s %s %s", TempUserReg.sFirstDoseLoc,TempUserReg.sFirstDoseDate,  TempUserReg.sFirstDoseVacc);
			printf("\nVaccine 2: %s %s %s", TempUserReg.sSecondDoseLoc,TempUserReg.sSecondDoseDate,  TempUserReg.sSecondDoseVacc);
			printf("\nVaccine 3: %s %s %s", TempUserReg.sBoosterDoseLoc,TempUserReg.sBoosterDoseDate,  TempUserReg.sBoosterDoseVacc);

			while (ValidInput == 0)
			{
				printf("\n\nWould you like to record this entry? (Y/N): ");
					scanf(" %c", &Pick2);

				if (Pick2 == 'Y')
				{
					UserReg[*UserCount] = TempUserReg;
   					*UserCount+=1;
					ValidInput = 1;
				}
				else if (Pick2 == 'N')
				{
					printf("Entry not recorded.");
					ValidInput = 1;
				}
				else
				printf("\nInvalid Input. Please try again.");
			}
			ValidInput = 0;
		 }
		fclose (UsersImp);
		PrintAllUsers(UserCount);
		printf("\nData sucessfully imported.");
		printf("\nNOTE: IF NO CHANGES OCCURRED, THE CONTENT IS EITHER MISSING OR THE FILENAME INPUTTED WAS NOT VALID.");
}

/*
ImportApp is a function that prompts the user to input a filename and imports the contents of the specified text file to the Appointment array.
The function loops until a valid filename of 25 characters or less is inputted and the file exists. (25 + .txt extension)
Each block of lines in the text file corresponds to an appointment's information stored in the Appointment array.
The function displays each imported appointment's information and prompts the user to confirm whether or not to record the entry.
@param int *AppCount - pointer to the current number of appointments stored in the Appointment array
@return none since it is a void function
Pre-condition: Appointment array and its elements are properly initialized.
*/
void ImportApp (int *AppCount)
{
	char temp2[31];
	int ValidInput = 0;
	FILE *AppImp;
	char Pick2;

	//START OF IMPORT APPOINTMENT.TXT*************************
		while (ValidInput == 0)
		{
			printf("\nSpecify name of .txt file for the Appointment.txt to import from: ");
				scanf(" %[^\n]", temp2);

				if (strlen(temp2) <= 25)
				{
					strcat(temp2, ".txt");

					AppImp = fopen(temp2, "r");
					if (AppImp == NULL)
					{
						printf("\nERROR FILE DOES NOT EXIST.");
						fclose (AppImp);
					}
					else
					ValidInput = 1;
				}
				else
				printf("\nERROR! INVALID FILE NAME INPUTTED!\n");
		}
		 ValidInput = 0;
		 //Actual appcount will be based on existing number of users in the current program
		 while (fscanf(AppImp, "%ld %ld\n", &TempApp.nAppID, &TempApp.nUserID) == 2) 
		 {
			fscanf(AppImp, "%[^\n]\n", TempApp.sName);
			fscanf(AppImp, "%[^\n]\n", TempApp.sLocation);
			fscanf(AppImp, "%s\n", TempApp.sVaccine);
			fscanf(AppImp, "%s\n", TempApp.sDate);
			fscanf(AppImp, "%s\n", TempApp.sTime);
			fscanf(AppImp, "%s\n", TempApp.sDose);
			fscanf(AppImp, "\n"); // read the empty line after each appointment
		
			printf("\nApp ID: %ld UserID: %ld", TempApp.nAppID, TempApp.nUserID);
			printf("\nName: %s", TempApp.sName);
			printf("\nLocation: %s", TempApp.sLocation);
			printf("\nVaccine: %s", TempApp.sVaccine);
			printf("\nDate: %s", TempApp.sVaccine);
			printf("\nTime: %s", TempApp.sTime);
			printf("\nDose: %s", TempApp.sDose);

			while (ValidInput == 0)
			{
				printf("\n\nWould you like to record this entry? (Y/N): ");
					scanf(" %c", &Pick2);

				if (Pick2 == 'Y')
				{
					Appointment[*AppCount] = TempApp;
   					*AppCount+=1;
					ValidInput = 1;
				}
				else if (Pick2 == 'N')
				{
					printf("Entry not recorded.\n");
					ValidInput = 1;
				}
				else
				printf("\nInvalid Input. Please try again.");
			}
			ValidInput = 0;
		 }
		 fclose (AppImp);
		 PrintAllAppointments(AppCount);
		 printf("\nData sucessfully imported.");
		 printf("\nNOTE: IF NO CHANGES OCCURRED, THE CONTENT IS EITHER MISSING OR THE FILENAME INPUTTED WAS NOT VALID.");
}

/*
ImportChat is a function that prompts the user to input a filename and imports the contents of the specified text file to the Chatbot array.
The function loops until a valid filename of 25 characters or less is inputted and the file exists. (25 + .txt extension)
Each block of lines in the text file corresponds to a chatbot's Q&A information stored in the Chatbot array.
The function displays each imported Q&A and prompts the user to confirm whether or not to record the entry.
@param int *QandACount - pointer to the current number of Q&A stored in the Chatbot array
@return none since it is a void function
Pre-condition: Chatbot array and its elements are properly initialized.
*/
void ImportChat (int *QandACount)
{
	char temp2[31];
	int ValidInput = 0;
	FILE *ChatbotImp;
	char Pick2;

	//START OF IMPORT CHATBOT.TXT HERE**********************
	while (ValidInput == 0)
		{
			printf("\nSpecify name of .txt file for the Chatbot.txt to import from: ");
				scanf(" %[^\n]", temp2);

				if (strlen(temp2) <= 25)
				{
					strcat(temp2, ".txt");
					ValidInput = 1;

					ChatbotImp = fopen(temp2, "r");
					if (ChatbotImp == NULL)
					{
						printf("\nERROR FILE DOES NOT EXIST.");
						fclose(ChatbotImp);
					}
					else
					ValidInput = 1;
				}
				else
				printf("\nERROR! INVALID FILE NAME INPUTTED!\n");
		}
		ValidInput = 0;

		 while (fscanf(ChatbotImp, "%[^\n]\n", TempChatbot.sQuestion) == 1) 
		 {
			fscanf(ChatbotImp, "%[^\n]\n", TempChatbot.sAnswer);

			printf("\nQUESTION: %s", TempChatbot.sQuestion);
			printf("\nANSWER: %s", TempChatbot.sAnswer);

			while (ValidInput == 0)
			{
				printf("\n\nWould you like to record this entry? (Y/N): ");
					scanf(" %c", &Pick2);

				if (Pick2 == 'Y')
				{
					Chatbot[*QandACount] = TempChatbot;
   					*QandACount+=1;
					ValidInput = 1;
				}
				else if (Pick2 == 'N')
				{
					printf("Entry not recorded.");
					ValidInput = 1;
				}
				else
				printf("\nInvalid Input. Please try again.");
			}
			ValidInput = 0;
		 }
		fclose (ChatbotImp); 
		PrintQandA(QandACount);
		printf("\nData sucessfully imported.");
		printf("\nNOTE: IF NO CHANGES OCCURRED, THE CONTENT IS EITHER MISSING OR THE FILENAME INPUTTED WAS NOT VALID.");
}

/*
VaccineChecker is a function that takes in a string parameter representing the name of a vaccine, and returns an integer value corresponding to that vaccine's unique identifier.
The function uses a series of if/else statements to determine which vaccine name was inputted and assigns a value based on that name.
If the vaccine name is not recognized, the function returns -1.
@param char *Vaccine - a string representing the name of a vaccine
@return an integer value corresponding to that vaccine's unique identifier, or -1 if the vaccine name is not recognized.
Pre-condition: Vaccine name is a valid string.
*/
int VaccineChecker(char *Vaccine)
{//J&J vaccine is only one dose, no booster / second.
	int value = -1;

	if (strcmp(Vaccine, "Moderna") == 0)
	value = 1;
	else if (strcmp(Vaccine, "Pfizer") == 0)
	value = 2;
	else if (strcmp(Vaccine, "AstraZeneca") == 0)
	value = 3;
	else if (strcmp(Vaccine, "Sinovac") == 0)
	value = 4;
	else if (strcmp(Vaccine, "J&J") == 0)
	value = 5;
	else if (strcmp(Vaccine, "Sputnik") == 0)
	value = 6;

	return value;
}

/*
SaveAll is a function that saves all current data in the program by exporting it in the default text file names
when exiting the program.
@param int *UserCount - integer pointing to the total number of current registered users in the program.
@param int *AppCount - integer pointing to the total number of current registered vaccination appointments in the program.
@param int *QandACount -  integer pointing to the total number of current questions & answers in the program.
@no return value since it is void
Pre-condition: User exited the program / Program was terminated
*/
void SaveAll(int *UserCount, int *AppCount, int *QandACount)
{

		FILE *fp, *app, *qanda;
		fp = fopen("Users.txt", "w");
		app = fopen("Appointment.txt", "w");
		qanda = fopen("Chatbot.txt", "w");

			for (int i = 0; i < *UserCount; i++)
			{
				fprintf(fp, "%ld %s\n", UserReg[i].nUserID, UserReg[i].sPassword);
				fprintf(fp, "%s\n", UserReg[i].sName);
				fprintf(fp, "%s\n", UserReg[i].sAddress);
				fprintf(fp, "%lld\n", UserReg[i].nContact);
				fprintf(fp, "%s\n", UserReg[i].sSex);
				fprintf(fp, "%s %s %s\n", UserReg[i].sFirstDoseLoc, UserReg[i].sFirstDoseDate, UserReg[i].sFirstDoseVacc);
				fprintf(fp, "%s %s %s\n", UserReg[i].sSecondDoseLoc, UserReg[i].sSecondDoseDate, UserReg[i].sSecondDoseVacc);
				fprintf(fp, "%s %s %s\n", UserReg[i].sBoosterDoseLoc, UserReg[i].sBoosterDoseDate, UserReg[i].sBoosterDoseVacc);
				fprintf(fp, "\n");
			}

			for (int i = 0; i < *QandACount; i++)
			{
				fprintf(qanda, "%s\n", Chatbot[i].sQuestion);
				fprintf(qanda, "%s\n", Chatbot[i].sAnswer);
			}

			for (int i = 0; i < *AppCount; i++)
			{
				fprintf(app, "%ld %ld\n", Appointment[i].nAppID, Appointment[i].nUserID);
				fprintf(app, "%s\n", Appointment[i].sName);
				fprintf(app, "%s\n", Appointment[i].sLocation);
				fprintf(app, "%s\n", Appointment[i].sVaccine);
				fprintf(app, "%s \n", Appointment[i].sDate);
				fprintf(app, "%s\n", Appointment[i].sTime);
				fprintf(app, "%s\n", Appointment[i].sDose);
				fprintf(app, "\n");
			}

		fclose(fp);
		fclose(app);
		fclose(qanda);
}