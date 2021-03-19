#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<cstdlib>

SINHVIEN searchStudentByMaSV(DSLOP *dslop,char masv_tmp[MAXMSV]){
	SINHVIEN sv;
	strcpy(sv.ho,"NONE");
	for(int i=0;i<dslop->n;i++){
		for(NODESINHVIEN p=dslop->lop[i]->dssinhvien;p!=NULL;p=p->next){
			if(stricmp(p->sinhvien.masv,masv_tmp)==0){

                sv = p->sinhvien;
                
                return sv;
			}
			
		}
							
	}
	return sv;
}
bool Empty_Diem(NODEDIEM &First)
{
   if(First == NULL)return true;
   
   return false;
}

void Insert_First_Diem(NODEDIEM &First, DIEM x)
{
   NODEDIEM p;
   p = new nodediem;
   p->diemthi = x;
   p->next = First;
   First = p;
   First->next = NULL;
   
}

void Insert_after(NODEDIEM &p, DIEM x)
{
   NODEDIEM q;
   if(p == NULL)
		printf("khong them phan tu vao danh sach duoc");
   else
   { q =(NODEDIEM)malloc(sizeof(nodediem));
      q->diemthi = x;
      q->next = p->next;
      p->next = q;
   }
}

void Traverse_Diem(NODEDIEM &First)
{ NODEDIEM p;
   int stt = 0;
   
   if(p == NULL)
      printf("\n   (Khong co phan tu trong danh sach)");
   for (p = First ; p != NULL; p=p->next){
   	   printf("%s %.1f\n",p->diemthi.mamh,p->diemthi.diem);
   	   
   }
      
    
}

bool CheckExist_info_Diem(NODEDIEM &First, char mamh[MAXMMH])
{  NODEDIEM p = new nodediem;
    
	for (p = First;  p   != NULL  ; p=p->next ) 
               if ( stricmp(p->diemthi.mamh,mamh)==0  ){
               	
               	return true;
			   }
	 return false;
}
DIEM getDiemFromStudent(NODEDIEM &First, char mamh[MAXMMH])
{  NODEDIEM p = new nodediem;
    p = NULL;
	for (p = First;  p   != NULL  ; p=p->next ) 
               if ( stricmp(p->diemthi.mamh,mamh)==0  ){
               	
               	return p->diemthi;
			   }
	 
}
int countSLMDaThi(NODEDIEM &First){
	NODEDIEM p = new nodediem;
	p = First;
   int stt = 0;
   
   if(p == NULL)
      return stt;
   for (p = First ; p != NULL; p=p->next){
   	   stt++;
   	   
   }
   return stt;
}
void updateNODESINHVIEN(DSLOP *dslop,int index,NODESINHVIEN &oldNode,NODESINHVIEN &newNode){
 
    NODESINHVIEN p = new nodesinhvien;
    SINHVIEN temp;
	p = dslop->lop[index]->dssinhvien;

	dslop->lop[index]->dssinhvien = NULL;
   
	bool first = true;
	if(p==NULL){
		printf("DSSV rong!");
	}else{
		int count=0;
		while(p!=NULL){		
			if(stricmp(p->sinhvien.masv,oldNode->sinhvien.masv)==0){

				temp = newNode->sinhvien;
				p=p->next;
				if(first==true){
					Insert_First_SV(dslop->lop[index]->dssinhvien,temp); 
				}
				else {
					first = false;
					Insert_After_SV(dslop->lop[index]->dssinhvien,temp);
				}

			}
			else {
			    temp = p->sinhvien;
				p=p->next;
				if(first==true){
					Insert_First_SV(dslop->lop[index]->dssinhvien,temp); 
				}
				else {
					first = false;
					Insert_After_SV(dslop->lop[index]->dssinhvien,temp);
				}

			}
			
			
		}
	}
   
	
	
}
void Search_info_Diem(NODEDIEM &First, char mamh[MAXMMH])
{  NODEDIEM p = new nodediem;

	for (p = First;  p   != NULL ; p=p->next ){
		if ( strcmp(p->diemthi.mamh,mamh)==0  ){
               	    printf("%s %.1f\n",p->diemthi.mamh,p->diemthi.diem);	
               	
			   }//system("pause");
	} 
               
	 	printf("%s %d","so mon da thi:",countSLMDaThi(First));
}

