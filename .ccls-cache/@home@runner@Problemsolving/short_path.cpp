#include "my_include.h"

// give a string 'a', calculate the shortest path from first node of 6 [a] to
// last node of 6 [f]
vector<string> split(string &s, char delimiter) {
  vector<string> res;
  stringstream ss(s);
  string word;

  while (getline(ss, word, delimiter)) {
    res.push_back(word);
  }
  return res;
}
vector<string> getV(vector<string> &v, int n) {
  vector<string> res;
  for (int i = 0; i < n; ++i)
    res.push_back(v[i + 1]);
  return res;
}
unordered_map<string, vector<string>> getMp(vector<string> &v, int n) {
  unordered_map<string, vector<string>> res;
  for (int i = n + 1; i < v.size(); ++i) {
    // split 'x-y' by '-'
    int index = v[i].find('-');
    string first = v[i].substr(0, index);
    string second = v[i].substr(index + 1);
    if (res.find(first) != res.end())
      res[first].push_back(second);
    else
      res[first] = {second};
  }
  return res;
}

void dfs(string target, queue<vector<string>> &to_visited, set<string> &visited,
         unordered_map<string, vector<string>> &mp, vector<string> &res) {
  while (!to_visited.empty()) {
    int loop = to_visited.size();
    for (int i = 0; i < loop; i++) {
      vector<string> v = to_visited.front();
      to_visited.pop();
      string last_node = v.back();

      for (auto node : mp[last_node]) {
        if (visited.count(node) == 0) {
          v.push_back(node);

          if (node == target) {
            res = v;
            return;
          }
          to_visited.push(v);
          v.pop_back();
          visited.insert(node);
        }
      }
    }
  }
}

int main() {
  string a = "6,a,b,c,d,e,f,a-b,b-c,c-d,d-e,e-f,b-d,a-e";
  vector<string> words = split(a, ',');

  int n = stoi(words[0]);
  vector<string> vertex = getV(words, n);
  unordered_map<string, vector<string>> mp = getMp(words, n);

  string start = words[1];
  string target = words[n];
//cout << "FROM " << start << " TO " << target << endl;
  set<string> visited;
  queue<vector<string>> to_visited;
  vector<string> path;
  vector<string> result;
  to_visited.push({start});
  // DFS
  dfs(target, to_visited, visited, mp, result);

  cout << "The shortest path fomr [" << start << "] to [" << target << "] is:
" << endl;

  for(int i=0; i<result.size()-1; i++)
    cout << result[i] << " -> ";
  cout << result.back();
}