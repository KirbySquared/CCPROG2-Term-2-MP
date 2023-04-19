#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "MORALESmpMenuFunctions.c"
int VaccRegMenu();
int VaccAppoint();
int DataMenu();
void AdminUserSubMenu();
void AdminAppointSubMenu();
void AdminChatbotSubMenu();
void UserRegistrationInput();
void PrintAllUsers();
void PrintAllAppointments();
void CallChatBot();
void InitializeChatBotQandA();
void PrintQandA();
void ExportMenu();
void ImportMenu();

/* FirstMenu shows the very first main menu used to access the Data Menu, and the Vacc Registration Menu.
Contains a loop and will only end when user chooses to do so.
@No return since it is void
Pre-condition: None since it is a display function
*/
void 
FirstMenu()
{

    int nChoice = 0;
    int registeredusers = 0;
    int appointmentcount = 0;
    int qandacount = 9;
    int terminate = 0;

       for (int c = registeredusers; c < 100; c++)
        {
            UserReg[c] = DelReg;
        }

    while (nChoice != 3)
    {
        nChoice = 0;
        printf("\n--------------MAIN MENU------------------");
        printf("\n(1.) Vaccination Registration Menu");
        printf("\n(2.) Data Management Menu (Admins only)");
        printf("\n(3.) Exit the program.");
        printf("\n-----------------------------------------");
        printf("\nEnter your choice: ");
        //printf("\nITO YUNG BINIGAY NA VALUE: %d\n", registeredusers);
            scanf("%d", &nChoice);

        switch (nChoice)
        {
            case 1: terminate = VaccRegMenu(&registeredusers, &appointmentcount); break;
            case 2: terminate = DataMenu(&registeredusers, &appointmentcount, &qandacount); break;
            case 3: SaveAll(&registeredusers, &appointmentcount, &qandacount);
            printf("\nExiting Program ..."); break;
            default: printf("\nInvalid option. Please pick again."); break;
        }

        if (terminate == 1)
        nChoice = 3;
    }

}

/* VaccRegMenu: Displays a menu of options to the user and prompts them to enter a choice. The user will either call
the UserRegistrationInput, VaccAppoint or CallChatBot function depending on their input. 
Contains a loop and will only end when user chooses to do so.
@param int *NumOfUsers points to the number of users at the start of the program (0)
@param int *AppCount points to the number of Vaccine Applications at the start of the program (0)
@Returns 1 or 0 , 1 to terminate the program, 0 to not terminate. Value changes if user inputted wrong ID / pass
Pre-condition: User chose to access Vaccination Registration Menu
*/
int 
VaccRegMenu
(int *NumOfUsers,
 int *AppCount)
{
    int terminate = 0;
    int RegChoice = 0;
    //userID should be unique
    //Prompt user after succesful registration
    //User will be redirected to Vacc Registration Menu
    while (RegChoice != 4)
    {
        printf("\n----------------VACCINATION REGISTRATION MENU----------------");
        printf("\n(1.) User Registration Menu");
        printf("\n(2.) Vaccination Appointment");
        printf("\n(3.) Chatbot (FAQS)");
        printf("\n(4.) Exit Menu");
        printf("\n-------------------------------------------------------------");
        printf("\nEnter your choice: ");
      //  printf("\nITO YUNG BINIGAY NA VALUE: %d\n", *NumOfUsers);
            scanf("%d", &RegChoice);

        switch (RegChoice)
        {
            case 1: UserRegistrationInput(NumOfUsers); break;
            case 2: terminate = VaccAppoint(NumOfUsers, AppCount); break;
            case 3: CallChatBot();break;
            case 4: printf("\nExiting Menu ..."); break;
            default: printf("\nInvalid option. Please pick again."); break;
        }

        if (terminate == 1)
        {
            RegChoice = 4;
            printf("\n3 UNSUCCESSFUL ATTEMPTS HAVE BEEN DETECTED! TERMINATING PROGRAM...");
        }
    }

    return terminate;
}

