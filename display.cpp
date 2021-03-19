int menuDisplay() {
                       	   int x=70,y=20;
	   OBJECR_LCT diemxy;
	   diemxy.x = x-20;
	   diemxy.y = y-2;
 makeTable_Color_Type2(diemxy,18,60,187,187);
   while(true){
   	colorText(IDCOLOR_CLEARTEXT);
     gotoxy(x,y);printf("%s","Mon Hoc");
	 gotoxy(x,y+2);printf("%s","Lop Hoc");
	 gotoxy(x,y+4);printf("%s","Sinh Vien");
	 gotoxy(x,y+6);printf("%s","Nhap cau hoi");//In Diem Thi Trac Nghiem
	 gotoxy(x,y+8);printf("%s","Hieu Chinh Cau Hoi Thi");//Cau Hoi Thi
	 gotoxy(x,y+10);printf("%s","Thi Thu");
	 gotoxy(x,y+12);printf("%s","Xem Chi Tiet Bai Thi Cua Sinh Vien");
	 gotoxy(x,y+14);printf("%s","Xem Diem Thi Cua Mot Lop");
	 char c;
     int arrow = -1;
W:   if(kbhit()){
     	c = getch();
     	if(c==80){
     		arrow++;
     		if(arrow>7)arrow = 0;
     		if(arrow==0){
     			
     			gotoxy(x,y+14);printf("%s","Xem Diem Thi Cua Mot Lop");
     			colorText(160);
     			gotoxy(x,y);printf("%s","Mon Hoc");
     			colorText(IDCOLOR_CLEARTEXT);
			 }
			 if(arrow==1){
			 	
			 	gotoxy(x,y);printf("%s","Mon Hoc");
			 	colorText(160);
			 	gotoxy(x,y+2);printf("%s","Lop Hoc");
			 	colorText(IDCOLOR_CLEARTEXT);
			 }
			 if(arrow==2){
			 	
			 	gotoxy(x,y+2);printf("%s","Lop Hoc");
			 	colorText(160);
				gotoxy(x,y+4);printf("%s","Sinh Vien");
			 	colorText(IDCOLOR_CLEARTEXT);
			 }
			 if(arrow==3){
			 	
			 	gotoxy(x,y+4);printf("%s","Sinh Vien");
			 	colorText(160);
			 	gotoxy(x,y+6);printf("%s","Nhap cau hoi");
			 	colorText(IDCOLOR_CLEARTEXT);
			 }
			 if(arrow==4){
			    gotoxy(x,y+6);printf("%s","Nhap cau hoi");
			    colorText(160);
			    gotoxy(x,y+8);printf("%s","Hieu Chinh Cau Hoi Thi");
			    colorText(IDCOLOR_CLEARTEXT);
			 }
			 if(arrow==5){
			 	gotoxy(x,y+8);printf("%s","Hieu Chinh Cau Hoi Thi");
			 	colorText(160);
			 	gotoxy(x,y+10);printf("%s","Thi Thu");
			 	colorText(IDCOLOR_CLEARTEXT);
			 }
			 if(arrow==6){
			 	colorText(IDCOLOR_CLEARTEXT);
			 	gotoxy(x,y+10);printf("%s","Thi Thu");
			 	colorText(160);
			 	gotoxy(x,y+12);printf("%s","Xem Chi Tiet Bai Thi Cua Sinh Vien");
			 	colorText(IDCOLOR_CLEARTEXT);
			 }
			 if(arrow==7){
			 	colorText(IDCOLOR_CLEARTEXT);
			 	gotoxy(x,y+12);printf("%s","Xem Chi Tiet Bai Thi Cua Sinh Vien");
			 	colorText(160);
			 	gotoxy(x,y+14);printf("%s","Xem Diem Thi Cua Mot Lop");
			 	colorText(IDCOLOR_CLEARTEXT);
			 }
		 }
     	if(c==72){
     		arrow--;
			if(arrow<0)arrow = 7;
     		
     		if(arrow==0){
     			
     			gotoxy(x,y+2);printf("%s","Lop Hoc");
     			colorText(160);
     			gotoxy(x,y);printf("%s","Mon Hoc");
     			colorText(IDCOLOR_CLEARTEXT);
			 }
			 if(arrow==1){
			 	
			 	gotoxy(x,y+4);printf("%s","Sinh Vien");
			 	colorText(160);
			 	gotoxy(x,y+2);printf("%s","Lop Hoc");
			 	colorText(IDCOLOR_CLEARTEXT);
			 }
			 if(arrow==2){
			 	
			 	gotoxy(x,y+6);printf("%s","Nhap cau hoi");
			 	colorText(160);
				gotoxy(x,y+4);printf("%s","Sinh Vien");
			 	colorText(IDCOLOR_CLEARTEXT);
			 }
			 if(arrow==3){
			 	
			 	gotoxy(x,y+8);printf("%s","Hieu Chinh Cau Hoi Thi");
			 	colorText(160);
			 	gotoxy(x,y+6);printf("%s","Nhap cau hoi");
			 	colorText(IDCOLOR_CLEARTEXT);
			 }
			 if(arrow==4){
			 	gotoxy(x,y+10);printf("%s","Thi Thu");
			 	colorText(160);
			 	gotoxy(x,y+8);printf("%s","Hieu Chinh Cau Hoi Thi");
			 	colorText(IDCOLOR_CLEARTEXT);
			 }
			 if(arrow==5){
			 	gotoxy(x,y+12);printf("%s","Xem Chi Tiet Bai Thi Cua Sinh Vien");
			 	colorText(160);
			 	gotoxy(x,y+10);printf("%s","Thi Thu");
			 	colorText(IDCOLOR_CLEARTEXT);
			 }
			 if(arrow==6){
			 	colorText(IDCOLOR_CLEARTEXT);
			 	gotoxy(x,y+14);printf("%s","Xem Diem Thi Cua Mot Lop");
			 	colorText(160);
			 	gotoxy(x,y+12);printf("%s","Xem Chi Tiet Bai Thi Cua Sinh Vien");
			 	colorText(IDCOLOR_CLEARTEXT);
			 }
			 if(arrow==7){
			 	colorText(IDCOLOR_CLEARTEXT);
			 	gotoxy(x,y);printf("%s","Mon Hoc");
			 	colorText(160);
			 	gotoxy(x,y+14);printf("%s","Xem Diem Thi Cua Mot Lop");
			 	colorText(IDCOLOR_CLEARTEXT);
			 }
        }
     
     	if(c==27){
     		return -1;
     	
		 }
		 if(c==13 &&arrow!=-1){
		     changeScene_type1(IDCOLOR_BACKGROUND);//238
		 	return arrow;
		 }
     	
	 }goto W;
                       
     
    }
}
int menuDisplayQuanLySinhVien() {
	systemCls();
    int x=70,y=20;
	OBJECR_LCT diemxy;
	diemxy.x = x-20;
	diemxy.y = y-2;
	makeTable_Color_Type2(diemxy,10,60,187,187);
	while(true){
		colorText(IDCOLOR_CLEARTEXT);
	    gotoxy(x,y);printf("Them Sinh Vien");
		gotoxy(x,y+2);printf("Xoa Sinh Vien");
		gotoxy(x,y+4);printf("Sua Thong Tin Sinh Vien");
		gotoxy(x,y+6);printf("Tim Kiem Sinh Vien");
		char c;
	    int arrow = -1;
W:		if(kbhit()){
			c=getch();
			if(c==80){
				arrow++;
				if(arrow>3) arrow=0;
				if(arrow==0){
					gotoxy(x,y+6);printf("Tim Kiem Sinh Vien");
					colorText(160);
	    			gotoxy(x,y);printf("Them Sinh Vien");
	                colorText(IDCOLOR_CLEARTEXT);
				}
				if(arrow==1){
					gotoxy(x,y);printf("Them Sinh Vien");
					colorText(160);
					gotoxy(x,y+2);printf("Xoa Sinh Vien");
					whiteColor();colorText(IDCOLOR_CLEARTEXT);
				}
				if(arrow==2){
					gotoxy(x,y+2);printf("Xoa Sinh Vien");
					colorText(160);
					gotoxy(x,y+4);printf("Sua Thong Tin Sinh Vien");
					whiteColor();colorText(IDCOLOR_CLEARTEXT);
				}
				if(arrow==3){
					gotoxy(x,y+4);printf("Sua Thong Tin Sinh Vien");
					colorText(160);
					gotoxy(x,y+6);printf("Tim Kiem Sinh Vien");
					whiteColor();colorText(IDCOLOR_CLEARTEXT);
				}
			}
			if(c==72){
				arrow--;
				if(arrow<0) arrow=3;
				if(arrow==0){     			
	    			gotoxy(x,y+2);printf("Xoa Sinh Vien");
	    			colorText(160);
	    			gotoxy(x,y);printf("Them Sinh Vien");
	    			whiteColor();colorText(IDCOLOR_CLEARTEXT);
				}
				if(arrow==1){     			
	    			gotoxy(x,y+4);printf("Sua Thong Tin Sinh Vien");
	    			colorText(160);
	    			gotoxy(x,y+2);printf("Xoa Sinh Vien");
	    			whiteColor();colorText(IDCOLOR_CLEARTEXT);
				}
				if(arrow==2){     			
	    			gotoxy(x,y+6);printf("Tim Kiem Sinh Vien");
	    			colorText(160);
	    			gotoxy(x,y+4);printf("Sua Thong Tin Sinh Vien");
	    			whiteColor();colorText(IDCOLOR_CLEARTEXT);
				}
				if(arrow==3){     			
	    			gotoxy(x,y);printf("Them Sinh Vien");
	    			colorText(160);
	    			gotoxy(x,y+6);printf("Tim Kiem Sinh Vien");
	    			whiteColor();colorText(IDCOLOR_CLEARTEXT);
				}
			}
			if(c==27) return -1;
			if(c==13&&arrow!=-1){
				changeScene_type1(IDCOLOR_BACKGROUND);//238
				return arrow;
			}						
		} goto W;	    
	}          
}
int menuDisplayQuanLyCauHoi(){
    systemCls();
    int x=70,y=20;
	OBJECR_LCT diemxy;
	diemxy.x = x-18;
	diemxy.y = y-2;
	makeTable_Color_Type2(diemxy,10,60,187,187);
	while(true){
		colorText(IDCOLOR_CLEARTEXT);
	    gotoxy(x,y);printf("Nhap Cau Hoi");
		gotoxy(x,y+2);printf("Xoa Cau Hoi");
		gotoxy(x,y+4);printf("Chinh Sua Noi Dung Cau Hoi");		
		gotoxy(x,y+6);printf("In Danh Sach Cau Hoi Theo Mon");
		char c;
	    int arrow = -1;
W:		if(kbhit()){
			c=getch();
			if(c==80){
				arrow++;
				if(arrow>3) arrow=0;
				if(arrow==0){
					gotoxy(x,y+6);printf("In Danh Sach Cau Hoi Theo Mon");
					colorText(160);
	    			gotoxy(x,y);printf("Nhap Cau Hoi");
	                colorText(IDCOLOR_CLEARTEXT);
				}
				if(arrow==1){
					gotoxy(x,y);printf("Nhap Cau Hoi");
					colorText(160);
					gotoxy(x,y+2);printf("Xoa Cau Hoi");
					whiteColor();colorText(IDCOLOR_CLEARTEXT);
				}
				if(arrow==2){
					gotoxy(x,y+2);printf("Xoa Cau Hoi");
					colorText(160);
					gotoxy(x,y+4);printf("Chinh Sua Noi Dung Cau Hoi");
					whiteColor();colorText(IDCOLOR_CLEARTEXT);
				}
				if(arrow==3){
					gotoxy(x,y+4);printf("Chinh Sua Noi Dung Cau Hoi");
					colorText(160);
					gotoxy(x,y+6);printf("In Danh Sach Cau Hoi Theo Mon");
					whiteColor();colorText(IDCOLOR_CLEARTEXT);
				}
			}
			if(c==72){
				arrow--;
				if(arrow<0) arrow=3;
				if(arrow==0){     			
	    			gotoxy(x,y+2);printf("Xoa Cau Hoi");
	    			colorText(160);
	    			gotoxy(x,y);printf("Nhap Cau Hoi");
	    			whiteColor();colorText(IDCOLOR_CLEARTEXT);
				}
				if(arrow==1){     			
	    			gotoxy(x,y+4);printf("Chinh Sua Noi Dung Cau Hoi");
	    			colorText(160);
	    			gotoxy(x,y+2);printf("Xoa Cau Hoi");
	    			whiteColor();colorText(IDCOLOR_CLEARTEXT);
				}
				if(arrow==2){     			
	    			gotoxy(x,y+6);printf("In Danh Sach Cau Hoi Theo Mon");
	    			colorText(160);
	    			gotoxy(x,y+4);printf("Chinh Sua Noi Dung Cau Hoi");
	    			whiteColor();colorText(IDCOLOR_CLEARTEXT);
				}
				if(arrow==3){     			
	    			gotoxy(x,y);printf("Nhap Cau Hoi");
	    			colorText(160);
	    			gotoxy(x,y+6);printf("In Danh Sach Cau Hoi Theo Mon");
	    			whiteColor();colorText(IDCOLOR_CLEARTEXT);
				}
			}
			if(c==27) return -1;
			if(c==13&&arrow!=-1){
				changeScene_type1(IDCOLOR_BACKGROUND);//238
				return arrow;
			}						
		} goto W;	    
	}     
}
//int menuDisplayQuanLyLop() {
//                        systemCls();
//                         int x=70,y=20;
//	   OBJECR_LCT diemxy;
//	   diemxy.x = x-20;
//	   diemxy.y = y-2;
// makeTable_Color_Type2(diemxy,12,60,187,187);
//   while(true){
//   	colorText(IDCOLOR_CLEARTEXT);
//     gotoxy(x,y);printf("%s","Xem Lop Theo Nien Khoa");
//	 gotoxy(x,y+2);printf("%s","Them Lop Moi");
//	 gotoxy(x,y+4);printf("%s","Chinh Sua Thong Tin Lop Hoc");
//	 gotoxy(x,y+6);printf("%s","Xoa Lop Hoc");
//	 gotoxy(x,y+8);printf("%s","Tra Cuu Lop Hoc");
//	 char c;
//     int arrow = -1;
//W:   if(kbhit()){
//     	c = getch();
//     	if(c==80){
//     		arrow++;
//     		if(arrow>4)arrow = 0;
//     		if(arrow==0){
//     			
//     			gotoxy(x,y+8);printf("%s","Tra Cuu Lop Hoc");
//     			colorText(160);
//     			gotoxy(x,y);printf("%s","Xem Lop Theo Nien Khoa");
////     			whiteColor();
//                colorText(IDCOLOR_CLEARTEXT);
//			 }
//			 if(arrow==1){
//			 	
//			 	gotoxy(x,y);printf("%s","Xem Lop Theo Nien Khoa");
//			 	colorText(160);
//			 	gotoxy(x,y+2);printf("%s","Them Lop Moi");
//			 	whiteColor();colorText(IDCOLOR_CLEARTEXT);
//			 }
//			 if(arrow==2){
//			 	
//			 	gotoxy(x,y+2);printf("%s","Them Lop Moi");
//			 	colorText(160);
//				gotoxy(x,y+4);printf("%s","Chinh Sua Thong Tin Lop Hoc");
//			 	whiteColor();colorText(IDCOLOR_CLEARTEXT);
//			 }
//			 if(arrow==3){
//			 	
//			 	gotoxy(x,y+4);printf("%s","Chinh Sua Thong Tin Lop Hoc");
//			 	colorText(160);
//			 	gotoxy(x,y+6);printf("%s","Xoa Lop Hoc");
//			 	whiteColor();colorText(IDCOLOR_CLEARTEXT);
//			 }
//			 if(arrow==4){
//			 	gotoxy(x,y+6);printf("%s","Xoa Lop Hoc");
//			 	colorText(160);
//			 	gotoxy(x,y+8);printf("%s","Tra Cuu Lop Hoc");
//			 	whiteColor();colorText(IDCOLOR_CLEARTEXT);
//			 }
//		 }
//     	if(c==72){
//     		arrow--;
//			if(arrow<0)arrow = 4;
//     		
//     		if(arrow==0){
//     			
//     			gotoxy(x,y+2);printf("%s","Them Lop Moi");
//     			colorText(160);
//     			gotoxy(x,y);printf("%s","Xem Lop Theo Nien Khoa");
//     			whiteColor();colorText(IDCOLOR_CLEARTEXT);
//			 }
//			 if(arrow==1){
//			 	
//			 	gotoxy(x,y+4);printf("%s","Chinh Sua Thong Tin Lop Hoc");
//			 	colorText(160);
//			 	gotoxy(x,y+2);printf("%s","Them Lop Moi");
//			 	whiteColor();colorText(IDCOLOR_CLEARTEXT);
//			 }
//			 if(arrow==2){
//			 	
//			 	gotoxy(x,y+6);printf("%s","Xoa Lop Hoc");
//			 	colorText(160);
//				gotoxy(x,y+4);printf("%s","Chinh Sua Thong Tin Lop Hoc");
//			 	whiteColor();colorText(IDCOLOR_CLEARTEXT);
//			 }
//			 if(arrow==3){
//			 	
//			 	gotoxy(x,y+8);printf("%s","Tra Cuu Lop Hoc");
//			 	colorText(160);
//			 	gotoxy(x,y+6);printf("%s","Xoa Lop Hoc");
//			 	whiteColor();colorText(IDCOLOR_CLEARTEXT);
//			 }
//			 if(arrow==4){
//			 	 gotoxy(x,y);printf("%s","Xem Lop Theo Nien Khoa");
//				colorText(160);
//				gotoxy(x,y+8);printf("%s","Tra Cuu Lop Hoc");
//				whiteColor();colorText(IDCOLOR_CLEARTEXT);
//			 }
//			 
//        }
//     
//     	if(c==27){
//     		
//     		return -1;
//		 }
//		if(c==13 &&arrow!=-1){
//		     changeScene_type1(IDCOLOR_BACKGROUND);//238
//		 	return arrow;
//		 
//			 
//		 }
//     	
//	 }goto W;
//	 
//   }       
//} 
int menuDisplayQuanLyLop() {
                        systemCls();
                         int x=70,y=20;
	   OBJECR_LCT diemxy;
	   diemxy.x = x-20;
	   diemxy.y = y-2;
 makeTable_Color_Type2(diemxy,12,60,187,187);
   while(true){
   	colorText(IDCOLOR_CLEARTEXT);
     gotoxy(x,y+4);printf("%s","Xem Lop Theo Nien Khoa");
	 gotoxy(x,y+2);printf("%s","Danh sach lop");
	 char c;
     int arrow = -1;
W:   if(kbhit()){
     	c = getch();
     	if(c==80){
     		arrow++;
     		if(arrow>1)arrow = 0;
     		if(arrow==0){
     			gotoxy(x,y+2);printf("%s","Danh sach lop");
     			colorText(160);
     			gotoxy(x,y+4);printf("%s","Xem Lop Theo Nien Khoa");
//     			whiteColor();
                colorText(IDCOLOR_CLEARTEXT);
			 }
			 if(arrow==1){
			 	
			 	gotoxy(x,y+4);printf("%s","Xem Lop Theo Nien Khoa");
			 	colorText(160);
			 	gotoxy(x,y+2);printf("%s","Danh sach lop");
			 	whiteColor();colorText(IDCOLOR_CLEARTEXT);
			 }
		 }
     	if(c==72){
     		arrow--;
			if(arrow<0)arrow = 1;
     		
     		if(arrow==0){
     			
     			gotoxy(x,y+2);printf("%s","Danh sach lop");
     			colorText(160);
     			gotoxy(x,y+4);printf("%s","Xem Lop Theo Nien Khoa");
     			whiteColor();colorText(IDCOLOR_CLEARTEXT);
			 }
			 if(arrow==1){
			 	
			 	gotoxy(x,y+4);printf("%s","Xem Lop Theo Nien Khoa");
			 	colorText(160);
			 	gotoxy(x,y+2);printf("%s","Danh sach lop");
			 	whiteColor();colorText(IDCOLOR_CLEARTEXT);
			 }
        }
     
     	if(c==27){
     		
     		return -1;
		 }
		if(c==13 &&arrow!=-1){
		     changeScene_type1(IDCOLOR_BACKGROUND);//238
		 	return arrow;
		 
			 
		 }
     	
	 }goto W;
	 
   }       
     
     
} 
int menuDisplayQuanLyMonHoc() {
                        systemCls();
                        int x=70,y=20;
	   OBJECR_LCT diemxy;
	   diemxy.x = x-20;
	   diemxy.y = y-2;
 makeTable_Color_Type2(diemxy,12,60,187,187);
   while(true){
   	colorText(IDCOLOR_CLEARTEXT);
     gotoxy(x,y);printf("%s","Xem Chi Tiet Mon Hoc");
	 gotoxy(x,y+2);printf("%s","Them mon hoc");
	 gotoxy(x,y+4);printf("%s","Chinh sua mon hoc");
	 gotoxy(x,y+6);printf("%s","Xoa mon hoc");
	 gotoxy(x,y+8);printf("%s","Tra Cuu Mon Hoc");
	 char c;
     int arrow = -1;
W:   if(kbhit()){
     	c = getch();
     	if(c==80){
     		arrow++;
     		if(arrow>4)arrow = 0;
     		if(arrow==0){
     			
     			gotoxy(x,y+8);printf("%s","Tra Cuu Mon Hoc");
     			colorText(160);
     			gotoxy(x,y);printf("%s","Xem Chi Tiet Mon Hoc");
//     			whiteColor();
                colorText(IDCOLOR_CLEARTEXT);
			 }
			 if(arrow==1){
			 	
			 	gotoxy(x,y);printf("%s","Xem Chi Tiet Mon Hoc");
			 	colorText(160);
			 	gotoxy(x,y+2);printf("%s","Them mon hoc");
			 	whiteColor();colorText(IDCOLOR_CLEARTEXT);
			 }
			 if(arrow==2){
			 	
			 	gotoxy(x,y+2);printf("%s","Them mon hoc");
			 	colorText(160);
				gotoxy(x,y+4);printf("%s","Chinh sua mon hoc");
			 	whiteColor();colorText(IDCOLOR_CLEARTEXT);
			 }
			 if(arrow==3){
			 	
			 	gotoxy(x,y+4);printf("%s","Chinh sua mon hoc");
			 	colorText(160);
			 	gotoxy(x,y+6);printf("%s","Xoa mon hoc");
			 	whiteColor();colorText(IDCOLOR_CLEARTEXT);
			 }
			 if(arrow==4){
			 	gotoxy(x,y+6);printf("%s","Xoa mon hoc");
			 	colorText(160);
			 	gotoxy(x,y+8);printf("%s","Tra Cuu Mon Hoc");
			 	whiteColor();colorText(IDCOLOR_CLEARTEXT);
			 }
		 }
     	if(c==72){
     		arrow--;
			if(arrow<0)arrow = 4;
     		
     		if(arrow==0){
     			
     			gotoxy(x,y+2);printf("%s","Them mon hoc");
     			colorText(160);
     			gotoxy(x,y);printf("%s","Xem Chi Tiet Mon Hoc");
     			whiteColor();colorText(IDCOLOR_CLEARTEXT);
			 }
			 if(arrow==1){
			 	
			 	gotoxy(x,y+4);printf("%s","Chinh sua mon hoc");
			 	colorText(160);
			 	gotoxy(x,y+2);printf("%s","Them mon hoc");
			 	whiteColor();colorText(IDCOLOR_CLEARTEXT);
			 }
			 if(arrow==2){
			 	
			 	gotoxy(x,y+6);printf("%s","Xoa mon hoc");
			 	colorText(160);
				gotoxy(x,y+4);printf("%s","Chinh sua mon hoc");
			 	whiteColor();colorText(IDCOLOR_CLEARTEXT);
			 }
			 if(arrow==3){
			 	
			 	gotoxy(x,y+8);printf("%s","Tra Cuu Mon Hoc");
			 	colorText(160);
			 	gotoxy(x,y+6);printf("%s","Xoa mon hoc");
			 	whiteColor();colorText(IDCOLOR_CLEARTEXT);
			 }
			 if(arrow==4){
			 	 gotoxy(x,y);printf("%s","Xem Chi Tiet Mon Hoc");
				colorText(160);
				gotoxy(x,y+8);printf("%s","Tra Cuu Mon Hoc");
				whiteColor();colorText(IDCOLOR_CLEARTEXT);
			 }
			 
        }
     
     	if(c==27){
     		
     		return -1;
		 }
		if(c==13 &&arrow!=-1){
		     changeScene_type1(IDCOLOR_BACKGROUND);//238
		 	return arrow;
		 }
		 	
     	
	 }goto W;
	 
   }
     
     } 
