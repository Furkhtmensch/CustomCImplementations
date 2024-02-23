# CustomCImplementations
Some custom C implementations which appeal more to my taste.



nprint.h is a header composed of 3 functions, two of which serve as support for convertion from integer/float to string format with as many decimal places as you want (255 limit, close enough. Logically, you can change it).
nprint() is a function which is similar to python's print() (helpful for people who like python's simplicity and flexibility with the print() function), although it supports printf for every string passed to the function.
The only downside (yet) is having to pass NULL as the final argument (will attempt to remove the need for it). It's necessary because I haven't found a way to check when the end of arguments is reached.


The way you use it is simple: You pass a string, you may insert %<char> somewhere in it and then you must pass, as arguments, left-to-right order, the corresponding value so that the symbols are replaced. Then, in the end, you pass NULL (as the very last argument). You may pass as many strings as you want (separated by commas, which means they are separate arguments!), as well as as many %<char> symbols as you want. Here is the list of currently implemented values:


%c     -> replace it with a character (single quotes :D)

%s     -> replace it with a string (double quotes :D)

%i     -> replace it with an integer (integers ONLY, no implicit conversions, sorry not sorry)

%f     -> replace it with a floating point number (float and double, floats will always be implicitly converted to double, does not work with integers, sorry again)

%.f    -> works the in the same way as the previous one (%f)

%.xf   -> takes floats/doubles and prints with the first x decimal places

%.xxf  -> takes float/double and prints with the first xx decimal places

%.xxxf -> takes float/double and prints with the first xxx decimal places (change the limit of decimal places and you can use even more 'x' :D)


I hope this function makes someone's life a little bit easier :)

In order to include it in your program, all you need to do is bring the nprint.h into the program folder and write the beginning include "nprint.h" (simple tutorial, if you want to use it differently to the research yourself)

That's it! Have a nice day :)
