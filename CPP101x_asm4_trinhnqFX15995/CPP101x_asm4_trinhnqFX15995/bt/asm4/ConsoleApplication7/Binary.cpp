#include <iostream>
#include <fstream>
#include "Binary.h"
#include <string>
using namespace std;
// thuật toán sắp xếp selection sort( tìm ra giá trị nhỏ nhất và xếp nó lên đầu, sau đó tiếp tục vòng lặp với giá trị tiếp theo)
void sapXep(int arr[], int n) {
	int *p = &arr[0];
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				int temp = *(p + i);
				*(p + i) = *(p + j);
				*(p + j) = temp;
			}
		}
	}
}
// thuật toán sủi bọt (đổi chỗ 2 giá trị cạnh nhau, lặp lại cho đến khi mảng được sắp xếp đúng).
void noiBot(int arr[], int n) {
	bool ok = false;
	int *p = &arr[0];
	for (int i = 0; i < n - 1; i++) {
		ok = false;
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = *(p + j);
				*(p + j) = *(p + j + 1);
				*(p + j + 1) = temp;
				ok = true;
			}
		}
		if (ok == false) {
			break;
		}
	}
}

void XeCuaT::kiemTraMSCN(bool giaTri, int &soKyTu) {
	string maSoCaNhan[8];//mảng mscn người dùng nhập vào(cài đặt lần đầu), để string để kiểm tra xem nhập có phải số không hay chữ cái
	string maSoCaNhan2[8];// mảng mscn người dùng nhập vào các lần sau(string)
	int maSoHI2[8];// mảng giá trị mscn người dùng nhập vào các lần sau(int)
	int ketQua = 0;// biến cho biết 2 mảng nhập vào có giá trị giống nhau hay không
	do {
		if (giaTri == 0) {// lần đầu đăng nhập
			system("cls");
			cout << "LAN DAU DANG NHAP, VUI LONG CAI DAT MAT KHAU" << endl;
			// nhập mscn
			for (int i = 0; i < 8; i++) {
				do {
					soKyTu = 0;
					cout << "SO THU " << i + 1 << ":";
					cin >> maSoCaNhan[i];
					cout << endl;
					if (maSoCaNhan[i] >= "a" && maSoCaNhan[i] <= "z" || maSoCaNhan[i] >= "A" && maSoCaNhan[i] <= "Z") {
						cout << "KHONG DUOC NHAP VAO KI TU, VUI LONG NHAP LAI" << endl;
						system("pause");
						soKyTu = 1;
					}
					else { soKyTu = 0; }
				} while (soKyTu == 1);//  bị nhập lại nếu nhập phải kí tự không phải số
			}
			for (int i = 0; i < 8; i++) {
				maSoHI[i] = atoi(maSoCaNhan[i].c_str());
			}// đổi sang int để lưu vào trong file và lấy ra tiện so sánh cho dễ 
		}
		else {//không phải lần đầu đăng nhập
			system("cls");
			// nhập mscn2
			cout << "VUI LONG NHAP MAT KHAU" << endl;
			for (int i = 0; i < 8; i++) {
				do {
					soKyTu = 0;
					cout << "SO THU " << i + 1 << ":";
					cin >> maSoCaNhan2[i];
					cout << endl;
					if (maSoCaNhan2[i] >= "a" && maSoCaNhan2[i] <= "z" || maSoCaNhan2[i] >= "A" && maSoCaNhan2[i] <= "Z") {
						cout << "KHONG DUOC NHAP VAO KI TU, VUI LONG NHAP LAI" << endl;
						system("pause");
						soKyTu = 1;
					}
					else { soKyTu = 0; }
				} while (soKyTu == 1);
			}
			for (int i = 0; i < 8; i++) {
				maSoHI2[i] = atoi(maSoCaNhan2[i].c_str());// chuyển mscn2 sang int
			}
			// lấy hết tất cả từ file mangDocChung
			ifstream file("AMS04.dat", ios::in | ios::binary);
			if (file.is_open()) {
				file.read((char*)mangDocChung, sizeof(mangDocChung));
				file.close();
			}
			// in ra mảng nhập vào trước khi sắp xếp
			cout << "MANG NHAP VAO TRUOC KHI SAP XEP: ";
			for (int i = 0; i < 8; i++) {
				cout << maSoHI2[i] << " ";
			}
			cout << endl;
			noiBot(maSoHI2, 8);// in ra sắp xếp nổi bọt của mã số nhập vào
			cout << "MANG NHAP VAO SAU KHI SAP XEP: ";
			for (int i = 0; i < 8; i++) {
				cout << maSoHI2[i] << " ";
			}
			cout << endl;
			// gán mã số có sẵn được lấy ra từ mangDocChung vào mảng mã số có sẵn MaSoHI3
			for (int i = 0; i < 8; i++) {
				maSoHI3[i] = mangDocChung[i];
				maSoHI[i] = maSoHI3[i];
			}
			// tương tự như vậy với mã số có sẵn
			sapXep(maSoHI3, 8);
			// kiểm tra xem 2 mã số có giống nhau không, đúng thì kết quả trả về giá trị 0.
			for (int i = 0; i < 8; i++) {
				if (maSoHI2[i] == maSoHI3[i]) {
					ketQua = 0;
				}
				else {
					ketQua = 1;
				}
			}
			cout << endl;
			// 2 mảng có giá trị bằng nhau thì đăng nhập thành công
			if (ketQua == 0) {
				char answer;// biến hỏi xem có muốn  thay đổi mk hay không
				cout << "DANG NHAP THANH CONG" << endl;
				cout << "BAN CO MUON THAY DOI MAT KHAU KHONG (y/n)? (NHAP y HOAC n)" << endl;// hỏi người dùng có muốn đổi mk không
				do {
					cin >> answer;
				} while (answer != 'y'&& answer != 'n');// buộc phải chon y hoặc n
														// nếu muốn đổi mk
				if (answer == 'y') {

					system("cls");
					cout << " VUI LONG CAI DAT LAI MAT KHAU" << endl;
					for (int i = 0; i < 8; i++) {
						do {
							soKyTu = 0;
							cout << "SO THU " << i + 1 << ":";
							cin >> maSoCaNhan[i];
							cout << endl;
							if (maSoCaNhan[i] >= "a" && maSoCaNhan[i] <= "z" || maSoCaNhan[i] >= "A" && maSoCaNhan[i] <= "Z") {
								cout << "KHONG DUOC NHAP VAO KI TU, VUI LONG NHAP LAI" << endl;
								system("pause");
								soKyTu = 1;
							}
							else { soKyTu = 0; }
						} while (soKyTu == 1);
					}
					for (int i = 0; i < 8; i++) {
						maSoHI[i] = atoi(maSoCaNhan[i].c_str());
					}
				}
			}
			// sai mật khẩu 
			if (ketQua == 1) {
				cout << "DANG NHAP THAT BAI DO NHAP SAI MAT KHAU, VUI LONG NHAP LAI" << endl;
			}
		}
		system("pause");
	} while (ketQua == 1);// vòng lặp luôn lặp lại khi phát hiện có kí tự hoặc 2 mảng có giá trị không giống nhau
}



