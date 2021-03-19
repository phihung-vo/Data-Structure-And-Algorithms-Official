#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<string>
#include<windows.h>
//typedef struct{
//	int x;
//	int y;
//	int maxX;
//	int maxY;
//}OBJECR_LCT;

void gotoxy(short int x,short int y)
{
	static HANDLE h = NULL;
	if(!h)
	{
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	}
	COORD c = {x,y};
	SetConsoleCursorPosition(h,c);
}


void systemCls(){
	system("cls");
	backGround();
	colorText(IDCOLOR_CLEARTEXT);
	
}
void backGround(){
	int i,j;
	
	colorText(IDCOLOR_BACKGROUND);//COLOR_BACKGROUND
	for( i=0;i<=171;i++)
		for( j=0;j<=54;j++){
		   gotoxy(i,j);
		   printf("%s"," ");//Sleep(10);
       }gotoxy(i,j);printf("%s","");gotoxy(i+1,j);printf("%s","");
	   gotoxy(i+1,j);printf("%s"," ");
	   colorText(IDCOLOR_CLEARTEXT);gotoxy(0,0);
}


//ham in mau chu
void colorText(int colorId){
	  HANDLE hConsoleColor;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(hConsoleColor, colorId);
}

void backGround2(int x, int y, int xend, int yend, int color){	
	int i,j;
	colorText(color);
	for(i=x;i<=xend;i++)
		for(j=y;j<=yend;j++){
		   gotoxy(i,j);
		   printf("%s"," ");//Sleep(10);
       }gotoxy(i,j);printf("%s","");
	   colorText(color);gotoxy(0,0);
}
//ham tro lai mau goc
void whiteColor(){
	  HANDLE hConsoleColor;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(hConsoleColor, 7);//7
}
void clearColor(){
	 HANDLE hConsoleColor;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(hConsoleColor, IDCOLOR_CLEARTEXT);//7
}

//ham in mau bang
void colorTable(){
	system("cls");
	for(int i=0;i<255;i++){
		printf("%s%d ","Ma mau: ",i);
		colorText(i);
		printf("%s\n","COLOR");
	    whiteColor();
	}
}

void changeScene_type1(int id_Color){
	colorText(id_Color);
	for(int i=0;i<=180;i++)
		for(int j=0;j<=56;j++){
		   gotoxy(i,j);
		   printf("%s"," ");//Sleep(10);
       }
       whiteColor();
       system("cls");
}

void changeScene_type2(int id_Color){
	colorText(id_Color);
	for(int i=0;i<=50;i++)
		for(int j=0;j<=200;j++){
		   gotoxy(j,i);
		   printf("%s"," ");//Sleep(10);
       }
       whiteColor();
       system("cls");
}

OBJECR_LCT makeTable_Type2(OBJECR_LCT diemxy,int cD,int cR){
	
	 int i;
	 
	 for(i=1;i<=cR;i++) // tao dong ngang
	 {gotoxy(diemxy.x+i,diemxy.y);printf("%c",205); // dong ngang tren
	  gotoxy(diemxy.x+i,diemxy.y+cD);printf("%c",205);  // dong ngang duoi
	  }
	   for(i=1;i<=cD;i++)  // dong ke thang dung
	  {
	  gotoxy(diemxy.x,diemxy.y+i);printf("%c",186); // dong thang ben trai
	  gotoxy(diemxy.x+cR,diemxy.y+i);printf("%c",186); // dong thang ben phai
	  }
	  gotoxy(diemxy.x+cR,diemxy.y);printf("%c",187); // cai moc cau ben phai ben tre^n
	  gotoxy(diemxy.x+cR,diemxy.y+cD);printf("%c",188); // cai moc cau ben phai ben duoi
	  gotoxy(diemxy.x,diemxy.y);printf("%c",201); // cai moc cau ben trai tren
	  gotoxy(diemxy.x,diemxy.y+cD);printf("%c",200); // moc cau ben trai duoi
	
	diemxy.maxX = diemxy.x + cR;
	diemxy.maxY = diemxy.y + cD;
	clearColor();
	return diemxy;
}

