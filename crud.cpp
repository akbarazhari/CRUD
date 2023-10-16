#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#define nmax 4

using namespace std;
int n=0; 
struct data
{ 
	char matkul[50], nama[50];
	int sks, tempsks;
};
	struct data dosen[nmax];
	void tambah_data(), hapus_data(), tampilkan_data(), swap_data();
	int	main()
{
	int pil;
	menu :
	cout<<"Menu Database Dosen \n";
	cout<<"1. Tambah Data\n";
	cout<<"2. Hapus Data \n";
	cout<<"3. Tampilkan Data \n";
	cout<<"4. Swap Data \n";
	cout<<"5. Keluar \n";
	cout<<"Pilih menu (1/2/3/4) : ";
	cin>>pil;
	
	if (pil==1) tambah_data();
	else if (pil==2) hapus_data();
	else if (pil==3) tampilkan_data();
	else if (pil==4) swap_data();
	else if (pil==5) return 0;
	
	else 
		{
		system("CLS");
		cout<<"Pilihan tidak tersedia. \n";
		}
	goto menu;
	getch();
}
void tambah_data()
{
     if (n<nmax)
	 	{
	 	system("CLS");
        cout<<"Nama Dosen : ";
        cin>>dosen[n].nama;
        cout<<"Mata Kuliah : ";
        cin>>dosen[n].matkul;
        cout<<"SKS : ";
        cin>>dosen[n].sks;
        n++;
        system("CLS");
        cout<<("Data ditambahkan.\n");
        }
     else cout<<"\n Kapasitas data maksimum. ("<<nmax<<")";
}

void hapus_data(){
     int x;
     system("CLS");
     cout<<"Pilih data yang akan dihapus (1-4) : ";
     cin>>x;
     if (x<n && x>0){
        for (int i=x;i<n;i++)
		{
			strcpy(dosen[i-1].nama,dosen[x].nama);
            strcpy(dosen[i-1].matkul,dosen[x].matkul);
            dosen[i-1].sks = dosen[x].sks;
        }
        n--;
        }
     else if(x==n) {
	 	n--;
	 	system("CLS");
		cout<<"Data dihapus. \n";
		}
     else cout<<"\n Data yang ingin dihapus tidak ada. Pilih data yang lain.\n";
}

void tampilkan_data(){
     if (n==0) 
	 {
	 system("CLS");
	 cout<<"Tidak ada data yang disimpan. \n";
 	}
	 else {
	 	system("CLS");
        for (int i=0;i<n;i++)
		{
        cout<<"Data ke-"<<i+1<<" : ";
        cout<<"\nNama        : "<<dosen[i].nama;
        cout<<"\nMata Kuliah : "<<dosen[i].matkul;
        cout<<"\nSKS         : "<<dosen[i].sks;
        cout<<endl;
    	}
     }
}

void swap_data()
{
     if (n==0) 
	 {
	 system("CLS");
	 cout<<"Tidak ada data yang diswap.  \n";
 	}
	 else {
	 	system("CLS");
	 	int swap1, swap2, tempsks;
	 	char tempmatkul[50], tempnama[50];
        cout<<"Pilih data pertama yang ingin diubah : ";
		cin>>swap1;
		cout<<"Pilih data kedua yang ingin diubah : ";
		cin>>swap2;
        swap(dosen[swap1].nama, dosen[swap2].nama);
        swap(dosen[swap1].matkul, dosen[swap2].matkul);
        swap(dosen[swap1].sks, dosen[swap2].sks);
        cout<<endl;
     }
}
