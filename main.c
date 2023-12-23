#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Sign up And Sign in
#define MAX_USERNAME_LENGTH 50
#define MAX_USERPASS 50

//Online Courses registration
#define MAX_COURSES 10
#define MAX_NAME_LEN 50

//Hotel Booking services
#define MAX_NAME_LENGTH 50
#define MAX_CITIES 5
#define MAX_HOTELS 25

//Digital marketing advertisement
#define LOW_FOLLOWER_COUNT 5000
#define MEDIUM_FOLLOWER_COUNT 10000

//structure
//struct USER{
  //  char username[MAX_USERNAME_LENGTH];
    //char password[MAX_USERPASS];
//};
//sign up function
//void signup(){
//    struct USER user;
//    FILE *signfile;
  //  signfile=fopen("Assignment-Fop.txt","a");

    //printf("Enter username:");
    //scanf("%s",user.username);

    //printf("Enter password:");
    //scanf("%s",&user.password);

    //fprintf(signfile,"%s %s\n",user.username,user.password);
    //fclose(signfile);
//    printf("Sign up successfully:\n");
//}
//login Function
//void login(){
//    struct USER user;
  //      FILE *loginfile;
//   char enter_username[MAX_USERNAME_LENGTH];
//   char enter_userpassword[MAX_USERPASS];

  // loginfile=fopen("Assignment-Fop.txt","r");

   // printf("Enter username:");
  //  scanf("%s",&enter_username);

//    printf("Enter password:");
 //   scanf("%s",&enter_userpassword);
//    while(fscanf(loginfile,"%s %s",user.username,user.password) !=EOF){
   //     if(strcmp(user.username, enter_username)==0 && strcmp(user.password,enter_userpassword)==0){
     //           fclose(loginfile);
       // printf("Login succesfully Welcome:\n%s;\n",user.username);
     //   return;
    //    }
  //  }
    //    fclose(loginfile);
      //  printf("login failed.Invalid username or password");
//}
// Online courses services



// Structure for  online course information
// start

typedef struct {
    char courseName[MAX_NAME_LEN];
    char instructorName[MAX_NAME_LEN];
    float price;
    int maxDurationMonth;
} Course;

// Initialize courses
Course courses[MAX_COURSES] = {
    {"Programming Basics", "Sir Usama Khalid", 1000.0, 12},
    {"Web Development", "Sir Burhan",500.0, 9},
    {"Data Science", "Miss Sadia khan",400.0, 8},
    {"IT Metaverse","Sir Kamran khan",100.0,5},
    {"Free Lancing","Sir Alfaid",350,3},
    {"Graphic Designing","Sir Ahmed",150,6},
    {"Video Editing","Sir Nouman",70,2},
};

int courseCount = 7; // number for courses

// Function display courses
void displayCourses() {
	printf("\n----------------------");
    printf("\n  Available Courses:\n");
    printf("----------------------\n\n");
    printf("_________________________________________\n");
    for (int i = 0; i < courseCount; i++) {
        printf("\n %d. Course Name: %s, Instructor: %s:  Total Price: %.2f, Max Duration: %d months\n\n",
               i + 1,
               courses[i].courseName,
               courses[i].instructorName,
               courses[i].price,
               courses[i].maxDurationMonth);
    }
}

// Function calculate and display monthly cost for Online Courses
void calculateAndDisplayCosts(int courseIndex, int rentalMonths) {
    if (courseIndex < 0 || courseIndex >= courseCount) {
        printf("Invalid course Selection:\n");
        return;
    }

    if (rentalMonths <= 0 || rentalMonths > courses[courseIndex].maxDurationMonth) {
        printf("Invalid rent duration. Please choose between 1 and %d months.\n", courses[courseIndex].maxDurationMonth);
        return;
    }

    Course selectedCourse = courses[courseIndex];
    float monthlyRate = selectedCourse.price / selectedCourse.maxDurationMonth;
    float totalCost = monthlyRate * rentalMonths;

    printf("\nCourse Selected: %s\nMonthly Rate: %.2f\nTotal Cost for %d months: %.2f\n",
           selectedCourse.courseName, monthlyRate, rentalMonths, totalCost);
}
//end
//online courses registration

