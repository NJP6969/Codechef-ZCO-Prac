#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    long long int max_height;
    cin >> n;
    cin >> max_height;
    int arr[n];
    cin >> arr[0];
    for(int i = 1; i < n; i++){
        cin >> arr[i];
    }
    long long int boxes_in_crane = 0;
    int pos = 0;
    while(true){
        int command;
        cin >> command;
        if(command == 1 && pos > 0){
            pos--;
        }
        else if(command == 2 && pos < n-1){
            pos++;
        }
        else if(command == 3 && boxes_in_crane == 0 && arr[pos] > 0){
            arr[pos]--;
            boxes_in_crane++;
        }
        else if(command == 4 && boxes_in_crane == 1 && arr[pos] < max_height){
            arr[pos]++;
            boxes_in_crane--;
        }
        if(command == 0){
            break;
        }
    }
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}