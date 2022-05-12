#include <cctype>
#include <iostream>
#include <cstring>
#include <cmath>           
using namespace std;

#define PI M_PI
class Number
{
    public:
        long long value;
        string factors;
        int total_factors;
};

bool isEven (int age);
void calculate_factors_of(Number& input_num);
int stringToNum(string numInString);
void display_menu(char sub_choice = '0');
int get_highest(int nums[], int size);
int get_lowest(int nums[], int size);
float get_average(int nums[], int size);

// A function to prompt user for a choice
char get_choice();
// A function to execute the specified lab
void execute_lab1();
void execute_lab2_1();
void execute_lab2_2();
void execute_lab3();
void execute_lab4();
void execute_lab5();
void execute_lab6();
void execute_lab8();

int main()
{
    char current_choice;
    // continue to prompt user for next choice after program execution until the '8' is entered as a choice
    do
    {
        display_menu();

        current_choice = get_choice();

        switch (current_choice)
        {
            case '1':
                execute_lab1();
                break;
            case '2':
                // continue to prompt user for entering sub-choice until 'B' is entered as a choice
                do 
                {
                    display_menu('2');
                    current_choice = get_choice();
                    switch (current_choice)
                    {
                        case '1':
                            execute_lab2_1();
                            break;
                        case '2':
                            execute_lab2_2();
                            break;
                        case 'B':
                            break;
                        default:
                            cout << "invalid input" << endl;
                            break;
                    }
                }
                while (current_choice != 'B');
                break;
            case '3':
                execute_lab3();
                break;
            case '4':
                execute_lab4();
                break;
            case '5':
                execute_lab5();
                break;
            case '6':
                execute_lab6();
                break;
            case '7':
                execute_lab8();
                break;
            case '8':
                break;
            default:
                cout << "invalid input" << endl;
                break;
        }
    }
    while (current_choice != '8');
    return 0;
}

char get_choice()
{
    char choice;

    cout << "Your Choice: ";
    cin >> choice;

    if (islower(choice))
    {
        choice = toupper(choice);
    }
    system("clear");
    return choice;
}

void display_menu(char sub_choice)
{
    if (sub_choice == '0')
    {
        // display main menu
        cout << "\nMAIN MENU: Select Laboratory Activity";
        cout << "\n[1] On Arithmetic Operators and Keyboard Input";
        cout << "\n[2] On Arithmetic Operators";
        cout << "\n[3] Age and Name";
        cout << "\n[4] Body Temperature";
        cout << "\n[5] Prime or Composite";
        cout << "\n[6] Grade";
        cout << "\n[7] Highest, Lowest, and Average";
        cout << "\n[8] Exit\n" << endl;
    }
    else if (sub_choice == '2')
    {
        // Display sub menu 2
        cout << "\nSELECT PROGRAMS";
        cout << "\n[1] Circumference and Area";
        cout << "\n[2] Temperature Conversion";
        cout << "\n[B] Go back to the main menu\n" << endl;
    }
}

void execute_lab1()
{
    cout << "This program will accept 3 numbers and calculate their sum, average and product\n";

    float first_num;
    cout << "\nEnter First Number: ";
    cin >> first_num;

    float second_num;
    cout << "\nEnter Second Number: ";
    cin >> second_num;

    float third_num;
    cout << "\nEnter Third Number: ";
    cin >> third_num;

    float sum = first_num + second_num + third_num;
    cout << "\nThe sum of " << first_num << ", " 
    << second_num << " and " 
    << third_num << " is " 
    << sum << endl;

    float average = sum/3;
    cout << "\nThe average of " << first_num << ", " 
    << second_num << " and " 
    << third_num << " is " 
    << average << endl;

    float product = first_num * second_num * third_num;
    cout << "\nThe product of " << first_num << ", " 
    << second_num << " and " 
    << third_num << " is " 
    << product << endl;
}
void execute_lab2_1()
{
    cout << "This program will accept a circle radius and calculate its area and circumference\n" << endl;
    
    double radius;              
    cout << "Enter radius: ";   
    cin >> radius;              
    double area = PI * (radius * radius);              
    double circumference = 2 * PI * radius;;
    cout << "The area of the circle is: " << area << endl;          
    cout << "The circumference of the circle is: " << circumference << endl; 
}
void execute_lab2_2()
{
    cout << "This progrma will accept a temperature in degree celcius and convert it to Kelvin and Fahrenheit\n" << endl;
    double celcius;           
    cout << "Enter degrees in celcius: ";
    cin >> celcius;
    double fahrenheit =  (celcius * 9/5) + 32;       
    double kelvin = celcius + 273.15;               
    cout << "The value of " << celcius << " degrees C in K is: " << kelvin << endl;     
    cout << "The value of " << celcius << " degrees C in F is: " << fahrenheit << endl; 
}

bool isEven (int age)
{
    return (age % 2 == 0) ? true: false;
}

