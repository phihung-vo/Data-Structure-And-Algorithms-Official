#include<conio.h>
#include <cstdlib>
//#include<stdlib.h>
//#include<stdio.h>
//#include<string.h>
//#include<string>
#include<time.h>
#include<ctime>
#include <algorithm>


#include <pthread.h>


int  userManual_DoExam(){
	systemCls();
	char userManual[MAX_CONTENT_QUESTION];
	OBJECR_LCT diemxy,diemxy_2,endxy_id1,endxy_id2;
	diemxy.x = 24;
	diemxy.y = 10;
	diemxy_2.x = diemxy.x+1;
	diemxy_2.y = diemxy.y+1;
    endxy_id1 = makeTable_Color(diemxy,20,100,'|','_',58,58);
    gotoxy(diemxy.x+2,diemxy.y+2);
    colorText(228);
    printf("%s","HUONG DAN:");clearColor();
    gotoxy(diemxy.x+2,diemxy.y+3+1);
    printf("%s","Thi sinh chon mon thi sau do nhap chinh xac va day du cac thong tin: \"so cau hoi thi\"  ");
    gotoxy(diemxy.x+2,diemxy.y+4+1);
    printf("%s","va \"so phut thi\"sau do nhan \"Enter\" de vao thi");
    gotoxy(diemxy.x+2,diemxy.y+6+1);
    printf("%s","Trong qua trinh lam bai,thi sinh nhan cac phim mui ten \"len\" \"xuong\" de duyet qua cac cau hoi");
	gotoxy(diemxy.x+2,diemxy.y+8+1);
	printf("%s","Thi sinh nhan esc de nop bai va hoan tat qua trinh thi");
	gotoxy(diemxy.x+2,diemxy.y+10+1);
	printf("%s","Thi sinh xem lai ket qua thi va ket thuc chuong trinh");  
	gotoxy(diemxy.x+2,diemxy.y+12+1);
	colorText(227);
	printf("%s","Nhan \"Enter\" de vao thi!");clearColor();
	int status;
	char c = ' ';
	while(c !=13 &&c!=27){
	Wait:  if(kbhit()){
		c = getch();
		if(c==13){
			systemCls();
			continue;
		}
		if(c==27){
			status = 1;
			continue;
		}
	} 
	goto Wait;
		}
		systemCls();
		if(status==1)return 1;
}




bool checkIfItNumber(char c){
	if(c<48 || c>57)return false;
	return true;
}



float lamTronDiem(float x){
         int y = (int) x;
         x = x*10;
         x = (int) x;
         x = x/10;
return x;      
          
      }
void makeLogFile(char masv[MAXMSV],char mamh[MAXMMH],int slc){
    FILE *file;
    file = fopen("log.bin","wb");
    LOG log;
    strcpy(log.masv,masv);   
    strcpy(log.mamh,mamh);
    log.slCauHoi = slc;
    log.seconds = time(NULL); 
    time_t t=time(0);// Reset  l?i th?i gian b?ng 0
    struct tm *time=localtime(&t);
    log.time.day = time->tm_mday;
    log.time.mon = time->tm_mon+1;
    log.time.year = time->tm_year+1900;
    fwrite(&log,sizeof(log),1,file);
    fclose(file); 
}
int checkLog(){
    FILE *file;
    file = fopen("log.bin","rb");
    time_t seconds;
    LOG log;
    fread(&log,sizeof(log),1,file);
    fclose(file);
    seconds = time(NULL);
    return(seconds - log.seconds);
}
bool trueStudent(char masv[MAXMSV]){
     FILE *file;
    file = fopen("log.bin","rb");
    LOG log;
    fread(&log,sizeof(log),1,file);
    fclose(file);
   
    if(stricmp(log.masv,masv)==0)return true;
    return false;
}
bool trueSubject(char mamh[MAXMMH]){
     FILE *file;
    file = fopen("log.bin","rb");
    LOG log;
    fread(&log,sizeof(log),1,file);
    fclose(file);
   
    if(stricmp(log.mamh,mamh)==0)return true;
    return false;
}
bool trueSLCHoi(int slcH){
     FILE *file;
    file = fopen("log.bin","rb");
    LOG log;
    fread(&log,sizeof(log),1,file);
    fclose(file);
  
    if(log.slCauHoi==slcH)return true;
    return false;
}


bool useOldExam(char masv[MAXMSV],char mamh[MAXMMH],int slch){
   if(trueSLCHoi(slch)==true &&checkLog()<= RE_EXAM_TIME &&trueStudent(masv)==true &&trueSubject(mamh)==true ) {return true;}
   return false;    
}
void makeExam(DETHI *dethi,CAUHOI mangCauHoi[MAX],bool thiLai,int slc,char masv[20]){
     if(thiLai==true){/*loadDeThiTuFileTam(dethi);*/}//dung de thi cu
     if(thiLai==false){initDethi(dethi,mangCauHoi, slc);}//tao de thi moi
}
void initDethi(DETHI *dethi,CAUHOI mangCauHoi[MAX],int slc){
            CHT *temp ;
            dethi->n = 0;
            FILE *file;
            file = fopen(TEMPEXAM,"wb"); 
              for(int i=0;i<slc;i++){
                      //temp = (CHT *)malloc(sizeof(CHT));
                      dethi->cauHoiThi[i] = (CHT *)malloc(sizeof(CHT));
                      dethi->cauHoiThi[i]->id = mangCauHoi[i].id; 
                      dethi->cauHoiThi[i]->daC =  ' ';
                      dethi->cauHoiThi[i]->daD = mangCauHoi[i].da;
                      dethi->cauHoiThi[i]->diem = 0;
                      dethi->n++;
                    
              }
              for(int i=0;i<(dethi->n);i++){
                fwrite(dethi->cauHoiThi[i],sizeof(*(dethi->cauHoiThi[i])),1,file);
         }
         
                
         fclose(file);
         //
                      
    
         
              //xu ly random dap an
             
     }

void ghiLaiTrangThaiThi(EXAMTIME examTime){
	
	FILE *file;
         file = fopen(TIMEEXAM,"wb"); 
         fwrite(&examTime,sizeof(EXAMTIME),1,file);
         fclose(file);
}



void display_LoginProgram(int x,int y){
	gotoxy(50,3);colorText(228);
	printf("%s","H O C  V I E N  C O N G  N G H E  B U U  C H I N H  V I E N  T H O N G ");clearColor();
	gotoxy(65,5);colorText(236);
	printf("%s","CHUONG TRINH QUAN LY THI TRAC NGHIEM");clearColor();
	OBJECR_LCT diemxy,endxy,end_Diemxy_v;
	diemxy.x = x;
	diemxy.y = y;
    endxy = makeTable_Color(diemxy,20,80,'|','_',236,236);
    end_Diemxy_v = make_OuterBorderTable_Color(diemxy,20,80,'|','_',1,228,228);
    diemxy.x = x+3+15;
    diemxy.y = y+3;
    makeTable_Color_Type2(diemxy,2,MAXDN+2,119,119);
    diemxy.y = y+9;
    makeTable_Color_Type2(diemxy,2,MAXDN+2,119,119);
    colorText(IDCOLOR_CLEARTEXT);
	gotoxy(x+3,y+4);printf("%s","Ten dang nhap:");
    gotoxy(x+3,y+10);printf("%s","Mat khau:");
}
void display_LoginFail(int x,int y){
	
	display_LoginProgram(x,y);
	for(int i=1;i<=5;i++){
	gotoxy(x+30,y+15);
	colorText(32);printf("%s","Access denied");Sleep(100);
	colorText(IDCOLOR_CLEARTEXT);
	gotoxy(x+30,y+15);printf("%s","             ");Sleep(100);
    }
	colorText(IDCOLOR_CLEARTEXT);
	Sleep(1000);
	gotoxy(x+25,y+15);
	printf("%s","Sai thong tin dang nhap");
}
ACCOUNT  getLoginInfo(int x,int y){
	
	display_LoginProgram(x,y);
	ACCOUNT account ;
	strcpy(account.tenDangNhap,"");
	strcpy(account.password,"");
	int end = -1;
	char tenDn[MAXDN] = "";
	char password[MAXMK] = "";
	int input = x+3+15+1;
	int z =0;
	int i = 0;
while(end <0) {

T: fflush(stdin);		gotoxy(input+z,y+4);
  	while((tenDn[z]=getch())!=13){
                        fflush(stdin);
                             
                             if(tenDn[z]==72){   
                                               if(z>MAXDN-2){
											      backSpace(input+z-1,y+4);
											      goto T;
										       }
											   else {
											   backSpace(input+z-1,y+4);z--;
                                               goto T; }
                                           }
                             if(tenDn[z]==80){if(z<0)z=0;
                                               if(z>MAXDN-2){
											 	   backSpace(input+z-1,y+4);z--;
                                                   goto T; }
							 				   else{
												
											     backSpace(input+z-1,y+4);z--;
                                                 goto P;
											}
                                           }
                             if(tenDn[z]==8) {    
                                                 z--;if(z<0){z=0;}
                                                 else{tenDn[z+1] = '\0';
                                                 backSpace(input+z,y+4);
                                                 gotoxy(input+z,y+4);continue;
                                                 }
                                             }
                              if(tenDn[z]==27){                              		
                               		strcpy(account.tenDangNhap,"");
									strcpy(account.password,"");
									end = 1;
                               		goto  Exit;
							   }
							     
                             if(tenDn[z]!=72 &&tenDn[z]!=80 &tenDn[z]!=8){
							     if(z>MAXDN-2){//continue;
							      }
                                 else{
	
                                      printf("%c",(char)tenDn[z]);z++;
                                  }
                                  
                              
                             }
                             
 
        }
P: fflush(stdin);		gotoxy(input+i,y+10);
  	while((password[i]=getch())!=13){
                        fflush(stdin);
                             
                             if(password[i]==72){   
                                               if(i>MAXMK-2){
											     backSpace(input+i-1,y+10);
												 goto T;
										       }
											   else {
											   backSpace(input+i-1,y+10);i--;
                                               goto T; }
                                           }
                             if(password[i]==80){if(i<0)i=0;
                                               if(i>14){
											       backSpace(input+i-1,y+10);
												   goto P;
									        	}
							 				   else {
												backSpace(input+i-1,y+10);i--;
                                               goto P; }
                                           }
                             if(password[i]==8) {    
                                                 i--;if(i<0){i=0;}
                                                 else{password[i+1] = '\0';
                                                 backSpace(input+i,y+10);
                                                 gotoxy(input+i,y+10);continue;
                                                 }
                                             }
                              if(password[i]==32){
							   		goto P;
							   }
                              if(password[i]==27){
                               		strcpy(account.tenDangNhap,"");
									strcpy(account.password,"");
									end = 1;
                               		goto Exit;
							   }
							   if(password[i]==59){password[i] = '\0';
							   	gotoxy(input,y+10);
							   	printf("%s",password);
							   	backSpace(input+strlen(password),y+10);
							   	gotoxy(input+strlen(password),y+10);
							   	Sleep(1000);
							   	gotoxy(input,y+10);
							   	for(int i=0;i<strlen(password);i++){
							   		gotoxy(input+i,y+10);
							   		printf("%s","*");
							   		
								   }
                                    continue;
							   }  
                             if(password[i]!=72 &&password[i]!=80 &&password[i]!=8){
							     if(i>MAXMK-2){//continue;
							      }
                                 else{
	
                                      printf("%c",'*');i++;
                                  }
                                  
                              
                             }
 
        }
		tenDn[z] = '\0';password[i] = '\0';
        strcpy(account.tenDangNhap,tenDn);
        strcpy(account.password,password);
        end = 1;
    }
    
    
	
	
	
	Exit: ;
	return account;
}

