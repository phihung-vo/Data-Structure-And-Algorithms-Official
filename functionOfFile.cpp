#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<fstream>
#include"function.h"


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<fstream>
#include"function.h"
//For File function CLASS
void saveDSLopTam(DSLOP *dslop){
	int slsv;
	FILE *f; f = fopen(CLASSFILE, "w");
    if(!f){
    	printf("\nKhong tim thay file DSLOP!");
    	Input_Class(dslop);
	}else{
		for(int i=0;i<dslop->n;i++){
			if(i==(dslop->n)-1){
			    NODESINHVIEN temp=NULL;
				temp=dslop->lop[i]->dssinhvien;
				slsv=countSV(temp);
				
				if(slsv==0){
					fprintf(f,"%s\n",dslop->lop[i]->malop);
					fprintf(f,"%s\n",dslop->lop[i]->tenlop);
					fprintf(f,"%s\n",dslop->lop[i]->nienkhoa);
		             			
					fprintf(f,"%d",slsv);
				}else {
					NODESINHVIEN temp=NULL;
					fprintf(f,"%s\n",dslop->lop[i]->malop);
					fprintf(f,"%s\n",dslop->lop[i]->tenlop);
					fprintf(f,"%s\n",dslop->lop[i]->nienkhoa);
		             			
					temp=dslop->lop[i]->dssinhvien;
					slsv=countSV(temp);
					fprintf(f,"%d\n",slsv);
					
					int k=0;
					while((temp!=NULL)&&(k<slsv)&&(slsv>0)){
						fprintf(f,"%s\n",temp->sinhvien.masv);
						fprintf(f,"%s\n",temp->sinhvien.ho);
						fprintf(f,"%s\n",temp->sinhvien.ten);
						fprintf(f,"%s\n",temp->sinhvien.phai);
						if(k==(slsv-1)){
						  fprintf(f,"%s\n",temp->sinhvien.password);
						}else{
							fprintf(f,"%s\n",temp->sinhvien.password);
						}
						temp=temp->next;
						k++;
					}
				}
			}
			else {
				NODESINHVIEN temp=NULL;
				fprintf(f,"%s\n",dslop->lop[i]->malop);
				fprintf(f,"%s\n",dslop->lop[i]->tenlop);
				fprintf(f,"%s\n",dslop->lop[i]->nienkhoa);
				
				temp=dslop->lop[i]->dssinhvien;
				slsv=countSV(temp);
				fprintf(f,"%d\n",slsv);
				
				int k=0;
				while((temp!=NULL)&&(k<slsv)&&(slsv>0)){
					fprintf(f,"%s\n",temp->sinhvien.masv);
					fprintf(f,"%s\n",temp->sinhvien.ho);
					fprintf(f,"%s\n",temp->sinhvien.ten);
					fprintf(f,"%s\n",temp->sinhvien.phai);
					fprintf(f,"%s\n",temp->sinhvien.password);
					
					temp=temp->next;
					k++;
				}
			}			
	    }
   	fclose(f);
   }
}