/* VaccAppoint: Menu for the vaccination appointment process. Prompts the user to enter their userID and password,
 and checks if they are valid. If they are, it displays another menu of options and calls either the AppReq function 
 or the ManageAppointment function. Contains a loop and will only end when user chooses to do so.
 @Returns 1 or 0 , 1 to terminate the program, 0 to not terminate.
Pre-condition: User chose to access Vaccination Appointment Menu*/
int
VaccAppoint
(int *NumOfUsers,
 int *AppCount)
{
    //3 unsuccessful attempts = terminates program
    int AppChoice = 0;
    int terminatecount = 3;
    int check = 0;
    int terminate;
    int IDFuncVal;
    char temppass[11];
    int i = 0;

    while (terminatecount != 0)
    {
        if (terminatecount > 0)
        {
            printf("\nPlease input your userID: ");
            scanf("%d", &check);
        }

            IDFuncVal = IDIndex(NumOfUsers, check);

        if ( IDFuncVal >= 0)
        {
        int z = 0;
        printf("\nPlease input your password: ");
        while (  (temppass[z] = getch() )  != 13 ) //13 = ASCII value of enter
		{
			if (temppass[z] == 8 && z > 0)
       	 	{
            printf("\b \b");
            z--;
        	}
        else if (temppass[z] != 8)
       		 {
            printf("*");
            z++;
       		 }
		}
		temppass[z] ='\0';

            if(PassChecker(NumOfUsers,temppass,IDFuncVal) == 1)
            {
                i = IDIndex(NumOfUsers, check);
                printf("\nYou have logged in successfully!");
                terminatecount = 0;
                terminate = 0;
                AppChoice = 0;
            }
            else
            {
                terminatecount--;
                 if (terminatecount > 0)
                 printf("\nIncorrect password has been inputted. You have %d more tries.", terminatecount);
                 else
                 {
                    terminate = 1;
                    AppChoice = 3;
                 }
                 
            }
        }
        else 
        {
            terminatecount--;
            if (terminatecount > 0 && IDFuncVal == -1)
                printf("\nIncorrect userID has been inputted.");
            if (terminatecount > 0 && IDFuncVal == -2)
                printf("\nUser ID already exists.");
            else
            {
                terminate = 1;
                AppChoice = 3;
            }
            printf("You have %d more tries.", terminatecount);
        }
       
    }

    while (AppChoice != 3)
    {   
        Appointment[*AppCount].nUserID = UserReg[i].nUserID;
        AppChoice = 0;
        printf("\n------------VACCINATION APPOINTMENT MENU------------");
        printf("\n(1.) Appointment Request");
        printf("\n(2.) Manage Appointment Menu");
        printf("\n(3.) Exit Menu");
        printf("\n----------------------------------------------------");
        printf("\nEnter your choice: ");
            scanf("%d", &AppChoice);

        switch (AppChoice)
        {
            case 1: AppReq(NumOfUsers, AppCount); break;
            case 2: ManageAppointment(NumOfUsers, AppCount); break;
            case 3: printf("\nExiting Menu ..."); break;
            default: printf("\nInvalid option. Please pick again."); break;
        }
    }

    return terminate;
}

