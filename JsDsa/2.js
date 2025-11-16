function runways_req(arrival_time,departure_time,no_of_planes){
    arrival_time.sort((a,b)=>a-b);
    departure_time.sort((a,b)=> a-b);
    var no_of_runways = 1;

    let i =0 ,j= 0;
    let curr_planes =0;
    while(i<no_of_planes && j<no_of_planes){
        if(arrival_time[i]<departure_time[j]){
            curr_planes++;
            i++;
            no_of_runways = Math.max(no_of_runways,curr_planes);
        }else{
            curr_planes --;
            j++;
        }
    }
    return no_of_runways;
}