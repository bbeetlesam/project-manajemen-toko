#include <iostream>
#include <string>
using namespace std;

struct Barang {
    int kodeRak, idBarang, stok;
    string jenis, nama;
    float harga;
	
    Barang* next;
};

Barang* head = nullptr;
Barang* tail = nullptr;
int currentIdBarang = 1;

void inputBarang() {
    char pilihanTambah;
    do {
        Barang* newBarang = new Barang();

        cout << "\tMasukkan Kode Rak: ";
        cin >> newBarang->kodeRak;
        newBarang->idBarang = currentIdBarang++;

        cin.ignore(); 
        
        cout << "\tMasukkan Jenis Barang: ";
        getline(cin, newBarang->jenis);
        cout << "\tMasukkan Nama Barang: ";
        getline(cin, newBarang->nama);
        cout << "\tMasukkan Harga/pcs: ";
        cin >> newBarang->harga;
        cout << "\tMasukkan Stok Barang/pcs: ";
        cin >> newBarang->stok;

        newBarang->next = nullptr;

        if (head == nullptr) {
            head = newBarang;
            tail = newBarang;
        } else {
            tail->next = newBarang;
            tail = newBarang;
        }

        cout << "\n\tApakah Anda ingin memasukkan barang lagi? (y/n): ";
        cin >> pilihanTambah;
    } while (pilihanTambah == 'y' || pilihanTambah == 'Y');
}

void printBarang() {
    Barang* cur = head;
    while (cur != nullptr) {
        cout << "\tId Barang: " << cur->idBarang << endl;
        cout << "\tKode Rak: " << cur->kodeRak << endl;
        cout << "\tJenis Barang: " << cur->jenis << endl;
        cout << "\tNama Barang: " << cur->nama << endl;
        cout << "\tHarga barang/pcs: " << cur->harga << endl;
        cout << "\tStok Barang/pcs: " << cur->stok << endl;
        cout << "-----------------------" << endl;
        cur = cur->next;
    }
}

void hapusBarang() {
    if (head == nullptr) {
        cout << "\n\tMAAF! Tidak ada barang untuk dihapus." << endl;
        return;
    }

    char pilihanHapus;
    do {
        int id;
        cout << "\tMasukkan Id Barang yang akan dihapus: ";
        cin >> id;

        Barang* cur = head;
        Barang* prev = nullptr;

        while (cur != nullptr && cur->idBarang != id) {
            prev = cur;
            cur = cur->next;
        }

        if (cur == nullptr) {
            cout << "\tBarang dengan Id " << id << " tidak ditemukan." << endl;
        } else {
            if (cur == head) {
                head = head->next;
            } else {
                prev->next = cur->next;
            }
            if (cur == tail) {
                tail = prev;
            }
            delete cur;
            cout << "\tBarang dengan Id " << id << " telah dihapus." << endl;
        }

        cout << "\n\tApakah Anda ingin menghapus barang lagi? (y/n): ";
        cin >> pilihanHapus;
    } while (pilihanHapus == 'y' || pilihanHapus == 'Y');
}

void editBarang() {
    if (head == nullptr) {
        cout << "\tTidak ada barang untuk diedit." << endl;
        return;
    }

    char pilihanEdit;
    do {
        int id;
        cout << "\tMasukkan Id Barang yang akan diedit: ";
        cin >> id;

        Barang* cur = head;

        while (cur != nullptr && cur->idBarang != id) {
            cur = cur->next;
        }

        if (cur == nullptr) {
            cout << "\tBarang dengan Id " << id << " tidak ditemukan." << endl;
        } else {
            cout << "\tMasukkan Kode Rak baru: ";
            cin >> cur->kodeRak;
            cin.ignore();
            cout << "\tMasukkan Jenis baru: ";
            getline(cin, cur->jenis);
            cout << "\tMasukkan Nama baru: ";
            getline(cin, cur->nama);
            cout << "\tMasukkan Harga baru: ";
            cin >> cur->harga;
            cout << "\tMasukkan Stok baru: ";
            cin >> cur->stok;

            cout << "\tBarang dengan Id " << id << " telah diperbarui." << endl;
        }

        cout << "\n\tApakah Anda ingin mengedit barang lagi? (y/n): ";
        cin >> pilihanEdit;
    } while (pilihanEdit == 'y' || pilihanEdit == 'Y');
}

void cariBarang() {
    if (head == nullptr) {
        cout << "\tTidak ada barang untuk dicari." << endl;
        return;
    }

    char pilihanCari;
    do {
        int id;
        cout << "\tMasukkan Id Barang yang dicari: ";
        cin >> id;

        Barang* cur = head;

        while (cur != nullptr && cur->idBarang != id) {
            cur = cur->next;
        }

        if (cur == nullptr) {
            cout << "\tBarang dengan Id " << id << " tidak ditemukan." << endl;
        } else {
            cout << "\tBarang ditemukan:" << endl;
            cout << "\tId Barang: " << cur->idBarang << endl;
            cout << "\tKode Rak: " << cur->kodeRak << endl;
            cout << "\tJenis: " << cur->jenis << endl;
            cout << "\tNama: " << cur->nama << endl;
            cout << "\tHarga: " << cur->harga << endl;
            cout << "\tStok: " << cur->stok << endl;
            cout << "\t-----------------------" << endl;
        }

        cout << "Apakah Anda ingin mencari barang lagi? (y/n): ";
        cin >> pilihanCari;
    } while (pilihanCari == 'y' || pilihanCari == 'Y');
}

