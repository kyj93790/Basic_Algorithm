#include <iostream>
#include <string>
using namespace std;

typedef struct student {
    string name;
    int kor;
    int eng;
    int math;
} student;

int cmpStu(student a, student b) {
    if (a.kor != b.kor) return (a.kor - b.kor);
    else if (a.eng != b.eng) return (b.eng - a.eng);
    else if (a.math != b.math) return (a.math - b.math);
    else return (b.name.compare(a.name));
}

void merge(student *arr, int s, int m, int e) {
    student *temp = new student[e-s+1];
    int i = s, j = m+1, k = 0;
    while (i<=m && j<=e) {
        if (cmpStu(arr[i], arr[j]) >= 0)
            temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while (i<=m) temp[k++] = arr[i++];
    while (j<=e) temp[k++] = arr[j++];
    for (k=0; k<e-s+1; k++) {
        arr[s+k] = temp[k];
    }
}

void mergeSort(student *arr, int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;
        mergeSort(arr, s, m);
        mergeSort(arr, m+1, e);
        merge(arr, s, m, e);
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n;
    cin >> n;
    student arr[100000];
    for (int i=0; i<n; i++) {
        cin >> arr[i].name >> arr[i].kor >> arr[i].eng >> arr[i].math;
    }
    mergeSort(arr, 0, n-1);
    for (int i=0; i<n; i++) {
        cout << arr[i].name << '\n';
    }
    return 0;
}