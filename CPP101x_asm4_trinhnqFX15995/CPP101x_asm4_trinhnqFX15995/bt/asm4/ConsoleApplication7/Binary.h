#pragma once
#include <iostream>
using namespace std;
class XeCuaT {
public:
	int maSoHI[8];// mảng mscn int để lưu vào file
	int giaTriMot, giaTriHai, giaTriBa;// ba giá trị vận tốc người dùng cần nhập vào
	int maSoHI3[8];// mảng giá trị mscn lấy từ file ra
	int mangVI[3];// mảng giá trị vận tốc (là int) để lưu vào trong file
	int mangVI2[3];// mảng giá trị vận tốc ( int) lấy từ file ra
	int mangDocChung[11];// mảng đọc tất cả các giá trị từ file
	XeCuaT(int gT1, int gT2, int gT3) {
		giaTriMot = gT1;
		giaTriHai = gT2;
		giaTriBa = gT3;
	}
	void kiemTraMSCN(bool giaTri, int &soKyTu);// hàm kiểm tra mscn
	void kiemTraV(bool giaTri2, int &soKyTuMot);// hàm kiểm tra vận tốc
	void luuFile();//lưu file

};