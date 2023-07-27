#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include "Binary.h"
using namespace std;

// check xem có tồn tại file hay không
bool checkF(string path) {
	ifstream isf(path);
	return isf.good();
}
// màn hình 2, hiển thị các lựa chọn sau khi nhập đúng msd
void manHinhHai() {
	system("cls");
	cout << "XIN CHAO: 12345678 " << endl;
	cout << "XIN MOI LUA CHON:" << endl;
	cout << "1. P" << endl;
	cout << "2. R" << endl;
	cout << "3. N" << endl;
	cout << "4. D" << endl;
	cout << "5. POWER OFF" << endl;
}
// màn hình 3 ( số N và số P), sử dụng kiểu dữ liệu hàm là int vì cần giữ lại giá trị v để tương tác giữa các số N P R D
int manHinhBa(string choice,int v){
	system("cls");
    // số N
	if (choice == "3") {
		// kiểm tra về số phải có vận tốc bằng 0
		if(v == 0){
		    cout << "DA VE SO N. CHU Y PHANH TAY " << endl<< endl; 
		}
		else {
			cout << "HAY CHAC CHAN VAN TOC XE LA 0 KM/H" << endl << endl;
		}
		cout << "XIN MOI LUA CHON:" << endl;
		cout << "1. P" << endl;
		cout << "2. R" << endl;
		cout << "3. N" << endl;
		cout << "4. D" << endl;
		cout << "5. POWER OFF" << endl;
	}
    // số P
	if (choice == "1") {
		// tương tự trên
		if (v == 0) {
			cout << "DA VE SO P. CHU Y PHANH TAY " << endl << endl;
		}
		else {
			cout << "HAY CHAC CHAN VAN TOC XE LA 0 KM/H" << endl << endl;
		}
		cout << "XIN MOI LUA CHON:" << endl;
		cout << "1. P" << endl;
		cout << "2. R" << endl;
		cout << "3. N" << endl;
		cout << "4. D" << endl;
		cout << "5. POWER OFF" << endl;
	}
	system("pause");
	cout << "NHAN BAT CU PHIM NAO DE TIEP TUC" << endl; 
	return v;
}
// màn hình 4 (số R và D), sử dụng kiểu dữ liệu hàm là int vì cần giữ lại giá trị v để tương tác giữa các số N P R D
int manHinhBon(string choice, int v, int giaTriMot, int giaTriHai, int giaTriBa){
	string choice1; // lựa chọn tăng giảm tốc, phanh và trở về menu
	system("cls");
    // số R ( choice =2)
	if (choice == "2") {
		// kiểm tra vận tốc bằng 0 khi chuyển số 
		if (v > 0) {
			cout << "CHU Y VAN TOC PHAI BANG 0 KHI CHUYEN SO" << endl;
			system("pause");
		}
		else {
			// sử dụng hàm do để cho phép nhập tiếp các giá trị sau mỗi chọn, trừ trường hợp người dùng muốn trở về menu (choice1 = 4)
			do {
				// khởi tạo vận tốc bằng 7, và sau mỗi vòng lặp, nếu vận tốc lớn hơn 7 thì phải giữ nguyên vận tốc
				if (v < -7) {
					v = v;
				}
				if ((choice1 == "3"&& v == 0) || (choice1 == "2"&&v == 0)) {
					v = 0;
				}
				if (choice1 != "3" && choice1 != "2" && (v == -7 || v == 0)) {
					v = -7;
				}
				system("cls");
				// in ra các giá trị cảnh báo
				if (v <= -20) {
					cout << "TOC DO NGUY HIEM, BAN NEN GIAM TOC DO" << endl;
				}
				if (-v < giaTriMot) {
					cout << "BAN CHU Y GIU KHOANG CACH TOI THIEU 20m" << endl;
				}
				if (-v < giaTriHai && -v >= giaTriMot) {
					cout << "BAN CHU Y GIU KHOANG CACH TOI THIEU 55m" << endl;
				}
				if (-v < giaTriBa&&-v >= giaTriHai) {
					cout << "BAN CHU Y GIU KHOANG CACH TOI THIEU 70m" << endl;
				}
				if (-v >= giaTriBa) {
					cout << "BAN CHU Y GIU KHOANG CACH TOI THIEU 100m" << endl;
				}
				// nhập và kiểm tra giá trị choice1 xem có phù hợp không
				do {
					cout << "DA VE SO R. " << endl << endl;
					cout << "TOC DO HIEN TAI LA:  " << -v << " KM/H" << endl;
					cout << "MOI LUA CHON:" << endl;
					cout << "1. TANG TOC" << endl;
					cout << "2. GIAM TOC" << endl;
					cout << "3. PHANH" << endl;
					cout << "4. TRO VE MENU" << endl;
					int soKyTuMot = 0;
					cin >> choice1;
					for (int i = 0; i < choice1.length(); i++) {
						if (choice1[i] >= 'a' && choice1[i] <= 'z' || choice1[i] >= 'A' && choice1[i] <= 'Z') {
							soKyTuMot = 1;
						}
					}
					if (soKyTuMot == 1) {
						system("cls");
						cout << "GIA TRI NHAP VAO PHAI LA SO, VUI LONG NHAP LAI" << endl;
					}
				} while (choice1 != "1" && choice1 != "2" && choice1 != "3" && choice1 != "4");
				// tăng tốc
				if (choice1 == "1") {
					v -= 5;
				}
				// giảm tốc
				if (choice1 == "2") {
					v += 5;
					if (v > 0) {
						v = 0;
					}

				}
				// phanh
				if (choice1 == "3") {
					v = 0;
				}
				// hiển thị thông báo nếu tốc độ trên 20 km/h
			} while (choice1 != "4");// nếu choice1 là 4 thì sẽ thoát khỏi vòng lặp, trở về menu
		}
    }
    // nếu choice là 4 thì là số D
    if (choice == "4") {
		// tương tự ở trên
		if (v < 0) {
			cout << "CHU Y VAN TOC PHAI KHAC 0 KHI CHUYEN SO" << endl;
			system("pause");
		}
		else {
			// sử dụng do tương tự khi choice = 2 ở trên.
			do {
				if (v > 7) {
					v = v;
				}
				if ((choice1 == "3"&& v == 0) || (choice1 == "2"&&v == 0)) {
					v = 0;
				}
				if (choice1 != "3" && choice1 != "2" && (v == 7 || v == 0)) {
					v = 7;
				}
				system("cls");
				// nếu tốc độ cao, hiện thông báo 
				if (v >= 60) {
					cout << "TOC DO NGUY HIEM, BAN NEN GIAM TOC DO" << endl;
				}
				if (v < giaTriMot) {
					cout << "BAN CHU Y GIU KHOANG CACH TOI THIEU 20m" << endl;
				}
				if (v < giaTriHai &&v >= giaTriMot) {
					cout << "BAN CHU Y GIU KHOANG CACH TOI THIEU 55m" << endl;
				}
				if (v < giaTriBa &&v >= giaTriHai) {
					cout << "BAN CHU Y GIU KHOANG CACH TOI THIEU 70m" << endl;
				}
				if (v >= giaTriBa) {
					cout << "BAN CHU Y GIU KHOANG CACH TOI THIEU 100m" << endl;
				}
				// nhập và kiểm tra xem lựa chọn có phù hợp không
				do {
					cout << "DA VE SO D. " << endl << endl;
					cout << "TOC DO HIEN TAI LA:  " << v << " KM/H" << endl;
					cout << "MOI LUA CHON:" << endl;
					cout << "1. TANG TOC" << endl;
					cout << "2. GIAM TOC" << endl;
					cout << "3. PHANH" << endl;
					cout << "4. TRO VE MENU" << endl;
					int soKyTuMot = 0;
					cin >> choice1;
					for (int i = 0; i < choice1.length(); i++) {
						if (choice1[i] >= 'a' && choice1[i] <= 'z' || choice1[i] >= 'A' && choice1[i] <= 'Z') {
							soKyTuMot = 1;
						}
					}
					if (soKyTuMot == 1) {
						system("cls");
						cout << "GIA TRI NHAP VAO PHAI LA SO, VUI LONG NHAP LAI" << endl;
					}
				} while (choice1 != "1" && choice1 != "2" && choice1 != "3" && choice1 != "4");
				// tăng tốc
				if (choice1 == "1") {
					v += 5;
				}
				// giảm tốc
				if (choice1 == "2") {
					v -= 5;
					if (v < 0) {
						v = 0;
					}

				}
				// phanh 
				if (choice1 == "3") {
					v = 0;
				}
			} while (choice1 != "4");// nếu choice là 4 thì sẽ thoát khỏi vòng lặp (trở về menu chính)
		}
	}
	return v;
}

