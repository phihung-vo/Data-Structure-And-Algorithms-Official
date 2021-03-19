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

OBJECR_LCT printfDetailExamOfStudentData(CTT ctt[MAX_QUESTION_AMOUNT+2],CAUHOI cauHoi [MAX_QUESTION_AMOUNT+2],int count){
	int x=5,y=1;
	//dung ham search

        bool end = false;
//	char ndch[MAX_CONTENT_QUESTION] = "Our 12th grade Literature test will help you to synthesize and re-evaluate the entire volume of Literature knowledge you have learned in 12th grade. The content of the test is based on the content of lectures. The candidates will consolidate and improve their knowledge and prepare for graduation and university exams.Our 12th grade Literatu will help you to synthesize and re-evaluate the entire volume of Literature knowledge you have learned in 12th grade. The content of the test is based on the content of lectures. The candidates will consolidate and improve their knowledge and prepare for graduation and university exams..Our 12thgrade Literature test will help you to synthesize and re-evaluate the entire volume of Literature knowledge you have learned in 12th grade. The content of the test is based on the content of lectures. The candidates will consolidate and improve their knowledge and prepare for graduation and university exams.";
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
	bool tap = false;
	while(true){
	
L:		 tickPage = 0;j=9;indexOfLocation = 0;
        diemxy.x = x;
	    diemxy.y = y+3;
	    diemxyL.x = x;
	    diemxyL.y = y+3;
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
//			gotoxy(0,0);printf("%s","   ");
//			gotoxy(0,0);printf("%d",i);
			if(i>count-1){
				end = true;
				sttC = count - startIndex; 
				break;
			}
			else {
			
			    if((startIndex+10)==count)end = true;

			    diemxyT.y = diemxyL.maxY;
			    diemxyT.x = x;
				diemxyL = makeTable_Type2(diemxyT,4,140);

				locationOfDetail[indexOfLocation] =  diemxyL; indexOfLocation++;
				diemxy.x = x;
				diemxy.y = diemxyL.y;
				gotoxy(diemxy.x-2,diemxy.y+1);
				if(sttC<=count){
				   sttC = ((page)*10)-j;printf("%d",sttC);j--;
				   
				}			
				if(strlen(cauHoi[0].nd)>maxShowChar){
					char ndTmp[maxShowChar+1];
					for(int i=0;i<=maxShowChar;i++){
						ndTmp[i] = cauHoi[0].nd[i];
					}
					
				
					ndTmp[maxShowChar+1] = '\0';
					
					showStringInLocation(ndTmp,diemxyT.x+1,diemxyT.y+1,diemxyT.x+1+130);
					gotoxy(maxShowChar+1,diemxy.y+3);
					printf("%s","(con tiep....)");ndTmp[0] = '\0';//
				}
				else{
				
				  showStringInLocation(cauHoi[i].nd,diemxyT.x+1,diemxyT.y+1,diemxyT.x+1+130);
			    }
				
				
	                diemxyT.x = diemxyL.maxX;
                 
                    diemxyL = makeTable_Type2(diemxyT,4,5);

				    diemxy.y = diemxyT.y;	
					gotoxy(diemxyT.x+1,diemxyT.y+1);
					colorText(6);printf("%c",ctt[i].cauHoiThi.daC);clearColor();
				
	                diemxyT.x = diemxyL.maxX;;
                    
			
					diemxy.x = diemxy.x+7;
				    diemxy.y = diemxyT.y;

				    diemxyL = makeTable_Type2(diemxyT,4,5);
					gotoxy(diemxyT.x+1,diemxyT.y+1);
					colorText(4);printf("%c",ctt[i].cauHoiThi.daD);clearColor();
					
					diemxyT.x = diemxyL.maxX;;
                    diemxyL = makeTable_Type2(diemxyT,4,5);
					diemxy.x = diemxy.x+7;
				    diemxy.y = diemxyT.y;
				    gotoxy(diemxyT.x+1,diemxyT.y+1);
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
				    

                    makeTable_Color_Type2(locationOfDetail[arrow],4,140,57,57);
					arrow++;
				    }
		
			    
			}
			//
			else {
			
		W:	if(kbhit){
			   
				c = getch();fflush(stdin);
				if(c==13 && arrow>=0 && tap==true){
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
		    		tap = true;
					if(arrow <=0){
						arrow = 0;
					}
				
					
					if(arrow>9){
					}
					else if(arrow>indexOfLocation-1){
					}
					else {
				
				    if(arrow>0)makeTable_Color_Type2(locationOfDetail[arrow-1],4,140,IDCOLOR_CLEARTEXT,IDCOLOR_CLEARTEXT);
				    makeTable_Color_Type2(locationOfDetail[arrow],4,140,57,57);
					arrow++;
				    }
		
			    }
				if(c==72){
				    tap = true;
					arrow--;
					if(arrow <=0){
					 arrow = 0;
					}
					
					
					else{
					if(arrow<=9)makeTable_Color_Type2(locationOfDetail[arrow],4,140,IDCOLOR_CLEARTEXT,IDCOLOR_CLEARTEXT);
					makeTable_Color_Type2(locationOfDetail[arrow-1],4,140,57,57);	
							
				}
			}
	}
	}
			goto W;
		
		
	}
	E:	return diemxyL;
	
}

