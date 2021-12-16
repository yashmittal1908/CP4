#include <string>
#include <sstream>
#include <iostream>
#include "VoteHeap.h"

int main(int, char* argv[]) {
    using namespace std;

    size_t flight_cost = stoull(argv[1]);
    string choice;
    string action;
    UserTree userTree;
    VoteHeap voteHeap;
    size_t profit = 0;
    size_t moneyPool = 0;

    //menu
    do {
        cout << endl;
        cout << "What would you like to do?" << endl;
        cout << "1. Register <userid>" << endl;
        cout << "2. Vote <numofvotes> <userid>" << endl;
        cout << "3. Scoreboard <k>" << endl;
        cout << endl;

        getline(cin, choice);
        stringstream choice_stream(choice);
        choice_stream >> action; // main command
        if (action == "register") {
            string userid;
            std::getline(choice_stream, userid);
            User* user = userTree.find(userid);
            if (user) {
                cerr << "This username is already taken! Please try again!" << endl;
            } else {
                user = new User{userid};
                voteHeap.insert(user);
                userTree.insert(user);
                cout << "User " << userid << " successfully registered!" << endl;
            }
        } else if (action == "vote") {
            size_t votes;
            choice_stream >> votes;
            string userid;
            std::getline(choice_stream, userid);

            User* user = userTree.find(userid);
            if (user != nullptr){
                voteHeap.updateVotes(user, votes);
                moneyPool += votes / 2;
                profit += votes / 2 + (votes % 2);
                cout << "MoneyPool = " << moneyPool << endl;
                for (; moneyPool >= flight_cost && voteHeap.size() > 0; moneyPool -= flight_cost) {
                    User* toLaunch = voteHeap.extractMax();
                    const string& launchUserID = toLaunch->m_user_id;
                    cout << "Launch User Id: " << launchUserID << endl;
                    userTree.remove(toLaunch);
                }
            } else {
                cerr << "This user doesn't exist!" << endl;
            }
        } else if (action == "scoreboard") {
            size_t k;
            choice_stream >> k;
            voteHeap.scoreboard(k);
        } else if (action == "profit") {
            cout << '$' << profit << endl;
        }
    } while (choice != "Exit");
}
