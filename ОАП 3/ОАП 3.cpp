#include <iostream>
#include <vector>

const int nh = 50; const int nh1 = 650;
using namespace std;
typedef double db;

struct local_max
{
	int x, y, znach;
};

struct razm {
	int t, n;
};



local_max min_a(int(&a)[nh][nh], int t);
local_max max_a(int(&a)[nh][nh], int t);
razm n_t();
void obmen(int matrix, local_max utik, local_max putik);







int main()
{
	setlocale(0, "");
	int matrix[nh][nh];
	int massive[nh1];
	razm nt = n_t();

	for (int x = 0; x < nt.t; x++) {
		cout << "Введите значение ячейки: " << x << "\n";
		cin >> massive[x];
	}
	nt.t = 0;
	for (int x = 0; x < nt.n; x++) {
		for (int y = x; y < nt.n - x; y++) {
			matrix[x][y] = massive[nt.t];
			nt.t += 1;
		}
	}
	nt.n -= 1;
	for (int x = 0; x <= nt.n / 2; x++) {
		for (int y = x; y <= nt.n - x; y++) {
			int a = matrix[x][y];
			int t = nt.n - x, k = nt.n - y;
			matrix[t][k] = a;
			matrix[k][t] = a;
			matrix[y][x] = a;
		}
	}
	nt.n += 1;
	cout << "\n \n";

	cout << "Введённая вами матрица: \n";
	matrix_output(matrix, nt.n);

	local_max utik, putik;
	utik = max_a(matrix, nt.n);
	putik = min_a(matrix, nt.n);
	

	cout << "\n \n";
	cout << "Координаты наименьшего из локальных максимумов: " << "(" << utik.x << ", " << utik.y << ") \n";
	cout << "Координаты наибольшего из локальных минимумов: " << "(" << putik.x << ", " << putik.y << ") \n";
	
	

	int anton = matrix[utik.x][utik.y];
	matrix[utik.x][utik.y] = matrix[putik.x][putik.y];
	matrix[putik.x][putik.y] = anton;

	cout << "\n \n \n";

	cout << "Матрица с изменёнными максимум и минимумом: \n";
	matrix_output(matrix, nt.n);




}

razm n_t(){
	cout << "Введите сторону матрицы \n";
	int n; cin >> n;
	int t = 0; int z = n;
	while (z > 0) {
		t += z;
		z -= 2;
	}
	razm q;
	q.t = t;
	q.n = n;
	return q;
}
void matrix_output(int(&a)[nh][nh], int n) {
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			cout << a[x][y] << " ";
		}
		cout << "\n";
	}
}


local_max max_a(int(&a)[nh][nh], int t) {
	local_max min_max; min_max.znach = a[0][0];
	for (int x = 0; x < t; x++) {
		for (int y = 0; y < t; y++) {
			if (a[x][y] > min_max.znach) {
				min_max.znach = a[x][y];
				min_max.x = x;
				min_max.y = y;
			}	
		
		}
	}
	for (int x = 0; x < t; x++) {
		for (int y = 0; y < t; y++) {
			if (x == 0 && y == 0) {
				if (a[x][y] > a[x + 1][y] && a[x][y] > a[x][y + 1] && a[x][y] > a[x + 1][y + 1] && a[x][y] < min_max.znach) {
					min_max.znach = a[x][y];
					min_max.x = x;
					min_max.y = y;
				}
			}
			else if (x == 0 && y != 0 && y != t-1) {
				if (a[x][y] > a[x + 1][y] && a[x][y] > a[x][y + 1] && a[x][y] > a[x + 1][y + 1] && a[x][y] > a[x+1][y-1] && a[x][y] > a[x][y-1] && a[x][y] < min_max.znach) {
					min_max.znach = a[x][y];
					min_max.x = x;
					min_max.y = y;
				}
			}
			else  if (x == 0 && y == t - 1) {
				if (a[x][y] > a[x + 1][y] && a[x][y] > a[x][y - 1] && a[x][y] > a[x + 1][y - 1] && a[x][y] < min_max.znach) {
					min_max.znach = a[x][y];
					min_max.x = x;
					min_max.y = y;
				}

			}
			else if (x != 0 && x != t-1 && y == 0) {
				if (a[x][y] > a[x + 1][y] && a[x][y] > a[x][y + 1] && a[x][y] > a[x + 1][y + 1] && a[x][y] > a[x-1][y] && a[x][y] > a[x-1][y+1] && a[x][y] < min_max.znach) {
					min_max.znach = a[x][y];
					min_max.x = x;
					min_max.y = y;
				}
			}
			else if (x == t - 1 && y == 0) {
				if (a[x][y] > a[x - 1][y] && a[x][y] > a[x][y + 1] && a[x][y] > a[x - 1][y + 1] && a[x][y] < min_max.znach) {
					min_max.znach = a[x][y];
					min_max.x = x;
					min_max.y = y;
				}
			}
			else if (x == t - 1 && y != 0 && y != t - 1) {
				if (a[x][y] > a[x - 1][y] && a[x][y] > a[x][y + 1] && a[x][y] > a[x - 1][y + 1] && a[x][y] > a[x-1][y-1] && a[x][y] > a[x][y-1] && a[x][y] < min_max.znach) {
					min_max.znach = a[x][y];
					min_max.x = x;
					min_max.y = y;
				}
			}
			else if (x == t - 1 && y == t - 1) {
				if (a[x][y] > a[x - 1][y] && a[x][y] > a[x][y - 1] && a[x][y] > a[x - 1][y - 1] && a[x][y] < min_max.znach) {
					min_max.znach = a[x][y];
					min_max.x = x;
					min_max.y = y;
				}
			}
			else if (x != 0 && x != t - 1 && y == t - 1) {
				if (a[x][y] > a[x + 1][y] && a[x][y] > a[x][y - 1] && a[x][y] > a[x + 1][y - 1] && a[x][y] > a[x-1][y-1] && a[x][y] > a[x-1][y] && a[x][y] < min_max.znach) {
					min_max.znach = a[x][y];
					min_max.x = x;
					min_max.y = y;
				}
			}
			else {
				if (a[x][y] > a[x - 1][y - 1] && a[x][y] > a[x - 1][y] && a[x][y] > a[x - 1][y + 1] && a[x][y] > a[x][y+1] && a[x][y] > a[x+1][y+1] && a[x][y] > a[x+1][y] && a[x][y] > a[x+1][y-1] && a[x][y] > a[x][y-1] && a[x][y] < min_max.znach) {
					min_max.znach = a[x][y];
					min_max.x = x;
					min_max.y = y;
				}
			}
		}
	}
	return min_max;



}

