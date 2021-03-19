#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<conio.h>

#define xIn 15 //cho cot nhap trai
#define yIn 5 // dong nhap trai                  //yIn = yGd = 5
#define xGd 100 //cho cot in ds phai
#define yGd 5 // dong in ds phai

//--------------------------FUNCTION CLASS
//-------TRA CUU LOP
void displayOuputDSL(int x,int y){
  
   OBJECR_LCT diemxy;
	diemxy.x = 50;
	diemxy.y = 4;
	makeTable_Type2(diemxy,2,72);
	gotoxy(diemxy.x+28,diemxy.y+1);//bang ds
colorText(78);
	printf("%s","BANG DANH SACH LOP");
colorText(237);
	diemxy.x = x;
	diemxy.y = y+3;
	makeTable_Type2(diemxy,2,xIn+118);// bang duoi
} 
void Gdin(){
		gotoxy(1,1);colorText(228);printf("Nhan ESC de ve menu!");
		gotoxy(1,2);colorText(228);printf("Nhan Tab de tim kiem!");
		displayOuputDSL(xIn-2,4);
		gotoxy(xIn,8);colorText(235);printf("STT");
		gotoxy(xIn+15,8);colorText(235);printf("MA LOP");
		gotoxy(xIn+60,8);colorText(235);printf("TEN LOP");
		gotoxy(xIn+110,8);colorText(235);printf("NIEN KHOA");
		gotoxy(xIn+125,8);colorText(235);printf("SLSV");
}
void inDS(int tick, DSLOP *dslop){
	int count =0; char c;	int j=0; 
	int vitri=0; //chi dung lam tang them 1 hang trong
    Gdin();//GD
    if( ( (tick*20) - (dslop->n) ) > 20 ){	}
	else {
		clearPartOfScreen(xIn,vitri+10,xIn+125+10,48);//xoa 1 vung in ds
		sapXepLop(dslop);//SAP XEP
		//in trang
		for(int i=0;i<dslop->n;i++){
				if(i % 20 == 0) j ++;
			if(j == tick){
				colorText(226);
				gotoxy(xIn,vitri+10);
		        printf("%d",i+1);
				gotoxy(xIn+15,vitri+10);
		        printf("%s",dslop->lop[i]->malop);
		        gotoxy(xIn+45,vitri+10);
			    printf("%s",dslop->lop[i]->tenlop);
			    gotoxy(xIn+110,vitri+10);
			    printf("%s",dslop->lop[i]->nienkhoa);
			    gotoxy(xIn+125,vitri+10);
			    printf("%d",countSV_DSLOP(dslop,dslop->lop[i]->malop));
				vitri = vitri+2;
				count++;
			}
			if(count == 20){
				break;
			}
		}
	}
}
int inDSLop(DSLOP *dslop) { 
    systemCls();fflush(stdin);
   	char c; int tick = 1; int stcthuc = dslop->n / 20;
   	inDS(tick,dslop);//in ds
   	//tinh so trang
	float stdu = (float)((dslop->n) % 20);
	stdu /= 10;	
	if(stdu >= 0 && stdu < 1){	stcthuc += 1;	}
	else {	stcthuc += 0;	}
	//
W:	if(kbhit){
		c=getch();
		if(Empty_L(dslop) == 1){	gotoxy(xGd+3,yGd+7);colorText(230);printf("DS rong!"); Sleep(1000); return -1;	}
		else {
			if( c==0 ){c=getch();
				if ( c == 59) {//f1
		   			tick ++;
					if(tick<=stcthuc){
						inDS(tick,dslop);
					}else{
						tick=tick-1;
						inDS(tick,dslop);
					}
				}
				if ( c == 60) {//f2
					tick --;if(tick == 0) tick = 1;
					inDS(tick,dslop);
				}
			}
			if ( c == 9) {//tab
				inDSLopTheoNK(dslop);
			}
			if ( c == 27) {//esc
				return -1;
			}
		}
	}goto W;
}
void inDSLopTheoNK(DSLOP *dslop){
Loop:	systemCls();fflush(stdin);
	char c; int k=0; int vitri=0;    
	gotoxy(1,1);
    printf("Nhan ESC de ve ds lop!");
        char timLopTheoNK[MAXNK];
        gotoxy(50,2);colorText(226);
   		printf("Nhap lop can tim theo nien khoa: ");
Timnk:   		gotoxy(50+33+k,2);
       	while ((timLopTheoNK[k]=getch())!=13){
       		fflush(stdin);
       		if(timLopTheoNK[k] == 27) {
			   		goto Esc;
			}
			if(timLopTheoNK[k] == 8) {//xoa
                k--;if(k<0)	k=0;
                else{
		                backSpace(50+33+k,2);
		                gotoxy(50+33+k,2);
                }
            }
			else{
       				printf("%c",(char)timLopTheoNK[k]);k++;
				}
		}
		fflush(stdin); 
		timLopTheoNK[k] = '\0';
		while (true){
			if(ktKyTuSo(timLopTheoNK)==false){//dieu kien neu khong la so
					gotoxy(50+33,3);colorText(234);
					printf("chi nhap so!");//12
					Sleep(500);
					clearPartOfScreen(50+33,3,50+33+35,3);//xoa bat loi
					goto Timnk;
			}
			if(k<1||k>=10){
					gotoxy(50+33,3);colorText(234);
					printf("nhap theo kieu yy hoac yyyy-yyyy!");//35
					Sleep(500);
					clearPartOfScreen(50+33,3,50+33+35,3);//xoa bat loi
					goto Timnk;
			}
			else {
					clearPartOfScreen(50+33,3,50+33+35,3);//xoa bat loi
					break;
			}
		}
		Gdin();//---- gdien
		clearPartOfScreen(1,1,1+22,2);//xoa thang esc va tab tren dau ngoai cung
		sapXepLop(dslop);//sap xep
		//----in
		for(int i=0;i<dslop->n;i++){
			if(strlen(timLopTheoNK)<=2){
				if(strstr(dslop->lop[i]->tenlop, timLopTheoNK)) { // neu nhap yy tim theo ten lop
					fflush(stdin);
					colorText(233);
					gotoxy(xIn,vitri+10);
			        printf("%d",i+1);
					gotoxy(xIn+15,vitri+10);
			        printf("%s",dslop->lop[i]->malop);
			        gotoxy(xIn+45,vitri+10);
				    printf("%s",dslop->lop[i]->tenlop);
				    gotoxy(xIn+110,vitri+10);
				    printf("%s",dslop->lop[i]->nienkhoa);
				    gotoxy(xIn+125,vitri+10);
			    	printf("%d",countSV_DSLOP(dslop,dslop->lop[i]->malop));
					vitri = vitri+2;
				}
			}
			else if(strlen(timLopTheoNK)==4){
				char* cpstr = substring(timLopTheoNK,2);//tach 2 so dau de lay 2 so duoi
				strcpy(timLopTheoNK,cpstr);
//				printf("%s\n",cpstr);
				if(strstr(dslop->lop[i]->tenlop,timLopTheoNK)){
					fflush(stdin);
					colorText(233);
					gotoxy(xIn,vitri+10);
			        printf("%d",i+1);
					gotoxy(xIn+15,vitri+10);
			        printf("%s",dslop->lop[i]->malop);
			        gotoxy(xIn+45,vitri+10);
				    printf("%s",dslop->lop[i]->tenlop);
				    gotoxy(xIn+110,vitri+10);
				    printf("%s",dslop->lop[i]->nienkhoa);
				    gotoxy(xIn+125,vitri+10);
			    	printf("%d",countSV_DSLOP(dslop,dslop->lop[i]->malop));
					vitri = vitri+2;
				}
			}
			else{
				if(strstr(dslop->lop[i]->nienkhoa, timLopTheoNK)) {// neu nhap yyyy-yyyy tim theo nien khoa
					fflush(stdin);
					colorText(232);
					gotoxy(xIn,vitri+10);
			        printf("%d",i+1);
					gotoxy(xIn+15,vitri+10);
			        printf("%s",dslop->lop[i]->malop);
			        gotoxy(xIn+45,vitri+10);
				    printf("%s",dslop->lop[i]->tenlop);
				    gotoxy(xIn+110,vitri+10);
				    printf("%s",dslop->lop[i]->nienkhoa);
				    gotoxy(xIn+125,vitri+10);
			    	printf("%d",countSV_DSLOP(dslop,dslop->lop[i]->malop));
					vitri = vitri+2;
				}
			}
		}
		gotoxy(0,6);colorText(225);
		printf("ESC: Exit		Enter: Search");
		do{
		  	c=getch();fflush(stdin);
		}while(c!=27 && c!=13);
		if(c==27){
		  	goto Esc;
		}
		if(c==13){
			goto Loop;
		}
    Esc : inDSLop(dslop);
}
//-----------------------------------------DisplayOuput
void chuThichMM(){  colorText(237);
		gotoxy(xIn, 16); printf("MM: GOM CAC KI TU (A-Z) & (0-9), TOI DA: %d KI TU",MAXMMH);clearColor();
}

void chuThichTM(){colorText(237);
		gotoxy(xIn, 16); printf("TM: GOM CAC KI TU (A-Z) & (0-9), TOI DA: %d KI TU",MAXTMH);clearColor();
}

void chuThichML(){colorText(236);
		gotoxy(xIn, 18); printf("ML: GOM CAC KI TU (A-Z) & (0-9), TOI DA: %d KI TU",MAXML);
		gotoxy(xIn, 19); printf("VA CO MA VUNG(-N:NAM;-B:BAC)");clearColor();
}

void chuThichTL(){colorText(236);
		gotoxy(xIn, 18); printf("TL: GOM CAC KI TU (A-Z) & (0-9), TOI DA: %d KI TU",MAXTL);
		gotoxy(xIn, 19); printf("VA CO NIEN KHOA");clearColor();
}

void chuThichNK(){colorText(236);
		gotoxy(xIn, 18); printf("NK: DUNG DINH DANG YYYY-YYYY, TOI DA: 10 KI TU");clearColor();
}
//------------IN LOP
void displayOuputDSLop(int x,int y){
	
    OBJECR_LCT diemxy;
	diemxy.x = x;
	diemxy.y = y-1;
	makeTable_Type2(diemxy,2,80);
	gotoxy(diemxy.x+32,diemxy.y+1);
colorText(78);
	printf("%s","BANG DANH SACH LOP");
colorText(234);
	diemxy.x = x;
	diemxy.y = y+3;
	makeTable_Type2(diemxy,42,80);
} 
void GdLop(){
	colorText(158);
		gotoxy(xIn,42);printf("F3:Insert");
		gotoxy(xIn,44);printf("F4:Delete");
		gotoxy(xIn,46);printf("F5:Edit");
		gotoxy(xIn,48);printf("ESC:MENU - Enter:IN_SV - F1:Phai - F2:Trai");
		displayOuputDSLop(75,5);
		gotoxy(xGd-23,yGd+3);colorText(236);printf("MA LOP");
		gotoxy(xGd+7,yGd+3);colorText(236);printf("TEN LOP");
		gotoxy(xGd+38,yGd+3);colorText(236);printf("NIEN KHOA");
		gotoxy(xGd+38+10+2,yGd+3);colorText(236);printf("SLSV");
}
//----------IN DS
void displayOuputDSSV(int x,int y){
	
    OBJECR_LCT diemxy;
	diemxy.x = 50;
	diemxy.y = 7;
	makeTable_Type2(diemxy,2,72);
	gotoxy(diemxy.x+25,diemxy.y+1);//bang ds
colorText(233);
	printf("%s","DANH SACH SINH VIEN");
colorText(226);
	diemxy.x = x;
	diemxy.y = y+3;
	makeTable_Type2(diemxy,2,xIn+125);// bang duoi
} 
void GdSV(){
		gotoxy(xIn,8);colorText(224);printf("ESC: Exit!");
		displayOuputDSSV(xIn-2,7);
		gotoxy(xIn,11);colorText(234);printf("STT");
		gotoxy(xIn+10,11);colorText(234);printf("MA");
		gotoxy(xIn+35,11);colorText(234);printf("HO");
		gotoxy(xIn+55,11);colorText(234);printf("TEN");
		gotoxy(xIn+105,11);colorText(234);printf("PHAI");
		gotoxy(xIn+120,11);colorText(234);printf("PASSWORD");
}