int  showDetailExamOfStudentData(NODECAUHOI dscauhoi,SINHVIEN sv,MON mon){
	int x = 5,y=5;
	CTT tmp;
	
	FILE *file;
	file = fopen(DETAILEXAM,"rb");
	int checkExit = -2;//chua thi
	int i = 0;
	systemCls();
	if(file==NULL){
		
			char notice[MAX] = "Loi mat file du lieu!!! ";
		    dialog(75,1,notice);
	  return -1;
     }
	 else{
	 	
	    CTT ctt[MAX_QUESTION_AMOUNT];
    	while(fread(&tmp,sizeof(tmp),1,file)){
    		if(stricmp(tmp.masv,sv.masv)==0){
    			if(stricmp(tmp.mamh,mon.mamh)==0){
	    	       ctt[i] = tmp;
				   i++;	
				   checkExit = 1;
			    }
			}
	    	
			
	} fclose(file);
	
	if(checkExit==1){
		//search cau hoi
       CAUHOI* cauHoi = new CAUHOI[MAX_QUESTION_AMOUNT+2];

		for(int j=0;j<i;j++){
			cauHoi[j] = SearchTree(dscauhoi,ctt[j].cauHoiThi.id);
		}
        systemCls();
        int x = 5,y=1;
	    strupr(mon.tenmh);
		char tenBang[MAX_CONTENT_QUESTION] = "BANG THONG TIN CHI TIET CAC CAU HOI THI CUA SINH VIEN";
	 	gotoxy(findCenterScreenX(tenBang),y-1);
	 	printf("%s",tenBang);
	 	gotoxy(findCenterScreenX(tenBang),y);
	 	printf("%s\t\t\t\t\t\t%s %s",sv.masv,sv.ho,sv.ten);
	 	gotoxy(x+20,y+1);colorText(6);
	 	printf("%s %s%s",mon.tenmh,"__",mon.mamh);clearColor();
	 	gotoxy(0,46);
	 	printf("%s","Nhan F1 de duyet toi                  Nhan F2 de duyet lui             Nhan phim mui ten len xuong de duyet bang            ESC:Thoat");
	    gotoxy(x+139,y+2);printf(" Da Chon");
	    gotoxy(x+148,y+2);printf("Dap An");
	    gotoxy(x+156,y+2);printf("Diem");
        
	    printfDetailExamOfStudentData(ctt,cauHoi,i);
	     return 1;
	}
	else if(checkExit==-2){//sinh vien chua thi
		return -2;
	}
	
	
     }
	
}
int  bangMonDaThi(DSMON *dsmon,char mamh[MAXMMH], char masv[MAXMSV]){
	system("cls");
	//loc ra dsmon da co diem
    char c; int tick=1;	int stcthuc = dsmon->n/20;
    int index = 0;
    int arrow = 0;
   
    //goi ham in
    index = inMonThi(tick,dsmon,index);
    int i = 0; int vitri = 0;
     c = ' ';
W:   if(kbhit()){
    	c = getch();fflush(stdin);
    	if(c==-32){c = getch();
    		if(c==77){//qua phai
    			tick++;
    			arrow = 0;
    			int tmp = index;
    			clearPartOfScreen(xGd-23,yGd+5,xGd+38+10,yGd+5+38);
    			index = inMonThi(tick,dsmon,arrow);
    			if(tmp==index)tick--;
			}
			if(c==75){//qua trai
			    
				tick--;
				arrow = 0;
				int tmp = index;
				clearPartOfScreen(xGd-23,yGd+5,xGd+38+10,yGd+5+38);
				index = inMonThi(tick,dsmon,arrow);
				if(tmp==index)tick++;
			}
		}
		if(c==80){
    		arrow++;
    		if(arrow>=19){
    			arrow = 19;
			}
    		index = inMonThi(tick,dsmon,arrow);
    		
		}
		if(c==72){
			arrow--;
			if(arrow<0)arrow = 0;
			index = inMonThi(tick,dsmon,arrow);
		}
		if(c==13){

			systemCls();
//			printf("%s",dsmon->mon[(19+(tick-1)*20-(19-arrow))]->mamh);system("pause");
//            printf("%d",19+(tick-1)*20-(19-arrow));system("pause");
		    return (19+(tick-1)*20-(19-arrow));
           
		}
		if(c==27){
			return -1;
		}
    	
	}goto W;
}

