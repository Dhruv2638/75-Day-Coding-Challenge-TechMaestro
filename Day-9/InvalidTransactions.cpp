// name of Problem : Invalid Transactions
// leetcode link of problem : https://leetcode.com/problems/invalid-transactions/
// author : Dhruv Nagar

class Transactions{
        public:
        string name;
        string city;
        int amount;
        int time;
        
        Transactions(string name, string city, int amount, int time) {
            this->name = name;
            this->city = city;
            this->amount = amount;
            this->time = time;
        }
    };
class Solution {
public:
    Transactions* decodeString(string t) {
        string name = "";
        string city = "";
        int amount = 0;
        int time = 0;
        
        int i = 0;
        while(i < t.length() && t[i] != ',') {
            name += t[i];
            i++;
        }
        i++;
        
        while(i < t.length() && t[i] != ',') {
            time = time * 10 + (t[i]-'0');
            i++;
        }
        i++;
        
        while(i < t.length() && t[i] != ',') {
            amount = amount * 10 + (t[i]-'0');
            i++;
        } 
        i++;
        
        while(i < t.length() && t[i] != ',') {
            city += t[i];
            i++;
        }
        i++; 
        
        Transactions* trx = new Transactions(name, city, amount, time);
        return trx;
    }
    bool isValid(Transactions* trx, vector<Transactions*> list) {
        if (trx->amount > 1000) {
            return false;
        }
        for (Transactions* t: list) {
            if (abs(trx->time - t->time) <= 60 && trx->city != t->city)             {
                return false;
            }
        }
        return true;
    }
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> result;
        map<string, vector<Transactions*>> m;
        int size = transactions.size();
        for (int index = 0; index < size; index++) {
            string t = transactions[index];
            Transactions* trx = decodeString(t);
            m[trx->name].push_back(trx);
        }
        
        for (string t: transactions) {
            Transactions* trx = decodeString(t);
            if (!isValid(trx, m[trx->name])) {
                result.push_back(t);
            }
        }
        
        return result;
    }
};