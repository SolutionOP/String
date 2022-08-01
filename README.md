# s21_string+

## Part 1. Implementation of the string.h library functions

It is necessary to implement the described [above](#stringh-functions) functions of the string.h library: 
 - The library must be developed in C language of C11 standard using gcc compiler
 - The library's code, makefile and library itself must be located in the src folder on the develop branch    
 - Do not use outdated and legacy language constructions and library functions. Pay attention to the legacy and obsolete marks in the official documentation on the language and the libraries used. Use the POSIX.1-2017 standard. 
 - Make it as a static library (with the header file s21_string.h)
 - The library must be developed in accordance with the principles of structured programming, duplication in the code must be avoided
 - Prepare a full coverage of the library's functions by unit-tests using the Check library
 - Test's code and the executable file must be located in the src folder or its any subfolder
 - Unit-tests must check the results of your implementation by comparing them with the implementation of the standard string.h library
 - Unit tests must cover at least 80% of each function (checked using gcov)
 - Provide a Makefile for building the library and tests (with the targets all, clean, test, s21_string.a, gcov_report)
 - The gcov_report target should generate a gcov report in the form of an html page. Unit tests must be run with gcov flags to do this
 - Use prefix s21_ before each function
 - It is forbidden to copy the implementation of the standard string.h library and other string processing libraries and to use them anywhere, except unit-tests
 - It is forbidden to use system errors arrays, including those not specified in POSIX (sys_nerr, sys_errlist). Instead, you need to implement your own platform-specific errors arrays, as it was mentioned in the description of the [strerror function](#stringh-functions)  
 - You must follow the logic of the standard string.h library (in terms of checks, working with memory and behavior in emergency situations - tests will help you with that)
 - Functions must work with z-string made of single-byte characters in ASCII encoding.

## Part 2. Partial implementation of the sprintf function

It is necessary to implement the sprintf function from the stdio.h library:
- The function must be placed in the s21_string.h library
- All of the requirements outlined in [the first part](#part-1-implementation-of-the-stringh-library-functions) are applied to function implementation.
- The next partial formatting must be supported:
  - Specifiers: c, d, i, f, s, u, %
  - Flags: -, +, (space)
  - Width description: (number)
  - Precision description: .(number)
  - Length description: h, l

## Part 3. Bonus. Implementation of some format modifiers of the sprintf function

Bonus assignment for extra points. It is necessary to implement some format modifiers of the sprintf function from the stdio.h library:
- The function must be placed in the s21_string.h library
- All of the requirements outlined in [the first part](#part-1-implementation-of-the-stringh-library-functions) are applied to function implementation.
- The next additional format modifiers must be supported:
  - Specifiers: g, G, e, E, x, X, o, n, p
  - Flags: #, 0
  - Width description: *
  - Precision description: .*
  - Length description: L

## Part 4. Bonus. Implementation of the sscanf function

Bonus assignment for extra points. It is necessary to implement the sscanf function from the stdio.h library:
- The function must be placed in the s21_string.h library
- All of the requirements outlined in [the first part](#part-1-implementation-of-the-stringh-library-functions) are applied to function implementation.
- Full formatting (including flags, widths, precision, modifiers and conversion types) must be supported.


## Part 5. Bonus. Implementation of special string processing functions

Bonus assignment for extra points. You must implement some string processing functions from the String class (described [here](#special-string-processing-functions-from-the-string-class-in-c)):
- The functions must be placed in the s21_string.h library.
- All of the requirements outlined in [the first part](#part-1-implementation-of-the-stringh-library-functions) are applied to functions implementation, 
  excluding the requirement to compare your implementation with the standard.