OBJECR_LCT makeTable_Color_Type2(OBJECR_LCT diemxy,int cD,int cR,int color_CD,int color_CR){
	
	 int i;
	 colorText(color_CR);
	 for(i=1;i<=cR;i++) // tao dong ngang
	 {gotoxy(diemxy.x+i,diemxy.y);printf("%c",205); // dong ngang tren
	  gotoxy(diemxy.x+i,diemxy.y+cD);printf("%c",205);  // dong ngang duoi
	  }
	  whiteColor();
	  colorText(color_CD);
	   for(i=1;i<=cD;i++)  // dong ke thang dung
	  {
	  gotoxy(diemxy.x,diemxy.y+i);printf("%c",186); // dong thang ben trai
	  gotoxy(diemxy.x+cR,diemxy.y+i);printf("%c",186); // dong thang ben phai
	  }
	  whiteColor();
	  
	  colorText(color_CR);gotoxy(diemxy.x+cR,diemxy.y);printf("%c",187); // cai moc cau ben phai ben tre^n
	  colorText(color_CD);gotoxy(diemxy.x+cR,diemxy.y+cD);printf("%c",188); // cai moc cau ben phai ben duoi
	  colorText(color_CD);gotoxy(diemxy.x,diemxy.y);printf("%c",201); // cai moc cau ben trai tren
	  colorText(color_CR);gotoxy(diemxy.x,diemxy.y+cD);printf("%c",200); // moc cau ben trai duoi
		clearColor();
	
	diemxy.maxX = diemxy.x + cR;
	diemxy.maxY = diemxy.y + cD;
	return diemxy;
	
}


OBJECR_LCT makeTable_Color(OBJECR_LCT diemxy,int chieuDai,int chieuRong,char char_Cd,char char_Cr,int idColor_Cd,int idColor_Cr){
	gotoxy(diemxy.x,diemxy.y);
	colorText(idColor_Cr);
	for(int i=1;i<=chieuRong;i++)printf("%c",char_Cr);
	whiteColor();
	for(int i=1;i<=chieuDai;i++){colorText(idColor_Cd);
		gotoxy(diemxy.x,diemxy.y+i);printf("%c",char_Cd);
	}whiteColor();
	gotoxy(diemxy.x+1,diemxy.y+chieuDai);
	colorText(idColor_Cr);
	for(int i=1;i<=chieuRong;i++)printf("%c",char_Cr);
	whiteColor();
	for(int i=1;i<=chieuDai;i++){colorText(idColor_Cd);
		gotoxy(diemxy.x+chieuRong,diemxy.y+i);printf("%c",char_Cd);
	}whiteColor();
	diemxy.maxX = diemxy.x + chieuRong;
	diemxy.maxY = diemxy.y + chieuDai;
	return diemxy;
}

OBJECR_LCT makeTable(OBJECR_LCT diemxy,int chieuDai,int chieuRong,char char_Cd,char char_Cr){
	gotoxy(diemxy.x,diemxy.y);
	for(int i=1;i<=chieuRong;i++)printf("%c",char_Cr);
	for(int i=1;i<=chieuDai;i++){
		gotoxy(diemxy.x,diemxy.y+i);printf("%c",char_Cd);
	}
	gotoxy(diemxy.x+1,diemxy.y+chieuDai);
	for(int i=1;i<=chieuRong;i++)printf("%c",char_Cr);
	for(int i=1;i<=chieuDai;i++){
		gotoxy(diemxy.x+chieuRong,diemxy.y+i);printf("%c",char_Cd);
	}
	diemxy.maxX = diemxy.x + chieuRong;
	diemxy.maxY = diemxy.y + chieuDai;
	return diemxy;
}

