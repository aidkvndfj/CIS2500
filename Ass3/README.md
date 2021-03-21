# CIS2500 Assignment 3
## Created By:
Eric Morse <br>
ID: 1141504 <br>
Last Edited: March 20, 2021

## How To Use
The first step is to make sure you are in the directory with main.c and other critical files, then run the command:

```make```

Once the make has finished, run the program with the command:

```.\tweetManager```

You can then use:

```make clean```

to clear out the .o files and the executable.

## Completed Components
All sections of the assignment where completed and implemented into the program. This includes
1. Create a new tweet <br>
Takes in a tweet list as a parameter. Prompts the user for a username and a tweet. The code will then automatically generate a unique id for the tweet. The function will then return the newly created tweet.
2. Display tweets <br>
Takes in a tweet list as a parameter. The program will make sure the list isn't empty, then will loop through the list and print the tweets in sequential order. It will print the ID, user, then tweet.
3. Search a tweet (by keyword) <br>
Takes in a tweet list as a parameter. The program will then prompt the user for a keyword, and will dynamically allocate the keyword, based on said user input. It will then loop through the tweet entire tweet list and print any tweets with the keyword. Will return weather or not it found a match.
4. Find how many words are "stop words" <br>
Takes in a tweet list as a parameter. The program will loop through the list of tweets, and the text for each tweet. For every "stop word" it finds, it will add 1 to a counter. At the end, it will print how many stop words it found.
5. Delete the nth tweet <br>
Takes in a tweet list as a parameter. The output the tweets in the system, and then prompt the user for a tweet number(not id) to delete. The systems will then delete the tweet. If the inputted number is not within the range, the program will ask for another number.
6. Save tweets to a file <br>
Takes in a tweet list as a parameter. The program will prompt the user for a file to save the tweets to. It will then loop through the list of tweets and save them all to the file specified by the user
7. Load tweets from a file <br>
Takes in a tweet list as a parameter. The program will prompt the user for a file to load tweets from. The program will then to go the end of the file loading tweets 1 at a time into the tweet list. The program will output onces it's finished.
8. Add node to list <br>
Takes in a tweet list and a node in as parameters. The program will then add the node to the end of the tweet list.

## Program Limitations
I was unable to determine how to remove the commas at the end of a tweets in the load tweets function. 

## Future Improvements
* Removing the commas at the end of a users tweet in load tweets.