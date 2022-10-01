//Homework 15

/*
 *  Filename:           main.cpp
 * 
 *  Purpose:            The purpose of this program is to 
 * 
 *  Author:             Zachary Charles Stewart
 *  Student ID:         105903414
 *  Date:               1/31/2017 15:34 PST
 */

//Preprocessor Directives
#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>
#include <iomanip>

//Namespace
using namespace std;

//Declare global constant N
const int N = 5;
const int P = 3;
//--------------------------------------------------------------------------//

//Function Definitions
// Reads in the Voting Data
void getVotes(string candidates[N], int votes[N], int &totalVotes);

// Calculates the Voting Percentages
void calculatePercentages(const int votes[N], const int totalVotes,
                          double percentages[N]);

// Calculates the Election Winner
void calculateWinner(const int votes[N], int &winnerIndex);

// Prints the Election Results
void printResults(const string candidates[N], const int votes[N],
                  const int totalVotes, const double percentages[N],
                  const int winnerIndex); 

//--------------------------------------------------------------------------//

int main(int argc, char** argv)
{
    string name[N] = {""};
    int votes[N] = {0};
    int num_votes = 0;
    int wIndex;
    double percent_votes[N] = {0};
    cout.imbue(locale("en_US.UTF-8"));
     
    getVotes(name, votes, num_votes);
    calculatePercentages(votes, num_votes, percent_votes);
    calculateWinner(votes, wIndex);
    printResults(name, votes, num_votes, percent_votes, wIndex);
       
    exit(EXIT_SUCCESS);
}

//--------------------------------------------------------------------------//


void getVotes(string candidates[N], int votes[N], int &totalVotes)
{
    if(!cin)
    {
        cout << "Invalid input stream" << endl;
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < N ; i++)
    {
        cout << "Enter candidate name and number of votes" << endl;
        cin >> candidates[i] >> votes[i];
        totalVotes += votes[i];
    }
    cout << endl << endl;
}

// Calculates the Voting Percentages
void calculatePercentages(const int votes[N], const int totalVotes,
                          double percentages[N])
{
    int vote_Total;
    for(int i = 0; i < N; i++)
    {
        vote_Total = votes[i];
        percentages[i] = (((static_cast<double>(vote_Total)*100.0) / totalVotes));
    }
}

// Calculates the Election Winner
void calculateWinner(const int votes[N], int &winnerIndex)
{
    winnerIndex = 0;
    for(int i = 0; i < N; i++)
    {
        if(votes[i] > winnerIndex)
        {
            winnerIndex = i;
        }
    }
}

// Prints the Election Results
void printResults(const string candidates[N], const int votes[N],
                  const int totalVotes, const double percentages[N],
                  const int winnerIndex)
{
    string s1 = "Candidate";
    string s2 = "Votes Received";
    string s3 = "% of Total Votes";
    
    string s4 = "Total:";
    string s5 = "The Winner of the Election is ";
    
    cout << left << setw(20) << s1 << setw(20) << s2
                 << setw(20) << s3 << endl << endl;

    for(int i = 0; i < N; i++)
    {
        cout << left;
        cout << setw(13) << candidates[i];
        cout.unsetf(ios::left);
        cout << setw(13) << votes[i];
        cout << fixed << showpoint << setprecision(2) << setw(13);
        cout << percentages[i];
        cout << endl << endl;
    }
    cout.unsetf(ios::fixed);
    cout << left << setw(10) << s4;
    cout << setw(10) << totalVotes << endl << endl;
    cout << setw(10) <<s5<< candidates[winnerIndex];
    cout << endl << endl;
}