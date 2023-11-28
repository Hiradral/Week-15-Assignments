#include <iostream>
#include <cctype>
using namespace std;

// Function prototypes.
char character(char, int);
void invalidCharacterExceptionHandler(char);

int main() {
    // Test 1. Should print 'a' to terminal.
    try {
        cout << character('a', 1) << endl;
    }
    catch (char invalidCharacterException) {
        invalidCharacterExceptionHandler(invalidCharacterException);
    }
    catch (int invalidRangeException) {
        cout << "Error: " << invalidRangeException << " is not a valid"
             << " offset given the character\nyou entered. Please enter a valid"
             << " offset.\n";
    }

    // Test 2. Should throw the invalidRange exception and report an error.
    try {
        cout << character('A', -1) << endl;
    }
    catch (char invalidCharacterException) {
        invalidCharacterExceptionHandler(invalidCharacterException);
    }
    catch (int invalidRangeException) {
        cout << "Error: " << invalidRangeException << " is not a valid"
             << " offset given the character\nyou entered. Please enter a valid"
             << " offset.\n";
    }

    // Test 3. Should print 'Y' to the terminal.
    try {
        cout << character('Z', -1) << endl;
    }
    catch (char invalidCharacterException) {
        invalidCharacterExceptionHandler(invalidCharacterException);
    }
    catch (int invalidRangeException) {
        cout << "Error: " << invalidRangeException << " is not a valid"
            << " offset given the character\nyou entered. Please enter a valid"
            << " offset.\n";
    }

    // Test 4. Should throw invalidCharacterException and report an error.
    try {
        cout << character('?', -1) << endl;
    }
    catch (char invalidCharacterException) {
        invalidCharacterExceptionHandler(invalidCharacterException);
    }
    catch (int invalidRangeException) {
        cout << "Error: " << invalidRangeException << " is not a valid"
            << " offset given the character\nyou entered. Please enter a valid"
            << " offset.\n";
    }

    return 0;
}

/* character function. The function takes a char argument representing the
 * starting point and an int argument representing the offset from the starting
 * point. The function checks to make sure the user entered a valid character,
 * and that the target letter is also a valid character. If both are valid then
 * the function returns the offset character.
 */
char character(char start, int offset) {
    // Check if the user entered a valid letter.
    if ((start < 'A' || start > 'Z') && (start < 'a' || start > 'z')) {
        char invalidCharacterException = start;
        throw invalidCharacterException;
    }
    // Check if the user entered a valid offset.
    else if (!isalpha(start + offset)) {
        int invalidRangeException = offset;
        throw invalidRangeException;
    }
    // Everything is good. Return the letter targeted by the offset.
    else
        return start + offset;
} // End character.

/* invalidCharacterExceptionHandler. This function takes a char as an argument
 * and prints a message telling the user the character they entered is not a
 * valid character. This function only runs if the invalidCharacterException is
 * thrown.
 */
void invalidCharacterExceptionHandler(char exceptionChar) {
    cout << "Error: " << exceptionChar << " is not a valid character. Please"
         << "enter a character 'A-Z' or 'a-z'.\n";
}