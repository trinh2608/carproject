/*#include <stdio.h>
#include <fstream> // for ofstream,ifstream
#include <iostream>
#include <string>
using namespace std;
bool checkF(string path) {
	ifstream isf(path);
	return isf.good();
}

int main(){
	int skt = 0;
	int giatri = checkF("AMS03.dat");
	string mscn[8];
	string mscn2[8];
	int mshi[8];
	int mshi2[8];
	int mshi3[8];
	if (giatri == 0) {
		cout << "lan dau dang nhap" << endl;
		for (int i = 0; i < 8; i++) {
			do {
				skt = 0;
				cout << "SO THU " << i + 1 << ":";
				getline(cin, mscn[i]);
				cout << endl;
				if (mscn[i] >= "a" && mscn[i] <= "z" || mscn[i] >= "A" && mscn[i] <= "Z") {
					cout << "KHONG DUOC NHAP VAO KI TU, VUI LONG NHAP LAI" << endl;
					system("pause");
					skt = 1;
				}
				else { skt = 0; }
			} while (skt == 1 );
		}
		for (int i = 0; i < 8; i++) {
			mshi[i] = atoi(mscn[i].c_str());
		}


		ofstream ofile("AMS03.dat", ios_base::binary);
		if (ofile.is_open())
		{
			ofile.write((char*)mshi, sizeof(mshi));
			ofile.close();
		}
		else{
			std::cerr << "K mở được file" << std::endl;
		}
	}
	else{
		cout << "ban da cai dat mat khau, vui long nhap mat khau" << endl;
		for (int i = 0; i < 8; i++) {
			do {
				skt = 0;
				cout << "SO THU " << i + 1 << ":";
				getline(cin, mscn2[i]);
				cout << endl;
				if (mscn2[i] >= "a" && mscn2[i] <= "z" || mscn2[i] >= "A" && mscn2[i] <= "Z") {
					cout << "KHONG DUOC NHAP VAO KI TU, VUI LONG NHAP LAI" << endl;
					system("pause");
					skt = 1;
				}
				else { skt = 0; }
			} while (skt == 1 );
		}
		for (int i = 0; i < 8; i++) {
			mshi2[i] = atoi(mscn2[i].c_str());
		}
		ifstream file("AMS03.dat", ios::in | ios::binary);
		if (file.is_open()) {
			file.read((char*)mshi3, sizeof(mshi3));
			file.close();
		}
	}
	system("pause");
	return 0;
}*/



