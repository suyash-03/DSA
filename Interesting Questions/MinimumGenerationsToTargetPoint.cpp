#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {

        for(auto i: points){
            if(target == i){
                return 0;
            }
        }

        if(points.size() == 1) return -1;

        vector<vector<int>> allPoints = points;

        set<vector<int>> seen;

        for(auto &p : points){
            seen.insert(p);
        }

        int k = 0;

        while(true){

            vector<vector<int>> newGeneration;

            int n = allPoints.size();

            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){

                    int x1 = allPoints[i][0];
                    int y1 = allPoints[i][1];
                    int z1 = allPoints[i][2];

                    int x2 = allPoints[j][0];
                    int y2 = allPoints[j][1];
                    int z2 = allPoints[j][2];

                    int x3 = (x1 + x2) / 2;
                    int y3 = (y1 + y2) / 2;
                    int z3 = (z1 + z2) / 2;

                    vector<int> generationK = {x3,y3,z3};

                    if(generationK == target)
                        return k + 1;

                    if(seen.find(generationK) == seen.end()){
                        seen.insert(generationK);
                        newGeneration.push_back(generationK);
                    }
                }
            }

            if(newGeneration.empty())
                return -1;

            for(auto &p : newGeneration){
                allPoints.push_back(p);
            }

            k++;
        }
    }
};

int main(){
    Solution sol;

    vector<vector<int>> points = {{0,0,0},{5,5,5}};
    vector<int> target = {1,1,1};

    cout << sol.minGenerations(points, target) << endl;

    return 0;
}
