// Name:MAFUZAL HOQUE
// Student Number:100908620
//SUMMER 2013 (I)
//ASSIGNMENT 5:QUESTION 2
//DATE OF SUBMISSION:11/6/2013


#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

bool isInt (double value) {
	double dummy;
	return bool(modf(value, &dummy) == 0);
}

double sqr(double value) { 
	return value * value; 
}
//"PLEASE HAVE PATIENT WITH MY CODES BECAUSE IT WORKS EVENTHOUGH IT IS LONG"
// picks a random number between 0 and "max" inclusive. values
// returned are uniformly distributed (each possible value
// is equally likely).
int pickRandomIntValue (int max) {

	// a key point - the 1.0 is a double constant.  this means
	// that "RAND_MAX + 1.0" is double and so on.
	return (int) ((rand() / (RAND_MAX + 1.0)) * (max + 1));

}


// puts between 10 and 20 (inclusive) chips on each of the three piles
void makeInitialPiles (int &pile1, int &pile2, int &pile3) 
{

	pile1 = 10 + pickRandomIntValue(10);
	pile2 = 10 + pickRandomIntValue(10);
	pile3 = 10 + pickRandomIntValue(10);

}


// displays instructions for playing the game of Nim
void displayInstructions ()
{

	cout << "\nThe game of Nim involves two players and three piles of chips.\n"
		<< "The players move alternately.  Each player, in his or her turn,\n"
		<< "removes one or more chips from one of the piles.  The player who\n"
		<< "removes the last chip wins the game.\n";

}


// four functions are added here

////////////////////////////////////////////////////////////////////////////////
//this function always diplays the chips in piles remaining after removal operations
void displayPiles(int pile1,int pile2,int pile3)
{
	cout<<"Pile 1:"<<pile1<< "  Pile 2:"<<pile2<< "  Pile 3: "<<pile3<<endl;
}


////////////////////////////////////////////////////////////////////////////////
//intellegent selctMove done only when at least two piles are zero 
//removes all  remaining chips if they are all in the same pile
//since the values are changed and these values are to be output 
//call by reference is used
void selectComputerMove (int& pile1, int &pile2, int& pile3, int pileChosen, int chipsRemoved)
{
	if(pileChosen==pile1)
	{
		pile1=pile1-chipsRemoved;
	}
	else
		if(pileChosen==pile2)
		{
			pile2=pile2-chipsRemoved;
		}
		else
			if(pileChosen==pile3)
			{
				pile3=pile3-chipsRemoved;
			}
}


////////////////////////////////////////////////////////////////////////////////
//Opeartion removal of chips is done here
//this func was called in func playGame
//all these if and else statements are designed to choose the exact pile carefully
//since the values are changed and these values are to be output 
//call by reference is used
void makeMove (int& pile1, int &pile2, int& pile3, int pileChosen, int chipsRemoved)
{
	if(pileChosen==pile1)
	{
		pile1=pile1-chipsRemoved;
	}
	else
		if(pileChosen==pile2)
		{
			pile2=pile2-chipsRemoved;
		}
		else
			if(pileChosen==pile3)
			{
				pile3=pile3-chipsRemoved;
			}
}
////////////////////////////////////////////////////////////////////////////////
//this func is important to check invalid inputs in all cases
//and output error messages
//names are abbreviated into small forms to make it easier
bool getHumanMove (int pile1, int pile2, int pile3, int pileChosen, int chipsRemoved)
{   
	int pc=pileChosen,cr=chipsRemoved,p1=pile1,p2=pile2,p3=pile3;
	if(!(pileChosen>0&&pileChosen<=3) )//checks pileChosen is wrong
		//or not from the user
	{
		cout<<"****Invalid pile number or number of chips.****"<<endl;
		return true;
	}
	else 
		if(pc==1 &&(cr<=0 ||cr>p1))//checks if the ChipsRemoved from pile 1 input from 
			//user is wrong or not
		{
			cout<<"****Invalid pile number or number of chips.****"<<endl;
			return true;
		}
		else 
			if(pc==2 &&(cr<=0 ||cr>p2))//checks if the ChipsRemoved from pile 2  input from 
				//user is wrong or not
			{
				cout<<"****Invalid pile number or number of chips.****"<<endl;
				return true;
			}
			else 
				if(pc==3 &&(cr<=0 ||cr>p3))//checks if the ChipsRemoved from pile 3 input from 
					//user is wrong or not
				{
					cout<<"****Invalid pile number or number of chips.****"<<endl;
					return true;
				}
				else
				{
					return false;
				}

}
////////////////////////////////////////////////////////////////////////////////

