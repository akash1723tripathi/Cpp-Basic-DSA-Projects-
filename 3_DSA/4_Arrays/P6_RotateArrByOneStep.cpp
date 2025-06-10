//left rotate
vector<int> LeftrotateArray(vector<int>& arr, int n) {
    int temp = arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
    return arr;
}

// Right rotate
vector<int> rightrotateArray(vector<int>& arr, int n) {
      int temp = arr[n-1];
      for(int i=n-2;i>=0;i--){
            arr[i+1]=arr[i];
      }
      arr[0]=temp;
      return arr;
}