void saveDSLop(DSLOP *dslop){
	int slsv;
	int countMark = 0;
	FILE *f; f = fopen(CLASSFILE, "w");
    if(!f){
    	printf("\nKhong tim thay file DSLOP!");
    	Input_Class(dslop);
	}else{
		for(int i=0;i<dslop->n;i++){//printf("%s\n","for");system("pause");
			if(i==(dslop->n)-1){//lop cuoi cung
			    NODESINHVIEN temp=NULL;
				temp=dslop->lop[i]->dssinhvien;
				slsv=countSV(temp);
				
				if(slsv==0){
					fprintf(f,"%s\n",dslop->lop[i]->malop);
					fprintf(f,"%s\n",dslop->lop[i]->tenlop);
					fprintf(f,"%s\n",dslop->lop[i]->nienkhoa);
		             			
					fprintf(f,"%d",slsv);
				}else {
					NODESINHVIEN temp=NULL;
					NODEDIEM tempDiem = NULL;
					fprintf(f,"%s\n",dslop->lop[i]->malop);
					fprintf(f,"%s\n",dslop->lop[i]->tenlop);
					fprintf(f,"%s\n",dslop->lop[i]->nienkhoa);
		             			
					temp=dslop->lop[i]->dssinhvien;
					
					slsv=countSV(temp);
					fprintf(f,"%d\n",slsv);
				
					int k=0;
					while((temp!=NULL)&&(k<slsv)&&(slsv>0)){
						fprintf(f,"%s\n",temp->sinhvien.masv);
						fprintf(f,"%s\n",temp->sinhvien.ho);
						fprintf(f,"%s\n",temp->sinhvien.ten);
						fprintf(f,"%s\n",temp->sinhvien.phai);
						if(k==(slsv-1)){
						  fprintf(f,"%s\n",temp->sinhvien.password);
						  //ghi diem
//						  tempDiem = dslop->lop[i]->dssinhvien->sinhvien.dsdiem;
						  tempDiem = temp->sinhvien.dsdiem;
						  if(tempDiem==NULL){
						        fprintf(f,"%d",countMark);
					        }
					      if(tempDiem!=NULL){
								countMark = countSLMDaThi(tempDiem);
								fprintf(f,"%d\n",countMark);
								int kM = 0;
								while((tempDiem!=NULL)&&(kM<countMark)&&(countMark)>0){
									fprintf(f,"%s\n",tempDiem->diemthi.mamh);
									fprintf(f,"%f",tempDiem->diemthi.diem);
									tempDiem = tempDiem->next;
									kM++;
							   }
							}
							//
						}else{
							fprintf(f,"%s\n",temp->sinhvien.password);
							if(tempDiem==NULL){
								fprintf(f,"%d\n",countMark);
							}
							if(tempDiem!=NULL){
								countMark = countSLMDaThi(tempDiem);
								fprintf(f,"%d\n",countMark);
								int kM = 0;
								while((tempDiem!=NULL)&&(kM<countMark)&&(countMark)>0){
									fprintf(f,"%s\n",tempDiem->diemthi.mamh);
									fprintf(f,"%f\n",tempDiem->diemthi.diem);
									tempDiem = tempDiem->next;
									kM++;
							   }
							}
						}
						temp=temp->next;
						k++;
						countMark = 0;
					}
				}
			}//
			else {//printf("%s\n","else");system("pause");
				NODESINHVIEN temp=NULL;
				NODEDIEM tempDiem = NULL;
				fprintf(f,"%s\n",dslop->lop[i]->malop);
				fprintf(f,"%s\n",dslop->lop[i]->tenlop);
				fprintf(f,"%s\n",dslop->lop[i]->nienkhoa);
				
				temp=dslop->lop[i]->dssinhvien;//printf("%s\n","lay dsdiem");system("pause");
				
//				tempDiem = temp->sinhvien.dsdiem;
				slsv=countSV(temp);
				fprintf(f,"%d\n",slsv);
				
				int k=0;//printf("%s",dslop->lop[i]->malop);
				while((temp!=NULL)&&(k<slsv)&&(slsv>0)){
					fprintf(f,"%s\n",temp->sinhvien.masv);
					fprintf(f,"%s\n",temp->sinhvien.ho);
					fprintf(f,"%s\n",temp->sinhvien.ten);
					fprintf(f,"%s\n",temp->sinhvien.phai);
					fprintf(f,"%s\n",temp->sinhvien.password);
					//ghi diem 
//					tempDiem = dslop->lop[i]->dssinhvien->sinhvien.dsdiem;
                    tempDiem = temp->sinhvien.dsdiem;
					if(tempDiem==NULL){
						fprintf(f,"%d\n",countMark);//printf("%s\n","null");system("pause");
					}
					if(tempDiem!=NULL){//printf("%d",countMark);//system("pause");
						countMark = countSLMDaThi(tempDiem);//printf("%d",countMark);system("pause");
						fprintf(f,"%d\n",countMark);
						int kM = 0;
						while((tempDiem!=NULL)&&(kM<countMark)&&(countMark)>0){
							fprintf(f,"%s\n",tempDiem->diemthi.mamh);
							fprintf(f,"%f\n",tempDiem->diemthi.diem);
							tempDiem = tempDiem->next;//system("pause");
							kM++;
					   }
					}
					
					//
					temp=temp->next;
					k++;//printf("%s\n","temp tro next"); system("pause");
					countMark = 0;
				}
			}			
	    }
   	fclose(f);
   }
}