ACCOUNT module_Login(int x,int y){
	bool exit = false;
	while(true){
		display_LoginProgram(x,y);
		ACCOUNT account; NODESINHVIEN p=NULL; DSLOP *dslop;
		account = getLoginInfo(x,y);
		if(stricmp(account.tenDangNhap,"") ==0&& stricmp(account.password,"")==0){          // nhan ESC
          systemCls();Sleep(1000);
		  strcpy(account.tenDangNhap,"NONE");
		  strcpy(account.password,"NONE");
		  return account;
	    }
	    else {
	    	for(int i=0;i<dslop->n;i++){
	    		p=dslop->lop[i]->dssinhvien; p = p->next;
	    	if(strcmp(account.tenDangNhap,"GV") ==0&& strcmp(account.password,"GV")==0){
//			   return 0;
	             return account;
			}    //nguoi dang nhap la GV
			if(stricmp(p->sinhvien.masv,account.tenDangNhap) ==0/*&& stricmp(account.password,p->sinhvien.password)==0*/){    //kiem tra nguoi dang nhap la Sinh Vien
//	    	   return 1;
             	 return account;
			}//neu dieu kien dang nhap sai
		    	else{
				   display_LoginFail(x,y);
		    	   Sleep(1000);
		    	   systemCls();
		    	   continue;
				}
			}
		}break;
	}
	
//	    display_LoginFail(x,y);
//		Sleep(100);
//		
//	    	Sleep(1000);
//	    	systemCls();
//	
	
}

void display_GoodBye(){
	int x,y;
	x=0;
	y=20;
	changeScene_type2(112);
	colorText(4);
	gotoxy(x,y);
printf("%s\n","                                                  * * * *                     *           *");gotoxy(x,y+1);
printf("%s\n","                                                  *     *                     *           *");gotoxy(x,y+2);
printf("%s\n","                                                  * * * *  * * *  * * *  * *  *           * * *  *    *    ****");gotoxy(x,y+3);
printf("%s\n","                                                        *  *   *  *   *  *    *	         *   *  *    *  *  . \"");gotoxy(x,y+4);
printf("%s\n","                                                        *  *   *  *   *  *    *           *   *   *  *   * \"   *");gotoxy(x,y+5);
printf("%s\n","                                                    * * *  * * *  * * *  * *  *           * * *    *      \"  * ");gotoxy(x,y+6);
printf("%s\n","                                                                                                   *");gotoxy(x,y+7);
printf("%s\n","                                                                                                   *");
Sleep(1000);
clearColor();
systemCls();
}

void displayExamScreen(char masv[MAXMSV],char tenMon[MAXTMH],TIME localTime){

    int x =80,y =2; 
    int location;
//    systemCls();
   
    tenMon = strupr(tenMon);
    gotoxy(x,y);
    printf("%s","BAI THI MON:");
    location = showStringInLocation(tenMon,x+14,y,x+14+30);    
    gotoxy(x,location+2);
    printf("%s",masv);  
    gotoxy(x+40,location+2);
    printf("%s%d%s%d%s%d","ngay ",localTime.day,",thang ",localTime.mon,",nam ",localTime.year);
    gotoxy(x-75,y+48);printf("%s","Nhan \"ESC\" de nop bai");
  
}

void displayMarkTable(int x,int y) {
       /* int x = 120;
        int y = 10;*/
        gotoxy(x+40,y-1);
        printf("%s","KET QUA THI");
        
        for(int i=y+1;i<=40;i++){
                gotoxy(x,i);
                printf("%s","|");
        }
        for(int i=x+1;i<=x+91;i++){
                gotoxy(i,y);
                printf("%s","_");        
                
        }
        for(int i=x+1;i<=x+91;i++){//170
                gotoxy(i,y+30);
                printf("%s","_");        
                
        }
        for(int i=y+1;i<=40;i++){
                gotoxy(x+51+20+20,i);
                printf("%s","|");
        }
        gotoxy(x+18+20,y+2);printf("%s","Dap an da chon");
      
        int j=1;
        for(int i=y+4;i<=38;i++){
               gotoxy(x+2,i);printf("%s","Cau ");
               colorText(228);printf("%d",j);clearColor();
               printf("%s",":");
               j++;        
                
        }
        for(int i=y+4;i<=38;i++){
               gotoxy(x+20,i);printf("%s","Cau ");
               colorText(228);printf("%d",j);clearColor();
               printf("%s",":");
               j++;        
               if(j==51)break;
                
        }
        //
        for(int i=y+4;i<=38;i++){
               gotoxy(x+40,i);printf("%s","Cau ");
               colorText(228);printf("%d",j);clearColor();
               printf("%s",":");
               j++;        
               if(j==51)break;
                
        }
        for(int i=y+4;i<=38;i++){
               gotoxy(x+60,i);printf("%s","Cau ");
               colorText(228);printf("%d",j);clearColor();
               printf("%s",":");
               j++;        
               if(j==51)break;
                
        }
 
     }
     
 void hienThiDiem(DETHI *deThi,char hoSv[MAXHOSV],char tenSv[MAXTENSV],float diem,EXAMTIME examTimeUsed, int x,int y){
    
	 displayMarkTable(x,y);  
	 gotoxy(5,50);
	 clearPartOfScreen(5,50,5+24,50);
	 gotoxy(x-65,y+2);
	 colorText(224);
	 printf("%s","DA HOAN THANH BAI THI");
	 clearColor();
	 gotoxy(x-65,y+4);
	 printf("%s","Ho Va Ten Thi Sinh:");
	 gotoxy(x-40,y+4);printf("%s %s",hoSv,tenSv);
	 gotoxy(x-65,y+6);
	 printf("%s","Thoi Gian Thi Con Lai:");
	 gotoxy(x-40,y+6);
	 printf("%d %s %d",examTimeUsed.minutes,":",examTimeUsed.seconds);
     for(int i=0;i<deThi->n;i++){
         if(i>24)break;      
         gotoxy(x+3+6,y+4+i);colorText(225);printf("%c",deThi->cauHoiThi[i]->daC);clearColor();
         gotoxy(x+3+8,y+4+i);printf("%.1f",deThi->cauHoiThi[i]->diem); 
         gotoxy(x+3+12,y+4+i);colorText(228);printf("%c",deThi->cauHoiThi[i]->daD);clearColor();
          
     }
     int j = 0;
     for(int i=25;i<deThi->n;i++)    {
                   if(i>49)break; 
                 gotoxy(x+3+6+21,y+4+j);colorText(225);printf("%c",deThi->cauHoiThi[i]->daC);clearColor();
                 gotoxy(x+3+8+21,y+4+j);printf("%.1f",deThi->cauHoiThi[i]->diem);
                 gotoxy(x+3+12+21,y+4+j);colorText(228);printf("%c",deThi->cauHoiThi[i]->daD);clearColor();
                 j++;        
         } 
		 j = 0;  
		 //
	  for(int i=50;i<deThi->n;i++)    {
                   if(i>74)break; 
                 gotoxy(x+3+6+21+21,y+4+j);colorText(225);printf("%c",deThi->cauHoiThi[i]->daC);clearColor();
                 gotoxy(x+3+8+21+21,y+4+j);printf("%.1f",deThi->cauHoiThi[i]->diem);
                 gotoxy(x+3+12+21+21,y+4+j);colorText(228);printf("%c",deThi->cauHoiThi[i]->daD);clearColor();
                 j++;        
         }
		 j = 0; 
	  for(int i=75;i<deThi->n;i++)    {
                  
                 gotoxy(x+3+6+21+21+21,y+4+j);colorText(225);printf("%c",deThi->cauHoiThi[i]->daC);clearColor();
                 gotoxy(x+3+8+21+21+21,y+4+j);printf("%.1f",deThi->cauHoiThi[i]->diem);
                 gotoxy(x+3+12+21+21+21,y+4+j);colorText(228);printf("%c",deThi->cauHoiThi[i]->daD);clearColor();
                 j++;        
         }     
     
      gotoxy(145,39);printf("%s","Tong:");
      gotoxy(151,39 );printf("%.1f%s",diem,"diem");
}