// hàm main.
int main() {
	XeCuaT Porsche(0, 0, 0);
	int soKyTuMot = 0;// biến cho biết có kí tự hay không ở phần nhập dải vận tốc
	//int giaTriMot, giaTriHai, giaTriBa;// 3 giá trị dải vận tốc người dùng cần nhập
	int soKyTu = 0;// biến cho biết có kí tự hay không ở hàm nhập mã số
	string choice;// lựa chọn ở màn hình 2
	int v = 0;// vận tốc
	int giaTri = checkF("AMS04.dat");//check xem file có tồn tại không, biết được đây có phải lần đầu đăng nhập hay không
	// sử dụng hàm do để nhập mã số cá nhân
	Porsche.kiemTraMSCN(giaTri, soKyTu);// nhập MSCN và kiểm tra
	///////////////////////////////
	Porsche.kiemTraV(giaTri, soKyTuMot);   // nhập mức vận tốc cảnh báo, và kiểm tra xem nhập có hợp lệ không 
	Porsche.luuFile();//lưu lại giá trị mã số và vận tốc
	// khởi đầu với màn hình 2, sau đó kiểm tra các giá trị nhập vào để phù hợp với các số
	do{
		do {
			manHinhHai();
			int soKyTu = 0;
		    cin >> choice;
			for (int i = 0; i < choice.length(); i++) {
				if (choice[i] >= 'a' && choice[i] <= 'z' || choice[i] >= 'A' && choice[i] <= 'Z') {
					soKyTu = 1;
				}
			}
			if (soKyTu == 1) {
				system("cls");
				cout << "GIA TRI NHAP VAO PHAI LA SO, VUI LONG NHAP LAI" << endl;
				system("pause");
			}
		} while (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5");

	    if(choice == "3" || choice == "1"){
			v = manHinhBa(choice, v);
	    }
	    else if (choice ==  "4" || choice == "2") {
			v = manHinhBon(choice, v, Porsche.giaTriMot, Porsche.giaTriHai, Porsche.giaTriBa);
	    }
	} while (choice != "5");// choice bằng 5 thì thoát vòng lặp, tắt máy

	if (choice == "5") {
		cout << "DANG TAT MAY! CAM ON" << endl;
		system("pause");
	}
	return 0;
}