SINHVIEN getSVIndex(NODESINHVIEN p, int arrow){
	int i=0;
	while(p!=NULL&&i<=arrow){
		if(i==arrow){
			return p->sinhvien;
		}
		i++; p=p->next;
	}
}


CAUHOI SearchTree (NODECAUHOI root, int id)
{
   NODECAUHOI p;
   p = root;
   while (p != NULL && p->cauhoi.id !=id)
    if(id < p->cauhoi.id)
         p = p->left;
      else
         p = p->right;

return(p->cauhoi); 
}


void timer(int *time,int *second)
{   

	bool reCall = true;
    bool reFN = false;
	clearPartOfScreen(145,5,160,5);
	gotoxy(145,5);
	printf("%d %s %d",*time,":",*second);
	if((*second)==0){
	   (*second)= 59;
	   (*time)--;
	   reFN = true;
    }
	
	while(*time >= 0 && !kbhit())
	{   reCall = false;
		if(reCall==false &&(*second) == 59 &&reFN==true){
			//(*second) = 60;
			if(*(time)<2){
				gotoxy(0,0);Sleep(969-100);
			    clearPartOfScreen(145,5,160,5);Sleep(100);
				gotoxy(145,5);colorText(228);
				printf("%d %s %d",*time,":",*second);//Sleep(969-100);
			}
			else {
				gotoxy(0,0);
			    Sleep(969);
				 
			    clearPartOfScreen(145,5,160,5);
			    gotoxy(145,5);
				printf("%d %s %d",*time,":",*second);
			}
			
			reFN = false;

		}
		else {
			if(*(time)>=2){
				gotoxy(0,0);
				(*second)--;
				gotoxy(0,0);
			    Sleep(969); 
			    clearPartOfScreen(145,5,160,5);
			    gotoxy(145,5);
				printf("%d %s %d",*time,":",*second);
			}
			else {
				gotoxy(0,0);
				(*second)--;
				gotoxy(0,0);
			    clearPartOfScreen(145,5,160,5);Sleep(100);
				gotoxy(145,5);colorText(228);
				printf("%d %s %d",*time,":",*second);Sleep(969-100);
			}
//			gotoxy(0,0);
//		    Sleep(969);
//		    (*second)--;
//		    clearPartOfScreen(145,5,160,5);
//		    gotoxy(145,5);
//			printf("%d %s %d",*time,":",*second);
		}
	
		if(*second==0)
		{
			
			(*time)--;
			*(second)=59;
			reFN = true;
		}
		
	}
}

void timerRunningOut(int *time,int *second)
{   bool reCall = true;
    bool reFN = false;
    
	clearPartOfScreen(145,5,160,5);
	gotoxy(145,5);colorText(228);
	printf("%d %s %d",*time,":",*second);
    Sleep(969-100);
	if((*second)==0){
		   (*second)= 59;
		   (*time)--;
		   reFN = true;
	    }
	
	while(*time >= 0 && !kbhit())
	{   reCall = false;
		
		if(reCall==false &&(*second) == 59 &&reFN==true){
			gotoxy(0,0);
		    clearPartOfScreen(145,5,160,5);Sleep(100);
			gotoxy(145,5);colorText(228);
			printf("%d %s %d",*time,":",*second);Sleep(969-100);
            reFN = false;

		}
		else {
			gotoxy(0,0);
		    (*second)--;
		    clearPartOfScreen(145,5,160,5);Sleep(100);
			gotoxy(145,5);colorText(228);
			printf("%d %s %d",*time,":",*second);Sleep(969-100);

		}
	
		if(*second==0)
		{
			(*time)--;
			*(second)=59;
			reFN = true;
		}
		
	}
	clearColor();
}

void backSpace(int x,int y){
     gotoxy(x,y);
     printf("%s"," ");
     
     }
     