void clearPartOfScreenButNoClock(int x,int y,int endX,int endY){
 	//xoa ben trai
 
 	for(int i=0;i<x;i++)
 		for(int j=y;j<=endY;j++){
		 gotoxy(i,j);
	 printf("%c",' ');
		 }
 	//xoa phia tren
 	for(int i=0;i<180;i++)
 		for(int j=0;j<y;j++){
		 gotoxy(i,j);
		 printf("%c",' ');
		 }
 	//xoa ben phai
 	for(int i=endX+1;i<180;i++)
 		for(int j=y;j<=endY;j++){
		 gotoxy(i,j);
	 printf("%c",' ');
		 }
 	//xoa phia duoi
 	for(int i=0;i<180;i++)
 		for(int j=endY+1;j<50;j++){
		 gotoxy(i,j);
	 printf("%c",' ');
		 }
 	
	 
	 
 }    
 


     
bool checkIfAnswerIsTrueCharacter(char c) {
      if((int)c ==97 || (int)c ==98 || (int)c ==99 || (int)c ==100 ||
              (int)c ==65 || (int)c ==66 || (int)c ==67 || (int)c ==68  )return true;
       return false;
     
     }

bool checkIfAnswerIsTrueCharacter(char c[3]){
      
       if((int)c[0] ==65 || (int)c[0] ==66 || (int)c[0] ==67 || (int)c[0] ==68 ){return true;}
       return false;
     }
bool checkIfAnswerClean(char c){
     
      if(c==' ')return true;
      return false;
     
     }


struct node {
          int key;
         // char info[20];
          CAUHOI cauhoi;
          struct node *left;
          struct node *right;
       };typedef struct node *NODEPTR;
       

void initialize(NODECAUHOI &root){
         root = NULL;
     }


void posorder(NODECAUHOI p)
{  if(p != NULL)    
   {  posorder(p->left);
      posorder(p->right);
      
   }
}

    

void makeIdArray(int slc,int mang[]){
	int id;
srand((int)time(0));int i=0;
         while(true){

                id = random(slc,0);
	             if(checkExistId(id,mang,i)==false){
	             	 mang[i] = id;
	             	 i++;
				 }
	             if(i==slc)break;
         
         }
}

void getQuestionFromQuestionTree(NODECAUHOI p,NODECAUHOI &ds)
{ 
   
}

    

CHT loadDeThiTuFileTam(int index){
     CHT mangCht[MAX];
     FILE *file;  
     CHT cht;
    
     file = fopen(TEMPEXAM,"rb"); 
     int count = 0;
     if(file==NULL){}
     else{
            while(fread( &cht,sizeof(CHT),1,file))
		    {	mangCht[count] = cht;
     			count = count + 1;
    	
	    	}
	    	
      
     }

      
          fclose(file); 
     return mangCht[index];
     }
 
     
     
     
     
void ghiNhanDapAn(DETHI *deThi,int id,char da){
         for(int i=0;i<(deThi->n);i++){
             if(deThi->cauHoiThi[i]->id == id)deThi->cauHoiThi[i]->daC = da;
                 
         }
         FILE *file;
         file = fopen(TEMPEXAM,"wb");         
         for(int i=0;i<(deThi->n);i++){
                fwrite(deThi->cauHoiThi[i],sizeof(*deThi->cauHoiThi[i]),1,file);
         }
         fclose(file);
     }
bool ktDaGhiNhanDapAn(DETHI *deThi,int id){
        for(int i=0;i<deThi->n;i++){
                   if(deThi->cauHoiThi[i]->id == id){
                       if(checkIfAnswerIsTrueCharacter((deThi->cauHoiThi[i]->daC)) ==true){
                                     
                         return true;//da ghi
                       }
                   }
                }
        return false;//chua ghi
     
     }
void hienThiDapAn(int x,int y,char da){
        gotoxy(x,y);
        colorText(225);
        printf("%c",da);
     
     }

void* hienThiDongHo(void* params)

{

            EXAMTIME* p = (EXAMTIME*) params; //ep kieu tham so truyen vao
      
                
                        fflush(stdin);
            		clockTest(*p,145,5);
        
            return NULL;

}

int getRestExamTime(){
	 FILE *file;  
     int seconds;
    
     file = fopen(TIMEEXAM,"rb"); 
     
     if(file==NULL){return -1;}
     
     else{
           fread( &seconds,sizeof(int),1,file);
		   
      
     }fclose(file);
     return seconds;
}