//---------------------------------------- menu
int menuQuanLyLop(DSLOP *dslop) {
   int choise; 
 MENU:    
         choise = menuDisplayQuanLyLop();
                        
          
                
                  
                                                                       //nhan insert
                                                      
                                                      switch(choise) {
                                                                           case 1:{
                                                                           			//nhap lop
                                                                                     Input_Class(dslop);
                                                                                     goto MENU;
                                                                                
                                                                                }
                                                                            case 0:{//tra cuu
                                                                                     inDSLop(dslop);
                                                                                     goto MENU;
                                                                                
                                                                            }
                                                                            case -1:{
																				break;
																			}
                                                      }
                                      
                           
                                    
                                                    
                       
 return 1;            
        
     
     
 }
 int menuQuanLyMonHoc(DSMON *dsmon) {
    int choise;
 MENU:   systemCls(); 
         choise = menuDisplayQuanLyMonHoc();
                        
          
                                                      switch(choise) {
                                                                           case 1:{
                                                                                    //Xu ly Them Mon Hoc 
                                                                                     goto MENU;
                                                                                
                                                                                }
                                                                           case 3:{
                                                                                    //Xu ly Xoa Mon Hoc
                                                                                     goto MENU;
                                                                                
                                                                                }
                                                                           case 2:{
                                                                                    //Xu ly  Hieu chinh Mon  Hoc
                                                                                     goto MENU;
                                                                                
                                                                            }
                                                                            case 0:{
                                                                            	//xem danh sach mon
																				break;
																			}
																			case 4:{
																				//tra cuu
																				break;
																			}
																			case -1:{
																				break;
																			}
                                                      }
                                                            
 return 1;            
        
     
     
 }

