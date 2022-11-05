#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

const int MAXN = 100000;

int BIT[MAXN], positions[MAXN];

void add(int index, int n) {
	for (int i = index; i < MAXN; i += i & -i) {
		BIT[i] += n;
	}
}

int sum(int index) {
	int removedMovie = 0;
	for (int i = index; i; i -= i & -i) {
		removedMovie += BIT[i];
	}
	return removedMovie;
}

int main() {
    input;
	int numberOfOperations;
    cin>>numberOfOperations;
	while (numberOfOperations --) {
		int totalMovies, moviesToRemove;
        cin>>totalMovies>>moviesToRemove;
		fill(BIT + 1, BIT + 1 + totalMovies + moviesToRemove, 0);
		for (int i = 1; i <= totalMovies; ++ i) {
			positions[i] = totalMovies - i + 1;
			add(i, 1);
		}
		int cnt = totalMovies;
		for (int i = 0; i < moviesToRemove; ++ i) {
			int movie;
            cin>>movie;
			int removedMovie = sum(positions[movie]);
            if(i == moviesToRemove-1){
                cout<<totalMovies - removedMovie;
            } else{
                cout<<totalMovies - removedMovie<<" ";
            }
			
			add(positions[movie], -1);
			positions[movie] = ++ cnt;
			add(positions[movie], 1);
		}
        cout<<""<<endl;
	}
	return 0;
}
