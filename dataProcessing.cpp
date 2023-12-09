#include <iostream>
#include <unordered_map>
#include <stdexcept>
#include <string>

using namespace std;

class InMemoryDB {
private:
    unordered_map<string, int> mainState;
    unordered_map<string, int> transactionState;
    bool inTransaction;

public:
    InMemoryDB() : inTransaction(false) {}

    void begin_transaction() {
        if (inTransaction) {
            throw logic_error("Transaction already in progress");
        }
        transactionState.clear();
        inTransaction = true;
    }

    void put(const string& key, int value) {
        if (!inTransaction) {
            throw logic_error("Transaction not in progress");
        }
        transactionState[key] = value;
    }

    int get(const string& key) {
        if (mainState.count(key) > 0) {
            return mainState[key];
        } else {
            return -1; // Return a special value to indicate that the key doesn't exist
        }
    }

    void commit() {
        if (!inTransaction) {
            throw logic_error("No transaction to commit");
        }
        mainState.insert(transactionState.begin(), transactionState.end());
        transactionState.clear();
        inTransaction = false;
    }

    void rollback() {
        if (!inTransaction) {
            throw logic_error("No transaction to rollback");
        }
        transactionState.clear();
        inTransaction = false;
    }
};

int main() {
    InMemoryDB db;
    string action;

    string key;
    int value;
    bool inAction = true;
    bool transaction = false;

    while (inAction){
        
        cin >> action;
        
        if (action == "BEGIN")
        {
            db.begin_transaction();
        }

        else if (action == "PUT")
        {
            cin >> key >> value;
            db.put(key, value);
        }

        else if (action == "GET")
        {
            cin >> key;
            int result = db.get(key);
            if (result != -1) {
                cout << result << endl;
            }
        }

        else if (action == "COMMIT")
        {
            db.commit();
        }

        else if (action == "ROLLBACK")
        {
            db.rollback();
        }
    }
    return 0;
}
