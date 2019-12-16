#include <iostream>
#include <string>
#include "SeatOperations.h"

using namespace std;

vector<Person> vectorA;
vector<Person> vectorB;

int sizeOfLineA;
int sizeOfLineB;

void rearrangePeople(struct Person &temp)
{
    if (temp.currentSeatType == 'A')
    {
        if (temp.type == 1)
        {
            temp.line = (temp.seatNumber - 1) % sizeOfLineB;
            temp.currentSeatType = 'B';
            if (vectorB[temp.line].line == -1)
            {
                vectorB[temp.line] = temp;
            }
            else
            {
                struct Person atemp = vectorB[temp.line];
                vectorB[temp.line] = temp;
                rearrangePeople(atemp);
            }
        }
        else if (temp.type == 2)
        {
            temp.line++;
            if (temp.line == sizeOfLineA)
            {
                temp.line = 0;
                temp.currentSeatType = 'B';
                if (vectorB[temp.line].line == -1)
                {
                    vectorB[temp.line] = temp;
                }
                else
                {
                    struct Person atemp = vectorB[temp.line];
                    vectorB[temp.line] = temp;
                    rearrangePeople(atemp);
                }
            }
            else
            {
                if (vectorA[temp.line].line == -1)
                {
                    vectorA[temp.line] = temp;
                }
                else
                {
                    struct Person atemp = vectorA[temp.line];
                    vectorA[temp.line] = temp;
                    rearrangePeople(atemp);
                }
            }
        }
        else if (temp.type == 3)
        {
            temp.type3LastOperation++;
            int k = 2 * temp.type3LastOperation - 1;
            int diffA = sizeOfLineA - 1 - temp.line;
            if (k <= diffA)
            {
                temp.line += k;
                if (vectorA[temp.line].line == -1)
                {
                    vectorA[temp.line] = temp;
                }
                else
                {
                    struct Person atemp = vectorA[temp.line];
                    vectorA[temp.line] = temp;
                    rearrangePeople(atemp);
                }
            }
            else
            {
                k = k - diffA;
                temp.currentSeatType = 'B';
                while (true)
                {
                    if (temp.currentSeatType == 'B')
                    {
                        if (k <= sizeOfLineB)
                        {
                            temp.line = k - 1;
                            if (vectorB[temp.line].line == -1)
                            {
                                vectorB[temp.line] = temp;
                            }
                            else
                            {
                                struct Person atemp = vectorB[temp.line];
                                vectorB[temp.line] = temp;
                                rearrangePeople(atemp);
                            }
                            break;
                        }
                        else
                        {
                            k = k - sizeOfLineB;
                            temp.currentSeatType = 'A';
                            continue;
                        }
                    }
                    else if (temp.currentSeatType == 'A')
                    {
                        if (k <= sizeOfLineA)
                        {
                            temp.line = k - 1;
                            if (vectorA[temp.line].line == -1)
                            {
                                vectorA[temp.line] = temp;
                            }
                            else
                            {
                                struct Person atemp = vectorA[temp.line];
                                vectorA[temp.line] = temp;
                                rearrangePeople(atemp);
                            }
                            break;
                        }
                        else
                        {
                            k = k - sizeOfLineA;
                            temp.currentSeatType = 'B';
                            continue;
                        }
                    }
                }
            }
        }
    }
    else if (temp.currentSeatType == 'B')
    {
        if (temp.type == 1)
        {
            temp.line = (temp.seatNumber - 1) % sizeOfLineA;
            temp.currentSeatType = 'A';
            if (vectorA[temp.line].line == -1)
            {
                vectorA[temp.line] = temp;
            }
            else
            {
                struct Person atemp = vectorA[temp.line];
                vectorA[temp.line] = temp;
                rearrangePeople(atemp);
            }
        }
        else if (temp.type == 2)
        {
            temp.line++;
            if (temp.line == sizeOfLineB)
            {
                temp.line = 0;
                temp.currentSeatType = 'A';
                if (vectorA[temp.line].line == -1)
                {
                    vectorA[temp.line] = temp;
                }
                else
                {
                    struct Person atemp = vectorA[temp.line];
                    vectorA[temp.line] = temp;
                    rearrangePeople(atemp);
                }
            }
            else
            {
                if (vectorB[temp.line].line == -1)
                {
                    vectorB[temp.line] = temp;
                }
                else
                {
                    struct Person atemp = vectorB[temp.line];
                    vectorB[temp.line] = temp;
                    rearrangePeople(atemp);
                }
            }
        }
        else if (temp.type == 3)
        {
            temp.type3LastOperation++;
            int k = 2 * temp.type3LastOperation - 1;
            int diffB = sizeOfLineB - 1 - temp.line;
            if (k <= diffB)
            {
                temp.line += k;
                if (vectorB[temp.line].line == -1)
                {
                    vectorB[temp.line] = temp;
                }
                else
                {
                    struct Person atemp = vectorB[temp.line];
                    vectorB[temp.line] = temp;
                    rearrangePeople(atemp);
                }
            }
            else
            {
                k = k - diffB;
                temp.currentSeatType = 'A';
                while (true)
                {
                    if (temp.currentSeatType == 'B')
                    {
                        if (k <= sizeOfLineB)
                        {
                            temp.line = k - 1;
                            if (vectorB[temp.line].line == -1)
                            {
                                vectorB[temp.line] = temp;
                            }
                            else
                            {
                                struct Person atemp = vectorB[temp.line];
                                vectorB[temp.line] = temp;
                                rearrangePeople(atemp);
                            }
                            break;
                        }
                        else
                        {
                            k = k - sizeOfLineB;
                            temp.currentSeatType = 'A';
                            continue;
                        }
                    }
                    else if (temp.currentSeatType == 'A')
                    {
                        if (k <= sizeOfLineA)
                        {
                            temp.line = k - 1;
                            if (vectorA[temp.line].line == -1)
                            {
                                vectorA[temp.line] = temp;
                            }
                            else
                            {
                                struct Person atemp = vectorA[temp.line];
                                vectorA[temp.line] = temp;
                                rearrangePeople(atemp);
                            }
                            break;
                        }
                        else
                        {
                            k = k - sizeOfLineA;
                            temp.currentSeatType = 'B';
                            continue;
                        }
                    }
                }
            }
        }
    }
}

