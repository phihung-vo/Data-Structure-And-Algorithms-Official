//ham kt 
void sapXepLop(DSLOP *dslop);
void sapXepMon(DSMON *dsmon);
void clearPartOfScreenButNoClockUB(int x,int y,int endX,int endY);//xoa 1 vung man hinh nhu khong khoa dong ho
void wait ( int seconds );//hàm dung màn hình seconds giây
void clearPartOfScreen(int x,int y,int endX,int endY);//ham xoa mot vung trong man hinh
void vietHoaChuCaiDau(char str[]);
void timViTriXL(DSLOP *ds, int vitri);//tim vi tri xoa trong ds lop
void timViTriXM(DSMON *dsmon, int vitri);//tim vi tri xoa trong ds mon
void timViTriXoaKTrang(char s[90],int vitrixoa);
void xoaKhoangTrang(char*s);
void tachChuoi(char str[MAXML]);
bool tachChuoivaSoSanhNK(char str[MAXNK]);
bool trungMaLop(char s[MAXML], DSLOP *ds);
bool trungTenLop(char s[MAXTL], DSLOP *ds);
bool trungMaMon(char s[MAXMMH], DSMON *dsmon);
bool trungTenMon(char s[MAXTMH], DSMON *dsmon);
bool dinhdangNienKhoa(char s[MAXNK]);
bool dinhdangMaLop(char s[MAXML]);
bool ktKyTuSo(char s[]);
bool ktNhapVoPhaiCoKyTuSo(char *s);
bool YES_NO(OBJECR_LCT diemxy, int yIn, int xIn,char str[]);
bool checkIfAnswerOnlyCharacter(char c);//neu kt tu nhap vo la chu cai
bool checkNullArr(char arr[]);//ham kt chuoi rong
bool shouldPrintNewLine(char nd[MAX_CONTENT_QUESTION],int i,int j,int end);
bool printfOnNewLine(int index,int indexEnd);
int showStringInLocation(char nd[MAX_CONTENT_QUESTION],int x,int y,int end);//ham hien thi chuoi ky tu tren tung dong
int findsubstr(const char *str, char *sub);//tim chuoi con trong chuoi
int convertIntFromChar(char c);//ham chuyen tu c=getch() sang integer
int convertIntegerFromCharArr(char number[MAX]);//ham chuyen mang ky tu so sang integer
int getIdQuestionFromFile();//ham lay id ra tu file roi xoa id do
int findCenterScreenX(char str[MAX_X_SCREEN]);//hàm tìm vi trí cua x sao cho in chuoi str ngay giua màn hình
int Empty_L(DSLOP *dslop);//kiem tra danh sach LOP rong
int Full_L(DSLOP *dslop);//kiem tra xem danh sach LOP full 
int Empty_M(DSMON *dsmon);//kiem tra danh sach MON rong
int Full_M(DSMON *dsmon);//kiem tra xem danh sach MON full 