void loadDSLop(DSLOP *dslop){
	dslop->n  = 0;//dslop->lop = NULL;
	int slsv=0,slD=0, k=0,kM=0; NODESINHVIEN p; InitDSSV(p); SINHVIEN sv; LOP *lop;
	bool exist = true;
	for(int i=0;i<MAXCLASS;i++){
		dslop->lop[i]=(LOP*)malloc(sizeof(LOP));
		dslop->lop[i]->malop[0]='\0';
		dslop->lop[i]->tenlop[0]='\0';
		dslop->lop[i]->nienkhoa[0]='\0';
		dslop->lop[i]->dssinhvien=NULL;
	}
	FILE *f; f=fopen(CLASSFILE,"r");
	if(!f){
		exist = false;
		fclose(f);
		return ;
	}

	char mL[MAXML],tL[MAXTL],nK[MAXNK],mSV[MAXMSV],hoSV[MAXHOSV],tenSV[MAXTENSV],phaiSV[MAXPHAI],pwSV[MAXPW],mamh[MAXMMH],tmp[255];
	float diem = -1;
	char c[50];
	while(exist==true &&!feof(f)&&k<MAXCLASS){
		lop=(LOP*)malloc(sizeof(LOP));
		
		fgets(mL,255,f);
		mL[strlen(mL)-1] = '\0';
		strcpy(lop->malop,mL);
		
		fgets(tL,255,f);
		tL[strlen(tL)-1] = '\0';
		strcpy(lop->tenlop,tL);
		
		fgets(nK,255,f); 
		nK[strlen(nK)-1] = '\0';
		strcpy(lop->nienkhoa,nK);
		
		fscanf(f,"%d",&slsv);
		fgets(c,255,f);
		
		if(slsv>0){
			int j=0;
			while(j<slsv){ 
				fgets(mSV,255,f);
				mSV[strlen(mSV)-1] = '\0';			
				strcpy(sv.masv,mSV); 
				
				fgets(hoSV,255,f);
				hoSV[strlen(hoSV)-1] = '\0';
				strcpy(sv.ho,hoSV);
				
				fgets(tenSV,255,f);
				tenSV[strlen(tenSV)-1] = '\0';
				strcpy(sv.ten,tenSV);
				
				fgets(phaiSV,255,f);
				phaiSV[strlen(phaiSV)-1] = '\0';
				strcpy(sv.phai,phaiSV);
				
				fgets(pwSV,255,f);
				pwSV[strlen(pwSV)-1] = '\0';
				strcpy(sv.password,pwSV);

				//load diem
				fscanf(f,"%d",&slD);
				fgets(c,255,f);
				if(slD>0){
					int m = 0;
					sv.dsdiem = new nodediem;int n = 0;
					sv.dsdiem = NULL;
					while(m<slD){
				     fgets(mamh,255,f);	
				     mamh[strlen(mamh)-1] = '\0';
				     fscanf(f,"%f",&diem);
				     fgets(c,255,f);
				     DIEM loadD;
				     strcpy(loadD.mamh,mamh);
				     loadD.diem = diem;
				     if(Empty_Diem(sv.dsdiem)){
				     
		                    Insert_First_Diem(sv.dsdiem,loadD);
		              }
		              else{
		                
		              	    Insert_after(sv.dsdiem,loadD);
					  }
					   m++;	     
				    }
				}

				//
				Insert_Last_SV(lop->dssinhvien,sv);
				sv.dsdiem = NULL;
				j++;
			}
		}
		
		k++;
		insertClass(dslop,lop);
	}
	fclose(f);	

}
//	dslop->n  = 0;
//	int slsv=0,slD=0, k=0,kM=0; NODESINHVIEN p; InitDSSV(p); SINHVIEN sv; LOP *lop; DIEM loadD;
//	for(int i=0;i<MAXCLASS;i++){
//		dslop->lop[i]=(LOP*)malloc(sizeof(LOP));
//		dslop->lop[i]->malop[0]='\0';
//		dslop->lop[i]->tenlop[0]='\0';
//		dslop->lop[i]->nienkhoa[0]='\0';
//		dslop->lop[i]->dssinhvien=NULL;
//	}
//	ifstream f(CLASSFILE,std::ios::in);
////	ifstream f("dsloptamd.txt");
//	if(!f.is_open()){
//		cout<<"Can not open file"<<endl;
//		exit(0);
//	}	
//
//	string s;
//	float diem = -1;
//	char c[50];
//	while(!f.eof()&&k<MAXCLASS){
//		lop=(LOP*)malloc(sizeof(LOP));
//		
//		getline(f, s); 
//		if(s.size() == 0) break;
//		strcpy(lop->malop, s.c_str()); 
//		
//		getline(f, s); 
//		if(s.size() == 0) break;
//		strcpy(lop->tenlop, s.c_str()); 
//		
//		getline(f, s); 
//		if(s.size() == 0) break;
//		strcpy(lop->nienkhoa, s.c_str()); 
//		
//		f >> slsv;
//		// Doc nhung sv trong danh sach lop	
//		int j = 0; 
//		while(j<slsv && slsv > 0){ 
//			f.ignore();
//			getline(f, s); 
//			if(s.size() == 0) break;
//			strcpy(sv.masv, s.c_str()); 
//			
//			getline(f, s); 
//			if(s.size() == 0) break;
//			strcpy(sv.ho, s.c_str()); 
//			
//			getline(f, s); 
//			if(s.size() == 0) break;
//			strcpy(sv.ten, s.c_str()); 
//			
//			getline(f, s); 
//			if(s.size() == 0) break;
//			strcpy(sv.phai, s.c_str()); 
//			
//			getline(f, s); 
//			if(s.size() == 0) break;
//			strcpy(sv.password, s.c_str()); 
//			
//			f >> slD;
//				//Doc diem trong ds sv
//			if(slD>0){
//				int m = 0;
//				sv.dsdiem = new nodediem;int n = 0;
//				sv.dsdiem = NULL;
//				while(m<slD){
//			     	getline(f, s); 
//					if(s.size() == 0) break;
//					strcpy(loadD.mamh, s.c_str()); 
//			     	
//			     	f>>loadD.diem;
//			     	
//				    if(Empty_Diem(sv.dsdiem)){
//		                	Insert_First_Diem(sv.dsdiem,loadD);
//		            }
//		            else{
//		              	    Insert_after(sv.dsdiem,loadD);
//					}
//				   m++;	     
//			    }
//			}
//			//
//			Insert_Last_SV(lop->dssinhvien,sv);
//			j++;
//		}
//		
//		k++;
//		insertClass(dslop,lop);
//	}
//	f.close();	
//}
//For File function MonHoc
//void loadDSMon(DSMON *dsmon){
//     FILE *file;
//     MON *mon;
//     mon=(MON *)malloc(sizeof(MON));
//     file = fopen(OBJECTFILE,"rb"); 
//     int count = 0;
//     if(file==NULL){printf("\n\t\t\tKhong tim thay file DSMON!");}
//     else{
//            while(fread(mon,sizeof(*mon),1,file))
//		    {
//                
//    			dsmon->mon[count]=mon;
//   			    (dsmon->n) = count;
//    			mon=(MON *)malloc(sizeof(MON));
//    			count = count + 1;
//	    	}
//	    	free(mon);
//          
//          (dsmon->n) = count;
//     }
//     (dsmon->n) = count;  
//     fclose(file);            
//                  
//}
//
//void saveDSMon(char maMon[MAXMMH],char  tenMon[MAXTMH],DSMON *dsmon){//dsmon->dsmon[dsmon->n]->mamh);
//     FILE *file;
//     file = fopen(OBJECTFILE, "ab");
//     MON *temp;
//     temp = (MON *)malloc(sizeof(MON));
//     strcpy(temp->mamh,maMon);
//     strcpy(temp->tenmh,tenMon);
//     fwrite(temp,sizeof(*temp),1,file);
//     fclose(file);
//    
//     }
//
void saveDSMonMoi(DSMON *dsmon){
     FILE *file;
     file = fopen(OBJECTFILE, "wb");
     for(int i=0;i<dsmon->n;i++){
     	fwrite(dsmon->mon[i],sizeof(*dsmon->mon[i]),1,file);
	 }
     fclose(file);
}

