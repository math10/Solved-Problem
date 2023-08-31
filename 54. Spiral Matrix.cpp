class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int tot = m * n;
        vector<int>ans;

        int rLow = 0, cLow = 0;
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        int dir = 0;

        int x = 0, y = 0;
        ans.push_back(matrix[x][y]);
        --tot;
        while(tot) {
            int tmpX = x + dx[dir];
            int tmpY = y + dy[dir];
            if(tmpX >= rLow && tmpX < m
            && tmpY >= cLow && tmpY < n) {
                ans.push_back(matrix[tmpX][tmpY]);
                --tot;
                x = tmpX;
                y = tmpY;
            } else {
                switch(dir) {
                    case 0:
                        ++rLow;
                        break;
                    case 1:
                        --n;
                        break;
                    case 2:
                        --m;
                        break;
                    case 3:
                        ++cLow;
                        break;
                }
                dir = (dir + 1)%4;
            }
        }

        return ans;
    }
};
