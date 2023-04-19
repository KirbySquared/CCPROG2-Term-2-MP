#include <stdio.h>
#include <string.h>
#include <conio.h>

typedef char String1[21];
typedef char String2[11];
typedef char QandA[81];
typedef char String3[31];
typedef char TimeString[7];
void UserRegistrationInput();
void SecondDoseInput();
void EditUserDetails();
void printusers();
int IDChecker();
void StructPrint();

struct UserRegistration
{
	int nUserID;
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
};
 //UserReg is alias to call and change data within struct UserRegistration

struct VaccinationAppointment
{
	int nUserID;
	int nAppID;
	String1 sName;
	String2 sLocation;
	String2 sVaccine;
	String2 sDate;
	String2 sDose;
	TimeString sTime;
}; //VaccAppoint is alias to call and change data within struct UserRegistration

typedef struct VaccinationAppointment SecondReg[100];
SecondReg Appointment;

struct ChatBot
{
	QandA sQuestion;
	QandA sAnswer;
};

typedef struct ChatBot ChatTEMP;
ChatTEMP TempChatBot;

typedef struct UserRegistration TEMPUSER;
TEMPUSER TempUserReg;

typedef struct VaccinationAppointment TEMPVACC;
TEMPVACC TempApp;

typedef struct ChatBot ChatStuff[100];
ChatStuff Chatbot;

typedef struct UserRegistration FirstReg[100]; 
FirstReg UserReg;

typedef struct VaccinationAppointment ClearApp;
ClearApp DelApp;

typedef struct UserRegistration Deletion;
Deletion DelReg; //For clearing invalid inputs in UserRegistration
/* int 
main()
{
    int size = 1;
    String1 Word[size];

    scanf("%s", Word);

    printf("Before deletion: %s", Word[0]);

    Word[0][0] = '\0';

    printf("\nAfter deletion: %s", Word);
     printf("\nAfter deletion: %c", Word[0][1]);
      printf("\nAfter deletion: %c", Word[0][2]);

    return 0;
}*/

/*struct Data 
{
  int num;
  float number;
  String1 WORD;
};
typedef struct Data Arr[10];
Arr Access1;

int 
main
()
{
  Access1[0].num = 1;
  Access1[0].number = 6.9;
  fgets(Access1[0].WORD,100, stdin);

  printf("%d\n%f\n%s\n",Access1[0].num,Access1[0].number, Access1[0].WORD );

  Access1[0]=Access1[1];

  printf("\n%d\n", Access1[0].num);
  printf("%f\n", Access1[0].number);
  printf("WORD: %s\n", Access1[0].WORD); 

  return 0;
}*/
void 
InitializeNoValStruct()
{
	DelReg.nUserID = 0;
	DelReg.nContact = 0;
	strcpy(DelReg.sAddress, "" );
	strcpy(DelReg.sBoosterDoseDate, "" );
	strcpy(DelReg.sBoosterDoseLoc, "" );
	strcpy(DelReg.sBoosterDoseVacc, "" );
	strcpy(DelReg.sFirstDoseDate, "" );
	strcpy(DelReg.sFirstDoseLoc, "" );
	strcpy(DelReg.sFirstDoseVacc, "" );
	strcpy(DelReg.sName, "" );
	strcpy(DelReg.sPassword, "" );
	strcpy(DelReg.sSecondDoseDate, "" );
	strcpy(DelReg.sSecondDoseLoc, "" );
	strcpy(DelReg.sSecondDoseVacc, "" );
	strcpy(DelReg.sSex, "" );
}

void StructPrint (FirstReg a)
{
	printf("\nContact No.: %d", a[0].nContact);
	printf("\nID: %d", a[0].nUserID);
	printf("\nAddress: %5s", a[0].sAddress);
	printf("\nBoosterDate: %5s", a[0].sBoosterDoseDate);
	printf("\n%5s", a[0].sBoosterDoseLoc);
	printf("\n%5s", a[0].sBoosterDoseVacc);
	printf("\n%5s", a[0].sName);
	printf("\n%5s", a[0].sPassword);
	printf("\n%4s\n", a[0].sSex);
}

/* int
main
()
{
	//UserReg[0].nContact = 21;
	//UserReg[0].nUserID = 25;
	strcpy(UserReg[0].sAddress,"Hatdog");
	strcpy(UserReg[0].sBoosterDoseDate,"2021-12-21");
	strcpy(UserReg[0].sBoosterDoseLoc,"Quezon");
	strcpy(UserReg[0].sBoosterDoseVacc,"Moderna");
	strcpy(UserReg[0].sName,"Kurvy J. Morales");
	strcpy(UserReg[0].sPassword,"Secret");
	strcpy(UserReg[0].sSex,"Male");

StructPrint(&UserReg[0]);

UserReg[0] = DelReg;

StructPrint(UserReg);

return 0;
} */

