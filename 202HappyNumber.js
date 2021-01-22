var isHappy = function(n) {
    var num = n ;
    
   let sum = 0;
    var i = 1;
    var flag = false;
   while(i < 100){
       sum = 0;
       while(num > 0){
           
        let dig = num % 10;
        
        sum = sum + dig * dig;
        
        num = Math.floor(num/10);
    }
    
       if(sum == 1) flag=true;
       
      num = sum;
       
       i++;
  }
    
    return flag;
};

console.log(isHappy(19));