void del(char *a, int vitri){
    int n = strlen(a);
    for (int i=vitri; i<n; i++){
        a[i] = a[i + 1];
    }
    n--;
}

void delspace(char *a){
    int n=strlen(a);
    for (int i = 0; i < n; i++){
        if (a[0] == 32){
           del(a, 0);
            n--;
        }
        if (a[n-1] == 32){
            del(a, n-1);
            n--;
        }
        if (a[i] == 32 && a[i + 1] == 32){
            del(a, i);
            i--;
            n--;
        }
    }
}

void uppercase(char *a){
	for(int i=0; i< strlen(a); i++){
		if(a[i]>=97&&a[i]<=122){
			a[i]=a[i]-32;
		}
	}
}

char upper_an_char(char a){
	if(a>=97&&a<=122) {a=(int)a-32; return a;}	
	return a;
}

void upper_first_char(char *a){
	if(a[0]>=97&&a[0]<=122){
		a[0]=a[0]-32;
	}
}

void uppername(char *a){ //vO pHi hung -> Vo Phi Hung
	char *tmp =a;        
    for(int i=0;i<strlen(a);i++){ 
		if(i==0){
			if (tmp[0]>97&&tmp[0]<122){
	            tmp[0]=tmp[0]-32;
	            a[0]=tmp[0];
	        } 
		}else{
			if (tmp[i] == 32){
	            if(tmp[i+1]>97&&tmp[i+1]<122){
	            	tmp[i+1]=tmp[i+1]-32;
	            	a[i+1]=tmp[i+1];
				}
	        }else{
	        	if (tmp[i]>65&&tmp[i]<90){
		            tmp[i]=tmp[i]+32;
		            a[i]=tmp[i];
	       		}	
			}
		}
	}
}
//---------
//-----------------------------------CAC HAM BAT LOI

//sap xep lop theo ma
void sapXepLop(DSLOP *dslop){
	LOP *lop;
	for(int i=0;i<dslop->n-1;i++) {
		for(int j=dslop->n-1;j>i;j--){
			if(stricmp(dslop->lop[j]->malop,dslop->lop[j-1]->malop)<0){//sap xep ma theo alphabet
				lop = dslop->lop[j];
				dslop->lop[j]=dslop->lop[j-1];
				dslop->lop[j-1]=lop;
			}
		}
	}
}

//sap xep mon theo ma
void sapXepMon(DSMON *dsmon){
	MON *mon;
	for(int i=0;i<dsmon->n-1;i++) {
		for(int j=dsmon->n-1;j>i;j--){
			if(stricmp(dsmon->mon[j]->mamh,dsmon->mon[j-1]->mamh)<0){//sap xep ma theo alphabet
				mon = dsmon->mon[j];
				dsmon->mon[j]=dsmon->mon[j-1];
				dsmon->mon[j-1]=mon;
			}
		}
	}
}

//xoa 1 vung man hinh nhu khong khoa dong ho
void clearPartOfScreenButNoClockUB(int x,int y,int endX,int endY){
 	//xoa ben trai
    int l = y;
    while(l<=endY){
    	gotoxy(0,l);
    	for(int i=0;i<x;i++)printf("%c",' ');
    	l++;
	}
		 
 	//xoa phia tren
 int o = 0;
    while(o<y){
    	gotoxy(0,o);
    	for(int i=0;i<180;i++)printf("%c",' ');
    	o++;
	}
 	//xoa ben phai
 int r = y;
    while(r<=endY){
    	gotoxy(endX,r);
    	for(int i=endX+1;i<180;i++)printf("%c",' ');
    	r++;
	}
 	//xoa phia duoi
 int b = endY+1;
    while(b<=50){
    	gotoxy(0,b);
    	for(int i=0;i<180;i++)printf("%c",' ');
    	b++;
	}	 
}
 
//hàm dung màn hình seconds giây
void wait ( int seconds ){
	  clock_t endwait;
	  endwait = clock () + seconds * CLOCKS_PER_SEC ;
	  while (clock() < endwait) {}
}