void XeCuaT::kiemTraV(bool giaTri2,int&soKyTuMot){
	string mangV[3];// mảng chứa các giá trị vận tốc người dùng nhập vào, để string để kiểm tra xem người dùng có gán giá trị chữ cho vận tốc hay không.
	int k = 0;// biến kiểm tra xem giá trị dải vận tốc người dùng nhập vào có hợp lệ hay không 
	if (giaTri2 == 0) {// lần đầu đăng nhập
		system("cls");
		cout << "LAN DAU DANG NHAP, VUI LONG CAI DAT GIA TRI MUC VAN TOC CANH BAO" << endl;
		// nhập vận tốc cảnh báo, sẽ phải nhập lại nếu nhập vào kí tự hoặc nhập giá trị không hợp lệ
		do {
			k = 0;
			for (int i = 0; i < 3; i++) {
				do {
					soKyTuMot = 0;
					cout << "SO THU " << i + 1 << ":";
					cin >> mangV[i];
					cout << endl;
					if (mangV[i] >= "a" && mangV[i] <= "z" || mangV[i] >= "A" && mangV[i] <= "Z") {
						cout << "KHONG DUOC NHAP VAO KI TU, VUI LONG NHAP LAI" << endl;
						system("pause");
						soKyTuMot = 1;
					}
					else { soKyTuMot = 0; }

				} while (soKyTuMot == 1);
			}
			giaTriMot = atoi(mangV[0].c_str());
			giaTriHai = atoi(mangV[1].c_str());
			giaTriBa = atoi(mangV[2].c_str());
			// nếu giá trị không hợp lệ
			if (giaTriMot >= giaTriHai || giaTriMot >= giaTriBa || giaTriHai >= giaTriBa || giaTriBa > 150 || giaTriMot < 10) {
				system("cls");
				cout << "GIA TRI NHAP VAO KHONG HOP LE, VUI LONG NHAP LAI" << endl;
				k = 1;
				system("pause");
			}
		} while (k == 1);
		// chuyển đổi sang int để lưu vào trong file cho dễ
		for (int i = 0; i < 3; i++) {
			mangVI[i] = atoi(mangV[i].c_str());
		}
	}

	else {// lần thứ 2 đăng nhập trở đi
		char answer2;// biến hỏi xem có muốn thay đổi giá trị vận tốc hay không
					 // lấy giá trị trong file và gán vào mảng mvi2
		ifstream file2("AMS04.dat", ios::in | ios::binary);
		if (file2.is_open()) {
			file2.read((char*)mangDocChung, sizeof(mangDocChung));
			file2.close();
		}
		for (int i = 8; i < 11; i++) {
			mangVI2[i - 8] = mangDocChung[i];
			mangVI[i - 8] = mangVI2[i - 8];
		}
		giaTriMot = mangVI2[0];
		giaTriHai = mangVI2[1];
		giaTriBa = mangVI2[2];// 3 giá trị vận tốc được gán vào 3 biến phục vụ về sau 
		system("cls");
		// hỏi xem muốn thay đổi vận tốc ko
		cout << "BAN DA CAI DAT DAI VAN TOC, BAN CO MUON THAY DOI KHONG? (y/n)";
		do {
			cin >> answer2;
		} while (answer2 != 'y'&& answer2 != 'n');
		// nếu muốn thay đổi vận tốc
		if (answer2 == 'y') {
			do {
				system("cls");
				cout << " VUI LONG CAI DAT LAI DAI VAN TOC" << endl;
				k = 0;
				for (int i = 0; i < 3; i++) {
					do {
						soKyTuMot = 0;
						cout << "SO THU " << i + 1 << ":";
						cin >> mangV[i];
						cout << endl;
						if (mangV[i] >= "a" && mangV[i] <= "z" || mangV[i] >= "A" && mangV[i] <= "Z") {
							cout << "KHONG DUOC NHAP VAO KI TU, VUI LONG NHAP LAI" << endl;
							system("pause");
							soKyTuMot = 1;
						}
						else { soKyTuMot = 0; }

					} while (soKyTuMot == 1);
				}
				giaTriMot = atoi(mangV[0].c_str());
				giaTriHai = atoi(mangV[1].c_str());
				giaTriBa = atoi(mangV[2].c_str());
				// nếu giá trị không hợp lệ
				if (giaTriMot >= giaTriHai || giaTriMot >= giaTriBa || giaTriHai >= giaTriBa || giaTriBa > 150 || giaTriMot < 10) {
					cout << "GIA TRI NHAP VAO KHONG HOP LE, VUI LONG NHAP LAI" << endl;
					k = 1;
					system("pause");
				}
			} while (k == 1);
			for (int i = 0; i < 3; i++) {
				mangVI[i] = atoi(mangV[i].c_str());
			}
		}
	}
}
void XeCuaT::luuFile() {
	// lưu mscn vào file 
	ofstream ofile("AMS04.dat", ios_base::binary);
	if (ofile.is_open()){
		ofile.write((char*)maSoHI, sizeof(maSoHI));
		ofile.close();
	}
	// lưu v vào file 
	ofstream ofile2("AMS04.dat", ios_base::binary | ios::app);
	if (ofile2.is_open()){
		ofile2.write((char*)mangVI, sizeof(mangVI));
		ofile2.close();
	}
}


// lưu giá trị vào file