//---LOP&SV
int inLop(int tick, DSLOP *dslop, bool rig){
	int count =0; char c;
	int i;	int j=0;  int arrow = 0;	int index;
	GdLop(); 
	int vitri=0; //chi dung lam tang them 1 dong
    if( ( (tick*20) - (dslop->n) ) > 20 ){	}
	else {
		clearPartOfScreen(xGd-23,yGd+5,xGd+38+10+5,yIn+5+38);
		sapXepLop(dslop);//sap xep
		//in trang
		for(i=0;i<dslop->n;i++){
				if(i % 20 == 0) j ++;
			if(j == tick){
				if(arrow>count){	}
				else {
				    if(count==arrow && rig==true){
						colorText(94);
						  gotoxy(xGd-23,yGd+5+vitri);
				        printf("%s",dslop->lop[i]->malop);
				        gotoxy(xGd-10,yGd+5+vitri);
					    printf("%s",dslop->lop[i]->tenlop);
					    gotoxy(xGd+38,yGd+5+vitri);
					    printf("%s",dslop->lop[i]->nienkhoa);
					    gotoxy(xGd+38+10+2,yGd+5+vitri);
					    printf("%d",countSV_DSLOP(dslop,dslop->lop[i]->malop));
						vitri=vitri+2;
						count++;
		                arrow;
						clearColor();				
					}
					else {
						colorText(225);//mau in ds lop
						gotoxy(xGd-23,yGd+5+vitri);
				        printf("%s",dslop->lop[i]->malop);
				        gotoxy(xGd-10,yGd+5+vitri);
					    printf("%s",dslop->lop[i]->tenlop);
					    gotoxy(xGd+38,yGd+5+vitri);
					    printf("%s",dslop->lop[i]->nienkhoa);
					    gotoxy(xGd+38+10+2,yGd+5+vitri);
					    printf("%d",countSV_DSLOP(dslop,dslop->lop[i]->malop));
						vitri=vitri+2;
						count++;
					}
				}
			}
			if(count == 20){
				break;
			}
		}
	}
	if(rig==true){
		vitri = 0;
	W:	if(kbhit){
		   c= getch();
		 
			if(c==72 && arrow >0){
				arrow --;
				index = arrow+(tick-1)*20;
				colorText(225);
				  gotoxy(xGd-23,yGd+5+vitri);
		        printf("%s",dslop->lop[index+1]->malop);
		        gotoxy(xGd-10,yGd+5+vitri);
			    printf("%s",dslop->lop[index+1]->tenlop);
			    gotoxy(xGd+38,yGd+5+vitri);
			    printf("%s",dslop->lop[index+1]->nienkhoa);
			    gotoxy(xGd+38+10+2,yGd+5+vitri);
			    printf("%d",countSV_DSLOP(dslop,dslop->lop[index+1]->malop));
				//
				vitri -=2;
				colorText(94);
				  gotoxy(xGd-23,yGd+5+vitri);
		        printf("%s",dslop->lop[index]->malop);
		        gotoxy(xGd-10,yGd+5+vitri);
			    printf("%s",dslop->lop[index]->tenlop);
			    gotoxy(xGd+38,yGd+5+vitri);
			    printf("%s",dslop->lop[index]->nienkhoa);
			    gotoxy(xGd+38+10+2,yGd+5+vitri);
			    printf("%d",countSV_DSLOP(dslop,dslop->lop[index]->malop));
				colorText(225);
			}
			if(c==80 && arrow<count-1){
				arrow ++;
				index = arrow+(tick-1)*20;
				colorText(225);
				  gotoxy(xGd-23,yGd+5+vitri);
		        printf("%s",dslop->lop[index-1]->malop);
		        gotoxy(xGd-10,yGd+5+vitri);
			    printf("%s",dslop->lop[index-1]->tenlop);
			    gotoxy(xGd+38,yGd+5+vitri);
			    printf("%s",dslop->lop[index-1]->nienkhoa);
			    gotoxy(xGd+38+10+2,yGd+5+vitri);
			    printf("%d",countSV_DSLOP(dslop,dslop->lop[index-1]->malop));
				//
				vitri +=2;
				colorText(94);
				  gotoxy(xGd-23,yGd+5+vitri);
		        printf("%s",dslop->lop[index]->malop);
		        gotoxy(xGd-10,yGd+5+vitri);
			    printf("%s",dslop->lop[index]->tenlop);
			    gotoxy(xGd+38,yGd+5+vitri);
			    printf("%s",dslop->lop[index]->nienkhoa);
			    gotoxy(xGd+38+10+2,yGd+5+vitri);
			    printf("%d",countSV_DSLOP(dslop,dslop->lop[index]->malop));
				colorText(225);
			}
			if(c==13){
				systemCls();
				index = arrow+(tick-1)*20;
				GdSV();
				gotoxy(xIn+50,2);colorText(236);
				printf("Ma Lop: %s",dslop->lop[index]->malop);
		        gotoxy(xIn+50,4);colorText(236);
			    printf("Ten Lop: %s",dslop->lop[index]->tenlop);
			    gotoxy(xIn+50,6);colorText(236);
			    printf("Nien Khoa: %s",dslop->lop[index]->nienkhoa);
			    colorText(225);
				int demsv=0;
				vitri=0;
				NODESINHVIEN temp = NULL;
				temp=dslop->lop[index]->dssinhvien;
				int slsv=countSV(temp);
				if(slsv==0){
					gotoxy(xIn+55,30);
					printf("Chua nhap sv!");
				}
				else{
					for(i=0;i<slsv;i++){
						//ke bang
							OBJECR_LCT diemxy;
							diemxy.x = xIn-2;
							diemxy.y = 12+vitri;
							colorText(226);
							makeTable_Type2(diemxy,2,xIn+125);// bang in sv	
						//sv
						 fflush(stdin);
						 colorText(228);
						gotoxy(xIn,13+vitri);
						printf("%d",i+1);
						gotoxy(xIn+10,13+vitri);
				        printf("%s",temp->sinhvien.masv);
				        gotoxy(xIn+35,13+vitri);
					    printf("%s",temp->sinhvien.ho);
					    gotoxy(xIn+55,13+vitri);
					    printf("%s",temp->sinhvien.ten);
					    gotoxy(xIn+105,13+vitri);
					    printf("%s",temp->sinhvien.phai);
						gotoxy(xIn+120,13+vitri);
						printf("%s",temp->sinhvien.password);
						temp = temp->next;
						vitri=vitri+2;
					}
				}
				do{
				  	c=getch();fflush(stdin);
				}while(c!=27);
				if(c==27){
					systemCls();
					return -1;
				}
			}
			if(c==75){
			    return -1;
				goto E;
			}
		}goto W;E: ;
	}
	return index;	
}
int inf1(int stcthuc,DSLOP *dslop){//	stcthuc = dslop.n/20;	//goi dong nay o ngoai
	float stdu = (float)((dslop->n)%20);
	stdu/=10;	
	if(stdu>=0&&stdu<1){stcthuc+=1;}
	else{stcthuc+=0;}
	return stcthuc;	
}
//---------MON
void displayOuputDSMon(int x,int y){
	
    OBJECR_LCT diemxy;
	diemxy.x = x;
	diemxy.y = y-1;
	makeTable_Type2(diemxy,2,75);
	gotoxy(diemxy.x+28,diemxy.y+1);
colorText(206);
	printf("%s","DANH SACH MON HOC");
colorText(236);
	diemxy.x = x;
	diemxy.y = y+3;
	makeTable_Type2(diemxy,42,75);
} 
void GdMon(){
	colorText(233);
		gotoxy(xIn+20,42);printf("UP");
		gotoxy(xIn+12,44);printf("LEFT");
		gotoxy(xIn+26,44);printf("RIGHT");
		gotoxy(xIn+19,46);printf("DOWN");
		gotoxy(xIn,46);printf("TAB:TRA CUU");
		gotoxy(xIn,48);printf("ESC:EXIT 	F1:Insert 	F2:Delete 	F3:Edit");
	displayOuputDSMon(75,5);
	gotoxy(xGd-18,yGd+3);colorText(237);printf("MA MON");
	gotoxy(xGd+5,yGd+3);colorText(237);printf("TEN MON");
}
int inMon(int tick, DSMON *dsmon,bool rig){
	int count =0; char c;
	int i;	int j=0;  int arrow = 0;	int index;
    GdMon();
    int vitri=0; //chi dung lam tang them 1 hang trong
RP:    if( ( (tick*20) - (dsmon->n) ) > 20 ){
        tick--;
		goto RP; 
	}
	else {
		clearPartOfScreen(xGd-23,yGd+5,xGd+38+10,yGd+5+38);//xoa 1 vung in ds
		sapXepMon(dsmon);//sap xep
		//in trang
		for(i=0;i<dsmon->n;i++){
				if(i % 20 == 0) j ++;
			if(j == tick){
				if(arrow>count){	}
				else {
					if(count==arrow&& rig==true){
						colorText(253);
						gotoxy(xGd-22,yGd+5+vitri);
						printf("%d.",i+1);
						gotoxy(xGd-18,yGd+5+vitri);
				        printf("%s",dsmon->mon[i]->mamh);
				        gotoxy(xGd-5,yGd+5+vitri);
					    printf("%s\n",dsmon->mon[i]->tenmh);
					    vitri=vitri+2;
						count++;arrow;
					    clearColor();
					}
					else {
						colorText(237);
						gotoxy(xGd-22,yGd+5+vitri);
						printf("%d.",i+1);
						gotoxy(xGd-18,yGd+5+vitri);
				        printf("%s",dsmon->mon[i]->mamh);
				        gotoxy(xGd-5,yGd+5+vitri);
					    printf("%s\n",dsmon->mon[i]->tenmh);
						vitri=vitri+2;
						count++;
					}
				}
			}
			if(count == 20){
				break;
			}
		}
	}
	if(rig==true){
		vitri=0;
	W:	if(kbhit){
			c=getch();
			if(c==72 && arrow >0){
				arrow --;
				index = arrow+(tick-1)*20;
				colorText(237);
				  gotoxy(xGd-22,yGd+5+vitri);
				printf("%d.",(index+1)+1);
				gotoxy(xGd-18,yGd+5+vitri);
		        printf("%s",dsmon->mon[index+1]->mamh);
		        gotoxy(xGd-5,yGd+5+vitri);
			    printf("%s\n",dsmon->mon[index+1]->tenmh);
				//
				vitri -=2;
				colorText(253);
				  gotoxy(xGd-22,yGd+5+vitri);
				printf("%d.",index+1);
				gotoxy(xGd-18,yGd+5+vitri);
		        printf("%s",dsmon->mon[index]->mamh);
		        gotoxy(xGd-5,yGd+5+vitri);
			    printf("%s\n",dsmon->mon[index]->tenmh);
				colorText(237);
			}
			if(c==80 && arrow < count-1){
				arrow++;
				index = arrow+(tick-1)*20;
				colorText(237);
				 gotoxy(xGd-22,yGd+5+vitri);
				printf("%d.",(index-1)+1);
				gotoxy(xGd-18,yGd+5+vitri);
		        printf("%s",dsmon->mon[index-1]->mamh);
		        gotoxy(xGd-5,yGd+5+vitri);
			    printf("%s\n",dsmon->mon[index-1]->tenmh);
				//			    
			    vitri +=2;
			    colorText(253);
				 gotoxy(xGd-22,yGd+5+vitri);
				printf("%d.",index+1);
				gotoxy(xGd-18,yGd+5+vitri);
		        printf("%s",dsmon->mon[index]->mamh);
		        gotoxy(xGd-5,yGd+5+vitri);
			    printf("%s\n",dsmon->mon[index]->tenmh);
			    colorText(237);
			}
			if(c==13){
				systemCls();
				index = arrow+(tick-1)*20;
				gotoxy(xIn,8);printf("%s\n",dsmon->mon[index]->tenmh);
				do{
				  	c=getch();fflush(stdin);
				}while(c!=27);
				if(c==27){
					Sleep(500);
					clearPartOfScreen(xIn,8,xIn+15+40,8);//xoa 1 vung in ds
					return -1;
				}
			}
		if(c==75){
			    return -1;
				goto E;
			}
		}goto W;E: ;
	}
	return index;
}
int inMf1(int stcthuc,DSMON *dsmon){//	stcthuc = dsmon.n/20;	//goi dong nay o ngoai
	float stdu = (float)((dsmon->n)%20);
	stdu/=10;	
	if(stdu>=0&&stdu<1){stcthuc+=1;}
	else{stcthuc+=0;}
	return stcthuc;	
}
//------------------THEM & NHAP
//ham them lop
void insertClass(DSLOP *ds,LOP *lop) {
       int count;
       LOP *temp;
       temp = (LOP *)malloc(sizeof(LOP));
		strcpy(temp->malop,lop->malop);
        strcpy(temp->tenlop,lop->tenlop);
        strcpy(temp->nienkhoa,lop->nienkhoa);
        temp->dssinhvien=lop->dssinhvien;
        count = (ds->n); 
	    (ds->lop[count] )= temp;
	    (ds->n) = (count+1);
}