//ham xoa mot vung trong man hinh theo mau cua background
void clearPartOfScreen(int x,int y,int endX,int endY){
      colorText(IDCOLOR_BACKGROUND);
	  for(int i=x;i<=endX;i++)
              for(int j=y;j<=endY;j++){gotoxy(i,j);printf("%c",' ');}
      colorText(224);
     
     }

//ham chuyen chuoi nhap thanh viet hoa chu cai Dau
void vietHoaChuCaiDau(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;
        if (str[i - 1] == ' ' || i == 0)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
                str[i] = str[i] - 32;
        }
    }
}

//ham tim vi tri xoa trong ds lop
void timViTriXL(DSLOP *ds, int vitri){//xac dinh vi tri
		// Mang rong, khong the xoa.
    if (ds->n <= 0)
    {
        return;
    }
    // Neu pos <= 0 => Xoa dau
    if (vitri < 0)
    {
        vitri = 0;
    }
    // Neu pos >= n => Xoa cuoi
    else if (vitri >= ds->n)
    {
        vitri = ds->n - 1;
    }
    // Dich chuyen mang
    for (int i = vitri  ; i < ds->n - 1; i++)
    {
        ds->lop[i] = ds->lop[i+1];
    }
    // Giam so luong phan tu sau khi xoa.
    --ds->n;
}

//tim vi tri xoa trong ds mon
void timViTriXM(DSMON *ds, int vitri){//xac dinh vi tri
		// Mang rong, khong the xoa.
    if (ds->n <= 0)
    {
        return;
    }
    // Neu pos <= 0 => Xoa dau
    if (vitri < 0)
    {
        vitri = 0;
    }
    // Neu pos >= n => Xoa cuoi
    else if (vitri >= ds->n)
    {
        vitri = ds->n - 1;
    }
    // Dich chuyen mang
    for (int i = vitri  ; i < ds->n - 1; i++)
    {
        ds->mon[i] = ds->mon[i+1];
    }
    // Giam so luong phan tu sau khi xoa.
    --ds->n;
}

//ham tim vi tri xoa khoang trang
void timViTriXoaKTrang(char s[90],int vitrixoa)
{
	int n=strlen(s);//gan n= do dai cua chuoi
    for(int i=vitrixoa;i<n;i++)//duyet chuoi tu vi tri xoa
     s[i]=s[i+1];
	s[n-1]='\0'; //ket thuc
}

//ham xoa khoang trang
void xoaKhoangTrang(char*s)
{
    for(int i=0;i<strlen(s);i++)
		if(s[i]==' '&& s[i+1]==' ')
		{
			timViTriXoaKTrang(s,i);
			i--;
		}
    if(s[0]==' ')
		timViTriXoaKTrang(s,0);
    if(s[strlen(s)-1]==' ')
		timViTriXoaKTrang(s,strlen(s)-1);
}

//ham tach chuoi ma khi co khoang trang chi lay token dau tien
void tachChuoi(char str[15]){
	const char s[2] = " ";
	char *token;

	/* lay token dau tien */
    token = strtok(str, s);
}

char* substring(char* s,int pos)    {
    
    char* t = &s[pos];
    s[pos-1] = '\0';
    return t;
}

//ham tach chuoi va so sanh cho nien khoa
bool tachChuoivaSoSanhNK(char str[MAXNK]){
	char cpstr[MAXNK];
	int sodangTruoc,sodangSau;
	const char s[2] = "-";
	char *token;
	
	strcpy(cpstr,str);
	/* lay token dau tien */
    token = strtok(str, s);
    sodangTruoc=atoi(str);
    
    /* duyet qua cac token con lai */
   	while( token != NULL ) {
      	token = strtok(NULL, s);
    	sodangSau = atoi(token);
	    token = '\0';
    }
    
    /*So sanh 2 so*/
    if(sodangSau > sodangTruoc){
    	return true;
	}
	else if(sodangSau <= sodangTruoc){
		return false;
	}
}

//ham kiem tra trung ma lop
bool trungMaLop(char s[MAXML], DSLOP *ds)
{
	for(int i=0;i<ds->n;i++){
		if(stricmp(ds->lop[i]->malop,s)==0){
			return true;
		}
	}
	return false;
}

