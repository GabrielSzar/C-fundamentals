void Bubblesort(int array[], int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (array[i] < array[j]) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }
}
