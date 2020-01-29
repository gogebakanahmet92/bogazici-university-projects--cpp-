#include "HelpStudents.h"

using namespace std;

list<pair<long long int, long long int>> *adjacencyList;
list<pair<long long int, long long int>> *adjacencyList2;
list<pair<long long int, long long int>> *adjacencyList3;

vector<pair<pair<int, int>, int>> ways1;
vector<pair<pair<int, int>, int>> ways2;
vector<pair<pair<int, int>, int>> ways4;

long long int numberOfVertices;
long long int numberOfEdges;
long long int target;
long long int src = 0;

HelpStudents::HelpStudents(int N, int M, int K, vector<pair<pair<int, int>, int>> ways)
{
    ways1 = ways;
    ways2 = ways;
    ways4 = ways;

    numberOfVertices = N;
    numberOfEdges = M;
    target = K;
}

long long int HelpStudents::firstStudent()
{
    adjacencyList = new list<pair<long long int, long long int>>[numberOfVertices];
    for (long long int i = 0; i < ways1.size(); i++)
    {
        long long int u = ways1[i].first.first - 1;
        long long int v = ways1[i].first.second - 1;
        long long int w = ways1[i].second;
        adjacencyList[u].push_back(make_pair(v, w));
        adjacencyList[v].push_back(make_pair(u, w));
    }

    set<pair<long long int, long long int>> setds;

    vector<long long int> dist(numberOfVertices, INF);

    setds.insert(make_pair(0, src));
    dist[src] = 0;

    while (!setds.empty())
    {
        pair<long long int, long long int> tmp = *(setds.begin());
        setds.erase(setds.begin());

        long long int u = tmp.second;

        list<pair<long long int, long long int>>::iterator i;
        for (i = adjacencyList[u].begin(); i != adjacencyList[u].end(); ++i)
        {
            long long int v = (*i).first;
            long long int weight = (*i).second;

            if (dist[v] > dist[u] + weight)
            {
                if (dist[v] != INF)
                    setds.erase(setds.find(make_pair(dist[v], v)));

                dist[v] = dist[u] + weight;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }
    return dist[target - 1];
}

long long int HelpStudents::secondStudent()
{
    // IMPLEMENT ME!
    adjacencyList2 = new list<pair<long long int, long long int>>[numberOfVertices];
    for (long long int i = 0; i < ways1.size(); i++)
    {
        if (ways1[i].first.first == ways1[i].first.second)
            continue;
        long long int u = ways1[i].first.first - 1;
        long long int v = ways1[i].first.second - 1;
        long long int w = ways1[i].second;
        adjacencyList2[u].push_back(make_pair(v, w));
        adjacencyList2[v].push_back(make_pair(u, w));
    }

    set<pair<long long int, long long int>> setds;
    vector<long long int> dist(numberOfVertices, INF);
    vector<bool> visited(numberOfVertices, false);
    long long int maxEdge[numberOfVertices];

    setds.insert(make_pair(0, src));
    dist[src] = 0;
    visited.at(0) = true;
    maxEdge[0] = 0;

    while (!setds.empty())
    {
        pair<long long int, long long int> tmp = *(setds.begin());
        setds.erase(setds.begin());

        long long int u = tmp.second;
        visited.at(u) = true;
        list<pair<long long int, long long int>>::iterator i;
        for (i = adjacencyList2[u].begin(); i != adjacencyList2[u].end(); ++i)
        {
            if (visited.at((*i).first))
            {
                continue;
            }
            long long int v = (*i).first;
            long long int weight = (*i).second;

            if (dist[v] > weight)
            {
                if (maxEdge[u] < weight)
                {
                    maxEdge[v] = weight;
                }
                else
                {
                    maxEdge[v] = maxEdge[u];
                }
                if (dist[v] != INF)
                    setds.erase(setds.find(make_pair(dist[v], v)));

                dist[v] = weight;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }
    list<pair<long long int, long long int>>::iterator i;

    return maxEdge[target - 1];
}

long long int HelpStudents::thirdStudent()
{
    adjacencyList = new list<pair<long long int, long long int>>[numberOfVertices];
    for (long long int i = 0; i < ways1.size(); i++)
    {
        long long int u = ways1[i].first.first - 1;
        long long int v = ways1[i].first.second - 1;
        long long int w = 1;
        adjacencyList[u].push_back(make_pair(v, w));
        adjacencyList[v].push_back(make_pair(u, w));
    }

    set<pair<long long int, long long int>> setds;

    vector<long long int> dist(numberOfVertices, INF);

    setds.insert(make_pair(0, src));
    dist[src] = 0;

    while (!setds.empty())
    {
        pair<long long int, long long int> tmp = *(setds.begin());
        setds.erase(setds.begin());

        long long int u = tmp.second;

        list<pair<long long int, long long int>>::iterator i;
        for (i = adjacencyList[u].begin(); i != adjacencyList[u].end(); ++i)
        {
            long long int v = (*i).first;
            long long int weight = (*i).second;

            if (dist[v] > dist[u] + weight)
            {
                if (dist[v] != INF)
                    setds.erase(setds.find(make_pair(dist[v], v)));

                dist[v] = dist[u] + weight;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }
    return dist[target - 1];
}
long long int HelpStudents::fourthStudent()
{
    long long int max = 0;
    bool boolean = false;
    set<pair<int, int>> pq;
    adjacencyList = new list<pair<long long int, long long int>>[numberOfVertices];
    for (long long int i = 0; i < ways4.size(); i++)
    {
        long long int u = ways4[i].first.first - 1;
        long long int v = ways4[i].first.second - 1;
        long long int w = ways4[i].second;
        adjacencyList[u].push_back(make_pair(v, w));
        adjacencyList[v].push_back(make_pair(u, w));
    }

    vector<pair<long long int, long long int>> check[numberOfVertices];
    long long int v;
    long long int weight;
    //check->at(0)= make_pair(0,0);
    //long long int tmp = *(check->begin().second);
    long long int u = 0;
    for (;;)
    {

        list<pair<long long int, long long int>>::iterator i;
        for (i = adjacencyList[u].begin(); i != adjacencyList[u].end(); ++i)
        {
            pq.insert(make_pair((*i).second, (*i).first));
        }

        while (!pq.empty())
        {
            pair<int, int> pr = *(pq.begin());
            int minWeight = pr.first;
            int nodeNumber = pr.second;
            pq.erase(pq.begin());
            v = pr.second;
            weight = pr.first;

            bool existence = false;

            vector<pair<long long int, long long int>>::iterator i;
            for (i = check[u].begin(); i != check[u].end(); ++i)
            {
                if ((*i).first == weight && (*i).second == v)
                    existence = true;
            }

            if (!existence)
            {
                check[u].push_back(make_pair(weight, v));
                check[v].push_back(make_pair(weight, u));
                u = v;
                boolean = true;
                pq.clear();
                break;
            }
        }

        if (!boolean)
            return -1;
        max += weight;
        if (v == target - 1)
        {
            return max;
        }
        boolean = false;
    }
}
long long int HelpStudents::fifthStudent()
{
}

// YOU CAN ADD YOUR HELPER FUNCTIONS