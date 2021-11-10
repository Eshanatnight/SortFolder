# Sort Folder Program

## Backstory

</br>

So I when I write code I just create files sometimes without realizing where I am creating them.

Naturally when I have to open the Project in a different IDE or Text Editor I have to open the folder and find the file to properly open, compile and do all that jazz.

So the Procrostinator in me thought it would be a good idea to create a program that will automate sorting the files.

Hence this Python program was born.

</br>

---

## Useage

</br>

```terminal
    python FolderSort.py
```

You run the script AFTER you have changed the path in the script itself.Pretty Self Explanatory. Well What would you expect? :)

</br>

---

## Issues

</br>

Some issues I have noticed are:

- The program won't work without the Python Interpreter Installed.

        Possible Solution / Fix:

            1. Having the Python Interpreter Installed is a requirement for the program to work.
            ( But that goes against my Procrostinator's philosophy )


            2. Packing the Python Installer into the program via the pyinstaller


            3. Porting the program in to CXX

- Python Program is slow to run for large number files that need to be sorted.

        Even though realistically most of the time I would expect anyone to use this won't use it for that high amount of files.

---


## Todos / To be Decided:

- Pack the script file in a Python Virtual Envirnment Executable. But then at that point the C++ Executable will be more stable and less resource intencive.

    [ * ] Development Started

- Port to CXX so that we can still use the functionality without an interpreter

        PLUS: always running an instance of python interpreter would problably be inefficient use of CPU use.

---


## Licensing Information:

Copyright (C) 2020 Eshanatnight

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

Based on the UNLICENSE

[More Information Here](./LICENSE)