EXAMTIME thi(char masv[MAXMSV],char tenMon[MAXTMH],CAUHOI cauHoi[MAX],int slCauHoi,
                              DETHI *deThi,TIME localTime,EXAMTIME examTime){
       
       	    fflush(stdin);
			
				int x =5,y =10, endS =145;
                int endQ=0,endA=0,endB=0,endC=0,endD=0;
                char A[4] = "A. ",B[4] = "B. ",C[4] = "C. ",D[4] = "D. ";
                int end = -1;
                int check = -1;
                int i = 0;
                int j = 0;
                int dem = 1;
                char da[3];
                char c;
                 
                 
                do{
                Back:  
                
                      gotoxy(x,y-3);if(i>=slCauHoi) printf("%s%d\n","Cau: ",i);
                      else {
					     printf("%s%d\n","Cau: ",i+1);
					 }
                      endQ = showStringInLocation(cauHoi[i].nd,x,y,endS);
                      gotoxy(x,endQ+2);printf("A. ");
                      endA = showStringInLocation(cauHoi[i].a,x+3,endQ+2,endS);
                      gotoxy(x,endA+2);printf("B. ");
                      endB = showStringInLocation(cauHoi[i].b,x+3,endA+2,endS);
                      gotoxy(x,endB+2);printf("C. ");
                      endC = showStringInLocation(cauHoi[i].c,x+3,endB+2,endS);
                      gotoxy(x,endC+2);printf("D. ");
                      endD = showStringInLocation(cauHoi[i].d,x+3,endC+2,endS);
                       
                       
                       gotoxy(x,endD+2);
                       printf("%s","Lua chon: ");
                       if(i>=slCauHoi) {
                               i = slCauHoi - 1;
                               clearPartOfScreen(5,10,166,endD+2);;// 11 displayExamScreen(masv,tenMon,localTime);
                              endQ = showStringInLocation(cauHoi[i].nd,x,y,endS);
                              gotoxy(x,endQ+2);printf("A. ");
                              endA = showStringInLocation(cauHoi[i].a,x+3,endQ+2,endS);
                              gotoxy(x,endA+2);printf("B. ");
                              endB = showStringInLocation(cauHoi[i].b,x+3,endA+2,endS);
                              gotoxy(x,endB+2);printf("C. ");
                              endC = showStringInLocation(cauHoi[i].c,x+3,endB+2,endS);
                              gotoxy(x,endC+2);printf("D. ");
                              endD = showStringInLocation(cauHoi[i].d,x+3,endC+2,endS);
                              gotoxy(x,endD+2);
                              printf("%s","Lua chon: ");  
                              gotoxy(x,endD+3);
                              colorText(225);printf("%s","Da hoan thanh cac cau hoi");     clearColor();    
                                         
                       }
                      if(ktDaGhiNhanDapAn(deThi,cauHoi[i].id)==true){
                                                 colorText(225);hienThiDapAn(x+10,endD+2,deThi->cauHoiThi[i]->daC);clearColor();                                      
                                                                                         
                      }else{ 
                                
                                gotoxy(x+10,endD+2);
                           }
//						   clockTest(examTime,145,5);     
			Wait:		timer(&examTime.minutes,&examTime.seconds);
			            ghiLaiTrangThaiThi(examTime);
                        if(kbhit()) {
                              c = getch();                       
                              
                             if(c==72){ //len
                                           
                                            clearPartOfScreen(5,10,166,endD+2);;//displayExamScreen(masv,tenMon,localTime);
                                             i--;
                                            
                                              if(i<0){i = 0;}
                                              
                                             continue;
                             }
                             if(c==8) {
                                              
                                                 
                                                     backSpace(x+10,endD+2);
                                                     gotoxy(x+10,endD+2);
                                                    
                                                 
                              }
                             if(c==80){//xuong 
                                        clearPartOfScreen(5,10,166,endD+2);//displayExamScreen(masv,tenMon,localTime);
                                             
                                             i++;
                                             
                                              if(i>=slCauHoi){i = slCauHoi-1;}
                                              continue;
                             }
                                             
                             if(c==13){
                                      fflush(stdin); 
                                      clearPartOfScreen(5,10,166,endD+2);
                                    if(stopExam==true){
									    end = 1;break;
                                      }
                                      else{
									  
                                      ghiNhanDapAn(deThi,cauHoi[i].id,da[0]);
                                      
                                                   
                                                   i++;j++;
                                                   continue;
                                    }
                                       
                             }
                             if(c==27){
                                         while(c!=89 || c!=78 || c!=110 || c!=121){
                                         	
                                            for(int k=0;k<=3;k++){
												gotoxy(60,endD+10);colorText(225);
	                                            printf("%s","Thoi gian van con!! Ban co thuc su muon ket thuc khong!!! [y/n]");Sleep(150);
	                                            gotoxy(60,endD+10);printf("%65s"," ");Sleep(150);
	                                        }gotoxy(60,endD+10);colorText(225);
	                                        printf("%s","Thoi gian van con!! Ban co thuc su muon ket thuc khong!!! [y/n]");clearColor();
                                            gotoxy(x+60,endD+10);c=getch();
                                            if(c==110 || c==78)
											{  
											   clearPartOfScreen(60,endD+10,x+125,endD+10);
											   break; 
											}
                                            if(c==89 || c==121){
                                               
                                               end = 1;
                                               break;       
                                            }                   
                                                            
                                         
                                         }
                                        continue;
                                       }
                             if(checkIfAnswerIsTrueCharacter(c)==true ) {
                                  
                                      fflush(stdin);
                                      da[0] = (char)c;da[1] = '\0';
                                      strupr(da);
                                      gotoxy(x+10,endD+2);
                                      colorText(225);printf("%c",da[0]);clearColor();
                                      //xu ly luu diem vao file
                                      
                                  }
             
                                   
                      }
                      
                     goto Wait; 
                           
                    }while(end <0);
       	    
	        
				
              return examTime;    
   


     }
float tinhDiem(DETHI *deThi,float bangDiem[MAX]){
        float diem = 0;
        for(int i=0;i<deThi->n;i++){
                    if(deThi->cauHoiThi[i]->daC == deThi->cauHoiThi[i]->daD){
                        deThi->cauHoiThi[i]->diem = bangDiem[i];                                                                
                    }else{
                               deThi->cauHoiThi[i]->diem = 0;
                          }
                    
          
       } 
       //
     FILE *file;       
     
     file = fopen(TEMPEXAM,"rb"); 
     
     if(file==NULL){}
     else{
                 for(int i=0;i<deThi->n;i++)fwrite(deThi->cauHoiThi[i],sizeof(*(deThi->cauHoiThi[i])),1,file);
                 fclose(file); 
     }
       //
       for(int i=0;i<deThi->n;i++)diem+=(float)(deThi->cauHoiThi[i]->diem);
return diem;
 }
 int endExam(){
 	int x=10,y=48;
	 gotoxy(x,y);printf("%s","Nhan \"ESC\" de thoat!!");
	 char c;
Wait:if(kbhit()){
	 c = getch();fflush(stdin);
	 if(c==27)return 0;
	
	
	
}
goto Wait;
return 1;
 }
void initExam(char masv[MAXMSV],char hoSv[MAXHOSV],char tenSv[MAXTENSV], char tenMon[MAXTMH],
                  DETHI *deThi,CAUHOI mangCauHoi[MAX],int slc,float bangDiem[MAX],TIME localTime,EXAMTIME examTime){


        float diem  = -1;
        EXAMTIME exameTimeUsed;

         displayExamScreen(masv,tenMon,localTime);
      
        exameTimeUsed = thi(masv,tenMon,mangCauHoi,slc,deThi,localTime,examTime);
        stopExam = true;
		Sleep(1000);
	 
		systemCls();
        diem = tinhDiem(deThi,bangDiem);
        
        displayExamScreen(masv,tenMon,localTime);
        hienThiDiem(deThi,hoSv,tenSv, diem,exameTimeUsed,70,10);   //

		endExam();      
     }


int nhapSLCauHoi(){
   int slc;
    printf("%s","Nhap so luong cau hoi: ");
    scanf("%d",&slc);
    while(slc <10 && slc>50){
        printf("%s\n","So luong cau hoi thi it nhat la 10 cau & toi da la 50 cau");      
        printf("%s","Nhap so luong cau hoi: ");
        scanf("%d",&slc);     
    }   
   return slc; 
}


TIME getTime() {
    TIME localTime;
    time_t t=time(0);// Reset  l?i th?i gian b?ng 0
    struct tm *time=localtime(&t);
    localTime.day = time->tm_mday;
    localTime.mon = time->tm_mon+1;
    localTime.year = time->tm_year+1900;
   return localTime;
}



void showNumBerZeroToNine(int number,int x,int y){
  if(number==0){
     gotoxy(x,y);printf("%s",    " __");
     gotoxy(x,y+1);printf("%s", "|  |");
     gotoxy(x,y+2);printf("%s", "|__|");          
  }   
  if(number==1){
     gotoxy(x,y);printf("%s",    "   ");
     gotoxy(x,y+1);printf("%s", "   |");
     gotoxy(x,y+2);printf("%s", "   |");          
  }  
  if(number==2){
     gotoxy(x,y);printf("%s",    " __");
     gotoxy(x,y+1);printf("%s", " __|");
     gotoxy(x,y+2);printf("%s", "|__ ");          
  }  
  if(number==3){
     gotoxy(x,y);printf("%s",    " __");
     gotoxy(x,y+1);printf("%s", " __|");
     gotoxy(x,y+2);printf("%s", " __|");          
  }  
  if(number==4){
     //gotoxy(x,y);printf("%s",    "  ");
     gotoxy(x,y+1);printf("%s", "|__|");
     gotoxy(x,y+2);printf("%s", "   |");          
  }  
  if(number==5){
     gotoxy(x,y);printf("%s",    " __");
     gotoxy(x,y+1);printf("%s", "|__");
     gotoxy(x,y+2);printf("%s", " __|");          
  }  
  if(number==6){
     gotoxy(x,y);printf("%s",    " __");
     gotoxy(x,y+1);printf("%s", "|__ ");
     gotoxy(x,y+2);printf("%s", "|__|");          
  }  
  if(number==7){
     gotoxy(x,y);printf("%s",    " __");
     gotoxy(x,y+1);printf("%s", "   |");
     gotoxy(x,y+2);printf("%s", "   |");          
  }  
  if(number==8){
     gotoxy(x,y);printf("%s",    " __");
     gotoxy(x,y+1);printf("%s", "|__|");
     gotoxy(x,y+2);printf("%s", "|__|");          
  }  
  if(number==9){
     gotoxy(x,y);printf("%s",    " __");
     gotoxy(x,y+1);printf("%s", "|__|");
     gotoxy(x,y+2);printf("%s", " __|");          
  }  
    
}


  void showTime(int timeFirst,int timeAfter,int x,int y){
    
      gotoxy(x,y);showNumBerZeroToNine(timeFirst,x,y);
      gotoxy(x,y);showNumBerZeroToNine(timeAfter,x+4,y);
            
     }
 