void 
InitializeStruct()
{
	UserReg[0].nUserID = 315;
	UserReg[0].nContact = 9151300594;
	strcpy(UserReg[0].sAddress, "Blk 8 L42" );
	strcpy(UserReg[0].sBoosterDoseDate, "12-21-2022" );
	strcpy(UserReg[0].sBoosterDoseLoc, "Quezon" );
	strcpy(UserReg[0].sBoosterDoseVacc, "Moderna" );
	strcpy(UserReg[0].sFirstDoseDate, "12-21-2020" );
	strcpy(UserReg[0].sFirstDoseLoc, "Makati" );
	strcpy(UserReg[0].sFirstDoseVacc, "Moderna" );
	strcpy(UserReg[0].sName, "Kurvy J. Morales" );
	strcpy(UserReg[0].sPassword, "SECRET" );
	strcpy(UserReg[0].sSecondDoseDate, "12-21-2021" );
	strcpy(UserReg[0].sSecondDoseLoc, "Manila" );
	strcpy(UserReg[0].sSecondDoseVacc, "Moderna" );
	strcpy(UserReg[0].sSex, "Male" );

	UserReg[1].nUserID = 345;
	UserReg[1].nContact = 8700877777;
	strcpy(UserReg[1].sAddress, "EWAN" );
	strcpy(UserReg[1].sBoosterDoseDate, "12-12-2022" );
	strcpy(UserReg[1].sBoosterDoseLoc, "Sheesh" );
	strcpy(UserReg[1].sBoosterDoseVacc, "Pfizer" );
	strcpy(UserReg[1].sFirstDoseDate, "12-12-2024" );
	strcpy(UserReg[1].sFirstDoseLoc, "1st Loc" );
	strcpy(UserReg[1].sFirstDoseVacc, "Pfizer" );
	strcpy(UserReg[1].sName, "Childish Gambino" );
	strcpy(UserReg[1].sPassword, "MAMAMO" );
	strcpy(UserReg[1].sSecondDoseDate, "2ndDate" );
	strcpy(UserReg[1].sSecondDoseLoc, "Location2" );
	strcpy(UserReg[1].sSecondDoseVacc, "2ndVacc" );
	strcpy(UserReg[1].sSex, "Alien" );

	UserReg[2].nUserID = 23465;
	UserReg[2].nContact = 94223445;
	strcpy(UserReg[2].sAddress, "123456789012345678901234567890" );
	strcpy(UserReg[2].sBoosterDoseDate, "12-6-2077" );
	strcpy(UserReg[2].sBoosterDoseLoc, "SHHH" );
	strcpy(UserReg[2].sBoosterDoseVacc, "Nirvana" );
	strcpy(UserReg[2].sFirstDoseDate, "2021-12-20" );
	strcpy(UserReg[2].sFirstDoseLoc, "Nako" );
	strcpy(UserReg[2].sFirstDoseVacc, "Nirvana" );
	strcpy(UserReg[2].sName, "Donald Glover" );
	strcpy(UserReg[2].sPassword, "Redbone" );
	strcpy(UserReg[2].sSecondDoseDate, "12-04-6450" );
	strcpy(UserReg[2].sSecondDoseLoc, "Nevada" );
	strcpy(UserReg[2].sSecondDoseVacc, "Nirvana" );
	strcpy(UserReg[2].sSex, "Male" );

	strcpy(Chatbot[0].sQuestion, "Is vaccination mandatory?");
	strcpy(Chatbot[0].sAnswer, "No, but it is highly recommended by the government.");

	strcpy(Chatbot[1].sQuestion, "What are the possible side effects of vaccination?");
	strcpy(Chatbot[1].sAnswer, "The possible side effects include pain, fever, fatigue and headache.");

	strcpy(Chatbot[2].sQuestion, "No");
	strcpy(Chatbot[2].sAnswer, "What do you mean no? >:(");

	strcpy(Chatbot[3].sQuestion, "Never gonna give you up");
	strcpy(Chatbot[3].sAnswer, "Never gonna let you down");

	strcpy(Chatbot[4].sQuestion, "Never gonna run around and desert you");
	strcpy(Chatbot[4].sAnswer, "Never gonna make you cry");

	strcpy(Chatbot[5].sQuestion, "Never gonna say goodbye");
	strcpy(Chatbot[5].sAnswer, "Never gonna tell a lie and hurt you <3");
	/*  Appointment[0].nUserID = 315;
	Appointment[0].nAppID = 21;
	strcpy(Appointment[0].sDate, "LOREM IPSU" );
	strcpy(Appointment[0].sDose, "LOREM IPSU" );
	strcpy(Appointment[0].sLocation, "LOREM IPSU" );
	strcpy(Appointment[0].sName, "LOREM IPSU" );
	strcpy(Appointment[0].sTime, "LORE" );
	strcpy(Appointment[0].sVaccine, "LOREM IPSU" );

	Appointment[1].nUserID = 345;
	Appointment[1].nAppID = 34534;
	strcpy(Appointment[1].sDate, "LOREM IPSU" );
	strcpy(Appointment[1].sDose, "LOREM IPSU" );
	strcpy(Appointment[1].sLocation, "LOREM IPSU" );
	strcpy(Appointment[1].sName, "LOREM IPSU" );
	strcpy(Appointment[1].sTime, "LORE" );
	strcpy(Appointment[1].sVaccine, "LOREM IPSU" ); */

	/* UserReg[3].nUserID = 3;
	UserReg[3].nContact = 696969;
	strcpy(UserReg[3].sAddress, "123456789012345678901234567890" );
	strcpy(UserReg[3].sBoosterDoseDate, "" );
	strcpy(UserReg[3].sBoosterDoseLoc, "" );
	strcpy(UserReg[3].sBoosterDoseVacc, "" );
	strcpy(UserReg[3].sFirstDoseDate, "" );
	strcpy(UserReg[3].sFirstDoseLoc, "" );
	strcpy(UserReg[3].sFirstDoseVacc, "" );
	strcpy(UserReg[3].sName, "12345678901234567890" );
	strcpy(UserReg[3].sPassword, "" );
	strcpy(UserReg[3].sSecondDoseDate, "" );
	strcpy(UserReg[3].sSecondDoseLoc, "" );
	strcpy(UserReg[3].sSecondDoseVacc, "" );
	strcpy(UserReg[3].sSex, "" ); */
}
void printusers(int *index)
{ 
int i;
	printf("\n-------------------VIEWING ALL USERS--------------------------------------VIEWING ALL USERS-------------------");
	for (i = 0; i < *index; i++)
	{
		printf("\n**********************USER #%d************************||", i+1);
		if (UserReg[i+1].nUserID != 0)
		printf("**********************USER #%d************************||", i+2);

		printf("\nUser ID:               %-30d||", UserReg[i].nUserID);
		if (UserReg[i+1].nUserID != 0)
		printf("User ID:               %-30d||", UserReg[i+1].nUserID);

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

void printapp()
{
	int AppCount = 2;
	int i;
    for (int c = AppCount; c < 100; c++)
        {
            Appointment[c] = DelApp;
        }

	printf("\n-------------------VIEWING ALL APPOINTMENTS------------------------VIEWING ALL APPOINTMENTS-------------------");
	for (i = 0; i < AppCount; i++)
	{
		printf("\n**********************USER #%d************************||", i+1);
		if (Appointment[i+1].nAppID != 0)
		printf("**********************USER #%d************************||", i+2);

		printf("\nApp ID:                %-30d||", Appointment[i].nAppID);
		if (Appointment[i+1].nAppID != 0)
		printf("App ID:                %-30d||", Appointment[i+1].nAppID);

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
	
	printf("\nTotal Number of Users Registered: %d\n", AppCount);
}

void PrintQandA(int count)
{
    int i = 0;

    printf("\n--------------------VIEWING ALL QUESTIONS AND ANSWERS--------------------\n");

    for (i = 0; i < count; i++)
    {
        printf("\nQ%d: %s", i+1, Chatbot[i].sQuestion);
        printf("\nA%d: %s\n", i+1, Chatbot[i].sAnswer);
    }

    printf("\n----------------------------END OF PRINTING------------------------------\n");
    printf("\nTotal number of Questions + Answers: %d", count);
}

int
main 
()
{
int i = 0;
int test = 5;
int index = 3; 
int AppCount = 0;
int choice;
char Pick;
char Pick2;
int ValidInput = 0;
InitializeNoValStruct();
InitializeStruct();

/* while (ValidInput == 0) //ALGO FOR SEX MALE OR FEMALE 
	{
		printf("Enter your sex (Male / Female): ");
			scanf(" %[^\n]s", UserReg[1].sSex);

			if (strcmp(UserReg[1].sSex, "Male") != 0 && strcmp(UserReg[1].sSex, "Female") != 0)
			{
				printf("\nInvalid sex entered!\n");
			}
			else
			ValidInput = 1;
	}
	ValidInput = 0; */
 for (int c = index; c < 100; c++)
{
UserReg[c] = DelReg;
}
/* while (ValidInput == 0)
{
    int z = 0;
    printf("Enter password (Maximum of 10 characters): ");
    //Loop to mask password being inputted
    while ((UserReg[0].sPassword[z] = getch()) != 13) //13 = ASCII value of enter
    {
        if (UserReg[0].sPassword[z] == 8 && z > 0)
        {
            printf("\b \b");
            z--;
        }
        else if (UserReg[0].sPassword[z] != 8)
        {
            printf("*");
            z++;
        }
    }
    UserReg[0].sPassword[z] ='\0';

    if (strlen(UserReg[0].sPassword) > 10)
    {
        printf("\nInvalid password!\n");
    }
    else
    {
		printf("\nYour password is %s", UserReg[0].sPassword);
        ValidInput = 1;
        printf("\n");
    }
} */
/* while (ValidInput == 0)
	{
		int z = 0;
		printf("\nEnter password (Maximum of 10 characters): ");
		//Loop to mask password being inputted
		while (  (UserReg[i].sPassword[z] = getch() )  != 13 ) //13 = ASCII value of enter
		{
			if (UserReg[i].sPassword[z] == 8 && z >= 0)
			{
				printf("\b");
				z--;
			}
			else
			{
				printf("*");
				z++;
			}
		}
		UserReg[i].sPassword[z] ='\0';

		if ( strlen(UserReg[i].sPassword) > 10)
		{
			printf("\nInvalid password!\n");
		}
		else
		ValidInput = 1;
	}
	ValidInput = 0; */
	printusers(&index);
	printapp();
	PrintQandA(6);
	printf("\n5. Import \n6. Export\n");
	scanf("%d", &choice);

	if (choice == 5)
	{
		char temp2[31];
		ValidInput = 0;
		AppCount = 0;
		FILE *AppImp, *UsersImp, *ChatbotImp;
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
		 while (fscanf(AppImp, "%d %d\n", &TempApp.nAppID, &TempApp.nUserID) == 2) 
		 {
			fscanf(AppImp, "%[^\n]\n", TempApp.sName);
			fscanf(AppImp, "%[^\n]\n", TempApp.sLocation);
			fscanf(AppImp, "%s\n", TempApp.sVaccine);
			fscanf(AppImp, "%s\n", TempApp.sDate);
			fscanf(AppImp, "%s\n", TempApp.sTime);
			fscanf(AppImp, "%s\n", TempApp.sDose);
			fscanf(AppImp, "\n"); // read the empty line after each appointment
		
			printf("\nApp ID: %d UserID: %d", TempApp.nAppID, TempApp.nUserID);
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
					Appointment[AppCount] = TempApp;
   					AppCount++;
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

		 printf("\nData sucessfully imported.");
		 fclose (AppImp);
		 printapp();
	//END OF IMPORT APPOINTMENT.TXT************************************

	//START OF IMPORT USERS.TXT HERE*************************
		printusers(&index);
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

		while (fscanf(UsersImp, "%d %[^\n]\n", &TempUserReg.nUserID, TempUserReg.sPassword) == 2) 
		 {
			fscanf(UsersImp, "%[^\n]\n", TempUserReg.sName);
			fscanf(UsersImp, "%[^\n]\n", TempUserReg.sAddress);
			fscanf(UsersImp, "%lld\n", &TempUserReg.nContact);
			fscanf(UsersImp, "%s\n", TempUserReg.sSex);
			fscanf(UsersImp, "%s %s %s\n", TempUserReg.sFirstDoseLoc,TempUserReg.sFirstDoseDate,  TempUserReg.sFirstDoseVacc);
			fscanf(UsersImp, "%s %s %s\n", TempUserReg.sSecondDoseLoc,TempUserReg.sSecondDoseDate,  TempUserReg.sSecondDoseVacc);
			fscanf(UsersImp, "%s %s %s\n", TempUserReg.sBoosterDoseLoc,TempUserReg.sBoosterDoseDate,  TempUserReg.sBoosterDoseVacc);
			fscanf(UsersImp, "\n"); // read the empty line after each appointment
		
			printf("\nUserID: %d Password: %s", TempUserReg.nUserID, TempUserReg.sPassword);
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
					UserReg[index] = TempUserReg;
   					index++;
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

		printf("\nData successfully Imported.");
		fclose (UsersImp);
		printusers(&index);		
	//END OF IMPORT USERS.TXT HERE**********************

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

		 while (fscanf(ChatbotImp, "%[^\n]\n", TempChatBot.sQuestion) == 1) 
		 {
			fscanf(ChatbotImp, "%[^\n]\n", TempChatBot.sAnswer);

			printf("\nQUESTION: %s", TempChatBot.sQuestion);
			printf("\nANSWER: %s", TempChatBot.sAnswer);

			while (ValidInput == 0)
			{
				printf("\n\nWould you like to record this entry? (Y/N): ");
					scanf(" %c", &Pick2);

				if (Pick2 == 'Y')
				{
					Chatbot[test] = TempChatBot;
   					test++;
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

		printf("\nData successfully Imported.");
		PrintQandA(test);
		fclose (ChatbotImp); 
	//END OF IMPORT CHATBOT.TXT HERE**********************

	}
	else if (choice == 6)
	{
		char temp[31];
		ValidInput = 0;
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

			for (int i = 0; i < index; i++)
			{
				fprintf(fp, "%d %s\n", UserReg[i].nUserID, UserReg[i].sPassword);
				fprintf(fp, "%s\n", UserReg[i].sName);
				fprintf(fp, "%s\n", UserReg[i].sAddress);
				fprintf(fp, "%lld\n", UserReg[i].nContact);
				fprintf(fp, "%s\n", UserReg[i].sSex);
				fprintf(fp, "%s %s %s\n", UserReg[i].sFirstDoseLoc, UserReg[i].sFirstDoseDate, UserReg[i].sFirstDoseVacc);
				fprintf(fp, "%s %s %s\n", UserReg[i].sSecondDoseLoc, UserReg[i].sSecondDoseDate, UserReg[i].sSecondDoseVacc);
				fprintf(fp, "%s %s %s\n", UserReg[i].sBoosterDoseLoc, UserReg[i].sBoosterDoseDate, UserReg[i].sBoosterDoseVacc);
				fprintf(fp, "\n");
			}
			printf("\nData sucessfully exported.");
		fclose(fp);
//USERS.txt EXPORT ENDS HERE*************	

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
		
				for (int i = 0; i < AppCount; i++)
				{
					fprintf(app, "%d %d\n", Appointment[i].nAppID, Appointment[i].nUserID);
					fprintf(app, "%s\n", Appointment[i].sName);
					fprintf(app, "%s\n", Appointment[i].sLocation);
					fprintf(app, "%s\n", Appointment[i].sVaccine);
					fprintf(app, "%s \n", Appointment[i].sDate);
					fprintf(app, "%s\n", Appointment[i].sTime);
					fprintf(app, "%s\n", Appointment[i].sDose);
					fprintf(app, "\n");
				}
					printf("\nData sucessfully exported.");
			fclose(app);
		//EXPORT APPOINTMENT.txt ENDS HERE********
		
		//EXPORT CHATBOT.txt ENDS HERE********
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

			for (int i = 0; i < 5; i++)
			{
				fprintf(chatbot, "%s\n", Chatbot[i].sQuestion);
				fprintf(chatbot, "%s\n", Chatbot[i].sAnswer);
			}
			printf("\nData sucessfully exported.");

		fclose(chatbot);
	}
	else
	printf("\nNo such choice exists");

	printf("\nGoing back to previous menu . . .");
/* int AppCount = 2;
    for (int c = AppCount; c < 100; c++)
        {
            Appointment[c] = DelApp;
        }

	printf("\n-------------------VIEWING ALL APPOINTMENTS------------------------VIEWING ALL APPOINTMENTS-------------------");
	for (i = 0; i < AppCount; i++)
	{
		printf("\n**********************USER #%d************************||", i+1);
		if (Appointment[i+1].nAppID != 0)
		printf("**********************USER #%d************************||", i+2);

		printf("\nApp ID:                %-30d||", Appointment[i].nAppID);
		if (Appointment[i+1].nAppID != 0)
		printf("App ID:                %-30d||", Appointment[i+1].nAppID);

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
	
	printf("\nTotal Number of Users Registered: %d\n", AppCount); */

	return 0;
}