OBJECR_LCT make_OuterBorderTable(OBJECR_LCT diemxy,int chieuDai,int chieuRong,char char_Cd,char char_Cr,int doRong){
	gotoxy(diemxy.x-doRong-1-1,diemxy.y-doRong-1);
	for(int i=1;i<=chieuRong+doRong+1+1+1+1;i++)printf("%c",char_Cr);
	for(int i=1;i<=chieuDai+doRong+1;i++){
		gotoxy(diemxy.x-doRong-1-1,diemxy.y-doRong-1+i);printf("%c",char_Cd);
	}
	gotoxy(diemxy.x-doRong-1,diemxy.y+doRong-1+chieuDai);
	for(int i=1;i<=chieuRong+doRong+2;i++)printf("%c",char_Cr);
	for(int i=1;i<=chieuDai+doRong+1;i++){
		gotoxy(diemxy.x+doRong+chieuRong,diemxy.y-doRong-1+i);printf("%c",char_Cd);
	}
	diemxy.maxX = diemxy.x + chieuRong;
	diemxy.maxY = diemxy.y + chieuDai;
	return diemxy;
}

OBJECR_LCT make_OuterBorderTable_Color(OBJECR_LCT diemxy,int chieuDai,int chieuRong,char char_Cd,char char_Cr,int doRong,int idColor_Cd,int idColor_Cr){
	gotoxy(diemxy.x-doRong-1-1,diemxy.y-doRong-1);colorText(idColor_Cr);
	for(int i=1;i<=chieuRong+doRong+1+1+1+1;i++)printf("%c",char_Cr);whiteColor();
	for(int i=1;i<=chieuDai+doRong+1;i++){colorText(idColor_Cd);
		gotoxy(diemxy.x-doRong-1-1,diemxy.y-doRong-1+i);printf("%c",char_Cd);
	}whiteColor();
	gotoxy(diemxy.x-doRong-1,diemxy.y+doRong-1+chieuDai);colorText(idColor_Cr);
	for(int i=1;i<=chieuRong+doRong+2;i++)printf("%c",char_Cr);whiteColor();
	for(int i=1;i<=chieuDai+doRong+1;i++){colorText(idColor_Cd);
		gotoxy(diemxy.x+doRong+chieuRong,diemxy.y-doRong-1+i);printf("%c",char_Cd);
	}whiteColor();
	diemxy.maxX = diemxy.x + chieuRong;
	diemxy.maxY = diemxy.y + chieuDai;
	return diemxy;
}


void saveButton(int x,int y){
	OBJECR_LCT diemxy;
	diemxy.x = x;
	diemxy.y = y;
    makeTable_Color_Type2(diemxy,2,5,IDCOLOR_CLEARTEXT,IDCOLOR_CLEARTEXT);
	colorText(IDCOLOR_CLEARTEXT);
	gotoxy(x+1,y+1);printf("%s","SAVE");
	
}
//tìm ch? thêm hàm này vô nhe..cho chuong trình sinh d?ng tý

void enterSaveButton(int x,int y){
	OBJECR_LCT diemxy;
	diemxy.x = x;
	diemxy.y = y;
    makeTable_Color_Type2(diemxy,2,5,176,176);//144
	colorText(176);
	gotoxy(x+1,y+1);printf("%s","SAVE");gotoxy(0,0);
	Sleep(100);
	saveButton(x,y);
}

OBJECR_LCT displayInputQuestion(int x,int y){
	gotoxy(x,y);printf("%s","Nhap noi dung cau hoi:");
	gotoxy(x,y+20);printf("%s","Nhap noi dung dap an A");
	gotoxy(x,y+25);printf("%s","Nhap noi dung dap an B");
	gotoxy(x,y+30);printf("%s","Nhap noi dung dap an C");
	gotoxy(x,y+35);printf("%s","Nhap noi dung dap an D");
	saveButton(x+80,y+50);
	
}


//hàm clear màn hình theo c?p nh?t màu c?a background
//void clearPartOfScreen(int x,int y,int endX,int endY){
//      colorText(IDCOLOR_BACKGROUND);
//	  for(int i=x;i<=endX;i++)
//              for(int j=y;j<=endY;j++){gotoxy(i,j);printf("%c",' ');}
//      colorText(224);
//     
//     }

