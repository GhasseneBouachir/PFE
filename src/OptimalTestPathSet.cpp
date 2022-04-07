#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef tuple<vector<int>,long long,long long,vector<int>> path; //<path contentTranisitions, cost, heuristic, path contentNodes>
typedef vector<int> tObs;

struct myComparator
{
  bool operator()(const path& path1,
                 const path& path2)
  {
  	  	return get<1>(path1)+get<2>(path1) > get<1>(path2)+get<2>(path2);
  }
};


inline int getHeuristic( vector<int> transitions, int newTransition, long oldHeuristic ) {
		if(binary_search(transitions.begin(), transitions.end(), newTransition))
			return oldHeuristic;
		else return oldHeuristic - 1;
}

const int DFS_WHITE = -1;
const int DFS_BLACK = 1;

#define TRvii(c,it) \
	for (vii::iterator it = (c).begin(); it != (c).end(); it++)
int dfs_num[100];
vector <vii> AdjList;


void print(priority_queue<path,vector<path>,myComparator> priorityQueue)
{
  while (!priorityQueue.empty())
  {
    // Each element of the priority
    // queue is a tuple itself
    tuple<vector<int>, long, long, vector<int>> Tuple =
          priorityQueue.top();

    cout << "[ ";

    for (int i: get<0>(Tuple))
        std::cout << i << ' ';
    cout << ';';
   cout <<  get<1>(Tuple) << ';' <<
            get<2>(Tuple);
   cout << ';';
   for (int i: get<3>(Tuple))
           std::cout << i << ' ';
    cout << ']';
    cout << '\n';

    // Pop out the topmost tuple
    priorityQueue.pop();
  }
}


void a_star_based_path_generator(int start, vector<int> tObs){
//	bool totalCoverage = false;
	path current;
	// using lambda to compare paths.
//	    auto compare = [](path p1, path p2)
//	                {
//	                    return get<1>(p1)+get<2>(p1) < get<1>(p1)+get<2>(p1);
//	                };
	priority_queue<path,vector<path>,myComparator> open;
	vector<int> nodes{0};
	vector<int> transitions{};
	//Initialistaion
	for(vii::iterator it = AdjList[0].begin(); it != AdjList[0].end(); it++){
		nodes.push_back(it->first);
		transitions.push_back(it->second);
		path p = make_tuple(transitions,1,tObs.size()-1, nodes);
		open.emplace(p);
	}
	print(open);
	cout << "after Init \n";
	int i = 0;
	if(!open.empty()){
		current = open.top();}
	while(get<2>(current) != INT_MAX && i <100){
//		print(open);
//		cout << "\n";
		if(!open.empty())open.pop();
		if(AdjList[get<3>(current).back()].size()>0){
			for(vii::iterator it = AdjList[get<3>(current).back()].begin(); it != AdjList[get<3>(current).back()].end(); it++){
					transitions = get<0>(current);
					nodes = get<3>(current);
					transitions.push_back(it->second);
					nodes.push_back(it->first);
					if(count(get<3>(current).begin(), get<3>(current).end(),it->first)==0){
						open.emplace(make_tuple(transitions,transitions.size(),getHeuristic(transitions,transitions.back(),get<2>(current)), nodes));
					}
					else if(count(get<3>(current).begin(), get<3>(current).end(),it->first)==1){
						open.emplace(make_tuple(transitions,transitions.size(),getHeuristic(transitions,transitions.back(),get<2>(current)), nodes));
//						open.emplace(make_tuple(transitions,transitions.size(),INT_MAX, nodes));
					}
					else if(count(get<3>(current).begin(), get<3>(current).end(),it->first)==2){
//						do{
//							transitions.pop_back();
//							nodes.pop_back();
//						}
//						while(nodes.back()!=it->first);
//						open.emplace(make_tuple(transitions,transitions.size(),INT_MAX, nodes));
					}
			}
		}
		else{
			get<2>(current) = INT_MAX;
			open.emplace(current);
		}
		i++;
		if(!open.empty()){
			current = open.top();
		}
	}
	print(open);
}










void dfs(int u){
	printf("%d \n", u);
	dfs_num[u] = DFS_BLACK;
	TRvii (AdjList[u],v){
//		printf("hello : %d \n", dfs_num[v->first]);
		if (dfs_num[v->first] == DFS_WHITE )
			dfs(v->first);
	}
}







