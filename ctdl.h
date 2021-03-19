#include"define.h"
using namespace std;



//-----------------------DS MON HOC------------------------
typedef struct
{
	char mamh[MAXMMH];
	char tenmh[MAXTMH];
}MON;

typedef struct
{
  MON *mon[MAXOBJECT];
  int n;
}DSMON;
//----------------------NODE DIEM THI---------------------------
typedef struct
{
	char mamh[MAXMMH];
	float diem;
}DIEM;

struct nodediem
{
	DIEM diemthi;
	struct nodediem *next;
	
}; typedef struct nodediem *NODEDIEM;
//--------------NODE SINH VIEN------------------------
//khai bao cau truc sinh vien
typedef struct
{
	char masv[MAXMSV];//primary key
	char ho[MAXHOSV];
	char ten[MAXTENSV];
	char phai[MAXPHAI];
	char password[MAXPW];
	NODEDIEM	dsdiem;
}SINHVIEN;

struct nodesinhvien
{
	SINHVIEN sinhvien;
	struct nodesinhvien *next;
}; typedef struct nodesinhvien *NODESINHVIEN;

//------------------DS LOP HOC--------------------------
typedef struct 
{
	char malop[MAXML]; //primary key
	char tenlop[MAXTL];
	char  nienkhoa[MAXNK];
	NODESINHVIEN dssinhvien;
}LOP;
typedef struct
{
	int n;
	LOP *lop[MAXCLASS];
}DSLOP;
//--------------------DS CAU HOI --------------------------
typedef struct
{
	int id; //primary key
	char mamh[MAXMMH];
	char nd[MAX_QST_CNT];
	char a[MAX_ANS_CNT];
	char b[MAX_ANS_CNT];
	char c[MAX_ANS_CNT];
	char d[MAX_ANS_CNT];
	char da;
}CAUHOI;

struct nodecauhoi
{
	CAUHOI cauhoi;
	struct nodecauhoi *left;
	struct nodecauhoi *right;
}; typedef struct nodecauhoi *NODECAUHOI;

//------------------------Cau hoi Thi


//--------------------------DS bai kiem tra chi tiet cua SV------------------

typedef struct
{
	int chose[MAX],arr[MAX],slcauhoi;
	DIEM diems;
}detail;

