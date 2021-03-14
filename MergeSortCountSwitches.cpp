//notes gia mena: dynamic gia na mhn kanoume toses polles staseis
//icsd14027 Alexandros Galanis
//O()
#include <iostream>

using namespace std;

int A[] = {2,20,6,4,5};

int merge(int left, int mid, int right){

    int temp[5];
    int i, j, k;
    int counter = 0;

    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right)) {
        if (A[i] <= A[j]) {
            temp[k++] = A[i++];
        }
        else {
            temp[k++] = A[j++];
            counter = counter + (mid - i);
        }
    }
    while (i <= mid - 1){
        temp[k++] = A[i++];
    }
    while (j <= right){
        temp[k++] = A[j++];
    }
    for (i = left; i <= right; i++){
        A[i] = temp[i];
    }
    return counter;
}



int divide(int left, int right){

    int mid;
    int count = 0;

    if(left < right){
        mid = (left + right)/2;
        count = divide(left, mid);
        count+= divide(mid + 1, right);
        count+= merge(left, mid + 1, right);
    }

    return count;
}


int main(){
    int count = divide(0,4);
    cout<<"count swap:"<<count<<endl;

    int k;

    for(k=0;k<5;k++){
        cout<<A[k]<<endl;
    }

}