void saveDSMon(DSMON *dsmon){
	FILE *f; f = fopen(OBJECTFILE, "w");
//	FILE *f; f = fopen("dsmontam.txt", "w");
    if(!f){
    	printf("\nKhong tim thay file DSMON!");
	}else{
		for(int i=0;i<dsmon->n;i++){
			fprintf(f,"%s\n",dsmon->mon[i]->mamh);
			fprintf(f,"%s\n",dsmon->mon[i]->tenmh);
		}
    }
   	fclose(f);
}

void loadDSMon(DSMON *dsmon){
	dsmon->n  = 0;
	MON *mon;int k=0;
	for(int i=0;i<MAXOBJECT;i++){
		dsmon->mon[i]=(MON*)malloc(sizeof(MON));
		dsmon->mon[i]->mamh[0]='\0';
		dsmon->mon[i]->tenmh[0]='\0';
	}
	ifstream f(OBJECTFILE,std::ios::in);
	if(!f.is_open()){
		cout<<"Can not open file"<<endl;
		exit(0);
	}	
	string s;
	while(!f.eof()&&k<MAXOBJECT){
		mon=(MON*)malloc(sizeof(MON));
		
		getline(f, s); 
		if(s.size() == 0) break;
		strcpy(mon->mamh, s.c_str()); 
		
		getline(f, s); 
		if(s.size() == 0) break;
		strcpy(mon->tenmh, s.c_str()); 
		
		k++;
		insertObject(dsmon,mon);
	}
	f.close();
}