int main (){
cout << "path generator\n";

ii tmpPair;
vii tmpVPair;

//tmpPair.first = 1;
//tmpPair.second = 0;
//tmpVPair.push_back(tmpPair);
//AdjList.push_back(tmpVPair);
//tmpVPair.clear();
//
//tmpPair.first = 0;
//tmpPair.second = 0;
//tmpVPair.push_back(tmpPair);
//tmpPair.first = 3;
//tmpPair.second = 0;
//tmpVPair.push_back(tmpPair);
//tmpPair.first = 2;
//tmpPair.second = 0;
//tmpVPair.push_back(tmpPair);
//AdjList.push_back(tmpVPair);
//tmpVPair.clear();
//
//tmpPair.first = 1;
//tmpPair.second = 0;
//tmpVPair.push_back(tmpPair);
//tmpPair.first = 3;
//tmpPair.second = 0;
//tmpVPair.push_back(tmpPair);
//AdjList.push_back(tmpVPair);
//tmpVPair.clear();
//
//tmpPair.first = 1;
//tmpPair.second = 0;
//tmpVPair.push_back(tmpPair);
////tmpPair.first = 2;
////tmpPair.second = 0;
////tmpVPair.push_back(tmpPair);
//tmpPair.first = 4;
//tmpPair.second = 0;
//tmpVPair.push_back(tmpPair);
//AdjList.push_back(tmpVPair);
//tmpVPair.clear();
//
//tmpPair.first = 3;
//tmpPair.second = 0;
//tmpVPair.push_back(tmpPair);
//tmpPair.first = 5;
//tmpPair.second = 0;
//tmpVPair.push_back(tmpPair);
//AdjList.push_back(tmpVPair);
//tmpVPair.clear();
//
//tmpPair.first = 6;
//tmpPair.second = 0;
//tmpVPair.push_back(tmpPair);
//AdjList.push_back(tmpVPair);
//tmpVPair.clear();
//
//
//tmpPair.first = 7;
//tmpPair.second = 0;
//tmpVPair.push_back(tmpPair);
//AdjList.push_back(tmpVPair);
//tmpVPair.clear();
//
//tmpPair.first = 6;
//tmpPair.second = 0;
//tmpVPair.push_back(tmpPair);
//AdjList.push_back(tmpVPair);
//tmpVPair.clear();
//
//AdjList.push_back(tmpVPair);
//
//AdjList.push_back(tmpVPair);
//
//AdjList.push_back(tmpVPair);

////0
//tmpPair.first = 1;
//tmpPair.second = 0;
//tmpVPair.push_back(tmpPair);
//AdjList.push_back(tmpVPair);
//tmpVPair.clear();
//
////1
//tmpPair.first = 2;
//tmpPair.second = 0;
//tmpVPair.push_back(tmpPair);
//AdjList.push_back(tmpVPair);
//tmpVPair.clear();
//
////2
//tmpPair.first = 3;
//tmpPair.second = 0;
//tmpVPair.push_back(tmpPair);
//tmpPair.first = 4;
//tmpPair.second = 0;
//tmpVPair.push_back(tmpPair);
//tmpPair.first = 5;
//tmpPair.second = 0;
//tmpVPair.push_back(tmpPair);
//AdjList.push_back(tmpVPair);
//tmpVPair.clear();
//
//
////3
//tmpPair.first = 1;
//tmpPair.second = 0;
//tmpVPair.push_back(tmpPair);
//tmpPair.first = 7;
//tmpPair.second = 0;
//tmpVPair.push_back(tmpPair);
//AdjList.push_back(tmpVPair);
//tmpVPair.clear();
//
////4
//AdjList.push_back(tmpVPair);
//tmpVPair.clear();
//
////5
//tmpPair.first = 6;
//tmpPair.second = 0;
//tmpVPair.push_back(tmpPair);
//AdjList.push_back(tmpVPair);
//tmpVPair.clear();
//
//
////6
//tmpPair.first = 0;
//tmpPair.second = 0;
//tmpVPair.push_back(tmpPair);
//AdjList.push_back(tmpVPair);
//tmpVPair.clear();
//
////7
//AdjList.push_back(tmpVPair);
//tmpVPair.clear();

//0
tmpPair.first = 1;
tmpPair.second = 0;
tmpVPair.push_back(tmpPair);
AdjList.push_back(tmpVPair);
tmpVPair.clear();

//1
tmpPair.first = 2;
tmpPair.second = 0;
tmpVPair.push_back(tmpPair);
tmpPair.first = 4;
tmpPair.second = 0;
tmpVPair.push_back(tmpPair);
AdjList.push_back(tmpVPair);
tmpVPair.clear();

//2
tmpPair.first = 3;
tmpPair.second = 0;
tmpVPair.push_back(tmpPair);
AdjList.push_back(tmpVPair);
tmpVPair.clear();


//3
tmpPair.first = 1;
tmpPair.second = 0;
tmpVPair.push_back(tmpPair);
AdjList.push_back(tmpVPair);
tmpVPair.clear();

//4
AdjList.push_back(tmpVPair);
tmpVPair.clear();

vector<int> tobs = {0,1,2,3};
a_star_based_path_generator(0,tobs);






}

