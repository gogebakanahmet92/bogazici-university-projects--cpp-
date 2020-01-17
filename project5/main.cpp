
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <iostream>
#include <vector>

using namespace std;

void parseInput(ifstream &inFile, int &N, int &M, vector<int> &chocolateVector);

int main(int argc, char *argv[])
{
    // Command line arguments are malformed
    if (argc != 3)
    {
        // cerr should be used for errors
        cerr << "Run the code with the following command: ./cmpe250-assignment5 [input_file] [output_file]" << endl;
        return 1;
    }

    // Open the input and output files, check for failures
    ifstream inFile(argv[1]);
    if (!inFile)
    { // operator! is synonymous to .fail(), checking if there was a failure
        cerr << "There was a problem opening \"" << argv[1] << "\" as input file" << endl;
        return 1;
    }

    ofstream outFile(argv[2]);
    if (!outFile)
    {
        cerr << "There was a problem opening \"" << argv[2] << "\" as output file" << endl;
        return 1;
    }

    int N, M;
    vector<int> cholocateVector;
    long long int sum = 0;
    vector<long long int> artis;

    parseInput(inFile, N, M, cholocateVector);
    sort(cholocateVector.begin(), cholocateVector.end());

    if (N == 0) {
        outFile << 0;
        return 0;
    }

    for (int i = 0; i < N; i++) {
        artis.push_back(0);
    }

    for (int i = 0; i < M; i++) {
        sum += cholocateVector[i];
        artis[i] = cholocateVector[i];
        outFile << sum << ' ';
    }

    for (int j = M; j < N; j++) {
        sum = sum + cholocateVector[j] + artis[j - M];
        artis[j] = cholocateVector[j] + artis[j - M];
        outFile << sum << ' ';
    }

    return 0;
}

void parseInput(ifstream &inFile, int &N, int &M, vector<int> &chocolateVector)
{
    string line, tmp;
    getline(inFile, line);
    istringstream linestream(line);
    getline(linestream, tmp, ' ');
    N = stoi(tmp);
    getline(linestream, tmp, ' ');
    M = stoi(tmp);
    getline(linestream, tmp, ' ');

    getline(inFile, line);
    istringstream linestream2(line);
    string price;
    while (getline(linestream2, price, ' ')) {
        chocolateVector.push_back(stoi(price));
    }
    inFile.close();
}