bool trungMaLopForEdit(char s[MAXML], DSLOP *ds,int index)
{
	for(int i=0;i<ds->n;i++){
		if(i==index)continue;
		if(stricmp(ds->lop[i]->malop,s)==0){
			return true;
		}
	}
	return false;
}


//ham kiem tra trung ten lop
bool trungTenLop(char s[MAXTL], DSLOP *ds)
{
	for(int i=0;i<ds->n;i++){
		if(stricmp(ds->lop[i]->tenlop,s)==0){
				return true;
		}
	}
	return false;
}

bool trungTenLopForEdit(char s[MAXTL], DSLOP *ds,int index)
{
	for(int i=0;i<ds->n;i++){
		if(i==index)continue;
		if(stricmp(ds->lop[i]->tenlop,s)==0){
				return true;
		}
	}
	return false;
}

//ham kiem tra trung ma mon
bool trungMaMon(char s[MAXMMH], DSMON *dsmon)
{
	for(int i=0;i<dsmon->n;i++){
		if(stricmp(dsmon->mon[i]->mamh,s)==0){
			return true;
		}
	}
	return false;
}

bool trungMaMonForEdit(char s[MAXMMH], DSMON *dsmon,int index)
{  
	for(int i=0;i<dsmon->n;i++){
		if(i==index)continue;
		if(stricmp(dsmon->mon[i]->mamh,s)==0){
			return true;
		}
	}
	return false;
}

//ham kiem tra trung ten mon
bool trungTenMon(char s[MAXTMH], DSMON *dsmon)
{
	for(int i=0;i<dsmon->n;i++){
		if(stricmp(dsmon->mon[i]->tenmh,s)==0){
				return true;
		}
	}
	return false;
}
bool trungTenMonForEdit(char s[MAXTMH], DSMON *dsmon,int index)
{
	for(int i=0;i<dsmon->n;i++){
		if(i==index)continue;
		if(stricmp(dsmon->mon[i]->tenmh,s)==0){
				return true;
		}
	}
	return false;
}

//ham dinh dang nien khoa
bool dinhdangNienKhoa(char s[MAXNK])
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if(s[i] >= 48 && s[i] <= 57 && s[i+4]== 45 && strlen(s)==9){ //yyyy-yyyy
			return true;
		}
    }
    return false;
}

//ham dinh dang ma lop
bool dinhdangMaLop(char s[MAXML])
{ 
    for(int i=0;i<strlen(s);i++){
    	if(s[i]>=65&&s[i]<=90||s[i]>=97&&s[i]<=122||s[i]>=48&&s[i]<=57||s[i]==45)
//	  	 if(s[i+1] <= 48 && s[i+1] >= 57 && s[i+2] >= 48 && s[i+2] <= 57 && s[i+7] >= 48 && s[i+7] <= 57 && s[i+8] >= 48 && s[i+8] <= 57 && s[i+9] == 45 && s[i+10] == 78 && s[i+10] == 110 || s[i+10] != 66 && s[i+10] != 98 && strlen(s)>10 && strlen(s)<15)
	  	{
	  		return true; 
		}
	}
	return false;
}

//ham kiem tra chuoi nhap vo la so
bool ktKyTuSo(char s[])
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if(s[i] >= 48 && s[i] <= 57){
			return true;
		}
    }
    return false;
}

//ham kiem tra nhap vo phai co ky tu so
bool ktNhapVoPhaiCoKyTuSo(char *s)
{
	for(int i=0;i<strlen(s);i++){
        for(int j=48;j<=57;j++){
       		if(s[i]==j) {
       			return true; // dung la co ky tu so
			}
 		}
    }
 	return false;  //khong co ky tu so
}

int randColor(){
	srand((int)time(0));
    int r;
    for(int i = 0; i < 1; i++){
        r == random(10,15);
    }  
    return r;
}

