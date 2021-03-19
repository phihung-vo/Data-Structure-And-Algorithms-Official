#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<conio.h>

//--------------Function For Student
void InitDSSV(NODESINHVIEN &First) {
	First=NULL;
}
NODESINHVIEN NewNode(){
	NODESINHVIEN p;
	p = (NODESINHVIEN)malloc(sizeof(nodesinhvien));
	return p;
}
NODESINHVIEN CreateNode(SINHVIEN &sv){
	NODESINHVIEN tmp=(NODESINHVIEN)malloc(sizeof(nodesinhvien));
	tmp->next=NULL;
	tmp->sinhvien=sv;
	return tmp;
}
int EmptyDSSV(NODESINHVIEN &First){
	return(First==NULL ? 1 : 0);
}
void Clear_DSSV(NODESINHVIEN &First){
	NODESINHVIEN p; p=First;
	while(First!=NULL){
		p=First;
		First=First->next;
		free(p);
	}
}
bool checkMSV(NODESINHVIEN First, char maSv[MAXMSV]){
	NODESINHVIEN p;
	for(p=First;p!=NULL;p=p->next){
		if(stricmp(p->sinhvien.masv,maSv)==0){return true; break;}
	}
	return false;
}
bool trungMSV(DSLOP *dslop, char maSV[MAXMSV]){
	if(dslop->n==0) return false;
	else{
		NODESINHVIEN p;
		for(int i=0;i<dslop->n;i++){
			p = dslop->lop[i]->dssinhvien;
			while(p!=NULL){
				if(stricmp(p->sinhvien.masv,maSV)==0) return true;
				p=p->next;
			}
		}delete p;
	}
	return false;
}
bool trungMSVChonLoc(DSLOP *dslop, char maLop[MAXML], char maSV[MAXMSV], int pos){
	if(dslop->n==0) return false;
	else{
		NODESINHVIEN p;
		for(int i=0;i<dslop->n;i++){
			p = dslop->lop[i]->dssinhvien;
			if(stricmp(dslop->lop[i]->malop,maLop)!=0){
				while(p!=NULL){
					if(stricmp(p->sinhvien.masv,maSV)==0) return true;
					p=p->next;
				}
			}
			if(stricmp(dslop->lop[i]->malop,maLop)==0){		
				int cnt1=0;		
				while(p!=NULL){
					if(cnt1<pos){ if(stricmp(p->sinhvien.masv,maSV)==0) return true; }
					if(cnt1==pos){
						p=p->next; cnt1++; continue;
					}
					if(cnt1>pos){ if(stricmp(p->sinhvien.masv,maSV)==0) return true; }
					p=p->next; cnt1++;
				}
			}
		}delete p;
	}
	return false;
}
NODESINHVIEN Search_SV(NODESINHVIEN First, char maSv[MAXMSV]){
	NODESINHVIEN p;
	for(p=First;p!=NULL;p=p->next){
		if(stricmp(p->sinhvien.masv,maSv)==0){
			return p; break;
		}
	}	
	return NULL;
}
//nodepointer cho contro tro den node thu i trong danh sach lien ket
NODESINHVIEN nodepointer(NODESINHVIEN First, int i){
	NODESINHVIEN p;
	p=First;
	int pos=1;
	while(p!=NULL&&pos<i){
		p=p->next;
		pos++;
	}
	return p;
}
//position tra ve vi tri cua node p trong danh sach lien ket
int position(NODESINHVIEN First, NODESINHVIEN p){	
	NODESINHVIEN q;
	q=First;
	int pos=1;
	while(q!=NULL&&q!=p){
		q=q->next;
		pos++;
	}
	if(q==NULL) return -1;
	else return pos;
}
int countSV(NODESINHVIEN First){
	int count=0;
	NODESINHVIEN p = First;
	if(p==NULL) return 0;
	while(p!=NULL){
		count++; p=p->next;		
	}
	return count;
}
int countSV_DSLOP(DSLOP *dslop, char s[MAXML]){
	int count=0;	
	for(int i=0;i<dslop->n;i++){
		if(stricmp(dslop->lop[i]->malop,s)==0){
			NODESINHVIEN p = dslop->lop[i]->dssinhvien;
			if(p==NULL) return count=0;
			while(p!=NULL){
				count++; p=p->next;
			}
		}
	}
	return count;
}
bool trungML(DSLOP *dslop, char maLop[MAXML], NODESINHVIEN &p){
	for(int i=0;i<dslop->n;i++){
		if(stricmp(dslop->lop[i]->malop,maLop)==0){
			p=dslop->lop[i]->dssinhvien;
			return true;
		}
	}
	return false;
}
//Them SV moi vao dau DSSV
void Insert_First_SV(NODESINHVIEN &First, SINHVIEN sv){	
	NODESINHVIEN p = (NODESINHVIEN)malloc(sizeof(nodesinhvien));
	p->sinhvien=sv;
	p->next=First;
	First=p;
}
//Them SV moi vao sau SV co dia chi p
void Insert_After_SV(NODESINHVIEN &p, SINHVIEN sv){	
	if(p==NULL) printf("Khong the them SV vao DSSV!\n");
	else{
		NODESINHVIEN q = (NODESINHVIEN)malloc(sizeof(nodesinhvien));
		q->sinhvien=sv;
		q->next=p->next;
		p->next=q;		
	}
}
void Insert_Last_SV(NODESINHVIEN &First, SINHVIEN sv){
	NODESINHVIEN tmp;
	tmp=CreateNode(sv);
	if(First==NULL){
		First=tmp;
	}else{
		NODESINHVIEN p=First;
		while(p->next!=NULL){
			p=p->next;			
		}
		p->next=tmp;
	}
}
void DelHead_SV(NODESINHVIEN &First){
	if(First!=NULL){
		First=First->next;
	}
}
void DelTail_SV(NODESINHVIEN &First){
	if (First == NULL || First->next == NULL){
        DelHead_SV(First);
    }
    NODESINHVIEN p = First;
    while(p->next->next != NULL){
        p = p->next;
    }
    p->next = p->next->next; //p->next = NULL
}
void DelAt_SV(NODESINHVIEN &First, int pos){
	if(pos==0||First==NULL||First->next==NULL){
		DelHead_SV(First);
	}else{
		int k=1;
		NODESINHVIEN p = First;
		while(p->next->next!=NULL&&k!=pos){
			p=p->next; ++k;
		}
		if(k!=pos){
			DelTail_SV(First);
		}else{
			p->next=p->next->next;
		}
	}
}
void sapxepSV(NODESINHVIEN &First){
	NODESINHVIEN p,q,pmin; SINHVIEN min;
	for(p=First;p->next!=NULL;p=p->next){
		min=p->sinhvien;
		pmin=p;
		for(q=p->next;q!=NULL;q=q->next){
			if(stricmp(q->sinhvien.masv,min.masv)<0){
				min=q->sinhvien;
				pmin=q;
			}
		}
		pmin->sinhvien=p->sinhvien;
		p->sinhvien=min;
	}
}
void updateSVLop(DSLOP *dslop, char maLop[MAXML], NODESINHVIEN dssvNew){
	for(int i=0;i<dslop->n;i++){
		if(stricmp(dslop->lop[i]->malop,maLop)==0){
			dslop->lop[i]->dssinhvien=dssvNew;
			return;
		}
	}
}
char *findMaSVIndex(NODESINHVIEN p, int arrow){
	int i=0;
	while(p!=NULL&&i<=arrow){
		if(i==arrow){
			return p->sinhvien.masv;
		}
		i++; p=p->next;
	}
}
void Traverse_DSSV(NODESINHVIEN First){
	NODESINHVIEN p;
	p=First;
	if(p==NULL){
		printf("DSSV rong!");
	}else{
		int count=0;
		while(p!=NULL){		
			printf("\n%5d %10s %10s %10s %10s %10s %10s",++count,p->sinhvien.masv, p->sinhvien.ho, p->sinhvien.ten, p->sinhvien.phai, p->sinhvien.password,p->sinhvien.dsdiem);
			p=p->next;
		}
	}
}
void Khung_Nhap_SV(OBJECR_LCT start, int dai, int rong, int col_right, int row_bottom){
	makeTable_Type2(start,dai,rong);
	gotoxy(start.x+(rong-col_right)/2-12,start.y+1);
	printf("NHAP THONG TIN SINH VIEN");
	gotoxy(start.x+1,start.y+3);
	printf("Nhap Ma Lop: ");
	gotoxy(start.x+(rong-col_right)/2-7,start.y+6);
	printf("NHAP THONG TIN");
	gotoxy(start.x+1,start.y+8);
	printf("Nhap MSSV: ");
	gotoxy(start.x+1,start.y+10);
	printf("Nhap Ho: ");
	gotoxy(start.x+1,start.y+12);
	printf("Nhap Ten: ");
	gotoxy(start.x+1,start.y+14);
	printf("Nhap Phai: ");
	gotoxy(start.x+1,start.y+16);
	printf("Nhap Password: ");
	gotoxy(start.x+1,start.y+18);
	printf("Nhap lai Password: ");
	gotoxy(start.x+rong-col_right+col_right/2-8,start.y+1);
	printf("DANH SACH SINH VIEN");		
	gotoxy(start.x+rong/2-64,start.y+dai-1); colorText(227);
	printf("QUAY LAI::Esc  |  CONTROL::Up|Down|Left|Right  |  CHUYEN TRANG::F1+Left|Right  |  CHON SV::Control+Enter  |  SUA|XOA::F1+CHON SV"); clearColor();
	
	for(int i=1;i<rong;i++){
		if(start.x+i<start.x+(rong-col_right)){
			gotoxy(start.x+i,start.y+5);
			printf("-");
			gotoxy(start.x+i,start.y+dai-row_bottom-6);
			printf("-");
			gotoxy(start.x+i,start.y+dai-row_bottom);
			printf("-");
		}		
		if(start.y+i<start.y+dai-1){
			gotoxy(start.x+(rong-col_right),start.y+i);
			printf("%c",186);
		}
		if(start.x+i<start.x+rong){
			gotoxy(start.x+i,start.y+dai-2);
			printf("%c",205);
		}
	}
}
bool NOTICE(int x, int y, char str[]){
	int c, choice=0;
	gotoxy(x,y); printf("%s",str);
	colorText(252); gotoxy(x+strlen(str)/2-4,y+2); printf("Yes");
	colorText(233); gotoxy(x+strlen(str)/2+1,y+2); printf("No");			
	
	while(1){
		c=getch();
		if(c==75||c==77){
			choice++;
			if(choice%2==0){
				colorText(252); gotoxy(x+strlen(str)/2-4,y+2); printf("Yes");
				colorText(233); gotoxy(x+strlen(str)/2+1,y+2); printf("No");
			}else{
				colorText(233); gotoxy(x+strlen(str)/2-4,y+2); printf("Yes");
				colorText(252); gotoxy(x+strlen(str)/2+1,y+2); printf("No");
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
bool NOTICE2(int x, int y, int xyes, int yyes, int xno, int yno, char str[]){
	int c, choice=0;
	backGround2(x,y,x+18,y,119); colorText(121);
	gotoxy(x,y); printf("%s",str);
	colorText(252); gotoxy(xyes,yyes); printf("Yes");
	colorText(121); gotoxy(xno,yno); printf("No");			
	
	while(1){
		c=getch();
		if(c==75||c==77){
			choice++;
			if(choice%2==0){
				colorText(252); gotoxy(xyes,yyes); printf("Yes");
				colorText(121); gotoxy(xno,yno); printf("No");
			}else{
				colorText(121); gotoxy(xyes,yyes); printf("Yes");
				colorText(252); gotoxy(xno,yno); printf("No");
			}
		}	
		if(c==13){
			if(choice%2==0){
				return true;
			}else{
				return false;
			}
		}		
	}
}
int OPTION_SUA_XOA(OBJECR_LCT dialog, int dlogdai, char str[]){
	int dlogrong=strlen(str)+4;
	clearPartOfScreen(dialog.x-2,dialog.y-1,dialog.x+dlogrong+2,dialog.y+dlogdai+1);
	backGround2(dialog.x,dialog.y,dialog.x+dlogrong,dialog.y+dlogdai,119);	
	
	colorText(121); gotoxy(dialog.x+dlogrong/2-strlen(str)/2,dialog.y+1); printf("%s",str);
	colorText(121); gotoxy(dialog.x+3,dialog.y+dlogdai-1); printf("OK: ENTER");
	colorText(121); gotoxy(dialog.x+dlogrong-13,dialog.y+dlogdai-1); printf("CANCEL: ESC");
	
	int c, choice;
LOOP:	
	colorText(252); gotoxy(dialog.x+dlogrong/2-7,dialog.y+3); printf("SUA");
	colorText(121); gotoxy(dialog.x+dlogrong/2+4,dialog.y+3); printf("XOA");				
	choice=0;
	while(1){
		c=getch();
		if(c==75||c==77){
			choice++;
			if(choice%2==0){
				colorText(252); gotoxy(dialog.x+dlogrong/2-7,dialog.y+3); printf("SUA");
				colorText(121); gotoxy(dialog.x+dlogrong/2+4,dialog.y+3); printf("XOA");
			}else{
				colorText(121); gotoxy(dialog.x+dlogrong/2-7,dialog.y+3); printf("SUA");
				colorText(252); gotoxy(dialog.x+dlogrong/2+4,dialog.y+3); printf("XOA");
			}			
		}
		if(c==13){
			clearColor();
			if(choice%2==0){	//sua
				clearPartOfScreen(dialog.x,dialog.y,dialog.x+dlogrong,dialog.y+dlogdai);
				clearColor();
				return 0;
			}else{				//xoa
				if(NOTICE2(dialog.x+dlogrong/2-10,dialog.y+5,dialog.x+dlogrong/2-10+10,dialog.y+5,dialog.x+dlogrong/2-10+10+6,dialog.y+5,"Xac nhan: ")){
					clearPartOfScreen(dialog.x,dialog.y,dialog.x+dlogrong,dialog.y+dlogdai);
					clearColor();
					return 1;
				}else{
					backGround2(dialog.x+dlogrong/2-10,dialog.y+5,dialog.x+dlogrong/2-10+18,dialog.y+5,119);		//Clear XACNHAN
					goto LOOP;
				}
			}
		}
		if(c==27){
			clearPartOfScreen(dialog.x,dialog.y,dialog.x+dlogrong,dialog.y+dlogdai);
			clearColor();
			return -1;
		}	
	}	
}
int inDSSV(NODESINHVIEN p, int page, int arrow, int slsv, int x, int y){
	int count=0, i=0, j=-1, expand=0; char c;	
	
RP:		if((page*20 - slsv)>20){
			page--;
			goto RP;
		}else{					
			while(p!=NULL&&i<slsv){
				if(i%20==0) j++;
				if(j==page){
					if(count==arrow){						
						colorText(225);							
						gotoxy(x,y+expand); printf("%s",p->sinhvien.masv);
						gotoxy(x+MAXMSV+2,y+expand); printf("%s",p->sinhvien.ho);
						gotoxy(x+MAXMSV+MAXHOSV+3,y+expand); printf("%s",p->sinhvien.ten);
						gotoxy(x+MAXMSV+MAXHOSV+MAXTENSV+4,y+expand); printf("%s",p->sinhvien.phai);
						gotoxy(x+MAXMSV+MAXHOSV+MAXTENSV+MAXPHAI+5,y+expand); printf("%s",p->sinhvien.password);
						clearColor();
					}else{
						gotoxy(x,y+expand); printf("%s",p->sinhvien.masv);
						gotoxy(x+MAXMSV+2,y+expand); printf("%s",p->sinhvien.ho);
						gotoxy(x+MAXMSV+MAXHOSV+3,y+expand); printf("%s",p->sinhvien.ten);
						gotoxy(x+MAXMSV+MAXHOSV+MAXTENSV+4,y+expand); printf("%s",p->sinhvien.phai);
						gotoxy(x+MAXMSV+MAXHOSV+MAXTENSV+MAXPHAI+5,y+expand); printf("%s",p->sinhvien.password);
					}
					expand+=2;
					count++;					
				}
				i++; p=p->next;
			}																	
		}
	return i;
}
//--------------------------
void Edit_SV(DSLOP *dslop, char maLop[MAXML], NODESINHVIEN &First, int slsv, int pos, int page, int arrow,
OBJECR_LCT start, int dai, int rong, int col_right, int row_bottom, int x_esc, int y_esc);
//--------------------------
int DSSV(DSLOP *dslop, char maLop[MAXML], NODESINHVIEN &p, int page, int arrow, OBJECR_LCT start, int dai, int rong, int col_right, int row_bottom, int x_esc, int y_esc){
	char c; c='\0'; int maxpage, maxrow, slsv;	
	
	int dlogdai=8, dlogrong=30;
	OBJECR_LCT dialog; dialog.x=start.x+rong-col_right+col_right/2-dlogrong/2; dialog.y=start.y+dai/2-dlogdai/2;
	
	int x_tmp = start.x+rong-col_right;
	gotoxy(start.x+x_esc,start.y+dai-row_bottom-4); colorText(160); printf("THEM SINH VIEN::ESC  |  SUA/XOA SINH VIEN::ENTER");	clearColor();				
	gotoxy(x_tmp+2,start.y+2); printf("Lop nay hien co      sinh vien");		
	colorText(160); gotoxy(x_tmp+3,start.y+4); printf("MSSV");
	gotoxy(x_tmp+MAXMSV+5,start.y+4); printf("HO");
	gotoxy(x_tmp+MAXMSV+MAXHOSV+6,start.y+4); printf("TEN");
	gotoxy(x_tmp+MAXMSV+MAXHOSV+MAXTENSV+7,start.y+4); printf("PHAI");
	gotoxy(x_tmp+MAXMSV+MAXHOSV+MAXTENSV+MAXPHAI+8,start.y+4); printf("PASSWORD"); clearColor();				
	
W:	slsv=countSV(p); maxpage=slsv/20;
	if(maxpage==0) maxrow=slsv;
	else maxrow=slsv%20;
	colorText(225); gotoxy(x_tmp+18,start.y+2); printf("%d",slsv); clearColor();
	inDSSV(p,page,arrow,slsv,x_tmp+3,start.y+6);	
	while(1){
		c=getch();
		if(c==-32){
			c=getch();
			if(c==77&&page<maxpage){
				page++;
				arrow=0;
				clearPartOfScreen(x_tmp+1,start.y+6,start.x+rong-1,start.y+dai-3);							//Clear DSSV con Rut gon
				inDSSV(p,page,arrow,slsv,x_tmp+3,start.y+6);
			}
			if(c==75&&page>0){
				page--;
				arrow=0;
				clearPartOfScreen(x_tmp+1,start.y+6,start.x+rong-1,start.y+dai-3);							//Clear DSSV con Rut gon
				inDSSV(p,page,arrow,slsv,x_tmp+3,start.y+6);
			}
		}
		if(c==80){
			if(maxpage==0){
				if(arrow<maxrow-1){
					arrow++;
				}else{
					arrow=maxrow-1;
				}
				inDSSV(p,page,arrow,slsv,x_tmp+3,start.y+6);
			}else{
				if(page<maxpage){
					arrow++;
		    		if(arrow>19){
		    			arrow=19;
					}
		    		inDSSV(p,page,arrow,slsv,x_tmp+3,start.y+6);
				}else{
					if(arrow<maxrow-1){
						arrow++;
					}else{
						arrow=maxrow-1;
					}
					inDSSV(p,page,arrow,slsv,x_tmp+3,start.y+6);
				}
			}		
		}
		if(c==72){
			arrow--;
			if(arrow<0) arrow = 0;
			inDSSV(p,page,arrow,slsv,x_tmp+3,start.y+6);
		}
		if(c==13){
			int n=19+page*20-(19-arrow), m=OPTION_SUA_XOA(dialog,dlogrong,"HIEU CHINH SINH VIEN NAY?");
			inDSSV(p,page,arrow,slsv,x_tmp+3,start.y+6);						
			if(m==0){																	//sua
				Edit_SV(dslop,maLop,p,slsv,n,page,arrow,start,dai,rong,col_right,row_bottom,x_esc,y_esc);
				goto W;
			}else if(m==1){																//xoa
				clearPartOfScreen(x_tmp+1,start.y+6,start.x+rong-1,start.y+dai-3);							//Clear DSSV con Rut gon
				if(slsv>0){
					DelAt_SV(p,n);
					updateSVLop(dslop,maLop,p);
					saveDSLop(dslop);
				}				
				goto W;
			}
		}
		if(c==27){
			clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
			return -1;
		}
	}
}
void fastClear(OBJECR_LCT start, int dai, int rong, int col_right, int row_bottom){
	clearPartOfScreen(start.x+1,start.y+dai-row_bottom-2,start.x+rong-col_right-1,start.y+dai-row_bottom-2);				//Clear "BAN DANG..."
	clearPartOfScreen(start.x+20,start.y+8,start.x+20+MAXMSV,start.y+8);
	clearPartOfScreen(start.x+20,start.y+10,start.x+20+MAXHOSV,start.y+10);
	clearPartOfScreen(start.x+20,start.y+12,start.x+20+MAXTENSV,start.y+12);
	clearPartOfScreen(start.x+20,start.y+14,start.x+20+MAXPHAI,start.y+14);
	clearPartOfScreen(start.x+20,start.y+16,start.x+20+MAXPW,start.y+16);
	clearPartOfScreen(start.x+20,start.y+18,start.x+20+MAXPW,start.y+18);
	clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+rong-col_right-1,start.y+dai-3);  //row_bottom
}
void Edit_SV(DSLOP *dslop, char maLop[MAXML], NODESINHVIEN &First, int slsv, int pos, int page, int arrow,
OBJECR_LCT start, int dai, int rong, int col_right, int row_bottom, int x_esc, int y_esc){
	
	SINHVIEN sv = getSVIndex(First,pos); int i=0;
	
	gotoxy(start.x+x_esc,start.y+dai-row_bottom-2); printf("BAN DANG 'CHINH SUA' SINH VIEN %s",sv.masv);
	char key, pwcf[MAXPW];
	int vt_msv=strlen(sv.masv), vt_ho=strlen(sv.ho), vt_ten=strlen(sv.ten), vt_phai=strlen(sv.phai), vt_pw=strlen(sv.password), vt_pwcf=vt_pw;	
	
	strcpy(pwcf,sv.password);
	gotoxy(start.x+20,start.y+8); printf("%s",sv.masv);
	gotoxy(start.x+20,start.y+10); printf("%s",sv.ho);
	gotoxy(start.x+20,start.y+12); printf("%s",sv.ten);
	gotoxy(start.x+20,start.y+14); printf("%s",sv.phai);
	gotoxy(start.x+20,start.y+16); printf("%s",sv.password);
	gotoxy(start.x+20,start.y+18); printf("%s",pwcf);
			
MASV:	
		gotoxy(start.x+x_esc,start.y+(dai-row_bottom)+1);
		printf("MSSV: TOI DA %d KY TU, BAO GOM A-Z, a-z, 0-9",MAXMSV);
		gotoxy(start.x+20+vt_msv,start.y+8);
		while(1){
			key=getch();
			if(key>=65&&key<=90||key>=97&&key<=122||key>=48&&key<=57){ //A-Z a-z 0-9
				if(vt_msv<MAXMSV){
					sv.masv[vt_msv]=(char)key;
					sv.masv[vt_msv]=toupper(sv.masv[vt_msv]);
					gotoxy(start.x+20+vt_msv,start.y+8);
					printf("%c",sv.masv[vt_msv]);
					vt_msv++;
				}else{					
					gotoxy(start.x+20+vt_msv,start.y+8);
					printf(" ");
					gotoxy(start.x+20+vt_msv,start.y+8);
				}
			}
			if(key==8&&vt_msv>0){   //BACKSPACE
				vt_msv--;
				gotoxy(start.x+20+vt_msv,start.y+8);
				printf(" ");
				gotoxy(start.x+20+vt_msv,start.y+8);
			}
			if(key==13&&vt_msv!=0){ //ENTER
				clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
				goto HO;						
			}
			if(key==27){        //ESC
				vt_msv=0; vt_ho=0; vt_ten=0; vt_phai=0; vt_pw=0, vt_pwcf=0;
				sv.masv[vt_msv]='\0'; sv.ho[vt_ho]='\0'; sv.ten[vt_ten]='\0'; sv.phai[vt_phai]='\0'; sv.password[vt_pw]='\0'; pwcf[vt_pwcf]='\0';				
				fastClear(start,dai,rong,col_right,row_bottom);
				return;
			}
			if(key==0){
				key=getch();
				if(key==59){
					vt_msv=0; vt_ho=0; vt_ten=0; vt_phai=0; vt_pw=0, vt_pwcf=0;
					sv.masv[vt_msv]='\0'; sv.ho[vt_ho]='\0'; sv.ten[vt_ten]='\0'; sv.phai[vt_phai]='\0'; sv.password[vt_pw]='\0'; pwcf[vt_pwcf]='\0';				
					fastClear(start,dai,rong,col_right,row_bottom);
					return;
				}
			}
			if(key==-32){       
				key=getch();				
				if(key==80&&vt_msv!=0){		//DOWN
					clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
					goto HO;
				}				
				else{
					gotoxy(start.x+20+vt_msv,start.y+8);
				}
			}
		}
HO:		
		gotoxy(start.x+x_esc,start.y+(dai-row_bottom)+1);
		printf("HO: TOI DA %d KY TU, BAO GOM A-Z, a-z, Khoang Trang",MAXHOSV);
		gotoxy(start.x+20+vt_ho,start.y+10);
		while(1){
			key=getch();
			if(key>=65&&key<=90||key>=97&&key<=122||key==32){ //A-Z a-z 0-9
				if(vt_ho<MAXHOSV){
					sv.ho[vt_ho]=(char)key;
					gotoxy(start.x+20+vt_ho,start.y+10);
					printf("%c",sv.ho[vt_ho]);
					vt_ho++;
				}else{					
					gotoxy(start.x+20+vt_ho,start.y+10);
					printf(" ");
					gotoxy(start.x+20+vt_ho,start.y+10);
				}
			}
			if(key==8&&vt_ho>0){   //BACKSPACE
				vt_ho--;
				gotoxy(start.x+20+vt_ho,start.y+10);
				printf(" ");
				gotoxy(start.x+20+vt_ho,start.y+10);
			}
			if(key==13&&vt_ho!=0){ //ENTER
				clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
				goto TEN;
			}
			if(key==27){           //ESC
				vt_msv=0; vt_ho=0; vt_ten=0; vt_phai=0; vt_pw=0, vt_pwcf=0;
				sv.masv[vt_msv]='\0'; sv.ho[vt_ho]='\0'; sv.ten[vt_ten]='\0'; sv.phai[vt_phai]='\0'; sv.password[vt_pw]='\0'; pwcf[vt_pwcf]='\0';				
				fastClear(start,dai,rong,col_right,row_bottom);
				return;
			}
			if(key==0){
				key=getch();
				if(key==59){
					vt_msv=0; vt_ho=0; vt_ten=0; vt_phai=0; vt_pw=0, vt_pwcf=0;
					sv.masv[vt_msv]='\0'; sv.ho[vt_ho]='\0'; sv.ten[vt_ten]='\0'; sv.phai[vt_phai]='\0'; sv.password[vt_pw]='\0'; pwcf[vt_pwcf]='\0';				
					fastClear(start,dai,rong,col_right,row_bottom);
					return;
				}
			}
			if(key==-32){       
				key=getch();
				if(key==72){		              //UP
					clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
					goto MASV;
				}else if(key==80&&vt_ho!=0){	  //DOWN
					clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
					goto TEN;
				}else{
					gotoxy(start.x+20+vt_ho,start.y+10);
				}
			}
		}
TEN:	
		gotoxy(start.x+x_esc,start.y+(dai-row_bottom)+1);
		printf("TEN: TOI DA %d KY TU, BAO GOM A-Z, a-z, Khoang Trang",MAXTENSV);
		gotoxy(start.x+20+vt_ten,start.y+12);
		while(1){
			key=getch();
			if(key>=65&&key<=90||key>=97&&key<=122){ //A-Z a-z
				if(vt_ten<MAXTENSV){
					sv.ten[vt_ten]=(char)key;
					gotoxy(start.x+20+vt_ten,start.y+12);
					printf("%c",sv.ten[vt_ten]);
					vt_ten++;
				}else{					
					gotoxy(start.x+20+vt_ten,start.y+12);
					printf(" ");
					gotoxy(start.x+20+vt_ten,start.y+12);
				}
			}
			if(key==8&&vt_ten>0){   //BACKSPACE
				vt_ten--;
				gotoxy(start.x+20+vt_ten,start.y+12);
				printf(" ");
				gotoxy(start.x+20+vt_ten,start.y+12);
			}
			if(key==13&&vt_ten!=0){ //ENTER
				clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
				goto PHAI;
			}
			if(key==27){           //ESC
				vt_msv=0; vt_ho=0; vt_ten=0; vt_phai=0; vt_pw=0, vt_pwcf=0;
				sv.masv[vt_msv]='\0'; sv.ho[vt_ho]='\0'; sv.ten[vt_ten]='\0'; sv.phai[vt_phai]='\0'; sv.password[vt_pw]='\0'; pwcf[vt_pwcf]='\0';				
				fastClear(start,dai,rong,col_right,row_bottom);
				return;
			}
			if(key==0){
				key=getch();
				if(key==59){
					vt_msv=0; vt_ho=0; vt_ten=0; vt_phai=0; vt_pw=0, vt_pwcf=0;
					sv.masv[vt_msv]='\0'; sv.ho[vt_ho]='\0'; sv.ten[vt_ten]='\0'; sv.phai[vt_phai]='\0'; sv.password[vt_pw]='\0'; pwcf[vt_pwcf]='\0';				
					fastClear(start,dai,rong,col_right,row_bottom);
					return;
				}
			}
			if(key==-32){
				key=getch();
				if(key==72){		  //UP
					clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
					goto HO;
				}else if(key==80&&vt_ten!=0){	  //DOWN
					clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
					goto PHAI;
				}else{
					gotoxy(start.x+20+vt_ten,start.y+12);
				}
			}
		}
PHAI:	
		gotoxy(start.x+x_esc,start.y+(dai-row_bottom)+1);
		printf("PHAI: TOI DA %d KY TU, BAO GOM A-Z, a-z",MAXPHAI);
		gotoxy(start.x+20+vt_phai,start.y+14);
		while(1){
			key=getch();
			if(key>=65&&key<=90||key>=97&&key<=122||key>=48&&key<=57){ //A-Z a-z 0-9
				if(vt_phai<MAXPHAI){
					sv.phai[vt_phai]=(char)key;
					gotoxy(start.x+20+vt_phai,start.y+14);
					printf("%c",sv.phai[vt_phai]);
					vt_phai++;
				}else{					
					gotoxy(start.x+20+vt_phai,start.y+14);
					printf(" ");
					gotoxy(start.x+20+vt_phai,start.y+14);
				}
			}
			if(key==8&&vt_phai>0){   //BACKSPACE
				vt_phai--;
				gotoxy(start.x+20+vt_phai,start.y+14);
				printf(" ");
				gotoxy(start.x+20+vt_phai,start.y+14);
			}
			if(key==13&&vt_phai!=0){ //ENTER	
				sv.phai[vt_phai]='\0';			
				if(stricmp(sv.phai,"nam")==0||stricmp(sv.phai,"nu")==0||stricmp(sv.phai,"male")==0||stricmp(sv.phai,"female")==0){
					clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
					goto PASSWORD;
				}else{					
					gotoxy(start.x+x_esc,start.y+(dai-row_bottom)+3);
					printf("PHAI LA: 'NU' HOAC 'NAM' HOAC 'FEMALE' HOAC 'MALE'!");
					clearPartOfScreen(start.x+20,start.y+14,start.x+20+MAXPHAI,start.y+14);
					vt_phai=0; goto PHAI;
				}
			}
			if(key==27){        //ESC
				vt_msv=0; vt_ho=0; vt_ten=0; vt_phai=0; vt_pw=0, vt_pwcf=0;
				sv.masv[vt_msv]='\0'; sv.ho[vt_ho]='\0'; sv.ten[vt_ten]='\0'; sv.phai[vt_phai]='\0'; sv.password[vt_pw]='\0'; pwcf[vt_pwcf]='\0';				
				fastClear(start,dai,rong,col_right,row_bottom);
				return;
			}
			if(key==0){
				key=getch();
				if(key==59){
					vt_msv=0; vt_ho=0; vt_ten=0; vt_phai=0; vt_pw=0, vt_pwcf=0;
					sv.masv[vt_msv]='\0'; sv.ho[vt_ho]='\0'; sv.ten[vt_ten]='\0'; sv.phai[vt_phai]='\0'; sv.password[vt_pw]='\0'; pwcf[vt_pwcf]='\0';				
					fastClear(start,dai,rong,col_right,row_bottom);
					return;
				}
			}
			if(key==-32){       
				key=getch();
				if(key==72){		  //UP
					clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
					goto TEN;
				}else if(key==80&&vt_phai!=0){	  //DOWN
					sv.phai[vt_phai]='\0';			
					if(stricmp(sv.phai,"nam")==0||stricmp(sv.phai,"nu")==0||stricmp(sv.phai,"male")==0||stricmp(sv.phai,"female")==0){
						clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
						goto PASSWORD;
					}else{					
						gotoxy(start.x+x_esc,start.y+(dai-row_bottom)+3);
						printf("PHAI LA: 'NU' HOAC 'NAM' HOAC 'FEMALE' HOAC 'MALE'!");
						clearPartOfScreen(start.x+20,start.y+14,start.x+20+MAXPHAI,start.y+14);
						vt_phai=0; goto PHAI;
					}
				}else{
					gotoxy(start.x+20+vt_phai,start.y+14);
				}
			}
		}
PASSWORD:	
		gotoxy(start.x+x_esc,start.y+(dai-row_bottom)+1);
		printf("PASSWORD: TOI DA %d KY TU, BAO GOM A-Z, a-z, 0-9", MAXPW);
		gotoxy(start.x+20+vt_pw,start.y+16);
		while(1){
			key=getch();
			if(key>=65&&key<=90||key>=97&&key<=122||key>=48&&key<=57){ //A-Z a-z 0-9
				if(vt_pw<MAXPW){
					sv.password[vt_pw]=(char)key;
					gotoxy(start.x+20+vt_pw,start.y+16);
					printf("%c",sv.password[vt_pw]);
					vt_pw++;
				}else{					
					gotoxy(start.x+20+vt_pw,start.y+16);
					printf(" ");
					gotoxy(start.x+20+vt_pw,start.y+16);
				}
			}
			if(key==8&&vt_pw>0){   //BACKSPACE
				vt_pw--;
				gotoxy(start.x+20+vt_pw,start.y+16);
				printf(" ");
				gotoxy(start.x+20+vt_pw,start.y+16);
			}
			if(key==13&&vt_pw!=0){ //ENTER																												
				goto CONFIRM_PASSWORD;	
			}
			if(key==27){        //ESC
				vt_msv=0; vt_ho=0; vt_ten=0; vt_phai=0; vt_pw=0, vt_pwcf=0;
				sv.masv[vt_msv]='\0'; sv.ho[vt_ho]='\0'; sv.ten[vt_ten]='\0'; sv.phai[vt_phai]='\0'; sv.password[vt_pw]='\0'; pwcf[vt_pwcf]='\0';				
				fastClear(start,dai,rong,col_right,row_bottom);
				return;
			}
			if(key==0){
				key=getch();
				if(key==59){
					vt_msv=0; vt_ho=0; vt_ten=0; vt_phai=0; vt_pw=0, vt_pwcf=0;
					sv.masv[vt_msv]='\0'; sv.ho[vt_ho]='\0'; sv.ten[vt_ten]='\0'; sv.phai[vt_phai]='\0'; sv.password[vt_pw]='\0'; pwcf[vt_pwcf]='\0';				
					fastClear(start,dai,rong,col_right,row_bottom);
					return;
				}
			}
			if(key==-32){       
				key=getch();
				if(key==72){		  //UP
					clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
					goto PHAI;
				}else if(key==80&&vt_pw!=0){    //DOWN
					goto CONFIRM_PASSWORD;
				}else{				
					gotoxy(start.x+20+vt_pw,start.y+16);
				}
			}
		}
CONFIRM_PASSWORD:
		gotoxy(start.x+20+vt_pwcf,start.y+18);		
		while(1){
			key=getch();
			if(key>=65&&key<=90||key>=97&&key<=122||key>=48&&key<=57){ //A-Z a-z 0-9
				if(vt_pwcf<MAXPW){
					pwcf[vt_pwcf]=(char)key;
					gotoxy(start.x+20+vt_pwcf,start.y+18);
					printf("%c",pwcf[vt_pwcf]);
					vt_pwcf++;
				}else{					
					gotoxy(start.x+20+vt_pwcf,start.y+18);
					printf(" ");
					gotoxy(start.x+20+vt_pwcf,start.y+18);
				}
			}
			if(key==8&&vt_pwcf>0){   //BACKSPACE
				vt_pwcf--;
				gotoxy(start.x+20+vt_pwcf,start.y+18);
				printf(" ");
				gotoxy(start.x+20+vt_pwcf,start.y+18);
			}
			if(key==13&&vt_pwcf!=0){ //ENTER
			
				sv.password[vt_pw]='\0'; pwcf[vt_pwcf]='\0';
				if(strcmp(sv.password,pwcf)==0){
					//update?		
					if(NOTICE(start.x+(rong-col_right)/2-14,start.y+(dai-row_bottom)+y_esc,"Xac nhan cap nhat sinh vien?")){
						sv.masv[vt_msv]='\0'; sv.ho[vt_ho]='\0'; delspace(sv.ho); vietHoaChuCaiDau(sv.ho);
						sv.ten[vt_ten]='\0'; vietHoaChuCaiDau(sv.ten);
						sv.phai[vt_phai]='\0'; vietHoaChuCaiDau(sv.phai);
						sv.password[vt_pw]='\0'; sv.dsdiem=NULL;
						clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+3,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
						if(trungMSVChonLoc(dslop,maLop,sv.masv,pos)){
							gotoxy(start.x+x_esc,start.y+(dai-row_bottom)+3);
							printf("MASV DA TON TAI!!! NHAP LAI MASV!");  Sleep(1000);
							clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+3,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
							goto MASV;
						}else{
							DelAt_SV(First,pos);
							Insert_Last_SV(First,sv);
							sapxepSV(First);
							updateSVLop(dslop,maLop,First);															
						}
						saveDSLop(dslop);		
					}
					
					vt_msv=0; vt_ho=0; vt_ten=0; vt_phai=0; vt_pw=0, vt_pwcf=0;
					sv.masv[vt_msv]='\0'; sv.ho[vt_ho]='\0'; sv.ten[vt_ten]='\0'; sv.phai[vt_phai]='\0'; sv.password[vt_pw]='\0'; pwcf[vt_pwcf]='\0';	
					
					fastClear(start,dai,rong,col_right,row_bottom);
					clearPartOfScreen(start.x+rong-col_right+1,start.y+6,start.x+rong-1,start.y+dai-3);						//Clear DSSV con
					return;
					
				}else{
					gotoxy(start.x+x_esc,start.y+(dai-row_bottom)+3);
					printf("PASSWORD KHONG TRUNG KHOP! VUI LONG KIEM TRA LAI!");  Sleep(1000);
					clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+3,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom					
					goto CONFIRM_PASSWORD;
				}
				
			}
			if(key==27){        //ESC
				vt_msv=0; vt_ho=0; vt_ten=0; vt_phai=0; vt_pw=0, vt_pwcf=0;
				sv.masv[vt_msv]='\0'; sv.ho[vt_ho]='\0'; sv.ten[vt_ten]='\0'; sv.phai[vt_phai]='\0'; sv.password[vt_pw]='\0'; pwcf[vt_pwcf]='\0';				
				fastClear(start,dai,rong,col_right,row_bottom);
				return;
			}
			if(key==0){
				key=getch();
				if(key==59){
					vt_msv=0; vt_ho=0; vt_ten=0; vt_phai=0; vt_pw=0, vt_pwcf=0;
					sv.masv[vt_msv]='\0'; sv.ho[vt_ho]='\0'; sv.ten[vt_ten]='\0'; sv.phai[vt_phai]='\0'; sv.password[vt_pw]='\0'; pwcf[vt_pwcf]='\0';				
					fastClear(start,dai,rong,col_right,row_bottom);
					return;
				}
			}
			if(key==-32){       
				key=getch();
				if(key==72){		  //UP
					goto PASSWORD;
				}else{				
					gotoxy(start.x+20+vt_pwcf,start.y+18);
				}
			}
		}									
}
void Input_SV(DSLOP *dslop){
	systemCls();	
	
	OBJECR_LCT start; start.x=3; start.y=3;
	int dai=48, rong=160, col_right=rong/2+22, row_bottom=14, x_esc=3, y_esc=4;
	Khung_Nhap_SV(start,dai,rong,col_right,row_bottom);	
	
	if(dslop->n==0){
		gotoxy(start.x+rong-col_right+col_right/2-23,start.y+4);
		colorText(236); printf("DANH SACH LOP RONG! VUI LONG QUAY LAI NHAP LOP!"); clearColor(); Sleep(3000); return;	
	}		
	
	SINHVIEN sv; NODESINHVIEN First;  InitDSSV(First);	
	char key, maLop[MAXML], pwcf[MAXPW]; int slsv, page=0, arrow=0;
	int vt_ml=0, vt_msv=0, vt_ho=0, vt_ten=0, vt_phai=0, vt_pw=0, vt_pwcf=0;		

	maLop[vt_ml]='\0';
	sv.masv[vt_msv]='\0';
	sv.ho[vt_ho]='\0';
	sv.ten[vt_ten]='\0';
	sv.phai[vt_phai]='\0';
	sv.password[vt_pw]='\0';
	sv.dsdiem=NULL;		
	
MALOP:	
		clearPartOfScreen(start.x+rong-col_right+1,start.y+2,start.x+rong-1,start.y+dai-3);			//ClearDSSV		
		gotoxy(start.x+x_esc,start.y+(dai-row_bottom)+1);
		printf("MALOP: TOI DA %d KY TU, BAO GOM A-Z, a-z, 0-9 DAU '-'",MAXML);				
		gotoxy(start.x+14+vt_ml,start.y+3);
		while(1){
			key=getch();
			if(key>=65&&key<=90||key>=97&&key<=122||key>=48&&key<=57||key==45){ //A-Z a-z 0-9
				if(vt_ml<MAXML){
					maLop[vt_ml]=(char)key;
					maLop[vt_ml]=toupper(maLop[vt_ml]);
					gotoxy(start.x+14+vt_ml,start.y+3);
					printf("%c",maLop[vt_ml]);
					vt_ml++;
				}else{					
					gotoxy(start.x+14+vt_ml,start.y+3);
					printf(" ");
					gotoxy(start.x+14+vt_ml,start.y+3);
				}
			}
			if(key==8&&vt_ml>0){   //BACKSPACE
				vt_ml--;
				gotoxy(start.x+14+vt_ml,start.y+3);
				printf(" ");
				gotoxy(start.x+14+vt_ml,start.y+3);
			}
			if(key==13&&vt_ml!=0){ //ENTER												
				maLop[vt_ml]='\0';
				if(trungML(dslop,maLop,First)){
					gotoxy(start.x+14,start.y+3); printf("%s",maLop);						
					DSSV(dslop,maLop,First,page,arrow,start,dai,rong,col_right,row_bottom,x_esc,y_esc);
					goto MASV;
				}else{
					gotoxy(start.x+x_esc,start.y+(dai-row_bottom)+3);
					printf("MALOP KHONG TON TAI!!! VUI LONG NHAP LAI MA LOP!");  Sleep(1000);
					clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+3,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
					clearPartOfScreen(start.x+14,start.y+3,start.x+14+MAXML,start.y+3); vt_ml=0;
					goto MALOP;
				}
			}
			if(key==27){        //ESC
				if(NOTICE(start.x+x_esc,start.y+(dai-row_bottom)+y_esc,"Quay lai MENU?")){
					return;
				}else{
					clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
					goto MALOP;
				}
			}
			if(key==-32){       
				key=getch();
				if(key==80&&vt_ml!=0){
					maLop[vt_ml]='\0';
					if(trungML(dslop,maLop,First)){
						gotoxy(start.x+14,start.y+3); printf("%s",maLop);						
						DSSV(dslop,maLop,First,page,arrow,start,dai,rong,col_right,row_bottom,x_esc,y_esc);
						goto MASV;
					}else{
						gotoxy(start.x+x_esc,start.y+(dai-row_bottom)+3);
						printf("MALOP KHONG TON TAI!!! VUI LONG NHAP LAI MA LOP!");  Sleep(1000);
						clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+3,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
						clearPartOfScreen(start.x+14,start.y+3,start.x+14+MAXML,start.y+3); vt_ml=0;
						goto MALOP;
					}
				}else{
					gotoxy(start.x+14+vt_ml,start.y+3);	
				}				
			}
		}
		
MASV:	inDSSV(First,page,arrow,countSV(First),start.x+rong-col_right+3,start.y+6);		
		gotoxy(start.x+x_esc,start.y+dai-row_bottom-2); printf("BAN DANG 'THEM' SINH VIEN");
		gotoxy(start.x+x_esc,start.y+(dai-row_bottom)+1);
		printf("MSSV: TOI DA %d KY TU, BAO GOM A-Z, a-z, 0-9",MAXMSV);
		gotoxy(start.x+20+vt_msv,start.y+8);
		while(1){
			key=getch();
			if(key>=65&&key<=90||key>=97&&key<=122||key>=48&&key<=57){ //A-Z a-z 0-9
				if(vt_msv<MAXMSV){
					sv.masv[vt_msv]=(char)key;
					sv.masv[vt_msv]=toupper(sv.masv[vt_msv]);
					gotoxy(start.x+20+vt_msv,start.y+8);
					printf("%c",sv.masv[vt_msv]);
					vt_msv++;
				}else{					
					gotoxy(start.x+20+vt_msv,start.y+8);
					printf(" ");
					gotoxy(start.x+20+vt_msv,start.y+8);
				}
			}
			if(key==8&&vt_msv>0){   //BACKSPACE
				vt_msv--;
				gotoxy(start.x+20+vt_msv,start.y+8);
				printf(" ");
				gotoxy(start.x+20+vt_msv,start.y+8);
			}
			if(key==13&&vt_msv!=0){ //ENTER
				sv.masv[vt_msv]='\0';			 
				//ktra Masv bi trung
				if(trungMSV(dslop,sv.masv)){
					gotoxy(start.x+x_esc,start.y+(dai-row_bottom)+3);
					printf("MASV DA TON TAI!!! NHAP LAI MSV!");  Sleep(1000);
					clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+3,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
					//nhap lai masv					
					goto MASV;					
				}else{
					clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
					goto HO;					
				}							
			}
			if(key==27){        //ESC
				if(NOTICE(start.x+x_esc,start.y+(dai-row_bottom)+y_esc,"Quay lai MENU?")){
					return;
				}else{
					clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
					goto MASV;
				}
			}
			if(key==0){
				key=getch();
				if(key==59){
					vt_msv=0; vt_ho=0; vt_ten=0; vt_phai=0; vt_pw=0, vt_pwcf=0;
					sv.masv[vt_msv]='\0'; sv.ho[vt_ho]='\0'; sv.ten[vt_ten]='\0'; sv.phai[vt_phai]='\0'; sv.password[vt_pw]='\0'; pwcf[vt_pwcf]='\0';				
					fastClear(start,dai,rong,col_right,row_bottom);
					clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
					if(DSSV(dslop,maLop,First,page,arrow,start,dai,rong,col_right,row_bottom,x_esc,y_esc)==-1) goto MASV;								
				}
			}
			if(key==-32){       
				key=getch();
				if(key==72){				//UP
					clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
					goto MALOP;
				}
				if(key==80&&vt_msv!=0){		//DOWN
					sv.masv[vt_msv]='\0';			 
					//ktra Masv bi trung
					if(trungMSV(dslop,sv.masv)){
						gotoxy(start.x+x_esc,start.y+(dai-row_bottom)+3);
						printf("MASV DA TON TAI!!! NHAP LAI MSV!");  Sleep(1000);
						clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+3,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
						//nhap lai masv					
						goto MASV;					
					}else{
						clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
						goto HO;					
					}	
				}				
				else{
					gotoxy(start.x+20+vt_msv,start.y+8);
				}
			}
		}
HO:		
		gotoxy(start.x+x_esc,start.y+(dai-row_bottom)+1);
		printf("HO: TOI DA %d KY TU, BAO GOM A-Z, a-z, Khoang Trang",MAXHOSV);
		gotoxy(start.x+20+vt_ho,start.y+10);
		while(1){
			key=getch();
			if(key>=65&&key<=90||key>=97&&key<=122||key==32){ //A-Z a-z 0-9
				if(vt_ho<MAXHOSV){
					sv.ho[vt_ho]=(char)key;
					gotoxy(start.x+20+vt_ho,start.y+10);
					printf("%c",sv.ho[vt_ho]);
					vt_ho++;
				}else{					
					gotoxy(start.x+20+vt_ho,start.y+10);
					printf(" ");
					gotoxy(start.x+20+vt_ho,start.y+10);
				}
			}
			if(key==8&&vt_ho>0){   //BACKSPACE
				vt_ho--;
				gotoxy(start.x+20+vt_ho,start.y+10);
				printf(" ");
				gotoxy(start.x+20+vt_ho,start.y+10);
			}
			if(key==13&&vt_ho!=0){ //ENTER
				clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
				goto TEN;
			}
			if(key==27){           //ESC
				if(NOTICE(start.x+x_esc,start.y+(dai-row_bottom)+y_esc,"Quay lai MENU?")){
					return;
				}else{
					clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
					goto HO;
				}
			}
			if(key==0){
				key=getch();
				if(key==59){
					vt_msv=0; vt_ho=0; vt_ten=0; vt_phai=0; vt_pw=0, vt_pwcf=0;
					sv.masv[vt_msv]='\0'; sv.ho[vt_ho]='\0'; sv.ten[vt_ten]='\0'; sv.phai[vt_phai]='\0'; sv.password[vt_pw]='\0'; pwcf[vt_pwcf]='\0';				
					fastClear(start,dai,rong,col_right,row_bottom);
					clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
					if(DSSV(dslop,maLop,First,page,arrow,start,dai,rong,col_right,row_bottom,x_esc,y_esc)==-1) goto MASV;
				}
			}
			if(key==-32){       
				key=getch();
				if(key==72){		              //UP
					clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
					goto MASV;
				}else if(key==80&&vt_ho!=0){	  //DOWN
					clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
					goto TEN;
				}else{
					gotoxy(start.x+20+vt_ho,start.y+10);
				}
			}
		}	
TEN:	
		gotoxy(start.x+x_esc,start.y+(dai-row_bottom)+1);
		printf("TEN: TOI DA %d KY TU, BAO GOM A-Z, a-z, Khoang Trang",MAXTENSV);
		gotoxy(start.x+20+vt_ten,start.y+12);
		while(1){
			key=getch();
			if(key>=65&&key<=90||key>=97&&key<=122){ //A-Z a-z
				if(vt_ten<MAXTENSV){
					sv.ten[vt_ten]=(char)key;
					gotoxy(start.x+20+vt_ten,start.y+12);
					printf("%c",sv.ten[vt_ten]);
					vt_ten++;
				}else{					
					gotoxy(start.x+20+vt_ten,start.y+12);
					printf(" ");
					gotoxy(start.x+20+vt_ten,start.y+12);
				}
			}
			if(key==8&&vt_ten>0){   //BACKSPACE
				vt_ten--;
				gotoxy(start.x+20+vt_ten,start.y+12);
				printf(" ");
				gotoxy(start.x+20+vt_ten,start.y+12);
			}
			if(key==13&&vt_ten!=0){ //ENTER
				clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
				goto PHAI;
			}
			if(key==27){           //ESC
				if(NOTICE(start.x+x_esc,start.y+(dai-row_bottom)+y_esc,"Quay lai MENU?")){
					return;
				}else{
					clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
					goto TEN;
				}
			}
			if(key==0){
				key=getch();
				if(key==59){
					vt_msv=0; vt_ho=0; vt_ten=0; vt_phai=0; vt_pw=0, vt_pwcf=0;
					sv.masv[vt_msv]='\0'; sv.ho[vt_ho]='\0'; sv.ten[vt_ten]='\0'; sv.phai[vt_phai]='\0'; sv.password[vt_pw]='\0'; pwcf[vt_pwcf]='\0';				
					fastClear(start,dai,rong,col_right,row_bottom);
					clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
					if(DSSV(dslop,maLop,First,page,arrow,start,dai,rong,col_right,row_bottom,x_esc,y_esc)==-1) goto MASV;
				}
			}
			if(key==-32){
				key=getch();
				if(key==72){		  //UP
					clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
					goto HO;
				}else if(key==80&&vt_ten!=0){	  //DOWN
					clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
					goto PHAI;
				}else{
					gotoxy(start.x+20+vt_ten,start.y+12);
				}
			}
		}
PHAI:	
		gotoxy(start.x+x_esc,start.y+(dai-row_bottom)+1);
		printf("PHAI: TOI DA %d KY TU, BAO GOM A-Z, a-z",MAXPHAI);
		gotoxy(start.x+20+vt_phai,start.y+14);
		while(1){
			key=getch();
			if(key>=65&&key<=90||key>=97&&key<=122||key>=48&&key<=57){ //A-Z a-z 0-9
				if(vt_phai<MAXPHAI){
					sv.phai[vt_phai]=(char)key;
					gotoxy(start.x+20+vt_phai,start.y+14);
					printf("%c",sv.phai[vt_phai]);
					vt_phai++;
				}else{					
					gotoxy(start.x+20+vt_phai,start.y+14);
					printf(" ");
					gotoxy(start.x+20+vt_phai,start.y+14);
				}
			}
			if(key==8&&vt_phai>0){   //BACKSPACE
				vt_phai--;
				gotoxy(start.x+20+vt_phai,start.y+14);
				printf(" ");
				gotoxy(start.x+20+vt_phai,start.y+14);
			}
			if(key==13&&vt_phai!=0){ //ENTER	
				sv.phai[vt_phai]='\0';			
				if(stricmp(sv.phai,"nam")==0||stricmp(sv.phai,"nu")==0||stricmp(sv.phai,"male")==0||stricmp(sv.phai,"female")==0){
					clearPartOfScreen(start.x+1,start.y+dai-row_bottom-2,start.x+rong-col_right-1,start.y+dai-row_bottom-2);	//ClearTHEMSUA
					goto PASSWORD;
				}else{					
					gotoxy(start.x+x_esc,start.y+(dai-row_bottom)+3);
					printf("PHAI LA: 'NU' HOAC 'NAM' HOAC 'FEMALE' HOAC 'MALE'!");
					clearPartOfScreen(start.x+20,start.y+14,start.x+20+MAXPHAI,start.y+14);
					vt_phai=0; goto PHAI;
				}
			}
			if(key==27){        //ESC
				if(NOTICE(start.x+x_esc,start.y+(dai-row_bottom)+y_esc,"Quay lai MENU?")){
					return;
				}else{
					clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
					goto PHAI;
				}
			}
			if(key==0){
				key=getch();
				if(key==59){
					vt_msv=0; vt_ho=0; vt_ten=0; vt_phai=0; vt_pw=0, vt_pwcf=0;
					sv.masv[vt_msv]='\0'; sv.ho[vt_ho]='\0'; sv.ten[vt_ten]='\0'; sv.phai[vt_phai]='\0'; sv.password[vt_pw]='\0'; pwcf[vt_pwcf]='\0';				
					fastClear(start,dai,rong,col_right,row_bottom);
					clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
					if(DSSV(dslop,maLop,First,page,arrow,start,dai,rong,col_right,row_bottom,x_esc,y_esc)==-1) goto MASV;
				}
			}
			if(key==-32){       
				key=getch();
				if(key==72){		  //UP
					clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
					goto TEN;
				}else if(key==80&&vt_phai!=0){	  //DOWN
					sv.phai[vt_phai]='\0';			
					if(stricmp(sv.phai,"nam")==0||stricmp(sv.phai,"nu")==0||stricmp(sv.phai,"male")==0||stricmp(sv.phai,"female")==0){
						clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
						goto PASSWORD;
					}else{					
						gotoxy(start.x+x_esc,start.y+(dai-row_bottom)+3);
						printf("PHAI LA: 'NU' HOAC 'NAM' HOAC 'FEMALE' HOAC 'MALE'!");
						clearPartOfScreen(start.x+20,start.y+14,start.x+20+MAXPHAI,start.y+14);
						vt_phai=0; goto PHAI;
					}
				}else{
					gotoxy(start.x+20+vt_phai,start.y+14);
				}
			}
		}	
PASSWORD:	
		gotoxy(start.x+x_esc,start.y+(dai-row_bottom)+1);
		printf("PASSWORD: TOI DA %d KY TU, BAO GOM A-Z, a-z, 0-9", MAXPW);
		gotoxy(start.x+20+vt_pw,start.y+16);
		while(1){
			key=getch();
			if(key>=65&&key<=90||key>=97&&key<=122||key>=48&&key<=57){ //A-Z a-z 0-9
				if(vt_pw<MAXPW){
					sv.password[vt_pw]=(char)key;
					gotoxy(start.x+20+vt_pw,start.y+16);
					printf("%c",sv.password[vt_pw]);
					vt_pw++;
				}else{					
					gotoxy(start.x+20+vt_pw,start.y+16);
					printf(" ");
					gotoxy(start.x+20+vt_pw,start.y+16);
				}
			}
			if(key==8&&vt_pw>0){   //BACKSPACE
				vt_pw--;
				gotoxy(start.x+20+vt_pw,start.y+16);
				printf(" ");
				gotoxy(start.x+20+vt_pw,start.y+16);
			}
			if(key==13&&vt_pw!=0){ //ENTER																												
				goto CONFIRM_PASSWORD;	
			}
			if(key==27){        //ESC
				if(NOTICE(start.x+x_esc,start.y+(dai-row_bottom)+y_esc,"Quay lai MENU?")){
					return;
				}else{
					clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
					goto PASSWORD;
				}
			}
			if(key==0){
				key=getch();
				if(key==59){
					vt_msv=0; vt_ho=0; vt_ten=0; vt_phai=0; vt_pw=0, vt_pwcf=0;
					sv.masv[vt_msv]='\0'; sv.ho[vt_ho]='\0'; sv.ten[vt_ten]='\0'; sv.phai[vt_phai]='\0'; sv.password[vt_pw]='\0'; pwcf[vt_pwcf]='\0';				
					fastClear(start,dai,rong,col_right,row_bottom);
					clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
					if(DSSV(dslop,maLop,First,page,arrow,start,dai,rong,col_right,row_bottom,x_esc,y_esc)==-1) goto MASV;
				}
			}
			if(key==-32){       
				key=getch();
				if(key==72){		  //UP
					clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
					goto PHAI;
				}else if(key==80&&vt_pw!=0){    //DOWN
					goto CONFIRM_PASSWORD;
				}else{				
					gotoxy(start.x+20+vt_pw,start.y+16);
				}
			}
		}
CONFIRM_PASSWORD:
		gotoxy(start.x+20+vt_pwcf,start.y+18);		
		while(1){
			key=getch();
			if(key>=65&&key<=90||key>=97&&key<=122||key>=48&&key<=57){ //A-Z a-z 0-9
				if(vt_pwcf<MAXPW){
					pwcf[vt_pwcf]=(char)key;
					gotoxy(start.x+20+vt_pwcf,start.y+18);
					printf("%c",pwcf[vt_pwcf]);
					vt_pwcf++;
				}else{					
					gotoxy(start.x+20+vt_pwcf,start.y+18);
					printf(" ");
					gotoxy(start.x+20+vt_pwcf,start.y+18);
				}
			}
			if(key==8&&vt_pwcf>0){   //BACKSPACE
				vt_pwcf--;
				gotoxy(start.x+20+vt_pwcf,start.y+18);
				printf(" ");
				gotoxy(start.x+20+vt_pwcf,start.y+18);
			}
			if(key==13&&vt_pwcf!=0){ //ENTER
			
				sv.password[vt_pw]='\0'; pwcf[vt_pwcf]='\0';
				if(strcmp(sv.password,pwcf)==0){
					//savesv?		
					if(NOTICE(start.x+x_esc,start.y+(dai-row_bottom)+y_esc,"Luu Sinh Vien nay?")){
						sv.masv[vt_msv]='\0'; sv.ho[vt_ho]='\0'; delspace(sv.ho); vietHoaChuCaiDau(sv.ho);
						sv.ten[vt_ten]='\0'; vietHoaChuCaiDau(sv.ten);
						sv.phai[vt_phai]='\0'; vietHoaChuCaiDau(sv.phai);
						sv.password[vt_pw]='\0'; sv.dsdiem=NULL;						
						for(int i=0;i<dslop->n;i++){
							if(stricmp(dslop->lop[i]->malop,maLop)==0){
								Insert_Last_SV(First,sv);
								sapxepSV(First);
								dslop->lop[i]->dssinhvien=First;
								break;
							}
						}					
						saveDSLop(dslop);																
					}
					
					vt_msv=0; vt_ho=0; vt_ten=0; vt_phai=0; vt_pw=0, vt_pwcf=0;
					sv.masv[vt_msv]='\0'; sv.ho[vt_ho]='\0'; sv.ten[vt_ten]='\0'; sv.phai[vt_phai]='\0'; sv.password[vt_pw]='\0'; pwcf[vt_pwcf]='\0';	
									
					//nextsv?
					if(NOTICE(start.x+x_esc+25,start.y+(dai-row_bottom)+y_esc,"Nhap tiep Sinh Vien?")){
						fastClear(start,dai,rong,col_right,row_bottom);
						clearPartOfScreen(start.x+rong-col_right+1,start.y+6,start.x+rong-1,start.y+dai-3);						//Clear DSSV con			
						goto MASV;
					}else{
						vt_ml=0; maLop[vt_ml]='\0';
						clearPartOfScreen(start.x+13,start.y+3,start.x+13+MAXML,start.y+3);
						fastClear(start,dai,rong,col_right,row_bottom);
						clearPartOfScreen(start.x+rong-col_right+1,start.y+6,start.x+rong-1,start.y+dai-3);						//Clear DSSV con
						if(DSSV(dslop,maLop,First,page,arrow,start,dai,rong,col_right,row_bottom,x_esc,y_esc)==-1) goto MALOP;
					}
				}else{
					gotoxy(start.x+x_esc,start.y+(dai-row_bottom)+3);
					printf("PASSWORD KHONG TRUNG KHOP! VUI LONG KIEM TRA LAI!");  Sleep(1000);
					clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+3,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom					
					goto CONFIRM_PASSWORD;
				}
				
			}
			if(key==27){        //ESC
				if(NOTICE(start.x+x_esc,start.y+(dai-row_bottom)+y_esc,"Quay lai MENU?")){
					return;
				}else{
					clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
					goto CONFIRM_PASSWORD;
				}
			}
			if(key==0){
				key=getch();
				if(key==59){
					vt_msv=0; vt_ho=0; vt_ten=0; vt_phai=0; vt_pw=0, vt_pwcf=0;
					sv.masv[vt_msv]='\0'; sv.ho[vt_ho]='\0'; sv.ten[vt_ten]='\0'; sv.phai[vt_phai]='\0'; sv.password[vt_pw]='\0'; pwcf[vt_pwcf]='\0';				
					fastClear(start,dai,rong,col_right,row_bottom);
					clearPartOfScreen(start.x+1,start.y+(dai-row_bottom)+1,start.x+(rong-col_right)-1,start.y+dai-3);  //row_bottom
					if(DSSV(dslop,maLop,First,page,arrow,start,dai,rong,col_right,row_bottom,x_esc,y_esc)==-1) goto MASV;
				}
			}
			if(key==-32){       
				key=getch();
				if(key==72){		  //UP
					goto PASSWORD;
				}else{				
					gotoxy(start.x+20+vt_pwcf,start.y+18);
				}
			}
		}						
}


//------------------------------------DANH SACH CAU HOI-----------------------------------------


void Khung_Nhap_DSCH(OBJECR_LCT start, int dai, int rong){
	OBJECR_LCT title; title.x=start.x+rong/2-7; title.y=start.y-3;
	makeTable_Type2(title,2,15);
	gotoxy(title.x+2,title.y+1); printf("NHAP CAU HOI");
	makeTable_Type2(start,dai,rong);	
	gotoxy(start.x+1,start.y+1);printf("Nhap Ma Mon: ");
	gotoxy(start.x+rong/2-7,start.y+1);printf("ID CAU HOI: ");
	gotoxy(start.x+1,start.y+3);printf("Nhap Noi dung cau hoi: ");
	gotoxy(start.x+1,start.y+21);printf("Nhap Dap an A: ");
	gotoxy(start.x+1,start.y+26);printf("Nhap Dap an B: ");
	gotoxy(start.x+1,start.y+31);printf("Nhap Dap an C: ");
	gotoxy(start.x+1,start.y+36);printf("Nhap Dap an D: ");
	gotoxy(start.x+1,start.y+41);printf("Nhap Ket qua: ");
	gotoxy(start.x+rong/2,start.y+dai-5); printf("|");
	for(int i=1;i<rong;i++){
		gotoxy(start.x+i,start.y+dai-6);
		printf("-");		
		gotoxy(start.x+i,start.y+dai-4);
		printf("-");		
	}
	saveButton(start.x+rong/2-4,start.y+dai+1);
}

void InitDSCH(NODECAUHOI &root){
    root = NULL;
}

int EmptyDSCH(NODECAUHOI root){
	return (root==NULL ? true : false);
}

void FreeDSCH(NODECAUHOI &root){
	if(root==NULL) return;
	FreeDSCH(root->left);
	FreeDSCH(root->right);
	FreeDSCH(root);
}

void Insert_node(NODECAUHOI &root, CAUHOI cauhoi){
	if(root == NULL){    // p la nut la
		root =  (nodecauhoi*)(malloc(sizeof(nodecauhoi)));
	    root->cauhoi = cauhoi;
	    root->left = NULL;     root->right = NULL;
	}else{	   
	    if(cauhoi.id < (root->cauhoi.id )) {Insert_node((root->left),cauhoi);}
		else if(cauhoi.id > (root->cauhoi.id )) {Insert_node((root->right),cauhoi);}
	}
}
bool searchAndReturnCH(NODECAUHOI root, int iD, CAUHOI &ch){
	if(root==NULL) return false;
	if(root->cauhoi.id==iD){
		ch.id=iD;
		strcpy(ch.mamh,root->cauhoi.mamh);
		strcpy(ch.nd,root->cauhoi.nd);
		strcpy(ch.a,root->cauhoi.a);
		strcpy(ch.b,root->cauhoi.b);
		strcpy(ch.c,root->cauhoi.c);
		strcpy(ch.d,root->cauhoi.d);
		ch.da=root->cauhoi.da;
		return true;
	}
	else if(iD < root->cauhoi.id){
		return searchAndReturnCH(root->left,iD,ch);
	}else if(iD>root->cauhoi.id){
		return searchAndReturnCH(root->right,iD,ch);
	}
}

CAUHOI leftMostCH(NODECAUHOI root){
	while(root->left!=NULL){ root=root->left;}
	return root->cauhoi;
}
void deleteNodeCH(NODECAUHOI &root, CAUHOI ch){
	if(root==NULL)
	if(ch.id < root->cauhoi.id){
		deleteNodeCH(root->left,ch);
	}else if(ch.id > root->cauhoi.id){
		deleteNodeCH(root->right,ch);
	}else{
		if(root->left==NULL){
			NODECAUHOI newRoot = root->right;
//			free(root);
			root = newRoot;
		}
		if(root->right==NULL){
			NODECAUHOI newRoot = root->left;
//			free(root);
			root = newRoot;
		}
		root->cauhoi = leftMostCH(root->right);
		deleteNodeCH(root->right,root->cauhoi);
	}
}

bool searchAndUpdateDSCH(NODECAUHOI root, CAUHOI ch){
	int  STACKSIZE = 500, sp=-1;
	bool update = false;
	NODECAUHOI p = new nodecauhoi;
	NODECAUHOI tmp = new nodecauhoi;
	NODECAUHOI Stack[STACKSIZE]; p=root;tmp = p;
	do{
		while(p!=NULL){
			Stack[++sp]= p;
			p= p->left;
		}
		if(sp != -1){
			p=Stack[sp--];
			if(p->cauhoi.id==ch.id){
				strcpy(p->cauhoi.mamh,ch.mamh);
				strcpy(p->cauhoi.nd,ch.nd);
				strcpy(p->cauhoi.a,ch.a);
				strcpy(p->cauhoi.b,ch.b);
				strcpy(p->cauhoi.c,ch.c);
				strcpy(p->cauhoi.d,ch.d);
				p->cauhoi.da=ch.da;					
				update = true;
			}
			p=p->right;
		}else break;
	}while(1);
	root=tmp;	
	
	return update;
}

int CheckID(NODECAUHOI root, int iD){
	if(root==NULL) return 0;
	else if(root->cauhoi.id == iD) return 1;
	else if(root->cauhoi.id < iD){ return CheckID(root->right,iD);}
	else{return CheckID(root->left,iD);}printf("here");
}

int Random(){
	srand(time(NULL));
	int x;
	for(int i=0;i<MAXID;i++){
		x=rand();
	}
	return x;
}

int RandomID(NODECAUHOI root){
	int temp;
	do{
		temp=Random();
	}while(CheckID(root,temp));
	return temp;
}

void inorder(NODECAUHOI p){
	if(p != NULL){
		inorder(p->left);		
		printf("%d %s %s %s %s %s %s %c\n",p->cauhoi.id,p->cauhoi.mamh,p->cauhoi.nd,p->cauhoi.a,p->cauhoi.b,p->cauhoi.c,p->cauhoi.d,p->cauhoi.da);
		inorder(p->right);
	}   	
}

void Input_CH(NODECAUHOI &root, DSMON *dsmon){
	systemCls();
	CAUHOI ch;
	int vtmm=0, vtnd=0,xnd=0,ynd=0, vta=0,xa=0,ya=0, vtb=0,xb=0,yb=0, vtc=0,xc=0,yc=0, vtd=0,xd=0,yd=0; char key;
	
	OBJECR_LCT start; start.x=10; start.y=4; int dai=48, rong=150;
	Khung_Nhap_DSCH(start,dai,rong);
	
	ch.mamh[vtmm]='\0';
	ch.nd[vtnd]='\0';
	ch.a[vta]='\0';
	ch.b[vtb]='\0';
	ch.c[vtc]='\0';
	ch.d[vtd]='\0';
	ch.da=NULL;
	
ID:	while(1){
		ch.id=RandomID(root);
		gotoxy(start.x+rong/2+5,start.y+1);
		printf("%d",ch.id);
		goto MAMON;
	}		
	
MAMON:
	gotoxy(start.x+(rong/2)/2-20,start.y+dai-5);
	printf("MA MON: TOI DA %d KY TU, BAO GOM A-Z, a-z, 0-9",MAXMMH);
	gotoxy(start.x+14+vtmm,start.y+1);
	while(1){
		key=getch();
		if(key>=65&&key<=90||key>=97&&key<=122||key>=48&&key<=57){
			if(vtmm<MAXMMH){
				ch.mamh[vtmm]=(char)key;
				ch.mamh[vtmm]=toupper(ch.mamh[vtmm]);
				gotoxy(start.x+14+vtmm,start.y+1);
				printf("%c",ch.mamh[vtmm]);
				vtmm++;
			}else{
				gotoxy(start.x+14+vtmm,start.y+1);
				printf(" ");
				gotoxy(start.x+14+vtmm,start.y+1);
			}
		}
		if(key==8&&vtmm>0){
			vtmm--;
			gotoxy(start.x+14+vtmm,start.y+1);
			printf(" ");
			gotoxy(start.x+14+vtmm,start.y+1);
		}
		if(key==13&&vtmm!=0){
			ch.mamh[vtmm]='\0';
			if(trungMaMon(ch.mamh,dsmon)){
				goto NDCH;				
			}else{
				gotoxy(start.x+rong/2+17,start.y+dai-5);
				printf("MA MON KHONG TON TAI! NHAP LAI MA MON!"); Sleep(1000);
				clearPartOfScreen(start.x+rong/2+1,start.y+dai-5,start.x+rong-1,start.y+dai-5);
				goto MAMON;
			}			
		}
		if(key==27){
			if(NOTICE(start.x+(rong/2)/2-20,start.y+dai-3,"Ban muon thoat khong?")){
				vtmm=0; ch.mamh[vtmm]='\0';
				return;				
			}else{
				clearPartOfScreen(start.x+1,start.y+dai-3,start.x+rong-1,start.y+dai-1);
				goto MAMON;
			}
		}
		if(key==-32){       
			key=getch();
			if(key==80&&vtmm!=0){
				ch.mamh[vtmm]='\0';
				if(trungMaMon(ch.mamh,dsmon)){
					goto NDCH;				
				}else{
					gotoxy(start.x+rong/2+17,start.y+dai-5);
					printf("MA MON KHONG TON TAI! NHAP LAI MA MON!"); Sleep(1000);
					clearPartOfScreen(start.x+rong/2+1,start.y+dai-5,start.x+rong-1,start.y+dai-5);
					goto MAMON;
				}		
			}else{
				gotoxy(start.x+14+vtmm,start.y+1);
			}
		}
	}
NDCH:
	gotoxy(start.x+(rong/2)/2-20,start.y+dai-5);
	printf("NDCH: TOI DA %d KY TU",MAX_QST_CNT);
	if(vtnd<=rong-1-24){
		gotoxy(start.x+24+vtnd,start.y+3);	
	}else{
		gotoxy(start.x+1+xnd,start.y+3+ynd);
	}
	
	while(1){
		key=getch();
		if(key>=32&&key<=126){
			if(vtnd<MAX_QST_CNT){
				ch.nd[vtnd]=(char)key;
				if(vtnd<=rong-1-24){					
					gotoxy(start.x+24+vtnd,start.y+3);
					printf("%c",ch.nd[vtnd]);
					if(vtnd==rong-1-24){ynd++;}					
				}else{
					if(xnd<=rong-1){
						if(xnd==rong-1){xnd=0;ynd++;}
						gotoxy(start.x+1+xnd,start.y+3+ynd);
						printf("%c",ch.nd[vtnd]);
						xnd++;
					}					
				}
				vtnd++;
			}
		}
		if(key==8&&vtnd>0){	
			vtnd--;	
			if(vtnd<=rong-1-24){
				xnd=0;ynd=0;				
				gotoxy(start.x+24+vtnd,start.y+3);
				printf(" ");
				gotoxy(start.x+24+vtnd,start.y+3);	
			}else{
				if(xnd>=0&&ynd>=0){
					xnd--;
					if(xnd>0){
						gotoxy(start.x+1+xnd,start.y+3+ynd);
						printf(" ");
						gotoxy(start.x+1+xnd,start.y+3+ynd);						
					}
					if(xnd==0){
						gotoxy(start.x+1+xnd,start.y+3+ynd);
						printf(" ");
						gotoxy(start.x+1+xnd,start.y+3+ynd);
						xnd=rong-1;
						ynd--;
					}
				}				
			}			
		}
		if(key==13&&vtnd!=0){
			clearPartOfScreen(start.x+1,start.y+dai-5,start.x+rong/2-1,start.y+dai-5);
			goto DAA;
		}
		if(key==27){
			if(NOTICE(start.x+(rong/2)/2-20,start.y+dai-3,"Ban muon thoat khong?")){
				return;				
			}else{
				clearPartOfScreen(start.x+1,start.y+dai-3,start.x+rong-1,start.y+dai-1);
				goto NDCH;
			}
		}
		if(key==-32){
			key=getch();
			if(key==72){
				clearPartOfScreen(start.x+1,start.y+dai-5,start.x+rong/2-1,start.y+dai-5);
				goto MAMON;
			}
			if(key==80&&vtnd!=0){
				clearPartOfScreen(start.x+1,start.y+dai-5,start.x+rong/2-1,start.y+dai-5);
				goto DAA;
			}
			else{
				gotoxy(start.x+24+vtnd,start.y+3);
			}
		}
	}
DAA:
	gotoxy(start.x+(rong/2)/2-20,start.y+dai-5);
	printf("DAP AN: TOI DA %d KY TU",MAX_ANS_CNT);
	if(vta<=rong-1-16){
		gotoxy(start.x+16+vta,start.y+21);	
	}else{
		gotoxy(start.x+1+xa,start.y+21+ya);
	}

	while(1){
		key=getch();
		if(key>=32&&key<=126){
			if(vta<MAX_ANS_CNT){
				ch.a[vta]=(char)key;
				if(vta<=rong-1-16){					
					gotoxy(start.x+16+vta,start.y+21);
					printf("%c",ch.a[vta]);
					if(vta==rong-1-16){ya++;}					
				}else{					
					if(xa<=rong-1&&vta<MAX_ANS_CNT){
						if(xa==rong-1){xa=0;ya++;}
						gotoxy(start.x+1+xa,start.y+21+ya);
						printf("%c",ch.a[vta]);
						xa++;
					}					
				}
				vta++;
			}
		}
		if(key==8&&vta>0){
			vta--;	
			if(vta<=rong-1-24){
				xa=0;ya=0;				
				gotoxy(start.x+16+vta,start.y+21);
				printf(" ");
				gotoxy(start.x+16+vta,start.y+21);	
			}else{
				if(xa>=0&&ya>=0){
					xa--;
					if(xa>0){
						gotoxy(start.x+1+xa,start.y+21+ya);
						printf(" ");
						gotoxy(start.x+1+xa,start.y+21+ya);						
					}
					if(xa==0){
						gotoxy(start.x+1+xa,start.y+21+ya);
						printf(" ");
						gotoxy(start.x+1+xa,start.y+21+ya);
						xa=rong-1;
						ya--;
					}
				}				
			}			
		}
		if(key==13&&vta!=0){
			goto DAB;
		}
		if(key==27){
			if(NOTICE(start.x+(rong/2)/2-20,start.y+dai-3,"Ban muon thoat khong?")){
				return;
			}else{
				clearPartOfScreen(start.x+1,start.y+dai-3,start.x+rong-1,start.y+dai-1);
				goto DAA;
			}
		}
		if(key==-32){
			key=getch();
			if(key==72){
				clearPartOfScreen(start.x+1,start.y+dai-5,start.x+rong/2-1,start.y+dai-5);
				goto NDCH;
			}
			if(key==80&&vta!=0){				
				goto DAB;
			}
			else{
				gotoxy(start.x+16+vta,start.y+21);
			}
		}
	}
DAB:
	gotoxy(start.x+(rong/2)/2-20,start.y+dai-5);
	printf("DAP AN: TOI DA %d KY TU",MAX_ANS_CNT);
	if(vtb<=rong-1-16){
		gotoxy(start.x+16+vtb,start.y+26);	
	}else{
		gotoxy(start.x+1+xb,start.y+26+yb);
	}
	
	while(1){
		key=getch();
		if(key>=32&&key<=126){
			if(vtb<MAX_ANS_CNT){
				ch.b[vtb]=(char)key;
				if(vtb<=rong-1-16){					
					gotoxy(start.x+16+vtb,start.y+26);
					printf("%c",ch.b[vtb]);
					if(vtb==rong-1-16){yb++;}					
				}else{					
					if(xb<=rong-1&&vtb<MAX_ANS_CNT){
						if(xb==rong-1){xb=0;yb++;}
						gotoxy(start.x+1+xb,start.y+26+yb);
						printf("%c",ch.b[vtb]);
						xb++;
					}					
				}
				vtb++;
			}
		}
		if(key==8&&vtb>0){
			vtb--;	
			if(vtb<=rong-1-24){
				xb=0;yb=0;				
				gotoxy(start.x+16+vtb,start.y+26);
				printf(" ");
				gotoxy(start.x+16+vtb,start.y+26);	
			}else{
				if(xb>=0&&yb>=0){
					xb--;
					if(xb>0){
						gotoxy(start.x+1+xb,start.y+26+yb);
						printf(" ");
						gotoxy(start.x+1+xb,start.y+26+yb);						
					}
					if(xb==0){
						gotoxy(start.x+1+xb,start.y+26+yb);
						printf(" ");
						gotoxy(start.x+1+xb,start.y+26+yb);
						xb=rong-1;
						yb--;
					}
				}				
			}			
		}
		if(key==13&&vtb!=0){
			goto DAC;
		}
		if(key==27){
			if(NOTICE(start.x+(rong/2)/2-20,start.y+dai-3,"Ban muon thoat khong?")){
				return;
			}else{
				clearPartOfScreen(start.x+1,start.y+dai-3,start.x+rong-1,start.y+dai-1);
				goto DAB;
			}
		}
		if(key==-32){
			key=getch();
			if(key==72){				
				goto DAA;
			}
			if(key==80&&vtb!=0){
				goto DAC;
			}
			else{
				gotoxy(start.x+16+vtb,start.y+26);
			}
		}
	}
DAC:
	gotoxy(start.x+(rong/2)/2-20,start.y+dai-5);
	printf("DAP AN: TOI DA %d KY TU",MAX_ANS_CNT);
	if(vtb<=rong-1-16){
		gotoxy(start.x+16+vtc,start.y+31);
	}else{
		gotoxy(start.x+1+xc,start.y+31+yc);
	}
		
	while(1){
		key=getch();
		if(key>=32&&key<=126){
			if(vtc<MAX_ANS_CNT){
				ch.c[vtc]=(char)key;
				if(vtc<=rong-1-16){					
					gotoxy(start.x+16+vtc,start.y+31);
					printf("%c",ch.c[vtc]);
					if(vtc==rong-1-16){yc++;}					
				}else{					
					if(xc<=rong-1&&vtc<MAX_ANS_CNT){
						if(xc==rong-1){xc=0;yc++;}
						gotoxy(start.x+1+xc,start.y+31+yc);
						printf("%c",ch.c[vtc]);
						xc++;
					}					
				}
				vtc++;
			}
		}
		if(key==8&&vtc>0){
			vtc--;	
			if(vtc<=rong-1-24){
				xc=0;yc=0;				
				gotoxy(start.x+16+vtc,start.y+31);
				printf(" ");
				gotoxy(start.x+16+vtc,start.y+31);	
			}else{
				if(xc>=0&&yc>=0){
					xc--;
					if(xc>0){
						gotoxy(start.x+1+xc,start.y+31+yc);
						printf(" ");
						gotoxy(start.x+1+xc,start.y+31+yc);						
					}
					if(xc==0){
						gotoxy(start.x+1+xc,start.y+31+yc);
						printf(" ");
						gotoxy(start.x+1+xc,start.y+31+yc);
						xc=rong-1;
						yc--;
					}
				}				
			}			
		}
		if(key==13&&vtc!=0){
			goto DAD;
		}
		if(key==27){
			if(NOTICE(start.x+(rong/2)/2-20,start.y+dai-3,"Ban muon thoat khong?")){
				return;
			}else{
				clearPartOfScreen(start.x+1,start.y+dai-3,start.x+rong-1,start.y+dai-1);
				goto DAC;
			}
		}
		if(key==-32){
			key=getch();
			if(key==72){
				goto DAB;
			}
			if(key==80&&vtc!=0){
				goto DAD;
			}
			else{
				gotoxy(start.x+16+vtc,start.y+31);
			}
		}
	}
DAD:
	gotoxy(start.x+(rong/2)/2-20,start.y+dai-5);
	printf("DAP AN: TOI DA %d KY TU",MAX_ANS_CNT);
	if(vtb<=rong-1-16){
		gotoxy(start.x+16+vtd,start.y+36);
	}else{
		gotoxy(start.x+1+xd,start.y+36+yd);
	}
	
	while(1){
		key=getch();
		if(key>=32&&key<=126){
			if(vtd<MAX_ANS_CNT){
				ch.d[vtd]=(char)key;
				if(vtd<=rong-1-16){					
					gotoxy(start.x+16+vtd,start.y+36);
					printf("%c",ch.d[vtd]);
					if(vtd==rong-1-16){yd++;}					
				}else{					
					if(xd<=rong-1&&vtd<MAX_ANS_CNT){
						if(xd==rong-1){xd=0;yd++;}
						gotoxy(start.x+1+xd,start.y+36+yd);
						printf("%c",ch.d[vtd]);
						xd++;
					}					
				}
				vtd++;
			}
		}
		if(key==8&&vtd>0){
			vtd--;	
			if(vtd<=rong-1-24){
				xd=0;yd=0;				
				gotoxy(start.x+16+vtd,start.y+36);
				printf(" ");
				gotoxy(start.x+16+vtd,start.y+36);	
			}else{
				if(xd>=0&&yd>=0){
					xd--;
					if(xd>0){
						gotoxy(start.x+1+xd,start.y+31+yd);
						printf(" ");
						gotoxy(start.x+1+xd,start.y+31+yd);						
					}
					if(xd==0){
						gotoxy(start.x+1+xd,start.y+31+yd);
						printf(" ");
						gotoxy(start.x+1+xd,start.y+31+yd);
						xd=rong-1;
						yd--;
					}
				}				
			}
		}
		if(key==13&&vtd!=0){
			clearPartOfScreen(start.x+1,start.y+dai-5,start.x+rong/2-1,start.y+dai-5);
			goto KQ;
		}
		if(key==27){
			if(NOTICE(start.x+(rong/2)/2-20,start.y+dai-3,"Ban muon thoat khong?")){
				return;
			}else{
				clearPartOfScreen(start.x+1,start.y+dai-3,start.x+rong-1,start.y+dai-1);
				goto DAD;
			}
		}
		if(key==-32){
			key=getch();
			if(key==72){
				goto DAC;
			}
			if(key==80&&vtd!=0){
				clearPartOfScreen(start.x+1,start.y+dai-5,start.x+rong/2-1,start.y+dai-5);
				goto KQ;
			}
			else{
				gotoxy(start.x+16+vtd,start.y+36);
			}
		}
	}
KQ:
	gotoxy(start.x+(rong/2)/2-23,start.y+dai-5);
	printf("KET QUA: TOI DA 1 KY TU, 'A' | 'B' | 'C' | 'D'");
	if(ch.da=='\0'){
		gotoxy(start.x+16,start.y+41);
	}else{
		gotoxy(start.x+17,start.y+41);
	}
	while(1){
		key=getch();
		if(key>=65&&key<=68||key>=97&&key<=100){
			ch.da=toupper((char)key);
			gotoxy(start.x+16,start.y+41);
			printf("%c",ch.da);
		}
		if(key==8){
			gotoxy(start.x+16,start.y+41);
			printf(" ");
			gotoxy(start.x+16,start.y+41);
		}
		if(key==13&&ch.da!='\0'){
			//savech?
			enterSaveButton(start.x+rong/2-4,start.y+dai+1);
			if(NOTICE(start.x+(rong/2)/2-20,start.y+dai-3,"Ban muon luu Cau Hoi nay khong?")){
				ch.mamh[vtmm]='\0';
				ch.nd[vtnd]='\0'; delspace(ch.nd); upper_first_char(ch.nd);
				ch.a[vta]='\0'; delspace(ch.a); upper_first_char(ch.a);
				ch.b[vtb]='\0'; delspace(ch.b); upper_first_char(ch.b);
				ch.c[vtc]='\0'; delspace(ch.c); upper_first_char(ch.c);
				ch.d[vtd]='\0'; delspace(ch.d); upper_first_char(ch.d);							
				Insert_node(root,ch);
				saveDSCH(root);
			}
			
			vtnd=0,xnd=0,ynd=0, vta=0,xa=0,ya=0, vtb=0,xb=0,yb=0, vtc=0,xc=0,yc=0, vtd=0,xd=0,yd=0;
			ch.nd[vtnd]='\0'; ch.a[vta]='\0'; ch.b[vtb]='\0'; ch.c[vtc]='\0'; ch.d[vtd]='\0'; ch.da='\0';
			
			//nextch?
			if(NOTICE(start.x+rong/2+17,start.y+dai-3,"Ban muon nhap tiep khong?")){
				clearPartOfScreen(start.x+1,start.y+dai-3,start.x+rong-1,start.y+dai-1);
				gotoxy(start.x+16,start.y+41); printf(" ");
				clearPartOfScreen(start.x+1,start.y+37,start.x+rong-1,start.y+40);
				clearPartOfScreen(start.x+16,start.y+36,start.x+rong-1,start.y+36);
				clearPartOfScreen(start.x+1,start.y+32,start.x+rong-1,start.y+35);
				clearPartOfScreen(start.x+16,start.y+31,start.x+rong-1,start.y+31);
				clearPartOfScreen(start.x+1,start.y+27,start.x+rong-1,start.y+30);
				clearPartOfScreen(start.x+16,start.y+26,start.x+rong-1,start.y+26);
				clearPartOfScreen(start.x+1,start.y+22,start.x+rong-1,start.y+25);
				clearPartOfScreen(start.x+16,start.y+21,start.x+rong-1,start.y+21);
				clearPartOfScreen(start.x+1,start.y+4,start.x+rong-1,start.y+20);
				clearPartOfScreen(start.x+24,start.y+3,start.x+rong-1,start.y+3);
				clearPartOfScreen(start.x+rong/2+5,start.y+1,start.x+rong/2+15,start.y+1);				
				goto ID;
			}else{
				return;
			}							
		}
		if(key==27){
			if(NOTICE(start.x+(rong/2)/2-20,start.y+dai-3,"Ban muon thoat khong?")){
				return;
			}else{
				clearPartOfScreen(start.x+1,start.y+dai-3,start.x+rong-1,start.y+dai-1);
				goto KQ;
			}
		}
		if(key==-32){
			key=getch();
			if(key==72){
				clearPartOfScreen(start.x+1,start.y+dai-5,start.x+rong/2-1,start.y+dai-5);
				goto DAD;
			}else{
				if(ch.da=='\0'){
					gotoxy(start.x+16,start.y+41);
				}else{
					gotoxy(start.x+17,start.y+41);
				}
			}
		}
	}
}
void Edit_CH(DSMON *dsmon, NODECAUHOI root, CAUHOI ch){
	system("cls");
	gotoxy(0,0);printf("%s",ch.a);
	int vtmm=strlen(ch.mamh), vtnd=strlen(ch.nd), vta=strlen(ch.a), vtb=strlen(ch.b), vtc=strlen(ch.c), vtd=strlen(ch.d);
	int xnd=0,ynd=0, xa=0,ya=0, xb=0,yb=0, xc=0,yc=0, xd=0,yd=0, i=0; char key;
	
	OBJECR_LCT start; start.x=10; start.y=4; int dai=48, rong=150;
	Khung_Nhap_DSCH(start,dai,rong);
	gotoxy(start.x+rong/2+10,start.y+dai-2);
	printf("ENTER::SUA HOAC XOA CAU HOI HIEN TAI  |  ESC::QUAY LAI");
	
	gotoxy(start.x+rong/2+5,start.y+1); printf("%d",ch.id);
	gotoxy(start.x+14,start.y+1); printf("%s",ch.mamh);
	while(i<vtnd){
		if(i<=rong-1-24){					
			gotoxy(start.x+24+i,start.y+3);
			printf("%c",ch.nd[i]);
			if(i==rong-1-24)ynd++;				
		}else{
			if(xnd<=rong-1){
				if(xnd==rong-1){xnd=0;ynd++;}
				gotoxy(start.x+1+xnd,start.y+3+ynd);
				printf("%c",ch.nd[i]); xnd++;
			}					
		}i++;}i=0;
	while(i<vta){
		if(i<=rong-1-16){					
			gotoxy(start.x+16+i,start.y+21);
			printf("%c",ch.a[i]);
			if(i==rong-1-16)ya++;					
		}else{					
			if(xa<=rong-1){
				if(xa==rong-1){xa=0;ya++;}
				gotoxy(start.x+1+xa,start.y+21+ya);
				printf("%c",ch.a[i]); xa++;
			}					
		}i++;}i=0;
	while(i<vtb){
		if(i<=rong-1-16){					
			gotoxy(start.x+16+i,start.y+26);
			printf("%c",ch.b[i]);
			if(i==rong-1-16){yb++;}					
		}else{					
			if(xb<=rong-1){
				if(xb==rong-1){xb=0;yb++;}
				gotoxy(start.x+1+xb,start.y+26+yb);
				printf("%c",ch.b[i]); xb++;
			}					
		}i++;}i=0;
	while(i<vtc){
		if(i<=rong-1-16){					
			gotoxy(start.x+16+i,start.y+31);
			printf("%c",ch.c[i]);
			if(i==rong-1-16){yc++;}					
		}else{					
			if(xc<=rong-1){
				if(xc==rong-1){xc=0;yc++;}
				gotoxy(start.x+1+xc,start.y+31+yc);
				printf("%c",ch.c[i]); xc++;
			}					
		}i++;}i=0;
	while(i<vtd){
		if(i<=rong-1-16){					
			gotoxy(start.x+16+i,start.y+36);
			printf("%c",ch.d[i]);
			if(i==rong-1-16){yd++;}					
		}else{					
			if(xd<=rong-1){
				if(xd==rong-1){xd=0;yd++;}
				gotoxy(start.x+1+xd,start.y+36+yd);
				printf("%c",ch.d[i]); xd++;
			}					
		}i++;}i=0;
	gotoxy(start.x+16,start.y+41); printf("%c",ch.da);		
	
MAMON:
	gotoxy(start.x+(rong/2)/2-20,start.y+dai-5);
	printf("MA MON: TOI DA %d KY TU, BAO GOM A-Z, a-z, 0-9",MAXMMH);
	gotoxy(start.x+14+vtmm,start.y+1);
	while(1){
		key=getch();
		if(key>=65&&key<=90||key>=97&&key<=122||key>=48&&key<=57){
			if(vtmm<MAXMMH){
				ch.mamh[vtmm]=(char)key;
				ch.mamh[vtmm]=toupper(ch.mamh[vtmm]);
				gotoxy(start.x+14+vtmm,start.y+1);
				printf("%c",ch.mamh[vtmm]);
				vtmm++;
			}else{
				gotoxy(start.x+14+vtmm,start.y+1);
				printf(" ");
				gotoxy(start.x+14+vtmm,start.y+1);
			}
		}
		if(key==8&&vtmm>0){
			vtmm--;
			gotoxy(start.x+14+vtmm,start.y+1);
			printf(" ");
			gotoxy(start.x+14+vtmm,start.y+1);
		}
		if(key==13&&vtmm!=0){
			ch.mamh[vtmm]='\0';
			if(trungMaMon(ch.mamh,dsmon)){
				goto NDCH;				
			}else{
				gotoxy(start.x+rong/2+17,start.y+dai-5);
				printf("MA MON KHONG TON TAI! NHAP LAI MA MON!"); Sleep(1000);
				clearPartOfScreen(start.x+rong/2+1,start.y+dai-5,start.x+rong-1,start.y+dai-5);
				goto MAMON;
			}			
		}
		if(key==27){
			if(NOTICE(start.x+(rong/2)/2-14,start.y+dai-3,"Tiep tuc chinh sua cau hoi nay?")){
				clearPartOfScreen(start.x+1,start.y+dai-3,start.x+rong/2-1,start.y+dai-1);
				goto MAMON;								
			}else{
				return;
			}
		}
		if(key==-32){       
			key=getch();
			if(key==80&&vtmm!=0){
				ch.mamh[vtmm]='\0';
				if(trungMaMon(ch.mamh,dsmon)){
					goto NDCH;				
				}else{
					gotoxy(start.x+rong/2+17,start.y+dai-5);
					printf("MA MON KHONG TON TAI! NHAP LAI MA MON!"); Sleep(1000);
					clearPartOfScreen(start.x+rong/2+1,start.y+dai-5,start.x+rong-1,start.y+dai-5);
					goto MAMON;
				}
			}else{
				gotoxy(start.x+14+vtmm,start.y+1);
			}
		}
	}
NDCH:
	gotoxy(start.x+(rong/2)/2-20,start.y+dai-5);
	printf("NDCH: TOI DA %d KY TU",MAX_QST_CNT);
	if(vtnd<=rong-1-24){
		gotoxy(start.x+24+vtnd,start.y+3);	
	}else{
		gotoxy(start.x+1+xnd,start.y+3+ynd);
	}
	
	while(1){
		key=getch();
		if(key>=32&&key<=126){
			if(vtnd<MAX_QST_CNT){
				ch.nd[vtnd]=(char)key;
				if(vtnd<=rong-1-24){					
					gotoxy(start.x+24+vtnd,start.y+3);
					printf("%c",ch.nd[vtnd]);
					if(vtnd==rong-1-24){ynd++;}					
				}else{
					if(xnd<=rong-1){
						if(xnd==rong-1){xnd=0;ynd++;}
						gotoxy(start.x+1+xnd,start.y+3+ynd);
						printf("%c",ch.nd[vtnd]);
						xnd++;
					}					
				}
				vtnd++;
			}
		}
		if(key==8&&vtnd>0){	
			vtnd--;	
			if(vtnd<=rong-1-24){
				xnd=0;ynd=0;				
				gotoxy(start.x+24+vtnd,start.y+3);
				printf(" ");
				gotoxy(start.x+24+vtnd,start.y+3);	
			}else{
				if(xnd>=0&&ynd>=0){
					xnd--;
					if(xnd>0){
						gotoxy(start.x+1+xnd,start.y+3+ynd);
						printf(" ");
						gotoxy(start.x+1+xnd,start.y+3+ynd);						
					}
					if(xnd==0){
						gotoxy(start.x+1+xnd,start.y+3+ynd);
						printf(" ");
						gotoxy(start.x+1+xnd,start.y+3+ynd);
						xnd=rong-1;
						ynd--;
					}
				}				
			}			
		}
		if(key==13&&vtnd!=0){
			clearPartOfScreen(start.x+1,start.y+dai-5,start.x+rong/2-1,start.y+dai-5);
			goto DAA;
		}
		if(key==27){
			if(NOTICE(start.x+(rong/2)/2-14,start.y+dai-3,"Tiep tuc chinh sua cau hoi nay?")){
				clearPartOfScreen(start.x+1,start.y+dai-3,start.x+rong/2-1,start.y+dai-1);
				goto NDCH;								
			}else{
				return;
			}
		}
		if(key==-32){
			key=getch();
			if(key==72){
				clearPartOfScreen(start.x+1,start.y+dai-5,start.x+rong/2-1,start.y+dai-5);
				goto MAMON;
			}
			if(key==80&&vtnd!=0){
				clearPartOfScreen(start.x+1,start.y+dai-5,start.x+rong/2-1,start.y+dai-5);
				goto DAA;
			}
			else{
				gotoxy(start.x+24+vtnd,start.y+3);
			}
		}
	}
DAA:
	gotoxy(start.x+(rong/2)/2-20,start.y+dai-5);
	printf("DAP AN: TOI DA %d KY TU",MAX_ANS_CNT);
	if(vta<=rong-1-16){
		gotoxy(start.x+16+vta,start.y+21);	
	}else{
		gotoxy(start.x+1+xa,start.y+21+ya);
	}

	while(1){
		key=getch();
		if(key>=32&&key<=126){
			if(vta<MAX_ANS_CNT){
				ch.a[vta]=(char)key;
				if(vta<=rong-1-16){					
					gotoxy(start.x+16+vta,start.y+21);
					printf("%c",ch.a[vta]);
					if(vta==rong-1-16){ya++;}					
				}else{					
					if(xa<=rong-1&&vta<MAX_ANS_CNT){
						if(xa==rong-1){xa=0;ya++;}
						gotoxy(start.x+1+xa,start.y+21+ya);
						printf("%c",ch.a[vta]);
						xa++;
					}					
				}
				vta++;
			}
		}
		if(key==8&&vta>0){
			vta--;	
			if(vta<=rong-1-24){
				xa=0;ya=0;				
				gotoxy(start.x+16+vta,start.y+21);
				printf(" ");
				gotoxy(start.x+16+vta,start.y+21);	
			}else{
				if(xa>=0&&ya>=0){
					xa--;
					if(xa>0){
						gotoxy(start.x+1+xa,start.y+21+ya);
						printf(" ");
						gotoxy(start.x+1+xa,start.y+21+ya);						
					}
					if(xa==0){
						gotoxy(start.x+1+xa,start.y+21+ya);
						printf(" ");
						gotoxy(start.x+1+xa,start.y+21+ya);
						xa=rong-1;
						ya--;
					}
				}				
			}			
		}
		if(key==13&&vta!=0){
			goto DAB;
		}
		if(key==27){
			if(NOTICE(start.x+(rong/2)/2-14,start.y+dai-3,"Tiep tuc chinh sua cau hoi nay?")){
				clearPartOfScreen(start.x+1,start.y+dai-3,start.x+rong/2-1,start.y+dai-1);
				goto DAA;								
			}else{
				return;
			}
		}
		if(key==-32){
			key=getch();
			if(key==72){
				clearPartOfScreen(start.x+1,start.y+dai-5,start.x+rong/2-1,start.y+dai-5);
				goto NDCH;
			}
			if(key==80&&vta!=0){				
				goto DAB;
			}
			else{
				gotoxy(start.x+16+vta,start.y+21);
			}
		}
	}
DAB:
	gotoxy(start.x+(rong/2)/2-20,start.y+dai-5);
	printf("DAP AN: TOI DA %d KY TU",MAX_ANS_CNT);
	if(vtb<=rong-1-16){
		gotoxy(start.x+16+vtb,start.y+26);	
	}else{
		gotoxy(start.x+1+xb,start.y+26+yb);
	}
	
	while(1){
		key=getch();
		if(key>=32&&key<=126){
			if(vtb<MAX_ANS_CNT){
				ch.b[vtb]=(char)key;
				if(vtb<=rong-1-16){					
					gotoxy(start.x+16+vtb,start.y+26);
					printf("%c",ch.b[vtb]);
					if(vtb==rong-1-16){yb++;}					
				}else{					
					if(xb<=rong-1&&vtb<MAX_ANS_CNT){
						if(xb==rong-1){xb=0;yb++;}
						gotoxy(start.x+1+xb,start.y+26+yb);
						printf("%c",ch.b[vtb]);
						xb++;
					}					
				}
				vtb++;
			}
		}
		if(key==8&&vtb>0){
			vtb--;	
			if(vtb<=rong-1-24){
				xb=0;yb=0;				
				gotoxy(start.x+16+vtb,start.y+26);
				printf(" ");
				gotoxy(start.x+16+vtb,start.y+26);	
			}else{
				if(xb>=0&&yb>=0){
					xb--;
					if(xb>0){
						gotoxy(start.x+1+xb,start.y+26+yb);
						printf(" ");
						gotoxy(start.x+1+xb,start.y+26+yb);						
					}
					if(xb==0){
						gotoxy(start.x+1+xb,start.y+26+yb);
						printf(" ");
						gotoxy(start.x+1+xb,start.y+26+yb);
						xb=rong-1;
						yb--;
					}
				}				
			}			
		}
		if(key==13&&vtb!=0){
			goto DAC;
		}
		if(key==27){
			if(NOTICE(start.x+(rong/2)/2-14,start.y+dai-3,"Tiep tuc chinh sua cau hoi nay?")){
				clearPartOfScreen(start.x+1,start.y+dai-3,start.x+rong/2-1,start.y+dai-1);
				goto DAB;								
			}else{
				return;
			}
		}
		if(key==-32){
			key=getch();
			if(key==72){				
				goto DAA;
			}
			if(key==80&&vtb!=0){
				goto DAC;
			}
			else{
				gotoxy(start.x+16+vtb,start.y+26);
			}
		}
	}
DAC:
	gotoxy(start.x+(rong/2)/2-20,start.y+dai-5);
	printf("DAP AN: TOI DA %d KY TU",MAX_ANS_CNT);
	if(vtc<=rong-1-16){
		gotoxy(start.x+16+vtc,start.y+31);
	}else{
		gotoxy(start.x+1+xc,start.y+31+yc);
	}
		
	while(1){
		key=getch();
		if(key>=32&&key<=126){
			if(vtc<MAX_ANS_CNT){
				ch.c[vtc]=(char)key;
				if(vtc<=rong-1-16){					
					gotoxy(start.x+16+vtc,start.y+31);
					printf("%c",ch.c[vtc]);
					if(vtc==rong-1-16){yc++;}					
				}else{					
					if(xc<=rong-1&&vtc<MAX_ANS_CNT){
						if(xc==rong-1){xc=0;yc++;}
						gotoxy(start.x+1+xc,start.y+31+yc);
						printf("%c",ch.c[vtc]);
						xc++;
					}					
				}
				vtc++;
			}
		}
		if(key==8&&vtc>0){
			vtc--;	
			if(vtc<=rong-1-24){
				xc=0;yc=0;				
				gotoxy(start.x+16+vtc,start.y+31);
				printf(" ");
				gotoxy(start.x+16+vtc,start.y+31);	
			}else{
				if(xc>=0&&yc>=0){
					xc--;
					if(xc>0){
						gotoxy(start.x+1+xc,start.y+31+yc);
						printf(" ");
						gotoxy(start.x+1+xc,start.y+31+yc);						
					}
					if(xc==0){
						gotoxy(start.x+1+xc,start.y+31+yc);
						printf(" ");
						gotoxy(start.x+1+xc,start.y+31+yc);
						xc=rong-1;
						yc--;
					}
				}				
			}			
		}
		if(key==13&&vtc!=0){
			goto DAD;
		}
		if(key==27){
			if(NOTICE(start.x+(rong/2)/2-14,start.y+dai-3,"Tiep tuc chinh sua cau hoi nay?")){
				clearPartOfScreen(start.x+1,start.y+dai-3,start.x+rong/2-1,start.y+dai-1);
				goto DAC;								
			}else{
				return;
			}
		}
		if(key==-32){
			key=getch();
			if(key==72){
				goto DAB;
			}
			if(key==80&&vtc!=0){
				goto DAD;
			}
			else{
				gotoxy(start.x+16+vtc,start.y+31);
			}
		}
	}
DAD:
	gotoxy(start.x+(rong/2)/2-20,start.y+dai-5);
	printf("DAP AN: TOI DA %d KY TU",MAX_ANS_CNT);
	if(vtd<=rong-1-16){
		gotoxy(start.x+16+vtd,start.y+36);
	}else{
		gotoxy(start.x+1+xd,start.y+36+yd);
	}
	
	while(1){
		key=getch();
		if(key>=32&&key<=126){
			if(vtd<MAX_ANS_CNT){
				ch.d[vtd]=(char)key;
				if(vtd<=rong-1-16){					
					gotoxy(start.x+16+vtd,start.y+36);
					printf("%c",ch.d[vtd]);
					if(vtd==rong-1-16){yd++;}					
				}else{					
					if(xd<=rong-1&&vtd<MAX_ANS_CNT){
						if(xd==rong-1){xd=0;yd++;}
						gotoxy(start.x+1+xd,start.y+36+yd);
						printf("%c",ch.d[vtd]);
						xd++;
					}					
				}
				vtd++;
			}
		}
		if(key==8&&vtd>0){
			vtd--;	
			if(vtd<=rong-1-24){
				xd=0;yd=0;				
				gotoxy(start.x+16+vtd,start.y+36);
				printf(" ");
				gotoxy(start.x+16+vtd,start.y+36);	
			}else{
				if(xd>=0&&yd>=0){
					xd--;
					if(xd>0){
						gotoxy(start.x+1+xd,start.y+31+yd);
						printf(" ");
						gotoxy(start.x+1+xd,start.y+31+yd);						
					}
					if(xd==0){
						gotoxy(start.x+1+xd,start.y+31+yd);
						printf(" ");
						gotoxy(start.x+1+xd,start.y+31+yd);
						xd=rong-1;
						yd--;
					}
				}				
			}
		}
		if(key==13&&vtd!=0){
			clearPartOfScreen(start.x+1,start.y+dai-5,start.x+rong/2-1,start.y+dai-5);
			goto KQ;
		}
		if(key==27){
			if(NOTICE(start.x+(rong/2)/2-14,start.y+dai-3,"Tiep tuc chinh sua cau hoi nay?")){
				clearPartOfScreen(start.x+1,start.y+dai-3,start.x+rong/2-1,start.y+dai-1);
				goto DAD;								
			}else{
				return;
			}
		}
		if(key==-32){
			key=getch();
			if(key==72){
				goto DAC;
			}
			if(key==80&&vtd!=0){
				clearPartOfScreen(start.x+1,start.y+dai-5,start.x+rong/2-1,start.y+dai-5);
				goto KQ;
			}
			else{
				gotoxy(start.x+16+vtd,start.y+36);
			}
		}
	}
KQ:
	gotoxy(start.x+(rong/2)/2-23,start.y+dai-5);
	printf("KET QUA: TOI DA 1 KY TU, 'A' | 'B' | 'C' | 'D'");
	if(ch.da=='\0'){
		gotoxy(start.x+16,start.y+41);
	}else{
		gotoxy(start.x+17,start.y+41);
	}
	while(1){
		key=getch();
		if(key>=65&&key<=68||key>=97&&key<=100){
			ch.da=toupper((char)key);
			gotoxy(start.x+16,start.y+41);
			printf("%c",ch.da);
		}
		if(key==8){
			gotoxy(start.x+16,start.y+41);
			printf(" ");
			gotoxy(start.x+16,start.y+41);
		}
		if(key==13&&ch.da!='\0'){
			//savech?
			enterSaveButton(start.x+rong/2-4,start.y+dai+1);
			if(NOTICE(start.x+(rong/2)/2-20,start.y+dai-3,"Xac nhan cap nhat cau hoi nay?")){
				
				ch.mamh[vtmm]='\0'; ch.nd[vtnd]='\0'; ch.a[vta]='\0'; ch.b[vtb]='\0'; ch.c[vtc]='\0'; ch.d[vtd]='\0';
				delspace(ch.nd); delspace(ch.a); delspace(ch.b); delspace(ch.c); delspace(ch.d); 
				upper_first_char(ch.nd); upper_first_char(ch.a); upper_first_char(ch.b); upper_first_char(ch.c); upper_first_char(ch.d);
				bool update;
				NODECAUHOI tmp = new nodecauhoi;
				update = searchAndUpdateDSCH(root,ch); 
				tmp = root;
				if(update==true) saveDSCHEdit(root);				
                  
			}return;						
		}
		if(key==27){
			if(NOTICE(start.x+(rong/2)/2-14,start.y+dai-3,"Tiep tuc chinh sua cau hoi nay?")){
				clearPartOfScreen(start.x+1,start.y+dai-3,start.x+rong/2-1,start.y+dai-1);
				goto KQ;								
			}else{
				return;
			}
		}
		if(key==-32){
			key=getch();
			if(key==72){
				clearPartOfScreen(start.x+1,start.y+dai-5,start.x+rong/2-1,start.y+dai-5);
				goto DAD;
			}else{
				if(ch.da=='\0'){
					gotoxy(start.x+16,start.y+41);
				}else{
					gotoxy(start.x+17,start.y+41);
				}
			}
		}
	}
}
OBJECR_LCT inDSCauHoi_Mon2(DSMON *dsmon, NODECAUHOI &dscauhoi, CAUHOI cauHoi [MAX_QUESTION_AMOUNT+2],int count){
	
	int x=5,y=3;	
	//dung ham search
	OBJECR_LCT diemxy, diemxyL, diemxyT, locationOfDetail[13], dialog; dialog.x=50; dialog.y=20;
	int tickPage, indexOfLocation, arrow=0, page=1, j=12, sttC=0, i=0, startIndex = -10, maxShowChar = 380, m, n, dlg, dlogdai=8;
	bool back=false, tap=false, end=false; char c;
	
L:	systemCls();
	while(true){
		tickPage = 0;j=9;indexOfLocation = 0;
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
			if(tickPage==page){break;}
		}
		for( i=startIndex;i<startIndex+10;i++){
			gotoxy(0,1);printf("%s","   ");
			gotoxy(0,1);printf("%d",i);
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
				gotoxy(diemxy.x-3,diemxy.y+1);
				
				if(sttC<=count){ sttC = ((page)*10)-j;printf("%d",sttC);j--; }			
				
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
				else{ showStringInLocation(cauHoi[i].nd,diemxyT.x+1,diemxyT.y+1,diemxyT.x+1+130); }
			}
		}
		gotoxy(diemxyL.maxX,diemxyL.maxY+1);
		//printf("Page %d",page);
		
		if(back==true){				
			if(arrow <=0){ arrow = 0; }			
			if(arrow>9){}
			else if(arrow>indexOfLocation-1){}
			else {			
			    if(arrow>0) makeTable_Color_Type2(locationOfDetail[arrow],4,140,57,57);
				arrow++;
		    }			 			   
		}
		
		else {			
			W:	if(kbhit){			   
					c = getch();fflush(stdin);
					if(c==13 && arrow>=0 && tap==true){
						n=arrow+(page-1)*10-1;	
						dlg = OPTION_SUA_XOA(dialog,dlogdai,"SUA HOAC XOA SINH VIEN NAY?");
						if(dlg==0){  																//SUA
							Edit_CH(dsmon,dscauhoi,cauHoi[n]);	//CHINH SUA hoac XOA cau hoi
						}
						if(dlg==1){ 																//SUA
//							deleteNodeCH(dscauhoi,cauHoi[n]);
//							saveDSCHEdit(dscauhoi);
						   saveDSCHDelete(dscauhoi,cauHoi[n].id);
						   InitDSCH(dscauhoi);
						   loadDSCH(dscauhoi);
						}																			
						goto L;                        
					}
					if(c==0){
						c==getch();
						if(c==59){
							systemCls();
							Input_CH(dscauhoi,dsmon);
							goto L;
						}
						else goto W;
					}
					if(c==-32){
						c=getch();
						if(c==77){				//right					
							if(end==false){
							    arrow = 0;
							    clearPartOfScreen(x-4,y+3,diemxyL.maxX+7,diemxyL.maxY+1);
								page++;
								goto L;
							}else {
								goto W;
							}
						}
				        if(c==75){				//left
				        	if(page==1 && sttC==1){ }
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
					}					
				    if(c==27)goto E;
			    	if(c==80){
			    		tap = true;
						if(arrow <=0){ arrow = 0; }
						if(arrow>9){}
						else if(arrow>indexOfLocation-1){}
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

void showDSMon(DSMON *dsmon, NODECAUHOI dscauhoi){
	int slch, index; CAUHOI *cauHoi = new CAUHOI[MAX_QUESTION_AMOUNT+2];
	systemCls();
	
SM:	while(true){
	   	index = bangMonThi(dsmon);
		if(index==-1) return;
		if(index>=0){			
			slch = Inorder_Count_Filter(dscauhoi,cauHoi,dsmon->mon[index]->mamh);
			if(slch!=0){			
				inDSCauHoi_Mon2(dsmon,dscauhoi,cauHoi,slch);
				systemCls();
				goto SM;	
			}
			if(slch==0){				
				dialog(75,0,"Mon hoc nay hien chua co cau hoi. Nhap cau hoi");
//				Input_CH(dscauhoi,dsmon);
				goto SM;	
			}
		}		
	}
}

//int inDSCauHoi_Mon1(CAUHOI cauHoi [MAX_QUESTION_AMOUNT+2], int slch){
//	
//	OBJECR_LCT start; start.x=5; start.y=5;
//	int tickPage, indexOfLocation, arrow=0, page=1, j=12, sttC=0, i=0, startIndex = -10, maxShowChar = 380, dai=4, rong=152, maxrow=10;
//	bool back=false, tap=false, end=false; char c;
//	makeTable_Type2(start,dai,rong);
//	
//L: 	while(1){
//		tickPage=0;j=9;indexOfLocation=0;
//		startIndex=slch/maxrow;
//		
//		for(i=startIndex;i<startIndex+maxrow;i++){
//			gotoxy(0,0);printf("%s","   ");
//			gotoxy(0,0);printf("%d",i);
//			if(i>slch-1){
//				end = true;
//				sttC = slch - startIndex; 
//				break;
//			}else{
//				if((startIndex+10)==slch)end = true;
//					
//				
//			}
//		}
//	}	
//}
