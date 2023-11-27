#include <iostream>
#include <cctype>
using namespace std;

// Function prototypes.
char character(char, int);

int main() {

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