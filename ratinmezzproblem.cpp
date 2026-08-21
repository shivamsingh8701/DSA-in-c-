#include<iostream>
#include<vector>
using namespace std;
void helper( vector<vector<int>> &mat, int i, int j,string path, vector<string> &ans, vector<vector<bool>> &visited){
   int n = mat.size();
   if(i<0 || j<0 || i>=n || j>=n || mat[i][j]==0 || visited[i][j]==true){
       return;
   }
   if(i==n-1 && j==n-1){
       ans.push_back(path);
       return;
   }

   visited[i][j] = true;
   helper(mat ,i+1, j,  path+'D', ans, visited );           
   helper(mat, i, j-1,  path+'L', ans, visited);
   helper(mat, i, j+1,  path+'R', ans, visited);
   helper(mat, i-1, j,  path+'U', ans, visited);
   visited[i][j] = false;

}
vector<string> findPath(vector<vector<int>> &mat){
    int n = mat.size();
  
    vector<string> ans;
    string path = "";
      vector<vector<bool>> visited(n, vector<bool>(n, false));
    helper(mat, 0, 0, path, ans , visited);
    return ans;
}
int main(){
vector<vector<int>> mat = {{1,0,0,0} , {1,1,0,1} , {1,1,0,0,} , {0,1,1,1}};
vector<string> ans = findPath(mat);
for(string path : ans){
    cout<<path<<endl;

}

return 0;

}