int getMaSv(char masv[MAXMSV]){
	int x = 20,y = 5;
displayModuleDetailExam(20,5);
int end = -1;

	
int input = x+3+15+4;
int z =0;
int i = 0;
while(end <0) {

T:  
    fflush(stdin);		gotoxy(input+z,y+4);
  	while((masv[z]=getch())!=13){
                        fflush(stdin);
                             
                             if(masv[z]==72){   
                                               if(z>MAXDN-2){
											      backSpace(input+z-1,y+4);
											      goto T;
										       }
											   else {
											   backSpace(input+z-1,y+4);z--;
                                               goto T; }
                                           }
                             if(masv[z]==80){if(z<0)z=0;
                                               if(z>MAXMSV-2){
											 	   backSpace(input+z-1,y+4);z--;
                                                   goto T; }
							 				   else{
												
											     backSpace(input+z-1,y+4);z--;
                                                 goto T;
											}
                                           }
                             if(masv[z]==8) {    
                                                 z--;if(z<0){z=0;}
                                                 else{masv[z+1] = '\0';
                                                 backSpace(input+z,y+4);
                                                 gotoxy(input+z,y+4);continue;
                                                 }
                                             }
                              if(masv[z]==27){                              		
                               		strcpy(masv,"");
									strcpy(masv,"");
									end = 1;
                               		return -1;
							   }
							     
                             if(masv[z]!=72 &&masv[z]!=80 &masv[z]!=8){
							     if(z>MAXMSV-2){//continue;
							      }
                                 else{
	
                                      printf("%c",(char)masv[z]);z++;
                                  }
                                  
                              
                             }
                             
 
        }

		masv[z] = '\0';
		if(strcmp(masv,"")==0){
			gotoxy(x+25,y+15);printf("%s","Vui long dien ma sinh vien!!!");
			Sleep(1000);
	        clearPartOfScreen(x+25,y+15,x+25+50,y+15);
			goto T;
		}
		
	
        end = 1;	
    }
  
	Exit: ;
	return 1;

}
bool checkExistStudent(DSLOP *dslop,char masv[MAXMSV]){
	for(int i=0;i<dslop->n;i++){
				
							if(checkMSV(dslop->lop[i]->dssinhvien,masv)==true){
								//tbao sv bi trung
								
//								printf("MASV BI TRUNG!!! NHAP LAI MSV!"); 
                                return true;
								
								
							}
					
				}
return false;
}
int moduleDetailExam(NODECAUHOI dscauhoi,DSMON *dsmon,DSLOP *dslop){
systemCls();
char masv[MAXMSV] = "";
char mamh[MAXMMH] = "";
int indexMMH;
int statusDetail = 1;

while(true){
L:   statusDetail = getMaSv(masv);
   if(statusDetail<0)break;
   else {
   	    if(checkExistStudent(dslop,masv)==true){
   	    SINHVIEN sv = searchStudentByMaSV(dslop,masv);
   	    DSMON *dsmonTested = new DSMON;
   	    makeDSMonForShowDetail(dsmon,dsmonTested,sv);//dsmonTested = dsmon;
   	    char notice[MAX];
   	    while(true){
   	    	systemCls();
   	    	gotoxy(20,5);
   	    	printf("%s",sv.masv);
   	    	gotoxy(20,6);
   	    	printf("%s %s",sv.ho,sv.ten);
   	    	if(dsmonTested->n==0){
   	    	   strcpy(notice,"Sinh vien chua thi mon nao!!!");
			   GdMonThi();Sleep(500);
			   dialog(75,1,notice);
			   systemCls();
			   break;
			   	
			}
   	    	indexMMH =  bangMonThi(dsmonTested);	
            if(indexMMH<0 &&indexMMH!=-2){
            	systemCls();
            	break;
			}
			
            else if(indexMMH>=0){
            	MON mon;
            	strcpy(mon.mamh,dsmonTested->mon[indexMMH]->mamh);
            	strcpy(mon.tenmh,dsmonTested->mon[indexMMH]->tenmh);
            	systemCls();
   	   	        statusDetail = showDetailExamOfStudentData(dscauhoi,sv,mon);
   	            if(statusDetail==-1){
				
		        }   
		        if(statusDetail==-2){
   	   	
					strcpy(notice,"Loi du lieu!!!");
			        dialog(75,1,notice);
				
		        }
		        if(statusDetail==-3){
   	   	            
			        strcpy(notice,"Sinh vien nay chua thi!!!");
					dialog(75,1,notice);
			        
				
		        }
	       
            }
           systemCls();
		}
   	  
   }
   else {
   	  gotoxy(45,20);
	  printf("%s","Sinh vien nay khong ton tai!!!");
	  Sleep(1000);
	  clearPartOfScreen(45,20,90,20);
	  clearPartOfScreen(42,9,55,9);
   }
   }
   
   
}

	

}
void GdSVForShowMark(MON mon){
		gotoxy(xIn,8);colorText(224);printf("ESC: Exit!");
		displayOuputDSSV(xIn-2,7);
		gotoxy(xIn,11);colorText(234);printf("STT");
		gotoxy(xIn+10,11);colorText(234);printf("MA");
		gotoxy(xIn+35,11);colorText(234);printf("HO");
		gotoxy(xIn+55,11);colorText(234);printf("TEN");
		gotoxy(xIn+105,11);colorText(234);printf("DIEM");
		gotoxy(xIn+120,11);colorText(234);printf("TRANG THAI");
}
void displayOuputDSLopShowMark(int x,int y,MON mon){
	
    OBJECR_LCT diemxy;
	diemxy.x = x;
	diemxy.y = y-1;
	makeTable_Type2(diemxy,2,80);
	gotoxy(diemxy.x+32,diemxy.y+1);
colorText(78);
	printf("%s","BANG DIEM THI");
	
	
colorText(234);
	diemxy.x = x;
	diemxy.y = y+3;
	makeTable_Type2(diemxy,42,80);
} 
void GdLopShowMark(MON mon){
	colorText(158);
		gotoxy(xIn,42);printf("F3:Insert");
		gotoxy(xIn,44);printf("F4:Delete");
		gotoxy(xIn,46);printf("F5:Edit");
		gotoxy(xIn,48);printf("ESC:MENU - Enter:IN_SV - F1:Phai - F2:Trai");
		displayOuputDSLopShowMark(75,5,mon);
		gotoxy(xGd-23,yGd+3);colorText(236);printf("MA LOP");
		gotoxy(xGd+7,yGd+3);colorText(236);printf("TEN LOP");
		gotoxy(xGd+38,yGd+3);colorText(236);printf("NIEN KHOA");
		gotoxy(xGd+38+10+2,yGd+3);colorText(236);printf("SLSV");
}
int inBangLopForShowMark(int tick, DSLOP *dslop, bool rig,MON mon){
	int count =0; char c;
	int i;	int j=0;  int arrow = 0;	int index;
	bool tested = false;
	char statusTested[] = "Da Thi";
	char statusNone[] = "Chua Thi";
	SINHVIEN sv;
	GdLopShowMark(mon); 
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
				GdSVForShowMark(mon);
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
				int arrow = 0;
				int it = 0;
				int dem = -1;
				if(slsv==0){
					gotoxy(xIn+55,30);
					printf("Chua nhap sv!");
				}
			RP:	if( ( (tick*20) - slsv ) > 20 ){
					tick--;
					goto RP; 	
				}
				else {
					for(i=0;i<slsv;i++){
						if(i % 20 == 0) demsv ++;
						if(demsv == tick){
							//ke bang
								OBJECR_LCT diemxy;
								diemxy.x = xIn-2;
								diemxy.y = 12+vitri;
								colorText(226);
								makeTable_Type2(diemxy,2,xIn+125);// bang in sv	
							//sv
							dem++;
							if(dem==it){
								fflush(stdin);
								colorText(225);
								gotoxy(xIn,13+vitri);
								printf("%d",i+1);
								gotoxy(xIn+10,13+vitri);
						        printf("%s",temp->sinhvien.masv);
						        gotoxy(xIn+35,13+vitri);
							    printf("%s",temp->sinhvien.ho);
							    gotoxy(xIn+55,13+vitri);
							    printf("%s",temp->sinhvien.ten);
							    
							    //
	//						    printf("%s",temp->sinhvien.phai);
								gotoxy(xIn+105,13+vitri);
								if(CheckExist_info_Diem(temp->sinhvien.dsdiem,mon.mamh)){
//									printf("%.1f",getDiemFromOfStudent(temp->sinhvien.dsdiem,mon.mamh).diem);
									gotoxy(xIn+120,13+vitri);
									printf("%s",statusTested);
								}
								else {
									gotoxy(xIn+120,13+vitri);
									printf("%s",statusNone);
								}
	
							}
							else {
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
							    
							    //
	//						    printf("%s",temp->sinhvien.phai);
								gotoxy(xIn+105,13+vitri);
								if(CheckExist_info_Diem(temp->sinhvien.dsdiem,mon.mamh)){
//									printf("%.1f",getDiemFromOfStudent(temp->sinhvien.dsdiem,mon.mamh).diem);
									gotoxy(xIn+120,13+vitri);
									printf("%s",statusTested);
								}
								else {
									gotoxy(xIn+120,13+vitri);
									printf("%s",statusNone);
								}

							}
							 							
							
//							printf("%s",temp->sinhvien.password);
							//
							temp = temp->next;
							vitri=vitri+2;
						}
					}
				}
				do{
				  	c=getch();fflush(stdin);
				}while(c!=27);
				if(c==27){
					systemCls();
					return -1;
				}
				if(c==80){
					arrow++;
					it = arrow;
				}
				if(c==72){
					
				}
			}
			if(c==75){//qua trai
			    return -1;
				goto E;
			}
		}goto W;E: ;
	}
	return index;	
}
int inDSSVShowMark(NODESINHVIEN p,MON mon, int page, int arrow, int slsv, int x, int y){
	int count=0, i=0, j=-1, expand=0; char c;

    int startIndex = page*20;
	OBJECR_LCT diemxy;
	int vitri = 0;	
    char daThi[] = "DA THI";
	char chuaThi[] = "CHUA THI";	
RP:		if((page*20 - slsv)>20){
			page--;
			goto RP;
		}else{					
			while(p!=NULL&&i<slsv){
				if(i%20==0) j++;
				if(j==page){
					if(i>=startIndex){
						if(count==arrow){
							
							diemxy.x = x-2;
							diemxy.y = y-1+expand;
							colorText(226);
							makeTable_Type2(diemxy,2,xIn+90);// bang in sv	
							colorText(225);							
							
							gotoxy(x,y+expand+vitri); printf("%s",p->sinhvien.masv);
							gotoxy(x+MAXMSV+2,y+expand+vitri); printf("%s",p->sinhvien.ho);
							gotoxy(x+MAXMSV+MAXHOSV+3,y+expand+vitri); printf("%s",p->sinhvien.ten);
							
							if(CheckExist_info_Diem(p->sinhvien.dsdiem,mon.mamh)){
								gotoxy(x+MAXMSV+MAXHOSV+MAXTENSV+4,y+expand+vitri); 
								printf("%.1f",getDiemFromStudent(p->sinhvien.dsdiem,mon.mamh).diem);
								gotoxy(x+MAXMSV+MAXHOSV+MAXTENSV+MAXPHAI+5,y+expand+vitri); 
								printf("%s",daThi);
								
							}
							else {
								gotoxy(x+MAXMSV+MAXHOSV+MAXTENSV+MAXPHAI+5,y+expand+vitri); 
								printf("%s",chuaThi);
							}
							
							clearColor();
						}else{
							diemxy.x = x-2;
							diemxy.y = y-1+expand;
							colorText(226);
							makeTable_Type2(diemxy,2,xIn+90);// bang in sv	
	//						colorText(225);
							gotoxy(x,y+expand+vitri); printf("%s",p->sinhvien.masv);
							gotoxy(x+MAXMSV+2,y+expand+vitri); printf("%s",p->sinhvien.ho);
							gotoxy(x+MAXMSV+MAXHOSV+3,y+expand+vitri); printf("%s",p->sinhvien.ten);
							if(CheckExist_info_Diem(p->sinhvien.dsdiem,mon.mamh)){
								gotoxy(x+MAXMSV+MAXHOSV+MAXTENSV+4,y+expand+vitri); 
								printf("%.1f",getDiemFromStudent(p->sinhvien.dsdiem,mon.mamh).diem);
								gotoxy(x+MAXMSV+MAXHOSV+MAXTENSV+MAXPHAI+5,y+expand+vitri); 
								printf("%s",daThi);
								
							}
							else {
								gotoxy(x+MAXMSV+MAXHOSV+MAXTENSV+MAXPHAI+5,y+expand+vitri); 
								printf("%s",chuaThi);
							}
						}
	//					vitri+=2;
						expand+=2;
						count++;
							
					}
					
				}
				p=p->next;
				i++;
			}																	
		}
	return i;
}
void displayShowMarkTable(int x,int y,MON mon){
    OBJECR_LCT diemxy;
	diemxy.x = x;
	diemxy.y = y-1;
	makeTable_Type2(diemxy,4,75);
	gotoxy(diemxy.x+28,diemxy.y+1);
    colorText(206);
	printf("%s","BANG DIEM LOP");
    colorText(236);
	gotoxy(diemxy.x+15,diemxy.y+2);
	printf("%s %s","MON:",mon.tenmh);
	clearColor();

}
int DSSVShowMark(NODESINHVIEN p,MON mon, int page, int arrow, int slsv, OBJECR_LCT start, int dai, int rong, int col_right){
	
	displayShowMarkTable(start.x+25,start.y-1,mon);
	gotoxy(start.x+8,start.y+4);printf("%s","Ma Sinh Vien");
	gotoxy(start.x+MAXMSV+MAXHOSV,start.y+4);printf("%s","Ho Va Ten");
	gotoxy(start.x+MAXMSV+MAXHOSV+MAXTENSV+5,start.y+4);printf("%s","Diem");
    gotoxy(start.x+MAXMSV+MAXHOSV+MAXTENSV+MAXPHAI+15,start.y+4);printf("%s","Trang Thai");
	char c; int maxpage=slsv/20, maxrow;
	if(maxpage==0) maxrow=slsv;
	else maxrow=slsv%20;
    
	inDSSVShowMark(p,mon,page,arrow,slsv,start.x+10,start.y+6);//+rong-col_right+2
	c='\0';
	
W:	if(kbhit()){
		c=getch();
		if(c==-32){
			c=getch();
			if(c==77&&page<maxpage){
				page++;
				arrow=0;
				clearPartOfScreen(start.x,start.y+5,start.x+rong-1,start.y+dai-3);
				inDSSVShowMark(p,mon,page,arrow,slsv,start.x+10,start.y+6);
			}
			if(c==75&&page>0){
				page--;
				arrow=0;
				clearPartOfScreen(start.x,start.y+5,start.x+rong-1,start.y+dai-3);
				inDSSVShowMark(p,mon,page,arrow,slsv,start.x+10,start.y+6);
			}
		}
		if(c==80){
			if(maxpage==0){
				if(arrow<maxrow-1){
					arrow++;
				}else{
					arrow=maxrow-1;
				}

				inDSSVShowMark(p,mon,page,arrow,slsv,start.x+10,start.y+6);
			}else{
				if(page<maxpage){
					arrow++;
		    		if(arrow>19){
		    			arrow=19;
					}

		    		inDSSVShowMark(p,mon,page,arrow,slsv,start.x+10,start.y+6);
				}else{
					if(arrow<maxrow-1){
						arrow++;
					}else{
						arrow=maxrow-1;
					}

					inDSSVShowMark(p,mon,page,arrow,slsv,start.x+10,start.y+6);
				}
			} 		
		}
		if(c==72){
			arrow--;
			if(arrow<0) arrow = 0;

			inDSSVShowMark(p,mon,page,arrow,slsv,start.x+10,start.y+6);
		}
		if(c==13){

           	return (19+(page)*20-(19-arrow));
		}
		if(c==27){
			return -1;
		}
	}
	goto W;
}