void swapBarang(Barang* a, Barang* b) {
    int tempKodeRak = a->kodeRak;
    a->kodeRak = b->kodeRak;
    b->kodeRak = tempKodeRak;

    int tempIdBarang = a->idBarang;
    a->idBarang = b->idBarang;
    b->idBarang = tempIdBarang;

    string tempJenis = a->jenis;
    a->jenis = b->jenis;
    b->jenis = tempJenis;

    string tempNama = a->nama;
    a->nama = b->nama;
    b->nama = tempNama;

    float tempHarga = a->harga;
    a->harga = b->harga;
    b->harga = tempHarga;

    int tempStok = a->stok;
    a->stok = b->stok;
    b->stok = tempStok;
}

void sortIdBarang(bool ascending) {
    if (head == nullptr) return;

    for (Barang* i = head; i->next != nullptr; i = i->next) {
        for (Barang* j = i->next; j != nullptr; j = j->next) {
            if (ascending ? (i->idBarang > j->idBarang) : (i->idBarang < j->idBarang)) {
                swapBarang(i, j);
            }
        }
    }
}

void sortKodeRak(bool ascending) {
    if (head == nullptr) return;

    for (Barang* i = head; i->next != nullptr; i = i->next) {
        for (Barang* j = i->next; j != nullptr; j = j->next) {
            if (ascending ? (i->kodeRak > j->kodeRak) : (i->kodeRak < j->kodeRak)) {
                swapBarang(i, j);
            }
        }
    }
}

void sortStok(bool ascending) {
    if (head == nullptr) return;

    for (Barang* i = head; i->next != nullptr; i = i->next) {
        for (Barang* j = i->next; j != nullptr; j = j->next) {
            if (ascending ? (i->stok > j->stok) : (i->stok < j->stok)) {
                swapBarang(i, j);
            }
        }
    }
}

void manajemenToko() {
    while (true) {
        cout << "\t=============================" << endl;
        cout << "\t======= MANAJEMEN TOKO ======" << endl;
        cout << "\t1. Input Barang\n";
        cout << "\t2. Tampilkan Barang\n";
        cout << "\t3. Hapus Barang\n";
        cout << "\t4. Edit Barang\n";
        cout << "\t5. Cari Barang\n";
        cout << "\t6. Sort Barang\n";
		cout << "\t7. Exit\n";
        cout << "\tPilih: ";
        int pilihan;
        cin >> pilihan;

        if (pilihan == 1) {
            inputBarang();
        } else if (pilihan == 2) {
            printBarang();
        } else if (pilihan == 3) {
            hapusBarang();
        } else if (pilihan == 4) {
            editBarang();
        } else if (pilihan == 5) {
            cariBarang();
        } else if (pilihan == 6) {
			cout << "\tPilih sort: \n1. Kode Rak \n2. Id Barang \n3. Stok \n4. Exit " << "\npilihan anda: ";
            int sortPilihan;
            cin >> sortPilihan;

            if (sortPilihan == 1) {
                cout << "\tPilih Sort \n1. Ascending \n2. Descending" << "\npilihan anda:";
				int sortType;
				cin >> sortType;
				if (sortType == 1)
				{
					sortKodeRak(true); // ascending
					printBarang();
				} else if (sortType == 2) {
					sortKodeRak(false); // descending
					printBarang();
				} else {
					cout << "\nPilihanmu tidak ada." << endl;
					continue;
				}
            } else if (sortPilihan == 2) {
                cout << "\tPilih Sort \n1. Ascending \n2. Descending" << endl;
				int sortType;
				cin >> sortType;
				if (sortType == 1)
				{
					sortIdBarang(true); // ascending
					printBarang();
				} else if (sortType == 2) {
					sortIdBarang(false); // descending
					printBarang();
				} else {
					cout << "\nPilihanmu tidak ada." << endl;
					continue;
				}
            } else if (sortPilihan == 3) {
                cout << "\tPilih Sort \n1. Ascending \n2. Descending" << endl;
				int sortType;
				cin >> sortType;
				if (sortType == 1)
				{
					sortStok(true); // ascending
					printBarang();
				} else if (sortType == 2) {
					sortStok(false); // descending
					printBarang();
				} else {
					cout << "\nPilihanmu tidak ada." << endl;
					continue;
				}
            } else if (sortPilihan == 4) {
                continue;
            }
        } else if (pilihan == 7) {
			break;
		} else {
			cout << "Pilihanmu tidak ada." << endl;
			continue;
		}
    }
}

int main() {
    manajemenToko();
    return 0;
}
