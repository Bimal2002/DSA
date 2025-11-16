function isPermutaion(str1,str2){
    var check_string = false;
    if(str1.length > str2.length){
        return false;
    }

    function getCountMap(str){
        const map={};
        for(let ch of str){
            map[ch]=(mp[ch] ||0)+1;
           
        }
        return map;
    }

    const s1Count = getCountMap(str1);
    const windowSize = str1.length;
    for(let i=0;i<=str2.length-windowSize;i++){
       const window = str2.substring(i,i+windowSize);
       const s2Count = getCountMap(window);
       let isSame = true;
       for(let key in s1Count){
        if(s1Count[key] != s2Count[key]){
            isSame = false;
            break;
        }
       }

       if(isSame){
        check_string = true;
        break;
       }
    }
    return check_string;
}