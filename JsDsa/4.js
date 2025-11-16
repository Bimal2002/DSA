function major_element(arr,n){
    let freq ={};
    for(let i =0;i<n;i++){
        if(freq[arr[i]]==undefined) freq[arr[i]]=1;
        else
            freq[arr[i]]++;

    }

    for(let key in freq){
        if(freq[key] > Math.floor(n/2)){
            return parseInt(key);
        }
    }

    return -1;
}