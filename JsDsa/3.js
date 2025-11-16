function isPossible(arr, n, k, mid) {
    let students = 1;
    let pages = 0;
    for (let i = 0; i < n; i++) {
        if (arr[i] > mid) return false;

        if (pages + arr[i] > mid) {
            students++;
            pages = arr[i];
            if (students > k) return false;
        } else {
            pages += arr[i];
        }
    }
    return true;
}

function minimum_pages(arr, n, k) {
    if (k > n) return -1;

    let low = arr[0];
    for (let i = 1; i < n; i++) {
        if (arr[i] > low) low = arr[i];
    }

    let high = 0;
    for (let i = 0; i < n; i++) {
        high += arr[i];
    }
    let ans = -1;

    // for(let i=0;i<n;i++){
    while (low <= high) {
        let mid = Math.floor((low + high) / 2);
        if (isPossible(arr, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}


const arr = [11, 33, 15, 62, 22, 15, 31, 60];
const n = arr.length;
const k = 3;

console.log("Minimum pages =", minimum_pages(arr, n, k));
