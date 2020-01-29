#ifndef CMPE250_ASSIGNMENT3_HELPSTUDENTS_H
#define CMPE250_ASSIGNMENT3_HELPSTUDENTS_H
#include <vector>
#include <iostream>
#include <fstream>
#include<set>
#include<list>
#include<limits>
#include<bits/stdc++.h>
# define INF2 0x3f3f3f3f

using namespace std;
const long long int INF = numeric_limits<long long int>::max();

class HelpStudents{

public:
    HelpStudents(int  N,int  M,int K, vector < pair< pair <int,int> , int > > ways);
    long long int firstStudent();
    long long  int secondStudent();
    long long  int thirdStudent();
    long long int fourthStudent();
    long long  int fifthStudent();

    // YOU CAN ADD YOUR HELPER FUNCTIONS AND MEMBER FIELDS

};

#endif //CMPE250_ASSIGNMENT3_HELPSTUDENTS_H