/*DataMenu: Handles data management. It prompts the user to enter their userID and password, 
and checks if they are valid. If they are, it displays another menu of options and calls either User Submenus,
Appoint subments, Import / Export menus, and the Chatbot menu. Function will end when user chooses to do so.
@param int *NumOfUsers points to the number of users at the start of the program (0)
@param int *AppCount points to the number of Vaccine Applications at the start of the program (0)
@Returns 1 or 0 , 1 to terminate the program, 0 to not terminate. Value changes if user inputted wrong ID / pass.
Pre-condition: User chose to access Data Menu*/
int
DataMenu
(int *index,
 int *AppCount,
 int *QandAcount)
{
    int terminatecount = 3;
    int check = 0;
    int terminate;
    int IDFuncVal;
    int DataChoice;
	int z = 0;
    char temp[11];
    //User must login with their userID and password. 3 unsucessful attempts = Program will terminate
    //For my code, the 1st user will always be the admin, if no user = no admin. 

    while (terminatecount != 0)
    {
        if (terminatecount > 0)
        {
            printf("\nPlease input your userID: ");
            scanf("%d", &check);
        }
            if (check == UserReg[0].nUserID)
            IDFuncVal = 0;
            else
            IDFuncVal = -1;

        if ( IDFuncVal >= 0 && check == UserReg[0].nUserID)
        {
            printf("Please input your password: ");
		//Loop to mask password being inputted
		while (  (temp[z] = getch() )  != 13 ) //13 = ASCII value of enter
		{
			if (temp[z] == 8 && z > 0)
			{
				printf("\b \b");
				z--;
			}
			else if (temp[z] != 8)
			{
				printf("*");
				z++;
			}
		}
		temp[z] ='\0';

            if(PassChecker(index,temp,IDFuncVal) == 1)
            {
                printf("\nYou have logged in successfully!");
                terminatecount = 0;
                terminate = 0;
                DataChoice = 0;
            }
            else
            {
                terminatecount--;
                 if (terminatecount > 0)
                 printf("\nIncorrect password has been inputted. You have %d more tries.", terminatecount);
                 else
                 {
                    terminate = 1;
                    DataChoice = 6;
                 }
                 
            }
        }
        else 
        {
            terminatecount--;
            if (terminatecount > 0 && IDFuncVal == -1)
            printf("\nIncorrect userID has been inputted.");
            //if (terminatecount > 0 && IDFuncVal == -2)
           // printf("\nUser ID already exists.");
            else
            {
                terminate = 1;
                DataChoice = 6;
            }
            printf("You have %d more tries.", terminatecount);
        }
    }

    while (DataChoice != 6)
    {   
        printf("\n------------ADMIN DATA MENU------------");
        printf("\n1. User");
        printf("\n2. Manage Appointment Menu");
        printf("\n3. Chatbot");
        printf("\n4. Export");
        printf("\n5. Import");
        printf("\n6. Exit Menu");
        printf("\n---------------------------------------");
        printf("\nEnter your choice: ");
       // printf("\nITO YUNG BINIGAY NA VALUE: %d\n", *index);
            scanf("%d", &DataChoice);

        switch (DataChoice)
        {
            case 1: AdminUserSubMenu(index); break;
            case 2: AdminAppointSubMenu(index, AppCount); break;
            case 3: AdminChatbotSubMenu(QandAcount); break;
            case 4: ExportMenu(index, AppCount, QandAcount); break;
            case 5: ImportMenu(index, AppCount, QandAcount); break;
            case 6: printf("\nExiting Menu ..."); break;
            default: printf("\nInvalid option. Please pick again."); break;
        }
    }

    return terminate;
}