SeatOperations::SeatOperations(int N, int M)
{
    struct Person temp;
    for (int i = 0; i < N; i++)
    {
        vectorA.push_back(temp);
    }
    for (int i = 0; i < M; i++)
    {
        vectorB.push_back(temp);
    }

    sizeOfLineA = N;
    sizeOfLineB = M;
}

void SeatOperations::addNewPerson(int personType, const string &ticketInfo)
{

    char ab = ticketInfo[0];
    int seat = stoi(ticketInfo.substr(1, ticketInfo.length() - 1));

    struct Person newPersonData;
    newPersonData.seatNumber = seat;
    newPersonData.line = ab == 'A' ? (seat - 1) % sizeOfLineA : (seat - 1) % sizeOfLineB;
    newPersonData.type = personType;
    newPersonData.initialSeatType = ab;
    newPersonData.currentSeatType = ab;

    if (ab == 'A')
    {
        if (vectorA[newPersonData.line].type == 0)
        {
            vectorA[newPersonData.line] = newPersonData;
        }
        else
        {
            struct Person personTemp = vectorA[newPersonData.line];
            vectorA[newPersonData.line] = newPersonData;
            rearrangePeople(personTemp);
        }
    }

    else if (ab == 'B')
    {
        if (vectorB[newPersonData.line].type == 0)
        {
            vectorB[newPersonData.line] = newPersonData;
        }
        else
        {
            struct Person personTemp = vectorB[newPersonData.line];
            vectorB[newPersonData.line] = newPersonData;
            rearrangePeople(personTemp);
        }
    }
}

void SeatOperations::printAllSeats(ofstream &outFile)
{
    for (int i = 0; i < sizeOfLineA; i++)
    {
        if (vectorA[i].line == -1)
        {
            outFile << 0 << endl;
        }
        else
        {
            outFile << vectorA[i].type << " " << vectorA[i].initialSeatType << vectorA[i].seatNumber << endl;
        }
    }
    for (int i = 0; i < sizeOfLineB; i++)
    {
        if (vectorB[i].line == -1)
        {
            outFile << 0 << endl;
        }
        else
        {
            outFile << vectorB[i].type << " " << vectorB[i].initialSeatType << vectorB[i].seatNumber << endl;
        }
    }
}