void displayDSLop(){

    int x = 75;
    int y = 5;
    OBJECR_LCT diemxy;
	diemxy.x = x;
	diemxy.y = y-1;
	makeTable_Type2(diemxy,2,75);
	gotoxy(diemxy.x+28,diemxy.y+1);
    colorText(206);
	printf("%s","DANH SACH LOP");
    colorText(236);
	diemxy.x = x;
	diemxy.y = y+3;
	makeTable_Type2(diemxy,42,75);
	colorText(224);
	
	gotoxy(xIn+20,42);
	printf("UP");
	colorText(224);gotoxy(xIn+12,44);printf("LEFT");
	colorText(224);gotoxy(xIn+26,44);printf("RIGHT");
	colorText(224);gotoxy(xIn+19,46);
	printf("DOWN");
	
	gotoxy(xIn,48);
	printf("ESC:EXIT 	Enter:Chon ");
	
	gotoxy(xGd-20,yGd+3);
	printf("MA LOP");
	gotoxy(xGd+5,yGd+3);
	printf("TEN LOP");
    clearColor();
}
int inTungLop(int tick, DSLOP *dslop,int arrow){

	int count =0; char c;
	int j=0;
    int i=0;
    displayDSLop();
    int vitri=0; //chi dung lam tang them 1 hang trong
RP:    if( ( (tick*20) - (dslop->n) ) > 20 ){
	        tick--;
			goto RP; 
		}
	else {
//		clearPartOfScreen(xGd-23,yGd+5,xGd+38+10,yGd+5+38);//xoa 1 vung in ds
		//sap xep
//		sapXepMon(dsmon);
		//in trang
		for(i=0;i<dslop->n;i++){
				if(i % 20 == 0) j ++;
			if(j == tick){
				if(count==arrow){
					
					colorText(225);
					gotoxy(xGd-20,yGd+5+vitri);
		            printf("%s",dslop->lop[i]->malop);
		            gotoxy(xGd-5,yGd+5+vitri);
			        printf("%s\n",dslop->lop[i]->tenlop);
			        clearColor();
				}
				else {
					gotoxy(xGd-20,yGd+5+vitri);
		            printf("%s",dslop->lop[i]->malop);
		            gotoxy(xGd-5,yGd+5+vitri);
			        printf("%s\n",dslop->lop[i]->tenlop);
				}
				
				vitri=vitri+2;
				count++;
			}
			if(count == 20){
				break;
			}
		}
	}
	return i;
}

