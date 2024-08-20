# Binary Search Tree Spell Checker

## Overview

This project is a simple spell checker implemented using a Binary Search Tree (BST) in C. The program reads words from a dictionary file and stores them in the BST. It then allows the user to input a sentence and checks each word against the dictionary, offering spelling suggestions if a word is not found.

## Features

- **Insert Words into BST:** Words from a dictionary file (`Dictionary.txt`) are inserted into the BST, allowing efficient storage and retrieval.
- **Spell Checking:** The program checks each word in the user-provided sentence. If a word is not found in the dictionary, it suggests the closest words (predecessor and successor) based on the BST structure.
- **Display BST:** The BST can be displayed in order, showcasing the sorted order of words.
- **Get Height of BST:** The program calculates the height of the BST, providing insight into its structure.

## How It Works

1. **Dictionary Input:** The program reads words from a file named `Dictionary.txt` and inserts them into the BST.
2. **Spell Check:** The user inputs a sentence, and the program checks each word. If the word is found in the BST, it is marked as correct. If not, the program suggests similar words.
3. **Suggestions:** The program provides up to two suggestions based on the closest nodes in the BST.

## Code Structure

- `node` struct: Represents a single node in the BST.
- `initNode`: Initializes a new node with a given word.
- `insertWord`: Inserts a word into the BST.
- `displayBST`: Displays the words in the BST in order.
- `getHeight`: Calculates the height of the BST.
- `findSuccessor` and `findPredecessor`: Find the closest nodes in the BST to provide word suggestions.
- `spellCheck`: Checks if a word is correct and provides suggestions if it's not.

## Getting Started

### Prerequisites

- A C compiler (e.g., GCC)
- A `Dictionary.txt` file containing words to be used for spell checking

### Running the Program

1. Clone the repository or copy the source code.
2. Compile the code using a C compiler:
   ```sh
   gcc -o spell_checker spell_checker.c
3. Run the executable:
    ```sh
    ./spell_checker
  
### Example Dictionary.txt

```
apple
banana
grape
orange
pear
```

### Example Output

```
Size: 5
Height: 2
Enter a sentence :
applle banana orange
applle - Incorrect, Suggestions: apple banana No predecessor
banana - CORRECT
orange - CORRECT
```

### Notes
- Ensure that the Dictionary.txt file is in the same directory as the compiled executable.
- The dictionary file should contain one word per line.