void obmen(int (&matrix), local_max utik, local_max putik) {
	int anton = matrix[&utik.x][&utik.y];
	matrix[&utik.x][&utik.y] = matrix[&putik.x][&putik.y];
	matrix[&putik.x][&putik.y] = anton;
}



local_max min_a(int(&a)[nh][nh], int t) {
	local_max min_max; min_max.znach = a[0][0];
	for (int x = 0; x < t; x++) {
		for (int y = 0; y < t; y++) {
			if (a[x][y] < min_max.znach) {
				min_max.znach = a[x][y];
				min_max.x = x;
				min_max.y = y;
			}

		}
	}
	for (int x = 0; x < t; x++) {
		for (int y = 0; y < t; y++) {
			if (x == 0 && y == 0) {
				if (a[x][y] < a[x + 1][y] && a[x][y] < a[x][y + 1] && a[x][y] < a[x + 1][y + 1] && a[x][y] > min_max.znach) {
					min_max.znach = a[x][y];
					min_max.x = x;
					min_max.y = y;
				}
			}
			else if (x == 0 && y != 0 && y != t - 1) {
				if (a[x][y] < a[x + 1][y] && a[x][y] < a[x][y + 1] && a[x][y] < a[x + 1][y + 1] && a[x][y] < a[x + 1][y - 1] && a[x][y] < a[x][y - 1] && a[x][y] > min_max.znach) {
					min_max.znach = a[x][y];
					min_max.x = x;
					min_max.y = y;
				}
			}
			else  if (x == 0 && y == t - 1) {
				if (a[x][y] < a[x + 1][y] && a[x][y] < a[x][y - 1] && a[x][y] < a[x + 1][y - 1] && a[x][y] > min_max.znach) {
					min_max.znach = a[x][y];
					min_max.x = x;
					min_max.y = y;
				}

			}
			else if (x != 0 && x != t - 1 && y == 0) {
				if (a[x][y] < a[x + 1][y] && a[x][y] < a[x][y + 1] && a[x][y] < a[x + 1][y + 1] && a[x][y] < a[x - 1][y] && a[x][y] < a[x - 1][y + 1] && a[x][y] > min_max.znach) {
					min_max.znach = a[x][y];
					min_max.x = x;
					min_max.y = y;
				}
			}
			else if (x == t - 1 && y == 0) {
				if (a[x][y] < a[x - 1][y] && a[x][y] < a[x][y + 1] && a[x][y] < a[x - 1][y + 1] && a[x][y] > min_max.znach) {
					min_max.znach = a[x][y];
					min_max.x = x;
					min_max.y = y;
				}
			}
			else if (x == t - 1 && y != 0 && y != t - 1) {
				if (a[x][y] < a[x - 1][y] && a[x][y] < a[x][y + 1] && a[x][y] < a[x - 1][y + 1] && a[x][y] < a[x - 1][y - 1] && a[x][y] < a[x][y - 1] && a[x][y] > min_max.znach) {
					min_max.znach = a[x][y];
					min_max.x = x;
					min_max.y = y;
				}
			}
			else if (x == t - 1 && y == t - 1) {
				if (a[x][y] < a[x - 1][y] && a[x][y] < a[x][y - 1] && a[x][y] < a[x - 1][y - 1] && a[x][y] > min_max.znach) {
					min_max.znach = a[x][y];
					min_max.x = x;
					min_max.y = y;
				}
			}
			else if (x != 0 && x != t - 1 && y == t - 1) {
				if (a[x][y] < a[x + 1][y] && a[x][y] < a[x][y - 1] && a[x][y] < a[x + 1][y - 1] && a[x][y] < a[x - 1][y - 1] && a[x][y] < a[x - 1][y] && a[x][y] > min_max.znach) {
					min_max.znach = a[x][y];
					min_max.x = x;
					min_max.y = y;
				}
			}
			else {
				if (a[x][y] < a[x - 1][y - 1] && a[x][y] < a[x - 1][y] && a[x][y] < a[x - 1][y + 1] && a[x][y] < a[x][y + 1] && a[x][y] < a[x + 1][y + 1] && a[x][y] < a[x + 1][y] && a[x][y] < a[x + 1][y - 1] && a[x][y] < a[x][y - 1] && a[x][y] > min_max.znach) {
					min_max.znach = a[x][y];
					min_max.x = x;
					min_max.y = y;
				}
			}
		}
	}
	return min_max;



}