void clock(int minutes[MAXMINUTES],int len,int x,int y,int &restSeconds){
   int seconds = 0;
   int mi = minutes[0]*10+minutes[1];
   seconds = mi*60;
   restSeconds = seconds;
   bool giamT = false,giamS = false;
   int lenTime = 5;
   int i = 59;
   //clearPartOfScreen(x,y,x+19,y+4);
  for (int n = seconds; n > 0; n--) //wait 10 seconds
  {
    if(i<0)i=59;
    if(i==59){
              minutes[1]-=1;
              if(minutes[1]<0){minutes[1] = 9; giamT = true;}
             
              clearPartOfScreen(x,y,x+19,y+4);
    }
    
    
    
    if(giamT == true){
             minutes[0]--;
             if(minutes[0]<0)minutes[0]=0;
             giamT = false;
            clearPartOfScreen(x,y,x+19,y+4);
    }
   
    clearPartOfScreen(x,y,x+19,y+4);
       showTime(minutes[0],minutes[1],x,y);
       gotoxy(x+10,y+1);printf("%s",".");
        gotoxy(x+10,y+2);printf("%s",".");
       showTime(i/10,i%10,x+12,y);             
   
    i--;
    restSeconds--;
    if(stopExam==true)break;
	wait (1);
  }
 
  
}

//test
void clockTest(EXAMTIME &time,int x,int y){

    int i = 59;
  
    if(time.seconds<=59){
	  i=time.seconds;
	  time.seconds = time.restSeconds;
    }
	int j;
	for(j=time.seconds;j>0;j--){
       clearPartOfScreen(145,5,145+27,5);
      
	   
	      
		   
		   if(i==59){time.minutes--;}
	       if(time.minutes<0){
		     time.minutes = 0;}
	       if(time.minutes<=2 && time.seconds<=59){
	   	    if(i==0){
			   colorText(79);gotoxy(x,y);printf("%d%s",time.minutes," : 00");clearColor();
		    }    
	   	    if(i>=10){
			   colorText(79);gotoxy(x,y);printf("%d%s%d ",time.minutes," : ",i);clearColor();
		    }
	        if(i<10){
			   colorText(79);gotoxy(x,y);printf("%d%s%d ",time.minutes," : 0",i);clearColor();
		    }
	        clearPartOfScreen(145,5,145+25,5+2);
		    Sleep(50);
	        if(i==0){
			   colorText(79);gotoxy(x,y);printf("%d%s",time.minutes," : 00");clearColor();
	     	}
		    if(i>=10){
			   colorText(79);gotoxy(x,y);printf("%d%s%d ",time.minutes," : ",i);clearColor();
		    }
	        if(i<10){
			   colorText(79);gotoxy(x,y);printf("%d%s%d ",time.minutes," : 0",i);clearColor();
		    }
		}
	   else{
	   	    if(i==0){
			   colorText(IDCOLOR_CLEARTEXT);gotoxy(x,y);printf("%d%s",time.minutes," : 00");clearColor();
		    }
	   	    if(i>=10){
			   colorText(IDCOLOR_CLEARTEXT);gotoxy(x,y);printf("%d%s%d ",time.minutes," : ",i);clearColor();
		    }
	        if(i<10){
			   colorText(IDCOLOR_CLEARTEXT);gotoxy(x,y);printf("%d%s%d ",time.minutes," : 0",i);clearColor();
		    }
	   }
	   
	   ghiLaiTrangThaiThi(time);
	   if(stopExam==true)break;
	   i--;
	   if(i<0){
		     i=59;}	
	   time.restSeconds--;
	   time.seconds = i;
	   
	wait(1);
	}
	stopExam=true;
	if(j<=0){
	  time.seconds = 0;
	  
	  colorText(4);
	  for(int i=0;i<5;i++){
	     gotoxy(80,48);printf("%s","HET GIO!!!!");Sleep(200);gotoxy(80,48);printf("%s","            ");Sleep(200);
      }
       gotoxy(80,48);printf("%s","HET GIO!!!!");clearColor();
    }
	
}


//




void clockT(int minutes[MAXMINUTES],int len,int x,int y){
   int seconds = 0;
   int mi = minutes[0]*10+minutes[1];
   seconds = mi*60;
   bool giamT = false,giamS = false;
   int lenTime = 5;
   int i = 59;systemCls();
//   clearPartOfScreen(x,y,x+19,y+4);
  for (int n = seconds; n > 0; n--) //wait 10 seconds
  {
    if(i<0)i=59;
    if(i==59){
              minutes[1]-=1;
              if(minutes[1]<0){minutes[1] = 9; giamT = true;}
             
              //clearPartOfScreen(x,y,x+19,y+4);
    }
    
    
    
    if(giamT == true){
             minutes[0]--;
             if(minutes[0]<0)minutes[0]=0;
             giamT = false;
            //clearPartOfScreen(x,y,x+19,y+4);
    }
   
    //clearPartOfScreen(x,y,x+19,y+4);
      gotoxy(x,y);printf("%d",minutes[0]);
       gotoxy(x+3,y);printf("%d",minutes[0]);
        gotoxy(x+10,y);printf("%d %d",i/10,i%10);
                 
   
    i--;
    Sleep(1000);
    //wait (1);
  }
  printf ("HET GIO!!!\n");     
}


void clockStop(EXAMTIME time,int x,int y){
             if(time.seconds>=10){
			   colorText(IDCOLOR_CLEARTEXT);gotoxy(x,y);printf("%d%s%d ",time.minutes," : ",time.seconds);clearColor();
		    }
		    if(time.seconds<10){
			   colorText(IDCOLOR_CLEARTEXT);gotoxy(x,y);printf("%d%s%d ",time.minutes," : 0",time.seconds);clearColor();
		    }
   
    
}

void displayThiTracNghiemStartScreen(){
	colorText(228);
     
printf("%s\n","                                                               ");
printf("%s\n","         //////////////  //                //////////////    //                         /\         //    //'''''' ");
printf("%s\n","              //        //                      //         \\_ _//                      //\        //    //     //   //                //\\");
printf("%s\n","             //        //                      //  ('__')                             // \\      //    //. . . .   //                      ");
printf("%s\n","            //        / ////// /   //         //   // //    /'''\        //'''        //   \\    //           //   / /////// /   //   ''''''     //\\  /\\ ");
printf("%s\n","           //        //      //   //         //   //  \\   //_'_\\     /             //     \\  //           //   //       //    //   //_ _ _    //  \\// \\ ");
printf("%s\n","          //        //      //   //         //   //    \\ //     \\     //. .       //       \\//       . './/   //       //    //   //. . .    //    \/   \\ ");
printf("%s\n","                                                                                                                                     [] ");
  
     
     
     clearColor();
}


void displayStartExamScreen(int x,int y ){
     displayThiTracNghiemStartScreen();	
	
	OBJECR_LCT diemxy,endxy;
	diemxy.x = x;
	diemxy.y = y;
    //endxy = makeTable(diemxy,20,100,'|','_');
    endxy = makeTable_Color(diemxy,20,100,'|','_',68,68);                   //57
    colorText(224);
	gotoxy(x+3,y+4);printf("%s","Ten mon thi:");
	gotoxy(x+3,y+6);printf("Nhap so cau hoi thi:");
	gotoxy(x+3,y+8);printf("Nhap so phut thi:");
	gotoxy(endxy.maxX+3,y+2);printf("%s","Nhap thong tin va nhan \"Enter\"de vao thi");
	gotoxy(endxy.maxX+3,y+4);printf("%s","Nhan \"ESC\"de thoat");
	gotoxy(endxy.maxX+3,y+6);printf("%s","Nhan \"mui ten\"de dieu huong qua cac cau hoi ");
	
	colorText(225);    
	gotoxy(x, y+15+10); printf("      __...--~~~~~-._   _.-~~~~~--...__                  ");
	gotoxy(x, y+16+10); printf("    //               `V'               \\\\                ");
	gotoxy(x, y+17+10); printf("   //                 |                 \\\\               ");
	gotoxy(x, y+18+10); printf("  //__...--~~~~~~-._  |  _.-~~~~~~--...__\\\\              ");
	gotoxy(x, y+19+10); printf(" //__.....----~~~~._\\\ | /_.~~~~----.....__\\\\             ");
	gotoxy(x, y+20+10); printf("====================\\\\|//====================              "); 
	clearColor();
	
	
}




