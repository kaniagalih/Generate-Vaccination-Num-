#include <stdio.h>

int tanggal_vaksin2[300];
int vaksinBulan( int tanggal_vaksin1){
	int aux[100];
		for (int i = 0; i<=7; i++){
			tanggal_vaksin2[i] = tanggal_vaksin1 % 10;
			tanggal_vaksin1 /= 10;
		}
		for (int i = 0; i<=7; i++){
			aux[7-i] = tanggal_vaksin2[i];
		}
		for (int i = 0; i<=7; i++){
			tanggal_vaksin2[i] = aux[i];
		}
		tanggal_vaksin2[5] +=1;
		if(tanggal_vaksin2[4] * 10 + tanggal_vaksin2[5] > 12){
			tanggal_vaksin2[5] = 1;
			tanggal_vaksin2[4] = 0;
			tanggal_vaksin2[3] += 1;
		}
		for (int i = 0; i<8; i++){
			printf("%d", tanggal_vaksin2[i]);
		}
			printf("\n\n");
}


int vaksinTahun(int tanggal_vaksin1){
	int aox[100];
		for (int i = 0; i<=7; i++){
			tanggal_vaksin2[i] = tanggal_vaksin1 % 10;
			tanggal_vaksin1 /= 10;
		}
		for (int i = 0; i<=7; i++){
			aox[7-i] = tanggal_vaksin2[i];
		}
		for (int i = 0; i<=7; i++){
			tanggal_vaksin2[i] = aox[i];
		}
		tanggal_vaksin2[3] +=1;
		if(tanggal_vaksin2[4] * 10 + tanggal_vaksin2[5] > 12){
			tanggal_vaksin2[4] = 0;
			tanggal_vaksin2[3] = 1;
			tanggal_vaksin2[2] += 1;
		}
		for (int i = 0; i<8; i++){
			printf("%d", tanggal_vaksin2[i]);
		}
		printf("\n\n");	
}


int sertifikatVaksin(char tipe_vaksin[300], int tanggal_vaksin1, char nik[300]){
	printf("%s - %d - %s\n",tipe_vaksin,tanggal_vaksin1,nik);
}
	