//ham nhap
void Input_Class(DSLOP *dslop){
	systemCls();
    if(Empty_L(dslop) == 1){ gotoxy(xGd+3,yGd+7);printf("DS rong! Khoi tao file DSLOP!");
		Sleep(1000);/*thoat de chay lai ds*/
		clearPartOfScreen(xGd+3,yGd+7,xGd+3+29,yGd+7);	
	 }
	char c; int tick=1;	int stcthuc = dslop->n/20;
	int arrow = -1;bool rig = false;
	char note[50];
		OBJECR_LCT diemxy;
	   diemxy.x=xIn;
	   diemxy.y=xIn+7;
T:	inLop(tick,dslop,rig);
	arrow = 0;
	int i = 0; int vitri = 0;
RP:		while(true){
			do{
			  	c=getch();fflush(stdin);
			}while(c!=0 &&c!=27/*esc*/ && c!=59/*f1*/ && c!=60/*f2*/ && c!=61/*f3*/ && c!=62/*f4*/ && c!=63/*f5*/ && c!=75/*trai*/ && c!=77/*phai*/);
			if( c==0 ){c=getch();
				if ( c == 59) {//f1
					if(tick<=inf1(stcthuc,dslop)){
						tick +=1;
						inLop(tick,dslop,rig);
					}else{
						tick +=0;
						inLop(tick,dslop,rig);
					}
				}
				if ( c == 60 ) {//f2
					tick --;if(tick == 0) tick = 1;
					inLop(tick,dslop,rig);
				}
				if ( c == 61 ){	   //f3	(THEM)	
					if(Full_L(dslop) == 1) {	
						gotoxy(xIn+3,yIn+7);
						printf("DS full khong the them!");	
						Sleep(500);
						clearPartOfScreen(xIn+3,yIn+7,xIn+3+23,yIn+7);
						goto RP;
					}
					else {
					N:		gotoxy(xIn,8);colorText(233);
						printf("So luong lop hien co: %d",(dslop->n));
						if(YES_NO(diemxy, 25, 4,"BAN CO MUON THEM LOP?")){//yes
							clearPartOfScreen(xIn,22,50,27);//xoa vung hoi
							nhapDSLopMoi(dslop);
							clearPartOfScreen(xIn,10,xIn+50,14);//xoa vung sau khi nhap xong
							clearPartOfScreen(xIn,8,xIn+24+(dslop->n),8);//xoa lai de in vung so luong
							goto N;
						}
						else {//no
							clearPartOfScreen(xIn,22,50,27);
							clearPartOfScreen(xIn,8,xIn+24+(dslop->n),8);//xoa lai de in vung so luong
							goto RP;
						}
					}
				}
				if ( c == 62) {   //f4 (XOA)
						bool found = false;
				Del:		gotoxy(xIn,8);colorText(30);
						printf("DELETE CLASS!");
						char lopCanXoa[MAXML];
						clearColor();gotoxy(xIn,9);
						printf("NHAP ID CLASS: ");
					InpD:	gotoxy(xIn+15+i,9);
						while((lopCanXoa[i]=getch())!=13){
							fflush(stdin);
							if (lopCanXoa[i] == 0) { lopCanXoa[i]=getch();
								if (lopCanXoa[i] == 59) {//nut f1
							   			if(tick<=inf1(stcthuc,dslop)){
						                    tick +=1;
						                    inLop(tick,dslop,rig);
					                    }else{
						                    tick +=0;
						                    inLop(tick,dslop,rig);
					                    }
										gotoxy(xIn+15+i,9);
										continue;
								}
								if (lopCanXoa[i] == 60) {//nut f2
							   			tick --;if(tick == 0) tick = 1;
							    		inLop(tick,dslop,rig);
										gotoxy(xIn+15+i,9);
										continue;
								}
							}
				            if(lopCanXoa[i] ==27) {//nhan nut esc
			            			clearPartOfScreen(xIn,8,xIn+20+i,9); 
	 								goto T;
							}
							if(lopCanXoa[i]==32) {//space
						            goto InpD;
							}
				            if(lopCanXoa[i]==8) {//xoa
								i--;if(i<0){i=0;}
				                else{
					                backSpace(xIn+15+i,9);
					                gotoxy(xIn+15+i,9);
				                }
				            }
				            else{
			       					printf("%c",(char)lopCanXoa[i]);i++;
							}
				        }
				        fflush(stdin);
				    	lopCanXoa[i] = '\0';
				    	while(true) {
				    		if(strlen(lopCanXoa)<2){
			    				gotoxy(xIn+15,10);colorText(234);
			    				printf("Nhap 2kytu tro len!");//20
			    				Sleep(500);
			    				clearPartOfScreen(xIn+15,10,xIn+15+20,10);//xoa vung bat loi
			    				goto InpD;
							}
							else {//neu dung
								strupr(lopCanXoa);//tu dong viet hoa
								clearPartOfScreen(xGd-23,yGd+5,xGd+38+10+5,yIn+5+38);//xoa dslop lop de hien thi dslop tim xoa
								break;
							}
						}
						//-----tim
						for(int k=0;k<dslop->n;k++){
							if(findsubstr(dslop->lop[k]->malop, lopCanXoa ) != -1){
								colorText(78);
							 	found = true;
								 fflush(stdin);
								gotoxy(xGd-23,yGd+5+vitri);
						        printf("%s",dslop->lop[k]->malop);
						        gotoxy(xGd-10,yGd+5+vitri);
							    printf("%s",dslop->lop[k]->tenlop);
							    gotoxy(xGd+38,yGd+5+vitri);
							    printf("%s",dslop->lop[k]->nienkhoa);
							    gotoxy(xGd+38+10+2,yGd+5+vitri);
						    	printf("%d",countSV_DSLOP(dslop,dslop->lop[k]->malop));
							    vitri = vitri + 2;//in ds cho rong
							    clearColor();
							}
						}
						//----so sanh dung
						for(int k = 0; k< dslop->n ; k++){
							if(stricmp(dslop->lop[k]->malop, lopCanXoa) == 0)
							{	
								gotoxy(xIn,10);
								printf("----------");
								if(YES_NO(diemxy, 25, 4,"BAN CO MUON XOA LOP?")){//yes
									timViTriXL(dslop,k);
								  	saveDSLop(dslop);
									gotoxy(xIn+5,26);colorText(206);printf("Xoa thanh cong!");
								  	Sleep(500);
									clearPartOfScreen(xIn,8,xIn+15+55,16);//xoa vung nhap
									clearPartOfScreen(xIn,22,50,27);
									goto T;
									break;
								}
								else {//no
									gotoxy(xIn+5,26);colorText(206);printf("Xoa that bai!");
									Sleep(500);
									clearPartOfScreen(xIn,8,xIn+15+55,16);//xoa vung nhap
									clearPartOfScreen(xIn,22,50,27);
									goto T;
									break;
								}
							}
						}
						do{
						  	c=getch();fflush(stdin);
						}while(c!=13);
						if(c==13){
							clearPartOfScreen(xIn,8,xIn+15+i,9);
							clearPartOfScreen(xGd-23,yGd+5,xGd+38+10,yGd+5+38);//xoa ds
							inLop(tick,dslop,rig);
							if(i>0)i=0;
							vitri = 0;
							goto Del;
						}
				}
				if ( c == 63) {//f5(sua)
					    SINHVIEN sv; LOP *lop; lop = (LOP*)malloc(sizeof(LOP));
						NODESINHVIEN temp=NULL;
						//lop
						char maLop[MAXML] = ""; int a = 0;
						char tenLop[MAXTL] = ""; int j = 0;
					    char nienKhoa[MAXNK] ="";	char cpstr[MAXNK]=""; int z = 0;
						//sv 
						char mSV[MAXMSV],hoSV[MAXHOSV],tenSV[MAXTENSV],phaiSV[MAXPHAI],pwSV[MAXPW];int slsv;
					    bool found = false;
				Edit:		gotoxy(xIn,8);colorText(78);
						printf("EDIT INFORM CLASS!");
						char maLopCanCapNhat[MAXML];
						clearColor();gotoxy(xIn,9);
						printf("NHAP ID CLASS: ");
					InpE:	gotoxy(xIn+15+i,9);
						while((maLopCanCapNhat[i]=getch())!=13){
							fflush(stdin);
							if(maLopCanCapNhat[i]==0){maLopCanCapNhat[i]=getch();
								if(maLopCanCapNhat[i]==59){//f1
									if(tick<=inf1(stcthuc,dslop)){
					                    tick +=1;
					                    inLop(tick,dslop,rig);
				                    }else{
					                    tick +=0;
					                    inLop(tick,dslop,rig);
				                    }
									gotoxy(xIn+15+i,9);
									continue;
								}
								if(maLopCanCapNhat[i]==60){//f2
									tick --;if(tick == 0) tick = 1;
									inLop(tick,dslop,arrow);
									gotoxy(xIn+15+i,9);
									continue;
								}
							}
							if(maLopCanCapNhat[i]==27){//nhan nut esc
									clearPartOfScreen(xIn,8,xIn+20+i,9); 
		 							goto T;
							}
							if(maLopCanCapNhat[i]==32) {//space
						            goto Edit;
							}
							if(maLopCanCapNhat[i]==8) {//xoa
					                i--;if(i<0)i=0;
					                else{
						                backSpace(xIn+15+i,9);
						                gotoxy(xIn+15+i,9);
					                }
					        }
				            else{
				       				printf("%c",(char)maLopCanCapNhat[i]);i++;
							}
						}
						strupr(maLopCanCapNhat);//tu dong viet hoa
				    	maLopCanCapNhat[i] = '\0';
				    	while(true) {
				    		if(strlen(maLopCanCapNhat)<2){
			    				gotoxy(xIn+15,10);colorText(234);
			    				printf("Nhap 2kytu tro len!");//20
			    				Sleep(500);
			    				clearPartOfScreen(xIn+15,10,xIn+15+20,10);//xoa vung bat loi
			    				goto InpE;
							}
							else {
								clearPartOfScreen(xGd-23,yGd+5,xGd+38+10+5,yIn+5+38);//xoa dslop lop de hien thi dslop tim xoa
								break;
							}
						}
						//-----tim
						int index;
						for(int k=0;k<dslop->n;k++){
							if(findsubstr(dslop->lop[k]->malop, maLopCanCapNhat ) != -1){
								colorText(30);
							 	found = true;index = k;
								 fflush(stdin);
								gotoxy(xGd-23,yGd+5+vitri);
						        printf("%s",dslop->lop[k]->malop);
						        gotoxy(xGd-10,yGd+5+vitri);
							    printf("%s",dslop->lop[k]->tenlop);
							    gotoxy(xGd+38,yGd+5+vitri);
							    printf("%s",dslop->lop[k]->nienkhoa);
							    gotoxy(xGd+38+10+2,yGd+5+vitri);
						    	printf("%d",countSV_DSLOP(dslop,dslop->lop[k]->malop));
							    vitri = vitri + 2;//in ds cho rong
							    clearColor();
							}
						}
						//----so sanh dung
						for (int k = 0; k < dslop->n; k++)
						{
							if (stricmp(dslop->lop[k]->malop, maLopCanCapNhat)==0)
							{
								gotoxy(xIn,10);
								printf("------");
								gotoxy(xIn,11);colorText(223);
								printf("Ma lop: %s",dslop->lop[k]->malop);
								gotoxy(xIn,12);colorText(223);
								printf("Ten lop: %s",dslop->lop[k]->tenlop);
								gotoxy(xIn,13);colorText(223);
								printf("Nien khoa: %s",dslop->lop[k]->nienkhoa);
								if(YES_NO(diemxy, 25, 4,"BAN CO MUON CAP NHAP?")){//yes
									strcpy(maLop,dslop->lop[k]->malop);
									strcpy(tenLop,dslop->lop[k]->tenlop);
									strcpy(nienKhoa,dslop->lop[k]->nienkhoa);
									temp=dslop->lop[k]->dssinhvien;
									slsv=countSV(temp);
									if(temp != NULL){
										strcpy(mSV,dslop->lop[k]->dssinhvien->sinhvien.masv);
										strcpy(hoSV,dslop->lop[k]->dssinhvien->sinhvien.ho);
										strcpy(tenSV,dslop->lop[k]->dssinhvien->sinhvien.ten);
										strcpy(phaiSV,dslop->lop[k]->dssinhvien->sinhvien.phai);
										strcpy(pwSV,dslop->lop[k]->dssinhvien->sinhvien.password);
									}
									else {
										slsv = 0;
									}
									clearPartOfScreen(xIn,9,xIn+32+20,14);//xoa vung xet giong roi in nhap
									clearPartOfScreen(xIn,22,50,27);
									gotoxy(xIn,9);printf("------");
									//ham nhap
									gotoxy(xIn,10);colorText(226);
								    printf("%s","Nhap ma lop: ");
								    gotoxy(xIn,12);colorText(227);
								    printf("%s","Nhap ten lop: ");
								    gotoxy(xIn,14);colorText(228);
								    printf("%s","Nhap nien khoa: ");
										
									//----nhap ma lop
									ML:   chuThichML();
									gotoxy(xIn+16+a,10);
									while((maLop[a]=getch())!=13){
						   				fflush(stdin);
						            		if(maLop[a]==27){//NUT ESC
													clearPartOfScreen(xIn,8,xIn+50,19);
													clearPartOfScreen(xIn,22,50,27);
													goto T;
								 			}
											if(maLop[a]== 32){
													goto ML;
											}			
											if(maLop[a]== -32){ maLop[a]=getch();
													if(maLop[a]==72){//NUT LEN
						                                      goto ML;
											 		}
						                     		if(maLop[a]==80){//NUT XUONG
						                                if(a>0){
															clearPartOfScreen(xIn,18,xIn+50,19);//xoa 1 vung chu thich
						                                	goto TL;
														}else{
															goto ML;
														}
													}
													if(maLop[a]==75 || maLop[a]==77) {
															goto ML;	
													}
											}
						                    if(maLop[a]==8) {//NUT BACKSPACE
			                                     a--;if(a<0)a=0;
			                                     else{
			                                         backSpace(xIn+16+a,10);
			                                         gotoxy(xIn+16+a,10);
			                                     }
			                                }
						                     else{
						                          	printf("%c",(char)maLop[a]);a++;
											 }
									    }
										maLop[a]='\0';
										while (true){
											if(trungMaLopForEdit(maLop,dslop,index)==true ){//kt trung
								      			gotoxy(xIn+15,16);colorText(234);
												printf("%s","Ma lop nay da ton tai!!");
												Sleep(500);
												clearPartOfScreen(xIn+15,16,(xIn+15)+35,16);//xoa 1 vung bat loi
												goto ML;
											}
											if(dinhdangMaLop(maLop)==false){//ky tu
												gotoxy(xIn+15,16);colorText(234);
												printf("%s","Ma lop sai dinh dang!!!");
												Sleep(500);
												clearPartOfScreen(xIn+15,16,(xIn+15)+35,16);//xoa 1 vung bat loi
												goto ML;
											}
											else {
												strupr(maLop);//tu dong viet hoa
												clearPartOfScreen(xIn,18,xIn+50,19);//xoa 1 vung chu thich
												goto TL;
											}
										}
										
										fflush(stdin); 
									//----nhap ten lop
									TL:	chuThichTL();
									   gotoxy(xIn+16+j,12);
									   while((tenLop[j]=getch())!=13){
						   					fflush(stdin);
				                             if(tenLop[j]==27){//NUT ESC
													clearPartOfScreen(xIn,8,xIn+50,19);
													clearPartOfScreen(xIn,22,50,27);
													goto T;
								 			}
											 fflush(stdin);
											 if(tenLop[j]== -32){tenLop[j]=getch();
								 				if(tenLop[j]==72){//NUT LEN
								 						clearPartOfScreen(xIn,18,xIn+50,19);//xoa 1 vung chu thich
														goto ML;
												}
	                             				if(tenLop[j]==80){//NUT XUONG
		                                            if(j>0){
		                                            	clearPartOfScreen(xIn,18,xIn+50,19);//xoa 1 vung chu thich
					                                	goto NK;
													}else{
														goto TL;
													}
												}
												if(tenLop[j]==75 || tenLop[j]==77) {
														goto TL;	
												}
									 		}
				                             if(tenLop[j]==8) {//NUT BACKSPACE
                                                 j--;if(j<0){j=0;}
                                                 else{
	                                                 backSpace(xIn+16+j,12);
	                                                 gotoxy(xIn+16+j,12);
                                                 }
		                                    }
				                             else{
				                                  printf("%c",(char)tenLop[j]);j++;
											 }  
									    }
									    xoaKhoangTrang(tenLop);
										tenLop[j]='\0';
									    while (true){
									    	if(trungTenLopForEdit(tenLop,dslop,index)==true){//trung
									    		gotoxy(xIn+15,16);colorText(234);
												printf("%s","Ten lop nay da ton tai!!");
												Sleep(500);
												clearPartOfScreen(xIn+15,16,(xIn+15)+35,16);//xoa 1 vung bat loi
												goto TL;
											}
											if(strlen(tenLop)==0 || strlen(tenLop)>MAXTL){//do dai
												gotoxy(xIn+15,16);colorText(234);
												printf("%s","Do dai TL khong hop le!!");
												Sleep(500);
												goto TL;
											}
											if(ktNhapVoPhaiCoKyTuSo(tenLop)==false){
												gotoxy(xIn+15,16);colorText(234);
												printf("%s","Ten lop thieu nien khoa!");
												Sleep(500);
												clearPartOfScreen(xIn+15,16,(xIn+15)+35,16);//xoa 1 vung bat loi
												goto TL;
											}
											else {
												strupr(tenLop);//tu dong viet hoa
												clearPartOfScreen(xIn,18,xIn+50,19);//xoa 1 vung chu thich
												goto NK;
											}
										}
										
										fflush(stdin); 
									//----nhap nien khoa
									NK: chuThichNK();
										gotoxy(xIn+16+z,14);
									    while((nienKhoa[z]=getch())!=13){
					    					fflush(stdin);
				                             if(nienKhoa[z]==27){//NUT ESC
						            				clearPartOfScreen(xIn,8,xIn+50,19);
													clearPartOfScreen(xIn,22,50,27);
													goto T;
								 			}
									 		fflush(stdin);
								 			if(nienKhoa[z]== -32){nienKhoa[z]=getch();
								 				if(nienKhoa[z]=72){//NUT LEN
						 						   clearPartOfScreen(xIn,18,xIn+50,19);//xoa 1 vung chu thich
	                                               goto TL; 
												}
			                             		if(nienKhoa[z]==80){//NUT XUONG
												   goto NK; 
												}
												if(nienKhoa[z]==75 || nienKhoa[z]==77){
													goto NK; 
												}
											}
				                             if(nienKhoa[z]==8) {//NUT BACKSPACE
                                                 z--;if(z<0){z=0;}
                                                 else{
	                                                 backSpace(xIn+16+z,14);
	                                                 gotoxy(xIn+16+z,14);
                                                 }
				                            }
				                             else{
				                                  printf("%c",(char)nienKhoa[z]);z++;
				                                  strcpy(cpstr,nienKhoa);//cpy de so sanh 2 nien khoa
				                             }
									    }
										nienKhoa[z]='\0';
									    while (true){
									    	if(dinhdangNienKhoa(nienKhoa)==false){
									    		gotoxy(xIn+15,16);colorText(234);
												printf("%s","Nien khoa sai dinh dang yyyy-yyyy!");
												Sleep(500);
												clearPartOfScreen(xIn+15,16,(xIn+15)+40,16);//xoa 1 vung bat loi
												goto NK;
											}
											if(tachChuoivaSoSanhNK(cpstr)==false){
												gotoxy(xIn+15,16);colorText(234);
												printf("%s","Nien khoa sau > nien khoa truoc!!!");
												Sleep(500);
												clearPartOfScreen(xIn+15,16,(xIn+15)+40,16);//xoa 1 vung bat loi
												goto NK;
											}
											else {
												clearPartOfScreen(xIn,18,xIn+50,19);//xoa 1 vung chu thich
												goto X;
												break;
											}
										}
							//--------		
							X :		strcpy(lop->malop,maLop);
									strcpy(lop->tenlop,tenLop);
									strcpy(lop->nienkhoa,nienKhoa);
									lop->dssinhvien = temp;
									if(YES_NO(diemxy, 25, 4,"BAN CO MUON LUU FILE?")){//yes
										timViTriXL(dslop,k);
										insertClass(dslop,lop);
										saveDSLop(dslop);
										gotoxy(xIn+5,26);colorText(206);printf("Luu thanh cong!");
										Sleep(500);
										clearPartOfScreen(xIn,8,xIn+50,19); 
										clearPartOfScreen(xIn,22,50,27);
										goto T;
										break;
									}
									else {
										gotoxy(xIn+5,26);colorText(206);printf("Luu that bai!");
										Sleep(500);
										clearPartOfScreen(xIn,8,xIn+32+20,14);//xoa vung nhap
										clearPartOfScreen(xIn,22,50,27);
										goto T;
										break;
									}
								}
								else {//no
									clearPartOfScreen(xIn,8,xIn+32+20,14);//xoa vung nhap
									clearPartOfScreen(xIn,22,50,27);
									goto T;
									break;
								}
							}
						}
						do{
						  	c=getch();fflush(stdin);
						}while(c!=13);
						if(c==13){
							clearPartOfScreen(xIn,8,xIn+15+i,9);
							clearPartOfScreen(xGd-23,yGd+5,xGd+38+10,yGd+5+38);//xoa ds
							inLop(tick,dslop,rig);
							if(i>0)i=0;
							vitri = 0;
							goto Edit;
						}
				}
			}
			if( c == 77 ){ //PHAI
				rig = true;
				inLop(tick,dslop,rig);
				rig = false;
				goto T;
			}
			if ( c == 27 ){
				return; 
				menuQuanLyLop(dslop);
			}
		}
}
//NHAP 1 LOP
void nhapDSLopMoi(DSLOP *dslop){
	fflush(stdin);
	LOP *lop; lop = (LOP*)malloc(sizeof(LOP));
    char c;	int tick=1;	int stcthuc = dslop->n/20; bool rig = false;
	//
    char maLop[MAXML] = ""; int i = 0;
	char tenLop[MAXTL] = ""; int j = 0;
    char nienKhoa[MAXNK] ="";	char cpstr[MAXNK]=""; int z = 0; 
    //
    OBJECR_LCT diemxy;
	   diemxy.x=xIn;
	   diemxy.y=xIn+7;
	//
	gotoxy(xIn,10);colorText(226);
    printf("%s","Nhap ma lop: ");
    gotoxy(xIn,12);colorText(227);
    printf("%s","Nhap ten lop: ");
    gotoxy(xIn,14);colorText(228);
    printf("%s","Nhap nien khoa: ");
	
//----nhap ma lop
ML:   chuThichML();
   gotoxy(xIn+16+i,10);
   while((maLop[i]=getch())!=13){
   				fflush(stdin);
   					 if(maLop[i] == 0){maLop[i] = getch();
   					 			 if (maLop[i] == 59) {//nut f1
							   			if(tick<=inf1(stcthuc,dslop)){
						                    tick +=1;
						                    inLop(tick,dslop,rig);
					                    }else{
						                    tick +=0;
						                    inLop(tick,dslop,rig);
					                    }
										gotoxy(xIn+16+i,10);
										continue;
									}
			   					 if (maLop[i] == 60) {//nut f2
							    		tick --;if(tick == 0) tick = 1;
										inLop(tick,dslop,rig);
										gotoxy(xIn+16+i,10);
										continue;
									}
						}
            		 if(maLop[i]==27){//NUT ESC
									clearPartOfScreen(xIn,10,xIn+50,19);
									clearPartOfScreen(xIn,22,50,27);
									return; Input_Class(dslop);
				 			}
					 if (maLop[i] == 32) {//nut space
					    		goto ML;
							}
					 if(maLop[i]== -32){ maLop[i]=getch();
									if(maLop[i]==72){//NUT LEN
		                                    goto ML;
							 		}
		                     		if(maLop[i]==80){//NUT XUONG
		                                if(i>0){
		                                	clearPartOfScreen(xIn,18,xIn+50,19);//xoa 1 vung chu thich
		                                	goto TL;
										}else{
											goto ML;
										}
									}
									if(maLop[i]==75||maLop[i]==77){
										goto ML;
									}
							}
                     if(maLop[i]==8) {//NUT BACKSPACE
                                     i--;if(i<0)i=0;
                                     else{
                                         backSpace(xIn+16+i,10);
                                         gotoxy(xIn+16+i,10);
                                     }
                                }
                     else{
                          	printf("%c",(char)maLop[i]);i++;
					  }
    }
	maLop[i]='\0';
	while (true){
		if(trungMaLop(maLop,dslop)==true){//kt trung
      			gotoxy(xIn+15,16);colorText(234);
				printf("%s","Ma lop nay da ton tai!!");
				Sleep(500);
				clearPartOfScreen(xIn+15,16,(xIn+15)+35,16);//xoa 1 vung bat loi
				goto ML;
		}
		if(dinhdangMaLop(maLop)==false){//ky tu
				gotoxy(xIn+15,16);colorText(234);
				printf("%s","Ma lop sai dinh dang!!!");
				Sleep(500);
				clearPartOfScreen(xIn+15,16,(xIn+15)+35,16);//xoa 1 vung bat loi
				goto ML;
		}
		else {
				strupr(maLop);//tu dong viet hoa
				clearPartOfScreen(xIn,18,xIn+50,19);//xoa 1 vung chu thich
				goto TL;
		}
	}
	
	fflush(stdin); 
//----nhap ten lop
TL:	chuThichTL();
   gotoxy(xIn+16+j,12);
   while((tenLop[j]=getch())!=13){
   					fflush(stdin);
   					         if(tenLop[j] == 0){ tenLop[j]=getch();
		   							 if(tenLop[j] == 59) {//nut f1
									   			if(tick<=inf1(stcthuc,dslop)){
								                    tick +=1;
								                    inLop(tick,dslop,rig);
							                    }else{
								                    tick +=0;
								                    inLop(tick,dslop,rig);
							                    }
												gotoxy(xIn+16+j,12);
												continue;
											}
									 if(tenLop[j] == 60) {//nut f2
									   			tick --;if(tick == 0) tick = 1;
												inLop(tick,dslop,rig);
												gotoxy(xIn+16+j,12);
												continue;
											}
								}
                             if(tenLop[j]==27){//NUT ESC
										clearPartOfScreen(xIn,10,xIn+50,19);
										clearPartOfScreen(xIn,22,50,27);
										return; Input_Class(dslop);
					 			}
						 fflush(stdin);
							 if(tenLop[j]== -32){tenLop[j]=getch();
							 				if(tenLop[j]==72){//NUT LEN
							 					clearPartOfScreen(xIn,18,xIn+50,19);//xoa 1 vung chu thich
												goto ML;
											}
                             				if(tenLop[j]==80){//NUT XUONG
	                                            if(j>0){
	                                            	clearPartOfScreen(xIn,18,xIn+50,19);//xoa 1 vung chu thich
				                                	goto NK;
												}else{
													goto TL;
												}
											}
											if(tenLop[j]==75||tenLop[j]==77){
												goto TL;
											}
							 		}
                             if(tenLop[j]==8) {//NUT BACKSPACE
                                                 j--;if(j<0){j=0;}
                                                 else{
	                                                 backSpace(xIn+16+j,12);
	                                                 gotoxy(xIn+16+j,12);
                                                 }
                                    }
                             else{
                                  printf("%c",(char)tenLop[j]);j++;
							 }  
    }
    xoaKhoangTrang(tenLop);
	tenLop[j]='\0';
    while (true){
    	if(trungTenLop(tenLop,dslop)==true){//trung
    		gotoxy(xIn+15,16);colorText(234);
			printf("%s","Ten lop nay da ton tai!!");
			Sleep(500);
			clearPartOfScreen(xIn+15,16,(xIn+15)+35,16);//xoa 1 vung bat loi
			goto TL;
		}
		if(strlen(tenLop)==0 || strlen(tenLop)>MAXTL){//do dai
			gotoxy(xIn+15,16);colorText(234);
			printf("%s","Do dai TL khong hop le!!");
			Sleep(500);
			clearPartOfScreen(xIn+15,16,(xIn+15)+35,16);//xoa 1 vung bat loi
			goto TL;
		}
		if(ktNhapVoPhaiCoKyTuSo(tenLop)==false){
			gotoxy(xIn+15,16);colorText(234);
			printf("%s","Ten lop thieu nien khoa!");
			Sleep(500);
			clearPartOfScreen(xIn+15,16,(xIn+15)+35,16);//xoa 1 vung bat loi
			goto TL;
		}
		else {
			strupr(tenLop);//tu dong viet hoa
			clearPartOfScreen(xIn,18,xIn+50,19);//xoa 1 vung chu thich
			goto NK;
		}
	}
	
	fflush(stdin); 
//----nhap nien khoa
NK: chuThichNK();
	gotoxy(xIn+16+z,14);
    while((nienKhoa[z]=getch())!=13){
    					fflush(stdin);
    						 if(nienKhoa[z] == 0){nienKhoa[z]=getch();
		    						 if (nienKhoa[z] == 59) {//nut f1
									   			if(tick<=inf1(stcthuc,dslop)){
								                    tick +=1;
								                    inLop(tick,dslop,rig);
							                    }else{
								                    tick +=0;
								                    inLop(tick,dslop,rig);
							                    }
												gotoxy(xIn+16+j,12);
												continue;
											}
									 if (nienKhoa[z] == 60) {//nut f2
									   			tick --;if(tick == 0) tick = 1;
												inLop(tick,dslop,rig);
												gotoxy(xIn+16+z,14);
												continue;
											}
								}
                             if(nienKhoa[z]==27){//NUT ESC
										clearPartOfScreen(xIn,10,xIn+50,19);
										clearPartOfScreen(xIn,22,50,27);
										return; Input_Class(dslop);
					 			}
					 		fflush(stdin);
					 			if(nienKhoa[z]== -32){nienKhoa[z]=getch();
							 				if(nienKhoa[z]=72){//NUT LEN
							 						   clearPartOfScreen(xIn,18,xIn+50,19);//xoa 1 vung chu thich
		                                               goto TL; 
													}
		                             		if(nienKhoa[z]==80){//NUT XUONG
													   goto NK; 
													}
											if(nienKhoa[z]==75 || nienKhoa[z]==77){
												goto NK;
											}
								 	}
                             if(nienKhoa[z]==8) {//NUT BACKSPACE
                                                 z--;if(z<0){z=0;}
                                                 else{
	                                                 backSpace(xIn+16+z,14);
	                                                 gotoxy(xIn+16+z,14);
                                                 }
                                    }
                             else{
                                  printf("%c",(char)nienKhoa[z]);z++;
                                  strcpy(cpstr,nienKhoa);//cpy de so sanh 2 nien khoa
                             }
    }
	nienKhoa[z]='\0';
    while (true){
    	if(dinhdangNienKhoa(nienKhoa)==false){
    		gotoxy(xIn+15,16);colorText(234);
			printf("%s","Nien khoa sai dinh dang yyyy-yyyy!");
			Sleep(500);
			clearPartOfScreen(xIn+15,16,(xIn+15)+40,16);//xoa 1 vung bat loi
			goto NK;
		}
		if(tachChuoivaSoSanhNK(cpstr)==false){
			gotoxy(xIn+15,16);colorText(234);
			printf("%s","Nien khoa sau > nien khoa truoc!!!");
			Sleep(500);
			clearPartOfScreen(xIn+15,16,(xIn+15)+40,16);//xoa 1 vung bat loi
			goto NK;
		}
		else {
			clearPartOfScreen(xIn,18,xIn+50,19);//xoa 1 vung chu thich
			goto check;
			break;
		}
	}
check:	
	if(YES_NO(diemxy, 25, 4,"BAN CO MUON LUU FILE?")){//yes
		strcpy(lop->malop,maLop);
		strcpy(lop->tenlop,tenLop);
		strcpy(lop->nienkhoa,nienKhoa);
		lop->dssinhvien == NULL;
		insertClass(dslop,lop);	
		saveDSLop(dslop);
  		gotoxy(xIn+7,24);colorText(203);printf("Luu thanh cong!");
  		Sleep(500);
		clearPartOfScreen(xIn,22,50,27);
		inLop(tick,dslop,rig);
	}
	else {//no
		gotoxy(xIn+7,24);colorText(203);printf("Luu that bai!");
	  	Sleep(500);
		clearPartOfScreen(xIn,22,50,27);
	}
}
//------------Function For MonHoc
//ham them mon
void insertObject(DSMON *dsmon,MON *mon) {
      
       int count;
       MON *temp ;
       temp = (MON *)malloc(sizeof(MON));
       strcpy(temp->mamh,mon->mamh);
       strcpy(temp->tenmh,mon->tenmh);
       count = (dsmon->n);
       dsmon->mon[count] = temp; 
       (dsmon->n) = count+1; 
}
//nhap mon
void Input_Mon(DSMON *dsmon){
	systemCls();
    char c; int tick=1;	int stcthuc = dsmon->n/20;
    int arrow = -1;bool rig = false;
 T:   inMon(tick,dsmon,rig);
			OBJECR_LCT diemxy;
			diemxy.x=xIn;
			diemxy.y=xIn+7;
    int i = 0; int vitri = 0;
    //dk ds
	if(Empty_M(dsmon) == 1){	gotoxy(xGd+3,yGd+7);printf("DS rong! Khoi tao file DSMON!");	nhapDSMon(dsmon); }
	else {
RP:		while(true){
			do{
			  	c=getch();fflush(stdin);
			}while(c!=27 && c!=9 && c!=0 && c!=59 && c!=60 && c!=61 && c!=72 && c!=75 && c!=77 && c!=80);
			if ( c == 27 ){//exit
				return;//menuQuanLyMonHoc(dsmon);
				DSLOP *dslop;NODECAUHOI dscauhoi;
				menu(dslop,dsmon,dscauhoi);
			}
			if ( c == 9 ){//tab(tra cuu)
					bool found = false;	
			TC:	gotoxy(xIn,8);colorText(46);
				printf("TRA CUU MON HOC!");clearColor();
					while(true){	//CHON O DAY 
					   	colorText(IDCOLOR_CLEARTEXT);
					     gotoxy(xIn+25,10);printf("%s","THEO MA");
						 gotoxy(xIn+25,12);printf("%s","THEO TEN");
						 char c;
					     int arrow = -1;
					W:   if(kbhit()){
					     	c = getch();
					     	if(c==80){
					     		arrow++;
					     		if(arrow>1)arrow = 0;
					     		if(arrow==0){
					     			gotoxy(xIn+25,10);printf("%s","THEO MA");
					     			colorText(160);
					     			gotoxy(xIn+25,12);printf("%s","THEO TEN");
					                colorText(IDCOLOR_CLEARTEXT);
								}
								 if(arrow==1){
								 	gotoxy(xIn+25,12);printf("%s","THEO TEN");
								 	colorText(160);
								 	gotoxy(xIn+25,10);printf("%s","THEO MA");
								 	whiteColor();colorText(IDCOLOR_CLEARTEXT);
								}
							}
					     	if(c==72){
					     		arrow--;
								if(arrow<0)	arrow = 1;
					     		if(arrow==0){
					     			gotoxy(xIn+25,10);printf("%s","THEO MA");
					     			colorText(160);
					     			gotoxy(xIn+25,12);printf("%s","THEO TEN");
					     			whiteColor();colorText(IDCOLOR_CLEARTEXT);
								}
								if(arrow==1){
								 	gotoxy(xIn+25,12);printf("%s","THEO TEN");
								 	colorText(160);
								 	gotoxy(xIn+25,10);printf("%s","THEO MA");
								 	whiteColor();colorText(IDCOLOR_CLEARTEXT);
								}
					        }
					     	if(c==27){//ESC
					     		clearPartOfScreen(xIn,8,xIn+25+8,12);
					     		goto T;
							}
							if(c==13 &&arrow!=-1 ){
								clearPartOfScreen(xIn+25,10,xIn+25+8,12);
								switch(arrow){
									case 1:{	//TIM MA
									TimM:			char timMon[MAXTMH];
												gotoxy(xIn,9);
												printf("Nhap ma mon can tim: ");//21
												gotoxy(xIn+21+i,9);
												while((timMon[i]=getch())!=13){
													fflush(stdin);
														if(timMon[i]== -32){ timMon[i]=getch();
															if ( timMon[i] == 72 || timMon[i] == 75 ){//len=trai
																tick --;if(tick == 0) tick = 1;
																inMon(tick,dsmon,rig);
																gotoxy(xIn+21+i,9);
																continue;
															}
															if ( timMon[i] == 77 || timMon[i] == 80 ){//xuong=phai
																if(tick<=inMf1(stcthuc,dsmon)){
																	tick+=1;
																	inMon(tick,dsmon,rig);
																}else{
																	tick+=0;
																	inMon(tick,dsmon,rig);
																}
																gotoxy(xIn+21+i,9);
																continue;
															}
														}
														if(timMon[i]==27){//esc
															clearPartOfScreen(xIn,9,xIn+21+i,9);//XOA THANG NHAP
															goto TC;
														}
														if(timMon[i] == 8) {//xoa
											                i--;if(i<0)i=0;
											                else{
													                backSpace(xIn+21+i,9);
													                gotoxy(xIn+21+i,9);
											                }
											            }
														else{
											       				printf("%c",(char)timMon[i]);i++;
														}
												}
												fflush(stdin); 
												timMon[i] = '\0';
												while(true){
													if(i==0||i>=MAXTMH){
														gotoxy(xIn+30,10);colorText(234);
														printf("Do dai khong hop le!");//20
														Sleep(500);
														clearPartOfScreen(xIn+30,10,xIn+30+20,10);//xoa bat loi
														goto TimM;
													}
													else {
														strupr(timMon);
														clearPartOfScreen(xGd-23,yGd+5,xGd+38+10,yGd+5+38);
														break;
													}
												}
												sapXepMon(dsmon);
												for(int i=0;i<dsmon->n;i++){
													if((findsubstr(dsmon->mon[i]->mamh, timMon)!= -1) && strcmp(timMon, " ") != 0 && strcmp(timMon, "\0") != 0) { 
														found = true;
														fflush(stdin);
														gotoxy(xGd-18,yGd+5+vitri);
												        printf("%s",dsmon->mon[i]->mamh);
												        gotoxy(xGd-5,yGd+5+vitri);
													    printf("%s\n",dsmon->mon[i]->tenmh);
														vitri =vitri+2;
													}
												}
												do{
												  	c=getch();fflush(stdin);
												}while(c!=27&&c!=13);
												if(c==13){
													clearPartOfScreen(xIn,8,xIn+21+i,9);
													clearPartOfScreen(xGd-23,yGd+5,xGd+38+10,yGd+5+38);
													inMon(tick,dsmon,rig);
													if(i>0)i=0;
													vitri = 0;
													goto TimM;
												}
												if(c==27){
													clearPartOfScreen(xIn,8,xIn+21+i,9);
													if(i>0)i=0;
													vitri = 0;
													goto TC;
												}
									}
									case 0:{	//TIM TEN
									TimTM:		char timMon[MAXTMH];
											gotoxy(xIn,9);
											printf("Nhap ten mon can tim: ");//22
											gotoxy(xIn+22+i,9);
											while((timMon[i]=getch())!=13){
												fflush(stdin);
													if(timMon[i]== -32){ timMon[i]=getch();
														if ( timMon[i] == 72 || timMon[i] == 75 ){//len=trai
															tick --;if(tick == 0) tick = 1;
															inMon(tick,dsmon,rig);
															gotoxy(xIn+22+i,9);
															continue;
														}
														if ( timMon[i] == 77 || timMon[i] == 80 ){//xuong=phai
															if(tick<=inMf1(stcthuc,dsmon)){
																tick+=1;
																inMon(tick,dsmon,rig);
															}else{
																tick+=0;
																inMon(tick,dsmon,rig);
															}
															gotoxy(xIn+22+i,9);
															continue;
														}
													}
													if(timMon[i]==27){//esc
														clearPartOfScreen(xIn,9,xIn+22+i,9);//XOA THANG NHAP
														goto TC;
													}
													if(timMon[i] == 8) {//xoa
										                i--;if(i<0)i=0;	
										                else{
												                backSpace(xIn+22+i,9);
												                gotoxy(xIn+22+i,9);
										                }
										            }
													else{
										       				printf("%c",(char)timMon[i]);i++;
										       				strupr(timMon);
													}
											}
											fflush(stdin); 
											timMon[i] = '\0';
											while(true){
												if(i==0||i>=MAXTMH){
													gotoxy(xIn+30,10);colorText(234);
													printf("Nhap 1kytu tro len!");//20
													Sleep(100);
													clearPartOfScreen(xIn+30,10,xIn+30+20,10);//xoa bat loi
													goto TimTM;
												}
												else {
													clearPartOfScreen(xGd-23,yGd+5,xGd+38+10,yGd+5+38);
													break;
												}
											}
											sapXepMon(dsmon);
											for(int i=0;i<dsmon->n;i++){
												if((findsubstr(dsmon->mon[i]->tenmh, timMon)!= -1) && strcmp(timMon, " ") != 0 && strcmp(timMon, "\0") != 0) { 
													found = true;
													fflush(stdin);
													gotoxy(xGd-18,yGd+5+vitri);
											        printf("%s",dsmon->mon[i]->mamh);
											        gotoxy(xGd-5,yGd+5+vitri);
												    printf("%s\n",dsmon->mon[i]->tenmh);
													vitri =vitri+2;
												}
											}
											do{
											  	c=getch();fflush(stdin);
											}while(c!=27&&c!=13);
											if(c==13){
												clearPartOfScreen(xIn,8,xIn+22+i,9);
												clearPartOfScreen(xGd-23,yGd+5,xGd+38+10,yGd+5+38);
												inMon(tick,dsmon,rig);
												if(i>0)i=0;
												vitri = 0;
												goto TimTM;
											}
											if(c==27){
												clearPartOfScreen(xIn,8,xIn+22+i,9);
												if(i>0)i=0;
												vitri = 0;
												goto TC;
											}
									}
								}
							}
						}goto W;
					} 
			}
			if( c == 0 ){ c = getch();
				if ( c == 59 ){//f1 insert
					if(Full_M(dsmon) == 1) {	
						gotoxy(xIn+3,yIn+7);
						printf("DS full khong the them!");	
						Sleep(500);
						clearPartOfScreen(xIn+3,yIn+7,xIn+3+23,yIn+7); 
						goto RP;
					}
					else{
					N:		gotoxy(xIn,8);colorText(233);
			    		printf("So luong mon hien co: %d",(dsmon->n));
						if(YES_NO(diemxy, 25, 4,"BAN CO MUON THEM MON?")){//YES
							clearPartOfScreen(xIn,22,50,27);
						  	nhapDSMon(dsmon);
						  	clearPartOfScreen(xIn,10,xIn+50,12);//XOA VUNG NHAP
							clearPartOfScreen(xIn,8,xIn+24+(dsmon->n),8);//xoa lai de in vung so luong
							inMon(tick,dsmon,rig);
							goto N;
						}
						else {//NO
							clearPartOfScreen(xIn,8,xIn+24+(dsmon->n),8);//xoa lai de in vung so luong
							clearPartOfScreen(xIn,22,50,27);
						    goto RP;
						}
					}
				}
				if ( c == 60 ){//f2(del)
						bool found = false;
			Del:		gotoxy(xIn,8);colorText(30);	
					printf("XOA MON HOC!");
					char monCanXoa[MAXMMH];
					clearColor();gotoxy(xIn,9);
					printf("NHAP MA MON: ");
					gotoxy(xIn+13+i,9);
					while((monCanXoa[i]=getch())!=13){
						fflush(stdin);
								if(monCanXoa[i]== -32){ monCanXoa[i]=getch();
									if (monCanXoa[i] == 77 || monCanXoa[i] == 80) {
													if(tick<=inMf1(stcthuc,dsmon)){
										   			    tick+=1;
														inMon(tick,dsmon,rig);
													}
													else {
														tick+=0;
														inMon(tick,dsmon,rig);
													}
													gotoxy(xIn+13+i,9);
													continue;
												}
									if (monCanXoa[i] == 72 || monCanXoa[i] == 75) {
										   			tick --;if(tick == 0) tick = 1;
										    		inMon(tick,dsmon,rig);
													gotoxy(xIn+13+i,9);
													continue;
												}
								}
					            if(monCanXoa[i] ==27) {//nhan nut esc
					            		clearPartOfScreen(xIn,8,xIn+20+i,9); 
										goto T;
								}
								if(monCanXoa[i]==32) {//space
						                goto Del;
							    }
					            if(monCanXoa[i]==8) {//backspace
					                i--;if(i<0){i=0;}
					                else{
						                backSpace(xIn+13+i,9);
						                gotoxy(xIn+13+i,9);continue;
					                }
					            }
					            if(monCanXoa[i]>=65&&monCanXoa[i]<=90||monCanXoa[i]>=97&&monCanXoa[i]<=122||monCanXoa[i]>=48&&monCanXoa[i]<=57 || monCanXoa[i]==45){
					       				printf("%c",(char)monCanXoa[i]);i++;
								}
			        }
			        fflush(stdin);
			    	monCanXoa[i] = '\0';
			    	while(true) {
			    		if(strlen(monCanXoa)==0){
			    				gotoxy(xIn+13,10);colorText(234);
			    				printf("Khong duoc de trong!");//20
			    				Sleep(500);
			    				clearPartOfScreen(xIn+13,10,xIn+13+20,10);//xoa vung bat loi
			    				goto Del;
						}
						else {
							strupr(monCanXoa);//tu dong viet hoa
							clearPartOfScreen(xGd-23,yGd+5,xGd+38+10,yGd+5+38);
							break;
						}
					}
					for(int k=0;k<dsmon->n;k++){
						if(findsubstr(dsmon->mon[k]->mamh, monCanXoa)!= -1) { 
							colorText(78);
							found = true;
							fflush(stdin);
							gotoxy(xGd-18,yGd+5+vitri);
					        printf("%s",dsmon->mon[k]->mamh);
					        gotoxy(xGd-5,yGd+5+vitri);
						    printf("%s\n",dsmon->mon[k]->tenmh);
							vitri =vitri+2;
							clearColor();
						}
					}
					//----so sanh dung
					for(int k = 0; k< dsmon->n ; k++){
						if(stricmp(dsmon->mon[k]->mamh, monCanXoa) == 0)
						{	
							gotoxy(xIn,10);
							printf("------");
							if(YES_NO(diemxy, 25, 4,"BAN CO MUON XOA MON?")){//YES
								timViTriXM(dsmon,k);
								gotoxy(xIn+5,26);colorText(206);printf("Xoa thanh cong!");
							  	saveDSMonMoi(dsmon);
							  	Sleep(500);
								clearPartOfScreen(xIn,8,xIn+15+55,16);//xoa vung nhap
								clearPartOfScreen(xIn,22,50,27);
								goto T;
								break;
							}
							else {//NO
								gotoxy(xIn+5,26);colorText(206);printf("Xoa that bai!");
								Sleep(500);
								clearPartOfScreen(xIn,8,xIn+15+55,16);//xoa vung nhap
								clearPartOfScreen(xIn,22,50,27);
								goto T;
								break;
							}
						}
					}
					do{
					  	c=getch();fflush(stdin);
					}while(c!=13);
					if(c==13){
						clearPartOfScreen(xIn,8,xIn+21+i,9);
						clearPartOfScreen(xGd-23,yGd+5,xGd+38+10,yGd+5+38);//xoa ds
						inMon(tick,dsmon,rig);
						if(i>0)i=0;
						vitri = 0;
						goto Del;
					}
				}
				if ( c == 61 ){//f3(edit)
						bool found = false;MON *mon; mon = (MON*)malloc(sizeof(MON));
						char maMon[MAXMMH],tenMon[MAXTMH];
						int a=0,b=0;
			Edit:		gotoxy(xIn,8);colorText(78);
					printf("EDIT INFORM SUBJECT!");
					char maMonCanCapNhat[MAXMMH];
					clearColor();gotoxy(xIn,9);
					printf("NHAP MA MON: ");
					gotoxy(xIn+13+i,9);
					while((maMonCanCapNhat[i]=getch())!=13){
							fflush(stdin);
								if(maMonCanCapNhat[i]== -32){ maMonCanCapNhat[i]=getch();
									if (maMonCanCapNhat[i] == 77||maMonCanCapNhat[i] == 80) {
										   			if(tick<=inMf1(stcthuc,dsmon)){
										   			    tick+=1;
														inMon(tick,dsmon,rig);
													}
													else {
														tick+=0;
														inMon(tick,dsmon,rig);
													}
													gotoxy(xIn+13+i,9);
													continue;
											}
									if (maMonCanCapNhat[i] == 72 || maMonCanCapNhat[i] == 75) {
										   			tick --;if(tick == 0) tick = 1;
										    		inMon(tick,dsmon,rig);
													gotoxy(xIn+13+i,9);
													continue;
											}
								}
								if(maMonCanCapNhat[i]==27){//nhan nut esc
										clearPartOfScreen(xIn,8,xIn+20+i,9); 
										goto T;
								}
								if(maMonCanCapNhat[i]==32) {//space
							            goto Edit;
								}
								if(maMonCanCapNhat[i]==8) {//xoa
						                i--;if(i<0){i=0;}
						                else{
							                backSpace(xIn+13+i,9);
							                gotoxy(xIn+13+i,9);
						                }
						        }
					            else{
					       				printf("%c",(char)maMonCanCapNhat[i]);i++;
								}
					}
					fflush(stdin);
			    	maMonCanCapNhat[i] = '\0';
			    	while(true) {
			    		if(strlen(maMonCanCapNhat)==0){
			    				gotoxy(xIn+13,10);colorText(234);
			    				printf("Khong duoc de trong!");//20
			    				Sleep(500);
			    				clearPartOfScreen(xIn+13,10,xIn+13+20,10);//xoa vung bat loi
			    				goto Edit;
						}
						else {
							strupr(maMonCanCapNhat);//tu dong viet hoa
							clearPartOfScreen(xGd-23,yGd+5,xGd+38+10,yGd+5+38);//xoa ds mon de hien thi ds tim sua
							break;
						}
					}
					//-----tim
					int index;
					for(int k=0;k<dsmon->n;k++){
						if(findsubstr(dsmon->mon[k]->mamh, maMonCanCapNhat ) != -1){
							colorText(79);
							found = true;index = k;
							gotoxy(xGd-18,yGd+5+vitri);
					        printf("%s",dsmon->mon[k]->mamh);
					        gotoxy(xGd-5,yGd+5+vitri);
						    printf("%s\n",dsmon->mon[k]->tenmh);
							vitri=vitri+2;
							clearColor();
						}
					}
					//----so sanh dung
					for( int k = 0; k < dsmon->n ; k++){
						if(stricmp(dsmon->mon[k]->mamh, maMonCanCapNhat) == 0)
						{	
							gotoxy(xIn,12);colorText(223);
							printf("Ma mon: %s",dsmon->mon[k]->mamh);
							gotoxy(xIn,14);colorText(223);
							printf("Ten mon: %s",dsmon->mon[k]->tenmh);
							if(YES_NO(diemxy, 25, 4,"BAN CO MUON CAP NHAP?")){//yes
								//sao chep sv cu vao tam
								strcpy(maMon,dsmon->mon[k]->mamh);
								strcpy(tenMon,dsmon->mon[k]->tenmh);
								clearPartOfScreen(xIn,9,xIn+32+20,14);//xoa vung xet giong roi in nhap
								clearPartOfScreen(xIn,22,50,27);//xoa hoi
								//nhap
								gotoxy(xIn,9);printf("------");
								gotoxy(xIn,10);colorText(229);
							    printf("%s","Nhap ma mon: ");
							    gotoxy(xIn,12);colorText(235);
							    printf("%s","Nhap ten mon: ");
							    //----nhap ma lop
							    MM:		chuThichMM();
								gotoxy(xIn+14+a,10);
								while((maMon[a]=getch())!=13){
									if(maMon[a]==27){//NUT ESC
											clearPartOfScreen(xIn,8,xIn+50,27);
											goto T;
					 				}
									if(maMon[a]== 32){
											goto MM;
									}
								fflush(stdin);
									if(maMon[a]== -32){maMon[a] = getch();
										if(maMon[a]==72){//NUT LEN
		                                      goto MM; 
										}
	                    				if(maMon[a]==80){//NUT XUONG
		                                      if(a>0){
		                                      		clearPartOfScreen(xIn,16,xIn+50,16);//xoa 1 vung chu thich
		                                      		goto TM;
											  }else{
											  		goto MM; 
											  }
										}
									}
				                    if(maMon[a]==8) {//NUT BACKSPACE
	                                      a--;if(a<0){a=0;}
	                                      else{
	                                      		backSpace(xIn+14+a,10);
												gotoxy(xIn+14+a,10);
										  }
	                                }
				                    else{
				                            printf("%c",(char)maMon[a]);a++;
				                    } 
							    }
							    maMon[a]='\0';
							    while(true){
							    	if(trungMaMonForEdit(maMon,dsmon,index)==true){
								    		gotoxy(xIn+15,14);colorText(234);
											printf("%s","Ma mon nay da ton tai!");
											Sleep(500);
											clearPartOfScreen(xIn+15,14,(xIn+15)+35,14);//xoa 1 vung bat loi
											goto MM;
									}
									if(strlen(maMon)==0 ||strlen(maMon)>MAXMMH){
											gotoxy(xIn+15,14);colorText(234);
											printf("%s","Ma mon khong hop le!!!");
											Sleep(500);
											clearPartOfScreen(xIn+15,14,(xIn+15)+35,14);//xoa 1 vung bat loi
											goto MM;
									}
									else {
											strupr(maMon);//tu dong viet hoa
											clearPartOfScreen(xIn,16,xIn+50,16);//xoa 1 vung chu thich
											goto TM;
									}
								}
							    fflush(stdin);
								//-------NHAP TEN MON        
								TM:   chuThichTM();
									gotoxy(xIn+14+b,12);
								    while((tenMon[b]=getch())!=13){
					                    if(tenMon[b]==27){//NUT ESC
												clearPartOfScreen(xIn,8,xIn+50,27);
												goto T;
							 			} 
										fflush(stdin);
										if(tenMon[b]== -32){tenMon[b] = getch();
												if(tenMon[b]==72){
													clearPartOfScreen(xIn,16,xIn+50,16);//xoa 1 vung chu thich
													goto MM; 
												}
												if(tenMon[b]==80){
													goto TM; 
												}
										}			  
					                    if(tenMon[b]==8) {//NUT BACKSPACE
		                                     b--;if(b<0)b=0;
		                                     else{
			                                     backSpace(xIn+14+b,12);
			                                     gotoxy(xIn+14+b,12);
		                                     }
		                                }
					                    else{
					                          	printf("%c",(char)tenMon[b]);b++;
					                    }
								    }
								    xoaKhoangTrang(tenMon);
								    tenMon[b]='\0';
								    while(true) {
								    	if(trungTenMonForEdit(tenMon,dsmon,index)==true){
								    			gotoxy(xIn+15,14);colorText(234);
												printf("%s","Ten mon nay da ton tai!");
												Sleep(500);
												clearPartOfScreen(xIn+15,14,(xIn+15)+35,14);//xoa 1 vung bat loi
												goto TM;
										}
										if(strlen(tenMon)==0 || strlen(tenMon)>MAXTMH){
												gotoxy(xIn+15,14);colorText(234);
												printf("%s","Do dai TM khong hop le!");
												Sleep(500);
												clearPartOfScreen(xIn+15,14,(xIn+15)+35,14);//xoa 1 vung bat loi
												goto TM;
										}
										else {
												strupr(tenMon);//tu dong viet hoa
												clearPartOfScreen(xIn,16,xIn+50,16);//xoa 1 vung chu thich
												goto X;
												break;
										}
									}
						//----------
						X :		strcpy(mon->mamh,maMon);
								strcpy(mon->tenmh,tenMon);	
								if(YES_NO(diemxy, 25, 4,"BAN CO MUON LUU FILE?")){//yes
									timViTriXM(dsmon,k);
									insertObject(dsmon,mon);
									saveDSMon(dsmon);
									gotoxy(xIn+5,26);colorText(206);printf("Luu thanh cong!");
									Sleep(500);								
									clearPartOfScreen(xIn,8,xIn+15+55,14);//xoa vung nhap
									clearPartOfScreen(xIn,22,50,27);								
									goto T;
									break;
								}
								else{
									gotoxy(xIn+5,26);colorText(206);printf("Luu that bai!");
									Sleep(500);
									clearPartOfScreen(xIn,8,xIn+15+55,14);//xoa vung nhap
									clearPartOfScreen(xIn,22,50,27);
									goto T;
									break;
								}
							}
							else{//no
								clearPartOfScreen(xIn,8,xIn+15+55,14);//xoa vung nhap
								clearPartOfScreen(xIn,22,50,27);
								goto T;
								break;
							}
						}
					}
					do{
					  	c=getch();fflush(stdin);
					}while(c!=13);
					if(c==13){
						clearPartOfScreen(xIn,8,xIn+21+i,9);
						clearPartOfScreen(xGd-23,yGd+5,xGd+38+10,yGd+5+38);//xoa ds
						inMon(tick,dsmon,rig);
						if(i>0)i=0;
						vitri = 0;
						goto Edit;
					}
				}
			}
			if ( c == 75 ){//trai
				tick --;if(tick == 0) tick = 1;
				inMon(tick,dsmon,rig);
			}
			if ( c == 77){//phai
				if(tick<=inMf1(stcthuc,dsmon)){
					tick+=1;
					inMon(tick,dsmon,rig);
				}
				else {
					tick+=0;
					inMon(tick,dsmon,rig);
				}
			}
			if ( c == 80 || c== 72){//xuong/len
				rig=true;
				inMon(tick,dsmon,rig);
				rig=false;
				goto T;
			}
		}
	}
}
//NHAP 1 MON
void nhapDSMon(DSMON *dsmon) {
    fflush(stdin);
    MON *mon; mon = (MON*)malloc(sizeof(MON));
    char c;  int tick=1; int stcthuc = dsmon->n/20;bool rig = false;
    char maMon[MAXMMH] = ""; int i = 0;
	char tenMon[MAXTMH] = ""; int j = 0;
    OBJECR_LCT diemxy;
	   diemxy.x=xIn;
	   diemxy.y=xIn+7;
    gotoxy(xIn,10);colorText(229);
    printf("%s","Nhap ma mon: ");
    gotoxy(xIn,12);colorText(235);
    printf("%s","Nhap ten mon: ");
//------nhap ma mon
MM:		chuThichMM();
	gotoxy(xIn+14+i,10);
    while((maMon[i]=getch())!=13){
    				if(maMon[i]==27){//NUT ESC
										clearPartOfScreen(xIn,10,xIn+50,27);
										return; //Input_Mon(dsmon);
					 			}
					if(maMon[i]== 32){
									goto MM;
							}
					fflush(stdin);
					if(maMon[i]== -32){maMon[i] = getch();
									if(maMon[i]==72){//NUT LEN
	                                      goto MM; 
									}
                    				if(maMon[i]==80){//NUT XUONG
	                                      if(i>0){
	                                      		clearPartOfScreen(xIn,16,xIn+50,16);//xoa 1 vung chu thich
	                                      		goto TM;
										  }else{
										  		goto MM; 
										  }
									}
									if (maMon[i]==77) {
							   			if(tick<=inMf1(stcthuc,dsmon)){
					                        tick+=1;
					                        inMon(tick,dsmon,rig);
				                        }
				                        else {
					                        tick+=0;
					                        inMon(tick,dsmon,rig);
				                        }
										gotoxy(xIn+14+i,10);
										continue;
									}
									if (maMon[i]==75) {
							   			tick --;if(tick == 0) {tick = 1;}
							    		inMon(tick,dsmon,rig);
										gotoxy(xIn+14+i,10);
										continue;
									}
							}
                    if(maMon[i]==8) {//NUT BACKSPACE
                                      i--;if(i<0){i=0;}
                                      else{
                                      		backSpace(xIn+14+i,10);
											gotoxy(xIn+14+i,10);
									  }
                                }
                    else{
                            printf("%c",(char)maMon[i]);i++;
                    } 
    }
    maMon[i]='\0';
    while(true){
    	if(trungMaMon(maMon,dsmon)==true){
	    		gotoxy(xIn+15,14);colorText(234);
				printf("%s","Ma mon nay da ton tai!");
				Sleep(500);
				clearPartOfScreen(xIn+15,14,(xIn+15)+35,14);//xoa 1 vung bat loi
				goto MM;
		}
		if(strlen(maMon)==0 ||strlen(maMon)>MAXMMH){
				gotoxy(xIn+15,14);colorText(234);
				printf("%s","Ma mon khong hop le!!!");
				Sleep(500);
				clearPartOfScreen(xIn+15,14,(xIn+15)+35,14);//xoa 1 vung bat loi
				goto MM;
		}
		else {
				strupr(maMon);//tu dong viet hoa
				clearPartOfScreen(xIn,16,xIn+50,16);//xoa 1 vung chu thich
				goto TM;
		}
	}
	
   fflush(stdin);
//-------NHAP TEN MON        
TM:   chuThichTM();
	gotoxy(xIn+14+j,12);
    while((tenMon[j]=getch())!=13){
                    if(tenMon[j]==27){//NUT ESC
										clearPartOfScreen(xIn,10,xIn+50,27);
										return; //Input_Mon(dsmon);
					 			} 
				fflush(stdin);
					if(tenMon[j]== -32){tenMon[j] = getch();
									if(tenMon[j]==72){
										clearPartOfScreen(xIn,16,xIn+50,16);//xoa 1 vung chu thich
										goto MM; 
									}
									if(tenMon[j]==80){
										goto TM; 
									}
									if (tenMon[j] == 77) {
							   			if(tick<=inMf1(stcthuc,dsmon)){
					                        tick+=1;
					                        inMon(tick,dsmon,rig);
				                        }
				                        else {
					                        tick+=0;
					                        inMon(tick,dsmon,rig);
				                        }
										gotoxy(xIn+14+j,12);
										continue;
									}
									if (tenMon[j] == 75) {
							   			tick --;if(tick == 0) tick = 1;
							    		inMon(tick,dsmon,rig);
										gotoxy(xIn+14+j,12);
										continue;
									}
							}			  
                    if(tenMon[j]==8) {//NUT BACKSPACE
                                     j--;if(j<0)j=0;
                                     else{
	                                     backSpace(xIn+14+j,12);
	                                     gotoxy(xIn+14+j,12);
                                     }
                                }
                     else{
                          	printf("%c",(char)tenMon[j]);j++;
                     }
    }
    xoaKhoangTrang(tenMon);
    tenMon[j]='\0';
    while(true) {
    	if(trungTenMon(tenMon,dsmon)==true){
    			gotoxy(xIn+15,14);colorText(234);
				printf("%s","Ten mon nay da ton tai!");
				Sleep(500);
				clearPartOfScreen(xIn+15,14,(xIn+15)+35,14);//xoa 1 vung bat loi
				goto TM;
		}
		if(strlen(tenMon)==0 || strlen(tenMon)>MAXTMH){
				gotoxy(xIn+15,14);colorText(234);
				printf("%s","Do dai TM khong hop le!");
				Sleep(500);
				clearPartOfScreen(xIn+15,14,(xIn+15)+35,14);//xoa 1 vung bat loi
				goto TM;
		}
		else {
				strupr(tenMon);//tu dong viet hoa
				clearPartOfScreen(xIn,16,xIn+50,16);//xoa 1 vung chu thich
				goto checkM;
				break;
		}
	}
checkM:	
	if(YES_NO(diemxy, 25, 4,"BAN CO MUON LUU FILE?")){//YES
		strcpy(mon->mamh,maMon);
		strcpy(mon->tenmh,tenMon);
		insertObject(dsmon,mon);
		saveDSMon(dsmon);
		gotoxy(xIn+7,24);colorText(203);printf("Luu thanh cong!");
		Sleep(500);
		clearPartOfScreen(xIn,22,50,27);
	}
	else {//NO                       
		gotoxy(xIn+7,24);colorText(203);printf("Luu that bai!");
	  	Sleep(500);
		clearPartOfScreen(xIn,22,50,27);
	}
}
