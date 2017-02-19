#include <vector>
#include <iostream>
using namespace std;

vector<int> spiralOrder(vector< vector<int> > &matrix) {
	// 01. init
	vector< vector<int> > dir{{0,1}, {1,0}, {0,-1}, {-1,0}};
	vector<int> dir_cnt, result;

	if (matrix.size() == 0)    return vector<int>();
	dir_cnt.push_back(matrix[0].size());
	dir_cnt.push_back(matrix.size() - 1);

	int fill=0, area = dir_cnt[0]*(dir_cnt[1] + 1);
	int i=0, j=-1, iDir = 0;   // initial posision & direction

	// 02. filling loop
	while(fill < area){
		// go for each direction
		for (int _=0; _ < dir_cnt[iDir%2]; _++){
			i += dir[iDir][0];
			j += dir[iDir][1];
			result.push_back(matrix[i][j]);
		}
		fill += dir_cnt[iDir%2];
		dir_cnt[iDir%2]--;
		iDir = (iDir + 1)%4;
	}
	return result;
}

int main(){
	vector< vector<int> > m{{1,2,3},{4,5,6},{7,8,9}};
	for (int i : spiralOrder(m))
		cout << i << " ";
	return 0;
}