int main()
{
	int menu,kode_vaksin, no_ijin_praktek, tanggal_vaksin1;
	char no_hp[300],tipe_vaksin[300],nama_vaksin[300], kadaluwarsa_vaksin[300],
	 status_vaksinasi, nik[300], nama_peserta[300], tempat[300],tanggal_lahir[300], alamat[300],
	 alamat_tambahan[300], nama_tenmedis[300],lokasi_vaksin[300];
	printf("\t\t\t\t\t==================== Program Vaksin =====================\n");
	printf("\t\t\t\t\t\tBy Kania Galih Widowati/2502047070\n");
	
	menu:
	printf("*****************************\n");
	printf("\tMain menu:\n");
	printf("1. Input Data\n");
	printf("2. First Vaccination\n");
	printf("3. Second Vaccination\n");
	printf("4. Exit\n");
	printf("*****************************\n");
	printf("Input menu:");
	scanf("%d", &menu); 
	
	switch(menu){
		case 1:
			/* Input Data Vaksin */
			printf("1. Data Vaksin:\n");
			printf("\t a. Nama Vaksin:");
			scanf("%s", &nama_vaksin); fflush(stdin);
			printf("\t b. Kode Batch Vaksin:");
			scanf("%d", &kode_vaksin); fflush(stdin);
			printf("\t c. Status Vaksin[Y/N]:");
			scanf("%c", &status_vaksinasi); fflush(stdin);
			printf("\t d. Masa Kadaluwarsa Vaksin:");
			scanf("%s", &kadaluwarsa_vaksin); fflush(stdin);
			
			printf("\n");
			
			/* Input Data Peserta Vaksin */
			printf("2. Data Peserta Vaksin:\n");
			printf("\t a. Nomor Induk Kependudukan:");
			scanf("%s", &nik); fflush(stdin);
			printf("\t b. Nama:");
			scanf("%[^\n]s", &nama_peserta); fflush(stdin);
			printf("\t c. Tempat/Tanggal lahir(Y M D):");
			scanf("%s %s", &tempat, &tanggal_lahir); fflush(stdin);
			printf("\t d. Alamat sesuai dengan NIK:");
			scanf("%[^\n]s", &alamat); fflush(stdin);
			printf("\t e. Alamat Tambahan jika ada:");
			scanf(" %[^\n]s", &alamat_tambahan); fflush(stdin);
			printf("\t f. No Handphone:");
			scanf(" %s", &no_hp); fflush(stdin);
			
			printf("\n");
			
			/* Input Data Tenaga Kesehatan */
			printf("3.Tenaga Kesehatan yang Melakukan Vaksinasi\n");
			printf("\t a. Nama:"); 
			scanf(" %s", &nama_tenmedis); fflush(stdin);
			printf("\t b. Nomor Izin Praktek Tenaga Medis:");
			scanf("%d", &no_ijin_praktek); fflush(stdin);
			
			/* First or second Vaccination */
			printf("4. Vaksinasi\n");
			printf("\t a. Tipe vaksinasi:");
			scanf("%s",&tipe_vaksin); fflush(stdin);
			printf("\t b. Lokasi Vaksin:");
			scanf("%s", &lokasi_vaksin); fflush(stdin);
			printf("\t c. Tanggal Vaksin(Y M D):");
			scanf("%d",&tanggal_vaksin1); fflush(stdin);
			goto menu;
			break;
		case 2:
			printf("First Vaccination\n");
			printf("\tNomor Induk Kependudukan: %s\n",nik);
			printf("\tNama: %s\n",nama_peserta);
			printf("\tTempat/Tanggal lahir: %s %s\n", tempat,tanggal_lahir);
			printf("\tAlamat sesuai dengan NIK: %s\n",alamat);
			printf("\tAlamat Tambahan jika ada: %s\n",alamat_tambahan);
			printf("\tNo Handphone: %s\n",no_hp);
			
			printf("\n");
			
			printf("Vaccine Information\n");
			printf("\tNama Vaksin: %s\n",nama_vaksin);
			printf("\tKode Batch Vaksin: %d\n",kode_vaksin);
			printf("\tLokasi Vaksin: %s\n",lokasi_vaksin);
			printf("\tTanggal Vaksin: %d\n",tanggal_vaksin1);
			
			printf("\n");
			
			printf("Certificate & date of the next vaccine\n");
			printf("\tNomor Sertifikat Vaksin:");
			
				sertifikatVaksin(tipe_vaksin,tanggal_vaksin1, nik);
				
			printf("\tTanggal Vaksin Berikutnya:");
			
				vaksinBulan(tanggal_vaksin1);
			
			printf("\t\t\t\t\t|Tetap Jaga Jarak dan Patuhi Protokol Kesehatan|\n");
			break;
		case 3:
			printf("Second Vaccination\n");
			printf("\tNomor Induk Kependudukan: %s\n",nik);
			printf("\tNama: %s\n",nama_peserta);
			printf("\tTempat/Tanggal lahir: %s %s\n", tempat,tanggal_lahir);
			printf("\tAlamat sesuai dengan NIK: %s\n",alamat);
			printf("\tAlamat Tambahan jika ada: %s\n",alamat_tambahan);
			printf("\tNo Handphone: %s\n",no_hp);
			
			printf("\n");
			
			printf("Vaccine Information\n");
			printf("\tNama Vaksin: %s\n",nama_vaksin);
			printf("\tKode Batch Vaksin: %d\n",kode_vaksin);
			printf("\tLokasi Vaksin: %s\n",lokasi_vaksin);
			printf("\tTanggal Vaksin: %d\n",tanggal_vaksin1);
	
			printf("\n");
			
			printf("Certificate & date of the next vaccine\n");
			printf("\tNomor Sertifikat Vaksin:");
			
				sertifikatVaksin(tipe_vaksin,tanggal_vaksin1, nik);
				
			printf("\tTanggal Vaksin Berikutnya:");
		
				vaksinTahun(tanggal_vaksin1);
				
			printf("\t\t\t\t\t|Tetap Jaga Jarak dan Patuhi Protokol Kesehatan|\n");
			break;
		case 4:
			printf("\t\t\t\t\t|Tetap Jaga Jarak dan Patuhi Protokol Kesehatan|\n");
		break;
	}
}

