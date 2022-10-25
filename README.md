# Hangman
 This C program randomly chooses a film name that consists of letters and whitespace only from movie-list.txt. 
The name is presented to the player with some non-whitespace characters
missing; blanks are inserted to mark word boundaries as usual. The goal of the player is to guess the
name of the film. 
In each try, the player may guess a single character. If the character appears in
the film name, all its occurrences have to be filled in by the program; otherwise, the player loses a
“life”. 
The player may also guess the full name of the film. If the guess is wrong, the player also loses
a life. 
A player starts out with 10 lives. If the player does guess the name correctly before running
out of lives, the total number of tries required becomes her score.

This program will mark the missing letters using the underscore (_). A few of the letters will
be filled in initially as hints; as above, if any of the filled in characters appears in the film name
multiple times, all its occurrences have to be filled in initially. On average, at least one character in
five (rounded up) will be filled in initially.
Also the number of remaining lives will be displayed to the right of the film name. 
Note : uppercase and lowercase letters are not distinguished.
