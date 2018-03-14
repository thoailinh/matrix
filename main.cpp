// MATRIX STRING
//Cài đặt một số thao tác cơ bản trên một đồ thị hữu hướng, mỗi đỉnh của đồ thị được đặt tên.
//INPUT
//Dòng đầu tiên chứa 03 số v, e và n, đây lần lượt là số đỉnh, số cạnh của đồ thị cùng với 
//số thao tác xử lý, giá trị mỗi số không quá 1 tỷ.
//Dòng tiếp theo chứa v chuỗi, mỗi chuỗi bao một hoặc nhiều ký tự hoa trong bảng chữ cái 
//Tiếng Anh và cách nhau bởi khoảng trắng.Đây là danh sách tên các đỉnh của đồ thị.
//e dòng tiếp theo, mỗi dòng chứa 02 chuỗi u và i(cách nhau bởi khoảng trắng), thể hiện việc 
//có một cạnh nối từ đỉnh u sang đỉnh i trong đồ thị.
//n dòng tiếp theo, mỗi dòng tương ứng với một thao tác xử lý các thao tác có cú pháp như sau :
//Thao tác kiểm tra tính kề của 02 đỉnh, dòng này bắt đầu bằng số 1, theo sau là 02 chuỗi u và i 
//cách nhau bởi khoảng trắng
//Thao tác tìm kiếm đỉnh lân cận của 01 đỉnh, dòng này bắt đầu bằng số 2, theo sau là chuỗi u
//OUTPUT
//Ứng với thao tác kiểm tra tính kề của 02 đỉnh, xuất ra màn hình chuỗi TRUE nếu đỉnh u kề với
//đỉnh i.Nếu đỉnh u không kề với đỉnh i xuất ra chuỗi FALSE
//Ứng với thao tác tìm kiếm đỉnh lân cận của 02 đỉnh, xuất ra màn hình trên cùng một 
//dòng danh sách các đỉnh kề với đỉnh u, các đỉnh xuất theo thứ tự trong danh sách đỉnh ở 
//dòng thứ 02 của input và cách nhau bởi khoảng trắng.Nếu không có đỉnh nào kề với đỉnh u 
//xuất ra chuỗi NONE
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