//--------------------------------------------------------------------------------------------------------
//Function For Class
//ham nhap
void chuThichML();
void chuThichTL();
void chuThichNK();
void nhapDSLopMoi(DSLOP *dslop);
void Input_Class(DSLOP *dslop);
//ham in
void GdMonThi();
void Gdin();//giao dien in
void inDS(int tick, DSLOP *dslop);//phan trang
int inDSLop(DSLOP *dslop);//in ds lop toan man hinh
void inDSLopTheoNK(DSLOP *dslop);//tim lop theo nien khoa
void GdLop();//giao dien
int inLop(int tick, DSLOP *dslop, bool rig);//f2 va in ds lop 1 ben
int inf1(int stcthuc,DSLOP *dslop);//tinh so trang de in f1
//ham them
void insertClass(DSLOP *ds,LOP *lop);
//IN SV
void GdSV();
//----------------------------------------------------------------------------------------
//Function For Monhoc
//ham nhap mon
void chuThichMM();
void chuThichTM();
void nhapDSMon(DSMON *dsmon);
void Input_Mon(DSMON *dsmon);
//ham in
void GdMon();
int inMon(int tick, DSMON *dsmon,bool rig);
int inMf1(int stcthuc,DSMON *dsmon);
//ham them
//void insertObject(char maMon[MAXMMH],char tenMon[MAXTMH],DSMON *dsmon);
void insertObject(DSMON *dsmon,MON *mon);
//----------------------------------------------------------------------------------------
//Function For Student
int EmptyDSSV(NODESINHVIEN &First);
int countSV(NODESINHVIEN First);
int countSV_DSLOP(DSLOP *dslop, char s[MAXML]);
int position(NODESINHVIEN First, NODESINHVIEN p);
void InitDSSV(NODESINHVIEN &First);
void Clear_DSSV(NODESINHVIEN &First);
void Traverse_DSSV(NODESINHVIEN First);
void Delete_First_SV(NODESINHVIEN &First);
void Delete_After_SV(NODESINHVIEN p);
void Insert_Last_SV(NODESINHVIEN &First, SINHVIEN sv);
void Insert_After_SV(NODESINHVIEN &p, SINHVIEN sv);
void Insert_First_SV(NODESINHVIEN &First, SINHVIEN sv);
NODESINHVIEN NewNode();
NODESINHVIEN nodepointer(NODESINHVIEN First, int i);
NODESINHVIEN CreateNode(SINHVIEN &sv);
//NODESINHVIEN Search_SV(NODESINHVIEN First, char maSv[MAXMSV]);
NODESINHVIEN Input_DSSVtemp();
bool checkMSV(NODESINHVIEN First, char maSv[MAXMSV]);
//khung_sv
void Khung_Nhap_SV(OBJECR_LCT start, int dai, int rong, int col_right, int row_bottom);
void Khung_Tim_Kiem_SV(OBJECR_LCT start, int dai, int rong, int col_right, int row_bottom);
bool ESC_THOAT(OBJECR_LCT start,int dai, int rong, int col_right, int row_bottom, int x_esc, int y_esc);
bool ESC_LUU(OBJECR_LCT start, int dai, int rong, int col_right, int row_bottom, int x_esc, int y_esc);
bool ESC_INPUTSV(OBJECR_LCT start, int dai, int rong, int col_right, int row_bottom, int x_esc, int y_esc);
//Thao tac sv
void Input_SV(DSLOP *dslop);
void Delete_SV(DSLOP *dslop);
void Edit_SV(DSLOP *dslop);
void Search_SV(DSLOP *dslop);
//----------------------------------------------------------------------------------------
//Funtion For Question
void InitDSCH(NODECAUHOI &root);//khoi tao danh sach cau hoi
int EmptyDSCH(NODECAUHOI root);
void Insert_node(NODECAUHOI &p, CAUHOI cauhoi);//them cau hoi vao danh sach & luu cau hoi vao file
void inorder(NODECAUHOI p);//Duyet danh sach cau hoi
void saveDSCH(CAUHOI ch);
void loadDSCH(NODECAUHOI &root);
//khung_cauhoi
void Khung_Nhap_DSCH(OBJECR_LCT start, int dai, int rong); //...
//Thao tac cauhoi
void Input_CH(NODECAUHOI &root, DSMON *dsmon);
void Delete_CH(NODECAUHOI &root, DSMON *dsmon);
void Edit_CH(NODECAUHOI &root, DSMON *dsmon);
void Search_CH(NODECAUHOI &root, DSMON *dsmon);
//----------------------------------------------------------------------------------------
//Function Work With File
//file class
void saveDSLop(DSLOP *dslop);
void loadDSLop(DSLOP *dslop);
//file subject
void showDSMon(DSMON *dsmon, NODECAUHOI dscauhoi);
void loadDSMonTam(DSMON *dsmon);
void saveDSMonTam(DSMON *dsmon);
void loadDSMon(DSMON *dsmon);
void saveDSMon(char maMon[MAXMMH],char  tenMon[MAXTMH],DSMON *dsmon);
void saveDSMonMoi(DSMON *dsmon);
//Funtion For Services
void backSpace(int x,int y);
//Funtion For Display and Menu

int loginDisplay();
int menu(DSLOP *dslop,DSMON *dsmon,NODECAUHOI *dscauhoi);
int menuDisplay();                                                     //vua sua3
int menuDisplayQuanLySinhVien();
int menuDisplayQuanLyCauHoi();
int menuDisplayQuanLyLop();                                          //vua sua1
int menuDisplayQuanLyMonHoc();                                      //vua sua2
int menuQuanLyLop(DSLOP *dslop);
int menuQuanLyMonHoc(DSMON *dsmon);
void displayOuputDSMon(int x,int y);//cai dat vi tri cua danh sach
void displayOuputDSLop(int x,int y);
void displayOuputDSL(int x,int y);
void displayOuputDSSV(int x,int y);
void display_GoodBye();
//Function Login
int displayMenuRunByGV();
ACCOUNT module_Login(int x,int y);
ACCOUNT  getLoginInfo(int x,int y);
void display_LoginFail(int x,int y);
void display_LoginProgram(int x,int y);

//-----------
void showT(char masv[MAXMSV],char mamh[MAXMMH]);
//----ID
int random(int maxN,int minN);
void makeIdFile();
int getIdQuestionFromFile();

//ham do hoa
void colorText(int colorId);
int randColor();
void whiteColor();
void colorTable();
void changeScene_type1(int id_Color);
void changeScene_type2(int id_Color);
OBJECR_LCT makeTable_Type2(OBJECR_LCT diemxy,int cD,int cR);
OBJECR_LCT makeTable(OBJECR_LCT diemxy,int chieuDai,int chieuRong,char char_Cd,char char_Cr);
OBJECR_LCT makeTable_Color_Type2(OBJECR_LCT diemxy,int cD,int cR,int color_CD,int color_CR);
OBJECR_LCT makeTable_Color(OBJECR_LCT diemxy,int chieuDai,int chieuRong,char char_Cd,char char_Cr,int idColor_Cd,int idColor_Cr);
OBJECR_LCT make_OuterBorderTable(OBJECR_LCT diemxy,int chieuDai,int chieuRong,char char_Cd,char char_Cr,int doRong);
OBJECR_LCT make_OuterBorderTable_Color(OBJECR_LCT diemxy,int chieuDai,int chieuRong,char char_Cd,char char_Cr,int doRong,int idColor_Cd,int idColor_Cr);
void saveButton(int x,int y);
void enterSaveButton(int x,int y);
OBJECR_LCT displayInputQuestion(int x,int y);
void backGround();
void systemCls();
void clearPartOfScreen(int x,int y,int endX,int endY);

