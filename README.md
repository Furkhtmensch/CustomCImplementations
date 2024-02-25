# CustomCImplementations
Some custom C implementations which appeal more to my taste.



  CIOTools.h is a header composed of 3 functions, two of which serve as support for convertion from integer to string format and float/double to string format, the latter with as many decimal places as you wish (255 limit, close enough. Logically, you can change it in the CIOTools.h file).
print() is a function which is similar to python's print() (helpful for people who prefer python's simplicity and flexibility with the print() function), although it supports printf() %<char> (mostly the same, although customizable, I guess) way of working for every string passed to the function.
The only downside (yet) is having to pass either NULL or 0 as the final argument (will attempt to remove the need for it). It's necessary because I haven't found a way to check when the end of arguments is reached.


  The way you use it is simple: You pass a string, you may insert %, followed by a valid character, somewhere in it and then you must pass, as arguments, left-to-right order, the corresponding value so that the symbols are replaced. Then, in the end, you pass either NULL or 0 (as the very last argument). You may pass as many strings as you want (separated by commas, which means they are separate arguments!), as well as as many %<char> symbols as you want. Here is the list of currently implemented values:


%c     -> replace it with a character (single quotes :D)

%s     -> replace it with a string (double quotes :D)

%i     -> replace it with an integer (integers ONLY, no implicit conversions, sorry not sorry)

%d     -> works the same way as the previous one (%i)

%f     -> replace it with a floating point number (float and double, floats will always be implicitly converted to double, does not work with integers, sorry again)

%.f    -> works the same way as the previous one (%f)

%.xf   -> takes floats/doubles and prints with the first x decimal places

%.xxf  -> takes float/double and prints with the first xx decimal places

%.xxxf -> takes float/double and prints with the first xxx decimal places (change the limit of decimal places and you can use even more 'x' :D)



dprint() is a rather specific function. It takes as the first argument the number of following arguments. For example, dprint(3, 1, 2, 3); outputs:"1 2 3\n".


However, it also works for floats/doubles, all you have to do is pass a negative argument as the first argument, instead. Example: dprint(-3, 1.13, 2.2, 3.213); outputs:"1.13 2.20 3.21\n" (that is, disregarding the possible floating pointer imprecisions). As you have seen, it shows 2 decimal places by default. You can change that if you want, all you need to do is go to CIOTools.h, look for the function and follow the comment's instructions. After you do, you can pass as the second argument the number of decimal places, such that: dprint(-3, 3, 1.13, 2.2, 3.213); outputs:"1.130 2.200 3.213\n".



In order to include it in your program, all you need to do is bring the CIOTools.h into the program folder and write the beginning include "CIOTools.h" (simple tutorial, if you want to use it differently to the research yourself).
example.c is a short example of it's usage.


I hope this function makes someone's life a little bit easier :D
That's it! Have a nice day :)







input() and binput() both read and store all text into dynamically allocated memory arrays and statically allocated memory arrays, respectively.

This means that input() returns the pointer to a dynamic array with the exact same size as the input it received (you can remove this feature as it may have somewhat of a performance impact for larger inputs).

This also means that you must save the pointer and free() it after you're done using it. A more through explanation is in the CIOTools.h file.

For the binput() you must create the static array yourself and give it as the first function argument, as well as the it's size as the second argument. That's it, I guess.



It's customizable (supposing you know some C).


Not made for performance improments or anything. They do what they do, no relations to performance boosting (example of "bad" performance code: reallocating memory every 100 characters of input, as well as in the end of input)


TO DO:
Make print be able to take a variable/data type other than strings and print them directly (just like python's print());
Remove the need to have either NULL or 0 as the final argument;
Both objectives are a little bit far-fetched as of now.
Add random stuff I (or you <3) find useful.

Create functions for reading from specified files as well as writing into specified files (up next).

