#include <iostream>
using namespace std;

int n, v[100005];


void Merge(int st,int dr) {
	int i = st, j = ((st+dr)/2) +1;

	if (v[i] > v[j]) {
	int aux = v[i];
	v[i] = v[j];
	v[j] = aux;
	}

	while (j + 1 <= dr && i + 1 <= dr) {
		if (i + 1 == j) {
			++j;
			if (v[i] > v[j]) {
				int aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
		}
		if (v[i] > v[j]) {//scos posibil
			int aux = v[i];
			v[i] = v[j];
			v[j] = aux;
		}
		else
			if (j + 1 <= dr && i + 1 <= dr) {
			if (v[j] < v[i + 1]) {
				int aux = v[i+1];
				v[i+1] = v[j];
				v[j] = aux;
			}
			else if (v[i] > v[j + 1]) {
				int aux = v[i];
				v[i] = v[j+1];
				v[j+1] = aux;
			}
			else { ++i;}
		}
		else { ++i; }//merge si fara cred testeaza** dar trebuie ending

	}

}

void MergeSort(int st, int dr)
{
	if (st < dr)
	{
		int middle = (st + dr) / 2;
		MergeSort(st, middle);
		MergeSort(middle + 1, dr);
		Merge(st, dr);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	MergeSort(0, n - 1);
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";


	system("pause");
	return 0;
}

//11
//0 -1 -3 1 -4 9 3 -1 -4 3 -4