bool YES_NO(OBJECR_LCT diemxy, int y, int x,char str[]){
	backGround2(diemxy.x,diemxy.y,diemxy.x+y,diemxy.y+x,119);	
	colorText(121); gotoxy(x+14,23); colorText(randColor()); printf("%s",str); clearColor();
	int c, choice;

	colorText(252); gotoxy(x+20,25); printf("YES");
	colorText(121); gotoxy(x+25,25); printf("NO");				
	choice=0;
	while(true){
		c=getch();
		if(c==75||c==77){
			choice++;
			if(choice%2==0){
				colorText(252); gotoxy(x+20,25); printf("YES");
				colorText(121); gotoxy(x+25,25); printf("NO");
			}else{
				colorText(121); gotoxy(x+20,25); printf("YES");
				colorText(252); gotoxy(x+25,25); printf("NO");
			}			
		}
		if(c==13){
			clearColor();
			if(choice%2==0){
				return true;
			}else{
				return false;
			}
		}
	}	
}

//ham kiem tra neu ky tu nhan vao chi la ky tu chu cai
bool checkIfAnswerOnlyCharacter(char c){
    if((int)c<=90 && (int)c>=90 || (int)c<=122 && (int)c>=97){
   		return true;	
	}
    return false;
}

//ham kiem tra chuoi rong
bool checkNullArr(char arr[]){
	if(strlen(arr)==0)return true;
    return false;
}

//hàm ki?m tra n?u dang nh?p vào mà vu?t quá d? dài c?a dòng thì t? xu?ng dòng
bool shouldPrintNewLine(char nd[MAX_CONTENT_QUESTION],int i,int j,int end){
	int index = 0;
	int k;
	if(nd[i]==' '){
		for( k=i+1;k<(strlen(nd))-1;k++){
			if(nd[k]==' ')break;
			index++;
		}
		if((end-(index+j))<0)return true;
		else {
		  return false;
	    }
	}
	return false;
}

//hàm ? du?i dùng trong hàm showStringInLocation nha
bool printfOnNewLine(int index,int indexEnd){
	if(index==indexEnd)return true;
	return false;
}

//ham hien thi chuoi ky tu tren tung dong
//hàm này t?o du?ng vi?n bên ngoài cái b?ng chính. d? r?ng là kho?ng cách gi?a 2 c?nh c?a 2 b?ng
//--------------------------------------------------------------------------
int showStringInLocation(char nd[MAX_CONTENT_QUESTION],int x,int y,int end){
    
 int i=0,j=x,k=0,index,n,findBP=0;
 bool flag = false;
 while(i<strlen(nd)){
    if(flag ==false){
    	
       if(shouldPrintNewLine(nd,i,j,end)==true){
       	j = end;i++;
		goto NEWLINE;
	   }
	   else {
	   
	    gotoxy(j,y);
        printf("%c",nd[i]);
        j++;
        i++;}
    }
    if(flag==true){
    	if(shouldPrintNewLine(nd,i,j,end)==true){
       	j = end;i++;
		goto NEWLINE;
	   }
	   else { 
		
        gotoxy(j,y+k);
        printf("%c",nd[i]);
        j++;
        i++;}
    
    }
NEWLINE: 
       if(j==end){
       j = x;
       k++;
       gotoxy(j,y+k);
       printf("%c",nd[i--]);
       i++;
       flag = true;
    }
 }
 return y+k;    
}
//------------------------hàm t?o file id câu h?i v?i hàm l?y id câu h?i t? file lên---------

bool checkExistId(int num,int mangId[MAXQUESTION],int slc){
	for(int i=0;i<=slc;i++){
		if(mangId[i]==num)return true;
	}
	return false;
}

int random(int maxN,int minN){
    
     int r = minN + rand() % (maxN + 1 - minN);
     return r;
}
    
void makeIdFile(){
		FILE *file;

    int id;
    
    id = MAXID/2;
  	file = fopen(IDFILE,"wb");
    fwrite(&id,sizeof(int),1,file);
    fclose(file);
    file = fopen(IDFILE,"ab");
     srand((int)time(0));
     for(int i=1;i<=MAXID;i++){
	     id = random(1,MAXID); 
	     if(id==MAXID/2){
	     	
		 }
		 if(id!=MAXID/2){
		 	fwrite(&id,sizeof(int),1,file);
		 }
		 	
    }fclose(file);
}

