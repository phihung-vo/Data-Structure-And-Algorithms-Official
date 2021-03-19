#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include"include.h"
#include"module_Hanh.cpp"
#include"module_Hung.cpp"
#include"module_ChiTietThi.cpp"
#include"module_Dang.cpp"

int main(){
//     backGround();
	systemCls();
	//khoi tao
	
       DSLOP dslop;
       DSMON dsmon;
       NODECAUHOI dscauhoi;
       loadDSMon(&dsmon);
	   loadDSLop(&dslop);
	   loadDSCH(dscauhoi);
//	   Inorder_Count_Filter()

//		Input_Class(&dslop);//loi in dc sv cua lop dau tien
//		Input_Mon(&dsmon);
//		Input_SV(&dslop);   

//      Input_CH(dscauhoi,&dsmon);


		int login = -1;
		
		ACCOUNT account; 
  do {
  	  systemCls();
  	  
      account = module_Login(45,10,&dslop);
       if(strcmp(account.tenDangNhap,"GV")==0){//giao vien
	     	menu(&dslop,&dsmon,dscauhoi);
	  }
	   else if(strcmp(account.tenDangNhap,"")==0 &&strcmp(account.password,"")==0){
	   	login = 1;
	   }
      else {//neu nguoi dang nhap la sinh vien
      	int index;
      	char notice[MAX] = " ";
      	userManual_DoExam();
      
 THITIEP:
 	    
 	    SINHVIEN sv = searchStudentByMaSV(&dslop,account.tenDangNhap);
		DSMON *dsmonExam = new DSMON;

	    makeDSMonForDoExam(&dsmon,dsmonExam,sv);
	    systemCls();
SM:    	index = bangMonThi(dsmonExam);
		
//  	    if(index==-1){
//		  strcpy(notice,"Mon nay hien tai chua co cau hoi thi.Vui long chon lai mon thi!!!");
//    	dialog(85,0,notice);
//    	goto SM;
//		}
		if(index<0){
      		display_GoodBye();    
      		continue;
		  }

		 if(ExistQuestion(dscauhoi,dsmonExam->mon[index]->mamh)==false){
    	strcpy(notice,"Mon nay hien tai chua co cau hoi thi.Vui long chon lai mon thi!!!");
    	dialog(85,0,notice);
    	goto SM;
		}
      	
		else {
		  	
		    MON monThi;
		    strcpy(monThi.tenmh,dsmonExam->mon[index]->tenmh);
		    strcpy(monThi.mamh,dsmonExam->mon[index]->mamh);
      	    moduleThi(&dslop,dscauhoi,account.tenDangNhap,sv.ho,sv.ten,monThi);
//      	    xemDiem(&dslop,"n17dcat015",mamh);system("pause");

            goto THITIEP;
		  }
	  }
  }while(login<0);
 	system("cls");
}

 