void playGame (bool computerToMove, int pile1, int pile2, int pile3) 
{

	int pileChosen, chipsRemoved,num,clone,storeChipsRemoved;

	// display the initial situation
	cout << "\nInitial Situation:\n";
	displayPiles (pile1, pile2, pile3);//outputs first Piles information abt chips

	for (;;)
	{

		if (computerToMove)
		{
			//the following statements are designed to inititae selectComputerMove
			//function in order to remove all chips from same pile
			//till the "next long stripe on line 198 "			
			if(pile1>0 && pile2==0 && pile3==0)
			{
				pileChosen=pile1;
				chipsRemoved=pile1;
				clone=1;
				selectComputerMove (pile1, pile2, pile3, pileChosen, chipsRemoved);
			}
			else
				if(pile1==0 && pile2>0 && pile3==0)
				{
					pileChosen=pile2;
					chipsRemoved=pile2;
					clone=2;
					selectComputerMove (pile1, pile2, pile3, pileChosen, chipsRemoved);
				}
				else
					if(pile1==0 && pile2==0 && pile3>0)
					{
						pileChosen=pile3;
						chipsRemoved=pile3;
						clone=3;
						selectComputerMove (pile1, pile2, pile3, pileChosen, chipsRemoved);
					}
					/////////////////////////////////////////////////////////// line 198
					else 
					{


						if(pile1>0&&pile2>0&&pile3>0)//when chips in all piles are greater than 0
						{
							num=rand()%3+1;//by this way i'll only have either 1,2,3 randomly only
							if(num==1)
							{
								pileChosen=pile1;
								clone=1;
							}
							else 
								if(num==2)
								{
									pileChosen=pile2;
									clone=2;
								}
								else
									if(num==3)
									{
										pileChosen=pile3;
										clone=3;
									}


									for(;;)
									{


										chipsRemoved=rand()%20+1;//randomly select number of chips to be removed

										if( chipsRemoved<=pile1 &&chipsRemoved<=pile2 &&chipsRemoved<=pile3)
											//however random chips has to be less than initial chosen chips by rand function
										{
											break;
										}

									}
						}
						else
							if(pile1==0&&pile2>0&&pile3>0)//when chips in pile1 is zero and others are not
							{
								num=rand()%2+1;//only 2 or 3 will be chosen randomly

								//the following if statements will carefully selct piles 2,3 and ignore pile 1 because it has zero chips
								if(num==1)
								{
									pileChosen=pile2;
									clone=2;
								}
								else 
									if(num==2)
									{
										pileChosen=pile3;
										clone=3;
									}

									for(;;)
									{


										chipsRemoved=rand()%20+1;//a number is randomly choosen from 1 to 20

										if(chipsRemoved<=pile2 &&chipsRemoved<=pile3)
											//however chips chosen randomly has to be less than pile2 and pile3
										{
											break;
										}

									}
							}
							else
								if(pile1>0&&pile2==0&&pile3>0)//only pile 1 and pile 3 has chips greater than 0 and pile 2 is zero
								{
									num=rand()%2+1;//only 1 or 3 will be chosen randomly
									//the following if statements will carefully selct piles1,3  and ignore pile 2 because it has zero chips
									if(num==1)
									{
										pileChosen=pile1;
										clone=1;
									}
									else 
										if(num==2)
										{
											pileChosen=pile3;
											clone=3;
										}
										for(;;)
										{


											chipsRemoved=rand()%20+1;//a number is randomly choosen from 1 to 20

											if(chipsRemoved<=pile1&&chipsRemoved<=pile3)
												//however chips chosen randomly has to be less than pile1 and pile3
											{
												break;
											}

										}
								}
								else
									if(pile1>0&&pile2>0&&pile3==0)//only pile 1 and pile 2 has chips greater than 0 and pile 3 is zero
									{
										num=rand()%2+1;//only 1 or 2 will be chosen randomly
										if(num==1)
										{
											pileChosen=pile1;
											clone=1;
										}
										else 
											if(num==2)
											{
												pileChosen=pile2;
												clone=2;
											}
											for(;;)
											{


												chipsRemoved=rand()%20+1;//a number is randomly choosen from 1 to 20

												if(chipsRemoved<=pile1&&chipsRemoved<=pile2)
													//however chips chosen randomly has to be less than pile1 and pile2
												{
													break;
												}

											}
									}


									//calls function to do the opeartion that will remove chips from a particular pile
									makeMove (pile1, pile2, pile3, pileChosen, chipsRemoved);

					}





					cout << "The computer has removed " << chipsRemoved
						<< " chips from pile " << clone << ":\n";


					if ((pile1 + pile2 + pile3) == 0) 
					{
						cout << "The Computer has won!\n";
						return;
					}

		}
		else 
		{ // human to move

			//invalid values are checked here
			do
			{

				cout<<"Please enter the pile number and chips to remove :";
				cin>>pileChosen>>chipsRemoved;

			}
			while(getHumanMove (pile1, pile2, pile3, pileChosen, chipsRemoved));
			//skips when valid values are input

			//this following part takes care of the pile that "user" have input
			if(pileChosen==1)
			{
				pileChosen=pile1;
			}
			else 
				if(pileChosen==2)
				{
					pileChosen=pile2;

				}
				else
					if(pileChosen==3)
					{
						pileChosen=pile3;
					}
					//calls in makeMove function 
					//it takes in chipsRemoved and pileChosen from user and then does the 
					//Opeartion removal of chips 
					makeMove (pile1, pile2, pile3, pileChosen, chipsRemoved);
					if ((pile1 + pile2 + pile3) == 0) 
					{
						cout << "Congratulations - you have won!\n";
						return;
					}

		}

		// display the new number of chips in piles after user has entered his chioce 
		displayPiles (pile1, pile2, pile3);

		computerToMove = !computerToMove; // it's now the other player's turn

	}
}




int main () 
{

	char option;
	int pile1, pile2, pile3;

	srand (time(NULL));

	for (;;) 
	{

		// prompt user for and read option
		cout << "\nPlease enter option.\n"
			<< "  I = display instructions\n"
			<< "  C = play game (computer to move first)\n"
			<< "  H = play game (human to move first)\n"
			<< "  Q = quit program\n"
			<< "Option: ";
		cin >> option;
		cin.ignore (1000, '\n'); // get rid of the rest of the input line

		option = toupper(option); // convert option to uppercase

		if (option ==  'I') 
		{

			displayInstructions ();

		} 
		else
			if (option == 'C') 
			{

				makeInitialPiles (pile1, pile2, pile3);
				playGame (true, pile1, pile2, pile3);

			} 
			else 
				if (option == 'H') 
				{

					makeInitialPiles (pile1, pile2, pile3);
					playGame (false, pile1, pile2, pile3);

				} 
				else 
					if (option == 'Q')
					{

						// time to quit
						system ("PAUSE"); return 0;

					} 
					else 
					{

						cout << "\nIllegal option ignored.\n";

					}

	}// end for (;;)
	system("PAUSE");
	return 0;

}