int getRequestExam( char tenmh[MAXTMH],int &slc,int &sP){
fflush(stdin);
  	  int x=20,y=10;
  	  int input = x+25;int i=0,j=0,z=0,n=0;
	  //int sl;
          
      char soCau[5] = "";
      char soPhut[MAX] = "";
    
      int end = -1;
      colorText(228);
      gotoxy(input,y+4);printf("%s",tenmh);clearColor();  
SC:   gotoxy(input+z,y+6);
   while((soCau[z]=getch())!=13){
                        fflush(stdin);
                             
                             if(soCau[z]==72){   
                                               if(z>4)goto SC;
											   else {
											  // backSpace(input+z-1,y+6);z--;
                                               goto SC; }
                                           }
                             if(soCau[z]==80){if(z<0)z=0;
                                               if(z>4)goto PT;
							 				   else {
											//	backSpace(input+z-1,y+6);z--;
                                               goto PT; }
                                           }
                             if(soCau[z]==8) {
                                                 z--;if(z<0){z=0;}
                                                 else{soCau[z+1] = '\0';
                                                 backSpace(input+z,y+6);
                                                 gotoxy(input+z,y+6);goto SC;
                                                 }
                                             }
                              if(soCau[z]==27){
                               	end = 1;
                               		return 1;
							   }  
                             else{
                             	if(strlen(soCau)>MAX_QUESTIONEXAM_CHARACTER){goto SC;
							 }else{
							 	if(checkIfItNumber(soCau[z])==false){
								 }else{
								       
                                  printf("%c",(char)soCau[z]);z++;
                                  }
                              }
                             }
 
        }

 
     //kiem tra truoc khi luu   
	 fflush(stdin);    
PT:   gotoxy(input+n,y+8);
   while((soPhut[n]=getch())!=13){
                           fflush(stdin);
                              if(soPhut[n]==72){   if(n>MAX)goto SC;
                                               else{
											   //backSpace(input+n-1,y+8);n--;
                                               goto SC; }
                                           }
                             if(soPhut[n]==80){if(n<0)n=0;
                                                if(n>MAX)goto PT;
                                               else{
							 				  // backSpace(input+n-1,y+8);n--;
							 				   if(n<0)n=0;
                                               goto PT; }
                                           }
                            
                             if(soPhut[n]==8) {
                                                 n--;if(n<0){n=0;}
                                                 else{ soPhut[n+1] = '\0';
                                                 backSpace(input+n,y+8);
                                                 gotoxy(input+n,y+8);goto PT;
                                                 }
                                             }
                             if(soPhut[n]==27){
                               	end = 1;
                               		return 1;
							   }  
                             else{if(strlen(soPhut)>MAX_MINNUTES_CHARACTER){
							 
							     }else{
							 	if(checkIfItNumber(soPhut[n])==false){}
							    else {
								
                                  printf("%c",(char)soPhut[n]);n++;
                                  }
                              }
                             }
                         }
 
        

   soCau[z] = '\0';soPhut[n] = '\0';
//   if(checkNullArr(tenmh)==true){gotoxy(x,y+22);printf("%s","Khong duoc de trong \"Ten Mon Hoc!!!\"");tenmh[j] = ' ';goto TM;}
   if(checkNullArr(soCau)==true){clearPartOfScreen(x,y+22,x+40,y+22);gotoxy(x,y+22);
        printf("%s","Khong duoc de trong \"So Cau Hoi Thi!!!\"");soCau[z]=' ';goto SC;
		}
   if(checkNullArr(soPhut)==true){clearPartOfScreen(x,y+22,x+40,y+22);gotoxy(x,y+22);
        printf("%s","Khong duoc de trong \"So Phut Thi!!!\"");soPhut[n] = ' ';goto PT;}
   if(checkNullArr(tenmh)==false &&checkNullArr(soCau)==false &&checkNullArr(soPhut)==false){
   
	   slc = convertIntegerFromCharArr(soCau);
	   sP = convertIntegerFromCharArr(soPhut);
	   if(slc >MAX_QUESTION_AMOUNT ){clearPartOfScreen(x,y+22,x+40,y+22);gotoxy(x,y+22);
        printf("%s"," So cau hoi thi toi da la 100 cau hoi!!!");goto SC;
	   	
	   }
	   if(slc<=MIN_QUESTION_AMOUNT){
	   	clearPartOfScreen(x,y+22,x+40,y+22);gotoxy(x,y+22);
        printf("%s"," So cau hoi thi khong duoc nho hon hoac bang 0!!!");goto SC;
	   }
   }else{
//   	      goto TM;
   }
 

   return 0;
}
void initExamTime(EXAMTIME &examTime){
	examTime.seconds = examTime.minutes*60;
	examTime.restSeconds = examTime.seconds;
}
	
void loadThoiGianThi(EXAMTIME &examTime){
		FILE *file;
         file = fopen(TIMEEXAM,"rb"); 
         fread(&examTime,sizeof(EXAMTIME),1,file);
         fclose(file);

}
char convertTickNumberToAnswer(int tickNumber){
    if(tickNumber ==0){return 'A';}	
    if(tickNumber ==1){return 'B';}	
    if(tickNumber ==2){return 'C';}	
    if(tickNumber ==3){return 'D';}
	else{
		return -1;
	}	
}
int ConvertAnswerToconvertTickNumber(char da){
    if(da =='A'){return 0;}	
    if(da =='B'){return 1;}	
    if(da =='C'){return 2;}	
    if(da =='D'){return 3;}	
	else{
		return -1;
	}	
}

int randomAnswerTickNumber(char da,int id){
    
	 time_t seconds;
	 seconds = time(NULL);
	int number = (id+seconds+ConvertAnswerToconvertTickNumber(da))%4;	
    return number;
}
int randomMark(int id,int slc){
	return id%slc;
}
CAUHOI invertAnswer(CAUHOI cauHoi,int tickNumber){
      	//tickNumber la dap an dung
		  char tmpA [MAX_CONTENT_QUESTION] = "";
      	char c = convertTickNumberToAnswer(tickNumber);
      	if(c==cauHoi.da){
      		tickNumber--;
      		if(tickNumber<0){tickNumber+=2;
			  }
			c = convertTickNumberToAnswer(tickNumber);
		  }
		  else{
		  
      	if(c=='A'){
      		strcpy(tmpA,cauHoi.a);
      		if(cauHoi.da=='B'){
      			strcpy(cauHoi.a,cauHoi.b);
      			strcpy(cauHoi.b,tmpA);
			  }
			if(cauHoi.da=='C'){
      			strcpy(cauHoi.a,cauHoi.c);
      			strcpy(cauHoi.c,tmpA);
			  }
			if(cauHoi.da=='D'){
      			strcpy(cauHoi.a,cauHoi.d);
      			strcpy(cauHoi.d,tmpA);
			  }
			  cauHoi.da = c;
		  }
		 
		  if(c=='B'){
      		strcpy(tmpA,cauHoi.b);
      		if(cauHoi.da=='A'){
      			strcpy(cauHoi.b,cauHoi.a);
      			strcpy(cauHoi.a,tmpA);
			  }
			if(cauHoi.da=='C'){
      			strcpy(cauHoi.b,cauHoi.c);
      			strcpy(cauHoi.c,tmpA);
			  }
			if(cauHoi.da=='D'){
      			strcpy(cauHoi.b,cauHoi.d);
      			strcpy(cauHoi.d,tmpA);
			  }
			  cauHoi.da = c;
		  }
	
	   
	  if(c=='C'){
      		strcpy(tmpA,cauHoi.c);
      		if(cauHoi.da=='B'){
      			strcpy(cauHoi.c,cauHoi.b);
      			strcpy(cauHoi.b,tmpA);
			  }
			if(cauHoi.da=='A'){
      			strcpy(cauHoi.c,cauHoi.a);
      			strcpy(cauHoi.a,tmpA);
			  }
			if(cauHoi.da=='D'){
      			strcpy(cauHoi.a,cauHoi.d);
      			strcpy(cauHoi.d,tmpA);
			  }
			  cauHoi.da = c;
		  }
	
	   if(c=='D'){
      		strcpy(tmpA,cauHoi.d);
      		if(cauHoi.da=='B'){
      			strcpy(cauHoi.d,cauHoi.b);
      			strcpy(cauHoi.b,tmpA);
			  }
			if(cauHoi.da=='C'){
      			strcpy(cauHoi.d,cauHoi.c);
      			strcpy(cauHoi.c,tmpA);
			  }
			if(cauHoi.da=='A'){
      			strcpy(cauHoi.d,cauHoi.a);
      			strcpy(cauHoi.a,tmpA);
			  }
			  cauHoi.da = c;
		  }
       }
	return cauHoi;
	
}



void saveDetailExamOfStudent(DETHI deThi,char masv[MAXMSV],char mamh[MAXMMH]){
	CTT ctt;
	ctt.mamh[0] = ' ';
	ctt.masv[0] = ' ';
	FILE *file;
	file = fopen(DETAILEXAM,"ab");

	for(int i=0;i<deThi.n;i++){
		strcpy(ctt.masv,masv);
	    strcpy(ctt.mamh,mamh);
		ctt.cauHoiThi = *deThi.cauHoiThi[i];
	    fwrite(&ctt,sizeof(CTT),1,file);
	}
	
	fclose(file);
	
}

