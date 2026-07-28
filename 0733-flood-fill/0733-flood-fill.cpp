class Solution {
public:
    void dfs(vector<vector<int>>& image, int row, int col,
             int oldColor, int newColor) {

        if (row < 0 || row >= image.size() ||
            col < 0 || col >= image[0].size())
            return;

        if (image[row][col] != oldColor)
            return;

        image[row][col] = newColor;

        dfs(image, row + 1, col, oldColor, newColor);
        dfs(image, row - 1, col, oldColor, newColor);
        dfs(image, row, col + 1, oldColor, newColor);
        dfs(image, row, col - 1, oldColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,int sr, int sc, int color) {

        int oldColor = image[sr][sc];

        if (oldColor == color)
            return image;

        dfs(image, sr, sc, oldColor, color);
        
        return image;
    }
};