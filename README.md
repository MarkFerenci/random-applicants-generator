# Random applicant data generator

This program generates random applicant data such as names, surnames, email addresses, and dates. It utilizes random number generation to create realistic-looking applicant information.

## Functions

### printRandomNumericString(size_t len)

Prints a random numeric string of the specified length to the stdout.

### generateRandomInteger(int min, int max)

Generates a random integer within the specified range.

## printRandomDateString()

Prints a randomly generated date string in the format "dd.mm.yyyy" to the stdout.

## printRandomEmail()

Prints a random email address to the stdout.

## printApplicant(const char *name, const char *surname)

Prints a randomly generated applicant information row to the stdout.

## main()

The main function of the program that seeds the random number generator, generates applicant data for both female and male names, and prints the applicant details.

## Usage
To use this program, simply compile and run the executable. It will generate random applicant data based on the defined functions.

## Dependencies
This program includes the standard library headers `<format>`, `<iostream>` and a custom header file `config.h`.

## Compile

### With CMake

cd to the project dir and run
```
cmake .
make
```

### Directly with g++
`g++ generator.cc -std=c++23  -O3 -o generator`

## Launch
After compiling, execute the program by running the generated executable:
`./generator`

## Configuration

Configuration is performed in the header file `config.h` by directly editing the corresponding constants.

In order for the changes to take effect, you need to recompile the program.