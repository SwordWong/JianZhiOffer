#include <vector>
using namespace std;
namespace printMatrix{
    class Solution {
    public:
        vector<int> printMatrix(vector<vector<int> > matrix) {
            vector<int> res;
            printMat(matrix, res, 0, 0, matrix[0].size(), matrix.size());
            return res;
        }
    private:
        void printMat(const vector<vector<int>> &mat, vector<int> & res, int sx, int sy, int x_size, int y_size){
            if(x_size <= 0 || y_size <= 0)
                return;
            int x = sx;
            int y = sy - 1;
            for(int i = 0; i < x_size; i++)
                res.push_back(mat[x][++y]);
            for(int i = 0; i < y_size - 1; i++)
                res.push_back(mat[++x][y]);
			if(y_size > 1)
				for(int i = 0; i < x_size - 1; i++)
					res.push_back(mat[x][--y]);
			if(x_size > 1)
				for(int i = 0; i < y_size - 2; i++)
					res.push_back(mat[--x][y]);
            printMat(mat, res, sx + 1, sy + 1, x_size - 2, y_size - 2);
        }
    };
}