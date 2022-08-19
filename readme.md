# Deformator
A program that really serves no purpose.

---
## About
This project came to me as an idea when I saw a youtube video on how to properly format C code. Out of the blue, I suddenly had the idea to create a *deformatter* which would be the opposite of a formatter, and and take C source code and delete all line comments, new lines, and indentation.
You may ask why I would do this, and to that I reply "For fun!"

## Usage
The basic usage of the program is fairly simple.
```bash
$ deformat [ORIGINAL FILE] [NEW FILE NAME]
```

If no new name is provided, the deformatted code will overwrite and replace the original code.


#### Example:
```bash
$ deformat pretty_code.c bad_code.c
```