OBJECR_LCT printfDetailExamOfStudentData(CTT ctt[MAX_QUESTION_AMOUNT],CAUHOI cauHoi [MAX_QUESTION_AMOUNT],int count){
	int x=5,y=1;
	//dung ham search
	char tenSV[MAXHOSV] = "Doan Hong Dang";
	char tenmh[MAXTMH]  ="Lich Su The Gio Trung Dai";
	strupr(tenmh);
	char tenBang[MAX_CONTENT_QUESTION] = "BANG THONG TIN CHI TIET CAC CAU HOI THI CUA SINH VIEN";
	 	gotoxy(findCenterScreenX(tenBang),y-1);
	 	printf("%s",tenBang);
	 	gotoxy(findCenterScreenX(tenBang),y);
	 	printf("%s\t\t\t\t\t\t%s",ctt[0].masv,tenSV);
	 	gotoxy(x+20,y+1);colorText(6);
	 	printf("%s %s%s",tenmh,"__",ctt[0].mamh);clearColor();
	 	gotoxy(0,46);
	 	printf("%s","Nhan F1 de duyet toi                  Nhan F2 de duyet lui             Nhan phim mui ten len xuong de duyet bang            ESC:Thoat");
	    gotoxy(x+139,y+2);printf(" Da Chon");
	    gotoxy(x+148,y+2);printf("Dap An");
	    gotoxy(x+156,y+2);printf("Diem");
        bool end = false;
	char ndch[MAX_CONTENT_QUESTION] = "Our 12th grade Literature test will help you to synthesize and re-evaluate the entire volume of Literature knowledge you have learned in 12th grade. The content of the test is based on the content of lectures. The candidates will consolidate and improve their knowledge and prepare for graduation and university exams.Our 12th grade Literatu will help you to synthesize and re-evaluate the entire volume of Literature knowledge you have learned in 12th grade. The content of the test is based on the content of lectures. The candidates will consolidate and improve their knowledge and prepare for graduation and university exams..Our 12thgrade Literature test will help you to synthesize and re-evaluate the entire volume of Literature knowledge you have learned in 12th grade. The content of the test is based on the content of lectures. The candidates will consolidate and improve their knowledge and prepare for graduation and university exams.";
	OBJECR_LCT locationOfDetail[11];int arrow = 0;
	OBJECR_LCT diemxy;
	OBJECR_LCT diemxyL;
	OBJECR_LCT diemxyT;
	int page = 1;int j = 10;
	int sttC = 0;
	int tickPage;
	int i = 0;
	int back = false;
	int indexOfLocation;
	int startIndex = -10;
	int maxShowChar = 380;
	char c = ' ';
	
	while(true){
	
L:		 tickPage = 0;j=9;indexOfLocation = 0;
        diemxy.x = x;
	    diemxy.y = y+3;
	    diemxyL.x = x;
	    diemxyL.maxY = y+3;
	    diemxyT.x = x;
	    diemxyT.y = y+3;
		for(int k=0;k<count;k++){                               //i = starindex+10
			if(k%10==0){
			   startIndex=k;
			   tickPage++;	
			}
			if(tickPage==page){
				
				break;
			}
		}
		for( i=startIndex;i<startIndex+10;i++){
			gotoxy(0,0);printf("%s","   ");
			gotoxy(0,0);printf("%d",i);
			if(i>count-1){
				end = true;
				sttC = count - startIndex; 
				break;
			}
			else {
			
			    if((startIndex+10)==count)end = true;
				diemxyT.x = x;
				diemxyT.y = diemxyL.maxY;
			    /*diemxyL = makeTable(diemxyT,4,140,'|','_');*/ 
				diemxyL = makeTable_Type2(diemxyT,4,140);
				locationOfDetail[indexOfLocation] =  diemxyL; indexOfLocation++;
				diemxy.x = x;
				diemxy.y = diemxyL.y;
				gotoxy(diemxy.x-2,diemxy.y+1);
				if(sttC<=count){
				   sttC = ((page)*10)-j;printf("%d",sttC);j--;
				   
				}			
				if(strlen(ndch)>maxShowChar){
					char ndTmp[maxShowChar+1];
					for(int i=0;i<=maxShowChar;i++){
						ndTmp[i] = ndch[i];
					}
					
				
					ndTmp[maxShowChar+1] = '\0';
					
					showStringInLocation(ndTmp,diemxy.x+1,diemxy.y+1,diemxy.x+1+130);
					gotoxy(maxShowChar+1,diemxy.y+3);
					printf("%s","(con tiep....)");ndTmp[0] = '\0';//
				}
				else{
				
				  showStringInLocation(ndch,diemxy.x+1,diemxy.y+1,diemxy.x+1+130);
			    }
				
				
	                diemxyT.x = diemxyL.maxX;
								
//					diemxyL = makeTable(diemxyT,4,7,'|','_');
                    diemxyL = makeTable_Type2(diemxyT,4,7);
					diemxy.x = x+142;
				    diemxy.y = diemxyT.y;	
					gotoxy(diemxy.x,diemxy.y+2);
					colorText(6);printf("%c",ctt[i].cauHoiThi.daC);clearColor();
				
	                diemxyT.x = diemxyL.maxX;;
					  			
					diemxy.x = diemxy.x+7;
				    diemxy.y = diemxyT.y;
//					diemxyL = makeTable(diemxyT,4,7,'|','_');
				    diemxyL = makeTable_Type2(diemxyT,4,7);
					gotoxy(diemxy.x,diemxy.y+2);
					colorText(4);printf("%c",ctt[i].cauHoiThi.daD);clearColor();
					
					diemxyT.x = diemxyL.maxX;;
					
//					diemxyL = makeTable(diemxyT,4,7,'|','_');
                    diemxyL = makeTable_Type2(diemxyT,4,7);
					diemxy.x = diemxy.x+7;
				    diemxy.y = diemxyT.y;
				    gotoxy(diemxy.x,diemxy.y+2);
			    	printf("%.1f",ctt[i].cauHoiThi.diem);//166,44
			    	
			    
			    }
			}
			gotoxy(diemxyL.maxX,diemxyL.maxY+1);
			printf("%s %d","Page",page);
			//
			if(back==true){
				
		    	
					if(arrow <=0){
						arrow = 0;
					}
				
					
					if(arrow>9){
					}
					else if(arrow>indexOfLocation-1){
					}
					else {
				
				    if(arrow>0)makeTable_Color(locationOfDetail[arrow-1],4,140,'|','_',7,7);
				    
//					makeTable_Color(locationOfDetail[arrow],4,140,'|','_',57,57);
                    makeTable_Color_Type2(locationOfDetail[arrow],4,140,57,57);
					arrow++;
				    }
		
			    
			}
			//
			else {
			
		W:	if(kbhit){
				c = getch();fflush(stdin);
				if(c==13 && arrow>=0){
			    	  	 clearPartOfScreen(x-4,y+2,diemxyL.maxX+7,diemxyL.maxY+1);
			    	  	 gotoxy(x,y+3);printf("%s %d %s","Cau ",arrow+(page-1)*10,": ");
						int endStr = 0;
						
			    	  	endStr = showStringInLocation(cauHoi[arrow+(page-1)*10-1].nd,x,5,140);
			    	  	if(ctt[arrow+(page-1)*10-1].cauHoiThi.daD=='A'){colorText(4);}
						gotoxy(x,endStr+2);printf("A. ");clearColor();
						endStr = showStringInLocation(cauHoi[arrow+(page-1)*10-1].a,x+4,endStr+2,140);
						if(ctt[arrow+(page-1)*10-1].cauHoiThi.daD=='B'){colorText(4);}
						gotoxy(x,endStr+2);printf("B. ");clearColor();
						endStr = showStringInLocation(cauHoi[arrow+(page-1)*10-1].b,x+4,endStr+2,140);
						
						if(ctt[arrow+(page-1)*10-1].cauHoiThi.daD=='C'){colorText(4);}
						gotoxy(x,endStr+2);printf("C. ");clearColor();
                        endStr = showStringInLocation(cauHoi[arrow+(page-1)*10-1].c,x+4,endStr+2,140);
						if(ctt[arrow+(page-1)*10-1].cauHoiThi.daD=='D'){colorText(4);}
						gotoxy(x,endStr+2);printf("D. ");clearColor(); 
						endStr = showStringInLocation(cauHoi[arrow+(page-1)*10-1].d,x+4,endStr+2,140);
						gotoxy(x,endStr+2);printf("%s %c","Chon: ",ctt[arrow+(page-1)*10-1].cauHoiThi.daC);
						   while(c=getch()!=27){
						   	
						   }
						   
			    	  	   clearPartOfScreen(x-4,y+3,x+1+145,endStr+2);
			    	  	   arrow--;
					  	   back = true;
					  	   gotoxy(x+139,y+2);printf(" Da Chon");
						   gotoxy(x+148,y+2);printf("Dap An");
						   gotoxy(x+156,y+2);printf("Diem");
						   goto L;
                         
					  }
				if(c==59){ //F1
				
				 if(end==false){
				    arrow = 0;
				    clearPartOfScreen(x-4,y+3,diemxyL.maxX+7,diemxyL.maxY+1);
					page++;
					goto L;
				}else {
					goto W;
				}
			}
		        if(c==60){ //F2 lui
		        	 
				  if(page==1 && sttC==1){
				  	
				  }
				  if(page!=1){
				    arrow = 0; 
				    clearPartOfScreen(x-4,y+3,diemxyL.maxX+7,diemxyL.maxY+1);
					page--;
					//startIndex-=20 ;
					end = false;
					//sttC-=20;
					goto L;
				  }
				
				
			}
			    if(c==27)goto E;
		    	if(c==80){
					if(arrow <=0){
						arrow = 0;
					}
				
					
					if(arrow>9){
					}
					else if(arrow>indexOfLocation-1){
					}
					else {
				
				    if(arrow>0)/*makeTable_Color(locationOfDetail[arrow-1],4,140,'|','_',7,7);*/makeTable_Color_Type2(locationOfDetail[arrow-1],4,140,7,7);
				    
//					makeTable_Color(locationOfDetail[arrow],4,140,'|','_',57,57);
					makeTable_Color_Type2(locationOfDetail[arrow],4,140,57,57);
					arrow++;
				    }
		
			    }
				if(c==72){arrow--;
					if(arrow <=0){
					 arrow = 0;
					}
					
					
					else{
					if(arrow<=9)/*makeTable_Color(locationOfDetail[arrow],4,140,'|','_',7,7);*/makeTable_Color_Type2(locationOfDetail[arrow],4,140,7,7);
//					makeTable_Color(locationOfDetail[arrow-1],4,140,'|','_',57,57);
					makeTable_Color_Type2(locationOfDetail[arrow-1],4,140,57,57);	
							
				}
			}
	}
	}
			goto W;
		
		
	}
	E:	return diemxyL;
	
}

