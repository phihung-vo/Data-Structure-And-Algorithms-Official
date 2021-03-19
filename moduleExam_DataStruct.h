bool stopExam = false;
typedef struct {
	char tenDangNhap[15];
	char password[20];
}ACCOUNT;
typedef struct{
	int x;
	int y;
	int maxX;
	int maxY;
}OBJECR_LCT;

typedef struct{
	int minutes[10];
	int seconds;
}MINUTES;


typedef struct{
	int minutes;
	int seconds;
	int restSeconds;
}EXAMTIME;

typedef struct
{
	int id;
	char daD;
	char daC;
	float diem;
}CHT;

typedef struct
{
  CHT *cauHoiThi[MAX];
  int n;
 // int seconds;
  
}DETHI;
typedef struct {
    int day;
    int mon;
    int year;          
}TIME;
typedef struct {
    char masv[20];
	char mamh[MAXMMH];
	int slCauHoi;
    time_t seconds;     
    TIME time;
    EXAMTIME exameTime;        
}LOG;
typedef struct {
	char masv[MAXMSV];
	char mamh[MAXMMH];
    CHT cauHoiThi;
    
}CTT;



