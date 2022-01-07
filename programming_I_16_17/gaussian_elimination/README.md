# Gaussian Elimination

### DESCRIPTION:

*In linear algebra, Gaussian elimination is an algorithm for solving systems of
linear equations.*
*It is usually understood as a sequence of operations performed on the
corresponding matrix of coefficients. This method can also be used to find
the rank of a matrix, to calculate the determinant of a matrix, and to calculate
the inverse of an invertible square matrix.*
*To perform row reduction on a matrix, one uses a sequence of elementary row
operations to modify the matrix until the lower left-hand corner of the matrix
is filled with zeros, as much as possible.*
*There are three types of elementary row operations:*

*1) Swapping two rows;*

*2) Multiplying a row by a non-zero number;*

*3) Adding a multiple of one row to another row;*

*Using these operations, a matrix can always be transformed into an upper
triangular matrix.*


### REQUIREMENTS:

1) gcc;
2) make;


### INPUT:

This program reads a **matrix** given in input from a file.
The input file **must** be something like this:

>X1 X2 X3

>X4 X5 X6

To avoid errors, it's important to start writing the matrix from the beginning
of the file.
The value are divided by `one space`.
The rows are composed with one `newline`.


### OUTPUT:

The output is a file that contains the initial matrix, step by step all the
eliminations, and finally the system solutions.


### COMPILING:

To build the program, use:
>*$ **make** (or $ make all)*

To run the program, use:
>*$ **make** run <input_file> <output_file>*

To remove the generated executable file use:
>*$ **make** clean*

### SAMPLE INPUT/OUTPUT:


For any example look at ***"test"*** folder (still to be finished).


### Copy
Author: Luigi Capogrosso 
August, 2017