// online Car rent service
//start
// Structure to store car details
struct Car {
    char name[50];
    int category;
    int rentPerDay;
};

// Function to display car details
void displayCar(struct Car car) {
    printf("Car Name: %s\n", car.name);
    printf("Category: %d\n", car.category);
    printf("Rent per Day: %d\n", car.rentPerDay);
    printf("------------------------\n");
}
//end
//online car rent service

//Hotel Booking service
    //start
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char city[MAX_NAME_LENGTH];
    int availableRooms;
    double pricePerNight;
} Hotel;
void displayCities() {
    printf("\n----------------");
    printf("\nList of Cities:\n");
    printf("----------------\n");
    printf("1. Karachi\n");
    printf("2. Lahore\n");
    printf("3. Islamabad\n");
    printf("4. Peshawar\n");
    printf("5. Multan\n");
}
void displayHotels(Hotel hotels[], int hotelCount, char city[]) {
    printf("\nList of Available Hotels in %s:\n", city);
    for (int i = 0; i < hotelCount; i++) {
        if (strcmp(hotels[i].city, city) == 0) {
            printf("%d. %s\n", hotels[i].id, hotels[i].name);
        }
    }
}
void reserveHotel(Hotel hotels[], int hotelCount, char city[]) {
    int hotelId, numberOfRooms, nights;

    printf("\n\n------------------------------");
    printf("\n *** Hotel Reservation ***");
    printf("---------------------------------\n");
    printf("Enter the hotel ID: ");
    scanf("%d", &hotelId);

    if (hotelId == 0) {
        return;
    }

    if (hotelId < 1 || hotelId > hotelCount || strcmp(hotels[hotelId - 1].city, city) != 0) {
        printf("Invalid hotel ID. Please try again.\n");
        return;
    }

    printf("Enter the number of rooms: ");
    scanf("%d", &numberOfRooms);

    printf("Enter the number of nights: ");
    scanf("%d", &nights);

    if (numberOfRooms <= 0 || nights <= 0 || numberOfRooms > hotels[hotelId - 1].availableRooms) {
        printf("Invalid input. Please enter valid values.\n");
        return;
    }

    hotels[hotelId - 1].availableRooms -= numberOfRooms;

    printf("------------------------------------\n");
    printf("Reservation successful! \nYour reservation details:\n");
    printf("------------------------------------\n");
    printf("Hotel Name: %s\n", hotels[hotelId - 1].name);
    printf("City: %s\n", hotels[hotelId - 1].city);
    printf("Number of Rooms: %d\n", numberOfRooms);
    printf("Number of Nights: %d\n", nights);
    printf("Total Cost: $%.2f\n", hotels[hotelId - 1].pricePerNight * numberOfRooms * nights);
}
    //end
    //hotel Booking Service

//Online Ticket Booking Services
    //start
// Define structures for flights and tickets
struct Flight {
    char name[50];
    float fare;
    // Add more details like departure, arrival, etc., as needed
};

struct Ticket {
    char passengerName[50];
    struct Flight flight;
    int classType;// 1 for economy, 2 for business, etc.
    int quantity;
};

// Function to book a ticket
void bookTicket(struct Flight flights[], int numFlights) {
    int choice;
    printf("Available Flights:\n");
    for (int i = 0; i < numFlights; ++i) {
        printf("%d. %s - $%.2f\n", i + 1, flights[i].name, flights[i].fare);
    }
    printf("Enter the flight number to book: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= numFlights) {
        struct Ticket ticket;
        printf("Enter passenger name: ");
        scanf("%s", ticket.passengerName);
        ticket.flight = flights[choice - 1];

        printf("Select class type (1. Economy, 2. Business, etc.): ");
        scanf("%d", &ticket.classType);
printf("How many seats you want:");
scanf("%d",& ticket.quantity);
        // Print the ticket
        printf("\n--- Ticket Booked ---\n");
        printf("Passenger Name: %s\n", ticket.passengerName);
        printf("Flight: %s\n", ticket.flight.name);
        printf("Class: %d\n", ticket.classType);
        printf("Seats:%d\n",ticket.quantity);
        printf("Fare: $%.2f\n", ticket.flight.fare*ticket.quantity);
    } else {
        printf("Invalid choice.\n");
    }
}
// Structure to store train information
struct Train {
    char name[50];
    char city[50];
    float fare;
    int availableTickets;
};

