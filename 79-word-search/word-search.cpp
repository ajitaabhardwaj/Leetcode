class Solution {
public:

    void solve(string& curr, int i, int j, vector<vector<char>>& board, string& word, vector<vector<bool>>& visited, int n, int m, bool& ans, int index)
    {
        if(curr == word)
        {
            ans = true;
            return;
        }

        if(board[i][j] != word[index])
        {
            return;
        }

        index++;

        visited[i][j] = true;
        if(j+1 < m)
        {
            if(visited[i][j+1] == false)
            {
            curr.push_back(board[i][j+1]);
            solve(curr, i, j+1, board, word, visited, n, m, ans, index);
            curr.pop_back();
            }
        }
        if(i+1 < n)
        {
            if(visited[i+1][j] == false)
            {
            curr.push_back(board[i+1][j]);
            solve(curr, i+1, j, board, word, visited, n, m, ans, index);
            curr.pop_back();
            }
        }

        if(j-1 >= 0)
        {
            if(visited[i][j-1] == false)
            {
            curr.push_back(board[i][j-1]);
            solve(curr, i, j-1, board, word, visited, n, m, ans, index);
            curr.pop_back();
            }
        }
        
        if(i-1 >= 0)
        {
            if(visited[i-1][j] == false)
            {
            curr.push_back(board[i-1][j]);
            solve(curr, i-1, j, board, word, visited, n, m, ans, index);
            curr.pop_back();
            }
        }
        visited[i][j] = false;
        return;
    }
    bool exist(vector<vector<char>>& board, string word) 
    {
        int n = board.size();
        int m = board[0].size();
        reverse(word.begin(), word.end());
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        bool ans = false;
        int index = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                string curr ="";
                curr.push_back(board[i][j]);
                solve(curr, i, j, board, word, visited, n, m, ans, index);

                if(ans==true)
                {
                    break;
                }
            }
        }
        return ans;
    }
};