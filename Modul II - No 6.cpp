#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int validInt(int *var);
void reVldInt(int *var, char *prompt);
void reset();
void kalkulasi();

int validInt(int *var){
	char buff[1020];
	char cek;
	fflush(stdin);
	if(fgets(buff, sizeof(buff), stdin) != NULL){
		if(sscanf(buff, "%d %c", var, &cek) == 1) {
			return 1;
		}
	}
	return 0;
}

void reVldInt(int *var, char *prompt){
	while(1){
		printf(prompt);
		if(validInt(var))
			break;
		printf(" Input hanya  boleh berupa angka!! \n");
		printf("\n");
	}
}

void reset(){
	char pil[10];
	printf("\n<<<<<<<<<<<<<<<<<<<<~~~~~~~~~~>>>>>>>>>>>>>>>>>>>>");
	printf ("\n Tentukan Ulang Nilai? [Y/N] : "); 
	scanf("%s", &pil);
 	
	if(!strcmp(pil, "y") || !strcmp(pil, "Y")){
		system("cls");
		main();
	}
	else if(!strcmp(pil, "n") || !strcmp(pil, "N")){
		system("cls");
		printf("\nTerimakasih Telah Menggunakan Program Ini!");
  		exit(0);
	}  
	else{
		printf(" Inputan tidak valid!");
		reset();
	}

}

void kalkulasi(){
	int j;
	int p, i, t, bunga, apb, totalbunga, totalangsuran, bilangan;
	int angsuranpokok;
	reVldInt(&p, " Pokok Pinjaman (Rp)     : ");
	reVldInt(&i, " Besar Bunga    (persen) : ");
	reVldInt(&t, " Lama Pinjaman  (bulan)  : ");
	printf("\n--------------------------------------------------");
	printf("\n\n Bulan \t\t   Bunga \t      Angsuran Pokok \t     Angsuran Perbulan \t\n");
		for (j = 1; j <= t; j++)
		{
			angsuranpokok = p / t;
			bunga = (p - ((j - 1) * angsuranpokok)) * i / 12;
			apb = bunga + angsuranpokok;

	printf("  %d \t\t Rp.%d \t\t Rp.%d \t\t Rp.%d \t\n", j, bunga, angsuranpokok, apb);
			totalbunga = totalbunga + bunga;
			totalangsuran = totalangsuran + apb;
		}
	printf("\n--------------------------------------------------");
	printf("\n Total Bunga       : Rp. %d", totalbunga);
	printf("\n Total Angsuran    : Rp. %d", totalangsuran);
}

int main(){
  int pilihan;

    printf("\n==================================================");
    printf("\n>            Program Angsuran Bulanan            <");
    printf("\n==================================================\n");
    
    kalkulasi();
    reset();

return 0;
}
