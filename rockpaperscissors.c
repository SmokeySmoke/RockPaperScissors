/* rockpaperscissors.c -- a classic game of rock, paper, scissors
 */

#include <stdio.h>
#include <stdlib.h>	// for rand() and srand()
#include <ctype.h>	// for islower() and toupper()

int main(void)
{
	char ch;					// first character from user input
	char  * RPS[3] = {"Rock", "Paper", "Scissors"};	// strings for each choice
	short user_choice, npc_choice;			// user and npc choice indexes
	unsigned int userpts, npcpts;			// user and npc accumulated points
	userpts = npcpts = 0;							// initialize to 0

	puts("ROCK PAPER SCISSORS\n");
	do
	{
		puts("Rock, Paper, or Scissors? (q to quit):");
		ch = getchar();			// prompt user to choose
		while (getchar() != '\n')	// flush input buffer
			continue;
		if (islower(ch))		// if users first character is lowercase,
			ch = toupper(ch);	// 				make it uppercase

		switch (ch)			// set user choice index
		{
			case 'R' : user_choice = 0;	
				   break;
			case 'P' : user_choice = 1;
				   break;
			case 'S' : user_choice = 2;
				   break;
			case 'Q' : continue;
			default  : puts("Incorrect input! Try again.\n");// first user input character was invalid
				   continue;
		}
		printf("\nYou chose %s!\n", RPS[user_choice]);	// declare users choice

		srand(rand());					// randomize rand() seed
		npc_choice = rand() % 3;			// npc choose number between 0 and 2
		printf("NPC chose %s!\n\n", RPS[npc_choice]);	// declare npc choice

		if (user_choice == npc_choice)				// if players tie, award no points
			puts("Tie!");

		else if (user_choice == 0 && npc_choice == 1 ||
				user_choice == 1 && npc_choice == 2 ||
				user_choice == 2 && npc_choice == 0)	// if npc wins, award point to npc
		{
			puts("NPC WINS THIS ROUND!");
			npcpts++;
		}
		else if (user_choice == 1 && npc_choice == 0 ||
				user_choice == 2 && npc_choice == 1 ||
				user_choice == 0 && npc_choice == 2)	// if user wins, award point to user
		{
			puts("YOU WIN THIS ROUND!");
			userpts++;
		}
		else							 // error with player choices (impossible?)
			puts("Program error! user and/or NPC choices != 0, 1, or 2!");
		putchar('\n');
	} while (ch != 'Q');	// test condition should always be true unless something weird happens

	printf("\nYou won %u rounds!\n"
		 "NPC won %u rounds!\n",
				 userpts, npcpts);	// declare user and npc points
	if (npcpts == userpts)
		puts("It's a tie!");	
	else if (npcpts > userpts)
		puts("NPC WINS!");			// declare winner
	else if (npcpts < userpts)
		puts("YOU WIN!");
	

	puts("\nGood game!");	// good sportsmanship

	return 0;
}
