// Justin This
// CIS 1202 501
// December 2, 2023
#include <iostream>
#include <cctype>
using namespace std;

// Function prototypes.
char character(char, int);
void invalidCharacterExceptionHandler(char);
void invalidRangeExceptionHandler(int);

int main() {
    // Test 1. Should print 'b' to terminal.
    try {
        cout << character('a', 1) << endl;
    }
    catch (char invalidCharacterException) {
        invalidCharacterExceptionHandler(invalidCharacterException);
    }
    catch (int invalidRangeException) {
        invalidRangeExceptionHandler(invalidRangeException);
    }

    // Test 2. Should throw the invalidRange exception and report an error.
    try {
        cout << character('A', -1) << endl;
    }
    catch (char invalidCharacterException) {
        invalidCharacterExceptionHandler(invalidCharacterException);
    }
    catch (int invalidRangeException) {
        invalidRangeExceptionHandler(invalidRangeException);
    }

    // Test 3. Should print 'Y' to the terminal.
    try {
        cout << character('Z', -1) << endl;
    }
    catch (char invalidCharacterException) {
        invalidCharacterExceptionHandler(invalidCharacterException);
    }
    catch (int invalidRangeException) {
        invalidCharacterExceptionHandler(invalidRangeException);
    }

    // Test 4. Should throw invalidCharacterException and report an error.
    try {
        cout << character('?', -1) << endl;
    }
    catch (char invalidCharacterException) {
        invalidCharacterExceptionHandler(invalidCharacterException);
    }
    catch (int invalidRangeException) {
        invalidCharacterExceptionHandler(invalidRangeException);
    }

    // Test 5. Should throw an invalidRangeException because converion from
    // uppercase to lowercase should not be possible.
    try {
        cout << character('A', 32) << endl;
    }
    catch (char invalidCharacterException) {
        invalidCharacterExceptionHandler(invalidCharacterException);
    }
    catch (int invalidRangeException) {
        invalidRangeExceptionHandler(invalidRangeException);
    }

    // Test 6. Should throw an invalidRangeException because conversion from
    // lowercase to uppercase should not be possible.
    try {
        cout << character('j', -32) << endl;
    }
    catch (char invalidCharacterException) {
        invalidCharacterExceptionHandler(invalidCharacterException);
    }
    catch (int invalidRangeException) {
        invalidRangeExceptionHandler(invalidRangeException);
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
    // Check if the user entered a valid offset. The else if first checks that
    // the target is a character. If it is it then checks for uppercase to
    // lowercase conversion, then lowercase to uppercase conversion. It executes
    // if any of these evaluate to true.
    else if (!isalpha(start + offset) || 
             (isupper(start) && islower(start + offset)) ||
             (islower(start) && isupper(start + offset))) {
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
         << " rerun the program\nand enter a character 'A-Z' or 'a-z'.\n";
} // End invalidCharacterExceptionHandler.

/* invalidRangeExceptionHandler. This function takes an int as an argument and
 * prints a message telling the user the offset they entered is not a valid
 * offset given the character they entered. This function only runs if the
 * invalidRangeException is thrown.
 */
void invalidRangeExceptionHandler(int exceptionInt) {
    cout << "Error: " << exceptionInt << " is not a valid offset given the"
         << " character you entered. Please rerun the program\nand enter a"
         << " valid offset.\n";
} // End invalidRangeExceptionHandler.