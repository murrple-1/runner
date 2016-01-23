Runner
======
Created by Murray Christopherson  
Updated April 2010

About the Program
-----------------
This program was one of my first full programs written in C++, and so was
an experiment into the language. The program has gone through a couple
iterations, initially being a purely random race-simulator, generating race
times for various runners. However, I rewrote it to be more useful, in that
it generates the outcome based on race odds, as seen at horse races, using a
slightly novel algorithm. The focus on this project was using the standard C++
library, and focusing on the MVC design, at a simple level.  
It is recommended you read the source code to see exactly what the code is
doing.  
Please visit my portfolio at http://murraychristopherson.com

If you discover any bugs or unclear/inconsistent documentation, please contact me
at murraychristopherson@gmail.com with a description of what happened, and I
will try and have a fixed version up shortly.

Installation
------------
If you have the program 'make' installed on your computer, the executable is
easily creatable by running 'make' on the containing directory.

EXAMPLE:
```
$> make
```
To uninstall the file, the executable is easily removed with the 'make clean'
command.

EXAMPLE:
```
$> make clean
```
I recommend you open the 'makefile' for further macros to change (in particular,
if you don't use 'g++' as your C++ compiler)

Running the Program
-------------------
When the program starts, it opens a standard numbered menu. One uses the number
keys to navigate this menu. Start by adding a runner to the queue. Each runner
has the traits of a name and bib number (which are purely superficial), and a
relative odd's weighting. The odd's weighting can be any positive number,
but it is easiest to think of it as a percentage (ie, 4 runners might have odd's
weightings of 2, 4, 3, 1, as per 20%, 40%, 30% and 10% probability respectively).
After you add a couple runners, you can race them, which will output the race
results. Runners with higher weights tend to win or have high positions more often,
and vice versa, naturally. When the results are output, the runner on the highest 
line is the winner.  
To restart, you may empty the list. To see the list currently, you may print the list.
