void GdMonThi(){//(255 250 205)
	colorText(224);
	
	gotoxy(xIn+20,42);
	printf("UP");
	colorText(224);gotoxy(xIn+12,44);printf("LEFT");
	colorText(224);gotoxy(xIn+26,44);printf("RIGHT");
	colorText(224);gotoxy(xIn+19,46);
	printf("DOWN");
	
	gotoxy(xIn,48);
	printf("ESC:EXIT 	Enter:Chon ");
	displayOuputDSMon(75,5);
	gotoxy(xGd-20,yGd+3);
	printf("MA MON");
	gotoxy(xGd+5,yGd+3);
	printf("TEN MON");

}
int inMonThi(int tick, DSMON *dsmon,int arrow){

	int count =0; char c;
	int j=0;
    int i=0;
    GdMonThi();
    int vitri=0; //chi dung lam tang them 1 hang trong
RP:    if( ( (tick*20) - (dsmon->n) ) > 20 ){
	        tick--;
			goto RP; 
		}
	else {
//		clearPartOfScreen(xGd-23,yGd+5,xGd+38+10,yGd+5+38);//xoa 1 vung in ds
		//sap xep
		sapXepMon(dsmon);
		//in trang
		for(i=0;i<dsmon->n;i++){
				if(i % 20 == 0) j ++;
			if(j == tick){
				if(count==arrow){
					
					colorText(91);
					gotoxy(xGd-20,yGd+5+vitri);
		            printf("%s",dsmon->mon[i]->mamh);
		            gotoxy(xGd-5,yGd+5+vitri);
			        printf("%s\n",dsmon->mon[i]->tenmh);
			        clearColor();
				}
				else {
					gotoxy(xGd-20,yGd+5+vitri);
		            printf("%s",dsmon->mon[i]->mamh);
		            gotoxy(xGd-5,yGd+5+vitri);
			        printf("%s\n",dsmon->mon[i]->tenmh);
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
int  bangMonThi(DSMON *dsmon){
	system("cls");
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
           return (19+(tick-1)*20-(19-arrow));
		}
		if(c==27){
			return -1;
		}
    	
	}goto W;
}







strcpy(mSV,dslop->lop[k]->dssinhvien->sinhvien.masv);
