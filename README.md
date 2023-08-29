# Welcome to My Bsq
***

## Task
my_bsq is an algorithm project, the program will find the largest possible square on a board while avoiding obstacles. <br>

My task is to implement the algorithm and manage the maps imputed, the program takes a file containing the square map with the obstacles<br> 
and with the help of the algorithm finds the biggest square inside. At the end the result is printed to the user<br>

## Description
This project is divided in two major sections: <br>

'handle_map.c' handles the map inputed by the user, it opens and read the file and converts it into a string map, once the map is in a string we can obtain the size of the whole square,<br>
this allows me to convert this string into a 2D integer map based on 0s and 1s, the 0s represent the obstacles of the map while the 1s represent the free spaces. <br>

'my_bsq.c' implements the algorithm, it takes the 2D integer map and loops through it, finding where the largest possible square can be found, <br>
once we have this information the only thing left is printing the result to the user. The result map would be the initial string map but the largest square will be represented by 'x'.

## Installation
No intallation needed

## Usage
```
# Create desired map:
perl script.pl 'x' 'y' 'density' > map

    # Example map:
    5
    .....
    .o..o
    .....
    .o...
    o...o

# Run program:
./my_bsq map

    # Example result
    .....
    .oxxo
    ..xx.
    .o...
    o...o

```

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px'></span>
