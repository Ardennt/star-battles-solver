HOMEWORK 6: STAR BATTLE


NAME:  < Jiawei Wu >



COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

< insert collaborators / resources >
TA Ryan during Lab Hours
https://www.geeksforgeeks.org/backtracking-introduction/#:~:text=Backtracking%20is%20an%20algorithmic%2Dtechnique,reaching%20any%20level%20of%20the
^^ Used to learn how backtracking works

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.



ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < 40 >



ANALYSIS OF PERFORMANCE OF YOUR ALGORITHM:
(running time order notation & concise paragraph, < 200 words)

The dimensions of the board (w and h)
The number of zones (z)? 
The average number of squares in a zone (t) 
The number of stars per zone(s)?
etc.
Number of stars currently (n)

    O(z^t^n^nw)

    O(z) are the recursive calls. For each recursive call the algorithm loops
    through all the coordinates O(t). For each coordinate the algorithm tries to place
    the star and call all_valid O(n). all_valid loops through all the current stars and calls
    place. place function places the stars. Placing the stars loops through O(wh) as it makes
    the columns += 1 and the rows += 1 as well (to see how many stars there are). This function
    returns true or false, depending if ALL the stars are valid or not.
    
    My algorithm is computationally expensive, especially all_valid, which places all the stars
    in a board and returns false only when it is attempting to place a star at -1 or if
    the number of stars in that row is greater than the total number of stars allowed.
    There is definitely a better way to do this, one such being utilizing a distance
    formula which I could make a function for that takes 2 coords and compare their distance.
    If their distance is = 1, then return false because they are too close.



DESCRIPTION OF YOUR ADDTIONAL PUZZLES:
Briefly explain the design of the puzzles or dictionaries and what
makes them "interesting" test cases (or why they aren't interesting).
    My additional test case is interesting because all zones are 4 8 
    and a large area in the bottom. The board is created to test
    what will happen if there a huge chunk of space in the bottom
    with many zones on top. It handles the case well.

SUMMARY OF PERFORMANCE OF YOUR PROGRAM ON THE PROVIDED PUZZLES AND 
ON YOUR ADDITIONAL PUZZLES:
# of solutions & approximate wall clock running time for different
puzzles / stars per zone for a single solution or all solutions. Be
specific about which puzzle/parameters you were timing.

    sporcle1.txt - instant
    custom1.txt - instant
    custom2.txt - instant
    custom3.txt - instant
    mypuzzle.txt - instant
    twonot1.txt - 2 seconds
    twonot2.txt - 40 minutes +


MISC. COMMENTS TO GRADER:  
(optional, please be concise!)

