# Data Processing and Storage

## How to Run Code
1. Clone repository.
2. In the command line, navigate into the directory of the cloned repository.
3. To compile the C++ file, run the following command:
```bash
  g++ dataProcessing.cpp -o dataProcessing
```
4. Run the executable.
```bash
  dataProcessing.exe
```
5. To perform a specific function, enter one of the following commands:

   * "BEGIN TRANSACTION" - To start a new transaction.
   * "PUT" - To create or update a key/value pair
   * "GET" - To return the value associated with the key or null if the key doesn’t exist
   * "COMMIT" - To apply changes made within the transaction to the main state
   * "ROLLBACK" - To abort all the changes made within the transaction

## Assignment Modification
For this to become an "official assignment", I first suggest clarifying the instructions regarding the function commands and input format expectations. Students should know whether to ask for user input to determine which commands to use or hard-code specific examples with the function commands. To ensure consistency among submissions, file and class naming conventions can be specified. Additionally, students can be encouraged to write more detailed documentation that includes the thought process behind their data structure implementation. 
