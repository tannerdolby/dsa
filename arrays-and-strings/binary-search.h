// Iterative: O(log(n)) time and O(1) space
// Recursive: O(log(n)) time and O(log(n)) space

template <typename T>
int binarySearchIterative(std::vector<T> arr, T target) {
	int left = 0, right = arr.size()-1;
	while (left <= right) {
		int mid = left + ((right-left) / 2);
		if (target == arr[mid]) {
			return mid;
		} else if (target < arr[mid]) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return -1;
}

template <typename T, int N>
int binarySearchIterative(T arr[], T target) {
	int left = 0, right = N - 1;
	while (left <= right) {
		int mid = left + ((right-left) / 2);
		if (target == arr[mid]) {
			return mid;
		} else if (target < arr[mid]) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return -1;
}

template <typename T>
int binarySearchHelper(std::vector<T> arr, int left, int right, T target) {
	if (left >= right) return -1;
	int mid = left + ((right-left) / 2);
	if (target == arr[mid]) {
		return mid;
	} else if (target < arr[mid]) {
		return binarySearchHelper(arr, left, mid-1, target);
	} else {
		return binarySearchHelper(arr, mid+1, right, target);
	}
}

template <typename T>
int binarySearchRecursive(std::vector<T> arr, T target) {
	return binarySearchHelper(arr, 0, arr.size()-1, target);
}

template <typename T>
int binarySearchHelperTwo(T arr[], int left, int right, T target) {
	if (left >= right) return -1;
	int mid = left + ((right-left) / 2);
	if (target == arr[mid]) {
		return mid;
	} else if (target < arr[mid]) {
		return binarySearchHelperTwo(arr, left, mid-1, target);
	} else {
		return binarySearchHelperTwo(arr, mid+1, right, target);
	}
	return -1;
}

template <typename T, int N>
int binarySearchRecursiveTwo(T arr[], T target) {
	return binarySearchHelperTwo(arr, 0, N-1, target);
}