int getIdQuestionFromFile(){
   	int arrId[MAXID];
   	
   	FILE *file;
   	file = fopen(IDFILE,"rb");
   	int i = 0;
   	while(fread(&arrId[i],sizeof(int),1,file)){
   		i++;
	   }
   	fclose(file);
   	file = fopen(IDFILE,"wb");
   	for(int j=1;j<=MAXID;j++){
   		   fwrite(&arrId[j],sizeof(int),1,file);
	   }fclose(file);
	return arrId[0];
}

//tim chuoi con trong 1 chuoi
int findsubstr(const char *str, char *sub){
	const char *p = str;
	int len = strlen(sub);
	while(p != NULL){
		if (strlen(p) >= len){
			if (strncmp(p, sub, strlen(sub)) == 0){
				return (p - str);
			}
		}
		else{
			break;
		}
		p++;
	}
	return -1;
}

//ham chuyen tu c=getch() so sang so integer
int convertIntFromChar(char c){
	if(c==48)return 0;
	if(c==49)return 1;
	if(c==50)return 2;
	if(c==51)return 3;
	if(c==52)return 4;
	if(c==53)return 5;
	if(c==54)return 6;
	if(c==55)return 7;
	if(c==56)return 7;
	if(c==57)return 9;
	else{return -1;}    
}

//chuyen tu mang ky tu so sang so integer
int convertIntegerFromCharArr(char number[MAX]){
	int num = 0;
	int i = strlen(number);
	int j = 1;
	for(int n=0;n<i-1;n++)j*=10;
	int z = 0;
	while(z<i){
		num = num + j*convertIntFromChar(number[z]);
		j/=10;
		z++;
	}
	return num;
}

//hàm tìm vi trí cua x sao cho in chuoi str ngay giua màn hình
int findCenterScreenX(char str[MAX_X_SCREEN]){
	
	return ((MAX_X_SCREEN/2) - (strlen(str))/2);
}

//kiem tra danh sach LOP rong
int Empty_L(DSLOP *dslop){
	if(dslop->n == 0){
		return 1;
	}
  	return 0;	
}

//kiem tra xem danh sach LOP full 
int Full_L(DSLOP *dslop){
	if(dslop->n == MAXCLASS){
		return 1;
	}
  	return 0;	
}

//kiem tra danh sach MON rong
int Empty_M(DSMON *dsmon){
	if(dsmon->n == 0){
		return 1;
	}
  	return 0;	
}

//kiem tra xem danh sach MON full 
int Full_M(DSMON *dsmon){
	if(dsmon->n == MAXOBJECT){
		return 1;
	}
  	return 0;	
}

bool ExistQuestion(NODECAUHOI root,char mamh[MAXMMH]){

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
	 
	 if(stricmp(p->cauhoi.mamh,mamh)==0){
	 	
	 	return true;
	 }

	 p=p->right;
      }
      else break;
   } while (1);
return false; 
}

void dialog(int x,int y,char notice[100]){
	OBJECR_LCT diemxy;
	OBJECR_LCT diemxyL;
	diemxy.x = x;
	diemxy.y = y;
	diemxyL = makeTable_Color_Type2(diemxy,10,50,254,254);
	backGround2(diemxy.x,diemxy.y,diemxyL.maxX,diemxyL.maxY,254);
	colorText(240);
	showStringInLocation(notice,diemxy.x+2,diemxy.y+1,diemxy.x+50);
	diemxy.x = diemxyL.maxX-6;
	diemxy.y = diemxyL.maxY-6;
	diemxyL = makeTable_Color_Type2(diemxy,3,5,153,153);
	backGround2(diemxy.x,diemxy.y,diemxyL.maxX,diemxyL.maxY,153);
	colorText(159);
	gotoxy(diemxyL.maxX-3,diemxyL.maxY-2);
	printf("%s","OK");

    char c = ' ';
    Sleep(1500);
//    gotoxy(0,0);
//    clearColor();
//    while(c=getch()!=13){
//    	
//	}
	clearPartOfScreen(x,y,x+50,y+10);
	
}