/*AdminUserSubMenu: Displays the data management admin user submenu. Allows the admin / user to Add, Edit, View, or
Delete existing users in the database. Function will end if the user chooses to do so
@param int *index points to the number of users / current index to be accessed (*index -1)
No return value since void
Pre-condition: User chose to access Data Menu*/
void 
AdminUserSubMenu
(int *index)
{
    int nMenuChoice = 0;
    char cChoice;
    while (nMenuChoice != 5)
    {
        printf("\n------------1. USER SUBMENU------------");
        printf("\n(1) Add New User");
        printf("\n(2) View all Users");
        printf("\n(3) Edit User Details");
        printf("\n(4) Delete User");
        printf("\n(5) Exit");
        printf("\n---------------------------------------");
        printf("\nEnter your choice: ");
      //  printf("\nITO YUNG BINIGAY NA VALUE: %d\n", *index);
            scanf("%d", &nMenuChoice);

        switch (nMenuChoice)
        {
            case 1: cChoice = 'z';
            while (cChoice != 'N' && cChoice != 'n')
            {
                UserRegistrationInput(index); 
                cChoice = 'z';

                while (cChoice != 'N' && cChoice != 'n' && cChoice != 'y' && cChoice != 'Y')
                {
                    printf("\nWould you like to add another user? ");
                        scanf(" %c", &cChoice);
                
                    switch (cChoice)
                    {
                        case 'N':
                        case 'n': printf("\nExiting Menu ..."); break;
                        case 'Y':
                        case 'y': printf("Adding another user . . ."); break;
                        default: printf("\nInvalid option. Please pick again."); break;
                    }
                }
            }
            break;
            case 2: PrintAllUsers(index); break;
            case 3: EditUserDetails(index); break;
            case 4: DeleteUserRecord(index); break;
            case 5: printf("\nExiting Menu ..."); break;
            default: printf("\nInvalid option. Please pick again."); break;
        }
    }
}

/* AdminAppointSubMenu displays and allows the appointment submenu and prompts the user for input
@param UserCount - pointer to the current count of users in the user database
@param AppCount - pointer to the current count of appointments in the appointment database 
No return since void function
Pre-condition: User chose to access Vaccination Appointment Data Menu*/
void 
AdminAppointSubMenu
(int *UserCount,
 int *AppCount)
{
    int nAppointChoice = 0;

    while (nAppointChoice != 5)
    {
        nAppointChoice = 0;
        printf("\n------------2. APPOINTMENT SUBMENU------------");
        printf("\n(1) Add New Appointment");
        printf("\n(2) View all Appointments");
        printf("\n(3) Edit Appointment");
        printf("\n(4) Delete Appointment");
        printf("\n(5) Exit");
        printf("\n----------------------------------------------");
        printf("\nEnter your choice: ");
            scanf("%d", &nAppointChoice);

        switch (nAppointChoice)
        {
            case 1: AppReq (UserCount, AppCount); break;
            case 2: PrintAllAppointments(AppCount); break;
            case 3: EditAppDetails(UserCount, AppCount); break;
            case 4: DeleteAppRecord (AppCount); break;
            case 5: printf("\nExiting Menu ..."); break;
            default: printf("\nInvalid option. Please pick again."); break;
        }    
    }
}

/* AdminChatbotSubMenu allows user / admin to manage the chatbot's Q&A section by adding, editing, or deleting Q&A 
in the bot's database. Function will end when user / admin chooses to do so.
@param int *count - pointer to an integer containing the current number of Q&As in the system
No return since void function
Pre-Condition: User chose to access chatbot submenu
*/
void 
AdminChatbotSubMenu
(int *count)
{
    int nChatChoice = 0;
    for (int c = *count; c < 100; c++)
    {
        Chatbot[c] = DelQNA;
    }

    while (nChatChoice != 5)
    {
        nChatChoice = 0;
        printf("\n------------3. CHATBOT SUBMENU------------");
        printf("\n(1) Add New Question and Answer");
        printf("\n(2) View all Questions and Answers");
        printf("\n(3) Edit Questions and Answers");
        printf("\n(4) Delete Questions and Answers");
        printf("\n(5) Exit");
        printf("\n------------------------------------------");
        printf("\nEnter your choice: ");
            scanf("%d", &nChatChoice);
    
        switch (nChatChoice)
        {
            case 1: AddQandA(count); break;
            case 2: PrintQandA(count); break;
            case 3: EditQandA(count); break;
            case 4: DeleteQandA(count); break;
            case 5: printf("\nExiting Menu ..."); break;
            default: printf("\nInvalid option. Please pick again."); break;
        }
    }
    
}