int menuQuanLySinhVien(DSLOP *dslop){
	int choice;
MENU:
	systemCls();
	choice = menuDisplayQuanLySinhVien();
	switch(choice){
		case 0:{
			Input_SV(dslop);
			goto MENU;
		}
		case 1:{
//			Delete_SV(dslop);
			goto MENU;
		}
		case 2:{
//			Edit_SV(dslop);
			goto MENU;
		}
		case 3:{
//			Search_SV(dslop);
			goto MENU;
		}
		default: break;
	}
	return 1;
}

int menuQuanLyCauHoi(NODECAUHOI dscauhoi, DSMON *dsmon){
	int choice;
MENU:
	systemCls();
	choice = menuDisplayQuanLyCauHoi();
	switch(choice){
		case 0:{
			Input_CH(dscauhoi,dsmon);
			goto MENU;
		}
		case 1:{
//			Delete_CH(dscauhoi,dsmon);
			goto MENU;
		}
		case 2:{
//			Edit_CH(dscauhoi,dsmon);
			goto MENU;
		}
		case 3:{
//			Search_CH(dscauhoi,dsmon);
			goto MENU;
		}
		default: break;
	}
	return 1;
}

int loginDisplay() {
        short int x=100;
        short int y=26;
        char username[] = ""; 
        char password[] = "";  
        systemCls();           
        gotoxy(x,y);
        printf("Nhap username: ");
        gotoxy(x,y+1);
        printf("Nhap password: ");
        gotoxy(x+15,y);
        scanf("%s",&username);//fflush(stdin);
        gotoxy(x+15,y+27);//fflush(stdin);
        scanf("%s",&password);
        return 1;//login thanh cong
     }