int  showDetailExamOfStudentData(char masv[MAXMSV],char mamh[MAXMMH]){
	int x = 5,y=5;
	
	CTT tmp;
	CAUHOI cauHoi[MAX_QUESTION_AMOUNT];
	FILE *file;
	file = fopen(DETAILEXAM,"rb");
	bool checkExit = false;
	int i = 0;
	if(file==NULL){
		
	   printf("%s","Khong mo duoc file du lieu");return -1;
     }
	 else{
	 	
	    CTT ctt[MAX_QUESTION_AMOUNT];
    	while(fread(&tmp,sizeof(tmp),1,file)){
	    	if(stricmp(tmp.masv,masv)==0 &&stricmp(tmp.mamh,mamh)==0){
	    	    ctt[i] = tmp;
				i++;	checkExit = true;
			}
			
	} fclose(file);
	
	if(checkExit==true){
		//search cau hoi
		for(int j=0;j<i;j++){
			strcpy(cauHoi[j].nd , "lp you to synthesize and re-evaluate the entire volume of Literature knowledge you have learned in 12th grade. The content of the test is based on the content of lectures. The candidates will consolidate and improve their knowledge and prepare for graduation and university exams.");
            strcpy(cauHoi[j].a , "dap an A  ntire volume of Literature knowledge you have learned in 12th grade. The content of the test is based on the content of lectures. The candidates will consolidate and improve their knowledge and prepare for graduation and university exams.");
		    strcpy(cauHoi[j].b , "da an B  ectures. The candi");
            strcpy(cauHoi[j].c , "da an C  e and prepare for graduation and university exams..Our 12thgrade Literature test will help you to synthesize and re-evaluate the entire volume of Literature knowledge you have learned in 12th grade. The content of the test is ");
            strcpy(cauHoi[j].d , "da an D  wledge and prepare for graduation and university exams.Our 12th grade Literatu will help you to synthesize and re-evaluate the entire volume of Literature knowledge you have learned in 12th grade. T.");  
 		}
 		
		
		
		
		//
	    printfDetailExamOfStudentData(ctt,cauHoi,i);
	     return 1;
	}
	else{
		return -1;
	}
	
     }
	
}

void displayMakingExam(){
	systemCls();
	OBJECR_LCT diemxy;int x=70,y=10;
	diemxy.x = x;diemxy.y = y;
	gotoxy(x,y-1);printf("%s","DANG SOAN DE THI....");
	makeTable(diemxy,1,21,'|','_');
	for(int i=0;i<=20;i++){
		gotoxy(x+i,y+1);
		colorText(42);
		printf("%c",' ');Sleep(250);
	}clearColor();
	clearPartOfScreen(x,y-1,x+30,y+1); 

}
void displayRestoringExam(){
	systemCls();
	OBJECR_LCT diemxy;int x=70,y=10;
	diemxy.x = x;diemxy.y = y;
	gotoxy(x,y-1);printf("%s","DANG KHOI PHUC DE THI....");
	makeTable(diemxy,1,21,'|','_');
	for(int i=0;i<=20;i++){
		gotoxy(x+i,y+1);
		colorText(68);
		printf("%c",' ');Sleep(250);
	 }clearColor();
	clearPartOfScreen(x,y-1,x+30,y+1); 

}

int  Inorder_Count_Filter(NODECAUHOI root,CAUHOI cauHoi[],char mamon[MAXMMH])
{   
   int dem = 0;
   int  STACKSIZE = 500;
   NODECAUHOI Stack[STACKSIZE];
   NODECAUHOI p=root;
   int sp=-1;	 // Khoi tao Stack rong
   do
   { while (p != NULL)
      {	 Stack[++sp]= p;
	 p= p->left;
      }
      if (sp != -1)
      {	 p=Stack[sp--];
      //do something about p
	 
	 if(stricmp(p->cauhoi.mamh,mamon)==0){
	 	
	 	cauHoi[dem] = p->cauhoi;
	 	dem++;
	 }
//	 cout << p->info << " ";
	 //
	 p=p->right;
      }
      else break;
   } while (1);
return dem;
}


int moduleThi(NODECAUHOI dscauhoi,char masv[MAXMSV],char hoSv[MAXHOSV],char tenSV[MAXTENSV],MON monThi) {
	
	int status = 2;
	int statusExam = 2;
	
while(status !=1){
Con: systemCls(); //system("cls");
    stopExam = false;
    TIME localTime;
     EXAMTIME examTime;
       
    
    
     CHT cht[MAX] ;
   
    localTime = getTime();
     
    
    int slc ;
    
    displayStartExamScreen(20,10);
    status = getRequestExam(monThi.tenmh,slc,examTime.minutes);
    if(status==1){
    	continue;
	}
    bool thiLai;
    int mangId[MAX] ;//random lay ra
    strupr(masv);
    int slcl;
    
    
    initExamTime(examTime);
    DETHI deThi;//lay tu mangId
    deThi.n = 0;
    CAUHOI* mangCauHoi = new CAUHOI[MAX_QUESTION_AMOUNT+2];//search theo mangId tu dscauhoi
    CAUHOI* mangCHTmp = new CAUHOI[MAXQUESTION];
    float bangDiem[slc+2];
    thiLai = useOldExam(masv,monThi.mamh,slc);  
    if(thiLai==true){
                           
       
        for(int i=0;i<slc;i++){
            cht[i] = loadDeThiTuFileTam(i);
            deThi.cauHoiThi[deThi.n] = &cht[i];
//            mangId[i] = cht[i].id;
              //searchTree 
              mangCauHoi[i] = SearchTree(dscauhoi,cht[i].id);
              mangCauHoi[i] = invertAnswer(mangCauHoi[i],ConvertAnswerToconvertTickNumber(cht[i].daD));
			  //
            deThi.n++;
            }
        loadThoiGianThi(examTime);
       
    }
    if(thiLai==false){                                                           //tao mang id
         slcl = Inorder_Count_Filter(dscauhoi,mangCHTmp,monThi.mamh);
         makeIdArray(slcl-1,mangId);
         //
         
         //
         
//         if(slc>slcl){
//         	gotoxy(20,20+22);printf("%s","So luong cau hoi hien tai khong du!!!");
//		 }

      for(int i=0;i<slc;i++){
      	mangCauHoi[i] = mangCHTmp[mangId[i]];
	  }
	  
    }
    
    makeLogFile(masv,monThi.mamh,slc);
    
    if(thiLai ==false){                                                           //neu thi moi thi tron lai dap an
	
		for(int i=0;i<slc;i++){
		  	int tickNumber = randomAnswerTickNumber(mangCauHoi[i].da,mangCauHoi[i].id);
		  	mangCauHoi[i] = invertAnswer(mangCauHoi[i],tickNumber);
		  }
		  examTime.seconds = 0;      
     }
        
       for(int i=0;i<slc-1;i++){bangDiem[i]=lamTronDiem((float)10/slc);}           //tao bang diem  
       bangDiem[slc-1]=10-bangDiem[0]*(slc-1);                             
       int indexMark = randomMark(mangCauHoi[slc-1].id,slc);                       //random lai diem
	   float temp = bangDiem[indexMark];
	   bangDiem[indexMark] = bangDiem[slc-1];                                                               
       bangDiem[slc-1] = temp;
	    if(thiLai==true)displayRestoringExam();
		else {
		  displayMakingExam();
	    }
	  
	                                                               
       makeExam(&deThi,mangCauHoi,thiLai,slc,masv);                              //vao thi          
       initExam(masv,hoSv,tenSV, monThi.tenmh,&deThi,mangCauHoi,slc,bangDiem,localTime,examTime);
	   saveDetailExamOfStudent(deThi,masv,monThi.mamh);    
	   
	   Sleep(1000);     
	   goto Con; 
	   
    }
    
}




