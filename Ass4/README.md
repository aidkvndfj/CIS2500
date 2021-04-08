# CIS2500 Assignment 4
## Created By:
Eric Morse <br>
ID: 1141504 <br>
Last Edited: April 7, 2021

## How To Use
The first step is to make sure you are in the directory with testA4.c and other critical files, then run the command:

```make```

Once the make has finished, run the program with the command:

```.\testA4```

You can then use:

```make clean```

to clear out the .o files and the executable.

## Completed Components
All sections of the assignment where completed and implemented into the program. This includes
### Queue Functions
1. enqueue <br>
Takes in a head, tail, and node. Will add the node to the tail of the queue. If the queue is empty, will set head and tail to new node.
2. dequeue <br>
Takes in a head, and tail. Will remove the node in the head. If the queue becomes empty, sets both head and tail to null.
3. isEmpty <br>
Takes in the head, if the head is null, return true. Otherwise return false.
4. printQueue <br>
Takes in the head, will go through the queue, and print each element.
### Misc. Functions
1. sortID <br>
Takes in the head, and tail. Will go through the queue and use bubble sort to sort the list in ascending order of tweet ID.
2. reverse <br>
Takes in the head, and tail. Will go through the queue and reverse it.
3. sortUsername <br>
Takes in the head, and tail. Will go through the queue and use bubble sort to sort the list in ascending order of username.
### Helper Functions
1. FreeQueue <br>
Takes in a head, and will go through the queue and free the nodes.
2. InsertAtBegining <br>
Takes in a head, and tail, and a new tweet. Will insert the tweet onto the head of the queue. If the queue is empty, will set the head and tail to the new node.
3. SwapTweets <br>
Takes in 2 tweets and swaps the contents of the tweets.

## Program Limitations
N/A

## Future Improvements
* Potentially swapping elements via memory, instead of swapping the contents.