/* ExportMenu allows an admin / user to export data from the system, afterwards they pick which file to export; they can choose from
exporting the users, no. of appointments, or the chatbot questions and answers.
@param int *UserCount - pointer to an integer containing the current number of users in the system
@param int *AppCount - pointer to an integer containing the current number of appointments in the system
@param int *QandACount - pointer to an integer containing the current number of Q&As in the system
No return since void function
Pre-Condition: User chose the export submenu
*/
void ExportMenu
(int *UserCount, 
int *AppCount, 
int *QandACount)
{
    int cChoice = 0;

    while (cChoice != 4)
    {
        cChoice = 0;
        printf("\n------------5. EXPORT SUBMENU------------");
        printf("\n(1) Export Users.txt");
        printf("\n(2) Export Appointment.txt");
        printf("\n(3) Export Chatbot.txt");
        printf("\n(4) Exit");
        printf("\n----------------------------------------------");
        printf("\nEnter your choice: ");
            scanf("%d", &cChoice);

        switch (cChoice)
        {
            case 1: ExportUser(UserCount); break; //function here
            case 2: ExportApp(AppCount); break; //function here
            case 3: ExportChat(QandACount); break; //function here
            case 4: printf("\nGoing back to previous menu ..."); break;
            default: printf("\nInvalid option. Please pick again."); break;
        }    
    }
}

/* ExportMenu allows an admin / user to import data to the system, afterwards they pick which file to import; they can choose from
importing the users, appointments, or the chatbot questions and answers.
@param int *UserCount - pointer to an integer containing the current number of users in the system
@param int *AppCount - pointer to an integer containing the current number of appointments in the system
@param int *QandACount - pointer to an integer containing the current number of Q&As in the system
No return since void function
Pre-Condition: User chose the export submenu
*/
void ImportMenu
(int *UserCount, 
int *AppCount, 
int *QandACount)
{
    int cChoice = 0;

    while (cChoice != 4)
    {
        cChoice = 0;
        printf("\n------------5. IMPORT SUBMENU------------");
        printf("\n(1) Import Users.txt");
        printf("\n(2) Import Appointment.txt");
        printf("\n(3) Import Chatbot.txt");
        printf("\n(4) Exit");
        printf("\n----------------------------------------------");
        printf("\nEnter your choice: ");
            scanf("%d", &cChoice);

        switch (cChoice)
        {
            case 1: ImportUser(UserCount); break; //function here
            case 2: ImportApp(AppCount); break; //function here
            case 3: ImportChat(QandACount); break; //function here
            case 4: printf("\nGoing back to previous menu ..."); break;
            default: printf("\nInvalid option. Please pick again."); break;
        }    
    }
}

/*PrintQandA: Prints all the current chatbot questions and their corresponding answer when matched.
@param int *count - pointer to an integer containing the current number of users in the system
No return since void function
Pre-Condition: User chose to view all chatbot Q&A in the Chatbot Data menu
*/
void PrintQandA(int *count)
{
    int i = 0;

    printf("\n--------------------VIEWING ALL QUESTIONS AND ANSWERS--------------------\n");

    for (i = 0; i < *count; i++)
    {
        printf("\nQ%d: %s", i+1, Chatbot[i].sQuestion);
        printf("\nA%d: %s\n", i+1, Chatbot[i].sAnswer);
    }

    printf("\n----------------------------END OF PRINTING------------------------------\n");
    printf("\nTotal number of Questions + Answers: %d", *count);
}