//void saveDSCH(CAUHOI ch){
//	FILE *f; f=fopen(QSTFILE,"ab");
//	fwrite(&ch,sizeof(ch),1,f);
//	fclose(f);
//}


void saveDSCH(NODECAUHOI root){
	FILE *f; f=fopen(QSTFILE,"ab");
	int  STACKSIZE = 500, sp=-1, dem=0;
	NODECAUHOI Stack[STACKSIZE], p=root;
	CAUHOI ch;
	do{
		while(p!=NULL){
			Stack[++sp]= p;
			p= p->left;
		}
		if(sp != -1){
			p=Stack[sp--];
			ch = p->cauhoi;//printf("%s\n",ch.nd);
		    fwrite(&ch,sizeof(CAUHOI),1,f);
			p=p->right;
		}else break;
	}while(1);
	fclose(f);	
	return;
}
void saveDSCHEdit(NODECAUHOI root){
	FILE *f; f=fopen(QSTFILE,"wb");
	int  STACKSIZE = 500, sp=-1, dem=0;
	NODECAUHOI Stack[STACKSIZE], p=root;
	CAUHOI ch;
	do{
		while(p!=NULL){
			Stack[++sp]= p;
			p= p->left;
		}
		if(sp != -1){
			p=Stack[sp--];
			ch = p->cauhoi;//printf("%s\n",ch.nd);
		    fwrite(&ch,sizeof(CAUHOI),1,f);
			p=p->right;
		}else break;
	}while(1);
	fclose(f);	
	return;
}

void saveDSCHDelete(NODECAUHOI root,int id){
	FILE *f; f=fopen(QSTFILE,"wb");
	int  STACKSIZE = 500, sp=-1, dem=0;
	NODECAUHOI Stack[STACKSIZE], p=root;
	CAUHOI ch;
	do{
		while(p!=NULL){
			Stack[++sp]= p;
			p= p->left;
		}
		if(sp != -1){
			p=Stack[sp--];
			ch = p->cauhoi;//printf("%s\n",ch.nd);
		    if(p->cauhoi.id != id)fwrite(&ch,sizeof(CAUHOI),1,f);
			p=p->right;
		}else break;
	}while(1);
	fclose(f);	
	return;
}


void loadDSCH(NODECAUHOI &root){
	InitDSCH(root);
	CAUHOI cauhoi;
	FILE *file;
	if(!(file = fopen(QSTFILE,"rb"))){
		printf("File DSCH khong ton tai!");
	}else{
		while(fread(&cauhoi, sizeof(CAUHOI), 1, file)){	
			Insert_node(root,cauhoi);
		}
	}	
	fclose(file);
}


////----------------------------------------------------------
//void showT(char masv[MAXMSV],char mamh[MAXMMH]){
//	CT *ctt;
//	FILE *file;
//	file = fopen(DETAILEXAM,"rb");
//	ctt = (CT *)malloc(sizeof(CT));
//
//	while(fread(ctt,sizeof(*ctt),1,file)){
//		if(strcmp(ctt->masv,masv)==0 &&strcmp(ctt->mamh,mamh)==0){printf("sadfasfs");
//         printf("%c %c\n",ctt->cht->daC,ctt->cht->daD);
//		}
//			ctt = (CT *)malloc(sizeof(CT));
//	}fclose(file);
//}
