class Solution {
public:

    void dfs(vector<vector<char>>& grid,
        int numRows,
        int numCols,
        int rowIdx,
        int colIdx)
    {
        if((rowIdx >= 0 && rowIdx < numRows) &&
           (colIdx >= 0  && colIdx < numCols))
        {
            if(grid[rowIdx][colIdx] == '1')
            {
                grid[rowIdx][colIdx] = '0';
                dfs(grid, numRows, numCols, rowIdx-1, colIdx); /* Left */
                dfs(grid, numRows, numCols, rowIdx+1, colIdx); /* Right */
                dfs(grid, numRows, numCols, rowIdx, colIdx+1); /* Bottom */
                dfs(grid, numRows, numCols, rowIdx, colIdx-1); /* Top */
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) { 
        
        int numRows = 0;
        int numCols = 0;
        int numIslands = 0;
        
        if(grid.empty())
            return 0;
        
        numRows = grid.size();
        numCols = grid[0].size();
        
        for(int i=0; i<numRows; ++i)
        {
            for(int j=0; j<numCols; ++j)
            {
                if(grid[i][j] == '1')
                {
                    ++numIslands;
                    dfs(grid, numRows, numCols, i, j);                    
                }
            }
        }
        return numIslands;
    }
};
