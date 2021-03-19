#include"moduleExam_DataStruct.h"
//----Function for services
void backSpace(int x,int y);
int random(int maxN,int minN);
void clearPartOfScreen(int x,int y,int endX,int endY);
void makeLogFile();
int showStringInLocation(char nd[1000],int x,int y,int end);
void clearPartOfScreen(int x,int y,int endX,int endY);
void clearPartOfScreenButNoClock(int x,int y,int endX,int endY);
void wait ( int seconds );
int convertIntFromChar(char c);
//FunctionForHelper
CAUHOI invertAnswer(CAUHOI cauHoi,int tickNumber);
int randomMark(int id,int slc);
int randomAnswerTickNumber(char da,int id);
int ConvertAnswerToconvertTickNumber(char da);
char convertTickNumberToAnswer(int tickNumber);
bool checkNullArr(char arr[]);
void makeIdFile();
int getIdQuestionFromFile();
//----Function for Login
ACCOUNT module_Login(int x,int y);
ACCOUNT  getLoginInfo(int x,int y);

//----Function for Exam
int  userManual_DoExam();
void makeDSMonForShowDetail(DSMON *dsmonAll,DSMON *dsmonExam,SINHVIEN sv);
int  bangMonThi(DSMON *dsmon);
int inMonThi(int tick, DSMON *dsmon,int arrow);
int  Inorder_Count_Filter(NODECAUHOI root,CAUHOI cauHoi[],char mamon[MAXMMH]);
CAUHOI SearchTree (NODECAUHOI root, int id);
int getRequestExam(NODECAUHOI dscauhoi,CAUHOI mangCHTmp[],MON monThi ,int &slc,int &sP);
int moduleThi(DSLOP *dslop,NODECAUHOI dscauhoi,char masv[MAXMSV],
							char hoSv[MAXHOSV],char tenSV[MAXTENSV],MON monThi);
int moduleThiForTeacher(DSLOP *dslop,NODECAUHOI dscauhoi,char masv[MAXMSV],
							char hoSv[MAXHOSV],char tenSV[MAXTENSV],MON monThi);
int makeIdArray();
void loadThoiGianThi(EXAMTIME &examTime);
void initExamTime(EXAMTIME &examTime);
int getRequestExam( char tenmh[MAXTMH],int &slc,int &sP);
void initDethi(DETHI *dethi,CAUHOI mangCauHoi[MAX],int slc);
void makeExam(DETHI *dethi,CAUHOI mangCauHoi[MAX],bool thiLai,int slc,char masv[20]);
int getRestExamTime();
float lamTronDiem(float x);

//----Function for DetailExam
int  showDetailExamOfStudentData(NODECAUHOI dscauhoi,char masv[MAXMSV],char mamh[MAXMMH]);
void showMarkOfClass(DSLOP *dslop,DSMON *dsmon,NODECAUHOI dscauhoi);
OBJECR_LCT printfDetailExamOfStudentData(CTT ctt[MAX_QUESTION_AMOUNT],CAUHOI cauHoi [MAX_QUESTION_AMOUNT],int count);
void saveDetailExamOfStudent(DETHI deThi,char masv[MAXMSV],char mamh[MAXMMH]);
int moduleDetailExam(NODECAUHOI dscauhoi,DSMON *dsmon,DSLOP *dslop);
//void ghiLaiTrangThaiThi(EXAMTIME examTime);
int getRestExamTime();
bool checkIfAnswerClean(char c[3]);
bool checkIfAnswerIsTrueCharacter(char c[3]);//dung la abcd
bool checkIfAnswerOnlyCharacter(char c);//chi chua ky tu
bool checkAnswerTrueOfFormat(char c);
float lamTronDiem(float x);
void ghiNhanDapAn(DETHI *deThi,int id,char da[3]);
bool ktDaGhiNhanDapAn(DETHI *deThi,int id);
void hienThiDapAn(int x,int y,char da[3]);
EXAMTIME thi(char tenMon[MAXTMH],CAUHOI cauHoi[MAX],int slCauHoi,DETHI *deThi,TIME localTime,EXAMTIME &examTime);
void initExam(DSLOP *dslop,char masv[MAXMSV],char hoSv[MAXHOSV],char tenSv[MAXTENSV], 
            MON monThi,DETHI *deThi,CAUHOI mangCauHoi[MAX],
               int slc,float bangDiem[MAX],TIME localTime,EXAMTIME examTime);
float tinhDiem(DETHI *deThi,float bangDiem[MAX]);
void ghiDiem(DSLOP *dslop,char masv[MAXMSV+2],DIEM diem);
void xemDiem(DSLOP *dslop,char masv[MAXMSV],char mamh[MAXMMH]);
void hienThiDiem(DETHI *deThi,char hoSv[MAXHOSV],char tenSv[MAXTENSV],float diem,EXAMTIME examTimeUsed,int x,int y);
//--Function To Check ReExam
bool trueStudent(char masv[MAXMSV]);
bool trueSubject(char mamh[MAXMMH]);
bool trueSLCHoi(int slcH);
bool useOldExam(char masv[MAXMSV],char mamh[MAXMMH],int slch);
int checkLog();
void loadDeThiTuFileTam(DETHI *deThi);

//----Function for display
void displayMarkTable(int x,int y);
void displayExamScreen(char masv[MAXMSV],char tenMon[MAXTMH],TIME localTime);
void showNumBerZeroToNine(int number,int x,int y);
void showTime(int timeFirst,int timeAfter,int x,int y);
OBJECR_LCT makeTable(OBJECR_LCT diemxy,int chieuDai,int chieuRong,char char_Cd,char char_Cr);
OBJECR_LCT makeTable_Color(OBJECR_LCT diemxy,int chieuDai,int chieuRong,char char_Cd,char char_Cr,int idColor_Cd,int idColor_Cr);
OBJECR_LCT make_OuterBorderTable(OBJECR_LCT diemxy,int chieuDai,int chieuRong,char char_Cd,char char_Cr,int doRong);
OBJECR_LCT make_OuterBorderTable_Color(OBJECR_LCT diemxy,int chieuDai,int chieuRong,char char_Cd,char char_Cr,int doRong,int idColor_Cd,int idColor_Cr);
void display_LoginFail(int x,int y);
void display_LoginProgram(int x,int y);
void changeScene_type2(int id_Color);
void changeScene_type1(int id_Color);
void backGround();
//Clock
void* hienThiDongHo(void* params);
void clock(int minutes[MAXMINUTES],int len,int x,int y,int &seconds);
void clockT(int minutes[MAXMINUTES],int len,int x,int y,int *restSeconds);
void clockTest(EXAMTIME &time,int x,int y);
void clockStop(EXAMTIME time,int x,int y);

