#include<iostream>
#include<vector>
#include<string>

#pragma warning(disable: 4996)

using namespace std;

//--------------class KhachHang----------------
class KhachHang {
private:
    string _hoten;
    string _cmnd;
    string _diachi;
public:
    void Nhap();
    void Xuat();
};

void KhachHang::Nhap() {
    cout << "Nhap ho ten: ";
    getline(cin, _hoten);
    cout << "Nhap CMND: ";
    getline(cin, _cmnd);
    cout << "Nhap dia chi: ";
    getline(cin, _diachi);
}

void KhachHang::Xuat() {
    cout << "Ho ten: " << _hoten << endl;
    cout << "CMND: " << _cmnd << endl;
    cout << "Dia chi: " << _diachi << endl;
}

//--------------class GoiCuocBasic----------------
class GoiCuocBasic {
protected:
    float _thoigiangoi;
    float _luuluongtruycap;
    float _tiencuocthuebao;
public:
    virtual void Nhap();
    virtual void Xuat();
    float CuocTong();
};

void GoiCuocBasic::Nhap() {
    cout << "Nhap thoi gian goi: ";
    cin >> _thoigiangoi;
    cout << "Nhap luong luong truy cap: ";
    cin >> _luuluongtruycap;
}

void GoiCuocBasic::Xuat() {
    cout << "Thoi gian goi: " << _thoigiangoi << endl;
    cout << "Luong luong truy cap: " << _luuluongtruycap << endl;
}

float GoiCuocBasic::CuocTong() {
    float cuocdienthoai = _thoigiangoi * 1000;
    float cuocinternet = _luuluongtruycap * 200;
    float temp = cuocdienthoai + cuocinternet;
    return temp + temp * 0.1;
}

//--------------class GoiCuocDataFree----------------
class GoiCuocDataFree : public GoiCuocBasic {
private:
    float _luuluongtruycapmienphi;
public:
    void Nhap();
    void Xuat();
    float CuocTong();
};

void GoiCuocDataFree::Nhap() {
	GoiCuocBasic::Nhap();
	cout << "Nhap luong luong truy cap mien phi: ";
	cin >> _luuluongtruycapmienphi;
}

void GoiCuocDataFree::Xuat() {
	GoiCuocBasic::Xuat();
	cout << "Luong luong truy cap mien phi: " << _luuluongtruycapmienphi << endl;
}


float GoiCuocDataFree::CuocTong() {
    // 100MB lưu lượng truy cập miễn phí, 120MB
    float cuocdienthoai = _thoigiangoi * 1000;
    if (_luuluongtruycapmienphi <= _luuluongtruycap) {
        return (_luuluongtruycap - _luuluongtruycapmienphi) * 200 + _tiencuocthuebao;
    }
    else {
        return _tiencuocthuebao;
    }
}

//--------------class GoiCuocDataFix----------------
class GoiCuocDataFix : public GoiCuocBasic {
public:
    float CuocTong();
};

float GoiCuocDataFix::CuocTong() {
	// 100MB lưu lượng truy cập miễn phí, 120MB
	float cuocdienthoai = _thoigiangoi * 1000 * 0.9;
    float cuocinternet = 1000000;
    return cuocdienthoai + cuocinternet + cuocinternet * 0.1;
}

//--------------class HopDong----------------
class HopDong {
private:
    KhachHang* _kh;
    GoiCuocBasic* _gc;
public:
    void Nhap();
    float TinhTienCuoc();
    void ThongBaoCuoc();
};

void HopDong::Nhap() {
    _kh = new KhachHang();
    _kh->Nhap();
    int loaigc;
    cout << "Nhap loai goi cuoc: ";
    cin >> loaigc;
    if (loaigc == 1) {
        _gc = new GoiCuocBasic();
    }
    else if (loaigc == 2) {
        _gc = new GoiCuocDataFree();
    }
    else {
        _gc = new GoiCuocDataFix();
    }
    _gc->Nhap();
}

float HopDong::TinhTienCuoc() {
    return _gc->CuocTong();
}

void HopDong::ThongBaoCuoc() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    cout << (ltm->tm_year + 1900) << "-"
        << (ltm->tm_mon + 1) << "-"
        << ltm->tm_mday;
    // Cuối tháng ngày 28 sẽ thông báo cước cho khác hàng.
    if (ltm->tm_mday == 28) {
        cout << "Ban da den ngay dong tien: \n";
        cout << TinhTienCuoc() << endl;
    }
    // kịp thời gian xét năm nhuận và tất cả các tháng
}

//--------------class CongTy----------------
class CongTy {
private:
    vector<HopDong*> _dsHopDong;
public:
    void Nhap();
    void Xuat();
    float TongTien();
};

void CongTy::Nhap() {
    int n;
    cout << "Nhap so luong hop dong: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        HopDong* hd = new HopDong();
        hd->Nhap();
        _dsHopDong.push_back(hd);
    }
}

void CongTy::Xuat() {
    for (int i = 0; i < _dsHopDong.size(); i++) {
        _dsHopDong[i]->ThongBaoCuoc();
    }
}



float CongTy::TongTien() {
    float tongtien = 0;
    for (int i = 0; i < _dsHopDong.size(); i++) {
        _dsHopDong[i]->ThongBaoCuoc();
        tongtien += _dsHopDong[i]->TinhTienCuoc();
    }
    return tongtien;
}

int main() {

    time_t t = time(0);
    tm* now = localtime(&t);
    cout << (now->tm_year + 1900) << "-"
        << (now->tm_mon + 1) << "-"
        << now->tm_mday << endl;

    return 0;
}

// Lấy hàm thời gian trong hệ thống để ra được ngày tháng năm, do không nhớ cú pháp nên em sử dụng theo cách bên dưới
// Sau đó gán cho các biến như sau
// int day = time_day; (time_day là ngày hệ thống)
// int month = time_month; (time_month là tháng hệ thống)


// 1.Random (a-b)
// 2.Thời gian hệ thống, ngày, tháng, năm
// 3.Một số hàm di chuyển trong tập tin
// 4.Một số hàm hỗ trợ sort,....