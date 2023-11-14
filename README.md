This programming project is divided into four tasks for creating a Hangman game in C++. Here's a breakdown of each task:

**Task A: Dictionary using Arrays**
- Create a dictionary using global arrays for words, definitions, and part-of-speech.
- Implement a function `readWords` to read words, definitions, and part-of-speech from a file into the global arrays.
- Global variables include `g_MAX_WORDS`, `g_word_count`, `g_words`, `g_definitions`, and `g_pos`.

**Task B: Dictionary Operations**
- Implement functions for dictionary operations: `getIndex`, `getDefinition`, `getPOS`, and `countPrefix`.
- These functions allow users to query information about words in the dictionary.
- Test each function incrementally, and submit a single .cpp file without the main function.

**Task C: Dictionary Admin Operations**
- Implement functions to modify, add, and remove words in the dictionary: `addWord`, `editWord`, and `removeWord`.
- Ensure proper handling of word additions, edits, and removals.
- Utilize previously implemented functions for indexing.
- Submit a single .cpp file without the main function.

**Task D: Hangman**
- Implement a Hangman game using a provided game loop `gameLoop`.
- Additional functions include `getRandomWord`, `maskWord`, `getTries`, `printAttempts`, and `revealLetter`.
- The game involves selecting a random word, masking it, and allowing the player to guess letters until they either succeed or run out of attempts.
- Test each function, ensuring proper integration with the game loop.
- Submit a single .cpp file to gradescope without the main function.

**Important Notes:**
- Emphasizes incremental development, testing, and submission of individual tasks.
- Provides detailed specifications for each function, including parameters, return types, and post-conditions.
- Requires proper implementation of global variables, arrays, and file handling.
- Highlights the importance of testing and suggests removing the main function before submission to gradescope.