int menu(DSLOP *dslop,DSMON *dsmon,NODECAUHOI dscauhoi) {		

MENU:   systemCls(); 
        
        int choise; 
        choise = menuDisplay();
        gotoxy(70+10,20+11);               
                        
		if(choise==0){
			//menuQuanLyMonHoc(dsmon);
			Input_Mon(dsmon);
            goto MENU;
		}
    	if(choise==1){
    		menuQuanLyLop(dslop);
            goto MENU;
		}
		if(choise==2){
//			menuQuanLySinhVien(dslop);
            Input_SV(dslop);
			goto MENU;
		}		
		if(choise==3){
			//xu ly in diem thi trac nghiem
			Input_CH(dscauhoi,dsmon);
			goto MENU;
		}
		if(choise==4){
//			systemCls();
			showDSMon(dsmon,dscauhoi);
//			menuQuanLyCauHoi(dscauhoi,dsmon);
			goto MENU;
		}
    	if(choise==5){
    		int index;
    		char notice[MAX] = " ";
      	    userManual_DoExam();
            THITIEP:
 	                ACCOUNT account;
 	                strcpy(account.tenDangNhap,"GV");
 	                strcpy(account.password,"GV");
					systemCls(); 
      	    SM:     index = bangMonThi(dsmon);
      	            if(index<0){
      	            	display_GoodBye();
						goto MENU;      
      	            	
		            }
					if(ExistQuestion(dscauhoi,dsmon->mon[index]->mamh)==false){
				    	strcpy(notice,"Mon nay hien tai chua co cau hoi thi.Vui long chon lai mon thi!!!");
				    	dialog(85,0,notice);
				    	goto SM;
					}
      	            
		            else {
		  	
		                MON monThi;
		                strcpy(monThi.tenmh,dsmon->mon[index]->tenmh);
					    strcpy(monThi.mamh,dsmon->mon[index]->mamh);
					
			      	    moduleThiForTeacher(dslop,dscauhoi,"GV","GV","GV",monThi);
            			goto THITIEP;
		           }
            	   goto MENU;
		}
		if(choise==6){
			moduleDetailExam(dscauhoi,dsmon,dslop);
			goto MENU;
		}
		if(choise==7){
			showMarkOfClass(dslop,dsmon,dscauhoi);
			goto MENU;
		}
		else{
			Sleep(1000);
            systemCls();
            return 1;
		} 		                                           
}
                        
void displayModuleDetailExam(int x,int y){
		
	gotoxy(75,3);colorText(228);
	printf("%s","XEM CHI TIET THI CUA SINH VIEN ");clearColor();
	
	SINHVIEN sv; 
	NODESINHVIEN First;  InitDSSV(First);
	
	OBJECR_LCT diemxy;
	diemxy.x = x+3+15+3;
    diemxy.y = y+3;
    makeTable_Color_Type2(diemxy,2,MAXDN+2,119,119);
	colorText(IDCOLOR_CLEARTEXT);
	gotoxy(x+3,y+4);printf("%s","Nhap ma sinh vien:");
}
                        
                        

                        
                
        
       
    

