/* Name: Gavin McDavitt
Date: 11/6/2022 Section: TLH MAIN CAMPUS Online
Assignment: Module 8: Starbucks - Coffee Customer Rating Program part 2
Due Date: 11/6/2022
About this project: This project allows a user to use an int array to display a few different options.
 One of the first options is to display the array as is. A second option allows the user to change a rating.
 The third option allows for the user to see the average among the entire ratings. The fourth option is used
 to find the lowest rated option. The fifth option allows the user to see the array list in ascending order.
 The sixth option allows the user to see array in descending order. The seventh option allows the user to
 enter a new number. The last option quits the program and the while loop is then broken.
Assumptions: Assumes correct user input, meaning that only numbers will be allowed to be entered in.
 Anything else can and will break the program.
 All work below was performed by Gavin McDavitt */
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void displayRatings(const int *productRatings,int numCustomers);
void displayAverageRating(const int *productRatings, int numCustomers);
int getValidRating();
int getValidCustomer(int numCustomers);
int menuOption();
void ChangeARating(int *productRatings,int numCustomers);
void displayLowestRatings(const int *productRatings,int numCustomers);
void displaySortedRatingsAsc(int *productRatings, int numCustomers);
void displaySortedRatingsDesc(int *productRatings, int numCustomers);
int * AddAnotherRating(const int *productRatings,int & numCustomers);

