#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int M, N, P;
    cin >> M >> N;
    vector<vector<char>> map(M, vector<char>(N));
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }
    cin >> P;
    cin.ignore();
    string gerak;
    getline(cin, gerak);

    gerak.erase(remove(gerak.begin(), gerak.end(), ' '), gerak.end());

    int baris = 0, kolom = 0;
    int speed = 1;
    bool smash = false;
    int time = 0;
    bool crash = false;

    for (char arah : gerak){
        int nextBaris = baris, nextKolom = kolom;
        if (arah == 'D'){
            nextBaris++;
        }
        else if (arah == 'U'){
            nextBaris--;
        }
        else if (arah == 'R'){
            nextKolom++;
        }
        else if (arah == 'L'){
            nextKolom--;
        }

        if (nextBaris < 0 || nextBaris >= M || nextKolom < 0 || nextKolom >= N){
            cout << "Robot nabrak, silahkan diperbaiki\n";
            return 0;
        }
        if (map[nextBaris][nextKolom] == 'x' && smash == false){
            cout << "Robot nabrak, silahkan diperbaiki\n";
            continue;
        }

        time += (2 / speed);
        baris = nextBaris;
        kolom = nextKolom;
        char recentPoint = map[baris][kolom];
        if (recentPoint == 'M'){
            smash = true;
            cout << "Bertemu dengan mekanik, siap membasmi rintangan\n";
        }
        else if (recentPoint == 'E'){
            speed = 2;
            cout << "Bertemu dengan electrical, kecepatan roda naik menjadi 200%\n";
        }
        else if (recentPoint == 'P'){
            cout << "Hi Programmer\n";
        }
        else if (recentPoint == 'O'){
            time *= 2;
            cout << "Bertemu dengan official, diajak ngonten bareng\n";
        }

        if (recentPoint == 'F'){
            cout << "Robot berhasil mencapai tujuan\n";
            cout << "Robot telah berjalan selama " << time << " menit\n";
            return 0;
        }
    }
    cout << "Robot gagal dalam mencapai tujuan :(\n";
    cout << "Robot telah berjalan selama " << time << " menit\n";
    return 0;
}