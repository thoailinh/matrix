// MATRIX STRING 
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(int argc, int argv[])
{
	int v, e, n;
	short key;
	cin >> v >> e >> n;

	vector<string> vertexName;
	typedef vector<bool> bvt;
	vector<vector<bool>> matrix(v, bvt(v, 0));
	map<string, int> mapVertex;
	string str1, str2;
	for (int i = 0; i < v; i++)
	{
		cin >> str1;
		vertexName.push_back(str1);
		mapVertex[str1] = i;
	}

	for (int i = 0; i < e; i++)
	{
		cin >> str1 >> str2;
		matrix[mapVertex[str1]][mapVertex[str2]] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		cin >> key;
		switch (key)
		{
		case 1:
		{
			cin >> str1 >> str2;
			if (matrix[mapVertex[str1]][mapVertex[str2]] == 1)
				cout << "TRUE";
			else
				cout << "FALSE";
			break;
		}
		default:
		{
			bool flag = 0;
			cin >> str1;
			for (int k = 0; k < v; k++)
			{
				if (matrix[mapVertex[str1]][k] == 1)
				{
					flag = 1;
					cout << vertexName[k] << " ";
				}
			}
			if (flag == 0)
				cout << "NONE";
		}
		}
		cout << endl;
	}
	system("pause");
	return 0;
}