/* ANY WARNINGS ABOUT THE FORMAT SPECIFIER BEING WRONG / HAVING TOO MANY ARGUMENTS ARE FALSE POSITIVES. 
There is only 1 instance LONG LONG INT being printed per printf, therefore only 1 argument yet it says there is too many. */
/*PrintAllUsers: Prints all the data of the current users with their corresponding info such as their userID, name, password,
address, etc . . .
@param int *index - pointer to an integer containing the current number of users in the system
No return since void function
Pre-Condition: User chose to view all users in the User Data menu
*/
void 
PrintAllUsers
(int *index)
{
	int i;

	printf("\n-------------------VIEWING ALL USERS--------------------------------------VIEWING ALL USERS-------------------");
	for (i = 0; i < *index; i++)
	{
		printf("\n**********************USER #%d************************||", i+1);
		if (UserReg[i+1].nUserID != 0)
		printf("**********************USER #%d************************||", i+2);

		printf("\nUser ID:               %-30ld||", UserReg[i].nUserID);
		if (UserReg[i+1].nUserID != 0)
		printf("User ID:               %-30ld||", UserReg[i+1].nUserID);

		printf("\nPassword:              %-30s||", UserReg[i].sPassword);
		if (UserReg[i+1].nUserID != 0)
		printf("Password:              %-30s||", UserReg[i+1].sPassword);

		printf("\nName:                  %-30s||", UserReg[i].sName);
		if (UserReg[i+1].nUserID != 0)
		printf("Name:                  %-30s||", UserReg[i+1].sName);

		printf("\nAddress:               %-30s||", UserReg[i].sAddress);
		if (UserReg[i+1].nUserID != 0)
		printf("Address:               %-30s||", UserReg[i+1].sAddress);

		printf("\nContact No:            %-30lld||", UserReg[i].nContact);
		if (UserReg[i+1].nUserID != 0)
		printf("Contact No:            %-30lld||", UserReg[i+1].nContact);

		printf("\nSex:                   %-30s||", UserReg[i].sSex);
		if (UserReg[i+1].nUserID != 0)
		printf("Sex:                   %-30s||", UserReg[i+1].sSex);

		printf("\nFirst Dose Date:       %-30s||", UserReg[i].sFirstDoseDate);
		if (UserReg[i+1].nUserID != 0)
		printf("First Dose Date:       %-30s||", UserReg[i+1].sFirstDoseDate);

		printf("\nFirst Dose Vaccine:    %-30s||", UserReg[i].sFirstDoseVacc);
		if (UserReg[i+1].nUserID != 0)
		printf("First Dose Vaccine:    %-30s||", UserReg[i+1].sFirstDoseVacc);
		
		printf("\nFirst Dose Location:   %-30s||", UserReg[i].sFirstDoseLoc);
		if (UserReg[i+1].nUserID != 0)
		printf("First Dose Location:   %-30s||", UserReg[i+1].sFirstDoseLoc);
			
		printf("\nSecond Dose Date:      %-30s||", UserReg[i].sSecondDoseDate);
		if (UserReg[i+1].nUserID != 0)
		printf("Second Dose Date:      %-30s||", UserReg[i+1].sSecondDoseDate);

		printf("\nSecond Dose Vaccine:   %-30s||", UserReg[i].sSecondDoseVacc);
		if (UserReg[i+1].nUserID != 0)
		printf("Second Dose Vaccine:   %-30s||", UserReg[i+1].sSecondDoseVacc);

		printf("\nSecond Dose Location:  %-30s||", UserReg[i].sSecondDoseLoc);
		if (UserReg[i+1].nUserID != 0)
		printf("Second Dose Location:  %-30s||", UserReg[i+1].sSecondDoseLoc);

		printf("\nBooster Dose Date:     %-30s||", UserReg[i].sBoosterDoseDate);
		if (UserReg[i+1].nUserID != 0)
		printf("Booster Dose Date:     %-30s||", UserReg[i+1].sBoosterDoseDate);

		printf("\nBooster Dose Vaccine:  %-30s||", UserReg[i].sBoosterDoseVacc);
		if (UserReg[i+1].nUserID != 0)
		printf("Booster Dose Vaccine:  %-30s||", UserReg[i+1].sBoosterDoseVacc);

		printf("\nBooster Dose Location: %-30s||", UserReg[i].sBoosterDoseLoc);
		if (UserReg[i+1].nUserID != 0)
		printf("Booster Dose Location: %-30s||", UserReg[i+1].sBoosterDoseLoc);

		i++;

		printf("\n*****************************************************||*****************************************************||");
	}
    printf("\n--------------------------------------------------------------------------------------------------------------");
	
	printf("\nTotal Number of Users Registered: %d\n", *index);
	
}