int bangDSLop(DSLOP *dslop){

    char c; int tick=1;	int stcthuc = ((dslop->n))/20;
    if(stcthuc==0)stcthuc = 1;
    int index = 0;
    int arrow = 0;
    int lastIndex = 0;
    //goi ham in
    index = inTungLop(tick,dslop,index);
    int tmp = index;
    int i = 0; int vitri = 0;
     c = ' ';
W:   if(kbhit()){
    	c = getch();fflush(stdin);
    	if(c==-32){c = getch();
    		if(c==77){//qua phai
    			
    			if(index==((dslop->n))){
    				
				}
				else {
					tick++;
				    arrow = 0;
				    lastIndex = index;
    			    clearPartOfScreen(xGd-23,yGd+5,xGd+38+10,yGd+5+38);
    			    index = inTungLop(tick,dslop,arrow);//printf("%d %d %d",lastIndex,index,dsmon->n);system("pause");	
				}
    			

			}
			if(c==75){//qua trai
			    
				
				if(index==tmp){
					
				}
				else {
					tick--;
				    arrow = 0;
				    lastIndex = index;
				    clearPartOfScreen(xGd-23,yGd+5,xGd+38+10,yGd+5+38);
				    index = inTungLop(tick,dslop,arrow);	
				}

			}
		}
		if(c==80){
    		arrow++;
    		if(arrow>=19){
    			arrow = 19;
			}
			if((arrow>=((index)-lastIndex-1)) && (((dslop->n)-index)==0)){
				arrow = ((index)-lastIndex-1);
			}

    		index = inTungLop(tick,dslop,arrow);
    		
		}
		if(c==72){
			arrow--;
			if(arrow<0)arrow = 0;
			index = inTungLop(tick,dslop,arrow);//printf("%d %d ",index,(dsmonExam->n)-1);system("pause");	
		}
		if(c==13){

			
           return (19+(tick-1)*20-(19-arrow));
		}
		if(c==27){
			return -1;
		}
    	
	}goto W;


}
void showMarkOfClass(DSLOP *dslop,DSMON *dsmon,NODECAUHOI dscauhoi)	{
	while(true){
		MON mon;
		systemCls();
		int index;
		int indexOfMon;
		int indexOfSV;
	    int status;
	    char notice[MAX];
	    int slsv;
		int tick = 1;
		bool rig = true;
		SINHVIEN sv;
	    OBJECR_LCT start; start.x=20; start.y=3;
	    int dai=48, rong=160, col_right=rong/2+22, row_bottom=10, x_esc=3, y_esc=4,page=0, arrow=0;
	    
XL:     systemCls();
SL:     index = bangDSLop(dslop);
        if(index==-1){
	    	break;
		}
		if(EmptyDSSV(dslop->lop[index]->dssinhvien)==1){
        	strcpy(notice,"Lop nay hien tai chua co sinh vien!!!");
        	dialog(75,0,notice);
        	goto SL;
		}
        if(index !=-1){
        	slsv = countSV(dslop->lop[index]->dssinhvien);
XM:        	systemCls();
        	gotoxy(4,5);printf("%s %s","Ten Lop:",dslop->lop[index]->tenlop);
        	gotoxy(4,6);printf("%s %s","Ma Lop:",dslop->lop[index]->malop);
		    indexOfMon = bangMonThi(dsmon);
	        if(indexOfMon==-1)goto XL;
		    strcpy(mon.mamh,dsmon->mon[indexOfMon]->mamh);
		    strcpy(mon.tenmh,dsmon->mon[indexOfMon]->tenmh);
		    systemCls();	
XD:			indexOfSV = DSSVShowMark(dslop->lop[index]->dssinhvien,mon,page,arrow,slsv,start,dai,rong,col_right);
			if(indexOfSV!=-1){
				
				sv = getSVIndex(dslop->lop[index]->dssinhvien,indexOfSV);
				if(CheckExist_info_Diem(sv.dsdiem,mon.mamh)==true){
					systemCls();	
						status = showDetailExamOfStudentData(dscauhoi,sv,mon);	
						if(status==-2){
					    	char notice[MAX] = "Loi  du lieu!!! ";
		                    dialog(75,1,notice);
					    	goto XD;
						}
						if(status==-1){
					    	
					    	goto XD;
						}
					
						if(status==1){
							systemCls();
							goto XD;
						}
				}
				else {
				    	char notice[MAX] = "Sinh vien chua thi mon hoc nay!!! ";
	                    dialog(75,1,notice);
				    	goto XD;
					
				}
				
		    	
		    	
//				if(status==1&&CheckExist_info_Diem(sv.dsdiem,mon.mamh)==false){
//			    	char notice[MAX] = "Loi du lieu!!! ";
//                    dialog(75,1,notice);
//			    	goto XD;
//				}
				
					
			}
			
			goto XM;		
	    }
	    

	}
	 
}