// Function to display train information
void displayTrains(struct Train trains[], int numTrains) {
    printf("\nTrain Information:\n");
    printf("%-20s%-20s%-15s%s\n", "Train Name", "City", "Fare", "Available Tickets");
    for (int i = 0; i < numTrains; i++) {
        printf("%-20s%-20s%-15.2f%d\n", trains[i].name, trains[i].city, trains[i].fare, trains[i].availableTickets);
    }
}

// Function to book tickets
void bookTickets(struct Train trains[], int trainIndex, int quantity) {
    if (trainIndex >= 0 && trainIndex < 5) {
        if (trains[trainIndex].availableTickets >= quantity) {
            trains[trainIndex].availableTickets -= quantity;
            printf("\nBooking successful! %d tickets booked for %s.\n", quantity, trains[trainIndex].name);
        } else {
            printf("\nNot enough tickets available for %s.\n", trains[trainIndex].name);
        }
    } else {
        printf("\nInvalid train selection.\n");
    }
}

    //end
    //Online Ticket Booking services

    //ONLINE BUSINESS AND COMPANY ADVERTISEMENT int main mein hai koi function or structure nahi hai

//main function
int main()
{
    int choice;
    char continue_loop;
    char management_continue;//Continue Management
    do{
        printf("\n\n\t\t--------------------------------------------\t\t\n");
        printf("    \t\t***   Welcome to Signup and login page:   ***\t\t\n");
        printf("    \t\t--------------------------------------------\t\t\n\n");
        printf("1.signUp.\n");
        printf("2.Login.\n");
        printf("\nEnter your Choice:");
        scanf("%d",&choice);
        switch(choice){
    case 1:
//        signup();
        break;
    case 2:
  //      login();
        break;

    default:
        printf("Invalid choice !:\n");
        break;
    }
        printf("Do you want to Signup and login Again (y/n): ");
        scanf(" %c", &continue_loop);
}while(continue_loop == 'y' || choice == 'Y');

                            //Digital service Management system
        printf("\n\t\t----------------------------------------------\n");
        printf("\t\t Welcome To Digital Service Management System \n");
        printf("\t\t----------------------------------------------\n\n");
    printf("  || ***** Which Services You are Looking *****\t ||\n\n");
    int choice_1;
    int select;//this variable is  continue loop choice 1 where i can see the couses available
    printf("1.Customer Avail Services. \t\t 2.Current Customer using Services.\n");
    printf("\nEnter Choice:\n");
    scanf("%d",&choice_1);
   do{
    switch(choice_1){
    case 1:
    printf("__________________________________________________________________________\n");
    printf("\n\t *** WELL COME TO DIGITAL SERVICE MENU. ***\n\n");
    printf("(1)ONLINE COURSE  SERVICE.\n");
    printf("(2)RENT A CAR  SERVICE.\n");
    printf("(3)HOTEL  BOOKING SERVICE .\n");
    printf("(4)TICKET BOOKING SERVICE.\n");
    printf("(5)ONLINE Marketing Management System.\n");
    printf("\nEnter service you want :");
    scanf("\n\t%d",&select);
    switch (select) {
  case 1:
    printf("\tONLINE  COURSE SERVICE.");
    //online Courses registration
    //start
    int courseChoice, rentalMonths;
    char user_input[4];

    do{
        displayCourses();
        printf("________________________________________\n");
        printf("\nEnter the number of the course you want to rent: ");
        scanf("%d", &courseChoice);

        if (courseChoice == courseCount + 1) {
            break; // exit
        } else if (courseChoice < 1 || courseChoice > courseCount) {
            printf("Invalid course selection. Please try again.\n");
            continue;
        }

        printf("Enter the number of months you want to rent the course: ");
        scanf("%d", &rentalMonths);

        calculateAndDisplayCosts(courseChoice - 1, rentalMonths);

        printf("\n Do you want to continue? (yes/no):");
        scanf("%s", user_input);
    }while(user_input=="no" || user_input == "no");
    printf("\n\tThank you for rent this courses\n");
    //end
    //online Courses registration
    break;
  case 2:
    printf("RENT A CAR  SERVICE.");
    //Rent a car service
    //start
     // Array to store cars
    struct Car cars[15];

    printf("\n\t\t _______________________________________\n");
    printf("\n\t\t**Online Rent a car management system**\n");
    printf("\t\t_________________________________________\n\n");

    // Adding low category cars
    strcpy(cars[0].name, "Suzuki Mehran");
    cars[0].category = 1;
    cars[0].rentPerDay = 4000;

    strcpy(cars[1].name, "Suzuki Khyber");
    cars[1].category = 1;
    cars[1].rentPerDay = 4500;

    strcpy(cars[2].name, "Suzuki Alto");
    cars[2].category = 1;
    cars[2].rentPerDay = 5000;

    strcpy(cars[3].name, "Suzuki Cultus");
    cars[3].category = 1;
    cars[3].rentPerDay = 5500;

    strcpy(cars[4].name, "Suzuki Swift");
    cars[4].category = 1;
    cars[4].rentPerDay = 6000;

    // Adding mid category cars
    strcpy(cars[5].name, "HONDA Civic");
    cars[5].category = 2;
    cars[5].rentPerDay = 10000;

    strcpy(cars[6].name, "TOYOTA Corolla Altis");
    cars[6].category = 2;
    cars[6].rentPerDay = 11000;

    strcpy(cars[7].name, "TOYOTA Yaris");
    cars[7].category = 2;
    cars[7].rentPerDay = 12000;

    strcpy(cars[8].name, "HYUNDAI Elantra");
    cars[8].category = 2;
    cars[8].rentPerDay = 13000;

    strcpy(cars[9].name, "KIA Sportage");
    cars[9].category = 2;
    cars[9].rentPerDay = 14000;

    // Adding luxury category cars
    strcpy(cars[10].name, "Land Cruiser");
    cars[10].category = 3;
    cars[10].rentPerDay = 30000;

    strcpy(cars[11].name, "Lexus LX570");
    cars[11].category = 3;
    cars[11].rentPerDay = 35000;

    strcpy(cars[12].name, "Audi A4");
    cars[12].category = 3;
    cars[12].rentPerDay = 40000;

    strcpy(cars[13].name, "Audi A5");
    cars[13].category = 3;
    cars[13].rentPerDay = 45000;

    strcpy(cars[14].name, "MERCEDES CLA200");
    cars[14].category = 3;
    cars[14].rentPerDay = 50000;

    // User input
    int choice;
    int days;

 {
        printf("Choose a car category:\n");
        printf("1. Budget\n");
        printf("2. Standard\n");
        printf("3. Luxury\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0) {

        }

        printf("\nAvailable cars:\n\n");

        // Display cars based on category
        for (int i = 0; i < 15; i++) {
            if (cars[i].category == choice) {
                displayCar(cars[i]);
            }
        }

        printf("Enter the car number you want to rent: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 15) {
            printf("Invalid car number!\n");

        }

        printf("Enter the number of days you want to rent the car: ");
        scanf("%d", &days);

        int rent = cars[choice - 1].rentPerDay * days;

        printf("\nSuccessfully rented!\n");
        printf("Total rent: %d\n", rent);

        if (days >= 7) {
            printf("Special discount applied!\n");
            rent /= 2;
            printf("Discounted rent: %d\n", rent);
        }

        printf("------------------------\n");
    }
    //end
    //rent a car service
    break;
  case 3:
    printf("HOTEL  BOOKING SERVICE.\n\n");
    //Hotel Booking service
    //start
 Hotel hotels[MAX_HOTELS] = {
        {1, "PC Hotel              - 100$ per night", "Karachi", 10, 100.0},
        {2, "Ramada Hotel          - 150$ per night","Karachi", 12, 150.0},
        {3, "Marriot Hotel         - 110$ per night","Karachi",10,110.0},
        {4, "Movenpick             - 120$ per night","Karachi",15,120.0},
        {5, "Avari Towers          - 100$ per night","Karachi",11,100.0},
        {6, "PC Hotel              - 120$ per night", "Lahore", 20, 120.0},
        {7, "Ramada Hotel          - 100$ per night","Lahore",10,100.0},
        {8, "Marriot Hotel         - 100$ per night","Lahore",10,100.0},
        {9, "Movenpick             - 120$ per night","Lahore",15,120.0},
        {10, "Park Lane hotel      - 100$ per night","Lahore",12,100.0},
        {11, "PC Hotel             - 90$ per night", "Islamabad", 15, 90.0},
        {12, "Ramada Hotel         - 120$ per night","Islamabad",13,120.0},
        {13, "Marriot Hotel        - 130$ per night","Islamabad",15,130.0},
        {14, "Serena Hotel         - 150$ per night","Islamabad",15,150.0},
        {15, "Jacaranda Heights    - 100$ per night","Islamabad",15,100.0},
        {16, "PC Hotel                - 100$ per night","Peshawar",12,100.0},
        {17, "Luxury Palace Hotel     - 90$ per night", "Peshawar", 15, 90.0},
        {18, "Ramada Hotel            - 120$ per night","Peshawar",13,120.0},
        {19, "Marriot Hotel           - 130$ per night","Peshawar",15,130.0},
        {20, "Serena Hotel            - 150$ per night","Peshawar",15,150.0},
        {21, "PC Hotel                - 100$ per night","Multan",12,100.0},
        {22, "Avari Hotel             - 90$ per night", "Multan", 15,90.0},
        {23, "Ramada Hotel            - 120$ per night","Multan",13,120.0},
        {24, "Marriot Hotel           - 130$ per night","Multan",15,130.0},
        {25, "Serena Hotel            - 150$ per night","Multan",15,150.0},
        // You can add more hotels
    };
    int hotelCount = sizeof(hotels) / sizeof(hotels[0]);

    int choice_2;
    char selectedCity[MAX_NAME_LENGTH];

    printf("---------------------------------------------\n");
    printf("** Online Hotel Reservation System ***\n");
    printf("---------------------------------------------\n\n");

        displayCities();
        printf("\nEnter the number of the city you want to explore: ");
        scanf("%d", &choice_2);

        if (choice >= 1 && choice <= 5) {
            switch (choice) {
                case 1: strcpy(selectedCity, "Karachi"); break;
                case 2: strcpy(selectedCity, "Lahore"); break;
                case 3: strcpy(selectedCity, "Islamabad"); break;
                case 4: strcpy(selectedCity, "Peshawar"); break;
                case 5: strcpy(selectedCity, "Multan"); break;
            }

            displayHotels(hotels, hotelCount, selectedCity);
            reserveHotel(hotels, hotelCount, selectedCity);
        }

    printf("Thanks for using online hotel reservation service :)\n");
    //end
    //hotel Booking Service
    break;
  case 4:
    printf("TICKET BOOKING SERVICE.");
    //Online Ticket Booking Services
    //start
    // Define structures for flights and tickets
int n;
    struct Flight flights[3]; // Array of flights, change the size as needed
printf("\tWelcome to Online Ticket Booking Services\n\n");
printf(" (1)-Aeroplane\n");
printf(" (2)-Trains\n");
printf("\n Which Runway you prefer:");
scanf("%d",&n);
if(n==1){
    // Initialize flights (name and fare)
    strcpy(flights[0].name, "PIA");
    flights[0].fare = 200.0;

    strcpy(flights[1].name, "AIR BLUE");
    flights[1].fare = 250.0;

    strcpy(flights[2].name, "QATAR");
    flights[2].fare = 300.0;

    // Call function to book a ticket
    bookTicket(flights, 3);} // Pass the flights array and its size}



    // Initialize train information
    if(n==2){struct Train trains[5] = {
        {"Express 1", "City A", 25.50, 50},
        {"Superfast 2", "City B", 30.75, 30},
        {"Local 3", "City C", 15.25, 100},
        {"Bullet 4", "City D", 50.00, 20},
        {"Rapid 5", "City E", 40.50, 40}
    };

    int choice;
        printf("\nMenu:\n");
        printf("1. Display Train Information\n");
        printf("2. Book Tickets\n");
        printf("Choose Which lines you want to Travel: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayTrains(trains, 5);
                break;
            case 2:
                {
                    int trainIndex, quantity;
                    printf("\nEnter the train index (1-5) and quantity of tickets to book: ");
                    scanf("%d %d", &trainIndex, &quantity);
                    bookTickets(trains, trainIndex - 1, quantity);
                }
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
       }
    }
    //end
    //Online Ticket Booking services
    break;
  case 5:
    printf("ONLINE BUSINESS AND COMPANY ADVERTISEMENT.\n ");
    //ONLINE BUSINESS AND COMPANY ADVERTISEMENT
    //start
    int option;
    int platform;
    char adDetails[100];
    int adDuration;
    int followerCount;
    double totalCharges = 0.0;

        printf("\t\t__________________________________\n");
        printf("\n\t\t **Marketing Management Sytem**\n");
        printf("\t\t__________________________________\n\n");
        printf("Available options for Advertisement:\n\n");
        printf("1. Shop\n");
        printf("2. Business\n");
        printf("3. Company\n");
        printf("4. Exit\n");
        printf("Enter the choice:\n");
        scanf("%d", &option);

        if (option == 4) {
            printf("Total charges: $%.2f\n", totalCharges);
            printf("Exiting the program. Goodbye!\n");

        }
        printf("_______________\n");
        printf("\n*Platforms*\n");
        printf("_______________\n\n");
        printf("Available platforms for Advertisement: \n\n");
        printf("1. Facebook\n");
        printf("2. Instagram\n");
        printf("3. YouTube\n");
        printf("Enter the choice:\n");
        scanf("%d", &platform);

        printf("*Details*\n");
        printf("\nEnter ad details: ");
        scanf(" %[^\n]s", adDetails);

        printf("Enter ad duration (in days): ");
        scanf("%d", &adDuration);

        printf("Enter the number of followers: ");
        scanf("%d", &followerCount);

        // Perform marketing operations based on the selected option, platform, ad details, duration, and follower count
        switch (option) {
            case 1:
                printf("_____\n");
                printf("ORDER DETAILS\n");
                printf("_____\n\n");
                printf("Running ad for Shop on ");
                break;
            case 2:
                printf("_____\n");
                printf("ORDER DETAILS\n");
                printf("_____\n");
                printf("Running ad for Business on ");
                break;
            case 3:
                printf("_______\n");
                printf("*ORDER DETAILS*\n");
                printf("_______\n\n");
                printf("Running ad for Company on ");
                break;
            default:
                printf("\n\nInvalid option. Please try again.\n\n");

        }

        // Display the selected platform, ad details, and charges based on follower count
        switch (platform) {
            case 1:
                printf("Facebook:\n");
                if (followerCount < LOW_FOLLOWER_COUNT)
                    printf("\nCharges: $50.00");
                else if (followerCount < MEDIUM_FOLLOWER_COUNT)
                    printf("\nCharges: $100.00");
                else
                    printf("\nCharges: $150.00");
                break;
            case 2:
                printf("Instagram:\n");
                if (followerCount < LOW_FOLLOWER_COUNT)
                    printf("\nCharges: $40.00");
                else if (followerCount < MEDIUM_FOLLOWER_COUNT)
                    printf("\nCharges: $80.00");
                else
                    printf("\nCharges: $120.00");
                break;
            case 3:
                printf("YouTube:\n");
                if (followerCount < LOW_FOLLOWER_COUNT)
                    printf("\nCharges: $30.00");
                else if (followerCount < MEDIUM_FOLLOWER_COUNT)
                    printf("\nCharges: $60.00");
                else
                    printf("\nCharges: $90.00");
                break;
            default:
                printf("Invalid platform. Please try again.\n\n");

        }

        // Add the charges to the total
        totalCharges += adDuration * ((platform - 1) * 30.0 + 20.0);

        printf("\nAd Details: %s\n", adDetails);
        printf("Duration: %d days\n", adDuration);

        printf("Marketing operation completed.\n\n");
        printf("\t\tThanks for using online Marketing Management System:)\n\n");
    //end
    //ONLINE BUSINESS AND COMPANY ADVERTISEMENT
    break;
    }
    case 2:
        printf("Hahahah:\n");
        break;
    default:
        printf("Invalid choice");
    }
    printf("Do you want to stop (y/n):");
    scanf(" %c",&management_continue);
   }while(management_continue=='n' || management_continue=='N');

    return 0;
}