void execute_lab3()
{
    cout << "This program will accept a name and an age and print the name 10 times if age is even, otherwise, 5 times\n" << endl;

    string name;
    cout << "Please enter your name: ";
    cin >> name;    
    
    int age;
    cout << "Please enter your age: ";
    cin >> age;
    
    if (isEven(age))
    {
        for (int i = 0; i < 10; i++)
        {
            cout << name << endl;
        }
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            cout << name << endl;
        }
    }
}
void execute_lab4()
{
    cout << "This program will accept a body temperature and display a corresponding message\n" << endl;

    float temp;
    cout << "Enter Temperature: ";
    cin >> temp;

    if (temp >= 41 && temp <= 54)
    {
        cout << "Stay hydrated!" << endl;
    }
    else if (temp >= 32 && temp <= 40)
    {
        cout << "Stay cool and safe!" << endl;
    }
    else if (temp >= 26 && temp <= 31)
    {
        cout << "Keep a sunblock handy!" << endl;
    }
    else if (temp >= 20 && temp <= 25)
    {
        cout << "Always keep your cool!" << endl;
    }
    else if (temp < 20)
    {
        cout << "Cool breeze in the air" << endl;
    }
    else
    {
        cout << "Invalid temperature" << endl;
        execute_lab4();
    }
}

void calculate_factors_of(Number& input_num)
{
    // Initialize default value of the object's properties
    input_num.total_factors = 2;
    input_num.factors = "1,";
    
    // Check the divisibility of each number less than the input number's value
    for (long long i = 2; i < input_num.value; i++)
    {
        if (input_num.value % i == 0)
        {
            input_num.factors += to_string(i) + ",";
            input_num.total_factors++;
        }
    }

    input_num.factors += to_string(input_num.value);
}

void execute_lab5()
{
    cout << "This program will accept a natural number and determine if the number is a prime or a composite.\n" << endl;
    
    // Prompt the user for input
    Number input_num;
    cout << "Enter a number: ";
    cin >> input_num.value;

    // Check the input
    while (input_num.value < 2)
    {
        cout << "Invalid input" << endl;
    }
    
    calculate_factors_of(input_num);

    // Display prime if total_facotrs
    if (input_num.total_factors == 2)
    {
        cout << to_string(input_num.value) + " is a prime number" << endl;
    }
    else
    {
        cout << to_string(input_num.value) + " is a composite number" << endl;
    }

    // Display the factors
    cout << "The factor of " + to_string(input_num.value) + " is " + input_num.factors << endl;

    // Returns 0 to indicate successful execution
}

int stringToNum(string numInString)
{
    int num = 0;
    for (int i = 0; i < numInString.length(); i++)
    {
        num *= 10;
        num += (numInString[i] - '0');
    }
    return num;
}

void execute_lab6()
{
    // Insturction
    cout << "This program accepts grades and calculate the total numbers of populations in each grade cetegory\n" << endl;
    cout << "Please enter each grade seperated by only a comma\n" << endl;
    // Prompt user for scores seperated by a space
    string unfilteredScores;
    cout << "Enter Exam Scores: ";
    cin >> unfilteredScores;

    // Declare variable to store the result
    int numberOfA = 0;
    int numberOfB = 0;
    int numberOfC = 0;
    int numberOfD = 0;
    int numberOfF = 0;
    int totalScores = 0;

    // Loop through each character until end of line or see the sentinal value
    for (int i = 0; i < unfilteredScores.length() && unfilteredScores[i] != '-'; i++)
    {
        // Capture of the string of numbers
        string numInString = "";
        while(unfilteredScores[i] != ',' && i != unfilteredScores.length() && unfilteredScores[i] != '-')
        {
            if (unfilteredScores[i] >= '0' && unfilteredScores[i] <= '9')
            {
                numInString += unfilteredScores[i];
                i++;
            }
            else
            {
                cout << "invalid input detected" << endl;
                return;
            }
        }

        // Convert the string into an integer and evaulate its category
        int num = stringToNum(numInString);
        if (num >= 90 and num <= 100)
        {
            numberOfA++;
        }
        else if (num >= 80 and num <= 89)
        {
            numberOfB++;
        }
        else if (num >= 70 and num <= 79)
        {
            numberOfC++;
        }
        else if (num >= 60 and num <= 69)
        {
            numberOfD++;
        }
        else if (num >= 0 and num <= 59)
        {
            numberOfF++;
        }
        else
        {
            cout << "invalid input detected" << endl;
            return;
        }

        totalScores++;
    } 
    // Display all populations of each category
    cout << "Number of A's: " << numberOfA << endl;
    cout << "Number of B's: " << numberOfB << endl;
    cout << "Number of C's: " << numberOfC << endl;
    cout << "Number of D's: " << numberOfD << endl;
    cout << "Number of F's: " << numberOfF << endl;
    cout << "Total number of scores: " << totalScores << endl;
}

int get_highest(int nums[], int size)
{
    int largest = nums[0];
    for (int i = 0; i < size; i++)
    {
        if (largest < nums[i])
        {
            largest = nums[i];
        }
    }
   return largest; 
}
int get_lowest(int nums[], int size)
{
    int smallest = nums[0];
    for (int i = 0; i < size; i++)
    {
        if (smallest > nums[i])
        {
            smallest = nums[i];
        }
    }
    return smallest;
}
float get_average(int nums[], int size)
{
    float sum = 0;
    float avg;
    for (int i = 0; i < size; i++)
    {
        sum += nums[i]; 
    }
    return sum/size;
}

void execute_lab8()
{
    cout << "\nThis is a program to caculate the highest value, smallest value and average value of the array of numbers entered (Please use -1 as a sentinal value\n\nEnter value: ";
    
    int nums[100];
    int x;
    int size = 0;
    for (int i = 0; cin >> x && x != -1; i++)
    {
        nums[i] = x;
        size++;
    }

    cout << "Highest value: " << get_highest(nums, size) << '\n';
    cout << "Smallest value: " << get_lowest(nums, size) << '\n';
    printf("Average: %0.2f\n", get_average(nums, size));
}