/*This function is to get a number for which option the user wants. I simply prompt
 * the user for a number by showing him the different menu options. If the user
 * selects a number too large or small then it will be asked again for a valid number.
 * This is my own function that I created to make the code much more recyclable.
 * This way in future cases if I would like to create more options than I can simply
 * add more to this one function instead of multiple places.
 */

    int menuOption()
    {
        cout<<endl;
        cout << "1) Display number of the ratings per option" << endl;
        cout << "2) Change a rating" << endl;
        cout << "3) Display the Average Rating" << endl;
        cout << "4) Find the Lowest Rating" << endl;
        cout << "5) Display Sorted Ratings Asc"<<endl;
        cout << "6) Display sorted Rating Desc"<<endl;
        cout <<"7) Add Another Rating"<<endl;
        cout<<"8) Quit"<<endl;
        cout << "select an option (1..8)..";
        int userInput;
        cin >> userInput;
        while(userInput>=9 || userInput<=0)
        {
            cout<< "select an option (1..8)..";
            cin >> userInput;
        }//end of while loop
        return userInput;
    }//end of menuOption()

    /*This function is used to display all the contents of the array.
     * It is a void function, it returns nothing and just prints
     * entire contents of the array. It also counts what rating it was
     * given and displays each ranking total votes. It runs a for loop
     * to display each rating with a width of 5 between them. It then takes
     * an if statement to only display ten array items at a time.
     * The count by ratings has a width of 20 between them and
     * displays how many times each ranking has been counted.
     */
    void displayRatings(const int *productRatings, int numCustomers)
    {
        cout<< "Display Ratings" <<endl;
        for (int index=0; index < numCustomers; index++)
        {
            cout <<setw(5)<<*(productRatings+ index) << setw(5);
            if ((index % 10) == 9)
            {
                cout<< endl;
            }

        }//end of for loop

        cout<<endl;
        int num1 = 0;
        int num2 = 0;
        int num3 = 0;
        int num4 = 0;
        int num5 = 0;
        for (int i=0; i<numCustomers; i++)
        {

            if (*(productRatings + i) == 1)
            {
                num1++;
            }
            if (*(productRatings+i) == 2)
            {
                num2++;
            }
            if (*(productRatings +i) == 3)
            {
                num3++;
            }
            if ( *(productRatings+i) == 4)
            {
                num4++;
            }
            if (* (productRatings+i) == 5)
            {
                num5++;
            }
        }//end of for loop
        cout<<"Count by Rating"<<endl;
        cout<<"1" <<setw(20) << num1<<endl;
        cout<<"2" <<setw(20) << num2<<endl;
        cout<<"3" <<setw(20) << num3<<endl;
        cout<<"4" <<setw(20) << num4<<endl;
        cout<<"5" <<setw(20) << num5<<endl;
    }//end of display ratings

    /*This function that displays the average rating. I initialize
     * sum and average to zero. I then use a for loop to add each
     * element into an array. After I simply divide
     * sum/NUM_CUSTOMERS = average. I then display average in the format
     * as shown  in our example with only three numbers.
     *
     */

    void displayAverageRating( const int *productRatings, int numCustomers)
    {
        double sum=0;
        double average=0;
        for(int index=0; index < numCustomers; index++)
        {
            sum+= *(productRatings+ index);
            average=sum/numCustomers;
        }//end of for loop
        cout<< "The average of rating is " << setprecision(3)<<average <<endl;
    }//end of display average Ratings

    /*This function allows a user to enter a valid customer and if the user doesn't
    *Then they are prompted again for a correct user. This is a simple valid loop.
    */
    int getValidCustomer(int numCustomers)
    {
        int customerSel;
        cout << "Please enter in the number of the customer" <<endl;
        cin>>customerSel;
        while(customerSel>=numCustomers+1 || customerSel <=0)
        {
            cout << "Please enter in a valid customer number  ..." <<endl;
            cin>>customerSel;
        }
        return customerSel;
    }//end of getValidCustomer
    /*
     * This is a simple valid loop so a user may enter the correct rating. If a
     * user enters a number less than 1 or higher than 5 they will be prompted again.
     */
    int getValidRating()
    {
        int validRate;
        cout<<"Please enter in the rating (1-5)..."<<endl;
        cin >>validRate;
        while(validRate<=0 || validRate>=6)
        {
            cout << "Please enter in a valid rating (1-5) ..."<<endl;
            cin >> validRate;
        }
        return validRate;
    }//end of getValidRate
    /*
     * In this function I declare two ints named customer and rating.
     * Then those variables call two functions. The customer variable calls
     * getValidCustomer() and rating calls GetValidRating(). Then *(productRatings +customer-1)
     * is assigned to the integer rating. You must do one less to not mix computer language
     * with human language for the arrays. Then I initialize the chosen element in the array to be rating.
     */

    void ChangeARating(int *productRatings, int numCustomers)
    {
        int customer;
        int rating;
        customer = getValidCustomer(numCustomers);
        rating = getValidRating();
        *(productRatings +customer-1) = rating;
    }//END OF ChangeARating

    /*
     *This is my displayLowestRating function. I initialize min to be the first element in the array.
     *I then run a for loop to compare min to the second element. If *(productRatings+2) is smaller than
     * min will be assigned the second element. If not it loops through the array until an element in
     * the array is smaller than min. Lastly it prints to screen, the lowest rating in the array.
     */
    void displayLowestRatings(const int *productRatings, int numCustomers)
    {
        int min = productRatings[0];
        for(int i =1;i < numCustomers; i++)
        {
            if(min > *(productRatings+i))
            {
                min=*(productRatings+i);
            }
        }
        cout<<"The Lowest rating is "<<min <<endl;

    }
    /*
     * This is a bubble sort function. It takes two for loops to access and compare the array.
     * Before any loop starts I declare int index for my inner for loop. A for loop will then
     * loop through to access each element in the array. I initialize an int named swap that
     * is equal to zero. I then compare each element in my inner for loop. If *(productRankings +5)
     * is bigger than *(productRankings+6) then the two items are swapped. You need to use a temporary
     * int to swap the two elements. I then include that 'swapped=1' this allows the computer to
     * continue the loop and be optimally faster. Then *(productRankings+6) will compare to *(productRankings+7).
     * Inside the inner for loop, it runs until NUM_CUSTOMERS-i-1. The inclusion of subtracting i allows
     * for the loop to run faster as any checks that are already completed will be correct. It simplifies
     * the loops to not have to compare items that are already swapped. Lastly, displayRatings() will be
     * called so the user can see the ratings in asc order.
     */
    void displaySortedRatingsAsc(int *productRatings, int numCustomers)
    {
        int index;
        for(int i=0; i<numCustomers-1;++i)
        {
            int swapped=0;
            for(index=0; index < (numCustomers-i-1); ++index)
            {

                if( *(productRatings +index) > *(productRatings +index+1))
                {
                    int temp = *(productRatings +index);
                    *(productRatings +index) = *(productRatings +index+1);
                    *(productRatings +index+1)=temp;
                    swapped =1;
                }
            }
            if(swapped==0)
            {
                break;
            }
        }
        displayRatings(productRatings, numCustomers);
    }
    /*
     * This is a Selection sort. This uses two for loops as well. I declare two integer elements that
     * will be equal to the index and value of the upper for loop iteration (whatever number i is). It then
     * runs to the bottom for loop and will be used to compare *(productRankings+ index) to maxValue. if the
     * *(productRankings+ 5) is larger than maxValue is assigned to *(productRankings+ 5). It then takes
     * swaps *(productRankings+ maxIndex) and *(productRankings+ i). It is important to understand that the top for
     * loop starts at 0. While the bottom for loop starts at 1. Because of this when maxValue is assigned to
     * *(productRankings+ index), the index of bottom for loop. It allows *(productRankings+ i) to be swapped with
     * *(productRankings+ maxIndex). I again will need a temporary integer to swap the two elements.
     */

    void displaySortedRatingsDesc(int *productRatings, int numCustomers)
    {
        int maxIndex;
        int maxValue;
        for(int i =0; i < (numCustomers -1); i++ )
        {
            maxIndex = i;
            maxValue = *(productRatings+i);
            for(int index = i +1; index< numCustomers; index++)
            {
                if (*(productRatings + index) >maxValue)
                {
                    maxValue = *(productRatings +index);
                    maxIndex = index;
                }
            }
            int temp = *(productRatings + maxIndex);
           *(productRatings+maxIndex) = *(productRatings+i);
            *(productRatings+i)=temp;
        }
        displayRatings(productRatings, numCustomers);
    }
    /*
     * This function AddAnotherRating() takes two addresses as an argument.
     * The first is a constant integer that points to productRankings. The second
     * is the address to &numCustomers. I initialize my variable
     * newRating to the function getValidRating(). By doing this I save code,
     * and it will go through a validation loop. I then initialize a pointer to
     * a dynamic array the size of numCustomers+1 for my new rating. I then run
     * a for loop, that assigns the *(productRatings + index) to *(ptr +index).
     * I then have *(ptr + numCustomers) to be equal to newRating. I increase
     * NumCustomers one, so that it will have enough space for my functions.
     * I delete my productRanking[] and return ptr.
     */
    int * AddAnotherRating(const int *productRatings,int& numCustomers)
    {
        int newRating = getValidRating();
        int * ptr = new int [numCustomers+1];
        for(int index =0; index<numCustomers;index++)
        {
            *(ptr +index) = *(productRatings + index);
        }
        *(ptr + numCustomers)=newRating;
        numCustomers++;
        delete [] productRatings;
        return ptr;


    }//end of Add Another Rating

    /*
    This is the main function, I use a while loop to consistently prompt
    * the user for a menu option. I use a constant equal to 1 to have a continuous
    * loop until option 8 is selected. I call the function menuOption(), to display
    * the different menu options given. I then prompt the user for a response.
    */
    int main()
    {
        const int VALID =1;
        int numCustomers=113;
        int *productRatings= new int [numCustomers]{
                4, 4, 4, 2, 3, 4, 5, 4, 5, 4,
                4, 3, 4, 4, 5, 4, 4, 4, 4, 3,
                2, 5, 5, 5, 4, 4, 4, 5, 4, 5,
                3, 4, 2, 3, 3, 4, 3, 5, 4, 3,
                5, 5, 4, 5, 3, 3, 3, 4, 3, 5,
                3, 4, 4, 5, 5, 3, 4, 2, 5, 3,
                4, 3, 4, 4, 2, 3, 4, 5, 4, 3,
                3, 3, 4, 4, 2, 2, 3, 5, 4, 4,
                4, 4, 3, 4, 5, 4, 4, 5, 3, 3,
                3, 3, 4, 4, 3, 3, 4, 4, 4, 4,
                3, 3, 4, 5, 3, 2, 5, 4, 3, 5,
                3, 4, 1};
        while(VALID <2)
        {
            int option;
            option = menuOption();
            //If the user selects 1 then displayRatings() will be called.
            if (option == 1)
            {
                displayRatings(productRatings, numCustomers);
            }
            //If the user selects option 2 then ChangeARating() will be called.
            if(option==2)
            {
                ChangeARating(productRatings,numCustomers);
            }
            //If the user selects option 3 then displayAverageRating() will be called.
            if (option == 3)
            {
                displayAverageRating(productRatings, numCustomers);
            }
            //If the user selects option 4 then displayLowestRatings() will be called.
            if(option==4)
            {
                displayLowestRatings(productRatings, numCustomers);
            }
            //If the user selects option 5 then displaySortedRatingsAsc() will be called.
            if(option==5)
            {
                displaySortedRatingsAsc(productRatings, numCustomers);
            }
            //If the user selects option 6 then displaySortedRatingsDesc() will be called.
            if (option ==6)
            {
                displaySortedRatingsDesc(productRatings, numCustomers);
            }
            //If the user selects option 7 then AddAnotherRating() will be called.
            if (option ==7)
            {
                productRatings = AddAnotherRating(productRatings,numCustomers);
            }
            //if the user selects option 8 then the valid loop breaks and the program ends.
            if(option==8)
            {
                break;
            }
        }
        return 0;
    }