/*PrintAllAppointments: Prints all the data of the current users with their corresponding info such as their userID, name, password,
address, etc . . .
@param int *AppCount - pointer to an integer containing the current number of appointments in the system
No return since void function
Pre-Condition: User chose to view all users in the User Data menu */
void PrintAllAppointments(int *AppCount)
{
    int i;
    for (int c = *AppCount; c < 100; c++)
        {
            Appointment[c] = DelApp;
        }

	printf("\n-------------------VIEWING ALL APPOINTMENTS------------------------VIEWING ALL APPOINTMENTS-------------------");
	for (i = 0; i < *AppCount; i++)
	{
		printf("\n**********************USER #%d************************||", i+1);
		if (Appointment[i+1].nAppID != 0)
		printf("**********************USER #%d************************||", i+2);

        printf("\nUser ID:               %-30ld||", Appointment[i].nUserID);
		if (Appointment[i+1].nAppID != 0)
		printf("User ID:               %-30ld||", Appointment[i+1].nAppID);

		printf("\nApp ID:                %-30ld||", Appointment[i].nAppID);
		if (Appointment[i+1].nAppID != 0)
		printf("App ID:                %-30ld||", Appointment[i+1].nAppID);

		printf("\nDate:                  %-30s||", Appointment[i].sDate);
		if (Appointment[i+1].nAppID != 0)
		printf("Date:                  %-30s||", Appointment[i+1].sDate);

		printf("\nType of Dose:          %-30s||", Appointment[i].sDose);
		if (Appointment[i+1].nAppID != 0)
		printf("Type of Dose:          %-30s||", Appointment[i+1].sDose);

		printf("\nVaccination Location:  %-30s||", Appointment[i].sLocation);
		if (Appointment[i+1].nAppID != 0)
		printf("Vaccination Location:  %-30s||", Appointment[i+1].sLocation);

		printf("\nName:                  %-30s||", Appointment[i].sName);
		if (Appointment[i+1].nAppID != 0)
		printf("Name:                  %-30s||", Appointment[i+1].sName);

		printf("\nTime of Vaccination:   %-30s||", Appointment[i].sTime);
		if (Appointment[i+1].nAppID != 0)
		printf("Time of Vaccination:   %-30s||", Appointment[i+1].sTime);

        printf("\nVaccine:               %-30s||", Appointment[i].sVaccine);
		if (Appointment[i+1].nAppID != 0)
		printf("Vaccine:               %-30s||", Appointment[i+1].sVaccine);

		i++;

		printf("\n*****************************************************||*****************************************************||");
	}
    printf("\n--------------------------------------------------------------------------------------------------------------");
	
	printf("\nTotal Number of Users Registered: %d\n", *AppCount);
}

/*CallChatBot: Displays the chatbot Q&A where the user can input questions and an answer will be given if the question
matches one in the database
@param int *AppCount - pointer to an integer containing the current number of appointments in the system
No return since void function
Pre-Condition: User chose the Chatbot menu under Vaccination Registration*/
void CallChatBot()
{
    char UserInput[81];
    int i = 0;

    printf("\nHi! This is VacciBot :D. How may I help you?");

    while (stricmp(UserInput, "Exit") != 0)
    {   
        printf("\n\n>>");
        scanf(" %[^\n]s", UserInput);
        i = ChatBotQandA(UserInput);

        if ( i >= 0)
        {
            printf("VacciBot>> %s", Chatbot[i].sAnswer);
        }
        else if (stricmp(UserInput, "Exit") == 0)
        {
            printf("\nThank you for using VacciBot! Returning to previous menu . . .\n");
        }
        else
        {
            printf("\nVacciBot>> I'm sorry, I did not understand the question.");
        }
    }
}