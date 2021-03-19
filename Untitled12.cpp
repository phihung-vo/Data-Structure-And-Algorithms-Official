if(c==13){
				systemCls();
				GdSV();
				gotoxy(xIn+50,2);colorText(252);
				printf("Ma Lop: %s",dslop->lop[index]->malop);
		        gotoxy(xIn+50,4);colorText(252);
			    printf("Ten Lop: %s",dslop->lop[index]->tenlop);
			    gotoxy(xIn+50,6);colorText(252);
			    printf("Nien Khoa: %s",dslop->lop[index]->nienkhoa);
			    clearColor();
				vitri=0;
				NODESINHVIEN temp=NULL;
				temp=dslop->lop[index]->dssinhvien;
				int slsv=countSV(temp);
				RP:	if( ( (tick*20) - slsv ) > 20 ){
						tick--;
						goto RP; 	
					}
					else{
//						clearPartOfScreen(xIn,13+vitri,xIn+120+10,52);//xoa 1 vung in ds
						for(i=0;i<slsv;i++){
								if(i % 20 == 0) j ++;
							if(j == tick){
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
								count++;
							}
							if(count == 20){
								break;
							}
						}
					}
				
			}
