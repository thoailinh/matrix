//Cài đặt một số thao tác cơ bản trên một đồ thị vô hướng.
//
//INPUT
//Dòng đầu tiên chứa 03 số v, e và n, đây lần lượt là số đỉnh, số cạnh của đồ thị cùng với số thao tác xử lý, giá trị mỗi số không quá 1 tỷ.
//
//e dòng tiếp theo, mỗi dòng chứa 02 số u và i, thể hiện việc có một cạnh nối từ đỉnh thứ u sang đỉnh thứ i trong đồ thị(thứ tự các cạnh được đánh số từ 1...v)
//
//n dòng tiếp theo, mỗi dòng tương ứng với một trong các thao tác xử lý các thao tác có cú pháp như sau :
//
//Thao tác kiểm tra tính kề của 02 đỉnh, dòng này bắt đầu bằng số 1, theo sau là 02 số u và i.
//Thao tác tìm kiếm đỉnh lân cận của 01 đỉnh, dòng này bắt đầu bằng số 2, theo sau là số u
//OUTPUT
//Ứng với thao tác kiểm tra tính kề của 02 đỉnh, xuất ra màn hình chuỗi TRUE nếu đỉnh thứ u kề với đỉnh thứ i.Nếu đỉnh thứ u không kề với đỉnh thứ i xuất ra chuỗi FALSE
//
//Ứng với thao tác tìm kiếm đỉnh lân cận của 02 đỉnh, xuất ra màn hình trên cùng một dòng thứ tự của các đỉnh kề với đỉnh thứ u, các đỉnh xuất theo thứ tự tăng dần, cách nhau bởi khoảng trắng.Nếu không có đỉnh nào kề với đỉnh thứ u xuất ra chuỗi NONE
#include<iostream>
using namespace std;
int main()
{
	int v, e, n, u, i;
	cin >> v;
	cin >> e;
	cin >> n;
	bool **a;
	a = new bool*[v];
	for (int i = 0; i < v; i++) {
		a[i] = new bool[v];
		for (int j = 0; j < v; j++)
			a[i][j] = 0;
	}
	for (int k = 0; k < e; k++) {
		cin >> u >> i;
		u--;
		i--;
		a[u][i] = 1;
		a[i][u] = 1;
	}
	for (int k = 0; k < n; k++) {
		int x;
		cin >> x;
		if (x == 1) {
			cin >> u >> i;
			u--;
			i--;
			if (a[u][i] == 1 || a[i][u]==1)
				cout << "TRUE" << endl;
			else 
				cout << "FALSE" << endl;

		}
		else {
			cin >> u;
			u--;
			int kiemtra = 0;
			for (int i = 1; i <= v; i++) {
				if (a[u][i - 1] == 1 && a[i-1][u]==1)
				{
					kiemtra = 1;
					cout << i << "  ";
				}
			}
			if (kiemtra == 0) cout << "NONE";
			cout << endl;
		}
	}
	//system("pause");
	return 0;
}